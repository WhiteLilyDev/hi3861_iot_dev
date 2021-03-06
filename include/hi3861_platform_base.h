/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Hi3861 platform definication.
 * Author: hisilicon
 * Create: 2019-03-04
 */
#ifndef __HI3861_PLATFORM_ROM_H
#define __HI3861_PLATFORM_ROM_H

#include <hi_types_base.h>
#include <hi3861.h>
#include "los_hal.h"


HI_EXTERN hi_u32 g_cfg_apb_clock;
HI_EXTERN hi_u32 g_cfg_arm_clock;
HI_EXTERN hi_u32 g_cfg_uart_clock;

#define HI_XTAL_CLOCK_BASE   24
#define HI_XTAL_CLOCK        (HI_XTAL_CLOCK_BASE * 1000000)
#define HI_XTAL_CYCLE_PER_MS (HI_XTAL_CLOCK_BASE * 1000)
#define CLK32K_DELAY_US      63 /* 要求等待1 / 32K秒，此处预留约2 / 32K秒 */

#ifdef HI_BOARD_FPGA
/* #error */
#define CONFIG_CPU_CLOCK     53000000
#define CONFIG_UART_CLOCK    160000000
#else
#define CONFIG_CPU_CLOCK     160000000
#define CONFIG_UART_CLOCK    80000000
#endif
#define CONFIG_WDT_CLOCK     80000000

#define HI_FLASH_BASE        0x00400000
#define HI_FLASH_SIZE        0x01000000
#define HI_SFC_REG_BASE      0x40800000

#define HI_SYSCTRL_REG_BASE  0x40030000
#define HI_WDG_REG_BASE      0x40000000
#define HI_TIMER_REG_BASE    0x40032000
#define HI_GPIO_REG_BASE     0x50006000
#define HI_IOCFG_REG_BASE    0x5000A000
#define HI_BUCK_REG_BASE     0x40034000
#define HI_SSP0_REG_BASE     0x40058000
#define HI_I2C0_REG_BASE     0x40018000
#define HI_I2C1_REG_BASE     0x40019000
#define HI_SPACC_REG_BASE    0x40038000
#define HI_RSA_REG_BASE      0x40038c00
#define HI_EFUSE_REG_BASE    0x40078000
#define HI_RNG_REG_BASE      0x40038f00
#define HI_LED_REG_BASE      0x40039000
#define HI_TIMECNT_REG_BASE  0x4003A000
#define HI_CRG_REG_BASE      0x4003B000
#define HI_UART0_REG_BASE    0x40008000
#define HI_UART1_REG_BASE    0x40009000
#define HI_UART2_REG_BASE    0x4000a000

#define HI_TSENSOR_REG_BASE  0x4003D100
#define HI_PWM_REG_BASE      0x40040000
#define HI_OSC_REG_BASE      0x4003D300
#define HI_TIMECNT1_REG_BASE 0x4003D500
#define HI_SSP1_REG_BASE     0x40059000
#define HI_HPM_REG_BASE      0x4003F000
#define HI_AFE_REG_BASE      0x40040000
#define HI_MMU_REG_BASE      0x40041000

#define W_CTL_BASE_ADDR              0x40028000
#define W_CTL_MAC_WDT_RST_SEL_REG    (W_CTL_BASE_ADDR + 0x34)
#define W_CTL_PHY_WDT_RST_SEL_REG    (W_CTL_BASE_ADDR + 0x38)
#define W_CTL_WDT_RST_SEL_REG        (W_CTL_BASE_ADDR + 0x3C)
#define W_CTL_UART_MAC80M_CLKEN_REG  (W_CTL_BASE_ADDR + 0x40)
#define W_CTL_WLPHY_CLKEN_CLKEN_REG  (W_CTL_BASE_ADDR + 0x4C)
#define W_CTL_CPU_MAC_CLK_DIV_REG    (W_CTL_BASE_ADDR + 0x70)
#define W_CTL_UART01_CKDIV_OFFSET    (W_CTL_BASE_ADDR + 0x74)
#define W_CTL_WLPHY_CLK_DIV_0_REG    (W_CTL_BASE_ADDR + 0x78)
#define W_CTL_WLPHY_CLK_DIV_1_REG    (W_CTL_BASE_ADDR + 0x7C)
#define W_CTL_WLPHY_CLK_DIV_2_REG    (W_CTL_BASE_ADDR + 0x80)
#define W_CTL_TSENSOR_DIV_REG        (W_CTL_BASE_ADDR + 0x88)
#define W_CTL_UART2_CKDIV_OFFSET     (W_CTL_BASE_ADDR + 0x90)
#define W_CTL_W_TCXO_SEL_REG         (W_CTL_BASE_ADDR + 0x0118)
#define W_CTL_CLKMUX_STS_DIV_STS_REG (W_CTL_BASE_ADDR + 0x0130)
#define W_CTL_TSENSOR_CTRL_REG       (W_CTL_BASE_ADDR + 0x0504)


