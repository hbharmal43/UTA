// CSE 2312 Computer Org and Assembly Language Programming
// andor32 example
// J Losh

#include <stdlib.h>   // EXIT_ macro
#include <stdio.h>    // printf
#include <inttypes.h> // PRI macro
#include <stdint.h>   // C99 uintX_t and intX_t types


extern uint32_t and32(uint32_t x, uint32_t y);
extern uint32_t or32(uint32_t x, uint32_t y);

int main()
{
  uint32_t d, e, f;
  d = 0x12345678;
  e = 0xFFFF0000;
  f = and32(d, e);
  printf("d = 0x%08x\r\n", d);
  printf("e = 0x%08x\r\n", e);
  printf("f = d & e = 0x%08"PRIu32"\n", f);
  f = or32(d, e);
  printf("d = 0x%08x\r\n", d);
  printf("e = 0x%08x\r\n", e);
  printf("f = d | e = 0x%08"PRIu32"\n", f);
  
  return EXIT_SUCCESS;
}

