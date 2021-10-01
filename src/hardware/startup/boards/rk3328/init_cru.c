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

#include "init_cru.h"
#define data(clr, set)		(((clr) | (set)) << 16 | (set))

void init_clk(){
	uintptr_t pdev;
	rkclk_init();
	// rk3328_configure_cpu(0);
}

void rkclk_set_pll(enum rk_clk_id clk_id, const struct pll_div *div){
	u32 pll_con;
	u32 mode_shift, mode_mask;
	pll_con = NULL;
	mode_shift = 0;
	switch (clk_id) {
	case CLK_ARM:
		pll_con = RK3328_CRU_APLL_CON0;
		mode_shift = APLL_MODE_SHIFT;
		break;
	case CLK_DDR:
		pll_con = RK3328_CRU_DPLL_CON0;
		mode_shift = DPLL_MODE_SHIFT;
		break;
	case CLK_CODEC:
		pll_con = RK3328_CRU_CPLL_CON0;
		mode_shift = CPLL_MODE_SHIFT;
		break;
	case CLK_GENERAL:
		pll_con = RK3328_CRU_GPLL_CON0;
		mode_shift = GPLL_MODE_SHIFT;
		break;
	case CLK_NEW:
		pll_con = RK3328_CRU_NPLL_CON0;
		mode_shift = NPLL_MODE_SHIFT;
		break;
	default:
		break;
	}
	mode_mask = 1 << mode_shift;
	/* All 8 PLLs have same VCO and output frequency range restrictions. */
	u32 vco_khz = OSC_HZ / 1000 * div->fbdiv / div->refdiv;
	u32 output_khz = vco_khz / div->postdiv1 / div->postdiv2;

	kprintf("PLL at %p: fbdiv=%d, refdiv=%d, postdiv1=%d, \
	      postdiv2=%d, vco=%u khz, output=%u khz\n",
	      pll_con, div->fbdiv, div->refdiv, div->postdiv1,
	      div->postdiv2, vco_khz, output_khz);
	assert(vco_khz >= VCO_MIN_KHZ && vco_khz <= VCO_MAX_KHZ &&
	       output_khz >= OUTPUT_MIN_KHZ && output_khz <= OUTPUT_MAX_KHZ &&
	       div->fbdiv >= PLL_DIV_MIN && div->fbdiv <= PLL_DIV_MAX);
	/*
	 * When power on or changing PLL setting,
	 * we must force PLL into slow mode to ensure output stable clock.
	 */
	rk_clrsetreg(RK3328_CRU_BASE + RK3328_CRU_CRU_MODE, mode_mask, PLL_MODE_SLOW << mode_shift);
	/* use integer mode */
	rk_clrsetreg(RK3328_CRU_BASE + pll_con + 0x4, PLL_DSMPD_MASK,
		     PLL_INTEGER_MODE << PLL_DSMPD_SHIFT);

	rk_clrsetreg(RK3328_CRU_BASE + pll_con ,
		     PLL_FBDIV_MASK | PLL_POSTDIV1_MASK,
		     (div->fbdiv << PLL_FBDIV_SHIFT) |
		     (div->postdiv1 << PLL_POSTDIV1_SHIFT));


	rk_clrsetreg(RK3328_CRU_BASE + pll_con + 0x4 ,
		     PLL_POSTDIV2_MASK | PLL_REFDIV_MASK,
		     (div->postdiv2 << PLL_POSTDIV2_SHIFT) |
		     (div->refdiv << PLL_REFDIV_SHIFT));

	/* waiting for pll lock */
	while (!(readl(RK3328_CRU_BASE + pll_con + 0x4) & (1 << PLL_LOCK_STATUS_SHIFT)))
		delay(1);
	/* pll enter normal mode */
	rk_clrsetreg(RK3328_CRU_BASE + RK3328_CRU_CRU_MODE, mode_mask, PLL_MODE_NORM << mode_shift);

}
void rkclk_init(){

	u32 aclk_div;
	u32 hclk_div;
	u32 pclk_div;

	/* configure gpll cpll */
	rkclk_set_pll(CLK_GENERAL, &gpll_init_cfg);
	rkclk_set_pll(CLK_CODEC, &cpll_init_cfg);

	/* configure perihp aclk, hclk, pclk */
	aclk_div = GPLL_HZ / PERIHP_ACLK_HZ - 1;
	hclk_div = PERIHP_ACLK_HZ / PERIHP_HCLK_HZ - 1;
	pclk_div = PERIHP_ACLK_HZ / PERIHP_PCLK_HZ - 1;

	rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON28,
		     ACLK_PERIHP_PLL_SEL_MASK | ACLK_PERIHP_DIV_CON_MASK,
		     ACLK_PERIHP_PLL_SEL_GPLL << ACLK_PERIHP_PLL_SEL_SHIFT |
		     aclk_div << ACLK_PERIHP_DIV_CON_SHIFT);
	rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON29,
		     PCLK_PERIHP_DIV_CON_MASK | HCLK_PERIHP_DIV_CON_MASK,
		     pclk_div << PCLK_PERIHP_DIV_CON_SHIFT |
		     hclk_div << HCLK_PERIHP_DIV_CON_SHIFT);

}