#define GLB_CTL_RB_BASE_ADDR   0x50000000
#define CLDO_CTL_RB_BASE_ADDR  0x40010000
#define CLDO_CTL_GEN_REG0           (CLDO_CTL_RB_BASE_ADDR + 0x10) /* used for romboot */
#define CLDO_CTL_GEN_REG1           (CLDO_CTL_RB_BASE_ADDR + 0x14) /* used for romboot */
#define CLDO_CTL_GEN_REG2           (CLDO_CTL_RB_BASE_ADDR + 0x18) /* used for romboot */
#define CLDO_CTL_GEN_REG3           (CLDO_CTL_RB_BASE_ADDR + 0x1C) /* used for romboot */
#define CLDO_CTL_SOFT_RESET_REG     (CLDO_CTL_RB_BASE_ADDR + 0x20)
#define CLDO_CTL_WDG_RST_SEL_REG    (CLDO_CTL_RB_BASE_ADDR + 0x28)
#define CLDO_CTL_CLKEN_REG          (CLDO_CTL_RB_BASE_ADDR + 0x30)
#define CLDO_CTL_CLKEN1_REG         (CLDO_CTL_RB_BASE_ADDR + 0x34)
#define CLDO_CTL_CLK_SEL_REG        (CLDO_CTL_RB_BASE_ADDR + 0x38)
#define CLDO_CTL_CLKEN2_REG         (CLDO_CTL_RB_BASE_ADDR + 0x48)
#define CLDO_CTL_WDG_RST_SEL1_REG   (CLDO_CTL_RB_BASE_ADDR + 0x4C)
#define CLDO_CTL_CLKMUX_STS_REG     (CLDO_CTL_RB_BASE_ADDR + 0x64)
#define CLDO_CTL_CLK_DIV1_REG       (CLDO_CTL_RB_BASE_ADDR + 0x78)
#define CLDO_CTL_PKT_CPU_MEM_SEL    (CLDO_CTL_RB_BASE_ADDR + 0x100)

/*************************Timer**********************/
#define HI_TIMER_CLOCK_BASE 24 /* 24Mhz，timer时钟频率 */
#define TIMER_BASE_ADDR     0x40050000
#define TIMER_0_BASE_ADDR   (TIMER_BASE_ADDR + 0x00)
#define TIMER_1_BASE_ADDR   (TIMER_BASE_ADDR + 0x14)
#define TIMER_2_BASE_ADDR   (TIMER_BASE_ADDR + 0x28)
#define TIMER_3_BASE_ADDR   (TIMER_BASE_ADDR + 0x3C)

#define TIMER_LOAD_COUNT    0x00
#define TIMER_LOAD_COUNT_L  0x00
#define TIMER_LOAD_COUNT_H  0x02
#define TIMER_CURRENT_VALUE 0x04
#define TIMER_CONTROL_REG   0x08
#define TIMER_EOI           0x0C
#define TIMER_INT_STATUS    0x10

#define TIMER_CTL_CFG_DISABLE 0x0
#define TIMER_CTL_CFG_FREERUN 0x01
#define TIMER_CTL_CFG_USERDEF 0x03
/*************************RTC**********************/
#define HI_RTC_CLOCK_BASE   32  /* 32kHZ */
#define RTC_TIMER_BASE_ADDR                     0x50007000
#define RTC_TIMER_0_BASE_ADDR                   (RTC_TIMER_BASE_ADDR + 0x00)
#define RTC_TIMER_1_BASE_ADDR                   (RTC_TIMER_BASE_ADDR + 0x14)
#define RTC_TIMER_2_BASE_ADDR                   (RTC_TIMER_BASE_ADDR + 0x28)
#define RTC_TIMER_3_BASE_ADDR                   (RTC_TIMER_BASE_ADDR + 0x3C)
/*****************************************************/
#define CACHE_ALIGNED_SIZE    32


