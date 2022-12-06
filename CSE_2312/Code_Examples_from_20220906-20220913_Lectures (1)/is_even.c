// CSE 2312 Computer Org and Assembly Language Programming
// is_even example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types
#include <stdbool.h>  // C99 bool

extern bool isEven(uint32_t x);

int main()
{
    uint32_t x;
    x = 2;
    if (isEven(x))
        printf("%"PRIu32" is even\n", x);
    else
        printf("%"PRIu32" is odd\n", x);
    x = 3;
    if (isEven(x))
        printf("%"PRIu32" is even\n", x);
    else
        printf("%"PRIu32" is odd\n", x);
        
    return EXIT_SUCCESS;
}

