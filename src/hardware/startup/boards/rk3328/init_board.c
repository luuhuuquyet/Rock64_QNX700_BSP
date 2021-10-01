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
#include "rk3328_init.h"
#include "init_cru.h"

/**
 * enum type index corresponding to rockchip_perpin_drv_list arrays index.
 */
enum rockchip_pin_drv_type {
	DRV_TYPE_IO_DEFAULT = 0,
	DRV_TYPE_IO_1V8_OR_3V0,
	DRV_TYPE_IO_1V8_ONLY,
	DRV_TYPE_IO_1V8_3V0_AUTO,
	DRV_TYPE_IO_3V3_ONLY,
	DRV_TYPE_IO_WIDE_LEVEL,
	DRV_TYPE_IO_NARROW_LEVEL,
	DRV_TYPE_MAX
};


typedef enum rockchip_pin_pull_type {
	NORMAL = 0,
	PULL_UP,
	PULL_DOWN,
	REPEATER
} pull_type;

/**
 * enum type of pin extra drive alignment.
 */
enum rockchip_pin_extra_drv_type {
	DRV_TYPE_EXTRA_DEFAULT = 0,
	DRV_TYPE_EXTRA_SAME_OFFSET,
	DRV_TYPE_EXTRA_SAME_BITS
};


enum {
	/* GPIO0A_IOMUX */

	//HDMI CE
	GPIO0A3_SEL_SHIFT	= 6,
	GPIO0A3_SEL_MASK	= 3 << GPIO0A3_SEL_SHIFT,
	GPIO0A3_HDMI_CE		= 1,

	GPIO0A4_SEL_SHIFT	= 8,
	GPIO0A4_SEL_MASK	= 3 << GPIO0A4_SEL_SHIFT,
	GPIO0A4_HDMI_HDP	= 1,

	GPIO0A5_SEL_SHIFT	= 10,
	GPIO0A5_SEL_MASK	= 3 << GPIO0A5_SEL_SHIFT,
	GPIO0A5_I2C3_SCL	= 2,

	GPIO0A6_SEL_SHIFT	= 12,
	GPIO0A6_SEL_MASK	= 3 << GPIO0A6_SEL_SHIFT,
	GPIO0A6_I2C3_SDA	= 2,

	GPIO0A7_SEL_SHIFT	= 14,
	GPIO0A7_SEL_MASK	= 3 << GPIO0A7_SEL_SHIFT,
	GPIO0A7_EMMC_DATA0	= 2,

	/* GPIO0D_IOMUX*/
	GPIO0D6_SEL_SHIFT	= 12,
	GPIO0D6_SEL_MASK	= 3 << GPIO0D6_SEL_SHIFT,
	GPIO0D6_GPIO		= 0,
	GPIO0D6_SDMMC0_PWRENM1	= 3,

	/* GPIO1A_IOMUX */
	GPIO1A0_SEL_SHIFT	= 0,
	GPIO1A0_SEL_MASK	= 0x3fff << GPIO1A0_SEL_SHIFT,
	GPIO1A0_CARD_DATA_CLK_CMD_DETN	= 0x1555,

	/* GPIO2A_IOMUX */
	GPIO2A0_SEL_SHIFT	= 0,
	GPIO2A0_SEL_MASK	= 3 << GPIO2A0_SEL_SHIFT,
	GPIO2A0_UART2_TX_M1	= 1,

	GPIO2A1_SEL_SHIFT	= 2,
	GPIO2A1_SEL_MASK	= 3 << GPIO2A1_SEL_SHIFT,
	GPIO2A1_UART2_RX_M1	= 1,

	GPIO2A2_SEL_SHIFT	= 4,
	GPIO2A2_SEL_MASK	= 3 << GPIO2A2_SEL_SHIFT,
	GPIO2A2_PWM_IR		= 1,

	GPIO2A4_SEL_SHIFT	= 8,
	GPIO2A4_SEL_MASK	= 3 << GPIO2A4_SEL_SHIFT,
	GPIO2A4_PWM_0		= 1,
	GPIO2A4_I2C1_SDA,