#define GLB_CTL_BASE                       0x50000000
#define GLB_CTL_SYS_CTL_ID_REG             (GLB_CTL_BASE + 0x0)
#define GLB_CTL_GP_REG0_REG                (GLB_CTL_BASE + 0x10)
#define GLB_CTL_GP_REG1_REG                (GLB_CTL_BASE + 0x14)
#define GLB_CTL_GP_REG2_REG                (GLB_CTL_BASE + 0x18)
#define GLB_CTL_GP_REG3_REG                (GLB_CTL_BASE + 0x1C)
#define GLB_CTL_AON_SOFT_RST_W_REG         (GLB_CTL_BASE + 0x20)
#define GLB_CTL_SOFT_RST_WCPU_REG          (GLB_CTL_BASE + 0x24)
#define GLB_CTL_USB_RST_REG                (GLB_CTL_BASE + 0x28)
#define GLB_CTL_GLB_WDT_RST_SEL_REG        (GLB_CTL_BASE + 0x30)
#define GLB_CTL_WDT_RST_SEL_REG            (GLB_CTL_BASE + 0x34)
#define GLB_CTL_AON_CKEN_REG               (GLB_CTL_BASE + 0x40)
#define GLB_CTL_GLB_AON_32K_CLKEN_REG      (GLB_CTL_BASE + 0x50)
#define GLB_CTL_USB_RST_STS_REG            (GLB_CTL_BASE + 0x60)
#define GLB_CTL_A32K_DIV_REG               (GLB_CTL_BASE + 0x70)
#define GLB_CTL_TCXO_DIV_REG               (GLB_CTL_BASE + 0x74) /* 24M/40M div reg */
#define GLB_CTL_AON_PERP_CLKSEL_W_REG      (GLB_CTL_BASE + 0x90)
#define GLB_CTL_RC_32K_TCXO_SEL_REG        (GLB_CTL_BASE + 0x94)
#define GLB_CTL_AON_32K_SEL_REG            (GLB_CTL_BASE + 0x98)
#define GLB_CTL_USB_BUS_CLK_SEL_REG        (GLB_CTL_BASE + 0x9C)
#define GLB_CTL_SYS_TICK_CFG_REG           (GLB_CTL_BASE + 0xC0) /* systick */
#define GLB_CTL_SYS_TICK_VALUE_0_REG       (GLB_CTL_BASE + 0xD0)
#define GLB_CTL_SYS_TICK_VALUE_1_REG       (GLB_CTL_BASE + 0xD4)
#define GLB_CTL_SYS_TICK_VALUE_2_REG       (GLB_CTL_BASE + 0xD8)
#define GLB_CTL_SYS_TICK_VALUE_3_REG       (GLB_CTL_BASE + 0xDC)
#define GLB_CTL_CLKMUX_STS_REG             (GLB_CTL_BASE + 0x110)
#define GLB_CTL_DEBUG_CLKEN_REG            (GLB_CTL_BASE + 0x170)
#define GLB_CTL_SOFT_INT_EN_REG            (GLB_CTL_BASE + 0x280)
#define GLB_CTL_SOFT_INT_SET_REG           (GLB_CTL_BASE + 0x284)
#define GLB_CTL_SOFT_INT_CLR_REG           (GLB_CTL_BASE + 0x288)
#define GLB_CTL_SOFT_INT_STS_REG           (GLB_CTL_BASE + 0x28C)
#define GLB_CTL_INT_SEL_REG                (GLB_CTL_BASE + 0x290)
#define GLB_CTL_PAD_IO_SDIO_SR_CFG_REG     (GLB_CTL_BASE + 0x2FC)
#define GLB_CTL_PAD_SDIO_CFG0_REG          (GLB_CTL_BASE + 0x300)
#define GLB_CTL_PAD_SDIO_CFG1_REG          (GLB_CTL_BASE + 0x304)
#define GLB_CTL_PAD_IO_SYSLDO_CFG0_REG     (GLB_CTL_BASE + 0x310)
#define GLB_CTL_PAD_IO_SYSLDO_CFG1_REG     (GLB_CTL_BASE + 0x314)
#define GLB_CTL_PAD_IO_SYSLDO_CFG2_REG     (GLB_CTL_BASE + 0x31C)
#define GLB_CTL_PAD_MAN_CFG_0_REG          (GLB_CTL_BASE + 0x320)
#define GLB_CTL_PAD_MAN_CFG_1_REG          (GLB_CTL_BASE + 0x324)
#define GLB_CTL_PAD_OEN_CFG_0_REG          (GLB_CTL_BASE + 0x328)
#define GLB_CTL_PAD_OEN_CFG_1_REG          (GLB_CTL_BASE + 0x32C)
#define GLB_CTL_PAD_VALUE_CFG_0_REG        (GLB_CTL_BASE + 0x330)
#define GLB_CTL_PAD_VALUE_CFG_1_REG        (GLB_CTL_BASE + 0x334)
#define GLB_CTL_PAD_VALUE_0_REG            (GLB_CTL_BASE + 0x338)
#define GLB_CTL_PAD_VALUE_1_REG            (GLB_CTL_BASE + 0x33C)
#define GLB_CTL_PAD_PINMUX_CFG0_REG        (GLB_CTL_BASE + 0x350)
#define GLB_CTL_PAD_PINMUX_CFG1_REG        (GLB_CTL_BASE + 0x354)
#define GLB_CTL_REFCLK_FEQ_STATUS_REG      (GLB_CTL_BASE + 0x358)
#define GLB_CTL_EXT_TSF_CLK_PERIOD_H_REG   (GLB_CTL_BASE + 0x414)
#define GLB_CTL_EXT_TSF_CLK_PERIOD_L_REG   (GLB_CTL_BASE + 0x418)
#define GLB_CTL_EFUSE_WR_DATA0_REG         (GLB_CTL_BASE + 0x700)
#define GLB_CTL_EFUSE_WR_DATA1_REG         (GLB_CTL_BASE + 0x704)
#define GLB_CTL_EFUSE_WR_DATA2_REG         (GLB_CTL_BASE + 0x708)
#define GLB_CTL_EFUSE_WR_DATA3_REG         (GLB_CTL_BASE + 0x70C)
#define GLB_CTL_EFUSE_WR_DATA4_REG         (GLB_CTL_BASE + 0x710)
#define GLB_CTL_EFUSE_WR_DATA5_REG         (GLB_CTL_BASE + 0x714)
#define GLB_CTL_EFUSE_WR_DATA6_REG         (GLB_CTL_BASE + 0x718)
#define GLB_CTL_EFUSE_WR_DATA7_REG         (GLB_CTL_BASE + 0x71C)
#define GLB_CTL_EFUSE_WR_DATA8_REG         (GLB_CTL_BASE + 0x720)
#define GLB_CTL_EFUSE_WR_DATA9_REG         (GLB_CTL_BASE + 0x724)
#define GLB_CTL_EFUSE_WR_DATA10_REG        (GLB_CTL_BASE + 0x728)
#define GLB_CTL_EFUSE_WR_DATA11_REG        (GLB_CTL_BASE + 0x72C)
#define GLB_CTL_EFUSE_WR_DATA12_REG        (GLB_CTL_BASE + 0x730)
#define GLB_CTL_EFUSE_WR_DATA13_REG        (GLB_CTL_BASE + 0x734)
#define GLB_CTL_EFUSE_WR_DATA14_REG        (GLB_CTL_BASE + 0x738)
#define GLB_CTL_EFUSE_WR_DATA15_REG        (GLB_CTL_BASE + 0x73C)
#define GLB_CTL_EFUSE_RD_DATA0_REG         (GLB_CTL_BASE + 0x740)
#define GLB_CTL_EFUSE_RD_DATA1_REG         (GLB_CTL_BASE + 0x744)
#define GLB_CTL_EFUSE_RD_DATA2_REG         (GLB_CTL_BASE + 0x748)
#define GLB_CTL_EFUSE_RD_DATA3_REG         (GLB_CTL_BASE + 0x74C)
#define GLB_CTL_EFUSE_RD_DATA4_REG         (GLB_CTL_BASE + 0x750)
#define GLB_CTL_EFUSE_RD_DATA5_REG         (GLB_CTL_BASE + 0x754)
#define GLB_CTL_EFUSE_RD_DATA6_REG         (GLB_CTL_BASE + 0x758)
#define GLB_CTL_EFUSE_RD_DATA7_REG         (GLB_CTL_BASE + 0x75C)
#define GLB_CTL_EFUSE_RD_DATA8_REG         (GLB_CTL_BASE + 0x760)
#define GLB_CTL_EFUSE_RD_DATA9_REG         (GLB_CTL_BASE + 0x764)
#define GLB_CTL_EFUSE_RD_DATA10_REG        (GLB_CTL_BASE + 0x768)
#define GLB_CTL_EFUSE_RD_DATA11_REG        (GLB_CTL_BASE + 0x76C)
#define GLB_CTL_EFUSE_RD_DATA12_REG        (GLB_CTL_BASE + 0x770)
#define GLB_CTL_EFUSE_RD_DATA13_REG        (GLB_CTL_BASE + 0x774)
#define GLB_CTL_EFUSE_RD_DATA14_REG        (GLB_CTL_BASE + 0x778)
#define GLB_CTL_EFUSE_RD_DATA15_REG        (GLB_CTL_BASE + 0x77C)
#define GLB_CTL_EFUSE_CLK_SEL_REG          (GLB_CTL_BASE + 0x780)
#define GLB_CTL_EFUSE_CTL_REG              (GLB_CTL_BASE + 0x784)
#define GLB_CTL_EFUSE_SOFT_RST_REG         (GLB_CTL_BASE + 0x788)
#define GLB_CTL_CALI_32K_TCXO_CTL_REG      (GLB_CTL_BASE + 0x800)
#define GLB_CTL_CALI_32K_TCXO_CNT_L_REG    (GLB_CTL_BASE + 0x810)
#define GLB_CTL_CALI_32K_TCXO_CNT_H_REG    (GLB_CTL_BASE + 0x814)
#define GLB_CTL_CALI_32K_TCXO_RESULT_L_REG (GLB_CTL_BASE + 0x818)
#define GLB_CTL_CALI_32K_TCXO_RESULT_H_REG (GLB_CTL_BASE + 0x81C)
#define GLB_CTL_AON_ICM_PRIORITY_REG       (GLB_CTL_BASE + 0xF30)
#define GLB_CTL_MEM_CLK_FORCE_ON_REG       (GLB_CTL_BASE + 0xF50)
#define GLB_CTL_MARGIN_ADJ_REG             (GLB_CTL_BASE + 0xF54)
#define GLB_CTL_POR_RESET_REG              (GLB_CTL_BASE + 0xF70)
#define GLB_CTL_UTMI_RESET_REG             (GLB_CTL_BASE + 0xF74)
#define GLB_CTL_PHY_BIST_CTL_REG           (GLB_CTL_BASE + 0xF78)
#define GLB_CTL_PHY_BIST_STS_REG           (GLB_CTL_BASE + 0xF7C)
#define GLB_CTL_USB_REFCLK_CFG_REG         (GLB_CTL_BASE + 0xF80)
#define GLB_CTL_DEFAULT_SLV_EN_REG         (GLB_CTL_BASE + 0xF84)
#define GLB_CTL_DEFAULT_SLV_HIT_STATUS_REG (GLB_CTL_BASE + 0xF88)
#define GLB_CTL_DEFAULT_SLV_HIT_CLR_REG    (GLB_CTL_BASE + 0xF8C)
#define GLB_CTL_REFCLK_FEQ_START_BIT       0
#define GLB_CTL_REFCLK_FEQ_BITS            1

