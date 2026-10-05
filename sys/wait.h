#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include "types.h"

// Declare wait function prototype
pid_t wait(int *wstatus);

// Standard posix macros
#define WIFEXITED(status)   (((status) & 0x7f) == 0)
#define WEXITSTATUS(status) (((status) & 0xff00) >> 8)

#endif
