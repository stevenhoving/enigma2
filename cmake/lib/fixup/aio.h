#pragma once

#include <sys/types.h>

struct aiocb {
    /* The order of these fields is implementation-dependent */

    int             aio_fildes;     /* File descriptor */
    off_t           aio_offset;     /* File offset */
    volatile void  *aio_buf;        /* Location of buffer */
    size_t          aio_nbytes;     /* Length of transfer */
    int             aio_reqprio;    /* Request priority */
    //struct sigevent aio_sigevent;   /* Notification method */
    int             aio_lio_opcode; /* Operation to be performed;
                                       lio_listio() only */

                                       /* Various implementation-internal fields not shown */
};

enum
{
    AIO_CANCELED,
#define AIO_CANCELED AIO_CANCELED
    AIO_NOTCANCELED,
#define AIO_NOTCANCELED AIO_NOTCANCELED
    AIO_ALLDONE
#define AIO_ALLDONE AIO_ALLDONE
};



static int aio_error(const struct aiocb *aiocbp)
{
    printf("aio_error\n");
    return 0;
}

static int aio_suspend(const struct aiocb * const aiocb_list[],
    int nitems, const struct timespec *timeout)
{
    printf("aio_suspend\n");
    return 0;
}

static ssize_t aio_return(struct aiocb *aiocbp)
{
    printf("aio_return\n");
    return 0;
}

static int aio_write(struct aiocb *aiocbp)
{
    printf("aio_write\n");
    return 0;
}

static int aio_cancel(int fd, struct aiocb *aiocbp)
{
    printf("aio_cancel\n");
    return 0;
}