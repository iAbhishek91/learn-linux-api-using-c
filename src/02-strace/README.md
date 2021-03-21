# STRACE

Is a command which allow us to trace the system call made from a program. This is useful in understanding/or for debugging of system programs.

>NOTE: strace is specific to Linux, however other UnIX implementation have its equivalent. For example `truss` on solaris, `ktrace` on BSDs.

## SYNTAX

```sh
strace data
strace cat ./path/to/file.txt
```

## OPTIONS

**-o** - output

This is change the default output(to a stderr) to a file.

```sh
strace -o filename.log command args...
```

**-c** - summary

print a summary of all system calls made by the programs. For each system call below info is printed:

- total number of calls
- number of calls that failed
- total time spent executing the calls.

```sh
strace -c date
# OUTPUT
## Sun 21 Mar 11:30:50 GMT 2021
## % time     seconds  usecs/call     calls    errors syscall
## ------ ----------- ----------- --------- --------- ----------------
##   0.00    0.000000           0         3           read
##   0.00    0.000000           0         1           write
##   0.00    0.000000           0         6           close
##   0.00    0.000000           0         6           fstat
##   0.00    0.000000           0         1           lseek
##   0.00    0.000000           0         6           mmap
##   0.00    0.000000           0         4           mprotect
##   0.00    0.000000           0         1           munmap
##   0.00    0.000000           0         3           brk
##   0.00    0.000000           0         3         3 access
##   0.00    0.000000           0         1           execve
##   0.00    0.000000           0         1           arch_prctl
##   0.00    0.000000           0         4           openat
## ------ ----------- ----------- --------- --------- ----------------
## 100.00    0.000000                    40         3 total
```

**-f**: trace child processes as well

```sh
strace -cf date
# OUTPUT
## Sun 21 Mar 11:34:21 GMT 2021
## % time     seconds  usecs/call     calls    errors syscall
## ------ ----------- ----------- --------- --------- ----------------
##  16.42    0.000177          44         4           mprotect
##  13.45    0.000145          24         6           close
##  12.89    0.000139          23         6           mmap
##  12.24    0.000132          33         4           openat
##  11.22    0.000121         121         1           munmap
##  10.11    0.000109          18         6           fstat
##   6.22    0.000067          22         3           read
##   5.47    0.000059          59         1           write
##   4.92    0.000053          53         1           arch_prctl
##   4.36    0.000047          16         3           brk
##   2.69    0.000029          29         1           lseek
##   0.00    0.000000           0         3         3 access
##   0.00    0.000000           0         1           execve
## ------ ----------- ----------- --------- --------- ----------------
## 100.00    0.001078                    40         3 total
```

**-p**: trace a process id

```sh
sudo strace -p <pid>
# it attaches with the process and prints the trace to the system calls.
```

**-v**: to see entire structure arguments, by default they are abbreviated.

**-s**: increase the default size of 32 characters to more.

**-e**: search for specific events, using system call name, alternative to grep.

> Very important note the name that we mention is not the library function name, but the system call name. It may be different from library function name. For example library function exec() it calling execve() system call and that should be mentioned with -e option.

```sh
strace -e trace=openat,close date
```

## How to read strace output

- Each system call is displayed as a function call.
- It displays both input and output arguments shown in the parentheses.
- Arguments are printed as symbolic forms.
- Use -v and -s to have a full glance at the structure and string arguments.
- After the arguments, strace prints = followed by a number, which represents return value of the system calls.
- The symbolic errno value is also displayed.
- Strace produces large volume of logs, hence its better to use grep to search for specific system call you are interested in , like below

```sh
strace -v date 2>&1 | grep open
```

```sh
# EXAMPLE OUTPUT
## access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
## access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
## openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
## mmap(0x7f4eebd07000, 15072, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f4eebd07000
## close(3)                                = 0
## arch_prctl(ARCH_SET_FS, 0x7f4eebf1e540) = 0
```
