#ifndef _RK3328_H_
#define _RK3328_H_

/* Bit definitions */
#define BIT0				0x00000001
#define BIT1				0x00000002
#define BIT2				0x00000004
#define BIT3				0x00000008
#define BIT4				0x00000010
#define BIT5				0x00000020
#define BIT6				0x00000040
#define BIT7				0x00000080
#define BIT8				0x00000100
#define BIT9				0x00000200
#define BIT10				0x00000400
#define BIT11				0x00000800
#define BIT12				0x00001000
#define BIT13				0x00002000
#define BIT14				0x00004000
#define BIT15				0x00008000
#define BIT16				0x00010000
#define BIT17				0x00020000
#define BIT18				0x00040000
#define BIT19				0x00080000
#define BIT20				0x00100000
#define BIT21				0x00200000
#define BIT22				0x00400000
#define BIT23				0x00800000
#define BIT24				0x01000000
#define BIT25				0x02000000
#define BIT26				0x04000000
#define BIT27				0x08000000
#define BIT28				0x10000000
#define BIT29				0x20000000
#define BIT30				0x40000000
#define BIT31				0x80000000

#define BIT(nr)				(1 << (nr))
#define RKPM_SLP_CTR_VOL_PWM0		BIT(10)
#define RKPM_SLP_CTR_VOL_PWM1		BIT(11)
/* Size definitions */


////////////////// Interrupt /////////////////
#define BUS_DMAC_IRQ  			(32) 
#define BUS_DMAC_IRQ_ABORT  	(33) 
#define DFI_ALERT_ERR_INTR  	(34) 
#define UPCTL_AWPOISON_INTR  	(35) 
#define SDMMC_EXT_INT  			(36) 
#define VOP_INTR_DDR  			(37) 
#define SDMMC_EXT_DECTN_IN  	(38) 
#define RKVDEC_M_DEC_IRQ  		(39) 
#define UPCTL_ARPOISON_INTR 	(40) 
#define VPU_XINTDEC_IRQ  		(41) 
#define SDMMC_EXT_DETECTN_IRQ  	(42) 
#define VPU_MMU_IRQ  			(43) 
#define SDMMC_INT  				(44) 
#define SDIO_INT  				(45) 
#define EMMC_INT  				(46) 
#define OTP_INT_NS  			(47) 
#define HOST0_EHCI_INT  		(48) 
#define HOST0_OHCI_INT  		(49) 
#define HOST0_ARB_INT  			(50) 
#define OTP_INT_S  				(51) 
#define DDRMON_INT  			(52) 
#define GMAC2PHY_INT  			(53) 
#define GMAC2PHY_PMT_INT  		(54) 
#define OTG_INT  				(55) 
#define GMAC2IO_INT  			(56) 
#define GMAC2IO_PMT_INT  		(57) 
#define I2S0_8CH_INTR  			(58) 
#define I2S1_8CH_INTR  			(59) 
#define I2S2_2CH_INTR  			(60) 
#define SPDIF_8CH_INTR  		(61) 
#define CRYPTO_INT  			(62) 
#define IEP_INTR  				(63) 
#define VOP_INTR  				(64) 
#define RGA_INTR  				(65)
#define HDCP_INTR  				(66) 
#define HDMI_INTR  				(67) 
#define RKI2C0_INT 				(68)   
#define RKI2C1_INT 				(69)   
#define RKI2C2_INT 				(70)   
#define RKI2C3_INT 				(71)   
#define WDT_INTR  				(72) 
#define STIMER_INTR0  			(73) 
#define STIMER_INTR1  			(74) 
#define TIMER_INTR0 			(75)  
#define TIMER_INTR1 			(76)  
#define TIMER_INTR2 			(77)  
#define TIMER_INTR3 			(78)  
#define TIMER_INTR4 			(79)  
#define TIMER_INTR5 			(80)  
#define SPI0_INTR  				(81) 
#define RKPWM_INT  				(82) 
#define GPIO0_INTR 				(83)  
#define GPIO1_INTR 				(84)  
#define GPIO2_INTR 				(85)  
#define GPIO3_INTR 				(86)  
#define UART0_INTR 				(87)  
#define UART1_INTR 				(88)  
#define UART2_INTR 				(89)  
#define TSADC_INT  				(90) 
#define USBPHY_OTG_BVALID_IRQ  	(91) 
#define USBPHY_OTG_ID_IRQ  			(92) 
#define USBPHY_OTG_LINESTATE_IRQ  	(93) 
#define USBPHY_HOST_LINESTATE_IRQ  	(94) 
#define SDMMC_DETECTN_IRQ  			(95) 
#define CIF_INTR  					(96) 
#define SDMMC_DECTN_IN_FLT  		(97) 
#define USB3OTG_HOST_LEGACY_SMI_INTERRUPT  	(98 ) 
#define USB3OTG_INT  						(99 ) 
#define USB3OTG_HOST_SYS_ERR  				(100) 
#define USB3OTG_PME_GENERATION  			(101) 
#define MACPHY_INT  						(102)
#define HDMI_INTR_WAKEUP 					(103) 
#define TSP_INT  							(104) 
#define SIM_INT  							(105) 
#define RKVDEC_M_MMU_IRQ  					(106) 
#define USB3PHY_BVALID_IRQ  				(107) 
#define USB3PHY_ID_IRQ  					(108) 
#define USB3PHY_LINESTATE_IRQ  				(109) 
#define USB3PHY_RXDET_IRQ  					(110) 
#define EFUSE_INT  							(111) 
#define SARADC_INT  						(112) 
#define TSP_INT_MMU  						(113) 
#define PDM_INT  							(114) 
#define HDMIPHY_IRQ 						(115) 
#define DCF_DONE_INT 			(116)  
#define DCF_ERROR_INT			(117)  
#define PMU_INT 				(118)  
#define IRQ_GPU_GPMMU			(119)  
#define IRQ_GPU_PP0 			(120)  
#define IRQ_GPU_PPMMU0 			(121) 
#define IRQ_GPU_GP 				(122)  
#define IRQ_GPU_PP1 			(123)  
#define IRQ_GPU_PPMMU1 			(124)  
#define IRQ_GPU_PP 				(125)  
#define IRQ_GPU_PMU 			(126)  
#define RKVENC_H265_INT 		(127)  
#define RKVENC_H265_MMU_INT		(128)  
#define RKVENC_H264_ENC_INT		(129)  
#define RKVENC_H264_MMU_INT		(130)  
#define NPMUIRQ0 				(132) 
#define NPMUIRQ1 				(133) 
#define NPMUIRQ2 				(134) 
#define NPMUIRQ3 				(135) 
#define NVCPUMNTIRQ0 			(136)  
#define NVCPUMNTIRQ1 			(137)  
#define NVCPUMNTIRQ2 			(138)  
#define NVCPUMNTIRQ3 			(139)  
#define NCOMMIRQ0				(140)  
#define NCOMMIRQ1				(141)  
#define NCOMMIRQ2				(142)  
#define NCOMMIRQ3				(143)  
#define NAXIERRIRQ 				(144)  
////////////////// END Interrupt /////////////////


