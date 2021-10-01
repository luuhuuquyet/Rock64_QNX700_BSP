/*
 * $QNXLicenseC:
 * Copyright 2019, QNX Software Systems.
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
#ifndef __ARM_ORANGE_PI_H_INCLUDED
#define __ARM_ORANGE_PI_H_INCLUDED


// 5 ports(PC,PD,PF,PG,PH)
#define H6_PIO0_BASE 		0x0300B000

// 2 ports (PL, PM)
#define H6_PIO1_BASE  		(0x07022000)

// Common registers
#define H6_Pn_CFG0(n)      	(n*0x0024+0x00) // Port n Configure Register 0 (n =2,3,5,6,7)
#define H6_Pn_CFG1(n)      	(n*0x0024+0x04) // Port n Configure Register 1 (n =2,3,5,6,7)
#define H6_Pn_CFG2(n)      	(n*0x0024+0x08) // Port n Configure Register 2 (n =2,3,5,6,7)
#define H6_Pn_CFG3(n)      	(n*0x0024+0x0C) // Port n Configure Register 3 (n =2,3,5,6,7)
#define H6_Pn_DAT(n)      	(n*0x0024+0x10) // Port n Data Register (n =2,3,5,6,7)
#define H6_Pn_DRV0(n)      	(n*0x0024+0x14) // Port n Multi-Driving Register 0 (n =2,3,5,6,7)
#define H6_Pn_DRV1(n)      	(n*0x0024+0x18) // Port n Multi-Driving Register 1 (n =2,3,5,6,7)
#define H6_Pn_PUL0(n)      	(n*0x0024+0x1C) // Port n Pull Register 0 (n =2,3,5,6,7)
#define H6_Pn_PUL1(n)      	(n*0x0024+0x20) // Port n Pull Register 1 (n =2,3,5,6,7)
#define H6_Pn_INT_CFG0(n)      (0x200+n*0x20+0x00)  // PIO Interrupt Configure Register 0(n =5,6,7)
#define H6_Pn_INT_CFG1(n)      (0x200+n*0x20+0x04)  // PIO Interrupt Configure Register 1(n =5,6,7)
#define H6_Pn_INT_CFG2(n)      (0x200+n*0x20+0x08)  // PIO Interrupt Configure Register 2(n =5,6,7)
#define H6_Pn_INT_CFG3(n)      (0x200+n*0x20+0x0C)  // PIO Interrupt Configure Register 3(n =5,6,7)
#define H6_Pn_INT_CTL(n)       (0x200+n*0x20+0x10)  // PIO Interrupt Control Register(n =5,6,7)
#define H6_Pn_INT_STA(n)       (0x200+n*0x20+0x14)  // PIO Interrupt Status Register(n =5,6,7)
#define H6_Pn_INT_DEB(n)       (0x200+n*0x20+0x18)  // PIO Interrupt Debounce Register(n =5,6,7)
#define H6_PIO_POW_MOD_SEL  (0x0340)              // PIO Group Withstand Voltage Mode Select Register
#define H6_PIO_POW_Val      (0x0348)              // PIO Group Power Value Register




// ATE(Audio Codec, TVE, EPHY) controller
#define H6_ATE_SYS_CONTROL      (0x002) //  ATE System Control Register
#define H6_ATE_SYS_IRQ_ENABLE   (0x004) //  ATE System IRQ Enable Register
#define H6_ATE_SYS_IRQ_STATUS   (0x006) //  ATE System IRQ Status Register
#define H6_ATE_SYS_CLK_CTL      (0x008) //  ATE System Clock Control Register
#define H6_ATE_SYS_DLDO_OSC_CTL (0x00A) //  ATE System DLDO and OSC Control Register
#define H6_ATE_SYS_PLL_CTL0     (0x00C) //  ATE System PLL Control 0 Register
#define H6_ATE_SYS_AUDIO_CTL0   (0x010) //  ATE System AUDIO Control 0 Register
#define H6_ATE_SYS_AUDIO_CTL1   (0x012) //  ATE System AUDIO Control 1 Register
#define H6_ATE_SYS_EPHY_CTL0    (0x014) //  ATE System EPHY Control 0 Register
#define H6_ATE_SYS_EPHY_CTL1    (0x016) //  ATE System EPHY Control 1 Register
#define H6_ATE_SYS_TVE_CTL0     (0x018) //  ATE System TVE Control 0 Register
#define H6_ATE_SYS_TVE_CTL1     (0x01A) //  ATE System TVE Control 1 Register



#define H6_RTC_BASE                      0x07000000
#define H6_LOSC_CTRL_REG            (0x0000) // Low Oscillator Control Register
#define H6_LOSC_AUTO_SWT_STA_REG    (0x0004) // LOSC Auto Switch Status Register
#define H6_INTOSC_CLK_PRESCAL_REG   (0x0008) // Internal OSC Clock Prescalar Register
#define H6_INTOSC_CLK_AUTO_CALI_REG (0x000C) // Internal OSC Clock Auto Calibration Register
#define H6_RTC_YY_MM_DD_REG 		(0x0010) // RTC Year-Month-Day Register
#define H6_RTC_HH_MM_SS_REG 		(0x0014) // RTC Hour-Minute-Second Register
#define H6_ALARM0_COUNTER_REG 		(0x0020) // Alarm 0 Counter Register
#define H6_ALARM0_CUR_VLU_REG 		(0x0024) // Alarm 0 Counter Current Value Register
#define H6_ALARM0_ENABLE_REG 		(0x0028) // Alarm 0 Enable Register
#define H6_ALARM0_IRQ_EN 			(0x002C) // Alarm 0 IRQ Enable Register
#define H6_ALARM0_IRQ_STA_REG 		(0x0030) // Alarm 0 IRQ Status Register
#define H6_ALARM1_WK_HH_MM_SS 		(0x0040) // Alarm 1 Week HMS Register
#define H6_ALARM1_ENABLE_REG 		(0x0044) // Alarm 1 Enable Register
#define H6_ALARM1_IRQ_EN 			(0x0048) // Alarm 1 IRQ Enable Register
#define H6_ALARM1_IRQ_STA_REG 		(0x004C) // Alarm 1 IRQ Status Register
#define H6_ALARM_CONFIG_REG 		(0x0050) // Alarm Configuration Register
#define H6_LOSC_OUT_GATING_REG 		(0x0060) // LOSC Output Gating Register
#define H6_GP_DATA_REG(N) 			(0x0100+ N*0x04) // General Purpose Register (N=0~7)
#define H6_XO_CTRL_REG 				(0x0160) // XO Control Register
#define H6_CALI_CTRL_REG 			(0x0164) // Calibration Control Register
#define H6_GPL_HOLD_OUTPUT_REG 		(0x0180) // GPL Hold Output Register
#define H6_GPM 						(0x0184) // GPM Hold Output Register
#define H6_RTC_PWR_MODE_SEL_REG 	(0x0188) // RTC POWER MODE SELECT Register
#define H6_RTC_VIO_REG 				(0x0190) // RTC-VIO Regulate Register
#define H6_BOOT_CPU_HP_FLAG_REG 	(0x01B8) // Boot CPU Hot Plug Flag Register
#define H6_CPU_SOFT_ENT_REG0 		(0x01BC) // CPU Software Entry Register 0
#define H6_IC_CHARA_REG 			(0x01F0) // IC Characteristic Register
#define H6_SUP_STAN_FLAG_REG 		(0x01F8) // Super Standby Flag Register
#define H6_CPU_SOFT_ENT_REG1 		(0x01FC) // CPU Software Entry Register 1
#define H6_CRY_CONFIG_REG 			(0x0210) // Crypto Configuration Register
#define H6_CRY_KEY_REG 				(0x0214) // Crypto Key Register
#define H6_CRY_EN_REG 				(0x0218) // Crypto Enable Register


// Thermal Sensor
#define H6_THS_BASE  					0x05070400
#define H6_THS_CTRL 				(0x0000) // THS Control Register
#define H6_THS_EN 					(0x0004) // THS Enable Register
#define H6_THS_PER 					(0x0008) // THS Period Control Register
#define H6_THS_DATA_INTC 			(0x0010) // THS Data Interrupt Control Register
#define H6_THS_SHUT_INTC 			(0x0014) // THS Shut Interrupt Control Register
#define H6_THS_ALARM_INTC 			(0x0018) // THS Alarm Interrupt Control Register
#define H6_THS_DATA_INTS 			(0x0020) // THS Data Interrupt Status Register
#define H6_THS_SHUT_INTS 			(0x0024) // THS Shut Interrupt Status Register
#define H6_THS_ALARMO_INTS 			(0x0028) // THS Alarm off Interrupt Status Register
#define H6_THS_ALARM_INTS 			(0x002C) // THS Alarm Interrupt Status Register
#define H6_THS_FILTER 				(0x0030) // THS Median Filter Control Register
#define H6_THS0_ALARM_CTRL 			(0x0040) // THS0 Alarm threshold Control Register
#define H6_THS1_ALARM_CTRL 			(0x0044) // THS1 Alarm threshold Control Register
#define H6_THS01_SHUTDOWN_CTRL 		(0x0080) // THS0&1 Alarm threshold Control Register
#define H6_THS01_CDATA 				(0x00A0) // THS0&1 Calibration Data
#define H6_THS0_DATA 				(0x00C0) // THS0 Data Register
#define H6_THS1_DATA 				(0x00C4) // THS1 Data Reg




// Embedded Crypto Engine

#define H6_EMCE_BASE       0x01905000
#define H6_EMCE_KEY0  (0x0000) // EMCE Master Key’s 1st Word
#define H6_EMCE_KEY1  (0x0004) // EMCE Master key’s 2nd Word
#define H6_EMCE_KEY2  (0x0008) // EMCE Master Key’s 3rd Word
#define H6_EMCE_KEY3  (0x000C) // EMCE Master Key’s 4th Word
#define H6_EMCE_KEY4  (0x0010) // EMCE Master Key’s 5th Word
#define H6_EMCE_KEY5  (0x0014) // EMCE Master Key’s 6th Word
#define H6_EMCE_KEY6  (0x0018) // EMCE Master Key’s 7th Word
#define H6_EMCE_KEY7  (0x001C) // EMCE Master Key’s 8th Word
#define H6_EMCE_SALT0 (0x0040) // EMCE Master Salt’s 1st Word
#define H6_EMCE_SALT1 (0x0044) // EMCE Master Salt’s 2nd Word
#define H6_EMCE_SALT2 (0x0048) // EMCE Master Salt’s 3rd Word
#define H6_EMCE_SALT3 (0x004C) // EMCE Master Salt’s 4th Word
#define H6_EMCE_SALT4 (0x0050) // EMCE Master Salt’s 5th Word
#define H6_EMCE_SALT5 (0x0054) // EMCE Master Salt’s 6th Word
#define H6_EMCE_SALT6 (0x0058) // EMCE Master Salt’s 7th Word
#define H6_EMCE_SALT7 (0x005C) // EMCE Master Salt’s 8th Word
#define H6_EMCE_MODE  (0x0080) // AES Configuration for Key Length and Mode

// Crypto Engine
#define H6_CE_NS_BASE   		0x01904000 
#define H6_CE_S_BASE    		0x01904800
#define H6_CE_TDA  		(0x0000) // Task Descriptor Address
#define H6_CE_ICR  		(0x0008) // Interrupt Control Register
#define H6_CE_ISR  		(0x000C) // Interrupt Status Register
#define H6_CE_TLR  		(0x0010) // Task Load Register
#define H6_CE_TSR  		(0x0014) // Task Status Register
#define H6_CE_ESR  		(0x0018) // Error Status Register
#define H6_CE_SCSA 		(0x0024) // Symmetric Algorithm DMA Current Source Address
#define H6_CE_SCDA 		(0x0028) // Symmetric Algorithm DMA Current Destination Address
#define H6_CE_HCSA 		(0x0034) // HASH Algorithm DMA Current Source Address
#define H6_CE_HCDA 		(0x0038) // HASH Algorithm DMA Current Destination Address
#define H6_CE_ACSA 		(0x0044) // Asymmetric Algorithm DMA Current Source Address
#define H6_CE_ACDA 		(0x0048) // Asymmetric Algorithm DMA Current Destination Address
#define H6_CE_XCSA 		(0x0054) // XTS Algorithm DMA Current Source Address
#define H6_CE_XCDA 		(0x0058) // XTS Algorithm DMA Current Destination Address

// Spinlock
#define H6_SPINLOCK_BASE              	0x03004000
#define H6_SPINLOCK_SYSTATUS_REG 	(0x0000) // Spinlock System Status Register
#define H6_SPINLOCK_STATUS_REG   	(0x0010) // Spinlock Status Register
#define H6_SPINLOCK_LOCK_REGN(N)    (0x0100+N*0x04) //Spinlock Register N (N=0~31)


//Message Box
#define H6_MSGBOX_BASE 						0x03003000
#define H6_MSGBOX_CTRL_REG0 			(0x0000)  			// Message Queue Attribute Control Register 0
#define H6_MSGBOX_CTRL_REG1 			(0x0004) 			// Message Queue Attribute Control Register 1
#define H6_MSGBOXU_IRQ_EN_REG(n) 		(0x0040+n*0x20) 	// IRQ Enable for User n (n=0,1)
#define H6_MSGBOXU_IRQ_STATUS_REG(n) 	(0x0050+n*0x20) 	// IRQ Status for User n ( n=0,1)
#define H6_MSGBOXM_FIFO_STATUS_REG(N) 	(0x0100+N*0x4) 	// FIFO Status for Message Queue N(N = 0~7)
#define H6_MSGBOXM_MSG_STATUS_REG(N) 	(0x0140+N*0x4) 	// Message Status for Message Queue N(N=0~7)
#define H6_MSGBOXM_MSG_REG(N) 			(0x0180+N*0x4) 	// Message Register for Message Queue N(N=0~7)
#define H6_MSGBOX_DEBUG_REG 			(0x01C0)			 // MSGBOX Debug Register
// GIC


// DMA
#define H6_DMA_BASE 							0x03002000
#define H6_DMA_IRQ_EN_REG0 				(0x0000) // DMA IRQ Enable Register 0
#define H6_DMA_IRQ_EN_REG1 				(0x0004) // DMA IRQ Enable Register 1
#define H6_DMA_IRQ_PEND_REG0 			(0x0010) // DMA IRQ Pending Register 0
#define H6_DMA_IRQ_PEND_REG1 			(0x0014) // DMA IRQ Pending Register 1
#define H6_DMA_SEC_REG 					(0x0020) // DMA Security Register
#define H6_DMA_AUTO_GATE_REG 			(0x0028) // DMA Auto Gating Register
#define H6_DMA_STA_REG 					(0x0030) // DMA Status Register
#define H6_DMA_EN_REG(N) 					(0x0100+N*0x0040) // DMA Channel Enable Register (N=0~15)
#define H6_DMA_PAU_REG(N) 					(0x0100+N*0x0040+0x0004) // DMA Channel Pause Register(N=0~15)
#define H6_DMA_DESC_ADDR_REG(N) 			(0x0100+N*0x0040+0x0008) // DMA Channel Start Address Register(N=0~15)
#define H6_DMA_CFG_REG(N) 					(0x0100+N*0x0040+0x000C) // DMA Channel Configuration Register(N=0~15)
#define H6_DMA_CUR_SRC_REG(N) 				(0x0100+N*0x0040+0x0010) // DMA Channel Current Source Register(N=0~15)
#define H6_DMA_CUR_DEST_REG(N) 				(0x0100+N*0x0040+0x0014) // DMA Channel Current Destination Register(N=0~15)
#define H6_DMA_BCNT_LEFT_REG(N) 			(0x0100+N*0x0040+0x0018) // DMA Channel Byte Counter Left Register(N=0~15)
#define H6_DMA_PARA_REG(N) 					(0x0100+N*0x0040+0x001C) // DMA Channel Parameter Register(N=0~15)
#define H6_DMA_MODE_REG(N) 					(0x0100+N*0x0040+0x0028) // DMA Mode Register(N=0~15)
#define H6_DMA_FDESC_ADDR_REG(N) 			(0x0100+N*0x0040+0x002C) // DMA Former Descriptor Address Register(N=0~15)
#define H6_DMA_PKG_NUM_REG(N) 				(0x0100+N*0x0040+0x0030) // DMA Package Number Register(N=0~15)

// PWM
#define H6_PWM 						0x0300A000
#define H6_PWM_CTRL_REG 			0x0000  // PWM Control Register
#define H6_PWM_CH0_PERIOD 			0x0004  // PWM Channel 0 Period Register


// High Speed Timer
#define H6_HS_TMR_BASE 			0x03005000
#define H6_HS_TMR_IRQ_EN_REG 	(0x0000) // HS Timer IRQ Enable Register
#define H6_HS_TMR_IRQ_STAS_REG 	(0x0004) // HS Timer Status Register
#define H6_HS_TMR0_CTRL_REG 	(0x0020) // HS Timer 0 Control Register
#define H6_HS_TMR0_INTV_LO_REG 	(0x0024) // HS Timer 0 Interval Value Low Register
#define H6_HS_TMR0_INTV_HI_REG 	(0x0028) // HS Timer 0 Interval Value High Register
#define H6_HS_TMR0_CURNT_LO_REG (0x002C) // HS Timer 0 Current Value Low Register
#define H6_HS_TMR0_CURNT_HI_REG (0x0030) // HS Timer 0 Current Value High Register

// Timer
#define H6_TMR_BASE 			 0x03009000
#define H6_TMR_IRQ_EN_REG 		(0x0000) // Timer IRQ Enable Register
#define H6_TMR_IRQ_STA_REG 		(0x0004) // Timer Status Register
#define H6_TMR0_CTRL_REG 		(0x0010) // Timer 0 Control Register
#define H6_TMR0_INTV_VALUE_REG 	(0x0014) // Timer 0 Interval Value Register
#define H6_TMR0_CUR_VALUE_REG 	(0x0018) // Timer 0 Current Value Register
#define H6_TMR1_CTRL_REG 		(0x0020) // Timer 1 Control Register
#define H6_TMR1_INTV_VALUE_REG 	(0x0024) // Timer 1 Interval Value Register
#define H6_TMR1_CUR_VALUE_REG 	(0x0028) // Timer 1 Current Value Register
#define H6_CNT_TEST_REG 		(0x0094) // Counter Test Mode Register
#define H6_WDOG_IRQ_EN_REG 		(0x00A0) // Watchdog IRQ Enable Register
#define H6_WDOG_IRQ_STA_REG 	(0x00A4) // Watchdog Status Register
#define H6_WDOG_CTRL_REG 		(0x00B0) // Watchdog Control Register
#define H6_WDOG_CFG_REG 		(0x00B4) // Watchdog Configuration Register
#define H6_WDOG_MODE_REG 		(0x00B8) // Watchdog Mode Register
#define H6_AVS_CNT_CTL_REG		(0x00C0) // AVS Control Register
#define H6_AVS_CNT0_REG 		(0x00C4) // AVS Counter 0 Register
#define H6_AVS_CNT1_REG 		(0x00C8) // AVS Counter 1 Register
#define H6_AVS_CNT_DIV_REG 		(0x00CC) // AVS Divisor Register
#define H6_CNT64_CTRL_REG 		(0x0100) // 64-bit Counter Control Register
#define H6_CNT64_LOW_REG 		(0x0104) // 64-bit Counter Low Register
#define H6_CNT64_HIGH_REG 		(0x0108) // 64-bit Counter High Register



// System Configuration
#define H6_SYS_CFG_BASE 		0x03000000
#define H6_VER_REG 				0x0024  // Version Register
#define H6_EMAC_EPHY_CLK_REG0 	0x0030 // EMAC-EPHY Clock Register 0
#define H6_BROM_OUTPUT_REG 		0x00A4   //BROM Output Register



// IOMMU
#define H6_IOMMU_BASE						0x030F0000
#define H6_IOMMU_RESET_REG 					(0x0010)  // IOMMU Reset Register
#define H6_IOMMU_ENABLE_REG 				(0x0020)  // IOMMU Enable Register
#define H6_IOMMU_BYPASS_REG 				(0x0030)  // IOMMU Bypass Register
#define H6_IOMMU_AUTO_GATING_REG 			(0x0040)  // IOMMU Auto Gating Register
#define H6_IOMMU_WBUF_CTRL_REG 				(0x0044)  // IOMMU Write Buffer Control Register
#define H6_IOMMU_OOO_CTRL_REG 				(0x0048)  // IOMMU Out Of Order Control Register
#define H6_IOMMU_4KB_BDY_PRT_CTRL_REG 		(0x004C)  // IOMMU 4KB Boundary Protect Control Register
#define H6_IOMMU_TTB_REG 					(0x0050)  // IOMMU Translation Table Base Register
#define H6_IOMMU_TLB_ENABLE_REG 			(0x0060)  // IOMMU TLB Enable Register
#define H6_IOMMU_TLB_PREFETCH_REG 			(0x0070)  // IOMMU TLB Prefetch Register
#define H6_IOMMU_TLB_FLUSH_ENABLE_REG 		(0x0080)  // IOMMU TLB Flush Enable Register
#define H6_IOMMU_TLB_IVLD_ADDR_REG 			(0x0090)  // IOMMU TLB Invalidation Address Register
#define H6_IOMMU_TLB_IVLD_ADDR_MASK_REG 	(0x0094)  // IOMMU TLB Invalidation Address Mask Register
#define H6_IOMMU_TLB_IVLD_ENABLE_REG 		(0x0098)  // IOMMU TLB Invalidation Enable Register
#define H6_IOMMU_PC_IVLD_ADDR_REG 			(0x00A0)  // IOMMU PC Invalidation Address Register
#define H6_IOMMU_PC_IVLD_ENABLE_REG 		(0x00A8)  // IOMMU PC Invalidation Enable Register
#define H6_IOMMU_DM_AUT_CTRL_REG0 			(0x00B0)  // IOMMU Domain Authority Control Register 0
#define H6_IOMMU_DM_AUT_CTRL_REG1 			(0x00B4)  // IOMMU Domain Authority Control Register 1
#define H6_IOMMU_DM_AUT_CTRL_REG2 			(0x00B8)  // IOMMU Domain Authority Control Register 2
#define H6_IOMMU_DM_AUT_CTRL_REG3 			(0x00BC)  // IOMMU Domain Authority Control Register 3
#define H6_IOMMU_DM_AUT_CTRL_REG4 			(0x00C0)  // IOMMU Domain Authority Control Register 4
#define H6_IOMMU_DM_AUT_CTRL_REG5 			(0x00C4)  // IOMMU Domain Authority Control Register 5
#define H6_IOMMU_DM_AUT_CTRL_REG6 			(0x00C8)  // IOMMU Domain Authority Control Register 6
#define H6_IOMMU_DM_AUT_CTRL_REG7 			(0x00CC)  // IOMMU Domain Authority Control Register 7
#define H6_IOMMU_DM_AUT_OVWT_REG 			(0x00D0)  // IOMMU Domain Authority Overwrite Register
#define H6_IOMMU_INT_ENABLE_REG 			(0x0100)  // IOMMU Interrupt Enable Register
#define H6_IOMMU_INT_CLR_REG 				(0x0104)  // IOMMU Interrupt Clear Register
#define H6_IOMMU_INT_STA_REG 				(0x0108)  // IOMMU Interrupt Status Register
#define H6_IOMMU_INT_ERR_ADDR_REG0 			(0x0110)  // IOMMU Interrupt Error Address Register 0
#define H6_IOMMU_INT_ERR_ADDR_REG1 			(0x0114)  // IOMMU Interrupt Error Address Register 1
#define H6_IOMMU_INT_ERR_ADDR_REG2 			(0x0118)  // IOMMU Interrupt Error Address Register 2
#define H6_IOMMU_INT_ERR_ADDR_REG3 			(0x011C)  // IOMMU Interrupt Error Address Register 3
#define H6_IOMMU_INT_ERR_ADDR_REG4 			(0x0120)  // IOMMU Interrupt Error Address Register 4
#define H6_IOMMU_INT_ERR_ADDR_REG5 			(0x0124)  // IOMMU Interrupt Error Address Register 5
#define H6_IOMMU_INT_ERR_ADDR_REG6 			(0x0130)  // IOMMU Interrupt Error Address Register 6
#define H6_IOMMU_INT_ERR_ADDR_REG7 			(0x0134)  // IOMMU Interrupt Error Address Register 7
#define H6_IOMMU_INT_ERR_DATA_REG0 			(0x0150)  // IOMMU Interrupt Error Data Register 0
#define H6_IOMMU_INT_ERR_DATA_REG1 			(0x0154)  // IOMMU Interrupt Error Data Register 1
#define H6_IOMMU_INT_ERR_DATA_REG2 			(0x0158)  // IOMMU Interrupt Error Data Register 2
#define H6_IOMMU_INT_ERR_DATA_REG3 			(0x015C)  // IOMMU Interrupt Error Data Register 3
#define H6_IOMMU_INT_ERR_DATA_REG4 			(0x0160)  // IOMMU Interrupt Error Data Register 4
#define H6_IOMMU_INT_ERR_DATA_REG5 			(0x0164)  // IOMMU Interrupt Error Data Register 5
#define H6_IOMMU_INT_ERR_DATA_REG6 			(0x0170)  // IOMMU Interrupt Error Data Register 6
#define H6_IOMMU_INT_ERR_DATA_REG7 			(0x0174)  // IOMMU Interrupt Error Data Register 7
#define H6_IOMMU_L1PG_INT_REG 				(0x0180)  // IOMMU L1 Page Table Interrupt Register
#define H6_IOMMU_L2PG_INT_REG 				(0x0184)  // IOMMU L2 Page Table Interrupt Register
#define H6_IOMMU_VA_REG 					(0x0190)  // IOMMU Virtual Address Register
#define H6_IOMMU_VA_DATA_REG 				(0x0194)  // IOMMU Virtual Address Data Register
#define H6_IOMMU_VA_CONFIG_REG 				(0x0198)  // IOMMU Virtual Address Configuration Register
#define H6_IOMMU_PMU_ENABLE_REG 			(0x0200)  // IOMMU PMU Enable Register
#define H6_IOMMU_PMU_CLR_REG 				(0x0210)  // IOMMU PMU Clear Register
#define H6_IOMMU_PMU_ACCESS_LOW_REG0 		(0x0230)  // IOMMU PMU Access Low Register 0
#define H6_IOMMU_PMU_ACCESS_HIGH_REG0 		(0x0234)  // IOMMU PMU Access High Register 0
#define H6_IOMMU_PMU_HIT_LOW_REG0 			(0x0238)  // IOMMU PMU Hit Low Register 0
#define H6_IOMMU_PMU_HIT_HIGH_REG0 			(0x023C)  // IOMMU PMU Hit High Register 0
#define H6_IOMMU_PMU_ACCESS_LOW_REG1 		(0x0240)  // IOMMU PMU Access Low Register 1
#define H6_IOMMU_PMU_ACCESS_HIGH_REG1 		(0x0244)  // IOMMU PMU Access High Register 1
#define H6_IOMMU_PMU_HIT_LOW_REG1 			(0x0248)  // IOMMU PMU Hit Low Register 1
#define H6_IOMMU_PMU_HIT_HIGH_REG1 			(0x024C)  // IOMMU PMU Hit High Register 1
#define H6_IOMMU_PMU_ACCESS_LOW_REG2 		(0x0250)  // IOMMU PMU Access Low Register 2
#define H6_IOMMU_PMU_ACCESS_HIGH_REG2 		(0x0254)  // IOMMU PMU Access High Register 2
#define H6_IOMMU_PMU_HIT_LOW_REG2 			(0x0258)  // IOMMU PMU Hit Low Register 2
#define H6_IOMMU_PMU_HIT_HIGH_REG2 			(0x025C)  // IOMMU PMU Hit High Register 2
#define H6_IOMMU_PMU_ACCESS_LOW_REG3		(0x0260)  // IOMMU PMU Access Low Register 3
#define H6_IOMMU_PMU_ACCESS_HIGH_REG3 		(0x0264)  // IOMMU PMU Access High Register 3
#define H6_IOMMU_PMU_HIT_LOW_REG3 			(0x0268)  // IOMMU PMU Hit Low Register 3
#define H6_IOMMU_PMU_HIT_HIGH_REG3 			(0x026C)  // IOMMU PMU Hit High Register 3
#define H6_IOMMU_PMU_ACCESS_LOW_REG4 		(0x0270)  // IOMMU PMU Access Low Register 4
#define H6_IOMMU_PMU_ACCESS_HIGH_REG4 		(0x0274)  // IOMMU PMU Access High Register 4
#define H6_IOMMU_PMU_HIT_LOW_REG4 			(0x0278)  // IOMMU PMU Hit Low Register 4
#define H6_IOMMU_PMU_HIT_HIGH_REG4 			(0x027C)  // IOMMU PMU Hit High Register 4
#define H6_IOMMU_PMU_ACCESS_LOW_REG5 		(0x0280)  // IOMMU PMU Access Low Register 5
#define H6_IOMMU_PMU_ACCESS_HIGH_REG5 		(0x0284)  // IOMMU PMU Access High Register 5
#define H6_IOMMU_PMU_HIT_LOW_REG5 			(0x0288)  // IOMMU PMU Hit Low Register 5
#define H6_IOMMU_PMU_HIT_HIGH_REG5 			(0x028C)  // IOMMU PMU Hit High Register 5
#define H6_IOMMU_PMU_ACCESS_LOW_REG6 		(0x02D0)  // IOMMU PMU Access Low Register 6
#define H6_IOMMU_PMU_ACCESS_HIGH_REG6 		(0x02D4)  // IOMMU PMU Access High Register 6
#define H6_IOMMU_PMU_HIT_LOW_REG6 			(0x02D8)  // IOMMU PMU Hit Low Register 6
#define H6_IOMMU_PMU_HIT_HIGH_REG6 			(0x02DC)  // IOMMU PMU Hit High Register 6
#define H6_IOMMU_PMU_ACCESS_LOW_REG7 		(0x02E0)  // IOMMU PMU Access Low Register 7
#define H6_IOMMU_PMU_ACCESS_HIGH_REG7 		(0x02E4)  // IOMMU PMU Access High Register 7
#define H6_IOMMU_PMU_HIT_LOW_REG7 			(0x02E8)  // IOMMU PMU Hit Low Register 7
#define H6_IOMMU_PMU_HIT_HIGH_REG7 			(0x02EC)  // IOMMU PMU Hit High Register 7
#define H6_IOMMU_PMU_TL_LOW_REG0 			(0x0300)  // IOMMU Total Latency Low Register 0
#define H6_IOMMU_PMU_TL_HIGH_REG0 			(0x0304)  // IOMMU Total Latency High Register 0
#define H6_IOMMU_PMU_TL_LOW_REG1 			(0x0310)  // IOMMU Total Latency Low Register 1
#define H6_IOMMU_PMU_TL_HIGH_REG1 			(0x0314)  // IOMMU Total Latency High Register 1
#define H6_IOMMU_PMU_TL_LOW_REG2 			(0x0320)  // IOMMU Total Latency Low Register 2
#define H6_IOMMU_PMU_TL_HIGH_REG2 			(0x0324)  // IOMMU Total Latency High Register 2
#define H6_IOMMU_PMU_TL_LOW_REG3 			(0x0330)  // IOMMU Total Latency Low Register 3
#define H6_IOMMU_PMU_TL_HIGH_REG3 			(0x0334)  // IOMMU Total Latency High Register 3
#define H6_IOMMU_PMU_TL_LOW_REG4 			(0x0340)  // IOMMU Total Latency Low Register 4
#define H6_IOMMU_PMU_TL_HIGH_REG4 			(0x0344)  // IOMMU Total Latency High Register 4
#define H6_IOMMU_PMU_TL_LOW_REG5 			(0x0350)  // IOMMU Total Latency Low Register 5
#define H6_IOMMU_PMU_TL_HIGH_REG5 			(0x0354)  // IOMMU Total Latency High Register 5

// Cluster Configuration Registers
#define H6_CPU_CFG_BASE					0x09010000
#define H6_C0_RST_CTRL 					(0x0000) // Cluster 0 Reset Control Register
#define H6_C0_CTRL_REG0 				(0x0010) // Cluster 0 Control Register0
#define H6_C0_CTRL_REG1 				(0x0014) // Cluster 0 Control Register1
#define H6_C0_CTRL_REG2 				(0x0018) // Cluster 0 Control Register2
#define H6_CACHE_CFG_REG 				(0x0024) // Cache Configuration Register
#define H6_RVBARADDR0_L 				(0x0040) // Reset Vector Base Address Register0_L
#define H6_RVBARADDR0_H 				(0x0044) // Reset Vector Base Address Register0_H
#define H6_RVBARADDR1_L 				(0x0048) // Reset Vector Base Address Register1_L
#define H6_RVBARADDR1_H 				(0x004C) // Reset Vector Base Address Register1_H
#define H6_RVBARADDR2_L 				(0x0050) // Reset Vector Base Address Register2_L
#define H6_RVBARADDR2_H 				(0x0054) // Reset Vector Base Address Register2_H
#define H6_RVBARADDR3_L 				(0x0058) // Reset Vector Base Address Register3_L
#define H6_RVBARADDR3_H 				(0x005C) // Reset Vector Base Address Register3_H
#define H6_C0_CPU_STATUS 				(0x0080) // Cluster 0 CPU Status Register
#define H6_L2_STATUS_REG 				(0x0084) // Cluster 0 L2 Status Register
#define H6_DBG_REG0 					(0x00C0) // Cluster 0 Debug Control Register0
#define H6_DBG_REG1 					(0x00C4) // Cluster 0 Debug Control Register1

// CPU Subsystem Control Registers
#define H6_CPU_SUBSYS_CTRL_BASE	0x08100000
#define H6_GENER_CTRL_REG0 		(0x0000) // General Control Register0
#define H6_GENER_CTRL_REG1 		(0x0004) // General Control Register1
#define H6_GIC_JTAG_RST_CTRL 	(0x000C) // GIC and Jtag Reset Control Register
#define H6_C0_INT_EN 			(0x0010) // Cluster0 Interrupt Enable Control Register
#define H6_IRQ_FIQ_STATUS 		(0x0014) // GIC IRQ/FIQ Status Register
#define H6_GENER_CTRL_REG2 		(0x0018) // General Control Register2

// The CCU controls the PLLs configuration and most of the clock generation, division, distribution, synchronization and
// gating. CCU input signals include the external clock for the reference frequency (24MHz). The outputs from CCU are
// mostly clocks to other blocks in the system.

#define H6_CCU_BASE 							(0x03001000)
#define H6_PLL_CPUX_CTRL_REG 					(0x0000)    //   PLL_CPUX Control Register
#define H6_PLL_DDR0_CTRL_REG    				(0x0010)    //   PLL_DDR0 Control Register
#define H6_PLL_PERI0_CTRL_REG   				(0x0020)    //   PLL_PERI0 Control Register
#define H6_PLL_PERI1_CTRL_REG   				(0x0028)    //   PLL_PERI1 Control Register
#define H6_PLL_GPU_CTRL_REG     				(0x0030)    //   PLL_GPU Control Register
#define H6_PLL_VIDEO0_CTRL_REG  				(0x0040)    //   PLL_VIDEO0 Control Register
#define H6_PLL_VIDEO1_CTRL_REG  				(0x0048)    //   PLL_VIDEO1 Control Register
#define H6_PLL_VE_CTRL_REG 						(0x0058)    //   PLL_VE Control Register
#define H6_PLL_DE_CTRL_REG 						(0x0060)    //   PLL_DE Control Register
#define H6_PLL_HSIC_CTRL_REG 					(0x0070)    //   PLL_HSIC Control Register
#define H6_PLL_AUDIO_CTRL_REG 					(0x0078)    //   PLL_AUDIO Control Register
#define H6_PLL_DDR0_PAT_REG 					(0x0110)    //   PLL_DDR0 Pattern Register
#define H6_PLL_PERI1_PAT0_REG 					(0x0128)    //   PLL_PERI1 Pattern0 Register
#define H6_PLL_PERI1_PAT1_REG 					(0x012C)    //   PLL_PERI1 Pattern1 Register
#define H6_PLL_GPU_PAT0_REG 					(0x0130)    //   PLL_GPU Pattern0 Register
#define H6_PLL_GPU_PAT1_REG 					(0x0134)    //   PLL_GPU Pattern1 Register
#define H6_PLL_VIDEO0_PAT0_REG 					(0x0140)    //   PLL_VIDEO0 Pattern0 Register
#define H6_PLL_VIDEO0_PAT1_REG 					(0x0144)    //   PLL_VIDEO0 Pattern1 Register
#define H6_PLL_VIDEO1_PAT0_REG 					(0x0148)    //   PLL_VIDEO1 Pattern0 Register
#define H6_PLL_VIDEO1_PAT1_REG 					(0x014C)    //   PLL_VIDEO1 Pattern1 Register
#define H6_PLL_VE_PAT0_REG 						(0x0158)    //   PLL_VE Pattern0 Register
#define H6_PLL_VE_PAT1_REG 						(0x015C)    //   PLL_VE Pattern1 Register
#define H6_PLL_DE_PAT0_REG 						(0x0160)    //   PLL_DE Pattern0 Register
#define H6_PLL_DE_PAT1_REG 						(0x0164)    //   PLL_DE Pattern1 Register
#define H6_PLL_HSIC_PAT0_REG 					(0x0170)    //   PLL_HSIC Pattern0 Register
#define H6_PLL_HSIC_PAT1_REG 					(0x0174)    //   PLL_HSIC Pattern1 Register
#define H6_PLL_AUDIO_PAT0_REG 					(0x0178)    //   PLL_AUDIO Pattern0 Register
#define H6_PLL_AUDIO_PAT1_REG 					(0x017C)    //   PLL_AUDIO Pattern1 Register
#define H6_PLL_CPUX_BIAS_REG 					(0x0300)    //   PLL_CPUX Bias Register
#define H6_PLL_DDR0_BIAS_REG 					(0x0310)    //   PLL_DDR0 Bias Register
#define H6_PLL_PERI0_BIAS_REG 					(0x0320)    //   PLL_PERI0 Bias Register
#define H6_PLL_PERI1_BIAS_REG 					(0x0328)    //   PLL_PERI1 Bias Register
#define H6_PLL_GPU_BIAS_REG 					(0x0330)    //   PLL_GPU Bias Register
#define H6_PLL_VIDEO0_BIAS_REG 					(0x0340)    //   PLL_VIDEO0 Bias Register
#define H6_PLL_VIDEO1_BIAS_REG 					(0x0348)    //   PLL_VIDEO1 Bias Register
#define H6_PLL_VE_BIAS_REG 						(0x0358)    //   PLL_VE Bias Register
#define H6_PLL_DE_BIAS_REG 						(0x0360)    //   PLL_DE Bias Register
#define H6_PLL_ISP_BIAS_REG 					(0x0368)    //   PLL_ISP Bias Register
#define H6_PLL_HSIC_BIAS_REG 					(0x0370)    //   PLL_HSIC Bias Register
#define H6_PLL_AUDIO_BIAS_REG 					(0x0378)    //   PLL_AUDIO Bias Register
#define H6_PLL_CPUX_TUN_REG 					(0x0400)    //   PLL_CPUX Tunning Register
#define H6_CPUX_AXI_CFG_REG 					(0x0500)    //   CPUX_AXI Configuration Register
#define H6_PSI_AHB1_AHB2_CFG_REG				(0x0510)    //   PSI_AHB1_AHB2 Configuration Register
#define H6_AHB3_CFG_REG 						(0x051C)    //   AHB3 Configuration Register
#define H6_APB1_CFG_REG 						(0x0520)    //   APB1 Configuration Register
#define H6_APB2_CFG_REG 						(0x0524)    //   APB2 Configuration Register
#define H6_CCI400_CFG_REG 						(0x0530)    //   CCI400 Configuration Register
#define H6_MBUS_CFG_REG 						(0x0540)    //   MBUS Configuration Register
#define H6_DE_CLK_REG 							(0x0600)    //   DE Clock Register
#define H6_DE_BGR_REG 							(0x060C)    //   DE Bus Gating Reset Register
#define H6_DI_CLK_REG 							(0x0620)    //   DI Clock Register
#define H6_DI_BGR_REG 							(0x062C)    //   DI Bus Gating Reset Register
#define H6_GPU_CLK_REG 							(0x0670)    //   GPU Clock Register
#define H6_GPU_BGR_REG 							(0x067C)    //   GPU Bus Gating Reset Register
#define H6_CE_CLK_REG 							(0x0680)    //   CE Clock Register
#define H6_CE_BGR_REG 							(0x068C)    //   CE Bus Gating Reset Register
#define H6_VE_CLK_REG 							(0x0690)    //   VE Clock Register
#define H6_VE_BGR_REG 							(0x069C)    //   VE Bus Gating Reset Register
#define H6_EMCE_CLK_REG 						(0x06B0)    //   EMCE Clock Register
#define H6_EMCE_BGR_REG 						(0x06BC)    //   EMCE Bus Gating Reset Register
#define H6_VP9_CLK_REG 							(0x06C0)    //   VP9 Clock Register
#define H6_VP9_BGR_REG 							(0x06CC)    //   VP9 Bus Gating Reset Register
#define H6_DMA_BGR_REG 							(0x070C)    //   DMA Bus Gating Reset Register
#define H6_MSGBOX_BGR_REG 						(0x071C)    //   MessageBox Bus Gating Reset Register
#define H6_SPINLOCK_BGR_REG 					(0x072C)    //   Spinlock Bus Gating Reset Register
#define H6_HSTIMER_BGR_REG 						(0x073C)    //   HSTimer Bus Gating Reset Register
#define H6_AVS_CLK_REG 							(0x0740)    //   AVS Clock Register
#define H6_DBGSYS_BGR_REG 						(0x078C)    //   DBGSYS Bus Gating Reset Register
#define H6_PSI_BGR_REG 							(0x079C)    //   PSI Bus Gating Reset Register
#define H6_PWM_BGR_REG 							(0x07AC)    //   PWM Bus Gating Reset Register
#define H6_IOMMU_BGR_REG 						(0x07BC)    //   IOMMU Bus Gating Reset Register
#define H6_DRAM_CLK_REG 						(0x0800)    //   DRAM Clock Register
#define H6_MBUS_MST_CLK_GATING_REG 				(0x0804)    // MBUS Master Clock Gating Register
#define H6_DRAM_BGR_REG 						(0x080C)    // DRAM Bus Gating Reset Register
#define H6_NAND_0_CLK_REG 						(0x0810)    // NAND0 Clock Register
#define H6_NAND_1_CLK_REG 						(0x0814)    // NAND1 Clock Register
#define H6_NAND_BGR_REG 						(0x082C)    // NAND Bus Gating Reset Register
#define H6_SMHC0_CLK_REG 						(0x0830)    // SMHC0 Clock Register
#define H6_SMHC1_CLK_REG 						(0x0834)    // SMHC1 Clock Register
#define H6_SMHC2_CLK_REG 						(0x0838)    // SMHC2 Clock Register
#define H6_SMHC_BGR_REG 						(0x084C)    // SMHC Bus Gating Reset Register
#define H6_UART_BGR_REG 						(0x090C)    // UART Bus Gating Reset Register
#define H6_TWI_BGR_REG 							(0x091C)    // TWI Bus Gating Reset Register
#define H6_SCR_BGR_REG 							(0x093C)    // SCR Bus Gating Reset Register
#define H6_SPI0_CLK_REG 						(0x0940)    // SPI0 Clock Register
#define H6_SPI1_CLK_REG 						(0x0944)    // SPI1 Clock Register
#define H6_SPI_BGR_REG 							(0x096C)    // SPI Bus Gating Reset Register
#define H6_EMAC_BGR_REG 						(0x097C)    // EMAC Bus Gating Reset Register
#define H6_TS_CLK_REG 							(0x09B0)    // TS Clock Register
#define H6_TS_BGR_REG 							(0x09BC)    // TS Bus Gating Reset Register
#define H6_IRTX_CLK_REG 						(0x09C0)    // CIR-TX Clock Register
#define H6_IRTX_BGR_REG 						(0x09CC)    // CIR-TX Bus Gating Reset Register
#define H6_THS_BGR_REG 							(0x09FC)    // THS Bus Gating Reset Register
#define H6_I2S_PCM3_CLK_REG 					(0x0A0C)    // I2S/PCM3 Clock Register
#define H6_I2S_PCM0_CLK_REG 					(0x0A10)    // I2S/PCM0 Clock Register
#define H6_I2S_PCM1_CLK_REG 					(0x0A14)    // I2S/PCM1 Clock Register
#define H6_I2S_PCM2_CLK_REG 					(0x0A18)    // I2S/PCM2 Clock Register
#define H6_I2S_PCM_BGR_REG 						(0x0A1C)    // I2S/PCM Bus Gating Reset Register
#define H6_OWA_CLK_REG 							(0x0A20)    // OWA Clock Register
#define H6_OWA_BGR_REG 							(0x0A2C)    // OWA Bus Gating Reset Register
#define H6_DMIC_CLK_REG 						(0x0A40)    // DMIC Clock Register
#define H6_DMIC_BGR_REG 						(0x0A4C)    // DMIC Bus Gating Reset Register
#define H6_AUDIO_HUB_CLK_REG 					(0x0A60)    // AUDIO_HUB Clock Register
#define H6_AUDIO_HUB_BGR_REG 					(0x0A6C)    // AUDIO_HUB Bus Gating Reset Register
#define H6_USB0_CLK_REG 						(0x0A70)    // USB0 Clock Register
#define H6_USB1_CLK_REG 						(0x0A74)    // USB1 Clock Register
#define H6_USB3_CLK_REG 						(0x0A7C)    // USB3 Clock Register
#define H6_USB_CGR_REG 							(0x0A8C)    // USB Clock Gating Reset Register
#define H6_PCIE_REF_CLK_REG 					(0x0AB0)    // PCIE REF Clock Register
#define H6_PCIE_AXI_CLK_REG 					(0x0AB4)    // PCIE AXI Clock Register
#define H6_PCIE_AUX_CLK_REG 					(0x0AB8)    // PCIE AUX Clock Register
#define H6_PCIE_CGR_REG 						(0x0ABC)    // PCIE Clock Gating Reset Register
#define H6_cHDMI_CLK_REG 						(0x0B00)    // HDMI Clock Register
#define H6_HDMI_SLOW_CLK_REG 					(0x0B04)    // HDMI Slow Clock Register
#define H6_HDMI_CEC_CLK_REG 					(0x0B10)    // HDMI CEC Clock Register
#define H6_HDMI_BGR_REG 						(0x0B1C)    // HDMI Bus Gating Reset Register
#define H6_DISPLAY_IF_TOP_BGR_REG 				(0x0B5C)    // DISPLAY_IF_TOP Bus Gating Reset Register
#define H6_TCON_LCD_CLK_REG 					(0x0B60)    // TCON_LCD Clock Register
#define H6_TCON_LCD_BGR_REG 					(0x0B7C)    // TCON_LCD Bus Gating Reset Register
#define H6_TCON_TV_CLK_REG 						(0x0B80)    // TCON_TV Clock Register
#define H6_TCON_TV_BGR_REG 						(0x0B9C)    // TCON_TV Bus Gating Reset Register
#define H6_CSI_MISC_CLK_REG 					(0x0C00)    // CSI MISC Clock Register
#define H6_CSI_TOP_CLK_REG 						(0x0C04)    // CSI TOP Clock Register
#define H6_CSI_MST_CLK0_REG 					(0x0C08)    // CSI Master Clock0 Register
#define H6_CSI_BGR_REG 							(0x0C2C)    // CSI Bus Gating Reset Register
#define H6_HDMI_HDCP_CLK_REG 					(0x0C40)    // HDMI HDCP Clock Register
#define H6_HDMI_HDCP_CLK_REG 					(0x0C4C)    // HDMI HDCP Clock Register
#define H6_CCU_SEC_SWITCH_REG 					(0x0F00)    // CCU Security Switch Register
#define H6_PLL_LOCK_DBG_CTRL_REG 				(0x0F04)    // PLL Lock Debug Control Register

// NDFC0
#define H6_NDFC0_BASE  					(0x04011000)
#define H6_NDFC_CTL 					(0x0000) // NDFC Configure and Control Register
#define H6_NDFC_ST 						(0x0004) // NDFC Status Information Register
#define H6_NDFC_INT 					(0x0008) // NDFC Interrupt Control Register
#define H6_NDFC_TIMING_CTL 				(0x000C) // NDFC Timing Control Register
#define H6_NDFC_TIMING_CFG 				(0x0010) // NDFC Timing Configure Register
#define H6_NDFC_ADDR_LOW 				(0x0014) // NDFC Low Word Address Register
#define H6_NDFC_ADDR_HIGH 				(0x0018) // NDFC High Word Address Register
#define H6_NDFC_DATA_BLOCK_MASK 		(0x001C) // NDFC Data Block Mask Register
#define H6_NDFC_CNT 					(0x0020) // NDFC Data Counter for data transfer Register
#define H6_NDFC_CMD 					(0x0024) // Set up NDFC commands Register
#define H6_NDFC_RCMD_SET 				(0x0028) // Read Command Set Register for vendor’s NAND memory
#define H6_NDFC_WCMD_SET 				(0x002C) // Write Command Set Register for vendor’s NAND memory
#define H6_NDFC_ECC_CTL 				(0x0034) // ECC Configure and Control Register
#define H6_NDFC_ECC_ST 					(0x0038) // ECC Status and Operation information Register
#define H6_NDFC_DATA_PAT_STA 			(0x003C) // NDFC Data Pattern Status Register
#define H6_NDFC_EFR 					(0x0040) // NDFC Enhanced Feature Register
#define H6_NDFC_RDATA_STA_CTL 			(0x0044) // Read Data Status Control Register
#define H6_NDFC_RDATA_STA_0 			(0x0048) // Read Data Status Register 0
#define H6_NDFC_RDATA_STA_1 			(0x004C) // Read Data Status Register 1
#define H6_NDFC_ERR_CNT_N(N)			(0x0050+0x04*N) // NDFC Error Counter Register(N from 0 to 7)
#define H6_NDFC_USER_DATA_LEN_N(N) 		(0x0070+0x04*N) // NDFC User Data Length Register(N from 0 to 3)
#define H6_NDFC_USER_DATA_N(N) 			(0x0080+0x04*N) // User Data Field Register N (N from 0 to 31)
#define H6_NDFC_EFNAND_STA 				(0x0110) // EFNAND Status Register
#define H6_NDFC_SPARE_AREA 				(0x0114) // Spare Area Configure Register
#define H6_NDFC_PAT_ID 					(0x0118) // Pattern ID Register
#define H6_NDFC_DDR2_SPEC_CTL 			(0x011C) // NDFC DDR2 Configuration Control Register
#define H6_NDFC_NDMA_MODE_CTL 			(0x0120) // NDFC Normal DMA Mode Control Register
#define H6_NDFC_MDMA_DLBA_REG 			(0x0200) // NDFC MBUS DMA Descriptor List Base Address Register
#define H6_NDFC_MDMA_STA 				(0x0204) // NDFC MBUS DMA Interrupt Status Register
#define H6_NDFC_DMA_INT_MASK 			(0x0208) // NDFC MBUS DMA Interrupt Enable Register
#define H6_NDFC_MDMA_CUR_DESC_ADDR 		(0x020C) // NDFC MBUS DMA Current Descriptor Address Register
#define H6_NDFC_MDMA_CUR_BUF_ADDR 		(0x0210) // NDFC MBUS DMA Current Buffer Address Register
#define H6_NDFC_DMA_CNT 				(0x0214) // NDFC DMA Byte Counter Register
#define H6_NDFC_EMCE_CTL 				(0x0218) // NDFC EMCE Control Register
#define H6_NDFC_EMCE_IV_FAC_CMP_VAL 	(0x021C) // NDFC EMCE IV_FAC Compare Value Register
#define H6_NDFC_EMCE_IV_CAL_FACTOR_N(N)	(0x0220+0x04*N) // NDFC EMCE IV Calculate Factor Register N(N from 0 to 31)


// TODO: CSI
#define H6_CSI_BASE 								0x06620000
#define H6_CSI_TOP 								0x06620000
#define H6_CSI_PARSER 								0x06621000
#define H6_CSI_DMA0 								0x06623000
#define H6_CSI_DMA1 								0x06623100
#define H6_CSI_CCI0 								0x0662E000


// Display 
#define H6_TCON_TV0_BASE 				0x06515000
#define H6_TV_GCTL_REG 					(0x000) // TV Global Control Register
#define H6_TV_GINT0_REG 				(0x004) // TV Global Interrupt Register0
#define H6_TV_GINT1_REG 				(0x008) // TV Global Interrupt Register1
#define H6_TV_CTL_REG 					(0x090) // TV Control Register
#define H6_TV_BASIC0_REG 				(0x094) // TV Basic Timing Register0
#define H6_TV_BASIC1_REG 				(0x098) // TV Basic Timing Register1
#define H6_TV_BASIC2_REG 				(0x09C) // TV Basic Timing Register2
#define H6_TV_BASIC3_REG 				(0x0A0) // TV Basic Timing Register3
#define H6_TV_BASIC4_REG 				(0x0A4) // TV Basic Timing Register4
#define H6_TV_BASIC5_REG 				(0x0A8) // TV Basic Timing Register5
#define H6_TV_IO_POL_REG 				(0x088) // TV SYNC Signal Polarity Register
#define H6_TV_IO_TRI_REG 				(0x08C) // TV ISYNC Signal IO Control Register
#define H6_TV_DEBUG_REG 				(0x0FC) // TV Debug Register
#define H6_TV_CEU_CTL_REG 				(0x100) // TV CEU Control Register
#define H6_TV_CEU_COEF_MUL_REG(N)		(0x110+N*0x04) // TV CEU Coefficient Register0(N=0,1,2,4,5,6,8,9,10)
#define H6_TV_CEU_COEF_RANG_REG(N) 		(0x140+N*0x04) // TV CEU Coefficient Register2(N=0,1,2)
#define H6_TV_SAFE_PERIOD_REG 			(0x1F0) // TV Safe Period Register
#define H6_TV_FILL_CTL_REG 				(0x300) // TV Fill Data Control Register
#define H6_TV_FILL_BEGIN_REG(N) 		(0x304+N*0x0C) // TV Fill Data Begin Register(N=0,1,2)
#define H6_TV_FILL_END_REG(N) 			(0x308+N*0x0C) // TV Fill Data End Register(N=0,1,2)
#define H6_TV_FILL_DATA0_REG(N) 		(0x30C+N*0x0C) // TV Fill Data Value Register(N=0,1,2)
#define H6_TV_DATA_IO_POL0_REG 			(0x330) // TCON Data IO Polarity Control 0
#define H6_TV_DATA_IO_POL1_REG 			(0x334) // TCON Data IO Polarity Control 1
#define H6_TV_DATA_IO_TRI0_REG 			(0x338) // TCON Data IO Enable Control 0
#define H6_TV_DATA_IO_TRI1_REG 			(0x33C) // TCON Data IO Enable Control 1
#define H6_TV_PIXELDEPTH_MODE_REG 		(0x340) // TV Pixeldepth Mode Control Register



#define H6_TCON_LCD0_BASE 				0x06511000
#define H6_LCD_GCTL_REG 				(0x000) // LCD Global Control Register
#define H6_LCD_GINT0_REG 				(0x004) // LCD Global Interrupt Register0
#define H6_LCD_GINT1_REG 				(0x008) // LCD Global Interrupt Register1
#define H6_LCD_FRM_CTL_REG 				(0x010) // LCD FRM Control Register
#define H6_LCD_FRM_SEED_REG(N) 			(0x014+N*0x04) // LCD FRM Seed Register(N=0,1,2,3,4,5)
#define H6_LCD_FRM_TAB_REG(N)			(0x02C+N*0x04) // LCD FRM Table Register(N=0,1,2,3)
#define H6_LCD_3D_FIFO_REG 				(0x03C) // LCD 3D FIFO Register
#define H6_LCD_CTL_REG 					(0x040) // LCD Control Register
#define H6_LCD_DCLK_REG 				(0x044) // LCD Data Clock Register
#define H6_LCD_BASIC0_REG 				(0x048) // LCD Basic Timing Register0
#define H6_LCD_BASIC1_REG 				(0x04C) // LCD Basic Timing Register1
#define H6_LCD_BASIC2_REG 				(0x050) // LCD Basic Timing Register2
#define H6_LCD_BASIC3_REG 				(0x054) // LCD Basic Timing Register3
#define H6_LCD_HV_IF_REG 				(0x058) // LCD HV Panel Interface Register
#define H6_LCD_CPU_IF_REG 				(0x060) // LCD CPU Panel Interface Register
#define H6_LCD_CPU_WR_REG 				(0x064) // LCD CPU Panel Write Data Register
#define H6_LCD_CPU_RD0_REG 				(0x068) // LCD CPU Panel Read Data Register0
#define H6_LCD_CPU_RD1_REG 				(0x06C) // LCD CPU Panel Read Data Register1
#define H6_LCD_IO_POL_REG 				(0x088) // LCD IO Polarity Register
#define H6_LCD_IO_TRI_REG 				(0x08C) // LCD IO Control Register
#define H6_LCD_DEBUG_REG 				(0x0FC) // LCD Debug Register
#define H6_LCD_CEU_CTL_REG 				(0x100) // LCD CEU Control Register
#define H6_LCD_CEU_COEF_MUL_REG(N) 		(0x110+N*0x04) // LCD CEU Coefficient Register0(N=0,1,2,4,5,6,8,9,10)
#define H6_LCD_CEU_COEF_ADD_REG(N) 		(0x11C+N*0x10) // LCD CEU Coefficient Register1(N=0,1,2)
#define H6_LCD_CEU_COEF_RANG_REG(N)		(0x140+N*0x04) // LCD CEU Coefficient Register2(N=0,1,2)
#define H6_LCD_CPU_TRI0_REG 			(0x160)  // LCD CPU Panel Trigger Register0
#define H6_LCD_CPU_TRI1_REG 			(0x164)  // LCD CPU Panel Trigger Register1
#define H6_LCD_CPU_TRI2_REG 			(0x168)  // LCD CPU Panel Trigger Register2
#define H6_LCD_CPU_TRI3_REG 			(0x16C)  // LCD CPU Panel Trigger Register3
#define H6_LCD_CPU_TRI4_REG 			(0x170)  // LCD CPU Panel Trigger Register4
#define H6_LCD_CPU_TRI5_REG 			(0x174)  // LCD CPU Panel Trigger Register5
#define H6_LCD_CMAP_CTL_REG 			(0x180)  // LCD Color Map Control Register
#define H6_LCD_CMAP_ODD0_REG 			(0x190)  // LCD Color Map Odd Line Register0
#define H6_LCD_CMAP_ODD1_REG 			(0x194)  // LCD Color Map Odd Line Register1
#define H6_LCD_CMAP_EVEN0_REG 			(0x198)  // LCD Color Map Even Line Register0
#define H6_LCD_CMAP_EVEN1_REG 			(0x19C)  // LCD Color Map Even Line Register1
#define H6_LCD_SAFE_PERIOD_REG 			(0x1F0)  // LCD Safe Period Register
#define H6_LCD_GAMMA_TABLE_REG 			(0x400)  // LCD Gamma Table Registers


#define H6_ATE_TV_BASE 				0x4000
#define H6_TVE_CTL0 				(0x0000) // TV Encoder Control 0 Register
#define H6_TVE_CTL1 				(0x0002) // TV Encoder Control 1 Register
#define H6_TVE_MOD0 				(0x0004) // TV Encoder Mode 0 Register
#define H6_TVE_MOD1 				(0x0006) // TV Encoder Mode 1 Register
#define H6_TVE_DAC_CFG0 			(0x0008) // TV Encoder DAC Configuration 0 Register
#define H6_TVE_DAC_CFG1 			(0x000A) // TV Encoder DAC Configuration 1 Register
#define H6_TVE_YC_DELAY 			(0x000C) // TV Encoder YC Delay Register
#define H6_TVE_YC_FILTER 			(0x000E) // TV Encoder YC Filter Register
#define H6_TVE_BURST_FRQ0 			(0x0010) // TV Encoder Burst Frequency 0 Register
#define H6_TVE_BURST_FRQ1 			(0x0012) // TV Encoder Burst Frequency 1 Register
#define H6_TVE_FRONT_PORCH			(0x0014) // TV Encoder Front Porch Register
#define H6_TVE_BACK_PORCH 			(0x0016) // TV Encoder Back Porch Register
#define H6_TVE_TOTAL_LINE 			(0x001C) // TV Encoder Total Line Number Register
#define H6_TVE_FIRST_ACTIVE 		(0x001E) // TV Encoder First Active Line Register
#define H6_TVE_BLACK_LEVEL 			(0x0020) // TV Encoder Black Level Register
#define H6_TVE_BLANK_LEVEL 			(0x0022) // TV Encoder Blank Level Register
#define H6_TVE_PLUG_EN 				(0x0030) // TV Encoder Plug Detect Enable Register
#define H6_TVE_PLUG_IRQ_EN 			(0x0030) // TV Encoder Plug Detect Interrupt Enable Register
#define H6_TVE_PLUG_IRQ_STA 		(0x0034) // TV Encoder Plug Detect Interrupt Status Register
#define H6_TVE_PLUG_STA 			(0x0038) // TV Encoder Plug Detect Status Register
#define H6_TVE_PLUG_DEBOUNCE 		(0x0040) // TV Encoder Plug Detect De-Bounce Register
#define H6_TVE_PLUG_PULSE_LEVEL 	(0x00F4) // TV Encoder Plug Detect Pulse Level Register
#define H6_TVE_PLUG_PULSE_START 	(0x00F8) // TV Encoder Plug Detect Pulse Start Register
#define H6_TVE_PLUG_PULSE_PERIOD 	(0x00FA) // TV Encoder Auto Detect Pulse Period Register
#define H6_TVE_IF_CTL 				(0x1000) // TV Encoder Interface Control Register
#define H6_TVE_IF_TIM0 				(0x1008) // TV Encoder Interface Timing 0 Register
#define H6_TVE_IF_TIM1 				(0x100A) // TV Encoder Interface Timing 1 Register
#define H6_TVE_IF_TIM2 				(0x100C) // TV Encoder Interface Timing 2 Register
#define H6_TVE_IF_TIM3 				(0x100E) // TV Encoder Interface Timing 3 Register
#define H6_TVE_IF_SYNC0 			(0x1010) // TV Encoder Interface SYNC 0 Register
#define H6_TVE_IF_SYNC1 			(0x1012) // TV Encoder Interface SYNC 1 Register
#define H6_TVE_IF_SYNC2 			(0x1014) // TV Encoder Interface SYNC 2 Register
#define H6_TVE_IF_TIM4 				(0x1016) // TV Encoder Interface Timing 4 Register
#define H6_TVE_IF_STATUS 			(0x1018) // TV Encoder Interface Status Register



// AUDIO



// TWI
#define H6_TWI0_BASE 		0x05002000 
#define H6_TWI1_BASE 		0x05002400 
#define H6_TWI2_BASE 		0x05002800 
#define H6_R_TWI_BASE 		0x07081400

#define H6_TWI_ADDR 		0x0000 // TWI Slave address
#define H6_TWI_XADDR 		0x0004 // TWI Extended slave address
#define H6_TWI_DATA 		0x0008 // TWI Data byte
#define H6_TWI_CNTR 		0x000C // TWI Control register
#define H6_TWI_STAT 		0x0010 // TWI Status register
#define H6_TWI_CCR 			0x0014 // TWI Clock control register
#define H6_TWI_SRST 		0x0018 // TWI Software reset
#define H6_TWI_EFR 			0x001C // TWI Enhance Feature register
#define H6_TWI_LCR 			0x0020 // TWI Line Control register


// SPI 
#define H6_SPI0_BASE 			0x05010000 
#define H6_SPI1_BASE 			0x05011000
#define H6_SPI_GCR 				(0x0004) // SPI Global Control Register
#define H6_SPI_TCR 				(0x0008) // SPI Transfer Control register
#define H6_SPI_IER 				(0x0010) // SPI Interrupt Control register
#define H6_SPI_ISR 				(0x0014) // SPI Interrupt Status register
#define H6_SPI_FCR 				(0x0018) // SPI FIFO Control register
#define H6_SPI_FSR 				(0x001C) // SPI FIFO Status register
#define H6_SPI_WCR 				(0x0020) // SPI Wait Clock Counter register
#define H6_SPI_CCR 				(0x0024) // SPI Clock Rate Control register
#define H6_SPI_MBC 				(0x0030) // SPI Burst Counter register
#define H6_SPI_MTC 				(0x0034) // SPI Transmit Counter Register
#define H6_SPI_BCC 				(0x0038) // SPI Burst Control register
#define H6_SPI_BATCR 			(0x003C) // SPI Bit-Aligned Transfer Configure Register
#define H6_SPI_3W_CCR 			(0x0040) // SPI 3Wire CLOCK Configuration Register
#define H6_SPI_TBR 				(0x0044) // SPI TX Bit Register
#define H6_SPI_RBR 				(0x0048) // SPI RX Bit Register
#define H6_SPI_NDMA_MODE_CTL	(0x0088) // SPI Normal DMA Mode Control Register
#define H6_SPI_TXD 				(0x0200) // SPI TX Data register
#define H6_SPI_RXD 				(0x0300) // SPI RX Data register


#define H6_UART0_BASE 			0x05000000 
#define H6_UART1_BASE			0x05000400 
#define H6_UART2_BASE 			0x05000800 
#define H6_UART3_BASE 			0x05000C00 
#define H6_R_UART0_BASE 		0x07080000
#define H6_UART_RBR 			(0x0000) // UART Receive Buffer Register
#define H6_UART_THR 			(0x0000) // UART Transmit Holding Register
#define H6_UART_DLL 			(0x0000) // UART Divisor Latch Low Register
#define H6_UART_DLH 			(0x0004) // UART Divisor Latch High Register
#define H6_UART_IER 			(0x0004) // UART Interrupt Enable Register
#define H6_UART_IIR 			(0x0008) // UART Interrupt Identity Register
#define H6_UART_FCR 			(0x0008) // UART FIFO Control Register
#define H6_UART_FCR_FIFO_EN		0x01 /* Fifo enable */
#define H6_UART_FCR_CLEAR_RCVR	0x02 /* Clear the RCVR FIFO */
#define H6_UART_FCR_CLEAR_XMIT	0x04 /* Clear the XMIT FIFO */
#define H6_UART_FCR_DMA_SELECT	0x08 /* For DMA applications */
#define H6_UART_FCR_TRIGGER_MASK	0xC0 /* Mask for the FIFO trigger range */
#define H6_UART_FCR_TRIGGER_1	0x00 /* Mask for trigger set at 1 */
#define H6_UART_FCR_TRIGGER_4	0x40 /* Mask for trigger set at 4 */
#define H6_UART_FCR_TRIGGER_8	0x80 /* Mask for trigger set at 8 */
#define H6_UART_FCR_TRIGGER_14	0xC0 /* Mask for trigger set at 14 */
#define H6_UART_FCR_RXSR		0x02 /* Receiver soft reset */
#define H6_UART_FCR_TXSR		0x04 /* Transmitter soft reset */
#define H6_UART_FCRVAL 			(H6_UART_FCR_FIFO_EN | H6_UART_FCR_RXSR |H6_UART_FCR_TXSR)		/* Clear & enable FIFOs */

