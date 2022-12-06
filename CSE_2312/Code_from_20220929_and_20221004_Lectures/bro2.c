// CSE 2312 Computer Org and Assembly Language Programming
// bro2 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

extern void uint32ToBinary(char str[], uint32_t x);
extern uint32_t bro32(uint32_t x);
extern uint32_t countOnes32(uint32_t x);
extern uint32_t binaryToUint32(const char str[]);

/*
uint32_t countOnes32(uint32_t x)
{
    uint32_t count = 0; // R0 = 0
    uint32_t mask = 0x80000000; // R2 = 0x80000000
    while(mask != 0)
    {
        if (x & mask) // TST R1, R2
            count++; // R2 += 1
        mask >>= 1;  // MOVS R2, R2, LSR #1
    }
    return count;
}

uint32_t bro32(uint32_t x)
{
    uint32_t result = 0; // R0 = 0
    uint32_t test_mask = 0x80000000; // R2 = 0x80000000
    uint32_t apply_mask = 0x00000001; // R3 = 0x00000001
    while(test_mask != 0)
    {
        if (x & test_mask) // TST R1, R2
            result |= apply_mask;
        test_mask >>= 1;  // MOVS R2, R2, LSR #1
        apply_mask <<= 1;  // MOV R3, R3, LSL #1
    }
    return result;
}
*/

int main(void)
{
    uint32_t a, b, c;
    char str[33]; // 32 bits + null
    a = 0x12345678;
    uint32ToBinary(str, a); 
    printf("a = 0x%08"PRIu32" = %s(base-2)\n", a, str);       

    b = countOnes32(a);
    printf("The number of 1 bits in 0x%08"PRIu32" is %"PRIu32"\n", a, b);


    c = bro32(a);
    uint32ToBinary(str, c); 
    printf("c = 0x%08"PRIu32" = %s(base-2)\n", c, str);       

    uint32_t d = binaryToUint32(str);
    printf("d = %s(base-2) = 0x%08"PRIu32"\n", str, d);       

    char str2[] = "11000";

    uint32_t e = binaryToUint32(str2);
    printf("d = %s(base-2) = 0x%08"PRIu32"\n", str2, e);       
    
    return EXIT_SUCCESS;
}


