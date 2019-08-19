#pragma once

// fake define
#ifndef EFD_CLOEXEC
#define EFD_CLOEXEC 1
#endif

#define EFD_NONBLOCK 2
#define EFD_SEMAPHORE 3


[[maybe_unused]] static int eventfd(unsigned int initval, int flags)
{
    printf("eventfd called\n");
    return 0;
}