#define H6_UART_LCR 			(0x000C) // UART Line Control Register
#define H6_UART_LCR_WLS_MSK 	0x03		/* character length select mask */
#define H6_UART_LCR_WLS_5		0x00		/* 5 bit character length */
#define H6_UART_LCR_WLS_6		0x01		/* 6 bit character length */
#define H6_UART_LCR_WLS_7		0x02		/* 7 bit character length */
#define H6_UART_LCR_WLS_8		0x03		/* 8 bit character length */
#define H6_UART_LCR_STB			0x04		/* # stop Bits, off=1, on=1.5 or 2) */
#define H6_UART_LCR_PEN			0x08		/* Parity eneble */
#define H6_UART_LCR_EPS			0x10		/* Even Parity Select */
#define H6_UART_LCR_STKP		0x20		/* Stick Parity */
#define H6_UART_LCR_SBRK		0x40		/* Set Break */
#define H6_UART_LCR_BKSE		0x80		/* Bank select enable */
#define H6_UART_LCR_DLAB		0x80		/* Divisor latch access bit */
#define H6_UART_LCRVAL			0x03

#define H6_UART_MCR 			(0x0010) // UART Modem Control Register
#define H6_UART_MCR_AFCE		0x20 	
#define H6_UART_MCR_LOOP		0x10	/* Enable loopback test mode */
#define H6_UART_MCR_RTS			0x02	/* RTS complement */
#define H6_UART_MCR_DTR			0x01	/* DTR complement */
#define H6_UART_MCRVAL 			(H6_UART_MCR_DTR | H6_UART_MCR_RTS)		/* RTS/DTR */

