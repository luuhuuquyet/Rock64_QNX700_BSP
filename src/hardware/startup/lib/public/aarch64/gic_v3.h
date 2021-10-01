/*
 * $QNXLicenseC:
 * Copyright 2016, QNX Software Systems.
 * Copyright 2016, Freescale Semiconductor, Inc.
 * Copyright 2017 NXP
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
 * ARM Generic Interrupt Controller
 */

#ifndef GIC_V3_H_
#define GIC_V3_H_

/*
 * -----------------------------------------------------------------------
 * Interrupt Distributor registers
 * -----------------------------------------------------------------------
 */

#define ARM_GICD_SIZE                   0x1000

#define ARM_GICD_CTLR                   0x0000
#define ARM_GICD_CTLR_ARE_NS            0x00000020
#define ARM_GICD_CTLR_ARE_S             0x00000010
#define ARM_GICD_CTLR_EN_GRP1_S         0x00000004
#define ARM_GICD_CTLR_EN_GRP1_NS        0x00000002
#define ARM_GICD_CTLR_EN_GRP0           0x00000001
#define ARM_GICD_TYPER                  0x0004
#define ARM_GICD_TYPER_ITLN             0x1F
#define ARM_GICD_IIDR                   0x0008
#define ARM_GICD_IGROUPRn               0x0080
#define ARM_GICD_ISENABLERn             0x0100
#define ARM_GICD_ICENABLERn             0x0180
#define ARM_GICD_ISPENDRn               0x0200
#define ARM_GICD_ICPENDRn               0x0280
#define ARM_GICD_ISACTIVERn             0x0300
#define ARM_GICD_ICACTIVERn             0x0380
#define ARM_GICD_IPRIORITYn             0x0400
#define ARM_GICD_ITARGETSRn             0x0800
#define ARM_GICD_ICFGRn                 0x0C00
#define ARM_GICD_IGRPMODRn              0x0D00
#define ARM_GICD_SGIR                   0x0F00
#define ARM_GICD_CPENDSGIR              0x0F10
#define ARM_GICD_SPENDSGIR              0x0F20
#define ARM_GICD_IROUTERn               0x6100

/*
 * -----------------------------------------------------------------------
 * Redistributor registers
 * -----------------------------------------------------------------------
 */
#define ARM_GICR_SIZE                   0x2000

#define ARM_GICR_SIZE_PER_CORE          (2 << 16)
#define ARM_GICR_SGI_BASE_OFFSET        (1 << 16)

#define ARM_GICR_CTLR                   0x0000
#define ARM_GICR_IIDR                   0x0004
#define ARM_GICR_TYPER                  0x0008
#define ARM_GICR_STATUSR                0x0010
#define ARM_GICR_WAKER                  0x0014
#define ARM_GICR_SETLPIR                0x0040
#define ARM_GICR_CLRLPIR                0x0048
#define ARM_GICR_PROPBASER              0x0070
#define ARM_GICR_PENDBASER              0x0078
#define ARM_GICR_INVLPIR                0x00A0
#define ARM_GICR_INVALLR                0x00B0
#define ARM_GICR_SYNCR                  0x00C0

/* GIC SGI and PPI redistributor register map */
#define ARM_GICR_IGROUPR0               0x0080
#define ARM_GICR_ISENABLER0             0x0100
#define ARM_GICR_ICENABLER0             0x0180
#define ARM_GICR_ISPENDR0               0x0200
#define ARM_GICR_ICPENDR0               0x0280
#define ARM_GICR_ISACTIVER0             0x0300
#define ARM_GICR_ICACTIVER0             0x0380
#define ARM_GICR_IPRIORITYRn            0x0400
#define ARM_GICR_IPRIORITYR0            0x0400
#define ARM_GICR_IPRIORITYR1            0x0404
#define ARM_GICR_IPRIORITYR2            0x0408
#define ARM_GICR_IPRIORITYR3            0x040C
#define ARM_GICR_IPRIORITYR4            0x0410
#define ARM_GICR_IPRIORITYR5            0x0414
#define ARM_GICR_IPRIORITYR6            0x0418
#define ARM_GICR_IPRIORITYR7            0x041C
#define ARM_GICR_ICFGR0                 0x0C00
#define ARM_GICR_ICFGR1                 0x0C04
#define ARM_GICR_IGRPMODR0              0x0D00
#define ARM_GICR_NSACR                  0x0E00

/*
 * -----------------------------------------------------------------------
 * CPU interface registers
 * -----------------------------------------------------------------------
 */

#define ARM_GICC_SIZE                   0x2000

#define ARM_GICC_CTLR                   0x00
#define ARM_GICC_PMR                    0x04
#define ARM_GICC_BPR                    0x08
#define ARM_GICC_IAR                    0x0C
#define ARM_GICC_EOIR                   0x10
#define ARM_GICC_RPR                    0x14
#define ARM_GICC_HPPIR                  0x18
#define ARM_GICC_ABPR                   0x1C
#define ARM_GICC_AIAR                   0x20
#define ARM_GICC_AEOIR                  0x24
#define ARM_GICC_AHPPIR                 0x28
#define ARM_GICC_STATUSR                0x2C
#define ARM_GICC_APR0                   0xD0
#define ARM_GICC_NSAPR0                 0xE0
#define ARM_GICC_IIDR                   0xFC
#define ARM_GICC_DIR                    0x1000

/* System registers */
#define ARM_GICC_IAR0_EL1               S3_0_C12_C8_0
#define ARM_GICC_IAR1_EL1               S3_0_C12_C12_0
#define ARM_GICC_EOIR0_EL1              S3_0_C12_C8_1
#define ARM_GICC_EOIR1_EL1              S3_0_C12_C12_1
#define ARM_GICC_HPPIR0_EL1             S3_0_C12_C8_2
#define ARM_GICC_HPPIR1_EL1             S3_0_C12_C12_2
#define ARM_GICC_BPR0_EL1               S3_0_C12_C8_3
#define ARM_GICC_BPR1_EL1               S3_0_C12_C12_3
#define ARM_GICC_DIR_EL1                S3_0_C12_C11_1
#define ARM_GICC_PMR_EL1                S3_0_C4_C6_0
#define ARM_GICC_RPR_EL1                S3_0_C12_C11_3
#define ARM_GICC_CTLR_EL1               S3_0_C12_C12_4
#define ARM_GICC_CTLR_EL3               S3_6_C12_C12_4
#define ARM_GICC_SRE_EL1                S3_0_C12_C12_5
#define ARM_GICC_SRE_EL2                S3_4_C12_C9_5
#define ARM_GICC_SRE_EL3                S3_6_C12_C12_5
#define ARM_GICC_IGRPEN0_EL1            S3_0_C12_C12_6
#define ARM_GICC_IGRPEN1_EL1            S3_0_C12_C12_7
#define ARM_GICC_IGRPEN1_EL3            S3_6_C12_C12_7
#define ARM_GICC_SEIEN_EL1              S3_0_C12_C13_0
#define ARM_GICC_SGI0R_EL1              S3_0_C12_C11_7
#define ARM_GICC_SGI1R_EL1              S3_0_C12_C11_5
#define ARM_GICC_ASGI1R_EL1             S3_0_C12_C11_6

/*
 * CPU_CTRL bits
 */
#define ARM_GICC_CTLR_EN                0x00000001

/*
 * CPU_IACK bits
 */
#define ARM_GICC_IAR_SRCID              0x00001C00

#endif    /* GIC_V3_H_ */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/mainline/hardware/startup/lib/public/aarch64/gic_v3.h $ $Rev: 837667 $")
#endif
