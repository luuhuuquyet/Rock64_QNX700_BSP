/*
 * $QNXLicenseC:
 * Copyright 2017, QNX Software Systems.
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
#include "startup.h"
#include "aarch64/aarch64_tlb.h"

/*
 * Enable/disable the various system controls.
 * This code is hardware dependent and may have to be changed
 * changed by end users.
 */

uint64_t aarch64_tlb[TLB_SIZE] __attribute__ ((aligned(64 * 1024)));

aarch64_tlb_t board_tlb[] = {
    {
        .start = 0,
        .len   = MEG(2048)- MEG(32),
        .attr  = (0x4 << 2),
    },
    {
        -1, -1, 0,
    },
};

void board_mmu_enable(){
    aarch64_setup_tlb(board_tlb, aarch64_tlb);
    aarch64_enable_mmu((uint64_t)aarch64_tlb);
}

void board_mmu_disable() {
    aarch64_disable_mmu();
}

void board_alignment_check_enable() {
    aarch64_alignment_check_enable();
}

void board_alignment_check_disable() {
    aarch64_alignment_check_disable();
}

void board_dcache_enable() {
    aarch64_dcache_enable();
}

void board_dcache_disable() {
    aarch64_dcache_disable();
}

void board_icache_enable() {
    aarch64_icache_enable();
}

void board_icache_disable() {
    aarch64_icache_disable();
}

void board_enable_caches(){
    board_icache_enable();
    board_dcache_enable();
}

void board_disable_caches() {
    board_icache_disable();
    board_dcache_disable();
}