#define H6_UART_LSR 			(0x0014) // UART Line Status Register
#define H6_UART_LSR_DR			0x01		/* Data ready */
#define H6_UART_LSR_OE			0x02		/* Overrun */
#define H6_UART_LSR_PE			0x04		/* Parity error */
#define H6_UART_LSR_FE			0x08		/* Framing error */
#define H6_UART_LSR_BI			0x10		/* Break */
#define H6_UART_LSR_THRE		0x20		/* Xmit holding register empty */
#define H6_UART_LSR_TEMT		0x40		/* Xmitter empty */
#define H6_UART_LSR_ERR			0x80		/* Error */

#define H6_UART_MSR 			(0x0018) // UART Modem Status Register
#define H6_UART_SCH 			(0x001C) // UART Scratch Register
#define H6_UART_USR 			(0x007C) // UART Status Register
#define H6_UART_USR             0x7c      /* UART Status Register*/
#define H6_UART_USR_TFNF        (0x1<<1)  /* TX FIFO full bit ofs*/
#define H6_TX_FIFO_FULL         0x1       /* TX FIFO not full */
#define H6_TX_FIFO_NOT_FULL     0x0       /* TX FIFO full */

#define H6_UART_TFL 			(0x0080) // UART Transmit FIFO Level Register
#define H6_UART_RFL 			(0x0084) // UART Receive FIFO Level Register
#define H6_UART_HSK 			(0x0088) // UART DMA Handshake Configuration Register
#define H6_UART_HALT 			(0x00A4) // UART Halt TX Register
#define H6_UART_DBG_DLL 		(0x00B0) // UART Debug DLL Register
#define H6_UART_DBG_DLH 		(0x00B4) // UART Debug DLH Register
#define H6_UART_485_CTL 		(0x00C0) // UART RS485 Control and Status Register
#define H6_RS485_ADDR_MATCH		(0x00C4) // UART RS485 Address Match Register
#define H6_BUS_IDLE_CHK 		(0x00C8) // UART RS485 Bus Idle Check Register
#define H6_TX_DLY 				(0x00CC) // UART TX Delay Register


