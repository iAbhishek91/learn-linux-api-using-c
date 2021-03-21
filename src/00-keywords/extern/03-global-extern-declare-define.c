#include <stdio.h>

extern int var;

void main(){
    int var = 10; // note, we need to define the data type again
    printf("%d", var); // OUTPUT: 10
}