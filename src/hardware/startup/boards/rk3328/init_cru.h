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
#include <assert.h>
#include <aarch64/rk3328.h>
#include <stdint.h>
#include <sys/mman.h>
#include "rk3328_init.h"
#include "rk3328_cru.h"

#define ulong unsigned long 
#define u32 uint32_t 
#define u64 uint64_t 

/* define pll mode */
#define RKCLK_PLL_MODE_SLOW		0
#define RKCLK_PLL_MODE_NORMAL		1

enum {
	ROCKCHIP_SYSCON_NOC,
	ROCKCHIP_SYSCON_GRF,
	ROCKCHIP_SYSCON_SGRF,
	ROCKCHIP_SYSCON_PMU,
	ROCKCHIP_SYSCON_PMUGRF,
	ROCKCHIP_SYSCON_PMUSGRF,
	ROCKCHIP_SYSCON_CIC,
	ROCKCHIP_SYSCON_MSCH,
};

/* Standard Rockchip clock numbers */
enum rk_clk_id {
	CLK_OSC,
	CLK_ARM,
	CLK_DDR,
	CLK_CODEC,
	CLK_GENERAL,
	CLK_NEW,

	CLK_COUNT,
};


#define MHz		1000000
#define KHz		1000
#define OSC_HZ		(24 * MHz)
#define APLL_HZ		(600 * MHz)
#define GPLL_HZ		(576 * MHz)
#define CPLL_HZ		(594 * MHz)

#define CLK_CORE_HZ	(600 * MHz)
#define ACLKM_CORE_HZ	(300 * MHz)
#define PCLK_DBG_HZ	(300 * MHz)

#define PERIHP_ACLK_HZ	(144000 * KHz)
#define PERIHP_HCLK_HZ	(72000 * KHz)
#define PERIHP_PCLK_HZ	(72000 * KHz)

#define PWM_CLOCK_HZ    (74 * MHz)

enum apll_frequencies {
	APLL_816_MHZ,
	APLL_600_MHZ,
};

struct pll_div {
	uint32_t refdiv;
	uint32_t fbdiv;
	uint32_t postdiv1;
	uint32_t postdiv2;
	uint32_t frac;
};

#define RATE_TO_DIV(input_rate, output_rate) \
	((input_rate) / (output_rate) - 1);
#define DIV_TO_RATE(input_rate, div)    ((input_rate) / ((div) + 1))

#define PLL_DIVISORS(hz, _refdiv, _postdiv1, _postdiv2) {\
	.refdiv = _refdiv,\
	.fbdiv = (u32)((u64)hz * _refdiv * _postdiv1 * _postdiv2 / OSC_HZ),\
	.postdiv1 = _postdiv1, .postdiv2 = _postdiv2};

static const struct pll_div gpll_init_cfg = PLL_DIVISORS(GPLL_HZ, 1, 4, 1);
static const struct pll_div cpll_init_cfg = PLL_DIVISORS(CPLL_HZ, 2, 2, 1);

static const struct pll_div apll_816_cfg = PLL_DIVISORS(816 * MHz, 1, 2, 1);
static const struct pll_div apll_600_cfg = PLL_DIVISORS(600 * MHz, 1, 3, 1);

static const struct pll_div *apll_cfgs[] = {
	[APLL_816_MHZ] = &apll_816_cfg,
	[APLL_600_MHZ] = &apll_600_cfg,
};


enum {
	/* PLL_CON0 */
	PLL_POSTDIV1_SHIFT		= 12,
	PLL_POSTDIV1_MASK		= 0x7 << PLL_POSTDIV1_SHIFT,
	PLL_FBDIV_SHIFT			= 0,
	PLL_FBDIV_MASK			= 0xfff,

	/* PLL_CON1 */
	PLL_DSMPD_SHIFT			= 12,
	PLL_DSMPD_MASK			= 1 << PLL_DSMPD_SHIFT,
	PLL_INTEGER_MODE		= 1,
	PLL_LOCK_STATUS_SHIFT		= 10,
	PLL_LOCK_STATUS_MASK		= 1 << PLL_LOCK_STATUS_SHIFT,
	PLL_POSTDIV2_SHIFT		= 6,
	PLL_POSTDIV2_MASK		= 0x7 << PLL_POSTDIV2_SHIFT,
	PLL_REFDIV_SHIFT		= 0,
	PLL_REFDIV_MASK			= 0x3f,

	/* PLL_CON2 */
	PLL_FRACDIV_SHIFT		= 0,
	PLL_FRACDIV_MASK		= 0xffffff,

