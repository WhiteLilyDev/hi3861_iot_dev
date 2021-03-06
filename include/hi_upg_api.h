/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Upgrade APIs, which are used to implement the upgrade function.
 * Author: Hisilicon
 * Create: 2019-10-25
 */

/**
 * @defgroup upg Upgrade
 * @ingroup system
*/

#ifndef __HI_UPG_API_H__
#define __HI_UPG_API_H__
#include "hi_upg_file.h"
#include <hi_types.h>

/**
 * @ingroup upg
 * Kernel upgrade file. CNcomment:Kernel升级文件。CNend
 */
#define HI_UPG_FILE_KERNEL    0xF0

/**
 * @ingroup upg
 * FlashBoot upgrade file. CNcomment:FlashBoot升级文件。CNend
 */
#define HI_UPG_FILE_BOOT       0xE1

/**
 * @ingroup upg
 * Kernel upgrade file of area A. CNcomment:A区升级文件。CNend
 */
#define HI_UPG_FILE_FOR_AREA_A        1

/**
 * @ingroup upg
 * Kernel upgrade file of area B/Compress kernel upgrade file. CNcomment:B区升级文件/压缩升级文件。CNend
 */
#define HI_UPG_FILE_FOR_AREA_B        2

/**
 * @ingroup upg
 * Kernel upgrade file ID. CNcomment:Kernel升级文件ID。CNend
 */
#define HI_UPG_FILE_IMAGE_ID 0x3C78961E