// USB

#define H6_USB2_0_HOST 				0x05311000
// EHCI Capability Register
#define H6_E_CAPLENGTH 				(0x000) // EHCI Capability register Length Register
#define H6_E_HCIVERSION 			(0x002) // EHCI Host Interface Version Number Register
#define H6_E_HCSPARAMS 				(0x004) // EHCI Host Control Structural Parameter Register
#define H6_E_HCCPARAMS 				(0x008) // EHCI Host Control Capability Parameter Register
#define H6_E_HCSPPORTROUTE 			(0x00C) // EHCI Companion Port Route Description

// EHCI Operational Register
#define H6_E_USBCMD 				(0x010) // EHCI USB Command Register
#define H6_E_USBSTS 				(0x014) // EHCI USB Status Register
#define H6_E_USBINTR 				(0x018) // EHCI USB Interrupt Enable Register
#define H6_E_FRINDEX 				(0x01C) // EHCI USB Frame Index Register
#define H6_E_CTRLDSSEGMENT 			(0x020) // EHCI 4G Segment Selector Register
#define H6_E_PERIODICLISTBASE 		(0x024) // EHCI Frame List Base Address Register
#define H6_E_ASYNCLISTADDR 			(0x028) // EHCI Next Asynchronous List Address Register
#define H6_E_CONFIGFLAG 			(0x050) // EHCI Configured Flag Register
#define H6_E_PORTSC 				(0x054) // EHCI Port Status/Control Register
// OHCI Control and Status Partition Register
#define H6_O_HcRevision 			(0x400) // OHCI Revision Register
#define H6_O_HcControl 				(0x404) // OHCI Control Register
#define H6_O_HcCommandStatus 		(0x408) // OHCI Command Status Register
#define H6_O_HcInterruptStatus 		(0x40C) // OHCI Interrupt Status Register
#define H6_O_HcInterruptEnable 		(0x410) // OHCI Interrupt Enable Register
#define H6_O_HcInterruptDisable 	(0x414) // OHCI Interrupt Disable Register
// OHCI Memory Pointer Partition Register
#define H6_O_HcHCCA 				(0x418) // OHCI HCCA Base
#define H6_O_HcPeriodCurrentED 		(0x41C) // OHCI Period Current ED Base
#define H6_O_HcControlHeadED 		(0x420) // OHCI Control Head ED Base
#define H6_O_HcControlCurrentED 	(0x424) // OHCI Control Current ED Base
#define H6_O_HcBulkHeadED 			(0x428) // OHCI Bulk Head ED Base
#define H6_O_HcBulkCurrentED 		(0x42c) // OHCI Bulk Current ED Base
#define H6_O_HcDoneHead 			(0x430) // OHCI Done Head Base
// OHCI Frame Counter Partition Register
#define H6_O_HcFmInterval 			(0x434) // OHCI Frame Interval Register
#define H6_O_HcFmRemaining 			(0x438) // OHCI Frame Remaining Register
#define H6_O_HcFmNumber 			(0x43C) // OHCI Frame Number Register
#define H6_O_HcPerioddicStart 		(0x440) // OHCI Periodic Start Register
#define H6_O_HcLSThreshold 			(0x444) // OHCI LS Threshold Register
// OHCI Root Hub Partition Register
#define H6_O_HcRhDescriptorA 		(0x448) // OHCI Root Hub Descriptor Register A
#define H6_O_HcRhDesriptorB 		(0x44C) // OHCI Root Hub Descriptor Register B
#define H6_O_HcRhStatus 			(0x450) // OHCI Root Hub Status Register
#define H6_O_HcRhPortStatus 		(0x454) // OHCI Root Hub Port Status Register
// HCI Controller and PHY Interface Register
#define H6_HCI_INTERFACE 			(0x800) // HCI Interface Register
#define H6_PHY_CTR 					(0x810) // PHY Control Register
#define H6_HSIC_PHY_tune1 			(0x81C) // HSIC PHY Tune1 Register
#define H6_HSIC_PHY_tune2 			(0x820) // HSIC PHY Tune2 Register
#define H6_HSIC_PHY_tune3 			(0x824) // HSIC PHY Tune3 Register


