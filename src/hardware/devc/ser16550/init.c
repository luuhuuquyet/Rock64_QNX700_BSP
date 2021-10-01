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
#include <sys/mman.h>
#include <string.h>
void set_port(unsigned port, unsigned mask, unsigned data) {
    unsigned char c;

    c = read_16550(port);
    write_16550(port, (c & ~mask) | (data & mask));
}
/*
 * Specify parameters for default devices.
 */
void *
query_default_device(TTYINIT *dip, void *link)
{
    switch ((unsigned)link) {
        case 0:
            dip->port = RK3328_UART2_BASE;
            dip->intr = UART2_INTR;
            return (void *)1;
        }
    return NULL;
}
void free_device( DEV_SER16550 *dev )
{
   free(dev->tty.ibuf.head);
   free(dev->tty.obuf.head);
   free(dev->tty.cbuf.head);
   ser_detach_intr(dev);
   free(dev);
}


DEV_SER16550* create_device(TTYINIT *dip, unsigned unit)
{
    DEV_SER16550        *dev;
  unsigned      i;
  uintptr_t     port;

  // Get a device entry and the input/output buffers for it.
  if ((dev = (void *) malloc(sizeof(*dev))) == NULL)
   {
      slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Allocation of device entry failed (%d)", errno);
      return (dev);
   }
  memset(dev, 0, sizeof(*dev));

  // Get buffers.
  dev->tty.ibuf.head = dev->tty.ibuf.tail = dev->tty.ibuf.buff = malloc(dev->tty.ibuf.size = dip->isize);
   if (dev->tty.ibuf.head == NULL)
   {
      slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Allocation of input buffer failed (%d)", errno);
      free(dev);
      return (NULL);
   }
      
  dev->tty.obuf.head = dev->tty.obuf.tail = dev->tty.obuf.buff = malloc(dev->tty.obuf.size = dip->osize);
   if (dev->tty.obuf.head == NULL)
   {
      slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Allocation of output buffer failed (%d)", errno);
      free(dev->tty.ibuf.head);
      free(dev);
      return (NULL);
   }
   
  dev->tty.cbuf.head = dev->tty.cbuf.tail = dev->tty.cbuf.buff = malloc(dev->tty.cbuf.size = dip->csize);
   if (dev->tty.cbuf.head == NULL)
   {
      slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Allocation of canonical buffer failed (%d)", errno);
      free(dev->tty.ibuf.head);
      free(dev->tty.obuf.head);
      free(dev);
      return (NULL);
   }
   
  if (dip->highwater)
    dev->tty.highwater = dip->highwater;
  else
    dev->tty.highwater = dev->tty.ibuf.size - FIFO_SIZE * 2;
  
  if (dev->tty.highwater <= 0)
    return (NULL);

  strcpy(dev->tty.name, dip->name);

  dev->tty.baud = dip->baud;
  dev->tty.fifo = dip->fifo;

   port = mmap_device_io(
    (sizeof(dev->port)/sizeof(dev->port[0])) << dip->port_shift, dip->port);
  for(i = 0; i < sizeof(dev->port)/sizeof(dev->port[0]); ++i) {
    dev->port[i] = port;
    port += 1 << dip->port_shift;
  }
  dev->intr = dip->intr;
  dev->clk = dip->clk;
  dev->div = dip->div;

  dev->tty.flags = EDIT_INSERT | LOSES_TX_INTR;
  dev->tty.c_cflag = dip->c_cflag;
  dev->tty.c_iflag = dip->c_iflag;
  dev->tty.c_lflag = dip->c_lflag;
  dev->tty.c_oflag = dip->c_oflag;
   dev->tty.verbose = dip->verbose;

  // Initialize termios cc codes to an ANSI terminal.
  ttc(TTC_INIT_CC, &dev->tty, 0);

  // Initialize the device's name.
  // Assume that the basename is set in device name.  This will attach
  // to the path assigned by the unit number/minor number combination
  unit = SET_NAME_NUMBER(unit) | NUMBER_DEV_FROM_USER;
  ttc(TTC_INIT_TTYNAME, &dev->tty, unit);

  // Initialize power management structures before attaching ISR
  // ttc(TTC_INIT_POWER, &dev->tty, 0);

  /* Disable Interrupts on port 
   * Interrupts must be disbled on chip for all ports on a
   * multiport card before attaching an ISR to any of the ports.
   * enable_device() must be called for each port before returning 
   * from options() to complete port initialization
   */
  clear_device(dev->port);

   return (dev);
}

int enable_device( DEV_SER16550 *dev)
{
  unsigned char   reg;
  
  // Only setup IRQ handler for non-pcmcia devices.
  // Pcmcia devices will have this done later when card is inserted.
  if(dev->port != 0 && dev->intr != _NTO_INTR_SPARE) 
  {
    /*
     * If CREAD is set (default) then we must clear it before we call ser_stty(), 
     * else ser_stty() will enable the receive interrupt before we attach our ISR.
     * ser_attach_intr() will enable all the interrupts after the ISR is attached.
     */
    if (dev->tty.c_cflag & CREAD)
    {
      dev->tty.c_cflag &= ~(CREAD);
      ser_stty(dev);
      dev->tty.c_cflag |= CREAD;
    }
    else
      ser_stty(dev);
    
    if (ser_attach_intr(dev) == -1)
    {
      free_device(dev);
      return (-1);
    }
  }

  // Extract the rx and tx fifo sizes
  dev->rx_fifo = dev->tty.fifo & 0xf;
  dev->tx_fifo = (dev->tty.fifo >> 4) & 0xf;

  // Set RX fifo trigger level
  switch(dev->rx_fifo)
  {
    case 1:
    default: 
    reg = FCR_RX_TRIG_1; 
      break;  
      case 4:
      reg = FCR_RX_TRIG_4;
      break;
      case 8:
      reg = FCR_RX_TRIG_8;
      break;
      case 14:
      reg = FCR_RX_TRIG_14;
      break;
    }
  reg |= FCR_FIFO_ENABLE;
  write_16550(dev->port[REG_FC], reg);

  /* Turn on DTR and RTS */
  set_port(dev->port[REG_MC], MCR_DTR|MCR_RTS, MCR_DTR|MCR_RTS);
      
  /* Get current MSR stat */
  reg = read_16550(dev->port[REG_MS]);

  if(reg & MSR_DDCD)
    tti(&dev->tty, (reg & MSR_DCD) ? TTI_CARRIER : TTI_HANGUP);
          
  if((reg & MSR_DCTS)  &&  (dev->tty.c_cflag & OHFLOW))
    tti(&dev->tty, (reg & MSR_CTS) ? TTI_OHW_CONT : TTI_OHW_STOP);

  /* Attach the resource manager */
  ttc(TTC_INIT_ATTACH, &dev->tty, 0);
  return EOK; 
}

void sys_ttyinit( TTYINIT *dip ) {
    dip->clk = CONFIG_DEBUG_UART_CLOCK;
    dip->div = CONFIG_DEBUG_UART_DIV;
}