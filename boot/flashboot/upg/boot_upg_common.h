/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: boot upg common.
 * Author: Hisilicon
 * Create: 2019-12-10
 */

#ifndef __BOOT_UPG_COMMON_H__
#define __BOOT_UPG_COMMON_H__

#include <hi_upg_file.h>
#include <hi_boot_rom.h>
#include <hi_flashboot.h>
#include <hi_cipher.h>
#include <lzmaram.h>

typedef hi_u8 srv_bit; /* value 0 or 1 */

#define BIT_U8   8
#define BIT_U16  16
#define MASK_U16 0xFFFF

#define SRV_BIT_LOW  0
#define SRV_BIT_HIGH 1

/*
    i must 0~7 b must 0 or 1 x must a character
    high ---------------->  low
    **************************
     7  6  5  4  3  2   1   0
    **************************
 */
#define bit_set(x, i, b) ((x) = (hi_u8)((b) ? ((1 << (i)) | (x)) : ((~(hi_u8)(1 << (i))) & (x))))
#define bit_get(x, i)    (((1 << (i)) & (x)) ? 1 : 0)

#define boot_upg_mem_free(sz)  \
    do {                       \
        if ((sz) != HI_NULL) { \
            boot_free((sz));   \
        }                      \
        (sz) = HI_NULL;        \
    } while (0)

hi_bool boot_upg_tool_bit_test(const hi_u8 *data, hi_u16 pos);
hi_void boot_upg_tool_bit_set(hi_u8 *data, hi_u16 pos, hi_u8 val);

#endif