// SCR
#define H6_SCR0_BASE			0x05005000 
#define H6_SCR1_BASE			0x05005400
#define H6_SCR_CSR 				(0x0000) // Smart Card Reader Control and Status Register
#define H6_SCR_INTEN 			(0x0004) // Smart Card Reader Interrupt Enable Register 1
#define H6_SCR_INTST 			(0x0008) // Smart Card Reader Interrupt Status Register 1
#define H6_SCR_FCSR 			(0x000C) // Smart Card Reader FIFO Control and Status Register
#define H6_SCR_FCNT 			(0x0010) // Smart Card Reader RX and TX FIFO Counter Register
#define H6_SCR_RPT 				(0x0014) // Smart Card Reader RX and TX Repeat Register
#define H6_SCR_DIV 				(0x0018) // Smart Card Reader Clock and Baud Divisor Register
#define H6_SCR_LTIM 			(0x001C) // Smart Card Reader Line Time Register
#define H6_SCR_CTIM 			(0x0020) // Smart Card Reader Character Time Register
#define H6_SCR_LCTLR 			(0x0030) // Smart Card Reader Line Control Register
#define H6_SCR_FSM 				(0x003C) // Smart Card Reader FSM Register
#define H6_SCR_DT 				(0x0040) // Smart Card Reader Debounce Time Register
#define H6_SCR_FIFO 			(0x0100) // Smart Card Reader RX and TX FIFO Access Point

