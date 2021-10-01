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

/*
 * Rockchips specific WDT support.
 * 
 */

#include "startup.h"
#include <aarch64/rk3328.h>

#define CONFIG_DW_WDT_CLOCK_KHZ     25000
#define CONFIG_HW_WATCHDOG_TIMEOUT_MS   30000

static inline int log_2_n_round_up(unsigned int n)
{
    int log2n = -1;
    unsigned int temp = n;

    while (temp) {
        log2n++;
        temp >>= 1;
    }

    if (n & (n - 1))
        return log2n + 1; /* not power of 2 - round up */
    else
        return log2n; /* power of 2 */
}

void wdt_enable()
{
    unsigned int val;
    int i;

    /* reset to disable the watchdog */
    if (in32(RK3328_WDT_BASE + RK3328_WDT_CR) & 0x1)
        out32(RK3328_WDT_BASE + RK3328_WDT_CRR, RK3328_WDT_CRR_RESTART_VAL);

    /* calculate the timeout range value */
    i = (log_2_n_round_up(CONFIG_HW_WATCHDOG_TIMEOUT_MS * CONFIG_DW_WDT_CLOCK_KHZ)) - 16;
    if (i > 15)
        i = 15;
    if (i < 0)
        i = 0;

    out32((RK3328_WDT_BASE + RK3328_WDT_TORR),(i | (i << 4)));

    /* enable the watchdog */
    out32((RK3328_WDT_BASE + RK3328_WDT_CR), ((RK3328_WDT_CR_RMOD_VAL << RK3328_WDT_CR_RMOD_OFFSET) |
          (0x1 << RK3328_WDT_CR_EN_OFFSET)));
    /* reset the watchdog */
    if (in32(RK3328_WDT_BASE + RK3328_WDT_CR) & 0x1)
        out32(RK3328_WDT_BASE + RK3328_WDT_CRR, RK3328_WDT_CRR_RESTART_VAL);
}
