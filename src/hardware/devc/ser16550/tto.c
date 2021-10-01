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

int tto(TTYDEV *ttydev, int action, int arg1){
    TTYBUF          *bup = &ttydev->obuf;
    DEV_SER16550         *dev = (DEV_SER16550 *)ttydev;
    const uintptr_t *port = dev->port;
    unsigned char   c;
    int             nbytes_tx = 0;

    switch(action) {
        case TTO_STTY:
            ser_stty(dev);
            return(0);
        case TTO_CTRL:
            if(arg1 & _SERCTL_BRK_CHG)
                set_port(port[REG_LC], LCR_BREAK, arg1 &_SERCTL_BRK ? LCR_BREAK : 0);

            if(arg1 & _SERCTL_DTR_CHG)
                set_port(port[REG_MC], MCR_DTR, arg1 & _SERCTL_DTR ? MCR_DTR : 0);
          
            if(arg1 & _SERCTL_RTS_CHG)
                set_port(port[REG_MC], MCR_RTS, arg1 & _SERCTL_RTS ? MCR_RTS : 0);
            return(0);
        case TTO_LINESTATUS:
            return(((read_16550(port[REG_MS]) << 8) | read_16550(port[REG_MC])) & 0xf003);
        case TTO_DATA:
        case TTO_EVENT:
            break;
        default:
            return(0);
    }

    

      /* With FIFOs enable LSR_TXRDY is set when the last byte is moved from 
       * the TX fifo to the TX shift register (TX FIFO empty). LSR_TXRDY is cleared
       * when a byte is added to the TX FIFO. Since there is no TX trigger level 
       * for 16550 style UARTs, we only ever write when the FIFO is empty to ensure
       * we do not overrun the TX fifo.
       * NOTE: Do not confuse the LSR_TXDRY with the II_TX which is cleared on read
       *       of the II register and/or when a byte is written to the TX Fifo 
       */
   if (read_16550(port[REG_LS]) & LSR_TXRDY){
        nbytes_tx = 0;
        while (bup->cnt > 0 && nbytes_tx < dev->tx_fifo){
            /*
             * If the OSW_PAGED_OVERRIDE flag is set then allow
             * transmit of character even if output is suspended via
             * the OSW_PAGED flag. This flag implies that the next
             * character in the obuf is a software flow control
             * charater (STOP/START).
             * Note: tx_inject sets it up so that the contol
             *       character is at the start (tail) of the buffer.
             *
             */
            if(dev->tty.flags & (OHW_PAGED|OSW_PAGED) && !(dev->tty.xflags & OSW_PAGED_OVERRIDE)) 
                break;
         
             /* Get character from obuf and do any output processing */
            dev_lock(&dev->tty);
            c = tto_getchar(&dev->tty); 
            dev_unlock(&dev->tty);

            // Print the character
            dev->tty.un.s.tx_tmr = 3;  /* Timeout */
            write_16550(port[REG_TX], c);
            nbytes_tx++;
            /* Clear the OSW_PAGED_OVERRIDE flag as we only want
             * one character to be transmitted in this case.
             */
            if (dev->tty.xflags & OSW_PAGED_OVERRIDE){
                atomic_clr(&dev->tty.xflags, OSW_PAGED_OVERRIDE);
                break;
            }
        }
    }
   
   /* Check the client lists for notify conditions */
    return( tto_checkclients(&dev->tty) );
}

void ser_stty(DEV_SER16550 *dev){
    unsigned        lcr = 0;
    const uintptr_t *port = dev->port;
    unsigned        value;

    // Set Baud rate
    value = (dev->tty.baud == 0) ? 0 : (dev->clk/(dev->tty.baud * dev->div));

    dev_lock(&dev->tty);
    set_port(port[REG_LC], LCR_DLAB, LCR_DLAB);
    set_port(port[REG_DL0], 0xff, value & 0xff);
    set_port(port[REG_DL1], 0xff, value >> 8);
    set_port(port[REG_LC], LCR_DLAB, 0);
    dev_unlock(&dev->tty);

    if ( dev->tty.c_cflag & CREAD && !(read_16550(port[REG_IE]) & 0x1))
    {
        /* Enable receiver */
        set_port(port[REG_FC], FCR_RX_FIFO_RESET, FCR_RX_FIFO_RESET);   /* Clear RX Fifo */
        set_port(port[REG_IE], 0x1, 0x1);                               /* Enable receive interrupt */

    }
    else if ( !(dev->tty.c_cflag & CREAD)  && (read_16550(port[REG_IE]) & 0x1))
    {
        /* Disable receiver */
        set_port(port[REG_IE], 0x1, 0x0);                               /* Disable receive interrupt */
    }

    // Set data bits
    switch(dev->tty.c_cflag & CSIZE) {
    case CS8: ++lcr;
    case CS7: ++lcr;
    case CS6: ++lcr;
    }
    
    // Set stop bits
    if(dev->tty.c_cflag & CSTOPB)
        lcr |= LCR_STB2;

    // Set parity bits
    if(dev->tty.c_cflag & PARENB)
    {
        lcr |= LCR_PEN;
        if (dev->tty.c_cflag & PARODD)
            lcr &= ~( LCR_EPS );            /* Clear even bit if odd parity */
        else
            lcr |= LCR_EPS;
        if ( dev->tty.c_cflag & PARSTK )    /* Check if Mark/Space parity enabled */
            lcr |= LCR_SPS;
        else
            lcr &= ~( LCR_SPS );
    }
    else
        lcr &= ~( LCR_PEN );

    set_port(port[REG_LC], 0xFF, lcr);
}