// Ethernet Medium Access Controller
#define H6_EMAC_BASE 						0x05020000
#define H6_EMAC_BASIC_CTL0 					(0x0000) // EMAC Basic Control Register0
#define H6_EMAC_BASIC_CTL1 					(0x0004) // EMAC Basic Control Register1
#define H6_EMAC_INT_STA 					(0x0008) // EMAC Interrupt Status Register
#define H6_EMAC_INT_EN 						(0x000C) // EMAC Interrupt Enable Register
#define H6_EMAC_TX_CTL0 					(0x0010) // EMAC Transmit Control Register0
#define H6_EMAC_TX_CTL1 					(0x0014) // EMAC Transmit Control Register1
#define H6_EMAC_TX_FLOW_CTL					(0x001C) // EMAC Transmit Flow Control Register
#define H6_EMAC_TX_DMA_DESC_LIST 			(0x0020) // EMAC Transmit Descriptor List Address Register
#define H6_EMAC_RX_CTL0 					(0x0024) // EMAC Receive Control Register0
#define H6_EMAC_RX_CTL1 					(0x0028) // EMAC Receive Control Register1
#define H6_EMAC_RX_DMA_DESC_LIST 			(0x0034) // EMAC Receive Descriptor List Address Register
#define H6_EMAC_RX_FRM_FLT 					(0x0038) // EMAC Receive Frame Filter Register
#define H6_EMAC_RX_HASH0 					(0x0040) // EMAC Hash Table Register0
#define H6_EMAC_RX_HASH1 					(0x0044) // EMAC Hash Table Register1
#define H6_EMAC_MII_CMD 					(0x0048) // EMAC Management Interface Command Register
#define H6_EMAC_MII_DATA 					(0x004C) // EMAC Management Interface Data Register
#define H6_EMAC_ADDR_HIGH0 					(0x0050) // EMAC MAC Address High Register0
#define H6_EMAC_ADDR_LOW0 					(0x0054) // EMAC MAC Address High Register0
#define H6_EMAC_ADDR_HIGHx 					(0x0050+0x8*N) // (N=1~7) EMAC MAC Address High RegisterN(N:1~7)
#define H6_EMAC_ADDR_LOWx 					(0x0054+0x8*N) // (N=1~7) EMAC MAC Address Low RegisterN(N:1~7)
#define H6_EMAC_TX_DMA_STA 					(0x00B0) // EMAC Transmit DMA Status Register
#define H6_EMAC_TX_CUR_DESC 				(0x00B4) // EMAC Current Transmit Descriptor Register
#define H6_EMAC_TX_CUR_BUF 					(0x00B8) // EMAC Current Transmit Buffer Address Register
#define H6_EMAC_RX_DMA_STA 					(0x00C0) // EMAC Receive DMA Status Register
#define H6_EMAC_RX_CUR_DESC 				(0x00C4) // EMAC Current Receive Descriptor Register
#define H6_EMAC_RX_CUR_BUF 					(0x00C8) // EMAC Current Receive Buffer Address Register
#define H6_EMAC_RGMII_STA 					(0x00D0) // EMAC RGMII Status Register

