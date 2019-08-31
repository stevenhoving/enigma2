#include <lib/base/ebase.h>

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <lib/base/eerror.h>
#include <lib/base/elock.h>
#include <lib/gdi/grc.h>

int eApplication::_poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	int result;

	m_is_idle = 1;
	++m_idle_count;
	/* Py_BEGIN_ALLOW_THREADS contains a memory barrier, and that will
	 * make the idleCount() and isIdle() interfaces work properly */
	Py_BEGIN_ALLOW_THREADS
	result = ::poll(fds, nfds, timeout);
	Py_END_ALLOW_THREADS
	m_is_idle = 0;

	return result;
}

eApplication* eApp = nullptr;
