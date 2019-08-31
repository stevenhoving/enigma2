#ifndef __ebase_h
#define __ebase_h

#ifndef SWIG
#include <lib/base/emainloop.h>
#include <vector>
#include <map>
#include <sys/poll.h>
#include <sys/time.h>
#include <asm/types.h>
#include <time.h>

#include <lib/base/eptrlist.h>
#include <libsig_comp.h>
#endif

#include <lib/python/connections.h>

class eApplication;
class eMainloop;
class eTimer;

extern eApplication* eApp;

/**
 * \brief The application class.
 *
 * An application provides a mainloop, and runs in the primary thread.
 * You can have other threads, too, but this is the primary one.
 */
class eApplication: public eMainloop
{
	int m_is_idle;
	int m_idle_count;
public:
	eApplication():
		m_is_idle(0), m_idle_count(0)
	{
		if (!eApp)
			eApp = this;
	}
	~eApplication()
	{
		eApp = 0;
	}
	int isIdle() const { return m_is_idle; }
	int idleCount() const { return m_idle_count; }
protected:
	/* override */ int _poll(struct pollfd *fds, nfds_t nfds, int timeout);
};

#endif
