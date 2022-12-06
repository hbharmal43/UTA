// CSE 2312 Computer Org and Assembly Language Programming
// arrays example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

// Pass an array in x[], scale it by scale, return y[]
// for all i = 0... count-1: y[i] = x[i] * scale;
extern void scaleU32(uint32_t y[], const uint32_t x[], uint32_t scale, uint32_t count);

// Pass arrays in x[] and y[], return dot product
// for all sum = {i = 0... count-1} x[i] * y[i]
extern uint32_t dotpU32(const uint32_t x[], const uint32_t y[], uint32_t count);

#define COUNT 5
int main(void)
{
    uint32_t x[COUNT] = {1, 2, 3, 4, 5};
    uint32_t z[COUNT] = {2, 3, 4, 5, 6};
    uint32_t y[COUNT];
    uint32_t a = 10;
    uint32_t i;
    uint32_t prod;
    printf("a = %"PRIu32"\n", a);
    for (i = 0; i < COUNT; i++)
        printf("x[%"PRIu32"] = %"PRIu32"\n", i, x[i]);
    scaleU32(y, x, a, COUNT);
    for (i = 0; i < COUNT; i++)
        printf("y[%"PRIu32"] = %"PRIu32"\n", i, y[i]);
        
    for (i = 0; i < COUNT; i++)
        printf("x[%"PRIu32"] = %"PRIu32"\n", i, x[i]);
    for (i = 0; i < COUNT; i++)
        printf("z[%"PRIu32"] = %"PRIu32"\n", i, z[i]);
    prod = dotpU32(x, z, COUNT);
    printf("product = %"PRIu32"\n", prod);
    
    return EXIT_SUCCESS;
}
