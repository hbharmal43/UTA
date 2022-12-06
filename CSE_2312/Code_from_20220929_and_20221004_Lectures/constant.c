// CSE 2312 Computer Org and Assembly Language Programming
// constant example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

uint32_t getConstantU32();
int32_t getConstantS32();

int main(void)
{
    uint32_t a = getConstantU32();
    int32_t b = getConstantS32();
    printf("a = 0x%08"PRIu32"\n", a);
    printf("a = %"PRIu32"\n", a);
    printf("b = %"PRId32"\n", b);
        
    return EXIT_SUCCESS;
}

