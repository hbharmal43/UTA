#// CSE 2312 Computer Org and Assembly Language Programming
// strings concatenate
// T Rosenkrantz

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

extern void strCat(const char first[], const char last[]);

int main(void)
{
    char last[] = "Lastname";
    char str[] = "Hello World!";
    char first[30] = "Firstname ";   // with a 'space' at the end
    strCat(first, last);
    printf("Full Name = %s\n", first);
 return EXIT_SUCCESS;
}


