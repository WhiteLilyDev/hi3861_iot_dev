/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: Upgrade base funciton - file check.
 * Author: Hisilicon
 * Create: 2019-12-10
 */

#ifndef __UPG_CHECK_FILE_H__
#define __UPG_CHECK_FILE_H__

#include <upg_common.h>

#define PRODUCT_UPG_FILE_IMAGE_ID 0x3C78961E
#define KERELN_VER_MAX          48
#define KERNEL_VER_LEN          6
#define BOOT_VER_MAX              16
#define BOOT_VER_LEN              2

#define HI_UPG_FILE_ATTR_UNENCRYPT  0x1 /* kernel or flashboot attributes */
#define HI_UPG_FILE_ATTR_ENCRYPT    0x2 /* kernel or flashboot attributes */

#define HI_UPG_FILE_ATTR_KERNELA     0x1 /* dual partition ota kernelA attributes */
#define HI_UPG_FILE_ATTR_KERNELB     0x2 /* dual partition ota kernelB attributes */
#define HI_UPG_FILE_ATTR_COMPRESSION 0x4 /* compression ota kernel or flashboot attributes */

#define HI_UPG_OTA_SETTINGS_MASK  0x3F

hi_u32 upg_check_common_head(const hi_upg_common_head *head, hi_u32 head_size);
hi_u32 upg_get_common_head_from_flash(hi_u32 addr, hi_upg_common_head *head);
hi_u32 upg_get_section_head_from_flash(hi_u32 addr, hi_upg_section_head *section_head);
hi_u32 upg_verify_file(hi_u32 flash_addr);
#endif /* __UPG_CHECK_FILE_H__ */

