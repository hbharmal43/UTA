// CSE 2312 Computer Org and Assembly Language Programming
// sum example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types

// sum element of array modulo 2^32
extern uint32_t sumU32(const uint32_t x[], uint32_t count);

/*
uint32_t sumU32(const uint32_t x[], uint32_t count)
{ 
   uint32_t sum = 0;
   while (count> 0)
   {
      sum += *x;
      x++;
      count--;
   }
    return sum;
}

uint32_t sumU32(const uint32_t x[], uint32_t count)
{ 
   uint32_t sum = 0;
   while (count> 0)
   {
      sum += *(x++);
      count--;
   }
    return sum;
}

uint32_t sumU32(const uint32_t x[], uint32_t count)
{ 
   uint32_t sum = 0;
   uint32_t i = 0;
   for (i = 0; i < count; i++)
      sum += x[i];
    return sum;
}

uint32_t sumU32(const uint32_t x[], uint32_t count)
{ 
   uint32_t sum = 0;
   while (count > 0)
      sum += x[--count];
    return sum;
}

*/

#define COUNT 3
int main(void)
{
    uint32_t x[COUNT] = {10, 20, 30};
    uint32_t sum = sumU32(x, COUNT); 
    printf("Sum of elements in x is %"PRIu32"\n", sum);
    
    return EXIT_SUCCESS;
}


