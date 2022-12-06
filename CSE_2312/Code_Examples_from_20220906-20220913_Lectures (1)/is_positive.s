.global isPositiveU32
.global isPositiveS32

.text

// bool isPositiveU32(uint32_t x)
// x in R0, return 1 in R0 is positive, 0 else
isPositiveU32:
    CMP R0, #0   // Z=1 if zero, 0 positive
    MOV R0, #0   // R0=0 by default
    MOVNE R0, #1 // if positive (not zero), R0=1
    BX LR

// bool isPositiveS32(int32_t x)
// x in R0, return 1 in R0 is positive, 0 else
isPositiveS32:
    CMP R0, #0   // Z=1 if zero, 0 else
                 // N=1 if negative, 0 else
    MOV R0, #1   // R0=1 by default (assume positive)
    MOVEQ R0, #0 // if zero (not positive), R0=0
    MOVMI R0, #0 // if negative (not positive), R0=0
    BX LR


