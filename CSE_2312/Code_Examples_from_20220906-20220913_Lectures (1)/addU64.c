// CSE 2312 Computer Org and Assembly Language Programming
// addU64 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

extern uint64_t addU64(uint64_t x, uint64_t y);

int main()
{
    uint64_t x, y, z;
    x = 20000000000;
    y = 30000000000;
    z = addU64(x, y);
    printf("x = %"PRIu64"\n", x);
    printf("y = %"PRIu64"\n", y);
    printf("z = x + y = %"PRIu64"\n", z);
    
    return EXIT_SUCCESS;
}

