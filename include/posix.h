// USER9646's posix.h
#ifndef POSIX_H
#define POSIX_H

#include "tanja.h"

// These random bullshits are basically POSIX system calls, or a sad attempt at one (if that distinction matters).

#define UTSNAME_LENGTH 65

struct utsname {
    char sysname[UTSNAME_LENGTH];  // OS name
    char nodename[UTSNAME_LENGTH]; // Hostname
    char release[UTSNAME_LENGTH];  // Kernel release
    char version[UTSNAME_LENGTH];  // Build version
    char machine[UTSNAME_LENGTH];  // Hardware architecture
};

int uname(struct utsname *buf);

// void read(void);

#endif
