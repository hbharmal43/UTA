.global isGtU32
.global isGtS32

.text

// bool isGtU32(uint32_t x, uint32_t y)
// x in R0, y in R1, return 1 is x>y, 0 else in R0
isGtU32: 
    CMP R0, R1 // nothing <- x-y
    MOV R0, #0
    MOVHI R0, #1
    BX LR

// bool isGtS32(int32_t x, int32_t y)
// x in R0, y in R1, return 1 is x>y, 0 else in R0
isGtS32: 
    CMP R0, R1 // nothing <- x-y
    MOV R0, #0
    MOVGT R0, #1
    BX LR




