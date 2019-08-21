#ifndef __elock_h
#define __elock_h

#include <mutex>
#include <condition_variable>

#if 0
class eCondition
{
private:
	eCondition(const eCondition&);
protected:
	pthread_cond_t m_cond;
public:
	eCondition()
	{
		pthread_cond_init(&m_cond, 0);
	}
	~eCondition()
	{
		pthread_cond_destroy(&m_cond);
	}
	void signal()
	{
		pthread_cond_signal(&m_cond);
	}
	void wait(pthread_mutex_t& mutex)
	{
		pthread_cond_wait(&m_cond, &mutex);
	}
	operator pthread_cond_t&() { return m_cond; }
};


class std::scoped_lock<std::mutex>
{
protected:
	estd::scoped_lock<std::mutex> &m_lock;
public:
	std::scoped_lock<std::mutex>(estd::scoped_lock<std::mutex> &m)
		: m_lock(m)
	{
		m_lock.lock();
	}
	~std::scoped_lock<std::mutex>()
	{
		m_lock.unlock();
	}
};

#endif

class eLock
{
	std::mutex mutex;
	std::condition_variable cond;

	int counter, max;
public:
	void lock(int res=100);
	void unlock(int res=100);

	eLock(int max=100);
	~eLock();
};


class eSemaphore
{
	int v;
	std::mutex mutex;
	std::condition_variable cond;
public:
	eSemaphore();
	~eSemaphore();

	void down();
	void decrement();
	void up();
	int value();
};

#endif
