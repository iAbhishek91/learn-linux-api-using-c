# Command line arguments

Generally C program main function takes in two argument **argc** and **argv**. Which keeps the count of the argument that are passed while executing a program, and what are the values of each one of them.

However, they are not enough to implement default UNIX default behavior of CLI, like:

- options are initialized by "-", followed by a letter.
- multiple options can be combined together.
- many options takes in arguments, so while combining we have to make sure that the last options are the one which takes the arguments.

Hence, to implement this a library function is available: `getopt()`.

> Refer: ./src/03-cmd-line-args/00-c-argc-argv.c WITHOUT getopt()

```sh
./a a b c d e f g
# OUTPUT:
## value: a
## value: b
## value: c
## value: d
## value: e
## value: f
## value: g
```

