/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
 * Description: Cmd loop head file.
 * Author: Hisilicon
 * Create: 2019-12-19
 */

#ifndef __CMD_LOOP_H__
#define __CMD_LOOP_H__

#include <uart_auth.h>

#define ACK_SUCCESS        0x5A
#define ACK_FAILURE        0xA5

enum {
    CMD_ACK = 0xE1,
    CMD_DL_IMAGE = 0xD2,
    CMD_BURN_EFUSE = 0xC3,
    CMD_UL_DATA = 0xB4,
    CMD_READ_EFUSE = 0xA5,
    CMD_FLASH_PROTECT = 0x96,
    CMD_RESET = 0x87,
    CMD_FACTORY_IMAGE = 0x78,
    CMD_VERSION = 0x69
};

#define LOADER_CMD_MAX      8

hi_u32 loader_download_image(const uart_ctx *cmd_ctx);
hi_u32 loader_burn_efuse(const uart_ctx *cmd_ctx);
hi_u32 loader_upload_data(const uart_ctx *cmd_ctx);
hi_u32 loader_read_efuse(const uart_ctx *cmd_ctx);
hi_u32 loader_flash_protect(const uart_ctx *cmd_ctx);
hi_u32 loader_reset(const uart_ctx *cmd_ctx);
hi_u32 loader_burn_version(const uart_ctx *cmd_ctx);
uart_ctx *cmd_loop_init(hi_void);
hi_u32 cmd_loop_deinit(hi_void);
hi_void cmd_loop(uart_ctx *ctx);
hi_void loader_ack(hi_u8 err_code);

extern void *__nmi_stack_top;    /* defined in link scripts. */
extern void *__nmi_stack_bottom; /* defined in link scripts. */
#define bit_set(x, i, b) ((x) = (hi_u8)((b) ? ((1 << (i)) | (x)) : ((~(hi_u8)(1 << (i))) & (x))))
#define bit_get(x, i)    (((1 << (i)) & (x)) ? 1 : 0)
#define SRV_BIT_LOW  0
#define SRV_BIT_HIGH 1

#endif /* __CMD_LOOP_H__ */

