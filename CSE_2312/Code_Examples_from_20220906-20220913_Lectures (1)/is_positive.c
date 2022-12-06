// CSE 2312 Computer Org and Assembly Language Programming
// is_positive example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types
#include <stdbool.h>  // C99 bool

extern bool isPositiveU32(uint32_t x);
extern bool isPositiveS32(int32_t x);

int main(void)
{
    uint32_t x;
    x = 2;
    if (isPositiveU32(x))
        printf("x = %"PRIu32" is positive\n", x);
    else
        printf("x = %"PRIu32" is not positive (zero)\n", x);        

    x = 0;
    if (isPositiveU32(x))
        printf("x = %"PRIu32" is positive\n", x);
    else
        printf("x = %"PRIu32" is not positive (zero)\n", x);        

    int32_t y;
    y = 2;
    if (isPositiveS32(y))
        printf("y = %"PRId32" is positive\n", y);
    else
        printf("y = %"PRId32" is not positive\n", y);        

    y = 0;
    if (isPositiveS32(y))
        printf("y = %"PRId32" is positive\n", y);
    else
        printf("y = %"PRId32" is not positive\n", y);        

    y = -2;
    if (isPositiveS32(y))
        printf("y = %"PRId32" is positive\n", y);
    else
        printf("y = %"PRId32" is not positive\n", y);        

    return EXIT_SUCCESS;
}


