# USR/UX // A TanjaOS distro

### Contents

1 - What is USR/UX?

-  1.1 - What is so different about USR/UX?

2 - How to compile

3 - Compiling stuff inside the OS

## What is USR/UX?

USR/UX, as said before, is a TanjaOS distro/fork. It was made with the purpose of making TanjaOS behave a bit more closer to UNIX-like OSes, albeit a bit unconventional and not really in a POSIX-ish way.

### What is so different about USR/UX?

It contains these directories that TanjaOS does not have:
- /usr/ (Unix System Resources)
- /usr/bin (User-made programs)
- /etc/ (System variables)
- /sys/ (Other System stuff)
- /tmp/ (Temporary)

It also has some other things, that TanjaOS does not have, like:
- Seperated shell, login and kernel (less of a security risk)
- Primitive Semi-Init-system, called via `init()` that starts up login and then shell.

## How to compile
Remove the empty files in home/usr/bin and home/usr/src, they keep the folders intact while committing to git. Then after that:

Use 'make' to compile (this compiles the source, all bin/ commands, and
TinyCC - nothing else). Once compiling is finished, a bootable OS
image 'tanja-base' will be located at arch/x86/boot, boot it with:

    qemu-system-i386 -m 64 -kernel arch/x86/boot/tanja-base

But, if you want a bootable ISO file, do this:
`make iso`

On the root directory of the project, usr-ux.iso will appear.

make, nasm, gcc, xorriso and grub-mkrescue are needed. (xorriso and grub-mkrescue is only necessary if you want to make a ISO file).

And for the BSD users, sadly the BSD makefile will not work since i didnt really change it at all.

## Compiling stuff inside the OS

There is already a `*.c` file named `hello.c` as a example.

Do this if you want to compile it: 
    
    tcc -c hello.c -o hello.o      # compile
    
    mv hello.o /usr/bin/           # move
    
    hello some args                # run