#define RK3328_I2S0_BASE	0xFF000000
#define RK3328_I2S1_BASE	0xFF010000
#define RK3328_I2S2_BASE	0xFF020000
#define RK3328_SPDIF_BASE	0xFF030000
#define RK3328_PDM_BASE		0xFF040000
#define RK3328_TSP_BASE		0xFF050000
#define RK3328_ICRYPTO_BASE		0xFF060000
#define RK3328_BOOTROM_BASE		0xFF080000
#define RK3328_INT_MEM_BASE		0xFF090000
#define RK3328_OTP_S_BASE		0xFF0A0000
#define RK3328_EFUSE_S_BASE		0xFF0B0000
#define RK3328_DMAC_S_BASE		0xFF0C0000
#define RK3328_SGRF_BASE		0xFF0D0000


#define RK3328_UART0_BASE		0xFF110000
#define RK3328_UART1_BASE		0xFF120000
#define RK3328_UART2_BASE		0xFF130000
#define RK3328_UART2_SIZE		0x100
//        Name 					Offset 	 Size Reset 	Value Description
#define RK3328_UART_RBR 		0x0000 // W 0x00000000 Receive Buffer Register
#define RK3328_UART_THR 		0x0000 // W 0x00000000 Transmit Holding Register
#define RK3328_UART_DLL 		0x0000 // W 0x00000000 Divisor Latch (Low)
#define RK3328_UART_DLH 		0x0004 // W 0x00000000 Divisor Latch (High)
#define RK3328_UART_IER 		0x0004 // W 0x00000000 Interrupt Enable Register
	/*
	 * These are the definitions for the Interrupt Enable Register
	 */
	#define RK3328_UART_IER_MSI	0x08	/* Enable Modem status interrupt */
	#define RK3328_UART_IER_RLSI	0x04	/* Enable receiver line status interrupt */
	#define RK3328_UART_IER_THRI	0x02	/* Enable Transmitter holding register int. */
	#define RK3328_UART_IER_RDI	0x01	/* Enable receiver data interrupt */
	#define RK3328_UART_IER_ALL (RK3328_UART_IER_MSI | RK3328_UART_IER_RLSI  \
								| RK3328_UART_IER_THRI | RK3328_UART_IER_RDI)
#define RK3328_UART_IIR 		0x0008 // W 0x00000000 Interrupt Identification Register
	/*
	 * These are the definitions for the Interrupt Identification Register
	 */
	#define RK3328_UART_IIR_NO_INT	0x01	/* No interrupts pending */
	#define RK3328_UART_IIR_MSI		0x00	/* Modem status interrupt */
	#define RK3328_UART_IIR_THRI	0x02	/* Transmitter holding register empty */
	#define RK3328_UART_IIR_RDI		0x04	/* Receiver data interrupt */
	#define RK3328_UART_IIR_RLSI	0x06	/* Receiver line status interrupt */
	#define RK3328_UART_IIR_RBDI	0x07	/* busy detect status interrupt */
	#define RK3328_UART_IIR_RCTI	0x0C	/* character timeout status interrupt */
	#define RK3328_UART_IIR_RFEI	0xC0	/* FIFOs Enabled status interrupt */

#define RK3328_UART_FCR 		0x0008 // W 0x00000000 FIFO Control Register
	#define RK3328_UART_FCR_FIFO_EN	0x01 /* Fifo enable */
	#define RK3328_UART_FCR_CLEAR_RCVR	0x02 /* Clear the RCVR FIFO */
	#define RK3328_UART_FCR_CLEAR_XMIT	0x04 /* Clear the XMIT FIFO */
	#define RK3328_UART_FCR_DMA_SELECT	0x08 /* For DMA applications */
	#define RK3328_UART_FCR_RX_MASK	0xC0 /* Mask for the FIFO trigger range */
	#define RK3328_UART_FCR_TX_1	0x00 /* Mask for trigger set at 1 */
	#define RK3328_UART_FCR_TX_4	0x10 /* Mask for trigger set at 4 */
	#define RK3328_UART_FCR_TX_8	0x20 /* Mask for trigger set at 8 */
	#define RK3328_UART_FCR_TX_14	0x30 /* Mask for trigger set at 14 */
	#define RK3328_UART_FCR_RX_1	0x00 /* Mask for trigger set at 1 */
	#define RK3328_UART_FCR_RX_4	0x40 /* Mask for trigger set at 4 */
	#define RK3328_UART_FCR_RX_8	0x80 /* Mask for trigger set at 8 */
	#define RK3328_UART_FCR_RX_14	0xC0 /* Mask for trigger set at 14 */
	#define RK3328_UART_FCR_RXSR		0x02 /* Receiver soft reset */
	#define RK3328_UART_FCR_TXSR		0x04 /* Transmitter soft reset */
	/* Ingenic JZ47xx specific UART-enable bit. */
	#define RK3328_UART_FCR_UME		0x10
	/* Clear & enable FIFOs */
	#define RK3328_UART_FCR_DEFVAL (RK3328_UART_FCR_FIFO_EN | \
				RK3328_UART_FCR_RXSR |	RK3328_UART_FCR_TXSR)

#define RK3328_UART_LCR 		0x000c // W 0x00000000 Line Control Register
	/*
	 * These are the definitions for the Line Control Register
	 *
	 * Note: if the word length is 5 bits (UART_LCR_WLEN5), then setting
	 * UART_LCR_STOP will select 1.5 stop bits, not 2 stop bits.
	 */
	#define RK3328_UART_LCR_WLS_MSK 0x03		/* character length select mask */
	#define RK3328_UART_LCR_WLS_5	0x00		/* 5 bit character length */
	#define RK3328_UART_LCR_WLS_6	0x01		/* 6 bit character length */
	#define RK3328_UART_LCR_WLS_7	0x02		/* 7 bit character length */
	#define RK3328_UART_LCR_WLS_8	0x03		/* 8 bit character length */
	#define RK3328_UART_LCR_STB	0x04		/* # stop Bits, off=1, on=1.5 or 2) */
	#define RK3328_UART_LCR_PEN	0x08		/* Parity enable */
	#define RK3328_UART_LCR_EPS	0x10		/* Even Parity Select */
	#define RK3328_UART_LCR_STKP	0x20		/* Stick Parity */
	#define RK3328_UART_LCR_SBRK	0x40		/* Set Break */
	#define RK3328_UART_LCR_BKSE	0x80		/* Bank select enable */
	#define RK3328_UART_LCR_DLAB	0x80		/* Divisor latch access bit */
	/* useful defaults for LCR */
	#define RK3328_UART_LCR_8N1	0x03
#define RK3328_UART_MCR 		0x0010 // W 0x00000000 Modem Control Register
	/*
	 * These are the definitions for the Modem Control Register
	 */
	#define RK3328_UART_MCR_DTR	0x01		/* DTR   */
	#define RK3328_UART_MCR_RTS	0x02		/* RTS   */
	#define RK3328_UART_MCR_OUT1	0x04		/* Out 1 */
	#define RK3328_UART_MCR_OUT2	0x08		/* Out 2 */
	#define RK3328_UART_MCR_LOOP	0x10		/* Enable loopback test mode */
	#define RK3328_UART_MCR_AFE	0x20		/* Enable auto-RTS/CTS */
	#define RK3328_UART_MCR_DMA_EN	0x04
	#define RK3328_UART_MCR_TX_DFR	0x08