// The transport stream controller(TSC)
#define H6_TSC_BASE  			0x05060000
#define H6_TSG_BASE  			0x05060040
#define H6_TSF0_BASE 			0x05060100
#define H6_TSD0_BASE 			0x05060180
#define H6_TSF1_BASE 			0x05060200
#define H6_TSD1_BASE 			0x05060280
#define H6_TSF2_BASE 			0x05060300
#define H6_TSD2_BASE 			0x05060380
#define H6_TSF3_BASE 			0x05060400
#define H6_TSD3_BASE 			0x05060480
#define H6_TSF4_BASE 			0x05060500
#define H6_TSD4_BASE 			0x05060580
#define H6_TSC_PCTLR 				(H6_TSC_BASE + 0x10) // TSC Port Control Register
#define H6_TSC_PPARR 				(H6_TSC_BASE + 0x14) // TSC Port Parameter Register
#define H6_TSC_TSFMUXR 				(H6_TSC_BASE + 0x20) // TSC TSF Input Multiplex Control Register
#define H6_TSC_KLAD_INDEX 			(H6_TSC_BASE + 0x28) // TSC KLAD Index Register
#define H6_TSC_IRQ_STATUS 			(H6_TSC_BASE + 0x30) // TSC Interrupt Status Register
#define H6_TSG_CTLR 				(H6_TSG_BASE + 0x00) // TSG Control Register
#define H6_TSG_PPR 					(H6_TSG_BASE + 0x04) // TSG Packet Parameter Register
#define H6_TSG_STAR 				(H6_TSG_BASE + 0x08) // TSG Status Register
#define H6_TSG_CCR 					(H6_TSG_BASE + 0x0C) // TSG Clock Control Register
#define H6_TSG_BBAR 				(H6_TSG_BASE + 0x10) // TSG Buffer Base Address Register
#define H6_TSG_BSZR 				(H6_TSG_BASE + 0x14) // TSG Buffer Size Register
#define H6_TSG_BPR 					(H6_TSG_BASE + 0x18) // TSG Buffer Pointer Register
#define H6_TSF_CTLR(TSF_BASE)		(TSF_BASE + 0x00) // TSF Control Register
#define H6_TSF_PPR(TSF_BASE)		(TSF_BASE + 0x04) // TSF Packet Parameter Register
#define H6_TSF_STAR(TSF_BASE)		(TSF_BASE + 0x08) // TSF Status Register
#define H6_TSF_DIER(TSF_BASE)		(TSF_BASE + 0x10) // TSF DMA Interrupt Enable Register
#define H6_TSF_OIER(TSF_BASE)		(TSF_BASE + 0x14) // TSF Overlap Interrupt Enable Register
#define H6_TSF_DISR(TSF_BASE)		(TSF_BASE + 0x18) // TSF DMA Interrupt Status Register
#define H6_TSF_OISR(TSF_BASE)		(TSF_BASE + 0x1C) // TSF Overlap Interrupt Status Register
#define H6_TSF_PCRCR(TSF_BASE)		(TSF_BASE + 0x20) // TSF PCR Control Register
#define H6_TSF_PCRDR(TSF_BASE)		(TSF_BASE + 0x24) // TSF PCR Data Register
#define H6_TSF_CENR(TSF_BASE)		(TSF_BASE + 0x30) // TSF Channel Enable Register
#define H6_TSF_CPER(TSF_BASE)		(TSF_BASE + 0x34) // TSF Channel PES Enable Register
#define H6_TSF_CDER(TSF_BASE)		(TSF_BASE + 0x38) // TSF Channel Descramble Enable Register
#define H6_TSF_CINDR(TSF_BASE)		(TSF_BASE + 0x3C) // TSF Channel Index Register
#define H6_TSF_CCTLR(TSF_BASE)		(TSF_BASE + 0x40) // TSF Channel Control Register
#define H6_TSF_CSTAR(TSF_BASE)		(TSF_BASE + 0x44) // TSF Channel Status Register
#define H6_TSF_CCWIR(TSF_BASE)		(TSF_BASE + 0x48) // TSF Channel CW Index Register
#define H6_TSF_CPIDR(TSF_BASE)		(TSF_BASE + 0x4C) // TSF Channel PID Register
#define H6_TSF_CBBAR(TSF_BASE)		(TSF_BASE + 0x50) // TSF Channel Buffer Base Address Register
#define H6_TSF_CBSZR(TSF_BASE)		(TSF_BASE + 0x54) // TSF Channel Buffer Size Register
#define H6_TSF_CBWPR(TSF_BASE)		(TSF_BASE + 0x58) // TSF Channel Buffer Write Pointer Register
#define H6_TSF_CBRPR(TSF_BASE)		(TSF_BASE + 0x5C) // TSF Channel Buffer Read Pointer Register
#define H6_TSD_CTLR(TSD_BASE)		(TSD_BASE + 0x00) // TSD Control Register
#define H6_TSD_CWIR(TSD_BASE)		(TSD_BASE + 0x1C) // TSD Control Word Index Register
#define H6_TSD_CWR(TSD_BASE) 		(TSD_BASE + 0x20) // TSD Control Word Register

