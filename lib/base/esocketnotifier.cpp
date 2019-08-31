#include <lib/base/esocketnotifier.h>
#include <lib/base/emainloop.h>

DEFINE_REF(eSocketNotifier);

eSocketNotifier::eSocketNotifier(eMainloop *context, int fd, int requested, bool startnow)
    : context(*context)
    , fd(fd)
    , state(0)
    , requested(requested)
{
    if (startnow)
        start();
}

eSocketNotifier::~eSocketNotifier()
{
    stop();
}

void eSocketNotifier::start()
{
    if (state)
        stop();

    if (eMainloop::isValid(&context))
    {
        context.addSocketNotifier(this);
        state = 2;  // running but not in poll yet
    }
}

void eSocketNotifier::stop()
{
    if (state)
    {
        state = 0;
        context.removeSocketNotifier(this);
    }
}
