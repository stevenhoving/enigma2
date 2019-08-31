#pragma once

#include <lib/base/object.h>
#include <lib/base/ebase.h>
#include <lib/python/connections.h>

#ifndef SWIG

/**
 * \brief Gives a callback after a specified timeout.
 *
 * This class emits the signal \c eTimer::timeout after the specified timeout.
 */
class eTimer : iObject
{
    DECLARE_REF(eTimer);
    friend class eMainloop;

    eMainloop &context;
    timespec nextActivation;
    long interval;
    bool bSingleShot;
    bool bActive;

    void activate();
    eTimer(eMainloop *context)
        : context(*context)
        , bActive(false)
    {}
public:
    /**
     * \brief Constructs a timer.
     *
     * The timer is not yet active, it has to be started with \c start.
     * \param context The thread from which the signal should be emitted.
     */
    static eTimer *create(eMainloop *context = eApp) { return new eTimer(context); }
    ~eTimer() { if (bActive) stop(); }

    PSignal0<void> timeout;

    bool isActive() { return bActive; }

    timespec &getNextActivation() { return nextActivation; }
    bool needsActivation(const timespec &now);
    bool needsActivation();

    void start(long msec, bool b = false);
    void stop();
    void changeInterval(long msek);
    void startLongTimer(int seconds);
    bool operator<(const eTimer& t) const;
};
#endif  // SWIG