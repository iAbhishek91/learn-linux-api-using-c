#include <stdio.h>

extern int var;// only declared but never used, hence no compilation issue
int main() {
    printf(" variable is not used "); // OUTPUT: variable is not used
}