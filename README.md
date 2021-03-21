# Linux and Unix API

## System calls

Are call to the glibc(or any other library functions) wrapper functions(in the user mode). These function inturn calls the Trap handler(common for all system call, and is mostly termed as entry point to Kernel, it does some pre-requisite before calling the system routing. These are like identifying which system routine is called). Ultimately system routine is called and the result is traversed back to the stack (system routine, trap handler, wrapper function, to application program).

### Three main points about system calls

- System calls changes processor state from user mode to kernel mode(this is required to access protected kernel memory).
- System calls are fixed in each operating system(user can add, update or remove them).
- System call have a set of arguments.

### Disadvantage of system call

As we have already seen, each system call goes through a call stack (application program >> wrapper glibc library >> trap function >> finally system routine). This is a appreciable overhead.

## Library Functions

- Library functions are generally function which perform few tasks.
- Library functions are defined by different group of people like glibc | uClibc | diet_libc
- Library functions are which we always use in our application program as they makes system calls if required. Hence application programmer do NOT invoke system call directly.

### How to determine version of glibc

Version can be determined from shell or from program

- **from shell**: execute glibc shared library file as executable. *For example in ubuntu:*

```sh
/lib/x86_64-linux-gnu/libc.so.6 
# OUTPUT:
##GNU C Library (Ubuntu GLIBC 2.27-3ubuntu1.2) stable release version 2.27.
##Copyright (C) 2018 Free Software Foundation, Inc.
##This is free software; see the source for copying conditions.
##There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
##PARTICULAR PURPOSE.
##Compiled by GNU CC version 7.5.0.
##libc ABIs: UNIQUE IFUNC
##For bug reporting instructions, please see:
##<https://bugs.launchpad.net/ubuntu/+source/glibc/+bugs>.

ldd <dynamically liked program> | grep libc
# OUTPUT:
## libc.so.6 => /libc/tls/libc.so.6 (0x4004b000)
```

- **from program**:
  - there are again two way by checking  a constant or by calling a library function. *However due to portability of this constants they are rarely used, the constants are __GLIBC__, __GLIBC_MINOR__*.
  - Library function `gnu_get_libc_version()` to determine the version of libc.