	/* MODE_CON */
	APLL_MODE_SHIFT			= 0,
	NPLL_MODE_SHIFT			= 1,
	DPLL_MODE_SHIFT			= 4,
	CPLL_MODE_SHIFT			= 8,
	GPLL_MODE_SHIFT			= 12,
	PLL_MODE_SLOW			= 0,
	PLL_MODE_NORM,

	/* CLKSEL_CON0 */
	CLK_CORE_PLL_SEL_APLL		= 0,
	CLK_CORE_PLL_SEL_GPLL,
	CLK_CORE_PLL_SEL_DPLL,
	CLK_CORE_PLL_SEL_NPLL,
	CLK_CORE_PLL_SEL_SHIFT		= 6,
	CLK_CORE_PLL_SEL_MASK		= 3 << CLK_CORE_PLL_SEL_SHIFT,
	CLK_CORE_DIV_SHIFT		= 0,
	CLK_CORE_DIV_MASK		= 0x1f,

	/* CLKSEL_CON1 */
	ACLKM_CORE_DIV_SHIFT		= 4,
	ACLKM_CORE_DIV_MASK		= 0x7 << ACLKM_CORE_DIV_SHIFT,
	PCLK_DBG_DIV_SHIFT		= 0,
	PCLK_DBG_DIV_MASK		= 0xF << PCLK_DBG_DIV_SHIFT,

	/* CLKSEL_CON28 */
	ACLK_PERIHP_PLL_SEL_CPLL	= 0,
	ACLK_PERIHP_PLL_SEL_GPLL,
	ACLK_PERIHP_PLL_SEL_HDMIPHY,
	ACLK_PERIHP_PLL_SEL_SHIFT	= 6,
	ACLK_PERIHP_PLL_SEL_MASK	= 3 << ACLK_PERIHP_PLL_SEL_SHIFT,
	ACLK_PERIHP_DIV_CON_SHIFT	= 0,
	ACLK_PERIHP_DIV_CON_MASK	= 0x1f,

	/* CLKSEL_CON29 */
	PCLK_PERIHP_DIV_CON_SHIFT	= 4,
	PCLK_PERIHP_DIV_CON_MASK	= 0x7 << PCLK_PERIHP_DIV_CON_SHIFT,
	HCLK_PERIHP_DIV_CON_SHIFT	= 0,
	HCLK_PERIHP_DIV_CON_MASK	= 3 << HCLK_PERIHP_DIV_CON_SHIFT,

	/* CLKSEL_CON22 */
	CLK_TSADC_DIV_CON_SHIFT		= 0,
	CLK_TSADC_DIV_CON_MASK		= 0x3ff,

	/* CLKSEL_CON23 */
	CLK_SARADC_DIV_CON_SHIFT	= 0,
	CLK_SARADC_DIV_CON_MASK		= 0x3ff << CLK_SARADC_DIV_CON_SHIFT,

	/* CLKSEL_CON24 */
	CLK_PWM_PLL_SEL_CPLL		= 0,
	CLK_PWM_PLL_SEL_GPLL,
	CLK_PWM_PLL_SEL_SHIFT		= 15,
	CLK_PWM_PLL_SEL_MASK		= 1 << CLK_PWM_PLL_SEL_SHIFT,
	CLK_PWM_DIV_CON_SHIFT		= 8,
	CLK_PWM_DIV_CON_MASK		= 0x7f << CLK_PWM_DIV_CON_SHIFT,

	CLK_SPI_PLL_SEL_CPLL		= 0,
	CLK_SPI_PLL_SEL_GPLL,
	CLK_SPI_PLL_SEL_SHIFT		= 7,
	CLK_SPI_PLL_SEL_MASK		= 1 << CLK_SPI_PLL_SEL_SHIFT,
	CLK_SPI_DIV_CON_SHIFT		= 0,
	CLK_SPI_DIV_CON_MASK		= 0x7f << CLK_SPI_DIV_CON_SHIFT,

	/* CLKSEL_CON30 */
	CLK_SDMMC_PLL_SEL_CPLL		= 0,
	CLK_SDMMC_PLL_SEL_GPLL,
	CLK_SDMMC_PLL_SEL_24M,
	CLK_SDMMC_PLL_SEL_USBPHY,
	CLK_SDMMC_PLL_SHIFT		= 8,
	CLK_SDMMC_PLL_MASK		= 0x3 << CLK_SDMMC_PLL_SHIFT,
	CLK_SDMMC_DIV_CON_SHIFT          = 0,
	CLK_SDMMC_DIV_CON_MASK           = 0xff << CLK_SDMMC_DIV_CON_SHIFT,