/* PMU CMU 静态配置参数 */
#define PMU_CMU_CTL_BASE                    0x50002000
#define PMU_CMU_CTL_GP_REG0_REG             (PMU_CMU_CTL_BASE + 0x010)
#define PMU_CMU_CTL_GP_REG1_REG             (PMU_CMU_CTL_BASE + 0x014)
#define PMU_CMU_CTL_GP_REG2_REG             (PMU_CMU_CTL_BASE + 0x018)
#define PMU_CMU_CTL_GP_REG3_REG             (PMU_CMU_CTL_BASE + 0x01C)
#define PMU_CMU_CTL_UDSLEEP_BUTTON_CTRL_REG (PMU_CMU_CTL_BASE + 0x020)
#define PMU_CMU_CTL_UDSLEEP_BUTTON_RPT_REG  (PMU_CMU_CTL_BASE + 0x024)
#define PMU_CMU_CTL_UDSLEEP_BUTTON_INT_EN_REG   (PMU_CMU_CTL_BASE + 0x028)
#define PMU_CMU_CTL_FUSE_L_REG              (PMU_CMU_CTL_BASE + 0x040)
#define PMU_CMU_CTL_FUSE_H_REG              (PMU_CMU_CTL_BASE + 0x044)
#define PMU_CMU_CTL_FUSE_L_MAN_REG          (PMU_CMU_CTL_BASE + 0x050)
#define PMU_CMU_CTL_FUSE_H_MAN_REG          (PMU_CMU_CTL_BASE + 0x054)
#define PMU_CMU_CTL_FUSE_L_SEL_REG          (PMU_CMU_CTL_BASE + 0x058)
#define PMU_CMU_CTL_FUSE_H_SEL_REG          (PMU_CMU_CTL_BASE + 0x05C)
#define PMU_CMU_CTL_AON_PERP_CLKSEL_W_REG   (PMU_CMU_CTL_BASE + 0x090)
#define PMU_CMU_CTL_PMU_MAN_CLR_0_REG       (PMU_CMU_CTL_BASE + 0x104)
#define PMU_CMU_CTL_PMU_DBG_1_REG           (PMU_CMU_CTL_BASE + 0x130)
#define PMU_CMU_CTL_PMU_DBG_SEL_1_REG       (PMU_CMU_CTL_BASE + 0x134)
#define PMU_CMU_CTL_PMU_MAN_SEL_2           (PMU_CMU_CTL_BASE + 0x14C)
#define PMU_CMU_CTL_SYSLDO_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x200)
#define PMU_CMU_CTL_CLDO_CFG_0_REG          (PMU_CMU_CTL_BASE + 0x208)
#define PMU_CMU_CTL_CLDO_CFG_1_REG          (PMU_CMU_CTL_BASE + 0x20C)
#define PMU_CMU_CTL_VSET_AUTO_REG           (PMU_CMU_CTL_BASE + 0x210)
#define PMU_CMU_CTL_VBATD_CFG_REG           (PMU_CMU_CTL_BASE + 0x214)
#define PMU_CMU_CTL_PHYLDO_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x218)
#define PMU_CMU_CTL_PHYLDO_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x21C)
#define PMU_CMU_CTL_RFLDO1_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x220)
#define PMU_CMU_CTL_RFLDO1_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x224)
#define PMU_CMU_CTL_RFLDO2_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x228)
#define PMU_CMU_CTL_RFLDO2_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x22C)
#define PMU_CMU_CTL_RFLDO3_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x230)
#define PMU_CMU_CTL_RFLDO3_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x234)
#define PMU_CMU_CTL_RFLDO4_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x238)
#define PMU_CMU_CTL_RFLDO4_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x23c)
#define PMU_CMU_CTL_RFLDO5_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x240)
#define PMU_CMU_CTL_RFLDO5_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x244)
#define PMU_CMU_CTL_RFLDO6_CFG_0_REG        (PMU_CMU_CTL_BASE + 0x248)
#define PMU_CMU_CTL_RFLDO6_CFG_1_REG        (PMU_CMU_CTL_BASE + 0x24c)
#define PMU_CMU_CTL_EN_XLDO_CFG_0_REG       (PMU_CMU_CTL_BASE + 0x250)
#define PMU_CMU_CTL_EN_XLDO_CFG_1_REG       (PMU_CMU_CTL_BASE + 0x254)
#define PMU_CMU_CTL_EN_XLDO_CFG_2_REG       (PMU_CMU_CTL_BASE + 0x258)
#define PMU_CMU_CTL_FLASHLDO_CFG_0_REG      (PMU_CMU_CTL_BASE + 0x25c)
#define PMU_CMU_CTL_FLASHLDO_CFG_1_REG      (PMU_CMU_CTL_BASE + 0x260)
#define PMU_CMU_CTL_PMU_MISC_CFG_0_REG      (PMU_CMU_CTL_BASE + 0x270)
#define PMU_CMU_CTL_PMU_MISC_CFG_1_REG      (PMU_CMU_CTL_BASE + 0x274)
#define PMU_CMU_CTL_PMU_MISC_CFG_2_REG      (PMU_CMU_CTL_BASE + 0x278)
#define PMU_CMU_CTL_PMU_MISC_CFG_3_REG      (PMU_CMU_CTL_BASE + 0x27c)
#define PMU_CMU_CTL_BUCK_VSET_REG           (PMU_CMU_CTL_BASE + 0x280)
#define PMU_CMU_CTL_BUCK_CFG_0_REG          (PMU_CMU_CTL_BASE + 0x284)
#define PMU_CMU_CTL_BUCK_CFG_1_REG          (PMU_CMU_CTL_BASE + 0x288)
#define PMU_CMU_CTL_BUCK_CFG_2_REG          (PMU_CMU_CTL_BASE + 0x28c)
#define PMU_CMU_CTL_BUCK_CFG_3_REG          (PMU_CMU_CTL_BASE + 0x290)

