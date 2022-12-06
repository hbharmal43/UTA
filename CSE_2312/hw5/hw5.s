@a. int32_t sumS32(const int32_t x[], uint32_t count)
@// returns sum of the values in the array (x) containing count entries.
@b. int32_t dotpS32(const int32_t x[], const int32_t y[], uint32_t count) 
@// returns the dot product of the values in the arrays (x and y) containing count entries.
@c. uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count) 
@// returns number of values in the array (x) containing count entries that are > limit
@d. int32_t findCityAligned (const char city[], const BUSINESS2 business[], uint32_t count)
@// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
@ If the city is not found, return a value of -1. You can assume that C default alignment is used for this problem.
@e. int32_t findCityPacked (const char city[], const BUSINESS2 business[], uint32_t count)
@// returns the index of the first entry in the array (business) containing count entries which matches the requested city. 
@If the city is not found, return a value of -1. You can assume that C packing is used for this problem.

.global sumS32
.global dotpS32
.global countAboveLimit
.global findCityAligned
.global findCityPacked

.text

sumS32:
  MOV R3, R0
  MOV R0, #0
sumS32_loop:
  CMP R1, #0
  BEQ sumS32_exit
  LDR R2, [R3], #4
  ADD R0, R0, R2
  SUB R1, R1, #1
  B sumS32_loop
sumS32_exit:
  BX LR

dotpS32:
  PUSH  {R4, R5}
  MOV R3, R0
  MOV R0, #0
  CMP R2, #0
  BEQ dotpS32_exit
dotpS32_loop:
  LDR R4, [R3], #4
  LDR R5, [R1], #4
  MLA R0, R4, R5, R0
  SUBS R2, R2 ,#1
  BNE dotpS32_loop
dotpS32_exit:
  BX LR

@c. uint32_t countAboveLimit(const int32_t x[], int32_t limit, uint32_t count) 
countAboveLimit:
	PUSH {R4, R5}
	MOV R3, R0        /* R3 = &x[] */
	MOV R0, #0        /* initialzing RETURN count = 0 */
countAboveLimitLoop:
	CMP R2, #0		    /* always check to see if loop counter = 0 */
	BEQ countAboveLimitEnd
	LDR R5, [R3], #4 	/* Increment by 4 because we have 32bit ints now */
	CMP R5, R1		    /* check if the value is a zero */
	ADDGT R0, R0, #1  /* R0 += R4 */
	SUB R2, R2, #1	 	/* decrement loop counter */
	B countAboveLimitLoop
countAboveLimitEnd:
	POP {R4, R5}
	BX LR

findCityAligned:
@d. int32_t findCityAligned (const char city[], const BUSINESS2 business[], uint32_t count)
    PUSH {R4-R7, R8, R9, R10}
    MOV R5, R0	     @ backup copy of city[] to R5
    MOV R4, R1	     @ move business[0] to R4
    ADD R4, R4, #72  @ R0 = &business[0].city[0]
    MOV R3, #112     @ R2 = sizeof(BUSINESS)
    MOV R10, #0	     @ index tracker
    CMP R2, #0	     @ check if empty array
test_string:
    BEQ test_exit_not_found
    MOV R6, R4
    MOV R7, R0
test_string_loop:
    LDRSB R8, [R6], #1
    LDRSB R9, [R7], #1
    CMP R8, R9
    BNE next_business
    CMP R8, #0
    BEQ test_exit_found
    B test_string_loop
next_business:
    ADD R4, R4, R3
    ADD R10, R10, #1
    SUBS R2, R2, #1
    B test_string
test_exit_found:
    MOV R0, R10
    POP {R4-R7, R8, R9, R10}
    BX  LR
test_exit_not_found:
    MOV R0, #-1
    POP {R4-R7, R8, R9, R10}
    BX  LR


findCityPacked:
/* We are just going to set the values for a Packed Array and use the above function */
    PUSH {R4-R7, R8, R9, R10}
    MOV R5, R0	     @ backup copy of city[] to R5
    MOV R4, R1	     @ move business[0] to R4
    ADD R4, R4, #71  @ R0 = &business[0].city[0]
    MOV R3, #108     @ R2 = sizeof(BUSINESS)
    MOV R10, #0	     @ index tracker
    CMP R2, #0	     @ check if empty array
    B test_string

