.global countOnes32
.global bro32
.global uint32ToBinary
.text

/*
// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
    MOV R2, #0x80000000 // R2 = test mask = 10000000000000000000000000000000
co_loop:
    TST R1, R2          // update flags based on R1 & R2 (x & test mask)
                        // ZF=0 if bit set
    ADDNE R0, R0, #1    // if bit set (ZF=0), then inc count
    MOVS R2, R2, LSR #1 // R2 >>=1 or test mask >>=1
                        // sets ZF=1 if done
    BNE co_loop         // look at next bit
    BX LR

// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
    MOV R2, #0x00000001 // R2 = test mask = 00000000000000000000000000000001
co_loop:
    TST R1, R2          // update flags based on R1 & R2 (x & test mask)
                        // ZF=0 if bit set
    ADDNE R0, R0, #1    // if bit set (ZF=0), then inc count
    MOVS R2, R2, LSL #1 // R2 <<=1 or test mask <<=1
                        // sets ZF=1 if done
    BNE co_loop         // look at next bit
    BX LR

// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
    MOV R2, #0x00000001 // R2 = test mask = 00000000000000000000000000000001
co_loop:
    TST R1, R2          // update flags based on R1 & R2 (x & test mask)
                        // ZF=0 if bit set
    ADDNE R0, R0, #1    // if bit set (ZF=0), then inc count
    MOVS R1, R1, LSR #1 // R1 >>=1 or x >>=1
                        // sets ZF=1 if done
    BNE co_loop         // look at next bit
    BX LR

// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
co_loop:
    TST R1, #1          // update flags based on R1 & #1 (x & #1)
                        // ZF=0 if bit set
    ADDNE R0, R0, #1    // if bit set (ZF=0), then inc count
    MOVS R1, R1, LSR #1 // R1>>=1 or x>>=1
                        // sets ZF=1 if done
    BNE co_loop         // look at next bit
    BX LR

// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
co_loop:
    MOVS R1, R1, LSR #1 // R1>>=1 or x>>=1
                        // sets ZF=1 if done, sets CF=1 if old LSb was 1
    ADDCS R0, R0, #1    // if carry set (CF=1), then inc count
    BNE co_loop         // look at next bit
    BX LR
*/

// uint32_t countOnes32(uint32_t x)
// x in R0, return number of one bits in R0
countOnes32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = count = 0
co_loop:
    MOVS R1, R1, LSL #1 // R1<<=1 or x<<= 1
                        // sets ZF=1 if done, sets CF=1 if old LSb was 1
    ADDCS R0, R0, #1    // if carry set (CF=1), then inc count
    BNE co_loop         // look at next bit
    BX LR

/*
// uint32_t bro32(uint32_t x)
// x in R0, return bit reversed number in R0
bro32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = result = 0
    MOV R2, #0x80000000 // R2 = test mask  = 10000000000000000000000000000000
    MOV R3, #0x00000001 // R3 = apply mask = 00000000000000000000000000000001
bro_loop:
    TST R1, R2          // update flags based on R1 & R2 (x & test mask)
                        // ZF=0 if bit set
    ORRNE R0, R0, R3    // if bit set (ZF=0), then R0 |= R3 (result |= apply mask)
    MOVS R2, R2, LSR #1 // R2 >>=1 or test mask >>=1
                        // sets ZF=1 if done
    MOV R3, R3, LSL #1  // R3 <<= 1 or apply_mask <<=1
    BNE bro_loop        // look at next bit if not done
    BX LR

// uint32_t bro32(uint32_t x)
// x in R0, return bit reversed number in R0
bro32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = result = 0
    MOV R2, #0x80000000 // R2 = test mask  = 10000000000000000000000000000000
    MOV R3, #0x00000001 // R3 = apply mask = 00000000000000000000000000000001
bro_loop:
    TST R1, R2          // update flags based on R1 & R2 (x & test mask)
                        // ZF=0 if bit set
    ORRNE R0, R0, R3    // if bit set (ZF=0), then R0 |= R3 (result |= apply mask)
    MOVS R1, R1, LSL #1 // R1 <<= 1 or x <<= 1
                        // sets ZF=1 if done
    MOV R3, R3, LSL #1  // R3 <<= 1 or apply_mask <<=1
    BNE bro_loop        // look at next bit if not done
    BX LR
*/

// uint32_t bro32(uint32_t x)
// x in R0, return bit reversed number in R0
bro32:
    MOV R1, R0          // R1 = x
    MOV R0, #0          // R0 = result = 0
    MOV R2, #0x00000001 // R3 = apply mask = 00000000000000000000000000000001
bro_loop:
    TST R1, #0x80000000 // update flags based on R1 & bit 31 set (x & bit 31 set)
                        // ZF=0 if bit set
    ORRNE R0, R0, R2    // if bit set (ZF=0), then R0 |= R2 (result |= apply mask)
    MOVS R1, R1, LSL #1 // R1 <<= 1 or x <<= 1
                        // sets ZF=1 if done
    MOV R2, R2, LSL #1  // R2 <<= 1 or apply_mask <<=1
    BNE bro_loop        // look at next bit if not done
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

    STRB R3, [R0], #1 // store ascii character in string, 
                      // inc R0 by sizeof(char)=1
                      // *(str++) = c
    MOVS R2, R2, LSR #1 // move mask bit to the right
    BNE utb_loop // loop back for remaining 31 bits
    MOV R3, #0 // add null terminator
    STRB R3, [R0]
    BX LR