	/* CLKSEL_CON32 */
	CLK_EMMC_PLL_SEL_CPLL		= 0,
	CLK_EMMC_PLL_SEL_GPLL,
	CLK_EMMC_PLL_SEL_24M,
	CLK_EMMC_PLL_SEL_USBPHY,
	CLK_EMMC_PLL_SHIFT		= 8,
	CLK_EMMC_PLL_MASK		= 0x3 << CLK_EMMC_PLL_SHIFT,
	CLK_EMMC_DIV_CON_SHIFT          = 0,
	CLK_EMMC_DIV_CON_MASK           = 0xff << CLK_EMMC_DIV_CON_SHIFT,

	/* CLKSEL_CON34 */
	CLK_I2C_PLL_SEL_CPLL		= 0,
	CLK_I2C_PLL_SEL_GPLL,
	CLK_I2C_DIV_CON_MASK		= 0x7f,
	CLK_I2C_PLL_SEL_MASK		= 1,
	CLK_I2C1_PLL_SEL_SHIFT		= 15,
	CLK_I2C1_DIV_CON_SHIFT		= 8,
	CLK_I2C0_PLL_SEL_SHIFT		= 7,
	CLK_I2C0_DIV_CON_SHIFT		= 0,

	/* CLKSEL_CON35 */
	CLK_I2C3_PLL_SEL_SHIFT		= 15,
	CLK_I2C3_DIV_CON_SHIFT		= 8,
	CLK_I2C2_PLL_SEL_SHIFT		= 7,
	CLK_I2C2_DIV_CON_SHIFT		= 0,
};

#define VCO_MAX_KHZ	(3200 * (MHz / KHz))
#define VCO_MIN_KHZ	(800 * (MHz / KHz))
#define OUTPUT_MAX_KHZ	(3200 * (MHz / KHz))
#define OUTPUT_MIN_KHZ	(16 * (MHz / KHz))

/*
 *  the div restructions of pll in integer mode, these are defined in
 *  * CRU_*PLL_CON0 or PMUCRU_*PLL_CON0
 */
#define PLL_DIV_MIN	16
#define PLL_DIV_MAX	3200

/*
 * How to calculate the PLL(from TRM V0.3 Part 1 Page 63):
 * Formulas also embedded within the Fractional PLL Verilog model:
 * If DSMPD = 1 (DSM is disabled, "integer mode")
 * FOUTVCO = FREF / REFDIV * FBDIV
 * FOUTPOSTDIV = FOUTVCO / POSTDIV1 / POSTDIV2
 * Where:
 * FOUTVCO = Fractional PLL non-divided output frequency
 * FOUTPOSTDIV = Fractional PLL divided output frequency
 *               (output of second post divider)
 * FREF = Fractional PLL input reference frequency, (the OSC_HZ 24MHz input)
 * REFDIV = Fractional PLL input reference clock divider
 * FBDIV = Integer value programmed into feedback divide
 *
 */
struct rk3328_clk_priv {
	struct rk3328_cru *cru;
	ulong rate;
};

struct clk {
	unsigned long id;
};

struct rk3328_cru {
	uint32_t apll_con[5];
	uint32_t reserved1[3];
	uint32_t dpll_con[5];
	uint32_t reserved2[3];
	uint32_t cpll_con[5];
	uint32_t reserved3[3];
	uint32_t gpll_con[5];
	uint32_t reserved4[3];
	uint32_t mode_con;
	uint32_t misc;
	uint32_t reserved5[2];
	uint32_t glb_cnt_th;
	uint32_t glb_rst_st;
	uint32_t glb_srst_snd_value;
	uint32_t glb_srst_fst_value;
	uint32_t npll_con[5];
	uint32_t reserved6[(0x100 - 0xb4) / 4];
	uint32_t clksel_con[53];
	uint32_t reserved7[(0x200 - 0x1d4) / 4];
	uint32_t clkgate_con[29];
	uint32_t reserved8[3];
	uint32_t ssgtbl[32];
	uint32_t softrst_con[12];
	uint32_t reserved9[(0x380 - 0x330) / 4];
	uint32_t sdmmc_con[2];
	uint32_t sdio_con[2];
	uint32_t emmc_con[2];
	uint32_t sdmmc_ext_con[2];
};

void init_clk();

void rkclk_set_pll(enum rk_clk_id clk_id, const struct pll_div *div);
void rkclk_init();
void rk3328_configure_cpu(enum apll_frequencies apll_freq);
ulong rk3328_i2c_get_clk(ulong clk_id);
ulong rk3328_i2c_set_clk(ulong clk_id, uint hz);
ulong rk3328_mmc_get_clk(uint clk_id);
ulong rk3328_mmc_set_clk(ulong clk_id, ulong set_rate);
ulong rk3328_pwm_get_clk();
ulong rk3328_pwm_set_clk(uint hz);
ulong rk3328_clk_get_rate(ulong clk_id);
ulong rk3328_clk_set_rate(ulong clk_id, ulong rate);