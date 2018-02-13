/*
 * (C) Copyright 2016 Nexell
 * Hyunseok, Jung <hsjung@nexell.co.kr>
 *
 * SPDX-License-Identifier:      GPL-2.0+
 */

#ifndef __NXP5540_H__
#define __NXP5540_H__

#define PHYS_BASEADDR_AXISRAM				(0x10000000)
#define PHYS_BASEADDR_CHIPID				(0x20000000)
#define PHYS_BASEADDR_SYSCTRLTOP			(0x20010000)
#define PHYS_BASEADDR_TIEOFF_CCI			(0x20020000)
#define PHYS_BASEADDR_PPMU_SYS				(0x20030000)
#define PHYS_BASEADDR_HPM				(0x20040000)
#define PHYS_BASEADDR_Q_ENHANCER			(0x20050000)
#define PHYS_BASEADDR_TIEOFF_SYS			(0x20060000)
#define PHYS_BASEADDR_CORESIGHT				(0x20070000)
#define PHYS_BASEADDR_CCI4000				(0x20090000)
#define PHYS_BASEADDR_CPU_REGBASE			(0x200C0000)
#define PHYS_BASEADDR_CMU_SYS				(0x20100000)
#define PHYS_BASEADDR_CMU_TBUS				(0x20110000)
#define PHYS_BASEADDR_CMU_LBUS				(0x20120000)
#define PHYS_BASEADDR_CMU_BBUS				(0x20130000)
#define PHYS_BASEADDR_CMU_ISP				(0x20200000)
#define PHYS_BASEADDR_CMU_CODA				(0x20210000)
#define PHYS_BASEADDR_CMU_DISP				(0x20220000)
#define PHYS_BASEADDR_CMU_USB				(0x20230000)
#define PHYS_BASEADDR_CMU_HDMI				(0x20240000)
#define PHYS_BASEADDR_CMU_GPU				(0x20250000)
#define PHYS_BASEADDR_CMU_WAVE				(0x20260000)
#define PHYS_BASEADDR_CMU_DREX0				(0x20270000)
#define PHYS_BASEADDR_CMU_WAVE420			(0x20290000)
#define PHYS_BASEADDR_TIEOFF_CPU0			(0x202C0000)
#define PHYS_BASEADDR_CMU_CPU0				(0x202D0000)
#define PHYS_BASEADDR_CMU_PERICLK			(0x202E0000)
#define PHYS_BASEADDR_TZPC				(0x20300000)
#define PHYS_BASEADDR_ECID				(0x20310000)
#define PHYS_BASEADDR_ECID_SECU				(0x20320000)
#define PHYS_BASEADDR_GIC4000				(0x203F0000)
#define PHYS_BASEADDR_TIEOFF_DREX0			(0x20400000)
#define PHYS_BASEADDR_DDRPHY0				(0x20410000)
#define PHYS_BASEADDR_DREXTZASC0			(0x20420000)
#define PHYS_BASEADDR_DREX0_CFG				(0x20430000)
#define PHYS_BASEADDR_TIEOFF_CODA			(0x20500000)
#define PHYS_BASEADDR_CODA9800				(0x20510000)
#define PHYS_BASEADDR_JPEG				(0x20520000)
#define PHYS_BASEADDR_AXIM_CODA0			(0x20530000)
#define PHYS_BASEADDR_AXIM_CODA1			(0x20540000)
#define PHYS_BASEADDR_AXIM_JPEG				(0x20550000)
#define PHYS_BASEADDR_CRYPTO				(0x20600000)
#define PHYS_BASEADDR_PPM				(0x20610000)
#define PHYS_BASEADDR_TIMER				(0x20620000)
#define PHYS_BASEADDR_TIMER_SECU			(0x20630000)
#define PHYS_BASEADDR_PWM0				(0x20640000)
#define PHYS_BASEADDR_PWM1				(0x20650000)
#define PHYS_BASEADDR_PWM2				(0x20660000)
#define PHYS_BASEADDR_PWM3				(0x20670000)
#define PHYS_BASEADDR_WDT				(0x20680000)
#define PHYS_BASEADDR_WDT_SECU				(0x20690000)
#define PHYS_BASEADDR_PDM0				(0x206A0000)
#define PHYS_BASEADDR_PDM1				(0x206B0000)
#define PHYS_BASEADDR_PDM2				(0x206C0000)
#define PHYS_BASEADDR_PDM3				(0x206D0000)
#define PHYS_BASEADDR_MCUSTOP				(0x206E0000)
#define PHYS_BASEADDR_AUDIO_IO_CTRL			(0x206F0000)
#define PHYS_BASEADDR_PKA				(0x20700000)
#define PHYS_BASEADDR_DMAC0				(0x20780000)
#define PHYS_BASEADDR_DMAC1				(0x20790000)
#define PHYS_BASEADDR_SEC_DMA0				(0x207A0000)
#define PHYS_BASEADDR_SEC_DMA1				(0x207B0000)
#define PHYS_BASEADDR_MDMAC0				(0x207C0000)
#define PHYS_BASEADDR_MCU_MAILBOX			(0x20800000)
#define PHYS_BASEADDR_MCU_SRAM				(0x20810000)
#define PHYS_BASEADDR_AC970				(0x20820000)
#define PHYS_BASEADDR_I2S0				(0x20830000)
#define PHYS_BASEADDR_I2S1				(0x20840000)
#define PHYS_BASEADDR_I2S2				(0x20850000)
#define PHYS_BASEADDR_I2S3				(0x20860000)
#define PHYS_BASEADDR_I2C0				(0x20870000)
#define PHYS_BASEADDR_I2C1				(0x20880000)
#define PHYS_BASEADDR_ISP				(0x20900000)
#define PHYS_BASEADDR_SEC_ISP				(0x20910000)
#define PHYS_BASEADDR_ISPCORE				(0x20920000)
#define PHYS_BASEADDR_GPU				(0x20A00000)
#define PHYS_BASEADDR_AXIM_GPU				(0x20A10000)
#define PHYS_BASEADDR_TIEOFF_GPU			(0x20A20000)
#define PHYS_BASEADDR_ISS0				(0x20C00000)
#define PHYS_BASEADDR_SECURE_ISS0			(0x20C10000)
#define PHYS_BASEADDR_VIP_MCD0				(0x20C20000)
#define PHYS_BASEADDR_SECURE_VIP_MCD0			(0x20C30000)
#define PHYS_BASEADDR_VIP_VIP				(0x20C40000)
#define PHYS_BASEADDR_VIP_PRES				(0x20C50000)
#define PHYS_BASEADDR_SECURE_VIP_VIP			(0x20C60000)
#define PHYS_BASEADDR_SECURE_VIP_PRES			(0x20C70000)
#define PHYS_BASEADDR_DPC0				(0x20C80000)
#define PHYS_BASEADDR_DPC_0_I80MPU			(0x20C90000)
#define PHYS_BASEADDR_DPC1				(0x20CA0000)
#define PHYS_BASEADDR_DPC_1_NTSC			(0x20CB0000)
#define PHYS_BASEADDR_LVDS				(0x20CC0000)
#define PHYS_BASEADDR_MAPCONV0				(0x20CD0000)
#define PHYS_BASEADDR_LVDS1				(0x20CE0000)
#define PHYS_BASEADDR_AXIM_DMARW0			(0x20D00000)
#define PHYS_BASEADDR_AXIM_DMARW1			(0x20D04000)
#define PHYS_BASEADDR_AXIM_DMARW2			(0x20D08000)
#define PHYS_BASEADDR_AXIM_DMARW3			(0x20D0C000)
#define PHYS_BASEADDR_AXIM_DMARW4			(0x20D10000)
#define PHYS_BASEADDR_AXIM_DMARW5			(0x20D14000)
#define PHYS_BASEADDR_AXIM_DMARW6			(0x20D18000)
#define PHYS_BASEADDR_AXIM_DMARW7			(0x20D1C000)
#define PHYS_BASEADDR_AXIM_DMARW8			(0x20D20000)
#define PHYS_BASEADDR_AXIM_DMARW9			(0x20D24000)
#define PHYS_BASEADDR_AXIM_DMARW10			(0x20D28000)
#define PHYS_BASEADDR_AXIM_DMARW11			(0x20D2C000)
#define PHYS_BASEADDR_AXIM_DEINTERLACE0			(0x20D40000)
#define PHYS_BASEADDR_AXIM_MAPCONV0			(0x20D44000)
#define PHYS_BASEADDR_AXIM_CSI_TO_AXI0			(0x20D4C000)
#define PHYS_BASEADDR_DISP_TIEOFF			(0x20E00000)
#define PHYS_BASEADDR_DEINTERLACE			(0x20E10000)
#define PHYS_BASEADDR_MIPI_CSIS				(0x20E20000)
#define PHYS_BASEADDR_DISP_TZPC0			(0x20E30000)
#define PHYS_BASEADDR_DISP_TZPC1			(0x20E40000)
#define PHYS_BASEADDR_MIPI_DSIM				(0x20E50000)
#define PHYS_BASEADDR_DISP_BUS_CON			(0x20E80000)
#define PHYS_BASEADDR_NXS_TO_MIPIDSI			(0x20E90000)
#define PHYS_BASEADDR_NXS_TO_HDMI			(0x20EC0000)
#define PHYS_BASEADDR_HDMI_PHY				(0x20ED0000)
#define PHYS_BASEADDR_HDMI_LINK				(0x20F00000)
#define PHYS_BASEADDR_TIEOFF_LBUS			(0x21000000)
#define PHYS_BASEADDR_TMU_LBUS				(0x21010000)
#define PHYS_BASEADDR_MPEGTSI				(0x21040000)
#define PHYS_BASEADDR_GPIO0				(0x21050000)
#define PHYS_BASEADDR_GPIOA				(0x21050000)
#define PHYS_BASEADDR_GPIOB				(0x21051000)
#define PHYS_BASEADDR_GPIOC				(0x21052000)
#define PHYS_BASEADDR_GPIOD				(0x21053000)
#define PHYS_BASEADDR_GPIOE				(0x21054000)
#define PHYS_BASEADDR_GPIOF				(0x21055000)
#define PHYS_BASEADDR_GPIOG				(0x21056000)
#define PHYS_BASEADDR_GPIOH				(0x21057000)
#define PHYS_BASEADDR_GPIO1				(0x21060000)
#define PHYS_BASEADDR_SEC_GPIOA				(0x21060000)
#define PHYS_BASEADDR_SEC_GPIOB				(0x21061000)
#define PHYS_BASEADDR_SEC_GPIOC				(0x21062000)
#define PHYS_BASEADDR_SEC_GPIOD				(0x21063000)
#define PHYS_BASEADDR_SEC_GPIOE				(0x21064000)
#define PHYS_BASEADDR_SEC_GPIOF				(0x21065000)
#define PHYS_BASEADDR_SEC_GPIOG				(0x21066000)
#define PHYS_BASEADDR_SEC_GPIOH				(0x21067000)
#define PHYS_BASEADDR_GMAC				(0x21070000)
#define PHYS_BASEADDR_I2C2				(0x210B0000)
#define PHYS_BASEADDR_I2C3				(0x210C0000)
#define PHYS_BASEADDR_I2C4				(0x210D0000)
#define PHYS_BASEADDR_SDMMC0				(0x21100000)
#define PHYS_BASEADDR_SDMMC1				(0x21110000)
#define PHYS_BASEADDR_SDMMC2				(0x21120000)
#define PHYS_BASEADDR_TIEOFF_OTG			(0x21200000)
#define PHYS_BASEADDR_TIEOFF_HOST			(0x21210000)
#define PHYS_BASEADDR_TIEOFF_USB300			(0x21220000)
#define PHYS_BASEADDR_AXIM_USB200			(0x21230000)
#define PHYS_BASEADDR_AXIM_USB300			(0x21240000)
#define PHYS_BASEADDR_USB_OTG_LINK_A			(0x21280000)
#define PHYS_BASEADDR_USB_OTG_LINK_B			(0x21290000)
#define PHYS_BASEADDR_USB_HOST_EHCI_LINK		(0x212A0000)
#define PHYS_BASEADDR_USB_HOST_OHCI_LINK		(0x212B0000)
#define PHYS_BASEADDR_USB300				(0x21300000)
#define PHYS_BASEADDR_AXIM_CONNECTOR0			(0x21600000)
#define PHYS_BASEADDR_AXIM_CONNECTOR1			(0x21610000)
#define PHYS_BASEADDR_AXIM_CONNECTOR2			(0x21620000)
#define PHYS_BASEADDR_AXIM_CONNECTOR3			(0x21630000)
#define PHYS_BASEADDR_AXIM_CONNECTOR4			(0x21640000)
#define PHYS_BASEADDR_AXIM_CONNECTOR5			(0x21650000)
#define PHYS_BASEADDR_AXIM_CONNECTOR6			(0x21660000)
#define PHYS_BASEADDR_AXIM_CONNECTOR7			(0x21670000)
#define PHYS_BASEADDR_AXIM_CONNECTOR8			(0x21680000)
#define PHYS_BASEADDR_AXIM_CONNECTOR9			(0x21690000)
#define PHYS_BASEADDR_TIEOFF_BBUS			(0x21800000)
#define PHYS_BASEADDR_TMU_BBUS				(0x21810000)
#define PHYS_BASEADDR_ADC				(0x21840000)
#define PHYS_BASEADDR_UART0				(0x21880000)
#define PHYS_BASEADDR_UART1				(0x21890000)
#define PHYS_BASEADDR_UART2				(0x218A0000)
#define PHYS_BASEADDR_UART3				(0x218B0000)
#define PHYS_BASEADDR_UART4				(0x218C0000)
#define PHYS_BASEADDR_UART5				(0x218D0000)
#define PHYS_BASEADDR_SPI0				(0x21900000)
#define PHYS_BASEADDR_SPI1				(0x21910000)
#define PHYS_BASEADDR_SPI2				(0x21920000)
#define PHYS_BASEADDR_SPDIFTX				(0x21930000)
#define PHYS_BASEADDR_SPDIFRX				(0x21940000)
#define PHYS_BASEADDR_UART6				(0x21950000)
#define PHYS_BASEADDR_UART7				(0x21960000)
#define PHYS_BASEADDR_UART8				(0x21970000)
#define PHYS_BASEADDR_TIEOFF_WAVE			(0x21A00000)
#define PHYS_BASEADDR_WAVE4120				(0x21A10000)
#define PHYS_BASEADDR_AXIM_WAVE0			(0x21A20000)
#define PHYS_BASEADDR_AXIM_WAVE1			(0x21A30000)
#define PHYS_BASEADDR_TIEOFF_WAVE4200			(0x21B00000)
#define PHYS_BASEADDR_WAVE4200				(0x21B10000)
#define PHYS_BASEADDR_AXIM_WAVE4200			(0x21B20000)
#define PHYS_BASEADDR_AXIM_WAVE4201			(0x21B30000)
#define PHYS_BASEADDR_SONICS_BUS			(0x21F00000)

#endif /* __NXP5540_H__ */
