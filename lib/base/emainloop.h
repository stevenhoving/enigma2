#pragma once

#include <lib/base/eptrlist.h>
#include <lib/python/python.h>
#include <sys/poll.h>
#include <map>

class eTimer;
class eSocketNotifier;

class eMainloop
{
    friend class eTimer;
    friend class eSocketNotifier;

    std::map<int, eSocketNotifier*> notifiers;
    ePtrList<eTimer> m_timer_list;
    bool app_quit_now;
    int retval;
    eSocketNotifier *m_inActivate;
    int m_interrupt_requested;
    timespec m_twisted_timer;

    /* user_timeout < 0 - forever
     * user_timeout = 0 - immediately
     * user_timeout > 0 - wait
     */
    int processOneEvent(long user_timeout, PyObject **res = 0, ePyObject additional = ePyObject());

    void addSocketNotifier(eSocketNotifier *sn);
    void removeSocketNotifier(eSocketNotifier *sn);
    void addTimer(eTimer* e);
    void removeTimer(eTimer* e);

    static ePtrList<eMainloop> existing_loops;
    static bool isValid(eMainloop *);
public:
    eMainloop()
        : app_quit_now(0)
        , retval(0)
        , m_inActivate(0)
        , m_interrupt_requested(0)
    {
        existing_loops.push_back(this);
    }
    virtual ~eMainloop();

#ifndef SWIG
    void quit(int ret = 0); // leave all pending loops (recursive leave())
#endif

    /* a user supplied timeout. enter_loop will return with:
        0 - no timeout, no signal
        1 - timeout
        2 - signal
    */
    int iterate(unsigned int timeout = 0, PyObject **res = 0, SWIG_PYOBJECT(ePyObject) additional = (PyObject*)0);

    /* run will iterate endlessly until the app is quit, and return
       the exit code */
    int runLoop();

    /* our new shared polling interface. */
    PyObject *poll(SWIG_PYOBJECT(ePyObject) dict, SWIG_PYOBJECT(ePyObject) timeout);
    void interruptPoll();
    void reset();

protected:
    virtual int _poll(struct pollfd *fds, nfds_t nfds, int timeout);
};