#define PMU_CMU_CTL_PMU_STATUS_RAW_REG                 (PMU_CMU_CTL_BASE + 0x300)
#define PMU_CMU_CTL_PMU_STATUS_GRM_TIME_REG            (PMU_CMU_CTL_BASE + 0x330)
#define PMU_CMU_CTL_PMU_STATUS_GRM_TIME1_REG           (PMU_CMU_CTL_BASE + 0x334)
#define PMU_CMU_CTL_GATE_TSENSOR_VDDIO_REG             (PMU_CMU_CTL_BASE + 0x350)
#define PMU_CMU_CTL_BUCK_SLEEP3_REG                    (PMU_CMU_CTL_BASE + 0x364)
#define PMU_CMU_CTL_CMU_DBG_SEL_REG                    (PMU_CMU_CTL_BASE + 0x414)
#define PMU_CMU_CTL_CLK_480M_GT_REG                    (PMU_CMU_CTL_BASE + 0x420)
#define PMU_CMU_CTL_CLK_192M_GT_REG                    (PMU_CMU_CTL_BASE + 0x42C)
#define PMU_CMU_CTL_CLK_960M_GT_REG                    (PMU_CMU_CTL_BASE + 0x430)
#define PMU_CMU_CTL_REFDIV_REG                         (PMU_CMU_CTL_BASE + 0x500)
#define PMU_CMU_CTL_FBDIV_REG                          (PMU_CMU_CTL_BASE + 0x504)
#define PMU_CMU_CTL_FRAC_L_REG                         (PMU_CMU_CTL_BASE + 0x508)
#define PMU_CMU_CTL_FRAC_H_REG                         (PMU_CMU_CTL_BASE + 0x50C)
#define PMU_CMU_CTL_CMU_MISC_PD_REG                    (PMU_CMU_CTL_BASE + 0x514)
#define PMU_CMU_CTL_CMU_CLK_SEL_REG                    (PMU_CMU_CTL_BASE + 0x518)
#define PMU_CMU_CTL_CMU_STATUS_RAW_REG                 (PMU_CMU_CTL_BASE + 0x600)
#define PMU_CMU_CTL_SYS_STATUS_REG                     (PMU_CMU_CTL_BASE + 0x804)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_EN_FLASH_REG        (PMU_CMU_CTL_BASE + 0x810)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_EN_PMU_REF2_REG     (PMU_CMU_CTL_BASE + 0x814)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_EN_PMU_REG          (PMU_CMU_CTL_BASE + 0x818)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_CMU_XLDO_EN_REG     (PMU_CMU_CTL_BASE + 0x81C)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_BUCK_EN_REG         (PMU_CMU_CTL_BASE + 0x820)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_EN_CLDO_REG         (PMU_CMU_CTL_BASE + 0x824)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_EN_RFLDO4_REG       (PMU_CMU_CTL_BASE + 0x828)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_SDIO_SUB_PWR_EN_REG (PMU_CMU_CTL_BASE + 0x838)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_XO2PLL_BUF_PD_REG   (PMU_CMU_CTL_BASE + 0x83C)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_CMU_ISO_EN_REG      (PMU_CMU_CTL_BASE + 0x840)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_XLDO_VCO_GT_REG     (PMU_CMU_CTL_BASE + 0x844)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_TCXO2DBB_GT_REG     (PMU_CMU_CTL_BASE + 0x848)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_CLK_TCXO_EN_REG     (PMU_CMU_CTL_BASE + 0x84C)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_PD_REG              (PMU_CMU_CTL_BASE + 0x854)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_CLK_FON_REG         (PMU_CMU_CTL_BASE + 0x858)
#define PMU_CMU_CTL_WKUP_TIME_WLAN_RST_RELEASE_REG     (PMU_CMU_CTL_BASE + 0x85C)
#define PMU_CMU_CTL_WLAN_STA0_ALLOW_TO_SLEEP_REG       (PMU_CMU_CTL_BASE + 0x900)
#define PMU_CMU_CTL_WLAN_STA1_ALLOW_TO_SLEEP_REG       (PMU_CMU_CTL_BASE + 0x904)
#define PMU_CMU_CTL_WLAN_AP0_ALLOW_TO_SLEEP_REG        (PMU_CMU_CTL_BASE + 0x908)
#define PMU_CMU_CTL_WLAN_PF_ALLOW_TO_SLEEP_REG         (PMU_CMU_CTL_BASE + 0x90C)
#define PMU_CMU_CTL_WLAN_HOST_ALLOW_TO_SLEEP_REG       (PMU_CMU_CTL_BASE + 0x910)
#define PMU_CMU_CTL_WLAN_SLP_EVT_EN_REG                (PMU_CMU_CTL_BASE + 0x920)
#define PMU_CMU_CTL_WLAN_SLP_EVT_CLR_REG               (PMU_CMU_CTL_BASE + 0x924)
#define PMU_CMU_CTL_WLAN_SLP_INT_CLR_REG               (PMU_CMU_CTL_BASE + 0x934)
#define PMU_CMU_CTL_WLAN_WKUP_EVT_EN_REG               (PMU_CMU_CTL_BASE + 0x940)
#define PMU_CMU_CTL_WLAN_WKUP_EVT_CLR_REG              (PMU_CMU_CTL_BASE + 0x944)
#define PMU_CMU_CTL_WLAN_WKUP_EVT_STS_REG              (PMU_CMU_CTL_BASE + 0x948)
#define PMU_CMU_CTL_WLAN_WKUP_INT_EN_REG               (PMU_CMU_CTL_BASE + 0x950)
#define PMU_CMU_CTL_WLAN_WKUP_INT_CLR_REG              (PMU_CMU_CTL_BASE + 0x954)
#define PMU_CMU_CTL_WLAN_WKUP_INT_STS_REG              (PMU_CMU_CTL_BASE + 0x958)
#define PMU_CMU_CTL_DEBUG_GLB_SIGNAL_SEL_2_REG         (PMU_CMU_CTL_BASE + 0xF24)

