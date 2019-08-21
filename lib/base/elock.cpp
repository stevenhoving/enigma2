#include <lib/base/elock.h>
#include <unistd.h>

void eLock::lock(int res)
{
	if (res>max)
		res=max;

    std::unique_lock<std::mutex> slock(mutex);
    while ((counter + res) > max)
        cond.wait(slock);
	counter+=res;
}

void eLock::unlock(int res)
{
	if (res>max)
		res=max;
    {
        std::unique_lock<std::mutex> slock(mutex);
        counter -= res;
    }
    cond.notify_all();
}

eLock::eLock(int max)
    : max(max)
{
	counter=0;
}

eLock::~eLock() = default;

eSemaphore::eSemaphore()
{
	v=1;
}

eSemaphore::~eSemaphore() = default;

void eSemaphore::down()
{
    std::unique_lock<std::mutex> lock(mutex);
    while (v <= 0)
    {
        cond.wait(lock);
    }
    v--;

}

void eSemaphore::decrement()
{
    {
        std::scoped_lock<std::mutex> lock(mutex);
        v--;
    }

    cond.notify_one();
}

void eSemaphore::up()
{
    {
        std::scoped_lock<std::mutex> lock(mutex);
        v++;
    }

    cond.notify_one();
}

int eSemaphore::value()
{
	int value_after_op;

    {
        std::scoped_lock<std::mutex> lock(mutex);
        value_after_op = v;
    }
	return value_after_op;
}