void rk3328_configure_cpu(enum apll_frequencies apll_freq){
	u32 clk_core_div;
	u32 aclkm_div;
	u32 pclk_dbg_div;

	rkclk_set_pll(CLK_ARM, apll_cfgs[apll_freq]);

	clk_core_div = APLL_HZ / CLK_CORE_HZ - 1;
	aclkm_div = APLL_HZ / ACLKM_CORE_HZ / (clk_core_div + 1) - 1;
	pclk_dbg_div = APLL_HZ / PCLK_DBG_HZ / (clk_core_div + 1) - 1;

	rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON0,
		     CLK_CORE_PLL_SEL_MASK | CLK_CORE_DIV_MASK,
		     CLK_CORE_PLL_SEL_APLL << CLK_CORE_PLL_SEL_SHIFT |
		     clk_core_div << CLK_CORE_DIV_SHIFT);

	rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON1,
		     PCLK_DBG_DIV_MASK | ACLKM_CORE_DIV_MASK,
		     pclk_dbg_div << PCLK_DBG_DIV_SHIFT |
		     aclkm_div << ACLKM_CORE_DIV_SHIFT);
}
ulong rk3328_i2c_get_clk( ulong clk_id){
	u32 div, con;

	switch (clk_id) {
	case SCLK_I2C0:
		con = readl(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON34);
		div = con >> CLK_I2C0_DIV_CON_SHIFT & CLK_I2C_DIV_CON_MASK;
		break;
	case SCLK_I2C1:
		con = readl(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON34);
		div = con >> CLK_I2C1_DIV_CON_SHIFT & CLK_I2C_DIV_CON_MASK;
		break;
	case SCLK_I2C2:
		con = readl(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON35);
		div = con >> CLK_I2C2_DIV_CON_SHIFT & CLK_I2C_DIV_CON_MASK;
		break;
	case SCLK_I2C3:
		con = readl(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON35);
		div = con >> CLK_I2C3_DIV_CON_SHIFT & CLK_I2C_DIV_CON_MASK;
		break;
	default:
		kprintf("do not support this i2c bus\n");
		return -EINVAL;
	}

	return DIV_TO_RATE(GPLL_HZ, div);
}
ulong rk3328_i2c_set_clk( ulong clk_id, uint hz){
	int src_clk_div;

	src_clk_div = GPLL_HZ / hz;
	assert(src_clk_div - 1 < 127);

	switch (clk_id) {
	case SCLK_I2C0:
		rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON34,
			     CLK_I2C_DIV_CON_MASK << CLK_I2C0_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_MASK << CLK_I2C0_PLL_SEL_SHIFT,
			     (src_clk_div - 1) << CLK_I2C0_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_GPLL << CLK_I2C0_PLL_SEL_SHIFT);
		break;
	case SCLK_I2C1:
		rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON34,
			     CLK_I2C_DIV_CON_MASK << CLK_I2C1_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_MASK << CLK_I2C1_PLL_SEL_SHIFT,
			     (src_clk_div - 1) << CLK_I2C1_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_GPLL << CLK_I2C1_PLL_SEL_SHIFT);
		break;
	case SCLK_I2C2:
		rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON35,
			     CLK_I2C_DIV_CON_MASK << CLK_I2C2_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_MASK << CLK_I2C2_PLL_SEL_SHIFT,
			     (src_clk_div - 1) << CLK_I2C2_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_GPLL << CLK_I2C2_PLL_SEL_SHIFT);
		break;
	case SCLK_I2C3:
		rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON35,
			     CLK_I2C_DIV_CON_MASK << CLK_I2C3_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_MASK << CLK_I2C3_PLL_SEL_SHIFT,
			     (src_clk_div - 1) << CLK_I2C3_DIV_CON_SHIFT |
			     CLK_I2C_PLL_SEL_GPLL << CLK_I2C3_PLL_SEL_SHIFT);
		break;
	default:
		kprintf("do not support this i2c bus\n");
		return -EINVAL;
	}

	return DIV_TO_RATE(GPLL_HZ, src_clk_div);
}
ulong rk3328_mmc_get_clk(uint clk_id){
	u32 div, con, con_id;
	u32 addr;
	switch (clk_id) {
	case HCLK_SDMMC:
	case SCLK_SDMMC:
		con_id = 30;
		addr = RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON30;
		break;
	case HCLK_EMMC:
	case SCLK_EMMC:
		con_id = 32;
		addr = RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON32;
		break;
	default:
		return -1;
	}
	con = readl(addr);
	div = (con & CLK_EMMC_DIV_CON_MASK) >> CLK_EMMC_DIV_CON_SHIFT;

	if ((con & CLK_EMMC_PLL_MASK) >> CLK_EMMC_PLL_SHIFT
	    == CLK_EMMC_PLL_SEL_24M)
		return DIV_TO_RATE(OSC_HZ, div);
	else
		return DIV_TO_RATE(GPLL_HZ, div);
}
ulong rk3328_mmc_set_clk(ulong clk_id, ulong set_rate){
	int src_clk_div;
	u32 con_id;
	u32 addr;

	switch (clk_id) {
	case HCLK_SDMMC:
	case SCLK_SDMMC:
		con_id = 30;
		addr = RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON30;
		break;
	case HCLK_EMMC:
	case SCLK_EMMC:
		con_id = 32;
		addr = RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON32;
		break;
	default:
		return -1;
	}
	/* Select clk_sdmmc/emmc source from GPLL by default */
	src_clk_div = GPLL_HZ / set_rate;

	if (src_clk_div > 127) {
		/* use 24MHz source for 400KHz clock */
		src_clk_div = OSC_HZ / set_rate;
		rk_clrsetreg(addr,
			     CLK_EMMC_PLL_MASK | CLK_EMMC_DIV_CON_MASK,
			     CLK_EMMC_PLL_SEL_24M << CLK_EMMC_PLL_SHIFT |
			     (src_clk_div - 1) << CLK_EMMC_DIV_CON_SHIFT);
	} else {
		rk_clrsetreg(addr,
			     CLK_EMMC_PLL_MASK | CLK_EMMC_DIV_CON_MASK,
			     CLK_EMMC_PLL_SEL_GPLL << CLK_EMMC_PLL_SHIFT |
			     (src_clk_div - 1) << CLK_EMMC_DIV_CON_SHIFT);
	}

	return rk3328_mmc_get_clk(clk_id);
}
ulong rk3328_pwm_get_clk(){
	u32 div, con;

	con = readl(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON24);
	div = (con & CLK_PWM_DIV_CON_MASK) >> CLK_PWM_DIV_CON_SHIFT;

	return DIV_TO_RATE(GPLL_HZ, div);
}
ulong rk3328_pwm_set_clk(uint hz){
	u32 div = GPLL_HZ / hz;

	rk_clrsetreg(RK3328_CRU_BASE +  RK3328_CRU_CLKSEL_CON24,
		     CLK_PWM_PLL_SEL_MASK | CLK_PWM_DIV_CON_MASK,
		     CLK_PWM_PLL_SEL_GPLL << CLK_PWM_PLL_SEL_SHIFT |
		     (div - 1) << CLK_PWM_DIV_CON_SHIFT);

	return DIV_TO_RATE(GPLL_HZ, div);
}
ulong rk3328_clk_get_rate(ulong clk_id){
	ulong rate = 0;

	switch (clk_id) {
	case 0 ... 29:
		return 0;
	case HCLK_SDMMC:
	case HCLK_EMMC:
	case SCLK_SDMMC:
	case SCLK_EMMC:
		rate = rk3328_mmc_get_clk(clk_id);
		break;
	case SCLK_I2C0:
	case SCLK_I2C1:
	case SCLK_I2C2:
	case SCLK_I2C3:
		rate = rk3328_i2c_get_clk(clk_id);
		break;
	case SCLK_PWM:
		rate = rk3328_pwm_get_clk();
		break;
	default:
		return -ENOENT;
	}

	return rate;
}
ulong rk3328_clk_set_rate(ulong clk_id, ulong rate){
	ulong ret = 0;

	switch (clk_id) {
	case 0 ... 29:
		return 0;
	case HCLK_SDMMC:
	case HCLK_EMMC:
	case SCLK_SDMMC:
	case SCLK_EMMC:
		ret = rk3328_mmc_set_clk(clk_id, rate);
		break;
	case SCLK_I2C0:
	case SCLK_I2C1:
	case SCLK_I2C2:
	case SCLK_I2C3:
		ret = rk3328_i2c_set_clk(clk_id, rate);
		break;
	case SCLK_PWM:
		ret = rk3328_pwm_set_clk(rate);
		break;
	default:
		return -ENOENT;
	}

	return ret;
}