#define RK3328_UART_LSR 		0x0014 // W 0x00000000 Line Status Register
	/*
	 * These are the definitions for the Line Status Register
	 */
	#define RK3328_UART_LSR_DR	0x01		/* Data ready */
	#define RK3328_UART_LSR_OE	0x02		/* Overrun */
	#define RK3328_UART_LSR_PE	0x04		/* Parity error */
	#define RK3328_UART_LSR_FE	0x08		/* Framing error */
	#define RK3328_UART_LSR_BI	0x10		/* Break */
	#define RK3328_UART_LSR_THRE	0x20		/* Xmit holding register empty */
	#define RK3328_UART_LSR_TEMT	0x40		/* Xmitter empty */
	#define RK3328_UART_LSR_ERR	0x80		/* Error */

#define RK3328_UART_MSR 		0x0018 // W 0x00000000 Modem Status Register
	#define RK3328_UART_MSR_DCD	0x80		/* Data Carrier Detect */
	#define RK3328_UART_MSR_RI	0x40		/* Ring Indicator */
	#define RK3328_UART_MSR_DSR	0x20		/* Data Set Ready */
	#define RK3328_UART_MSR_CTS	0x10		/* Clear to Send */
	#define RK3328_UART_MSR_DDCD	0x08		/* Delta DCD */
	#define RK3328_UART_MSR_TERI	0x04		/* Trailing edge ring indicator */
	#define RK3328_UART_MSR_DDSR	0x02		/* Delta DSR */
	#define RK3328_UART_MSR_DCTS	0x01		/* Delta CTS */

#define RK3328_UART_SCR 		0x001c // W 0x00000000 Scratchpad Register
#define RK3328_UART_SRBR 		0x0030 // W 0x00000000 Shadow Receive Buffer Register
#define RK3328_UART_STHR 		0x006c // W 0x00000000 Shadow Transmit Holding Register
#define RK3328_UART_FAR 		0x0070 // W 0x00000000 FIFO Access Register
#define RK3328_UART_TFR 		0x0074 // W 0x00000000 Transmit FIFO Read
#define RK3328_UART_RFW 		0x0078 // W 0x00000000 Receive FIFO Write
#define RK3328_UART_USR 		0x007c // W 0x00000000 UART Status Register
	#define RK3328_UART_USR_RX_FIFO_FULL		0x10 /* Receive FIFO full */
	#define RK3328_UART_USR_RX_FIFO_NOT_EMPTY	0x08 /* Receive FIFO not empty */
	#define RK3328_UART_USR_TX_FIFO_EMPTY		0x04 /* Transmit FIFO empty */
	#define RK3328_UART_USR_TX_FIFO_NOT_FULL	0x02 /* Transmit FIFO not full */
	#define RK3328_UART_USR_BUSY			0x01 /* UART busy indicator */
#define RK3328_UART_TFL 		0x0080 // W 0x00000000 Transmit FIFO Level
#define RK3328_UART_RFL 		0x0084 // W 0x00000000 Receive FIFO Level
#define RK3328_UART_SRR 		0x0088 // W 0x00000000 Software Reset Register
#define RK3328_UART_SRTS 		0x008c // W 0x00000000 Shadow Request to Send
#define RK3328_UART_SBCR 		0x0090 // W 0x00000000 Shadow Break Control Register
#define RK3328_UART_SDMAM 		0x0094 // W 0x00000000 Shadow DMA Mode
#define RK3328_UART_SFE 		0x0098 // W 0x00000000 Shadow FIFO Enable
#define RK3328_UART_SRT 		0x009c // W 0x00000000 Shadow RCVR Trigger
#define RK3328_UART_STET 		0x00a0 // W 0x00000000 Shadow TX Empty Trigger
#define RK3328_UART_HTX 		0x00a4 // W 0x00000000 Halt TX
#define RK3328_UART_DMASA 		0x00a8 // W 0x00000000 DMA Software Acknowledge
#define RK3328_UART_CPR 		0x00f4 // W 0x00000000 Component Parameter Register
#define RK3328_UART_UCV 		0x00f8 // W 0x0330372a UART Component Version
#define RK3328_UART_CTR 		0x00fc // W 0x44570110 Component Type Register

#define RK3328_UART_LCRVAL RK3328_UART_LCR_8N1		/* 8 data, 1 stop, no parity */
#define RK3328_UART_MCRVAL (RK3328_UART_MCR_DTR | RK3328_UART_MCR_RTS)		/* RTS/DTR */

#define RK3328_PMU_BASE			0xFF140000
#define RK3328_I2C0_BASE		0xFF150000
#define RK3328_I2C1_BASE		0xFF160000
#define RK3328_I2C2_BASE		0xFF170000
#define RK3328_I2C3_BASE		0xFF180000
#define RK3328_SPI_BASE			0xFF190000
#define RK3328_WDT_BASE			0xFF1A0000
	#define RK3328_WDT_CR 		0x0000 // W 0x0000000a Control Register
	#define RK3328_WDT_CR_EN_OFFSET	0x00
	#define RK3328_WDT_CR_RMOD_OFFSET	0x01
	#define RK3328_WDT_CR_RMOD_VAL	0x00
	#define RK3328_WDT_TORR 	0x0004 // W 0x00000000 Timeout range Register
	#define RK3328_WDT_CCVR 	0x0008 // W 0x00000000 Current counter value Register
	#define RK3328_WDT_CRR 		0x000c // W 0x00000000 Counter restart Register
	#define RK3328_WDT_CRR_RESTART_VAL	0x76
	#define RK3328_WDT_STAT 	0x0010 // W 0x00000000 Interrupt status Register
	#define RK3328_WDT_EOI 		0x0014 // W 0x00000000 Interrupt clear Register		
#define RK3328_PWM_BASE			0xFF1B0000
#define RK3328_TIMER_BASE		0xFF1C0000
#define RK3328_STIMER_BASE		0xFF1D0000
#define RK3328_DCF_BASE			0xFF1E0000
#define RK3328_DMAC_NS_BASE		0xFF1F0000
#define RK3328_SIM_BASE			0xFF200000

//////////////////// GPIO /////////////////////	
#define RK3328_GPIO0_BASE		0xFF210000
#define RK3328_GPIO1_BASE			0xFF220000
#define RK3328_GPIO2_BASE			0xFF230000
#define RK3328_GPIO3_BASE			0xFF240000

#define RK3328_GPIO_SWPORTA_DR 	0x0000 // W 0x00000000 Port A data register
#define RK3328_GPIO_SWPORTA_DDR 	0x0004 // W 0x00000000 Port A data direction register
#define RK3328_GPIO_INTEN 			0x0030 // W 0x00000000 Interrupt enable register
#define RK3328_GPIO_INTMASK 		0x0034 // W 0x00000000 Interrupt mask register
#define RK3328_GPIO_INTTYPE_LEVEL 	0x0038 // W 0x00000000 Interrupt level register
#define RK3328_GPIO_INT_POLARITY 	0x003c // W 0x00000000 Interrupt polarity register
#define RK3328_GPIO_INT_STATUS 	0x0040 // W 0x00000000 Interrupt status of port A
#define RK3328_GPIO_INT_RAWSTATUS 	0x0044 // W 0x00000000 Raw Interrupt status of port A
#define RK3328_GPIO_DEBOUNCE 		0x0048 // W 0x00000000 Debounce enable register
#define RK3328_GPIO_PORTA_EOI 		0x004c // W 0x00000000 Port A clear interrupt register
#define RK3328_GPIO_EXT_PORTA 		0x0050 // W 0x00000000 Port A external port register
#define RK3328_GPIO_LS_SYNC 		0x0060 // W 0x00000000 Level_sensitive synchronization enable register
//////////////////////////////////////////////////