	GPIO2A5_SEL_SHIFT	= 10,
	GPIO2A5_SEL_MASK	= 3 << GPIO2A5_SEL_SHIFT,
	GPIO2A5_PWM_1		= 1,
	GPIO2A5_I2C1_SCL,

	GPIO2A6_SEL_SHIFT	= 12,
	GPIO2A6_SEL_MASK	= 3 << GPIO2A6_SEL_SHIFT,
	GPIO2A6_PWM_2		= 1,

	GPIO2A7_SEL_SHIFT	= 14,
	GPIO2A7_SEL_MASK	= 3 << GPIO2A7_SEL_SHIFT,
	GPIO2A7_GPIO		= 0,
	GPIO2A7_SDMMC0_PWRENM0,

	/* GPIO2BL_IOMUX */
	GPIO2BL0_SEL_SHIFT	= 0,
	GPIO2BL0_SEL_MASK	= 0x3f << GPIO2BL0_SEL_SHIFT,
	GPIO2BL0_SPI_CLK_TX_RX_M0	= 0x15,

	GPIO2BL3_SEL_SHIFT	= 6,
	GPIO2BL3_SEL_MASK	= 3 << GPIO2BL3_SEL_SHIFT,
	GPIO2BL3_SPI_CSN0_M0	= 1,

	GPIO2BL4_SEL_SHIFT	= 8,
	GPIO2BL4_SEL_MASK	= 3 << GPIO2BL4_SEL_SHIFT,
	GPIO2BL4_SPI_CSN1_M0	= 1,

	GPIO2BL5_SEL_SHIFT	= 10,
	GPIO2BL5_SEL_MASK	= 3 << GPIO2BL5_SEL_SHIFT,
	GPIO2BL5_I2C2_SDA	= 1,

	GPIO2BL6_SEL_SHIFT	= 12,
	GPIO2BL6_SEL_MASK	= 3 << GPIO2BL6_SEL_SHIFT,
	GPIO2BL6_I2C2_SCL	= 1,

	/* GPIO2D_IOMUX */
	GPIO2D0_SEL_SHIFT	= 0,
	GPIO2D0_SEL_MASK	= 3 << GPIO2D0_SEL_SHIFT,
	GPIO2D0_I2C0_SCL	= 1,

	GPIO2D1_SEL_SHIFT	= 2,
	GPIO2D1_SEL_MASK	= 3 << GPIO2D1_SEL_SHIFT,
	GPIO2D1_I2C0_SDA	= 1,

	GPIO2D4_SEL_SHIFT	= 8,
	GPIO2D4_SEL_MASK	= 0xff << GPIO2D4_SEL_SHIFT,
	GPIO2D4_EMMC_DATA1234	= 0xaa,

	/* GPIO3C_IOMUX */
	GPIO3C0_SEL_SHIFT	= 0,
	GPIO3C0_SEL_MASK	= 0x3fff << GPIO3C0_SEL_SHIFT,
	GPIO3C0_EMMC_DATA567_PWR_CLK_RSTN_CMD	= 0x2aaa,

	/* COM_IOMUX */
	IOMUX_SEL_UART2_SHIFT	= 0,
	IOMUX_SEL_UART2_MASK	= 3 << IOMUX_SEL_UART2_SHIFT,
	IOMUX_SEL_UART2_M0	= 0,
	IOMUX_SEL_UART2_M1,

	IOMUX_SEL_SPI_SHIFT	= 4,
	IOMUX_SEL_SPI_MASK	= 3 << IOMUX_SEL_SPI_SHIFT,
	IOMUX_SEL_SPI_M0	= 0,
	IOMUX_SEL_SPI_M1,
	IOMUX_SEL_SPI_M2,

	IOMUX_SEL_SDMMC_SHIFT	= 7,
	IOMUX_SEL_SDMMC_MASK	= 1 << IOMUX_SEL_SDMMC_SHIFT,
	IOMUX_SEL_SDMMC_M0	= 0,
	IOMUX_SEL_SDMMC_M1,
};




