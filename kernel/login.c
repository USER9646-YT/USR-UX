#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "../include/shell.h"
#include "../include/tanja.h"
#include "../include/fs.h"
#include "../include/store.h"
#include "../include/idt.h"
#include "../include/utf8.h"

// man fuck this shit too

void login_prompt() {
    char u[MAX_USERNAME], p[MAX_PASSWORD];
    while (1) {
        print(config.hostname); print(" login: "); read_line(u, MAX_USERNAME);
        print("Password: "); read_line(p, MAX_PASSWORD);
        if (streq(u, config.username) && streq(p, config.password)) { return; }
        print("Login incorrect\n\n");
    }
}
