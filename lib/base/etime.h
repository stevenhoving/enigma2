#pragma once

#include "gettime.h"

#ifndef SWIG
/* TODO: remove these inlines. */
static inline bool operator<(const timespec &t1, const timespec &t2)
{
    return t1.tv_sec < t2.tv_sec || (t1.tv_sec == t2.tv_sec && t1.tv_nsec < t2.tv_nsec);
}

static inline bool operator<=(const timespec &t1, const timespec &t2)
{
    return t1.tv_sec < t2.tv_sec || (t1.tv_sec == t2.tv_sec && t1.tv_nsec <= t2.tv_nsec);
}

static inline timespec &operator+=(timespec &t1, const timespec &t2)
{
    t1.tv_sec += t2.tv_sec;
    if ((t1.tv_nsec += t2.tv_nsec) >= 1000000000)
    {
        t1.tv_sec++;
        t1.tv_nsec -= 1000000000;
    }
    return t1;
}

static inline timespec operator+(const timespec &t1, const timespec &t2)
{
    timespec tmp;
    tmp.tv_sec = t1.tv_sec + t2.tv_sec;
    if ((tmp.tv_nsec = t1.tv_nsec + t2.tv_nsec) >= 1000000000)
    {
        tmp.tv_sec++;
        tmp.tv_nsec -= 1000000000;
    }
    return tmp;
}

static inline timespec operator-(const timespec &t1, const timespec &t2)
{
    timespec tmp;
    tmp.tv_sec = t1.tv_sec - t2.tv_sec;
    if ((tmp.tv_nsec = t1.tv_nsec - t2.tv_nsec) < 0)
    {
        tmp.tv_sec--;
        tmp.tv_nsec += 1000000000;
    }
    return tmp;
}

static inline timespec operator-=(timespec &t1, const timespec &t2)
{
    t1.tv_sec -= t2.tv_sec;
    if ((t1.tv_nsec -= t2.tv_nsec) < 0)
    {
        t1.tv_sec--;
        t1.tv_nsec += 1000000000;
    }
    return t1;
}

static inline timespec &operator+=(timespec &t1, const long msek)
{
    t1.tv_sec += msek / 1000;
    if ((t1.tv_nsec += (msek % 1000) * 1000000) >= 1000000000)
    {
        t1.tv_sec++;
        t1.tv_nsec -= 1000000000;
    }
    return t1;
}

static inline timespec operator+(const timespec &t1, const long msek)
{
    timespec tmp;
    tmp.tv_sec = t1.tv_sec + msek / 1000;
    if ((tmp.tv_nsec = t1.tv_nsec + (msek % 1000) * 1000000) >= 1000000000)
    {
        tmp.tv_sec++;
        tmp.tv_nsec -= 1000000;
    }
    return tmp;
}

static inline timespec operator-(const timespec &t1, const long msek)
{
    timespec tmp;
    tmp.tv_sec = t1.tv_sec - msek / 1000;
    if ((tmp.tv_nsec = t1.tv_nsec - (msek % 1000) * 1000000) < 0)
    {
        tmp.tv_sec--;
        tmp.tv_nsec += 1000000000;
    }
    return tmp;
}

static inline timespec operator-=(timespec &t1, const long msek)
{
    t1.tv_sec -= msek / 1000;
    if ((t1.tv_nsec -= (msek % 1000) * 1000000) < 0)
    {
        t1.tv_sec--;
        t1.tv_nsec += 1000000000;
    }
    return t1;
}

static inline long timeout_usec(const timespec & orig)
{
    timespec now, diff;
    clock_gettime(CLOCK_MONOTONIC, &now);
    diff = orig - now;
    if (diff.tv_sec > 2000)
        return 2000 * 1000 * 1000;
    return diff.tv_sec * 1000000 + diff.tv_nsec / 1000;
}

#endif