// Normal
static void init_pwm0 (void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		    GPIO2A4_SEL_MASK,
		    GPIO2A4_PWM_0 << GPIO2A4_SEL_SHIFT);

	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		    GPIO2A4_SEL_MASK,
		    NORMAL << GPIO2A4_SEL_SHIFT);
}

// Normal
static void init_pwm1 (void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		    GPIO2A5_SEL_MASK,
		    GPIO2A5_PWM_1 << GPIO2A5_SEL_SHIFT);

	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		    GPIO2A5_SEL_MASK,
		    NORMAL << GPIO2A5_SEL_SHIFT);	
}
// Normal
static void init_pwm2 (void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		    GPIO2A6_SEL_MASK,
		    GPIO2A6_PWM_2 << GPIO2A6_SEL_SHIFT);
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		    GPIO2A6_SEL_MASK,
		    NORMAL << GPIO2A6_SEL_SHIFT);		
}

// Normal
static void init_pwm3 (void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		    GPIO2A2_SEL_MASK,
		    GPIO2A2_PWM_IR << GPIO2A2_SEL_SHIFT);
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		    GPIO2A2_SEL_MASK,
		    NORMAL << GPIO2A2_SEL_SHIFT);

}

static void init_i2c0(void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2D_IOMUX,
		GPIO2D0_SEL_MASK | GPIO2D1_SEL_MASK,
		GPIO2D0_I2C0_SCL << GPIO2D0_SEL_SHIFT |
		GPIO2D1_I2C0_SDA << GPIO2D1_SEL_SHIFT);
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2D_P,
		GPIO2D0_SEL_MASK | GPIO2D1_SEL_MASK,
		NORMAL << GPIO2D0_SEL_SHIFT |
		NORMAL << GPIO2D1_SEL_SHIFT);
}
static void init_i2c1(void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		GPIO2A4_SEL_MASK | GPIO2A5_SEL_MASK,
		GPIO2A5_I2C1_SCL << GPIO2A5_SEL_SHIFT |
		GPIO2A4_I2C1_SDA << GPIO2A4_SEL_SHIFT);
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		GPIO2A4_SEL_MASK | GPIO2A5_SEL_MASK,
		NORMAL << GPIO2A5_SEL_SHIFT |
		NORMAL << GPIO2A4_SEL_SHIFT);	
}
static void init_i2c3(void){
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO0A_IOMUX,
		GPIO0A5_SEL_MASK | GPIO0A6_SEL_MASK,
		GPIO0A5_I2C3_SCL << GPIO0A5_SEL_SHIFT |
		GPIO0A6_I2C3_SDA << GPIO0A6_SEL_SHIFT);
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO0A_P,
		GPIO0A5_SEL_MASK | GPIO0A6_SEL_MASK,
		NORMAL << GPIO0A5_SEL_SHIFT |
		NORMAL << GPIO0A6_SEL_SHIFT);	
}