// One Wire Interface

#define H6_R_OWC_BASE 				0x07040400
#define H6_OW_DATA 					(0x0000) // One Wire Data Register
#define H6_OW_CTL 					(0x0004) // One Wire Control Register
#define H6_OW_SMSC 					(0x0008) // One Wire Standard Mode Special Control Register
#define H6_OW_SMCRC 				(0x000C) // One Wire Standard Mode CRC Register
#define H6_OW_INT_STATUS 			(0x0010) // One Wire Interrupt Status Register
#define H6_OW_INT_MASK 				(0x0014) // One Wire Interrupt Mask Register
#define H6_OW_FCLK 					(0x0018) // One Wire Function Clock Register
#define H6_OW_LC 					(0x001C) // One Wire Line Control Register
#define H6_SM_WR_RD_TCTL 			(0x0020) // Standard Mode Write Read Timing Control Register
#define H6_SM_RST_PRESENCE_TCTL 	(0x0024) // Standard Mode Reset Presence Timing Control Register
#define H6_SP_WR_RD_TCTL 			(0x0028) // Simple Mode Timing Control Register
#define H6_SP_BR_TCTL 				(0x002C) // Simple Mode Break Timing Control Register

// CIR Transmitter
#define H6_CIR_TX_BASE 				0x05070400
#define H6_CIR_TGLR 				(0x0000) // CIR Transmit Global Register
#define H6_CIR_TMCR 				(0x0004) // CIR Transmit Modulation Control Register
#define H6_CIR_TCR 					(0x0008) // CIR Transmit Control Register
#define H6_CIR_IDC_H 				(0x000C) // CIR Transmit Idle Duration Threshold Register
#define H6_CIR_IDC_L 				(0x0010) // CIR Transmit Idle Duration Threshold Register
#define H6_CIR_TICR_H 				(0x0014) // CIR Transmit Idle Counter Register
#define H6_CIR_TICR_L 				(0x0018) // CIR Transmit Idle Counter Register
#define H6_CIR_TEL 					(0x0020) // CIR TX FIFO empty Level Register
#define H6_CIR_TXINT 				(0x0024) // CIR Transmit Interrupt Control Register
#define H6_CIR_TAC 					(0x0028) // CIR Transmit FIFO Available Counter Register
#define H6_CIR_TXSTA 				(0x002C) // CIR Transmit Status Register
#define H6_CIR_TXT 					(0x0030) // CIR Transmit Threshold Register
#define H6_CIR_DMA 					(0x0034) // CIR DMA Control Register
#define H6_CIR_TXFIFO 				(0x0080) // CIR Transmit FIFO Data Register

// CIR Receiver
#define H6_CIR_RX_BASE 				0x07040000
#define H6_CIR_CTL 					(0x0000) // CIR Control Register
#define H6_CIR_RXPCFG 				(0x0010) // CIR Receiver Pulse Configure Register
#define H6_CIR_RXFIFO 				(0x0020) // CIR Receiver FIFO Register
#define H6_CIR_RXINT 				(0x002C) // CIR Receiver Interrupt Control Register
#define H6_CIR_RXSTA 				(0x0030) // CIR Receiver Status Register
#define H6_CIR_RXCFG 				(0x0034) // CIR Receiver Configure Register


// EPHY
#define H6_ATE_EPHY_BASE 			0x6000
#define H6_EPHY_CTL 				(0x0000) // Ethernet PHY Control Register
#define H6_EPHY_BIST 				(0x0002) // Ethernet PHY BIST Register

#endif /* __ARM_ORANGE_PI_H_INCLUDED */
