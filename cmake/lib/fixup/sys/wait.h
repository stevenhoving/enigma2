#pragma once

#include <sys/types.h>

#ifdef _POSIX_SOURCE
#define	_W_INT(i)	(i)
#else
#define	_W_INT(w)	(*(int *)&(w))	/* convert union wait to int */
#define	WCOREFLAG	0200
#endif

#define	_WSTATUS(x)	(_W_INT(x) & 0177)
#define	_WSTOPPED	0177		/* _WSTATUS if process is stopped */
#define WIFSTOPPED(x)	(_WSTATUS(x) == _WSTOPPED)
#define WSTOPSIG(x)	(_W_INT(x) >> 8)
#define WIFSIGNALED(x)	(_WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0)
#define WTERMSIG(x)	(_WSTATUS(x))
#define WIFEXITED(x)	(_WSTATUS(x) == 0)
#define WEXITSTATUS(x)	(_W_INT(x) >> 8)
//#ifndef _POSIX_SOURCE
#define WCOREDUMP(x)	(_W_INT(x) & WCOREFLAG)

//#define _LOW(v)		( (v) & 0377)
//#define _HIGH(v)	( ((v) >> 8) & 0377)
///* options for waitpid, WUNTRACED not supported */
//#define WNOHANG		1
//#define WUNTRACED	2
//#define WIFEXITED(s)	(!((s)&0xFF)
//#define WIFSTOPPED(s)	(((s)&0xFF)==0x7F)
//#define WEXITSTATUS(s)	(((s)>>8)&0xFF)
//#define WTERMSIG(s)	((s)&0x7F)
//#define WSTOPSIG(s)	(((s)>>8)&0xFF)
//#define WIFSIGNALED(s)	(((unsigned int)(s)-1 & 0xFFFF) < 0xFF)

static pid_t wait(int *status)
{
    printf("wait\n");
    return 0;
}

static pid_t waitpid(pid_t pid, int *status, int options)
{
    printf("waitpid\n");
    return pid;
}