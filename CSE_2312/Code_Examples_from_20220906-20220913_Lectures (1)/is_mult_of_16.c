#// CSE 2312 Computer Org and Assembly Language Programming
// is_mult_of example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types
#include <stdbool.h>  // C99 bool

extern bool isMultOf16(uint32_t x);

int main()
{
    uint32_t x;
    x = 15;
    if (isMultOf16(x))
        printf("%"PRIu32" is mult of 16\n", x);
    else
        printf("%"PRIu32" is not a mult of 16\n", x);
    x = 32;
    if (isMultOf16(x))
        printf("%"PRIu32" is mult of 16\n", x);
    else
        printf("%"PRIu32" is not a mult of 16\n", x);
    x = 0;
    if (isMultOf16(x))
        printf("%"PRIu32" is mult of 16\n", x);
    else
        printf("%"PRIu32" is not a mult of 16\n", x);
        
    return EXIT_SUCCESS;
}

