#ifndef __LIBSIG_COMP_H
#define __LIBSIG_COMP_H

#include <sigc++/sigc++.h>

#define CONNECT(_signal, _slot) _signal.connect(sigc::mem_fun(*this, &_slot))
#define CONNECT_EXTRA(_signal, _slot, ...) _signal.connect(bind(sigc::mem_fun(*this, &_slot), __VA_ARGS__))

#endif // __LIBSIG_COMP_H
