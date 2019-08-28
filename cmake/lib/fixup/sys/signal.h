#pragma once

#define SIGUSR1 30	/* user defined signal 1 */
#define SIGUSR2 31	/* user defined signal 2 */

#define __P(argument_list) argument_list

#ifndef _POSIX_SOURCE
typedef	void(*sig_t) __P((int));
#endif

typedef int pid_t;
typedef unsigned int sigset_t;

struct	sigaction {
    void(*sa_handler)(int);	/* signal handler */
    sigset_t sa_mask;		/* signal mask to apply */
    int	sa_flags;		/* see signal options below */
};

//void(*signal __P((int, void(*) __P((int))))) __P((int));
//int	raise __P((int));

#ifndef	_ANSI_SOURCE
int	kill __P((pid_t, int));
int	sigaction __P((int, const struct sigaction *, struct sigaction *));
int	sigpending __P((sigset_t *));
int	sigprocmask __P((int, const sigset_t *, sigset_t *));
int	sigsuspend __P((const sigset_t *));
#endif	/* !_ANSI_SOURCE */
#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
int	killpg __P((pid_t, int));
void	psignal __P((unsigned, const char *));
int	sigblock __P((int));
int	siginterrupt __P((int, int));
int	sigpause __P((int));
int	sigreturn __P((struct sigcontext *));
int	sigsetmask __P((int));
int	sigstack __P((const struct sigstack *, struct sigstack *));
int	sigvec __P((int, struct sigvec *, struct sigvec *));
#endif /* !_ANSI_SOURCE && !_POSIX_SOURCE */
