#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "../include/shell.h"
#include "../include/tanja.h"
#include "../include/fs.h"
#include "../include/store.h"
#include "../include/idt.h"
#include "../include/utf8.h"

// Init system for USR/UX or TanjaOS
// By USER9646, under GNU GPLv3

void init(){
    boot_log("UserInit v1.00 is starting USR/UX...\n");
    while (1)
    {
        print("The USR/UX Project \n\n");

        login_prompt();

        /* A login always starts in the user's home directory
         * (/home/home).  The filesystem persists cwd for storage, but
         * cwd is a shell-session state and should not leak from a
         * previous login/reboot. */
        if (fs_change_directory("/home") != 0)
            fs_change_directory("/");

        shell();
    }
}
