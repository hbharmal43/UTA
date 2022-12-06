.global sumU32

.text

/*
// uint32_t sumU32(const uint32_t x[], uint32_t count)
// address of x[0] in R0, count in R1, return sum in R0


// uint32_t sumU32(const uint32_t x[], uint32_t count)
// address of x[0] in R0, count in R1, return sum in R0
sumU32:
    MOV R2, R0               // R2 = &str[0]
    MOV R0, #0               // R0 = sum = 0
sum_loop:
    CMP R1, #0               // is R1 = count > 0
    BEQ sum_end              // yes, exit loop
    SUB R1, R1, #1           // decrement count
    LDR R3, [R2, R1, LSL #2] // R3 = *(R2+R1*4) = *(str+count)
    ADD R0, R0, R3           // R0 = R0 + R3
    B sum_loop               // get next integer
sum_end:
    BX LR
