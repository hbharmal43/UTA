// CSE 2312 Computer Org and Assembly Language Programming
// shift32 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

extern uint32_t lsl32(uint32_t x, uint32_t p);
extern uint32_t lsr32(uint32_t x, uint32_t p);
extern int32_t asl32(int32_t x, uint32_t p);
extern int32_t asr32(int32_t x, uint32_t p);

// note: not on quiz 1-3 or test 1... a look ahead
extern void uint32ToBinary(char str[], uint32_t x);

int main()
{
    uint32_t shift = 2;
    uint32_t a, b, c;
    int32_t d, e, f;
    char str[33];

    a = 7;
    b = lsl32(a, shift);
    c = lsr32(a, shift);
    uint32ToBinary(str, a);
    printf("a =          0x%08"PRIx32" = %s (base-2)\n", a, str);
    uint32ToBinary(str, b);
    printf("b = a << %u = 0x%08"PRIx32" = %s (base-2)\n", shift, b, str);
    uint32ToBinary(str, c);
    printf("c = a >> %u = 0x%08"PRIx32" = %s (base-2)\n", shift, c, str);

    d = -8;
    e = asl32(d, shift);
    f = asr32(d, shift);
    printf("d = %"PRId32"\n", d);
    printf("e = d << %"PRIu32" = %"PRId32"\n", shift, e);
    printf("f = d >> %"PRIu32" = %"PRId32"\n", shift, f);

    d = 8;
    e = asl32(d, shift);
    f = asr32(d, shift);
    printf("d = %"PRId32"\n", d);
    printf("e = d << %"PRIu32" = %"PRId32"\n", shift, e);
    printf("f = d >> %"PRIu32" = %"PRId32"\n", shift, f);
    
    return EXIT_SUCCESS;
}

