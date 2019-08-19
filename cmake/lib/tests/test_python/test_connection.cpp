#include <gtest/gtest.h>
#include "lib/python/connections.h"

TEST(connections, test_python_signal_slot)
{
    auto henk = PSignal0<int>();
}

TEST(connections, test_python_signal_slot2)
{
    auto henk = PSignal1<void, int>();
}


class eAUGTable : public sigc::trackable
{
protected:
    void slotTableReady(int)
    {

    }
public:
    virtual ~eAUGTable() {};

    sigc::signal<void(int)> tableReady;

    virtual void getNext(int err) = 0;
};

struct eMainloop;
struct iDVBDemux;
struct iDVBSectionReader;
struct eDVBTableSpec;

template <class Table>
class eAUTable : public eAUGTable
{
    ePtr<Table> current, next;		// current is READY AND ERRORFREE, next is not yet ready
    int first;
    ePtr<iDVBDemux> m_demux;
    ePtr<iDVBSectionReader> m_reader;
    eMainloop *ml;

    /* needed to detect broken table version handling (seen on some m2ts files) */
    struct timespec m_prev_table_update;
    int m_table_cnt;

    void begin(eMainloop *m)
    {
        m_table_cnt = 0;
        ml = m;
        first = 1;
        current = 0;
        next = new Table();
        //CONNECT(next->tableReady, eAUTable::slotTableReady);
    }

public:
    void stop()
    {
        current = next = 0;
        m_demux = 0;
        m_reader = 0;
    }

    int begin(eMainloop *m, const eDVBTableSpec &spec, ePtr<iDVBDemux> demux)
    {
        begin(m);
        m_demux = demux;
        m_reader = 0;
        next->start(demux, spec);
        return 0;
    }

    int begin(eMainloop *m, const eDVBTableSpec &spec, ePtr<iDVBSectionReader> reader)
    {
        begin(m);
        m_demux = 0;
        m_reader = reader;
        next->start(reader, spec);
        return 0;
    }

    int get()
    {
        if (current)
        {
            /*emit*/ tableReady.emit(0);
            return 0;
        }
        else if (!next)
        {
            /*emit*/ tableReady.emit(-1);
            return 0;
        }
        else
            return 1;
    }

    RESULT getCurrent(ePtr<Table> &ptr)
    {
        if (!current)
            return -1;
        ptr = current;
        return 0;
    }

    int ready()
    {
        return !!current;
    }

    void inject(Table *t)
    {
        next = t;
        getNext(0);
    }

    void getNext(int error)
    {
        current = 0;
        if (error)
        {
            next = 0;
            if (first)
                /*emit*/ tableReady.emit(error);
            first = 0;
            return;
        }
        else
            current = next;

        next = 0;
        first = 0;

        ASSERT(current->ready);

        /*emit*/ tableReady.emit(0);

        //eDVBTableSpec spec;
    }
};


