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

/*
 * _start.S
 *
 * This code runs as the first instructions after control has transferred
 * from any bootup monitor.  This module defines a minimal bootup stack,
 * and sets SP to this stack, and then starts running C code in _main().
 *
 */

    .text
    .align 2

/*
 * EL3 needs to perform some initial GIC configuration
 */
#define GIC_BASE            0xFF810000
#define GICC_PMR_OFF        0x2004
#define GICD_IGROUPR_OFF    0x1080

    .extern cstart
    .global _start

_start:
    /* NOTE:
     *  Do NOT modify registers X0-X3 before jumping to the cstart label.
     *  These registers may contain information provided by the IPL and
     *  cstart will save them in the boot_regs variable for later perusal
     *  by other portions of startup.
     */

    /*
     * Set up EL3 state if necessary
     */
    mrs     x9, CurrentEL
    cmp     x9, #0xc                // EL3
    bne     0f
    bl      setup_el3
0:

    /*
     * call cstart
     */
    b       cstart

    /*
     * Setup minimal GIC state
     */
setup_el3:
    /*
     * Set Priority Mask to enable forwarding of interrupts to cpu interface.
     * Configure interrupts as insecure Group1 interrupts.
     */
    mov     x4, #GIC_BASE
    mov     w5, #0xf0
    str     w5, [x4, #GICC_PMR_OFF]
    mov     w5, #0xffffffff
    str     w5, [x4, #GICD_IGROUPR_OFF]
    str     w5, [x4, #GICD_IGROUPR_OFF+4]
    str     w5, [x4, #GICD_IGROUPR_OFF+8]

    /*
     * Set default generic timer frequency
     */
    ldr     w4, cntfrq_default
    msr     cntfrq_el0, x4
    ret

cntfrq_default: .word   100000000   // bogus default cntfrq_el0 value