#define CRG_REG_SC_PLLLOCK_STAT_REG     (HI_CRG_REG_BASE + 0x0)  /* SC_PLLLOCK_STAT为PLL LOCK状态指示寄存器。 */
#define CRG_REG_SC_APLL_CTRL0_REG       (HI_CRG_REG_BASE + 0x4)  /* SC_APLL_CTRL0为ARM PLL控制0寄存器。 */
#define CRG_REG_SC_APLL_CTRL1_REG       (HI_CRG_REG_BASE + 0x8)  /* SC_APLL_CTRL1为ARM PLL控制1寄存器。 */
#define CRG_REG_SC_PERI_CLKEN0_REG      (HI_CRG_REG_BASE + 0x14) /* SC_PERI_CLKEN为外设时钟使能寄存器0。 */
#define CRG_REG_SC_PERI_CLKEN1_REG      (HI_CRG_REG_BASE + 0x18) /* SC_PERI_CLKEN为外设时钟使能寄存器1。 */
#define CRG_REG_SC_PERI_CLKSTAT0_REG    (HI_CRG_REG_BASE + 0x1C) /* SC_PERI_CLKSTAT为外设时钟状态指示寄存器0。 */
#define CRG_REG_SC_PERI_CLKSTAT1_REG    (HI_CRG_REG_BASE + 0x20) /* SC_PERI_CLKSTAT为外设时钟状态指示寄存器1。 */
#define CRG_REG_SC_PERI_CLKSEL_REG      (HI_CRG_REG_BASE + 0x24) /* SC_PERI_CLKSEL为外设时钟源选择寄存器。 */
#define CRG_REG_SC_PERI_SRST_REG        (HI_CRG_REG_BASE + 0x28) /* SC_PERI_SRST为外设软复位请求寄存器。 */
#define CRG_REG_SC_SLEEP0_CTRL_REG      (HI_CRG_REG_BASE + 0x2C) /* SC_SLEEP0_CTRL为低功耗各模块时钟sleep使能
                                                                    控制寄存器。 */
