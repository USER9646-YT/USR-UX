#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "../include/shell.h"
#include "../include/tanja.h"
#include "../include/fs.h"
#include "../include/store.h"
#include "../include/idt.h"
#include "../include/utf8.h"

void setup_wizard() {
    print("Starting setup...\n\n");
    print("===== USR/UX Setup =====\n");
    print("\n");
    print("Create a login: "); read_line(config.username, MAX_USERNAME);
    print("Create a password: "); read_line(config.password, MAX_PASSWORD);
    print("Set a hostname: "); read_line(config.hostname, MAX_HOSTNAME);
    config.is_setup = 1; print("\n");
}
