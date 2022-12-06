.global isEven

.text

/*
// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    AND R0, R0, #1 // R0=1 if odd, R0=0 if even
    RSB R0, R0, #1 // R0=0 if odd, R0=1 if even
    BX LR

// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    AND R0, R0, #1 // R0=1 if odd, R0=0 if even
    EOR R0, R0, #1 // R0=0 if odd, R0=1 if even
    BX LR

// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    MOVS R0, R0, LSR #1 // C=1 if odd, C=0 if even
    MOVCS R0, #0        // if C=1 (odd), then R0=0
    MOVCC R0, #1        // if C=0 (even), then R0=1
    BX LR

// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    MOVS R0, R0, LSL #31 // N=1 if odd, N=0 if even
    MOVMI R0, #0         // if N=1 (odd), then R0=0
    MOVPL R0, #1         // if N=0 (even), then R0=1
    BX LR

// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    MVN R0, R0     // invert bits
    AND R0, R0, #1 // R0=0 if odd, R0=1 if even
    BX LR

*/


// bool isEven(uint32_t x)
// x in R0, return 1 in R0 if even, else return 0
isEven:
    ANDS R0, R0, #1 // R0=1 if odd, R0=0 if even
                    // Z=1 if even, Z=0 if odd
    MOVEQ R0, #1    // if Z=1 (even), R0=1
    MOVNE R0, #0    // if Z=0 (odd), R0=0
    BX LR

