/*
 * $QNXLicenseC:
 * Copyright 2018, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

#include "externs.h"

unsigned  process_lsr(DEV_SER16550 *dev, unsigned char lsr) {
    unsigned key = 0;//, eventflag = 0;

    // Return immediately if no errors.
    if((lsr & (LSR_BI|LSR_OE|LSR_FE|LSR_PE)) == 0){
        return(0);
    }
    
    // Save the error as out-of-band data which can be retrieved via devctl().
    dev->tty.oband_data |= (lsr >> 1) & 0x0f;
    atomic_set(&dev->tty.flags, OBAND_DATA);

    if(lsr & LSR_BI){
        key |= TTI_BREAK;
    
    }else{    
        if(lsr & LSR_OE)
            key |= TTI_OVERRUN;
        else if(lsr & LSR_FE)
            key |= TTI_FRAME;
        else if(lsr & LSR_PE)
            key |= TTI_PARITY;
    }
   return (key);
}


/*
 * Serial interrupt handler
 */
const struct sigevent * ser_intr(void *area, int id){
    struct dev_list *list = area;
    int             status = 0;
    int             something_happened;
    unsigned char   msr, lsr;
    DEV_SER16550        *dev;
    struct sigevent *event = NULL;
    unsigned        c; 

    do {
        something_happened = 0;
        for(dev = list->device; dev != NULL; dev = dev->next) {
            unsigned    iir;
            uintptr_t   *port = dev->port; 
            status = 0;

            iir = (read_16550(port[REG_II]) & 0x07);
            switch(iir) {         
                case II_RX:     // Receive data
                case II_LS:
                    /* Some UARTs will generate a LS interrupt when there is an 
                     * error anywhere in the RX FIFO, and will clear this interrupt
                     * only when there are no more errors remaining in the FIFO. The 
                     * error bits in REG_LS (BI/PR/FE/OE) always represent the error 
                     * status for the received character at the top of the Rx FIFO. 
                     * Reading the Rx FIFO updates these bits to the appropriate status
                     * of the new character. This means that it is possible to get an
                     * LS interrupt with none of the error status bits set, in order
                     * to clear the LS interrupt we must read out all of the characters
                     * in the FIFO until we find and handle the erronous character.
                     */
                    while((lsr = read_16550(port[REG_LS])) & LSR_RXRDY)
                    {
                        c = read_16550(port[REG_RX]);
                        c |= process_lsr(dev, lsr);
                        status |= tti(&dev->tty, c);
                    };
                    break;         
                case II_TX:     // Transmit buffer empty                
                    dev->tty.un.s.tx_tmr = 0;
                    /* Send evnet to io-char, tto() will be processed at thread time */
                    atomic_set(&dev->tty.flags, EVENT_TTO);
                    status |= 1;                
                    break;

                case II_MS:     // Modem change
                    msr = read_16550(port[REG_MS]);

                    if(msr & MSR_DDCD)
                        status |= tti(&dev->tty, (msr & MSR_DCD) ? TTI_CARRIER : TTI_HANGUP);
                    
                    
                    if((msr & MSR_DCTS)  &&  (dev->tty.c_cflag & OHFLOW))
                        status |= tti(&dev->tty, (msr & MSR_CTS) ? TTI_OHW_CONT : TTI_OHW_STOP);
                    
                    /* OBAND notification of Modem status change */ 
                    dev->tty.oband_data |= _OBAND_SER_MS;
                    atomic_set(&dev->tty.flags, OBAND_DATA);
                    atomic_set(&dev->tty.flags, EVENT_NOTIFY_OBAND);
                    status |= 1;
                    break;

                default:
                    continue;

            }

            something_happened = 1;
            if(status) {
                if((dev->tty.flags & EVENT_QUEUED) == 0) {
                    event = &ttyctrl.event;
                    dev_lock(&ttyctrl);
                    ttyctrl.event_queue[ttyctrl.num_events++] = &dev->tty;
                    atomic_set(&dev->tty.flags, EVENT_QUEUED);
                    dev_unlock(&ttyctrl);
                    }
                }
            }
        } while(something_happened);
    return(event);
}


