/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved.
 * Description: implementation for l3_msg_event
 * Author: none
 * Create: 2020
 */

#include "lwip/opt.h"
#include "lwip/sys.h"
#if !NO_SYS /* don't build if not configured for use in lwipopts.h */

#if LWIP_L3_EVENT_MSG

#include "lwip/l3event.h"
#include "lwip/tcpip.h"

/* global variables, used for storing the callback function from upper app */
static app_callback_fn g_l3_evt_cbs[L3_EVENT_MSG_MAX];

/*
 * Invoke l3 msg event callback
 * @param type which l3 event msg type
 * @param msg data that are carried in the msg
 */
void
l3_invoke_msg_callback(enum l3_event_msg_type evt_type, void *msg)
{
#if (LWIP_ROUTE_CHANGE_MSG || LWIP_RPL_JOIN_SUCC_MSG || \
     LWIP_RPL_PARENT_CLEAR_MSG || LWIP_RPL_BEACON_PRI_RESET)
  switch (evt_type) {
#if LWIP_ROUTE_CHANGE_MSG
    case L3_EVENT_MSG_ROUTE_CHANGE:
#endif
#if LWIP_RPL_JOIN_SUCC_MSG
    case L3_EVENT_MSG_RPL_JOIN_SUCC:
#endif
#if LWIP_RPL_PARENT_CLEAR_MSG
    case L3_EVENT_MSG_PARENT_CLEAR:
#endif
#if LWIP_RPL_BEACON_PRI_RESET
    case L3_EVENT_MSG_BEACON_PRI_RESET:
#endif
    if (g_l3_evt_cbs[evt_type] != NULL) {
      g_l3_evt_cbs[evt_type](evt_type, msg);
    } else {
      LWIP_DEBUGF(L3_EVENT_MSG_DEBUG, ("l3_ext_parent_clear_callback: callback function didn't be registered\n"));
    }
    break;
    default:
      LWIP_DEBUGF(L3_EVENT_MSG_DEBUG, ("l3_event_thread: invalid message: %d\n", evt_type));
      LWIP_ASSERT("invalid message", 0);
      break;
  }
#else
  (void)evt_type;
  (void)msg;
#endif
}

/*
 * l3 event msg callback
 * @param type which l3 event msg type
 * @param app_callback the register callback function
 */
void l3_event_msg_callback_reg(enum l3_event_msg_type evt_type, app_callback_fn app_callback)
{
#if (LWIP_ROUTE_CHANGE_MSG || LWIP_RPL_JOIN_SUCC_MSG || \
     LWIP_RPL_PARENT_CLEAR_MSG || LWIP_RPL_BEACON_PRI_RESET)
  switch (evt_type) {
#if LWIP_ROUTE_CHANGE_MSG
    case L3_EVENT_MSG_ROUTE_CHANGE:
#endif
#if LWIP_RPL_JOIN_SUCC_MSG
    case L3_EVENT_MSG_RPL_JOIN_SUCC:
#endif
#if LWIP_RPL_PARENT_CLEAR_MSG
    case L3_EVENT_MSG_PARENT_CLEAR:
#endif
#if LWIP_RPL_BEACON_PRI_RESET
    case L3_EVENT_MSG_BEACON_PRI_RESET:
#endif
    LOCK_TCPIP_CORE();
    g_l3_evt_cbs[evt_type] = app_callback;
    UNLOCK_TCPIP_CORE();
    LWIP_DEBUGF(L3_EVENT_MSG_DEBUG, ("l3_event_msg_callback: register the MSG callback function\n"));
    break;
    default:
      LWIP_DEBUGF(L3_EVENT_MSG_DEBUG, ("l3_event_msg_callback: invalid message: %d\n", evt_type));
      LWIP_ASSERT("l3_event_msg_callback: invalid message", 0);
      break;
  }
#else
    (void)evt_type;
    (void)app_callback;
#endif
}

#endif /* LWIP_L3_EVENT_MSG */
#endif /* !NO_SYS */