#define RK3328_GRF_BASE			0xFF100000

#define GRF_GPIO0A_IOMUX 		0x0000 // W 0x00000000 GPIO0A iomux control
#define GRF_GPIO0B_IOMUX 		0x0004 // W 0x00000000 GPIO0B iomux control
#define GRF_GPIO0C_IOMUX 		0x0008 // W 0x00000000 GPIO0C iomux control
#define GRF_GPIO0D_IOMUX 		0x000c // W 0x00000000 GPIO0D iomux control
#define GRF_GPIO1A_IOMUX 		0x0010 // W 0x000004aa GPIO1A iomux control
#define GRF_GPIO1B_IOMUX 		0x0014 // W 0x00000000 GPIO1B iomux control
#define GRF_GPIO1C_IOMUX 		0x0018 // W 0x00000000 GPIO1C iomux control
#define GRF_GPIO1D_IOMUX 		0x001c // W 0x00000000 GPIO1D iomux control
#define GRF_GPIO2A_IOMUX 		0x0020 // W 0x00000000 GPIO2A iomux control
#define GRF_GPIO2BL_IOMUX 		0x0024 // W 0x00000200 GPIO2BL iomux control
#define GRF_GPIO2BH_IOMUX 		0x0028 // W 0x00000000 GPIO2BH iomux control
#define GRF_GPIO2CL_IOMUX 		0x002c // W 0x00000000 GPIO2CL iomux control
#define GRF_GPIO2CH_IOMUX 		0x0030 // W 0x00000000 GPIO2CH iomux control
#define GRF_GPIO2D_IOMUX 		0x0034 // W 0x00000000 GPIO2D iomux control
#define GRF_GPIO3AL_IOMUX 		0x0038 // W 0x00000000 GPIO3AL iomux control
#define GRF_GPIO3AH_IOMUX 		0x003c // W 0x00000000 GPIO3AH iomux control
#define GRF_GPIO3BL_IOMUX 		0x0040 // W 0x00000000 GPIO3BL iomux control
#define GRF_GPIO3BH_IOMUX 		0x0044 // W 0x00000000 GPIO3BH iomux control
#define GRF_GPIO3C_IOMUX 		0x0048 // W 0x00000000 GPIO3C iomux control
#define GRF_GPIO3D_IOMUX 		0x004c // W 0x00000000 GPIO3D iomux control
#define GRF_COM_IOMUX 			0x0050 // W 0x00000000 GRF common iomux control
#define GRF_GPIO0A_P 			0x0100 // W 0x0000566a GPIO0A PU/PD control
#define GRF_GPIO0B_P 			0x0104 // W 0x0000aa6a GPIO0B PU/PD control
#define GRF_GPIO0C_P 			0x0108 // W 0x0000aa6a GPIO0C PU/PD control
#define GRF_GPIO0D_P 			0x010c // W 0x0000aaaa GPIO0D PU/PD control
#define GRF_GPIO1A_P 			0x0110 // W 0x0000a555 GPIO1A PU/PD control
#define GRF_GPIO1B_P 			0x0114 // W 0x000056a5 GPIO1B PU/PD control
#define GRF_GPIO1C_P 			0x0118 // W 0x00009a65 GPIO1C PU/PD control
#define GRF_GPIO1D_P 			0x011c // W 0x0000aaaa GPIO1D PU/PD control
#define GRF_GPIO2A_P 			0x0120 // W 0x00009556 GPIO2A PU/PD control
#define GRF_GPIO2B_P 			0x0124 // W 0x0000959a GPIO2B PU/PD control
#define GRF_GPIO2C_P 			0x0128 // W 0x00005565 GPIO2C PU/PD control
#define GRF_GPIO2D_P 			0x012c // W 0x000055a5 GPIO2D PU/PD control
#define GRF_GPIO3A_P 			0x0130 // W 0x000055a5 GPIO3A PU/PD control
#define GRF_GPIO3B_P 			0x0134 // W 0x00005aaa GPIO3B PU/PD control
#define GRF_GPIO3C_P 			0x0138 // W 0x00006555 GPIO3C PU/PD control
#define GRF_GPIO3D_P 			0x013c // W 0x0000555a GPIO3D PU/PD control
#define GRF_GPIO0A_E 			0x0200 // W 0x00008011 GPIO0A drive strength control
#define GRF_GPIO0B_E 			0x0204 // W 0x0000aa2a GPIO0B drive strength control
#define GRF_GPIO0C_E 			0x0208 // W 0x0000aa0a GPIO0C drive strength control
#define GRF_GPIO0D_E 			0x020c // W 0x0000005a GPIO0D drive strength control
#define GRF_GPIO1A_E 			0x0210 // W 0x0000aaaa GPIO1A drive strength control
#define GRF_GPIO1B_E 			0x0214 // W 0x0000aa2a GPIO1B drive strength control
#define GRF_GPIO1C_E 			0x0218 // W 0x0000a88a GPIO1C drive strength control
#define GRF_GPIO1D_E 			0x021c // W 0x0000005a GPIO1D drive strength control
#define GRF_GPIO2A_E 			0x0220 // W 0x00000000 GPIO2A drive strength control
#define GRF_GPIO2B_E 			0x0224 // W 0x00004145 GPIO2B drive strength control
#define GRF_GPIO2C_E 			0x0228 // W 0x00005515 GPIO2C drive strength control
#define GRF_GPIO2D_E 			0x022c // W 0x0000aa01 GPIO2D drive strength control
#define GRF_GPIO3A_E 			0x0230 // W 0x0000aa22 GPIO3A drive strength control
#define GRF_GPIO3B_E 			0x0234 // W 0x00000000 GPIO3B drive strength control
#define GRF_GPIO3C_E 			0x0238 // W 0x0000aaaa GPIO3C drive strength control
#define GRF_GPIO3D_E 			0x023c // W 0x0000aaaa GPIO3D drive strength control
#define GRF_GPIO0L_SR 			0x0300 // W 0x00000000 GPIO0 A/B SR control
#define GRF_GPIO0H_SR 			0x0304 // W 0x00000000 GPIO0 C/D SR control
#define GRF_GPIO1L_SR 			0x0308 // W 0x00000000 GPIO1 A/B SR control
#define GRF_GPIO1H_SR 			0x030c // W 0x00000000 GPIO1 C/D SR control
#define GRF_GPIO2L_SR 			0x0310 // W 0x00000000 GPIO2 A/B SR control
#define GRF_GPIO2H_SR 			0x0314 // W 0x00000000 GPIO2 C/D SR control
#define GRF_GPIO3L_SR 			0x0318 // W 0x00000000 GPIO3 A/B SR control
#define GRF_GPIO3H_SR 			0x031c // W 0x00000000 GPIO3 C/D SR control
#define GRF_GPIO0L_SMT 			0x0380 // W 0x00000000 GPIO0 A/B smitter control register
#define GRF_GPIO0H_SMT 			0x0384 // W 0x00000000 GPIO0 C/D smitter control register
#define GRF_GPIO1L_SMT 			0x0388 // W 0x00000000 GPIO1 A/B smitter control register
#define GRF_GPIO1H_SMT 			0x038c // W 0x00000000 GPIO1 C/D smitter control register
#define GRF_GPIO2L_SMT 			0x0390 // W 0x00000000 GPIO2 A/B smitter control register
#define GRF_GPIO2H_SMT 			0x0394 // W 0x00000000 GPIO2 C/D smitter control register
#define GRF_GPIO3L_SMT 			0x0398 // W 0x00000000 GPIO3 A/B smitter control register
#define GRF_GPIO3H_SMT 			0x039c // W 0x00000000 GPIO3 C/D smitter control register
#define GRF_SOC_CON0 			0x0400 // W 0x00000000 SOC control register0
#define GRF_SOC_CON1 			0x0404 // W 0x00000000 SOC control register1
#define GRF_SOC_CON2 			0x0408 // W 0x00001000 SOC control register2
#define GRF_SOC_CON3 			0x040c // W 0x00000000 SOC control register3
#define GRF_SOC_CON4 			0x0410 // W 0x00000000 SOC control register4
#define GRF_SOC_CON5 			0x0414 // W 0x00000000 SOC control register5
#define GRF_SOC_CON6 			0x0418 // W 0x00000000 SOC control register6
#define GRF_SOC_CON7 			0x041c // W 0x00000000 SOC control register7
#define GRF_SOC_CON8 			0x0420 // W 0x00000000 SOC control register8
#define GRF_SOC_CON9 			0x0424 // W 0x00000000 SOC control register9
#define GRF_SOC_CON10 			0x0428 // W 0x0000f800 SOC control register10
#define GRF_SOC_STATUS0 		0x0480 // W 0x00000000 SOC status register0
#define GRF_SOC_STATUS1 		0x0484 // W 0x00000000 SOC status register1
#define GRF_SOC_STATUS2 		0x0488 // W 0x00000000 SOC status register2
#define GRF_SOC_STATUS3 		0x048c // W 0x00000000 SOC status register3
#define GRF_SOC_STATUS4 		0x0490 // W 0x00000000 SOC status register4
#define GRF_USB3OTG_CON0 		0x04c0 // W 0x00002000 USB3OTG control register0
#define GRF_USB3OTG_CON1 		0x04c4 // W 0x00001100 USB3OTG control register1
#define GRF_CPU_CON0 			0x0500 // W 0x00000060 CPU control register0
#define GRF_CPU_CON1 			0x0504 // W 0x0000000c CPU control register1
#define GRF_CPU_STATUS0 		0x0520 // W 0x00000000 CPU status register0
#define GRF_CPU_STATUS1 		0x0524 // W 0x00000000 CPU status register1
#define GRF_OS_REG0 			0x05c8 // W 0x00000000 os register0
#define GRF_OS_REG1 			0x05cc // W 0x00000000 os register1
#define GRF_OS_REG2 			0x05d0 // W 0x00000000 os register2
#define GRF_OS_REG3 			0x05d4 // W 0x00000000 os register3
#define GRF_OS_REG4 			0x05d8 // W 0x00000000 os register4
#define GRF_OS_REG5 			0x05dc // W 0x00000000 os register5
#define GRF_OS_REG6 			0x05e0 // W 0x00000000 os register6
#define GRF_OS_REG7 			0x05e4 // W 0x00000000 os register7
#define GRF_SIG_DETECT_CON 		0x0680 // W 0x00000000 External signal detect configue register
#define GRF_SIG_DETECT_STATUS 	0x0690 // W 0x00000000 External signal detect status register
#define GRF_SIG_DETECT_STATUS_CLEAR 0x06a0 // W 0x00000000 External signal detect status clear register
#define GRF_SDMMC_DET_COUNTER 		0x06b0 // W 0x00030100 SDMMC detect counter register
#define GRF_HOST0_CON0 				0x0700 // W 0x00000820 host0 control register0
#define GRF_HOST0_CON1 				0x0704 // W 0x000004bc host0 control register1
#define GRF_HOST0_CON2 				0x0708 // W 0x00000019 host0 control register2
#define GRF_OTG_CON0 				0x0880 // W 0x00000000 OTG control register
#define GRF_HOST0_STATUS			0x0890 // W 0x00000000 HOST0 status register
#define GRF_MAC_CON0 				0x0900 // W 0x00000000 MAC control register0
#define GRF_MAC_CON1 				0x0904 // W 0x00000000 MAC control register1
#define GRF_MAC_CON2 				0x0908 // W 0x00000000 MAC control register2
#define GRF_MACPHY_CON0 			0x0b00 // W 0x00002039 MACPHY control register0
#define GRF_MACPHY_CON1 			0x0b04 // W 0x00000000 MACPHY control register1
#define GRF_MACPHY_CON2 			0x0b08 // W 0x00000000 MACPHY control register2
#define GRF_MACPHY_CON3 			0x0b0c // W 0x00000000 MACPHY control register3
#define GRF_MACPHY_STATUS 			0x0b10 // W 0x00000000 MACPHY status register
///////////////////////////////////////////////	
#define RK3328_GTSADC_BASE				0xFF250000
#define RK3328_EFUSE_NS_BASE			0xFF260000
#define RK3328_OTP_NS_BASE				0xFF270000
#define RK3328_SARADC_BASE				0xFF280000
#define RK3328_GPU_BASE				0xFF300000
#define RK3328_H265_ENC_BASE			0xFF330000
#define RK3328_H264_ENC_BASE				0xFF340000
#define RK3328_SVPU_BASE				0xFF350000
#define RK3328_RKVDEC_BASE			0xFF360000
#define RK3328_VOP_BASE				0xFF370000
#define RK3328_VIP_BASE				0xFF380000
#define RK3328_RGA_BASE				0xFF390000
#define RK3328_IEP_BASE				0xFF3A0000
#define RK3328_HDCPMMU_BASE					0xFF3B0000
#define RK3328_HDMI_CTRL_BASE				0xFF3C0000
#define RK3328_VHDCP2_2_BASE				0xFF3E0000
#define RK3328_DDRPHY_BASE					0xFF400000
#define RK3328_ACODEC_PHY_BASE				0xFF410000
#define RK3328_VDAC_PHY_BASE				0xFF420000
#define RK3328_HDMI_PHY_BASE				0xFF430000

