#
# Copyright 2017, QNX Software Systems.
#
# Licensed under the Apache License, Version 2.0 (the "License"). You
# may not reproduce, modify or distribute this software except in
# compliance with the License. You may obtain a copy of the License
# at: http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTIES OF ANY KIND, either express or implied.
#
# This file may contain contributions from others, either as
# contributors under the License or as licensors under other terms.
# Please review this entire file for other proprietary rights or license
# notices, as well as the QNX Development Suite License Guide at
# http://licensing.qnx.com/license-guide/ for other information.
#

#include "callout.ah"
#include <aarch64/rk3328.h>

/*
 * -----------------------------------------------------------------------
 * Routine to patch callout code
 *
 * On entry:
 *  r0 - physical address of syspage
 *  r1 - virtual  address of syspage
 *  r2 - offset from start of syspage to start of the callout routine
 *  r3 - offset from start of syspage to read/write data used by callout
 * -----------------------------------------------------------------------
 */
patch_reboot:
    sub     sp, sp, #16
    stp     x19, x30, [sp]

    add     x19, x0, x2     // x19 = address of callout routine

    /*
     * Map reset control registers
     */
    mov     x0, #0x100
    adr     x1, Lpaddr
    bl      callout_io_map_indirect

    /*
     * Patch the callout routine
     */
    CALLOUT_PATCH   x19, w4, w5

    ldp     x19, x30, [sp]
    add     sp, sp, #16
    ret

            .align 3
Lpaddr:     .quad    RK3328_WDT_BASE


CALLOUT_START(reboot_rk3328, 0, patch_reboot)
    /*
     * Get the Watchdog Timer base address (patched)
     */
    mov     x5, #0xabcd             // UART base address (patched)
    movk    x5, #0xabcd, lsl #16
    movk    x5, #0xabcd, lsl #32
    movk    x5, #0xabcd, lsl #48

    ldrb    w0, [x5,#RK3328_WDT_CR]

_do_reboot:
    mov     w2, #0
    str     w2, [x5, #RK3328_WDT_CCVR]

    mov     w2, #0
    str     w2, [x5, #RK3328_WDT_CR]

0:  b       0b
CALLOUT_END(reboot_rk3328)
