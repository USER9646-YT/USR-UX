#ifndef MINAPI_H
#define MINAPI_H

// Mini API so that some stuff does not interfere with the normal Tanja API. Basically useless

#include <stdint.h>
#include <stddef.h>

#include "fs.h"

extern void print(const char* s);
extern int printf(const char* fmt, ...);

#endif
