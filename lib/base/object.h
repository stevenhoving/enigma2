#ifndef __base_object_h
#define __base_object_h
#include <lib/base/smartptr.h>
#include <lib/base/elock.h>
#include <lib/base/eerror.h>

#ifndef WIN32
#include <ext/atomicity.h>
#else
#include <windows.h>
#endif

#include <assert.h>

using ssize_t = int64_t;

typedef int RESULT;

class iObject
{
private:
		/* we don't allow the default operator here, as it would break the refcount. */
	void operator=(const iObject &);
protected:
#ifdef SWIG
	virtual void AddRef()=0;
	virtual void Release()=0;
#endif
public:
    //void operator delete(void *p) { ::operator delete(p); }
    virtual ~iObject() { }

#ifndef SWIG
	virtual void AddRef()=0;
	virtual void Release()=0;
#endif
};



#ifndef SWIG

#ifdef WIN32

class oRefCount
{
    mutable LONG ref;
public:
    oRefCount()
        : ref(0)
    {}

    int operator++()
    {
        return InterlockedIncrement(&ref) + 1;
        //return __gnu_cxx::__exchange_and_add(&ref, 1) + 1;
    }

    int operator--()
    {
        return InterlockedDecrement(&ref) - 1;
        //return __gnu_cxx::__exchange_and_add(&ref, -1) - 1;
    }

    operator int() const
    {
        //return __gnu_cxx::__exchange_and_add(&ref, 0);
        return InterlockedAdd(&ref, 0);
    }
};

#else


class oRefCount
{
	mutable _Atomic_word ref;
public:
	oRefCount(): ref(0) {}

	int operator++()
	{
		return __gnu_cxx::__exchange_and_add(&ref, 1) + 1;
	}

	int operator--()
	{
		return __gnu_cxx::__exchange_and_add(&ref, -1) - 1;
	}

	operator int() const
	{
		return __gnu_cxx::__exchange_and_add(&ref, 0);
	}
};

#endif

#define DECLARE_REF(x) 			\
    public: \
		    void AddRef(); 		\
		    void Release();		\
    private:\
		    oRefCount ref;

#define DEFINE_REF(c) \
    void c::AddRef() \
    { \
	    ++ref; \
    } \
    void c::Release() \
    { \
	    if (!(--ref)) \
		    delete this; \
    }

#else  // SWIG
#define DECLARE_REF(x) \
	private: \
		void AddRef(); \
		void Release();
#endif  // SWIG

#endif  // __base_object_h
