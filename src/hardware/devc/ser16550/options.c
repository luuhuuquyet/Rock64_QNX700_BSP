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


/*
#ifdef __USAGE
%C - Serial driver for Rock64 RK3328 UARTs

%C [options] [port[,irq]] &
Options:
 -b number    Define initial baud rate (default 1500000)
 -c clk       Set the input clock rate (default 24000000)
 -C number    Size of canonical input buffer (default 256)
 -e           Set options to "edit" mode
 -E           Set options to "raw" mode (default)
 -I number    Size of raw input buffer (default 2048)
 -f           Enable hardware flow control
 -F           Disable hardware flow control (default)
 -O number    Size of output buffer (default 2048)
 -s           Enable software flow control
 -S           Disable software flow control (default)
 -R number    Set receive FIFO trigger level (default 1)
 -T number    Set transmit FIFO size (default 8)
 -u unit      Set serial unit number (default 1)

#endif
*/
#include "externs.h"

/* open() ... */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>



unsigned options(int argc, char *argv[])
{
    int opt, i, enabled_cnt = 0, numports = 0;
    char *cp;
    void *link;
    unsigned unit;
    unsigned fifo_tx, fifo_rx;
    DEV_SER16550 *dev_list[MAX_DEVICES];
    static TTYINIT devinit ={
            RK3328_UART2_BASE,               // Port
            0,               // Port shift
            89,                // Interrupt address
            1500000,    // Baud
            2048,       // isize
            2048,       // osize    
            256,        // csize
            0,          // cflag
            0,          // iflag
            0,          // lflag
            0,          // oflag
            0xe8,          // fifo
            CONFIG_DEBUG_UART_CLOCK,    // clk
            16,         // div
            "/dev/ser",
            NULL, 
            0, 
            1, 
            0
    };

    // Initialize the devinit to raw mode
    ttc(TTC_INIT_RAW, &devinit, 0);

    sys_ttyinit(&devinit);
    unit = 1;
    while(optind < argc) {
        // Process dash options.
        while((opt = getopt(argc, argv, IO_CHAR_SERIAL_OPTIONS "c:b:t:T:u:")) != -1) {    
            switch(ttc(TTC_SET_OPTION, &devinit, opt)) {
            case 'c':
                devinit.clk = strtoul(optarg, &optarg, 0);
                if((cp = strchr(optarg, '/'))) {
                    devinit.div = strtoul(cp + 1, NULL, 0);
                }
                break;
            case 't':
                fifo_rx = strtoul(optarg, NULL, 0);
                if( !((fifo_rx == 1) || (fifo_rx == 4) || (fifo_rx == 8) || (fifo_rx == 14)) ) {
                    fprintf(stderr,"Illegal rx fifo trigger. \n");
                    fprintf(stderr,"Trigger number must be 1, 4, 8 or 14. \n");
                    fprintf(stderr,"Rx trigger will not be enabled.\n\n");
                    fifo_rx = 0;
                } else {
                   devinit.fifo &= 0xf0;
                   devinit.fifo |= fifo_rx;
                }
                break;
            case 'T':
                fifo_tx = strtoul(optarg, NULL, 0);
                if( !((fifo_tx == 1) || (fifo_tx == 4) || (fifo_tx == 8) || (fifo_tx == 14)) ) {
                    fprintf(stderr,"Illegal tx fifo size. \n");
                    fprintf(stderr,"Tx fifo size must be 1, 4, 8 or 14. \n");
                    fprintf(stderr,"Tx fifo will not be enabled.\n\n");
                    fifo_tx = 0;
                } else {
                   devinit.fifo &= 0x0f;
                   devinit.fifo |= (fifo_tx << 4);
                   
                }
                break;
            case 'u':
                unit = strtoul(optarg, NULL, 0);
                break;
            case 'b':       // value for baud rate 
                devinit.baud= atol(optarg);
                break;
            }
        }

        // Process ports and interrupts.
        while(optind < argc  &&  *(optarg = argv[optind]) != '-') {

            devinit.port = strtoull(optarg, &optarg, 16);
            if(*optarg == '^') {
                devinit.port_shift = strtoul(optarg + 1, &optarg, 0);
            }
            if(*optarg == ',') {
                devinit.intr = strtoul(optarg + 1, NULL, 0);
            }
            if ((dev_list[numports] = create_device(&devinit, unit++)) == NULL)
         {
            slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Initialization of /dev/ser%d (port 0x%llx) failed", unit - 1, devinit.port);
            fprintf(stderr, "io-char: Initialization of port 0x%llx failed\n", devinit.port);
         }
         else
            ++numports;
            ++optind;
        }
    }
    if(numports == 0) {
        link = NULL;
        for( ;; ) {
            link = query_default_device(&devinit, link);
            if(link == NULL) break;
            if ((dev_list[numports] = create_device(&devinit, unit++)) == NULL)
         {
            slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_ERROR, "io-char: Initialization of /dev/ser%d (port 0x%llx) failed", unit - 1, devinit.port);
            fprintf(stderr, "io-char: Initialization of port 0x%llx failed\n", devinit.port);
         }
         else
            ++numports;
        }
    }
   /* Enable all ports (Attach ISR and pathname entry) */ 
   for (i=0; i<numports; i++)
   {
      if(dev_list[i]->tty.verbose)
      {
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Port .......................... %s (0x%x)", dev_list[i]->tty.name, dev_list[i]->port[0]);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "IRQ ........................... 0x%x", dev_list[i]->intr);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Input Clock ................... %d", dev_list[i]->clk);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Clock Divisor ................. %d", dev_list[i]->div);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Tx fifo size .................. %d", (dev_list[i]->tty.fifo >> 4));
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Rx fifo trigger ............... %d", (dev_list[i]->tty.fifo & 0x0f));
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Input buffer size ............. %d", dev_list[i]->tty.ibuf.size);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Input flow control highwater .. %d", dev_list[i]->tty.highwater);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Output buffer size ............ %d", dev_list[i]->tty.obuf.size);
                slogf(_SLOG_SETCODE(_SLOGC_CHAR, 0), _SLOG_INFO, "Canonical buffer size ......... %d\n", dev_list[i]->tty.cbuf.size);
      }
      if (enable_device(dev_list[i]) != -1)
         enabled_cnt++;
   }
   return(enabled_cnt);
}