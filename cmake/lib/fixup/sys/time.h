#pragma once

/* this is incorrect, because clock_gettime should actually be located in the real time.h*/
#include <windows.h>
#include <time.h>

// pointless defines... but for compatibility.
#define CLOCK_REALTIME			0
#define CLOCK_MONOTONIC			1
#define CLOCK_PROCESS_CPUTIME_ID	2
#define CLOCK_THREAD_CPUTIME_ID		3
#define CLOCK_MONOTONIC_RAW		4
#define CLOCK_REALTIME_COARSE		5
#define CLOCK_MONOTONIC_COARSE		6
#define CLOCK_BOOTTIME			7
#define CLOCK_REALTIME_ALARM		8
#define CLOCK_BOOTTIME_ALARM		9

static LARGE_INTEGER getFILETIMEoffset()
{
    SYSTEMTIME s;
    FILETIME f;
    LARGE_INTEGER t;

    s.wYear = 1970;
    s.wMonth = 1;
    s.wDay = 1;
    s.wHour = 0;
    s.wMinute = 0;
    s.wSecond = 0;
    s.wMilliseconds = 0;
    SystemTimeToFileTime(&s, &f);
    t.QuadPart = f.dwHighDateTime;
    t.QuadPart <<= 32;
    t.QuadPart |= f.dwLowDateTime;
    return (t);
}

static int clock_gettime(int X, struct timespec *tv)
{
    LARGE_INTEGER           t;
    FILETIME            f;
    double                  nanoseconds;
    static LARGE_INTEGER    offset;
    static double           frequencyToNanoseconds;
    static int              initialized = 0;
    static BOOL             usePerformanceCounter = 0;

    if (!initialized) {
        LARGE_INTEGER performanceFrequency;
        initialized = 1;
        usePerformanceCounter = QueryPerformanceFrequency(&performanceFrequency);
        if (usePerformanceCounter) {
            QueryPerformanceCounter(&offset);
            frequencyToNanoseconds = (double)performanceFrequency.QuadPart / 1000.;
        }
        else {
            offset = getFILETIMEoffset();
            frequencyToNanoseconds = 10.;
        }
    }
    if (usePerformanceCounter) QueryPerformanceCounter(&t);
    else {
        GetSystemTimeAsFileTime(&f);
        t.QuadPart = f.dwHighDateTime;
        t.QuadPart <<= 32;
        t.QuadPart |= f.dwLowDateTime;
    }

    t.QuadPart -= offset.QuadPart;
    nanoseconds = (double)t.QuadPart / frequencyToNanoseconds;
    t.QuadPart = nanoseconds;
    tv->tv_sec = t.QuadPart / 1000000000;
    tv->tv_nsec = t.QuadPart % 1000000000;
    return (0);
}