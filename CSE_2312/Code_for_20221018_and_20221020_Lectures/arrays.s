.global scaleU32
.global dotpU32

.text
// void scaleU‌32(uint32_t y[], const uint32_t x[], uint32_t scale, uint32_t count)
// add of y[0] in R0, add of x[0] in R1, scale in R2, count in R3
scaleU32:
    PUSH {R4}           // save R4 on stack
    CMP R3, #0          // is count == 0?
scale_loop:
    BEQ scale_end       // if count == 0, exit loop
    LDR R4, [R1], #4    // R4 = *(R1), R1 += sizeof(uint32_t) -> R4 = *(x++)
    MUL R4, R4, R2      // R4 *= scale
    STR R4, [R0], #4    // *(R0) = R4, R0 += sizeof(uint32_t) -> *(y++) = R4
    SUBS R3, R3, #1     // count--, update zero flag
    B scale_loop        // get next value in array
scale_end:
    POP {R4}            // restore R4 from stack
    BX LR

// uint32_t dotpU32(const uint32_t x[], const uint32_t y[], uint32_t count)
// address of x[0] in R0, address of y[0] in R1, count in R2
dotpU32:
    PUSH {R4, R5}
    MOV R3, R0           // R3 = &x[0]
    MOV R0, #0           // prod = 0
    CMP R2, #0           // set ZF=1 if count == 0
dotp_loop:
    BEQ dotp_end         // exit loop if count == 0
    LDR R4, [R3], #4     // R4 = *(R3), R3 += sizeof(uint32_t) -> R4 = *(x++)
    LDR R5, [R1], #4     // R5 = *(R1), R1 += sizeof(uint32_t) -> R5 = *(y++)
    MLA R0, R4, R5, R0   // R0 = R4 * R5 + R0
    SUBS R2, R2, #1      // count--, update zero flag
    B dotp_loop          // get next value
dotp_end:
    POP {R4, R5}
    BX LR

