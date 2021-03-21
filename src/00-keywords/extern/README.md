# extern

## Understanding declaration and definition

**Declaration**: declaration is defining variable or functions where tell different aspect of variable or function. Note the important different between declaration and definition is that memory is not allocated while variable or function is declared.

**Definition**: is same as declaration, however memory is allocated to functions or variable.

## extern, what it does

Extern keyword extends the visibility of function and variable to the whole program.

## Functions and extern

Every functions are extern in nature. Hence below are equal

```c
int foo(int a, int b);
extern int foo(int a, int b);
```

Hence, function can be called anywhere in any of the files of the whole program. If declaration of the function in place, the compiler knows the definition of the function exists somewhere else and it goes ahead and compiles the files.

## Variable and extern

Unlike functions, variables are always defined, until and unless extern is used.

When we use extern, the variable is only declared and not defined(memory is NOT assigned).

```c
extern int var; // no memory is not allocated so far, and we can declare as many times as we want.
int var;
```

With extern keyword we can use the variable anywhere in the program we include its declaration the variable is defined somewhere.
