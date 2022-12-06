.global isMultOf16

.text

// bool isMultOf16(uint32_t x)
// x in R0, return 1 in R0 is integer 
// multiple of x, 0 else
isMultOf16:
    TST R0, #15     // ? = R0 & (2^4 - 1)
                    // Z=1, multiple of 16
                    // Z=0, not multiple of 16
     MOVEQ R0, #1   // if Z=1 (mult of 16), then R0=1
     MOVNE R0, #0   // if Z=0 (not mult), then R0=0
     BX LR