static void pinctrl_rk3328_spi_config(void)
{
// 	unsigned int com_iomux = in32(RK3328_GRF_BASE + GRF_COM_IOMUX);

// 	if ((com_iomux & IOMUX_SEL_SPI_MASK) !=
// 		IOMUX_SEL_SPI_M0 << IOMUX_SEL_SPI_SHIFT) {
// 		kprintf("driver do not support iomux other than m0\n");
// 		goto err;
// 	}

// 	switch (spi_id) {
// 	case PERIPH_ID_SPI0:
// 		switch (cs) {
// 		case 0:
// 			rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2BL_IOMUX,
// 				     GPIO2BL3_SEL_MASK,
// 				     GPIO2BL3_SPI_CSN0_M0
// 				     << GPIO2BL3_SEL_SHIFT);
// 			break;
// 		case 1:
// 			rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2BL_IOMUX,
// 				     GPIO2BL4_SEL_MASK,
// 				     GPIO2BL4_SPI_CSN1_M0
// 				     << GPIO2BL4_SEL_SHIFT);
// 			break;
// 		default:
// 			goto err;
// 		}
// 		rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2BL_IOMUX,
// 			     GPIO2BL0_SEL_MASK,
// 			     GPIO2BL0_SPI_CLK_TX_RX_M0 << GPIO2BL0_SEL_SHIFT);
// 		break;
// 	default:
// 		goto err;
// 	}

// err:
// 	kprintf("rkspi: periph%d cs=%d not supported", spi_id, cs);
}
static void init_uart2 (void){
	unsigned int com_iomux = in32(RK3328_GRF_BASE + GRF_COM_IOMUX);

	if (com_iomux & IOMUX_SEL_UART2_MASK){
		rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
		    GPIO2A0_SEL_MASK | GPIO2A1_SEL_MASK,
		    GPIO2A0_UART2_TX_M1 << GPIO2A0_SEL_SHIFT |
		    GPIO2A1_UART2_RX_M1 << GPIO2A1_SEL_SHIFT);
		rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_P,
		    GPIO2A0_SEL_MASK | GPIO2A1_SEL_MASK,
		    PULL_UP << GPIO2A0_SEL_SHIFT |
		    NORMAL << GPIO2A1_SEL_SHIFT);
	}	
}


static void pinctrl_rk3328_sdmmc_config(int mmc_id)
{
	// unsigned int com_iomux = in32(RK3328_GRF_BASE + GRF_COM_IOMUX);

	// switch (mmc_id) {
	// case PERIPH_ID_EMMC:
	// 	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO0A_IOMUX,
	// 		     GPIO0A7_SEL_MASK,
	// 		     GPIO0A7_EMMC_DATA0 << GPIO0A7_SEL_SHIFT);
	// 	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2D_IOMUX,
	// 		     GPIO2D4_SEL_MASK,
	// 		     GPIO2D4_EMMC_DATA1234 << GPIO2D4_SEL_SHIFT);
	// 	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO3C_IOMUX,
	// 		     GPIO3C0_SEL_MASK,
	// 		     GPIO3C0_EMMC_DATA567_PWR_CLK_RSTN_CMD
	// 		     << GPIO3C0_SEL_SHIFT);
	// 	break;
	// case PERIPH_ID_SDCARD:
	// 	 SDMMC_PWREN use GPIO and init as regulator-fiexed  
	// 	if (com_iomux & IOMUX_SEL_SDMMC_MASK)
	// 		rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO0D_IOMUX,
	// 			     GPIO0D6_SEL_MASK,
	// 			     GPIO0D6_GPIO << GPIO0D6_SEL_SHIFT);
	// 	else
	// 		rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO2A_IOMUX,
	// 			     GPIO2A7_SEL_MASK,
	// 			     GPIO2A7_GPIO << GPIO2A7_SEL_SHIFT);
	// 	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO1A_IOMUX,
	// 		     GPIO1A0_SEL_MASK,
	// 		     GPIO1A0_CARD_DATA_CLK_CMD_DETN
	// 		     << GPIO1A0_SEL_SHIFT);
	// 	break;
	// default:
	// 	kprintf("mmc id = %d iomux error!\n", mmc_id);
	// 	break;
	// }
}

static void init_hdmi(void)
{
	// HDMI_CE
	rk_clrsetreg(RK3328_GRF_BASE + GRF_GPIO0A_IOMUX,
	     GPIO0A3_SEL_MASK | GPIO0A4_SEL_MASK,
	     GPIO0A3_HDMI_CE << GPIO0A3_SEL_SHIFT |
	     GPIO0A4_HDMI_HDP << GPIO0A4_SEL_SHIFT);
	rk_setreg(RK3328_GRF_BASE + GRF_GPIO0A_P, PULL_DOWN << GPIO0A4_SEL_SHIFT);


}

void init_board()
{
	init_clk();
	init_uart2();
	init_i2c0();
	init_i2c1();
	init_i2c3();
	init_pwm3();
}

