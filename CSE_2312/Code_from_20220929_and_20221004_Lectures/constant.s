.global getConstantU32
.global getConstantS32

.text

NUM:
    .word 0x12345678 // assembler fills up 4 bytes of program memory with constant

// uint32_t getConstantU32()
// return result in R0
getConstantU32:
/*
    MOV R0, #0
    MOV R0, #255
    MOV R0, #256 // 64 ROL 2 = 64 ROR 30
    MOV R0, #0x83000000 // 0x00000083 ROR 8
    MOV R0, #0x30000008 // 0x00000083 ROR 4
    MOV R0, #0xC0000020 // 0x00000083 ROR 2
    MOV R0, #257 // bad
*/
    LDR R0, NUM
    BX LR

// int32_t getConstantS32()
// return result in R0
getConstantS32:
/*
    MOV R0, #1      // 00000001 ROR 0 -> N = 0x01, S = 0
    MVN R0, #0      // 00000000 ROR 0 -> N = 0x00, S = 0 -> -1
*/
    MOV R0, #-1     // assembler converts to MVN R0, #0
    BX LR

 
