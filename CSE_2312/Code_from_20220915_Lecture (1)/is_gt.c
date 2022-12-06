// CSE 2312 Computer Org and Assembly Language Programming
// is_gt example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types
#include <stdbool.h>  // C99 bool

extern bool isGtU32(uint32_t x, uint32_t y);
extern bool isGtS32(int32_t x, int32_t y);

int main()
{
    uint32_t x, y;
    x = 4000000000;
    y = 0;
    if (isGtU32(x, y))
        printf("%"PRIu32" > %"PRIu32"\n", x, y);
    else
        printf("%"PRIu32" <= %"PRIu32"\n", x, y);
    x = 3000000000;
    y = 3000000000;
    if (isGtU32(x, y))
        printf("%"PRIu32" > %"PRIu32"\n", x, y);
    else
        printf("%"PRIu32" <= %"PRIu32"\n", x, y);
    x = 2000000000;
    y = 4000000000;
    if (isGtU32(x, y))
        printf("%"PRIu32" > %"PRIu32"\n", x, y);
    else
        printf("%"PRIu32" <= %"PRIu32"\n", x, y);

    int32_t w, z;
    w = 2000000000;
    z = 0;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = 2000000000;
    z = 2000000000;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = 2000000000;
    z = 1000000000;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = -2000000000;
    z = 0;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = -2000000000;
    z = -2000000000;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = -2000000000;
    z = -1000000000;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
    w = 2000000000;
    z = -2000000000;
    if (isGtS32(w, z))
        printf("%"PRId32" > %"PRId32"\n", w, z);
    else
        printf("%"PRId32" <= %"PRId32"\n", w, z);
        
    return EXIT_SUCCESS;
}

