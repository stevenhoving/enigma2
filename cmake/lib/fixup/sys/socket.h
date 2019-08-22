#pragma once

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#include <stdio.h>

//using socklen_t = unsigned int;

static int getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len)
{
    printf("getsockopt\n");
    return 0;
}

static int shutdown(int socket, int how)
{
    printf("shutdown\n");
    return 0;
}

using sa_family_t = unsigned int;

struct sockaddr_un
{
    sa_family_t sun_family;      /* AF_UNIX */
    char        sun_path[108];   /* pathname */
};


enum
{
    //MSG_OOB = 0x01,        /* Process out-of-band data.  */
//#define MSG_OOB                MSG_OOB
    //MSG_PEEK = 0x02,        /* Peek at incoming messages.  */
//#define MSG_PEEK        MSG_PEEK
    //MSG_DONTROUTE = 0x04,        /* Don't use local routing.  */
//#define MSG_DONTROUTE        MSG_DONTROUTE
#ifdef __USE_GNU
    /* DECnet uses a different name.  */
    MSG_TRYHARD = MSG_DONTROUTE,
# define MSG_TRYHARD        MSG_DONTROUTE
#endif
    //MSG_CTRUNC = 0x08,        /* Control data lost before delivery.  */
//#define MSG_CTRUNC        MSG_CTRUNC
    MSG_PROXY = 0x10,        /* Supply or ask second address.  */
//#define MSG_PROXY        MSG_PROXY
  // MSG_TRUNC = 0x20,
#define MSG_TRUNC        MSG_TRUNC
    MSG_DONTWAIT = 0x40, /* Nonblocking IO.  */
#define MSG_DONTWAIT        MSG_DONTWAIT
    MSG_EOR = 0x80, /* End of record.  */
#define MSG_EOR                MSG_EOR
    //MSG_WAITALL = 0x100, /* Wait for a full request.  */
//#define MSG_WAITALL        MSG_WAITALL
    MSG_FIN = 0x200,
#define MSG_FIN                MSG_FIN
    MSG_SYN = 0x400,
#define MSG_SYN                MSG_SYN
    MSG_CONFIRM = 0x800, /* Confirm path validity.  */
#define MSG_CONFIRM        MSG_CONFIRM
    MSG_RST = 0x1000,
#define MSG_RST                MSG_RST
    //MSG_ERRQUEUE = 0x2000, /* Fetch message from error queue.  */
//#define MSG_ERRQUEUE        MSG_ERRQUEUE
    MSG_NOSIGNAL = 0x4000, /* Do not generate SIGPIPE.  */
#define MSG_NOSIGNAL        MSG_NOSIGNAL
    MSG_MORE = 0x8000,  /* Sender will send more.  */
#define MSG_MORE        MSG_MORE
    MSG_WAITFORONE = 0x10000, /* Wait for at least one packet to return.*/
#define MSG_WAITFORONE        MSG_WAITFORONE
    MSG_BATCH = 0x40000, /* sendmmsg: more messages coming.  */
#define MSG_BATCH        MSG_BATCH
    MSG_ZEROCOPY = 0x4000000, /* Use user data in kernel path.  */
#define MSG_ZEROCOPY        MSG_ZEROCOPY
    MSG_FASTOPEN = 0x20000000, /* Send data in TCP SYN.  */
#define MSG_FASTOPEN        MSG_FASTOPEN
    MSG_CMSG_CLOEXEC = 0x40000000        /* Set close_on_exit for file
                                           descriptor received through
                                           SCM_RIGHTS.  */
#define MSG_CMSG_CLOEXEC MSG_CMSG_CLOEXEC
};