#define RK3328_CRU_BASE						0xFF440000
#define RK3328_CRU_GLB_SRST_FST             0x9C
#define RK3328_CRU_GLB_SRST_FST_MAGIC       0xFDB9
#define RK3328_CRU_APLL_CON0 0x0000 // W 0x00003064 APLL configuration register0
#define RK3328_CRU_APLL_CON1 0x0004 // W 0x00001041 APLL configuration register1
#define RK3328_CRU_APLL_CON2 0x0008 // W 0x00000001 APLL configuration register2
#define RK3328_CRU_APLL_CON3 0x000c // W 0x00000007 APLL configuration register3
#define RK3328_CRU_APLL_CON4 0x0010 // W 0x00007f00 APLL configuration register4
#define RK3328_CRU_DPLL_CON0 0x0020 // W 0x00001096 DPLL configuration register0
#define RK3328_CRU_DPLL_CON1 0x0024 // W 0x00001042 DPLL configuration register1
#define RK3328_CRU_DPLL_CON2 0x0028 // W 0x00000001 DPLL configuration register2
#define RK3328_CRU_DPLL_CON3 0x002c // W 0x00000007 DPLL configuration register3
#define RK3328_CRU_DPLL_CON4 0x0030 // W 0x00007f00 DPLL configuration register4
#define RK3328_CRU_CPLL_CON0 0x0040 // W 0x000020c8 CPLL configuration register0
#define RK3328_CRU_CPLL_CON1 0x0044 // W 0x00001043 CPLL configuration register1
#define RK3328_CRU_CPLL_CON2 0x0048 // W 0x00000001 CPLL configuration register2
#define RK3328_CRU_CPLL_CON3 0x004c // W 0x00000007 CPLL configuration register3
#define RK3328_CRU_CPLL_CON4 0x0050 // W 0x00007f00 CPLL configuration register4
#define RK3328_CRU_GPLL_CON0 0x0060 // W 0x00001051 GPLL configuration register0
#define RK3328_CRU_GPLL_CON1 			0x0064 // W 0x00000042 GPLL configuration register1
#define RK3328_CRU_GPLL_CON2 			0x0068 // W 0x00eb84f8 GPLL configuration register2
#define RK3328_CRU_GPLL_CON3 			0x006c // W 0x00000007 GPLL configuration register3
#define RK3328_CRU_GPLL_CON4 			0x0070 // W 0x00007f00 GPLL configuration register4
#define RK3328_CRU_CRU_MODE 			0x0080 // W 0x00000000 CRU_MODE
#define RK3328_CRU_CRU_MISC 			0x0084 // W 0x0000a000 CRU_MISC
#define RK3328_CRU_CRU_GLB_CNT_TH 		0x0090 // W 0x3a980064 CRU_GLB_CNT_TH
#define RK3328_CRU_GLB_RST_ST 			0x0094 // W 0x00000000 GLB_RST_ST
#define RK3328_CRU_GLB_SRST_SND_VALUE 	0x0098 // W 0x00000000 GLB_SRST_SND_VALUE
#define RK3328_CRU_GLB_SRST_FST_VALUE 	0x009c // W 0x00000000 GLB_SRST_FST_VALUE
#define RK3328_CRU_NPLL_CON0 			0x00a0 // W 0x00003064 NPLL configuration register0
#define RK3328_CRU_NPLL_CON1 			0x00a4 // W 0x00001041 NPLL configuration register1
#define RK3328_CRU_NPLL_CON2 			0x00a8 // W 0x00000001 NPLL configuration register2
#define RK3328_CRU_NPLL_CON3 			0x00ac // W 0x00000007 NPLL configuration register3
#define RK3328_CRU_NPLL_CON4 			0x00b0 // W 0x00007f00 NPLL configuration register4
#define RK3328_CRU_CLKSEL_CON0 			0x0100 // W 0x00000300 Internal clock select and divide register0
#define RK3328_CRU_CLKSEL_CON1 			0x0104 // W 0x00001113 Internal clock select and divide register1
#define RK3328_CRU_CLKSEL_CON2 			0x0108 // W 0x00000003 Internal clock select and divide register2
#define RK3328_CRU_CLKSEL_CON3 			0x010c // W 0x00000000 Internal clock select and divide register3
#define RK3328_CRU_CLKSEL_CON4 			0x0110 // W 0x00000780 Internal clock select and divide register4
#define RK3328_CRU_CLKSEL_CON5 			0x0114 // W 0x00008000 Internal clock select and divide register5
#define RK3328_CRU_CLKSEL_CON6 			0x0118 // W 0x0000000f Internal clock select and divide register6
#define RK3328_CRU_CLKSEL_CON7 			0x011c // W 0x0bb8ea60 Internal clock select and divide register7
#define RK3328_CRU_CLKSEL_CON8 			0x0120 // W 0x0000000f Internal clock select and divide register8
#define RK3328_CRU_CLKSEL_CON9 			0x0124 // W 0x0bb8ea60 Internal clock select and divide register9
#define RK3328_CRU_CLKSEL_CON10			0x0128 // W 0x0000000f Internal clock select and divide register10
#define RK3328_CRU_CLKSEL_CON11			0x012c // W 0x0bb8ea60 Internal clock select and divide register11
#define RK3328_CRU_CLKSEL_CON12 		0x0130 // W 0x0000000f Internal clock select and divide register12
#define RK3328_CRU_CLKSEL_CON13 		0x0134 // W 0x0bb8ea60 Internal clock select and divide register13
#define RK3328_CRU_CLKSEL_CON14 		0x0138 // W 0x00000007 Internal clock select and divide register14
#define RK3328_CRU_CLKSEL_CON15 		0x013c // W 0x0bb8ea60 Internal clock select and divide register15
#define RK3328_CRU_CLKSEL_CON16 		0x0140 // W 0x00000007 Internal clock select and divide register16
#define RK3328_CRU_CLKSEL_CON17 		0x0144 // W 0x0bb8ea60 Internal clock select and divide register17
#define RK3328_CRU_CLKSEL_CON18 		0x0148 // W 0x00000007 Internal clock select and divide register18
#define RK3328_CRU_CLKSEL_CON19 		0x014c // W 0x0bb8ea60 Internal clock select and divide register19
#define RK3328_CRU_CLKSEL_CON20 		0x0150 // W 0x00008f04 Internal clock select and divide register20
#define RK3328_CRU_CLKSEL_CON21 		0x0154 // W 0x00000400 Internal clock select and divide register21
#define RK3328_CRU_CLKSEL_CON22 		0x0158 // W 0x000001e0 Internal clock select and divide register22
#define RK3328_CRU_CLKSEL_CON23 		0x015c // W 0x000001e0 Internal clock select and divide register23
#define RK3328_CRU_CLKSEL_CON24 		0x0160 // W 0x00000707 Internal clock select and divide register24
#define RK3328_CRU_CLKSEL_CON25 		0x0164 // W 0x00000242 Internal clock select and divide register25
#define RK3328_CRU_CLKSEL_CON26 		0x0168 // W 0x0000000f Internal clock select and divide register26
#define RK3328_CRU_CLKSEL_CON27 		0x016c // W 0x00000705 Internal clock select and divide register27
#define RK3328_CRU_CLKSEL_CON28 		0x0170 // W 0x00000042 Internal clock select and divide register28
#define RK3328_CRU_CLKSEL_CON29 		0x0174 // W 0x00000022 Internal clock select and divide register29
#define RK3328_CRU_CLKSEL_CON30 		0x0178 // W 0x00000003 Internal clock select and divide register30
#define RK3328_CRU_CLKSEL_CON31 		0x017c // W 0x00000001 Internal clock select and divide register31
#define RK3328_CRU_CLKSEL_CON32 		0x0180 // W 0x00000001 Internal clock select and divide register32
#define RK3328_CRU_CLKSEL_CON33 		0x0184 // W 0x0000030b Internal clock select and divide register33
#define RK3328_CRU_CLKSEL_CON34 		0x0188 // W 0x00000707 Internal clock select and divide register34
#define RK3328_CRU_CLKSEL_CON35 		0x018c // W 0x00000707 Internal clock select and divide register35
#define RK3328_CRU_CLKSEL_CON36 		0x0190 // W 0x00004242 Internal clock select and divide register36
#define RK3328_CRU_CLKSEL_CON37 		0x0194 // W 0x00000242 Internal clock select and divide register37
#define RK3328_CRU_CLKSEL_CON38 		0x0198 // W 0x0000c2dc Internal clock select and divide register38
#define RK3328_CRU_CLKSEL_CON39 		0x019c // W 0x00000001 Internal clock select and divide register39
#define RK3328_CRU_CLKSEL_CON40 		0x01a0 // W 0x00003113 Internal clock select and divide register40
#define RK3328_CRU_CLKSEL_CON41 		0x01a4 // W 0x0bb8ea60 Internal clock select and divide register41
#define RK3328_CRU_CLKSEL_CON42 		0x01a8 // W 0x00000013 Internal clock select and divide register42
#define RK3328_CRU_CLKSEL_CON43 		0x01ac // W 0x00000003 Internal clock select and divide register43
#define RK3328_CRU_CLKSEL_CON44 		0x01b0 // W 0x00000042 Internal clock select and divide register44
#define RK3328_CRU_CLKSEL_CON45 		0x01b4 // W 0x0000001f Internal clock select and divide register45
#define RK3328_CRU_CLKSEL_CON46 		0x01b8 // W 0x00000000 Internal clock select and divide register46
#define RK3328_CRU_CLKSEL_CON47 		0x01bc // W 0x00000000 Internal clock select and divide register47
#define RK3328_CRU_CLKSEL_CON48 		0x01c0 // W 0x00004201 Internal clock select and divide register48
#define RK3328_CRU_CLKSEL_CON49 		0x01c4 // W 0x00000042 Internal clock select and divide register49
#define RK3328_CRU_CLKSEL_CON50 		0x01c8 // W 0x00000042 Internal clock select and divide register50
#define RK3328_CRU_CLKSEL_CON51 		0x01cc // W 0x00000203 Internal clock select and divide register51
#define RK3328_CRU_CLKSEL_CON52 		0x01d0 // W 0x0000021e Internal clock select and divide register52
#define RK3328_CRU_CLKGATE_CON0 		0x0200 // W 0x00000000 Internal clock gating register0
#define RK3328_CRU_CLKGATE_CON1 		0x0204 // W 0x00000000 Internal clock gating register1
#define RK3328_CRU_CLKGATE_CON2 		0x0208 // W 0x00000000 Internal clock gating register2
#define RK3328_CRU_CLKGATE_CON3 		0x020c // W 0x00000000 Internal clock gating register3
#define RK3328_CRU_CLKGATE_CON4 		0x0210 // W 0x00000000 Internal clock gating register4
#define RK3328_CRU_CLKGATE_CON5 		0x0214 // W 0x00000000 Internal clock gating register5
#define RK3328_CRU_CLKGATE_CON6 		0x0218 // W 0x00000000 Internal clock gating register6
#define RK3328_CRU_CLKGATE_CON7 		0x021c // W 0x00000000 Internal clock gating register7
#define RK3328_CRU_CLKGATE_CON8 		0x0220 // W 0x00000000 Internal clock gating register8
#define RK3328_CRU_CLKGATE_CON9 		0x0224 // W 0x00000000 Internal clock gating register9
#define RK3328_CRU_CLKGATE_CON10 		0x0228 // W 0x00000000 Internal clock gating register10
#define RK3328_CRU_CLKGATE_CON11 		0x022c // W 0x00000000 Internal clock gating register11
#define RK3328_CRU_CLKGATE_CON12 		0x0230 // W 0x00000000 Internal clock gating register12
#define RK3328_CRU_CLKGATE_CON13 		0x0234 // W 0x00000000 Internal clock gating register13
#define RK3328_CRU_CLKGATE_CON14 		0x0238 // W 0x00000000 Internal clock gating register14
#define RK3328_CRU_CLKGATE_CON15 		0x023c // W 0x00000000 Internal clock gating register15
#define RK3328_CRU_CLKGATE_CON16 		0x0240 // W 0x00000000 Internal clock gating register16
#define RK3328_CRU_CLKGATE_CON17 		0x0244 // W 0x00000000 Internal clock gating register17
#define RK3328_CRU_CLKGATE_CON18 		0x0248 // W 0x00000000 Internal clock gating register18
#define RK3328_CRU_CLKGATE_CON19 		0x024c // W 0x00000000 Internal clock gating register19
#define RK3328_CRU_CLKGATE_CON20 		0x0250 // W 0x00000000 Internal clock gating register20
#define RK3328_CRU_CLKGATE_CON21 		0x0254 // W 0x00000000 Internal clock gating register21
#define RK3328_CRU_CLKGATE_CON22 		0x0258 // W 0x00000000 Internal clock gating register22
#define RK3328_CRU_CLKGATE_CON23 		0x025c // W 0x00000000 Internal clock gating register23
#define RK3328_CRU_CLKGATE_CON24 		0x0260 // W 0x00000000 Internal clock gating register24
#define RK3328_CRU_CLKGATE_CON25 		0x0264 // W 0x00000000 Internal clock gating register25
#define RK3328_CRU_CLKGATE_CON26 		0x0268 // W 0x00000000 Internal clock gating register26
#define RK3328_CRU_CLKGATE_CON27 		0x026c // W 0x00000000 Internal clock gating register27
#define RK3328_CRU_CLKGATE_CON28 		0x0270 // W 0x00000000 Internal clock gating register28
#define RK3328_CRU_SSGTBL0_3 			0x0280 // W 0x00000000 SSMOD external wave table register0
#define RK3328_CRU_SSGTBL4_7 			0x0284 // W 0x00000000 SSMOD external wave table register1
#define RK3328_CRU_SSGTBL8_11 			0x0288 // W 0x00000000 SSMOD external wave table register2
#define RK3328_CRU_SSGTBL12_15 			0x028c // W 0x00000000 SSMOD external wave table register3
#define RK3328_CRU_SSGTBL16_19 			0x0290 // W 0x00000000 SSMOD external wave table register4
#define RK3328_CRU_SSGTBL20_23 			0x0294 // W 0x00000000 SSMOD external wave table register5
#define RK3328_CRU_SSGTBL24_27 			0x0298 // W 0x00000000 SSMOD external wave table register6
#define RK3328_CRU_SSGTBL28_31 			0x029c // W 0x00000000 SSMOD external wave table register7
#define RK3328_CRU_SSGTBL32_35 			0x02a0 // W 0x00000000 SSMOD external wave table register8
#define RK3328_CRU_SSGTBL36_39 			0x02a4 // W 0x00000000 SSMOD external wave table register9
#define RK3328_CRU_SSGTBL40_43 			0x02a8 // W 0x00000000 SSMOD external wave table register10
#define RK3328_CRU_SSGTBL44_47 			0x02ac // W 0x00000000 SSMOD external wave table register11
#define RK3328_CRU_SSGTBL48_51 			0x02b0 // W 0x00000000 SSMOD external wave table register12
#define RK3328_CRU_SSGTBL52_55 			0x02b4 // W 0x00000000 SSMOD external wave table register13
#define RK3328_CRU_SSGTBL56_59 			0x02b8 // W 0x00000000 SSMOD external wave table register14
#define RK3328_CRU_SSGTBL60_63 			0x02bc // W 0x00000000 SSMOD external wave table register15
#define RK3328_CRU_SSGTBL64_67 			0x02c0 // W 0x00000000 SSMOD external wave table register16
#define RK3328_CRU_SSGTBL68_71 			0x02c4 // W 0x00000000 SSMOD external wave table register17
#define RK3328_CRU_SSGTBL72_75 			0x02c8 // W 0x00000000 SSMOD external wave table register18
#define RK3328_CRU_SSGTBL76_79 			0x02cc // W 0x00000000 SSMOD external wave table register19
#define RK3328_CRU_SSGTBL80_83 			0x02d0 // W 0x00000000 SSMOD external wave table register20
#define RK3328_CRU_SSGTBL84_87 			0x02d4 // W 0x00000000 SSMOD external wave table register21
#define RK3328_CRU_SSGTBL88_91 			0x02d8 // W 0x00000000 SSMOD external wave table register22
#define RK3328_CRU_SSGTBL92_95 			0x02dc // W 0x00000000 SSMOD external wave table register23
#define RK3328_CRU_SSGTBL96_99 			0x02e0 // W 0x00000000 SSMOD external wave table register24
#define RK3328_CRU_SSGTBL100_103 		0x02e4 // W 0x00000000 SSMOD external wave table register25
#define RK3328_CRU_SSGTBL104_107 		0x02e8 // W 0x00000000 SSMOD external wave table register26
#define RK3328_CRU_SSGTBL108_111 		0x02ec // W 0x00000000 SSMOD external wave table register27
#define RK3328_CRU_SSGTBL112_115 		0x02f0 // W 0x00000000 SSMOD external wave table register28
#define RK3328_CRU_SSGTBL116_119 		0x02f4 // W 0x00000000 SSMOD external wave table register29
#define RK3328_CRU_SSGTBL120_123 		0x02f8 // W 0x00000000 SSMOD external wave table register30
#define RK3328_CRU_SSGTBL124_127 		0x02fc // W 0x00000000 SSMOD external wave table register31
#define RK3328_CRU_SOFTRST_CON0 		0x0300 // W 0x00000000 Internal software reset control register0
#define RK3328_CRU_SOFTRST_CON1 		0x0304 // W 0x00000000 Internal software reset control register1
#define RK3328_CRU_SOFTRST_CON2 		0x0308 // W 0x00000000 Internal software reset control register2
#define RK3328_CRU_SOFTRST_CON3 		0x030c // W 0x00000000 Internal software reset control register3
#define RK3328_CRU_SOFTRST_CON4 		0x0310 // W 0x00000000 Internal software reset control register4
#define RK3328_CRU_SOFTRST_CON5 		0x0314 // W 0x00000000 Internal software reset control register5
#define RK3328_CRU_SOFTRST_CON6 		0x0318 // W 0x00000000 Internal software reset control register6
#define RK3328_CRU_SOFTRST_CON7 		0x031c // W 0x00000000 Internal software reset control register7
#define RK3328_CRU_SOFTRST_CON8 		0x0320 // W 0x00000000 Internal software reset control register8
#define RK3328_CRU_SOFTRST_CON9 		0x0324 // W 0x00000000 Internal software reset control register9
#define RK3328_CRU_SOFTRST_CON10 		0x0328 // W 0x00000000 Internal software reset control register10
#define RK3328_CRU_SOFTRST_CON11 		0x032c // W 0x00000000 Internal software reset control register11
#define RK3328_CRU_SDMMC_CON0 		0x0380 // W 0x00000004 sdmmc control0
#define RK3328_CRU_SDMMC_CON1 		0x0384 // W 0x00000000 sdmmc control1
#define RK3328_CRU_SDIO_CON0 		0x0388 // W 0x00000004 SDIO control0
#define RK3328_CRU_SDIO_CON1 		0x038c // W 0x00000000 SDIO control1
#define RK3328_CRU_EMMC_CON0 		0x0390 // W 0x00000004 EMMC control0
#define RK3328_CRU_EMMC_CON1 		0x0394 // W 0x00000000 EMMC control1
#define RK3328_CRU_SDMMC_EXT_CON0 	0x0398 // W 0x00000004 SDMMC_EXT control0
#define RK3328_CRU_SDMMC_EXT_CON1 	0x039c // W 0x00000000 SDMMC_EXT control1