#define CRG_REG_SC_PHY_CLK_EN_REG       (HI_CRG_REG_BASE + 0x30) /* SC_PHY_CLK_EN为PHY时钟门控软件控制寄存器。 */
#define CRG_REG_SC_PHY_SRST_REG         (HI_CRG_REG_BASE + 0x34) /* SC_PHY_SRST为PHY软复位控制寄存器。 */
#define CRG_REG_SC_PHY_RST_MASK_REG     (HI_CRG_REG_BASE + 0x38) /* SC_PHY_RST_MASK为PHY复位屏蔽寄存器。 */
#define CRG_REG_MEM_TOP_GATE_EN_REG     (HI_CRG_REG_BASE + 0x3C) /* MEM_TOP的时钟门控寄存器。 */
#define CRG_REG_BOOT_ROM_GATE_EN_REG    (HI_CRG_REG_BASE + 0x40) /* BOOTROM的时钟门控寄存器。 */
#define CRG_REG_SC_PHY_RST1_MASK_REG    (HI_CRG_REG_BASE + 0x44) /* SC_PHY_RST_MASK为PHY复位屏蔽寄存器1。 */
#define CRG_REG_SC_SLEEP1_CTRL_REG      (HI_CRG_REG_BASE + 0x48) /* SC_SLEEP1_CTRL为低功耗各模块时钟sleep使能
                                                                    控制寄存器。 */
#define CRG_REG_SC_DEEP_SLEEP0_CTRL_REG (HI_CRG_REG_BASE + 0x4C) /* SC_DEEP_SLEEP0_CTRL为低功耗各模块时钟sleep使能
                                                                    控制寄存器。 */
#define CRG_REG_SC_DEEP_SLEEP1_CTRL_REG (HI_CRG_REG_BASE + 0x50) /* SC_DEEP_SLEEP1_CTRL为低功耗各模块时钟sleep使能
                                                                    控制寄存器。 */
#define CRG_REG_SC_PERI_SRST1_REG       (HI_CRG_REG_BASE + 0x54) /* SC_PERI_SRST1为外设软复位请求寄存器。 */
#define CRG_REG_SC_PHY1_SRST1_REG       (HI_CRG_REG_BASE + 0x58) /* SC_PHY_SRST1为PHY软复位控制寄存器。 */
#define CRG_REG_XTAL_IO_CTRL_REG        (HI_CRG_REG_BASE + 0x5C) /* 晶体IO的配置寄存器。 */

#define CRG_REG_SSP_SRST_REQ_LEN           1
#define CRG_REG_SSP_SRST_REQ_OFFSET        7
#define CRG_REG_SSP2_SRST_REQ_LEN          1
#define CRG_REG_SSP2_SRST_REQ_OFFSET       5
#define CRG_REG_I2C_SRST_REQ_LEN           1
#define CRG_REG_I2C_SRST_REQ_OFFSET        12
#define CRG_REG_SFC_SRST_REQ_LEN           1
#define CRG_REG_SFC_SRST_REQ_OFFSET        2
#define CRG_REG_SFC_BUS_CLK_EN_LEN         1
#define CRG_REG_SFC_BUS_CLK_EN_OFFSET      17
#define CRG_REG_SFC_CLK_EN_LEN             1
#define CRG_REG_SFC_CLK_EN_OFFSET          16

#define SYSCTRL_SC_CTRL_REG       (HI_SYSCTRL_REG_BASE + 0x0)   /* SC_CTRL为系统控制寄存器。用于指定需要系统完成的
                                                                 * 操作。
                                                                 */
