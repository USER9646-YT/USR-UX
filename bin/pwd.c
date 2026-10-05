#include <stdint.h>
#include <stddef.h>
#include "../usr/lib/tanja.h"
#include "../usr/lib/utf8.h"

void main(char* args) {
    (void)args;
    
    char path[256];
    fs_get_current_path(path);
    print(path);
    print("\n");
}