#define RK3328_USB2PHY_GRF_BASE				0xFF450000
#define RK3328_USB3PHY_GRF_BASE				0xFF460000
#define RK3328_USB3PHY_UTMI_BASE			0xFF470000
#define RK3328_USB3PHY_PIPE_BASE			0xFF480000
#define RK3328_SDMMC_BASE					0xFF500000
#define RK3328_SDIO_BASE				0xFF510000
#define RK3328_eMMC_BASE				0xFF520000
#define RK3328_NANDC_BASE			0xFF530000
#define RK3328_GMAC0_BASE			0xFF540000
#define RK3328_GMAC1_BASE					0xFF550000
#define RK3328_USB2_OTG_BASE				0xFF580000
#define RK3328_USB_HOST_EHCI_BASE			0xFF5C0000
#define RK3328_USB_HOST_OHCI_BASE			0xFF5D0000
#define RK3328_SDMMC_EXT_BASE				0xFF5F0000
#define RK3328_USB3_0_OTG_BASE				0xFF600000
#define RK3328_SERVIVE_CORE_BASE			0xFF700000
#define RK3328_SERVIVE_GPU_BASE				0xFF710000
#define RK3328_SERVIVE_MSCH_BASE			0xFF720000
#define RK3328_SERVIVE_PERI_BASE			0xFF730000
#define RK3328_SERVIVE_SYS_BASE				0xFF740000
#define RK3328_SERVIVE_VDEC_BASE			0xFF750000
#define RK3328_SERVIVE_VIO_BASE				0xFF760000
#define RK3328_SERVIVE_VENC_BASE			0xFF770000
#define RK3328_SERVIVE_VPU_BASE				0xFF780000

#define RK3328_DDR_MONITOR_BASE				0xFF790000
#define RK3328_DDR_STDBY_BASE				0xFF794000
#define RK3328_DDR_GRF_BASE					0xFF798000
#define RK3328_FIREWALL_DDR_BASE			0xFF7C0000
#define RK3328_FIREWALL_CFG_BASE			0xFF7D0000
#define RK3328_CA53_DBG					0xFF800000			
#define RK3328_GIC400_BASE			0xFF810000
#define RK3328_GIC400_CPU_BASE           (RK3328_GIC400_BASE + 0x2000)
#define RK3328_GIC400_DIST_BASE          (RK3328_GIC400_BASE + 0x1000)
#define RK3328_GIC400_SIZE			0xFFFF


#endif