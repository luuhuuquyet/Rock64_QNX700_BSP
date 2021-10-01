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

#ifdef DEFN
    #define EXT
    #define INIT1(a)  = { a }
#else
    #define EXT extern
    #define INIT1(a)
#endif

#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <malloc.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <termios.h>
#include <devctl.h>
#include <sys/dcmd_chr.h>
#include <sys/iomsg.h>
#include <atomic.h>
#include <hw/inout.h>
#include <sys/io-char.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <arm/scif.h>
#include <drvr/hwinfo.h>
#include <sys/dispatch.h>

#include <aarch64/rk3328.h>
#include <hw/8250.h>

#define FIFO_SIZE   64

typedef struct dev_ser16550 {
    TTYDEV      tty;
    struct dev_ser16550  *next;
    unsigned        intr;
    unsigned        clk;
    unsigned        div;
    unsigned char   rx_fifo; /* rx fifo size */
    unsigned char   tx_fifo; /* tx fifo size */
    uintptr_t       port[REG_TOTAL];
} DEV_SER16550;

struct dev_list {
    struct dev_list *next;
    DEV_SER16550        *device;
    int             iid;
};

EXT TTYCTRL                     ttyctrl;
EXT struct dev_list             *devices;


#define MAX_DEVICES  16
#define FIFO_SIZE 16
#define DEFAULT_PRIORITY    24

#define CONFIG_DEBUG_UART_CLOCK 24000000
#define CONFIG_DEBUG_UART_DIV 16

DEV_SER16550*  create_device(TTYINIT *dip, unsigned unit);
void        ser_stty(DEV_SER16550 *dev);
int       ser_attach_intr(DEV_SER16550 *dev);
void        ser_detach_intr(DEV_SER16550 *dev);
void *query_default_device(TTYINIT *dip, void *link);
void set_port(unsigned port, unsigned mask, unsigned data);
const struct sigevent *ser_intr(void *area, int id);
unsigned options(int argc, char *argv[]);
void clear_device(const uintptr_t *port);
int enable_device(DEV_SER16550 *dev);
void sys_ttyinit( TTYINIT *dip );

#ifndef write_16550
#define write_16550(__port,__val)    out8(__port,__val)
#endif

#ifndef read_16550
#define read_16550(__port)   in8(__port)
#endif


#ifndef IE_SET_ALL
    #define IE_SET_ALL ( IE_RX | IE_TX | IE_LS | IE_MS )
#endif

#ifndef IE_CLR_ALL
    #define IE_CLR_ALL 0x0
#endif
