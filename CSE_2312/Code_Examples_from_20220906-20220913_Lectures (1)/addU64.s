.global addU64 
.text

// uint64_t addU64(uint64_t x, uint64_t y)
// x in R1:R0 (bits 63-32 are in R1, bits 31-0 are in R0)
// y in R3:R2 (bits 63-32 are in R3, bits 31-0 are in R2)
// return result in R1:R0 (bits 63-32 are in R1, bits 31-0 are in R0)
addU64:
    ADDS R0, R0, R2 // C:R0 (33b) <- R0 + R2, S means set/update flags
    ADC R1, R1, R3  // R1 <- R1 + R3 + C
    BX LR

// ADDS (add and set flags)
// adds least significant 32b of x and y and stores in C:R0
// important that S in ADDS makes sure that C flag is updated

// ADC (add with carry)
// adds most significant 32b of x and y and C together and stores in R1

// Now result is in R1:R0

// gdb commands:
// (add -g to gcc command to generate debug symbols)
// list
// b (line number) adds a breakpoint
// run (will stop at a breakpoint if any)
// step
// info registers or i r (see registers)
// much more later
// consult assembly textbook, chapter on GDB


