#include <lib/base/etimer.h>
#include <lib/base/emainloop.h>
#include <lib/base/etime.h>

DEFINE_REF(eTimer);

bool eTimer::needsActivation(const timespec &now)
{
    return nextActivation <= now;
}

bool eTimer::needsActivation()
{
    timespec now; clock_gettime(CLOCK_MONOTONIC, &now); return nextActivation <= now;
}

void eTimer::start(long msek, bool singleShot)
{
    if (bActive)
        stop();

    if (eMainloop::isValid(&context))
    {
        bActive = true;
        bSingleShot = singleShot;
        interval = msek;
        clock_gettime(CLOCK_MONOTONIC, &nextActivation);
        //		eDebug("[eTimer] this = %p\nnow sec = %d, nsec = %d\nadd %d msec", this, nextActivation.tv_sec, nextActivation.tv_nsec, msek);
        nextActivation += (msek < 0 ? 0 : msek);
        //		eDebug("[eTimer] next Activation sec = %d, nsec = %d", nextActivation.tv_sec, nextActivation.tv_nsec );
        context.addTimer(this);
    }
}

void eTimer::startLongTimer(int seconds)
{
    if (bActive)
        stop();

    if (eMainloop::isValid(&context))
    {
        bActive = bSingleShot = true;
        interval = 0;
        clock_gettime(CLOCK_MONOTONIC, &nextActivation);
        //		eDebug("[eTimer] this = %p\nnow sec = %d, nsec = %d\nadd %d sec", this, nextActivation.tv_sec, nextActivation.tv_nsec, seconds);
        if (seconds > 0)
            nextActivation.tv_sec += seconds;
        //		eDebug("[eTimer] next Activation sec = %d, nsec = %d", nextActivation.tv_sec, nextActivation.tv_nsec );
        context.addTimer(this);
    }
}

bool eTimer::operator<(const eTimer& t) const
{
    return nextActivation < t.nextActivation;
}

void eTimer::stop()
{
    if (bActive)
    {
        bActive = false;
        context.removeTimer(this);
    }
}

void eTimer::changeInterval(long msek)
{
    if (bActive)  // Timer is running?
    {
        context.removeTimer(this);	 // then stop
        nextActivation -= interval;  // sub old interval
    }
    else
        bActive = true; // then activate Timer

    interval = msek;   			 			// set new Interval
    nextActivation += interval;		// calc nextActivation

    context.addTimer(this);				// add Timer to context TimerList
}

void eTimer::activate()   // Internal Funktion... called from eApplication
{
    /* timer has already been removed from the context, when activate is called */

    if (!bSingleShot)
    {
        nextActivation += interval;
        context.addTimer(this);
    }
    else
        bActive = false;

    /*emit*/ timeout();
}