#define SYSCTRL_SC_SYSRES_REG     (HI_SYSCTRL_REG_BASE + 0x4)   /* SC_SYSRES为系统软复位控制寄存器。向该寄存器写
                                                                 * 入任何值都会使系统控制器向复位模块发出系统软复位
                                                                 * 请求，复位模进行系统软复位。
                                                                 */
#define SYSCTRL_SC_IMCTRL_REG     (HI_SYSCTRL_REG_BASE + 0x8)   /* SC_IMCTRL为中断模式控制寄存器。 */
#define SYSCTRL_SC_IMSTAT_REG     (HI_SYSCTRL_REG_BASE + 0xC)   /* SC_IMSTAT为中断模式状态寄存器。 */
#define SYSCTRL_SC_XTALCTRL_REG   (HI_SYSCTRL_REG_BASE + 0x10)  /* SC_XTALCTRL为晶振控制寄存器。用于控制初始化时钟
                                                                 * 模块的稳定等待时间，即从XTAL CTL中间态跳转到
                                                                 * SWtoXTAL中间态的等待时间。
                                                                 */
#define SYSCTRL_SC_PLLCTRL_REG    (HI_SYSCTRL_REG_BASE + 0x14)  /* SC_PLLCTRL为ARM PLL控制寄存器。用于设置APLL锁相
                                                                 * 环稳定等待时间。APLL的时钟频率由SC_APLL_CTRL1
                                                                 * bit[20:0]和SC_APLL_CTRL0 bit[29:0]控制。
                                                                 */
#define SYSCTRL_SC_AFE_CTRL_REG   (HI_SYSCTRL_REG_BASE + 0x20)  /* SC_AFE_CTRL为AFE控制寄存器。 */
#define SYSCTRL_SC_VERSION_ID_REG (HI_SYSCTRL_REG_BASE + 0x24)  /* SC_VERSION_ID为芯片版本寄存器。 */
#define SYSCTRL_SC_HW_ID_REG      (HI_SYSCTRL_REG_BASE + 0x28)  /* SC_HW_ID为硬件版本寄存器。 */
#define SYSCTRL_SC_PERI_CTRL_REG  (HI_SYSCTRL_REG_BASE + 0x2C)  /* SC_PERI_CTRL为外设控制寄存器。 */
#define SYSCTRL_SC_LOCKEN_REG     (HI_SYSCTRL_REG_BASE + 0x38)  /* SC_LOCKEN为写保护控制寄存器。 */
#define SYSCTRL_SC_PAD_CONFIG_REG (HI_SYSCTRL_REG_BASE + 0x3C)  /* SC_PAD_CONFIG为PAD的配置寄存器。 */
#define SYSCTRL_SC_GEN_REG0_REG   (HI_SYSCTRL_REG_BASE + 0x40)  /* SC_GEN_REG0为通用寄存器0。 */
#define SYSCTRL_SC_GEN_REG1_REG   (HI_SYSCTRL_REG_BASE + 0x44)  /* SC_GEN_REG1为通用寄存器1。 */
#define SYSCTRL_SC_GEN_REG2_REG   (HI_SYSCTRL_REG_BASE + 0x48)  /* SC_GEN_REG2为通用寄存器2。 */
#define SYSCTRL_SC_GEN_REG3_REG   (HI_SYSCTRL_REG_BASE + 0x4C)  /* SC_GEN_REG3为通用寄存器3，软件用来传工厂NV地址 */
#define SYSCTRL_SC_GEN_REG4_REG   (HI_SYSCTRL_REG_BASE + 0x50)  /* SC_GEN_REG4为通用寄存器4。 */
#define SYSCTRL_SC_GEN_REG5_REG   (HI_SYSCTRL_REG_BASE + 0x54)  /* SC_GEN_REG5为通用寄存器5。 */
#define SYSCTRL_SC_GEN_REG6_REG   (HI_SYSCTRL_REG_BASE + 0x58)  /* SC_GEN_REG6为通用寄存器6。 */
#define SYSCTRL_SC_GEN_REG7_REG   (HI_SYSCTRL_REG_BASE + 0x5C)  /* SC_GEN_REG7为通用寄存器7。 */

#define PKTB_MODE_NOT_CHANGE 0
#define PKTB_MODE_32K        1
#define PKTB_MODE_48K        2
#define PKTB_MODE_64K        3
#define PKTB_MODE_80K        4
#define PKTB_MODE_96K        5
#define PKTB_MODE_112K       6
#define PKTB_MODE_128K       7
#define PKTB_MODE_144K       8
#define PKTB_MODE_160K       9
#define PKTB_MODE_176K       10
#define PKTB_MODE_192K       11
#define PKTB_MODE_DEFAULT    PKTB_MODE_64K

/* DIAG CTL REG */
#define DIAG_CTL_BASE               0x40060000
#define DIAG_CTL_GP_REG0_REG        (DIAG_CTL_BASE + 0x010) /* used to save rsa key */
#define DIAG_CTL_GP_REG1_REG        (DIAG_CTL_BASE + 0x014) /* used to save rsa key */
#define DIAG_CTL_GP_REG2_REG        (DIAG_CTL_BASE + 0x018) /* used to save ecc key */
#define DIAG_CTL_GP_REG3_REG        (DIAG_CTL_BASE + 0x01C) /* used to save ecc key */
#endif /* __HI3861_PLATFORM_BASE_H */

