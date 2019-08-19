#pragma once

#include <io.h>

#define F_OK	0
#define X_OK	1
#define W_OK	2
#define R_OK	4

#define O_NONBLOCK      0x0004
#define O_CLOEXEC       02000000        /* set close_on_exec */

#ifndef O_WRONLY
#define O_WRONLY     _O_WRONLY
#endif

#ifndef O_WRONLY
#define O_WRONLY     _O_WRONLY
#endif

#ifndef O_RDONLY
#define O_RDONLY     _O_RDONLY
#endif

//#define _O_RDONLY      0x0000  // open for reading only
//#define _O_WRONLY      0x0001  // open for writing only
//#define _O_RDWR        0x0002  // open for reading and writing
//#define _O_APPEND      0x0008  // writes done at eof
//
//#define _O_CREAT       0x0100  // create and open file
//#define _O_TRUNC       0x0200  // open and truncate
//#define _O_EXCL        0x0400  // open only if file doesn't already exist