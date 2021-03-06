/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: hi_queue.h header file
 * Author: hisilicon
 * Create: 2016-02-29
 */

#ifndef __HI_QUEUE_H__
#define __HI_QUEUE_H__
#include "hi_types.h"
#include <linux/workqueue.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef hi_void (*work_func)(struct work_struct *);
typedef struct workqueue_struct     hi_workqueue;
typedef struct work_struct          hi_work;
typedef struct delayed_work         hi_delayed_work; /* struct delay_work wrap struct work_struct */

/* create workqueue. */
inline hi_workqueue *hi_workqueue_create(char *workqueue_name)
{
    return create_workqueue(workqueue_name);
}

/* destroy workqueue. */
inline hi_void  hi_workqueue_destroy(hi_workqueue *workqueue)
{
    destroy_workqueue(workqueue);
}

/* init work. */
inline hi_void hi_workqueue_init_work(hi_work *work, work_func func)
{
    INIT_WORK(work, func);
}

/* add work to workqueue. */
inline hi_s32  hi_workqueue_add_work(hi_workqueue *workqueue, hi_work *work)
{
    return queue_work(workqueue, work);
}

/* cancle work from workqueue. */
inline hi_bool hi_workqueue_cancle_work_sync(hi_work *work)
{
    return cancel_work_sync(work);
}

/* judge work is working. */
inline hi_bool hi_workqueue_is_busy(hi_work *work)
{
    return work_busy(work);
}

/* init delayed work. */
inline hi_void hi_workqueue_init_delayed_work(hi_delayed_work *delayed_work, work_func func)
{
    init_delayed_work(delayed_work, func);
}

/* add delay work to workqueue. */
inline hi_s32 hi_workqueue_add_delayed_work(hi_workqueue *workqueue, hi_delayed_work *delayed_work, hi_u32 delay)
{
    return queue_delayed_work(workqueue, delayed_work, delay);
}

/* cancle delayed work to workqueue. */
inline hi_bool hi_workqueue_cancle_delayed_work_sync(hi_delayed_work *delayed_work)
{
    return cancel_delayed_work_sync(delayed_work);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of hi_workqueue.h */
