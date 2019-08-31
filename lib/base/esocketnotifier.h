#pragma once

#ifndef SWIG

#include <lib/base/object.h>
#include <lib/base/eptrlist.h>
#include <lib/python/connections.h>
#include <sys/poll.h>

class eMainloop;

/**
 * \brief Gives a callback when data on a file descriptor is ready.
 *
 * This class emits the signal \c eSocketNotifier::activate whenever the
 * event specified by \c req is available.
 */
class eSocketNotifier : iObject
{
    DECLARE_REF(eSocketNotifier);
    friend class eMainloop;
public:
    enum { Read = POLLIN, Write = POLLOUT, Priority = POLLPRI, Error = POLLERR, Hungup = POLLHUP };
private:
    eMainloop &context;
    int fd;
    int state;
    int requested;

    void activate(int what) { /*emit*/ activated(what); }
    eSocketNotifier(eMainloop *context, int fd, int req, bool startnow);
public:
    /**
     * \brief Constructs a eSocketNotifier.
     * \param context The thread where to bind the socketnotifier to. The signal is emitted from that thread.
     * \param fd The filedescriptor to monitor. Can be a device or a socket.
     * \param req The events to watch to, normally either \c Read or \c Write. You can specify any events that \c poll supports.
     * \param startnow Specifies if the socketnotifier should start immediately.
     */
    static eSocketNotifier* create(eMainloop *context, int fd, int req, bool startnow = true)
    {
        return new eSocketNotifier(context, fd, req, startnow);
    }

    ~eSocketNotifier();

    PSignal1<void, int> activated;

    void start();
    void stop();
    bool isRunning() const { return state != 0; }

    int getFD() const { return fd; }
    int getRequested() const { return requested; }
    void setRequested(int req) { requested = req; }

    /* Only eConsoleAppContainer uses this, purpose unknown */
    eSmartPtrList<iObject> m_clients;
};

#endif
