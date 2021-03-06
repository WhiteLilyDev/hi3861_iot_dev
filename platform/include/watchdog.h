/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: watchdog internal interface.
 * Author: hisilicon
 * Create: 2019-03-04
 */


 /**
 * @file watchdog.h
 *
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019. All rights reserved.  \n
 *
 * Description: watchdog interfaces. \n
 */

#ifndef __BSP_INC_WATCHDOG_H__
#define __BSP_INC_WATCHDOG_H__

#include <hi3861_platform_base.h>
#include <hi_watchdog.h>

/**
* @ingroup  hct_watchdog
* @brief Watchdog callback function. CNcomment:看门狗到期回调函数。CNend
*
* @par 描述:
*           Watchdog callback function. CNcomment:看门狗到期回调函数。CNend
*
* @attention None.
* @param  data [IN] type #hi_u32，Callback function parameter passing.CNcomment:回调函数参数传递。CNend
*
* @retval None.
* @par 依赖:
*            @li watchdog.h：文件用于描述看门狗相关接口。
* @see 无。
* @since Hi3861_V100R001C00
*/
typedef hi_void (*hi_watchdog_func)(hi_u32 data);

/**
 * @ingroup hct_watchdog
 *
 * Watchdog mode. CNcomment:看门狗模式。CNend
 */
typedef enum {
    HI_WDG_MODE_NORMAL = 0,  /**< 普通模式，看门狗到期时复位芯片  */
    HI_WDG_MODE_INTER = 1,   /**< 中断模式，看门狗第一次到期时调用注册的回调函数，看门狗第二次到期时复位芯片  */
    HI_WDG_MODE_ERR,         /**< 错误入参，不可使用  */
} hi_wdg_mode;

/**
* @ingroup  hct_watchdog
* @brief  Clear the watchdog interrupt.CNcomment:清除看门狗中断。CNend
*
* @par 描述:
*           Clear the watchdog interrupt.CNcomment:清除看门狗中断。CNend
*
* @attention 无。
* @param  无。
*
* @retval 无。
* @par 依赖:
*            @li watchdog.h：文件用于描述看门狗相关接口。
* @see  无。
* @since Hi3861_V100R001C00
*/
HI_EXTERN hi_void hi_watchdog_int_clear(hi_void);

/**
* @ingroup  hct_watchdog
* @brief  Configure to enable the watchdog. CNcomment:配置使能看门狗。CNend
*
* @par 描述:
*           Configure to enable the watchdog. CNcomment:配置使能看门狗。CNend
*
* @attention 无。
* @param  mode         [IN] type #hi_wdg_mode ，Watchdog mode. CNcomment:看门狗模式。CNend
* @param  p_func       [IN] type #hi_watchdog_func，Configure the watchdog to interrupt mode and the function will be
called to notify the user when the watchdog first expires.
CNcomment:配置看门狗为中断模式时，看门狗第一次到期时会调用该函数通知用户。CNend
* @param  data         [IN] type #hi_u32 Callback function enter parameter. CNcomment:回调函数入参。CNend
* @param  over_time_ms [IN] type #hi_u32，Watchdog expiration time (unit: ms).
                        Expiration time calculation method: expiration time t = 2^(top+16)*1000/wd_clk,
                        where wd_clk is the watchdog clock frequency and top range is 0~15.
                        Therefore, there is a certain error between the expected expiration time and
                        the actual expiration time.
                        CNcomment:看门狗到期时间（单位：ms）。
*                           到期时间计算方法:到期时间t = 2^(top+16)*1000/wd_clk,其中wd_clk为看门狗时钟频率，top取值为0~15。
*                           因此期望的到期时间与实际到期时间有一定误差。CNend
*
* @retval #0           Sunccess.
* @retval #非0         Failure. For details, see hi_errno.h.
* @par 依赖:
*            @li watchdog.h：文件用于描述看门狗相关接口。
* @see  无。
* @since Hi3861_V100R001C00
*/
HI_EXTERN hi_u32 hi_watchdog_register(hi_wdg_mode mode, hi_watchdog_func p_func, hi_u32 data, hi_u32 over_time_ms);

HI_EXTERN hi_void watchdog_irq_handler(hi_u32 data);

#endif

