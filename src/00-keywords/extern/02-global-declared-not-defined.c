#include <stdio.h>

extern int var;
void main() {
    printf("%d", var); // this throws error as var is only declared and not defined
}