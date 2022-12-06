.global and32
.global or32

.text

// uint32_t and32(uint32_t x, uint32_t y)
// x in R0, y in R1, return result in R0
and32:
   AND R0, R0, R1 // R0 <- R0 AND R1
   BX LR

// uint32_t or32(uint32_t x, uint32_t y)
// x in R0, y in R1, return result 
   ORR R0, R0, R1 // R0 <- R0 OR R1
   BX LR
