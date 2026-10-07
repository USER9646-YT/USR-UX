#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "../include/shell.h"
#include "../include/tanja.h"
#include "../include/fs.h"
#include "../include/store.h"
#include "../include/idt.h"
#include "../include/utf8.h"

// man fuck this shit

void shell() {
    printf("If you see this, the shell is now officially seperated from the kernel\n");
    shell_exit_flag = 0; static char buf[INPUT_BUFFER_SIZE];
    while (1) {
        print(config.username); print("@"); print(config.hostname); print(":");
        print_prompt_path();
        /* root uses #, all other users use $. */
        if (streq(config.username, "root")) print("# ");
        else print("$ ");
        read_line(buf, 4096); clean(buf);
        {
            int bl = strlen(buf);
            if (bl > 0 && buf[bl - 1] == 4) {
                buf[bl - 1] = 0;
                if (buf[0] == 0) { print("exit\n"); shell_exit_flag = 1; }
            }
        }
        if (buf[0]) execute_command(buf);
        if (shell_exit_flag) { clear_screen(); break; }
    }
}

