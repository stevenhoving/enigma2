#pragma once

#include <unistd.h>
#include <fcntl.h>

static int fcntl(int fd, int cmd, ... /* arg */)
{
    printf("fcntl\n");
    return 0;
}