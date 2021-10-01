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
#include <errno.h>
#include <aarch64/rk3328.h>


#define RK_CLRSETBITS(clr, set)		((((clr) | (set)) << 16) | (set))
#define RK_SETBITS(set)			RK_CLRSETBITS(0, set)
#define RK_CLRBITS(clr)			RK_CLRSETBITS(clr, 0)

#define rk_clrsetreg(addr, clr, set)	\
				out32(addr, ((clr) | (set)) << 16 | (set))
#define rk_clrreg(addr, clr)		out32(addr, (clr) << 16)
#define rk_setreg(addr, set)		out32(addr, (set) << 16 | (set))
#define readl(addr)					in32(addr)