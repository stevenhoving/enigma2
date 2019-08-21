#pragma once

#include <sys/signal.h>

// just don't do squad
inline int ioctl(int fd, unsigned long request, ...)
{
    return 0;
}
