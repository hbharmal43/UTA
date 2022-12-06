.global lsl32
.global lsr32
.global asl32
.global asr32
.global uint32ToBinary

.text

// uint32_t lsl32(uint32_t x, uint32_t p)
// value in R0, shift in R1 -> return result in R0
lsl32:
    MOV R0, R0, LSL R1
    BX LR

// uint32_t lsr32(uint32_t x, uint32_t p)
// value in R0, shift in R1 -> return result in R0
lsr32:
    MOV R0, R0, LSR R1
    BX LR

// int32_t asl32(int32_t x, uint32_t p)
// value in R0, shift in R1 -> return result in R0
asl32:
    MOV R0, R0, LSL R1
    BX LR

// int32_t asr32(int32_t x, uint32_t p)
// value in R0, shift in R1 -> return result in R0
asr32:
    MOV R0, R0, ASR R1
    BX LR

// void uint32ToBinary(char str[], uint32_t x)
// address of string in R0, value in R1
uint32ToBinary:
    MOV R2, #0x80000000 // mask with bit 31 set
utb_loop:
    TST R1, R2 // return 0 if bit not set, non-zero if bit set
    MOVNE R3, #'1' // bit set
    MOVEQ R3, #'0' // bit clear
                   // if bitset char c='1', if bitclear c='0'
/*
    STRB R3, [R0]  // store ascii character in string
                   // *str = c  
    ADD R0, R0, #1 // increment pointer by sizeof(char)
                   // str++
*/
    STRB R3, [R0], #1 // store ascii character in string, 
                      // inc R0 by sizeof(char)=1
                      // *(str++) = c
    MOVS R2, R2, LSR #1 // move mask bit to the right
    BNE utb_loop // loop back for remaining 31 bits
    MOV R3, #0 // add null terminator
    STRB R3, [R0]
    BX LR