void clear_device(const uintptr_t *port) {
    unsigned char tmp;

    write_16550(port[REG_IE], IE_CLR_ALL);   /* Disable all interrupts       */
    tmp = read_16550(port[REG_LS]);          /* Clear Line Status Interrupt  */
    tmp = read_16550(port[REG_RX]);          /* Clear RX Interrupt           */
    tmp = read_16550(port[REG_TX]);          /* Clear TX Interrupt           */
    tmp = read_16550(port[REG_MS]);          /* Clear Modem Interrupt        */
    write_16550(port[REG_FC], 0x00);         /* Disable and reset FIFOs      */
}


int ser_attach_intr(DEV_SER16550 *dev){
    uintptr_t   *port = dev->port;
    struct dev_list **owner;
    struct dev_list *curr;

    // According to the National bug sheet you must wait for the transmit
    // holding register to be empty.
    do {
    } while((read_16550(port[REG_LS]) & LSR_TXRDY) == 0);

    // Clean the device so we get a level change on the intr line to the bus.
    // Enable out2 (gate intr to bus)
    set_port(port[REG_MC], MCR_OUT2, MCR_OUT2);
    clear_device(port);

    // Add it to the interrupt list
    owner = &devices;
    for( ;; ) {
        curr = *owner;
        if(curr == NULL) {
            curr = malloc(sizeof(*curr));
         if (curr == NULL)
         {
            slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Allocation of device interrupt entry failed (%d)", errno);
            return (-1);
         }
            *owner = curr;
            curr->next = NULL;
            curr->device = NULL;
            break;
        }
        if(curr->device->intr == dev->intr) break;
        owner = &curr->next;
    }
    // Delay interrupts while we're fiddling around with the list
    InterruptMask(dev->intr, -1);
    dev->next = curr->device;
    curr->device = dev;
    InterruptUnmask(dev->intr, -1);

    // If first handler, attach the interrupt.
    if(curr->device->next == NULL) {
        curr->iid = InterruptAttach(dev->intr, ser_intr, curr, 0, 0);
    }

    // Enable ALL interrupt sources.
    if (dev->tty.c_cflag & CREAD)
        write_16550(port[REG_IE], IE_SET_ALL);
    else
        write_16550(port[REG_IE], (IE_SET_ALL & ~IE_RX) );

    return EOK;
}
void ser_detach_intr(DEV_SER16550 *dev)
{
    struct dev_list     *curr_list, *prev_list;
    DEV_SER16550            *curr_dev, *prev_dev;
    uintptr_t           *port = dev->port;

    // Disable ALL interrupt sources
    write_16550(port[REG_IE], IE_CLR_ALL);   /* Disable interrupts */
    set_port(port[REG_MC], MCR_OUT2, 0x00); // Disable out2

    //
    // Remove from list of devices to scan on an interrupt.
    //
    
    // Delay interrupts while we're fiddling around with the list
    InterruptMask(dev->intr, -1);

    // Find the right interrupt list
    curr_list = prev_list = devices;
    while (curr_list){
        if (curr_list->device->intr == dev->intr){
         /* Now that we found the right interrupt list
          * find and remove the device from the device list (but don't free it) 
          */
            prev_dev = curr_dev = curr_list->device;
            while (curr_dev){
                if (curr_dev == dev){
                   if (curr_dev == curr_list->device){ /* If first entry in device list */
                        curr_list->device = curr_list->device->next;
                        if (curr_list->device == NULL){ /* No more devices in list */
                            if (curr_list == devices) /* If first list in list of lists :-) */
                                devices = devices->next;
                            else 
                                prev_list->next = curr_list->next;
                            InterruptDetach(curr_list->iid);
                            free(curr_list);  /* Free empty list */
                            curr_list = NULL;
                        }
                    } else{
                        prev_dev->next = curr_dev->next;
                    }                
                    curr_dev = NULL;
                    curr_list = NULL; /* We found what we were looking for, now bail out of both loops */
                } else {
                    if (prev_dev != curr_dev)
                        prev_dev = prev_dev->next;
                   curr_dev = curr_dev->next;
                }
            }
        } else {
            if (prev_list != curr_list)
                prev_list = prev_list->next;
            curr_list = curr_list->next;
        }
    }
    clear_device(dev->port);
    InterruptUnmask(dev->intr, -1);

    dev->intr = _NTO_INTR_SPARE;
    return;
}