/**
* @ingroup upg
* @brief  Upgrade module initialization.CNcomment:升级模块初始化。CNend
*
* @par   描述:
            Upgrade module initialization.CNcomment:升级模块初始化。CNend
* @attention
* @li Must be called immediately after NV initialization. CNcomment:必须紧跟NV初始化后调用。CNend
* @li This interface does not support multiple calls. CNcomment:该接口不支持多次调用。CNend
* @param  None.
* @retval #HI_ERR_SUCCESS Success.CNcomment:升级模块初始化成功。CNend
* @retval #Other Failure.CNcomment:其他值 升级模块初始化失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_init(hi_void);

/**
* @ingroup upg
* @brief  Get upgrade file from the backup flash.CNcomment:从备份区读取升级文件。CNend
*
* @par   描述:
            Used to get upgrade data from the backup flash.CNcomment:该函数从备份区读升级文件。CNend
* @attention
* @li Ensure that the actual buffer size is the same as the value of buf_len.
*   CNcomment:用户需保证buf实际大小与buf_len相等。CNend
* @li Must be called after calling interface hi_upg_transmit.CNcomment:必须在调用升级文件传输接口之后调用。CNend
* @li Must be called before calling interface hi_upg_transmit_finish.CNcomment:必须在调用升级文件传输完成之前调用。CNend
* @param  offset  [IN] type #hi_u32 Offset relative to the start address of the upgrade cache.
*   CNcomment:相对升级备份区起始地址的偏移地址。CNend
* @param  buf     [IN/OUT] type #hi_u8* Pointer to the upgrade data package.CNcomment:升级数据包指针。CNend
* @param  buf_len [IN] type #hi_u32 Length of the upgrade data package.Unit: byte.
*   CNcomment:升级数据包长度，单位：byte。CNend
* @retval #HI_ERR_SUCCESS Success.CNcomment:读成功。CNend
* @retval #Other Failure.CNcomment:其他值 读失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_get_content(hi_u32 offset, hi_u8* buf, hi_u32 buf_len);

/**
* @ingroup upg
* @brief  Transmit upgrade file.CNcomment:传输升级文件。CNend
*
* @par   描述:
            Transmit upgrade file.CNcomment:传输升级文件。CNend
* @attention
* @li The first packet transmitted is not less than 96 bytes.CNcomment:传输的第1包不小于96字节。CNend
* @param  offset  [IN] type #hi_u32 Offset relative to the head of the upgrade file.CNcomment:相对升级文件头的偏移地址。CNend
* @param  buf     [IN] type #hi_u8* Upgrade file data.CNcomment:升级数据包。CNend
* @param  buf_len [IN] type #hi_u32 Length of the upgrade file data.Unit:byte.CNcomment:升级数据包长度，单位：byte。CNend
* @retval #HI_ERR_SUCCESS Success.CNcomment:成功。CNend
* @retval #Other Failure.CNcomment:其他值 失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_transmit(hi_u32 offset, hi_u8* buf, hi_u32 buf_len);

/**
* @ingroup upg
* @brief  Upgrade restart.CNcomment:升级重启。CNend
*
* @par   描述:
            This interface is used to restart.CNcomment:该接口实现升级重启。CNend
* @attention None.
* @param  None.
* @retval None.
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_void hi_upg_finish(hi_void);

/**
* @ingroup upg
* @brief  Notify file transfer end.CNcomment:文件传输结束。CNend
*
* @par   描述:
            Used to notify file transfer end.CNcomment:文件传输结束。CNend
* @attention None.
* @param  None.
* @retval #HI_ERR_SUCCESS Success.CNcomment:成功。CNend
* @retval #Other Failure.CNcomment:其他值 失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_transmit_finish(hi_void);

/**
* @ingroup upg
* @brief  Get the maximum upgrade file length.CNcomment:获取最大升级文件长度。CNend
*
* @par   描述:
            Used to get the maximum upgrade file length.CNcomment:获取最大升级文件长度。CNend
* @attention None.
* @param  file_type [IN] type #hi_u8 Upgrade file type.CNcomment:升级文件类型。CNend
* @param  file_len  [IN/OUT] type #hi_u32* Max file length.CNcomment:最大升级文件大小。CNend
* @retval #HI_ERR_SUCCESS Success.CNcomment:成功。CNend
* @retval #Other Failure.CNcomment:其他值 失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_get_max_file_len(hi_u8 file_type, hi_u32 *file_len);

/**
* @ingroup upg
* @brief  Get the upgrade file index.CNcomment:获取升级文件编号。CNend
*
* @par   描述:
            Get the upgrade file index.CNcomment:获取升级文件编号。CNend
* @attention None.CNcomment:无。CNend
* @param  index [IN/OUT] type #hi_u8* Upgrade file index.CNcomment:升级文件编号。CNend
* @retval #1 Upg file for area A.CNcomment:1 A区升级文件。CNend
* @retval #2 Upg file for area B.CNcomment:2 B区升级文件。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_get_file_index(hi_u8 *index);

/**
* @ingroup upg
* @brief  Stop the upgrade process.CNcomment:停止升级。CNend
*
* @par   描述:
            Used to stop the upgrade process.CNcomment:停止升级。CNend
* @attention None.
* @param  None.
* @retval #HI_ERR_SUCCESS Success.CNcomment:成功。CNend
* @retval #Other Failure.CNcomment:其他值 失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_stop(hi_void);

/**
* @ingroup upg
* @brief  Register upgrade file validity check interface.CNcomment:注册升级文件合法性校验接口。CNend
*
* @par   描述:
            Register upgrade file validity check interface.CNcomment:注册升级文件合法性校验接口。CNend
* @attention Called during the initialization process.CNcomment:初始化流程中调用。CNend
* @param  upg_file_check_fn [IN]User-defined upgrade file verification interface.CNcomment:用户自定义接口。CNend
* @param  param [IN]Passed back to callback function when callback.CNcomment:用户自定义接口参数。CNend
* @retval #HI_ERR_SUCCESS Success.CNcomment:成功。CNend
* @retval #Other Failure.CNcomment:其他值 失败。CNend
* @par 依赖:
*            @li hi_upg_api.h：Describe Upgrade usage APIs.CNcomment:文件用于描述升级对外接口。CNend
* @see None.CNcomment:无。CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_upg_register_file_verify_fn(
    hi_u32 (*upg_file_check_fn)(const hi_upg_user_info *info, hi_void *param),
    hi_void *param);

#endif


