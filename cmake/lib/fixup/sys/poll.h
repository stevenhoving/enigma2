#pragma once

//#include <poll.h>

/* These are specified by iBCS2 */
#define POLLIN		0x0001
#define POLLPRI		0x0002
#define POLLOUT		0x0004
#define POLLERR		0x0008
#define POLLHUP		0x0010
#define POLLNVAL	0x0020

struct pollfd
{
    int fd;
    short events;
    short revents;
};

using nfds_t = unsigned int;


int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    printf("poll called\n");
    // don't do shit
    return 0;
}



//#define _GNU_SOURCE         /* See feature_test_macros(7) */
//#include <signal.h>
//#include <poll.h>

//int ppoll(struct pollfd *fds, nfds_t nfds,
//    const struct timespec *tmo_p, const sigset_t *sigmask);