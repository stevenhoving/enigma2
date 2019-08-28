#pragma once

#include <io.h>
#include <thread>

#define _CRT_DECLARE_NONSTDC_NAMES 1
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define SYS_ioprio_set 30
#define SYS_ioprio_get 31

#define O_RDONLY     _O_RDONLY
#define O_WRONLY     _O_WRONLY
#define O_RDWR       _O_RDWR
#define O_APPEND     _O_APPEND
#define O_CREAT      _O_CREAT
#define O_TRUNC      _O_TRUNC
#define O_EXCL       _O_EXCL
#define O_TEXT       _O_TEXT

#define F_OK	0
#define X_OK	1
#define W_OK	2
#define R_OK	4

#define O_NONBLOCK      0x0004
#define O_CLOEXEC       02000000        /* set close_on_exec */

//#ifndef _O_WRONLY
//#define _O_WRONLY 1
//#endif

#define _O_RDONLY      0x0000  // open for reading only
#define _O_WRONLY      0x0001  // open for writing only
#define _O_RDWR        0x0002  // open for reading and writing
#define _O_APPEND      0x0008  // writes done at eof

#define _O_CREAT       0x0100  // create and open file
#define _O_TRUNC       0x0200  // open and truncate
#define _O_EXCL        0x0400  // open only if file doesn't already exist

#define O_CREAT      _O_CREAT
#define O_TRUNC      _O_TRUNC
#define O_SYNC         0x0800



#ifndef O_WRONLY
#define O_WRONLY     _O_WRONLY
#endif

#ifndef O_WRONLY
#define O_WRONLY     _O_WRONLY
#endif

#ifndef O_RDONLY
#define O_RDONLY     _O_RDONLY
#endif

//#define _O_RDONLY      0x0000  // open for reading only
//#define _O_WRONLY      0x0001  // open for writing only
//#define _O_RDWR        0x0002  // open for reading and writing
//#define _O_APPEND      0x0008  // writes done at eof
//
//#define _O_CREAT       0x0100  // create and open file
//#define _O_TRUNC       0x0200  // open and truncate
//#define _O_EXCL        0x0400  // open only if file doesn't already exist

static unsigned int sleep(unsigned int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    return 0;
}

static unsigned int usleep(unsigned long long usec)
{
    std::this_thread::sleep_for(std::chrono::microseconds(usec));
    return 0;
}

//struct fd_pair {
//    long fd[2];
//};
//struct fd_pair pipe();

/* On all other architectures */
static int pipe(int pipefd[2])
{
    printf("pipe called\n");
    return 0;
}

static int fsync(int fd)
{
    printf("fsync\n");
    return 0;
}

//#define _GNU_SOURCE             /* See feature_test_macros(7) */
//#include <fcntl.h>              /* Obtain O_* constant definitions */
//#include <unistd.h>
//
//int pipe2(int pipefd[2], int flags);


static int nice(int inc)
{
    printf("nice\n");
    return 0;
}

using ssize_t = int64_t;
static ssize_t readlink(const char *pathname, char *buf, size_t bufsiz)
{
    printf("readlink\n");
    return 0;
}

static int ftruncate(int fildes, off_t length)
{
    printf("ftruncate\n");
    return 0;
}