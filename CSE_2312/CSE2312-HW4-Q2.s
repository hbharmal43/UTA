.global isStrEqual
.global strConcatenate
.global leftString
.global decimalStringToInt16
.global hexStringToUint8

.text

isStrEqual:
  LDRB    R2, [R0], #1        @ load next byte of str1
  LDRB    R3, [R1], #1        @ load next byte of str2
  CMP     R2, R3              @ check that both match
  MOVNE   R0, #0              @ No match, set result to ZERO
  BNE     isStrEqual_exit     @ No match, branch to exit
  CMP     R2, #0              @ did we reach end of 1st string?
  MOVEQ   R0, #1              @ reached end of 1st string and still match, set Result to ONE
  BEQ     isStrEqual_exit     @ everything Matched & at end of strings, branch to exit
  B       isStrEqual          @ branch to loop start (program start)
isStrEqual_exit:
  BX  LR

strConcatenate:
	LDRB	R2, [R0], #1	        @ load char of TO
	CMP		R2, #0								@ check for null of TO
	BNE 	strConcatenate				@ not null, get next char
	SUB 	R0, R0, #1						@ 'backup' address to the null
strCat_copy_loop:
	LDRB	R2, [R1], #1					@ load char of FROM & incr address
	STRB	R2, [R0], #1					@ store byte FROM in TO & incr address
	CMP		R2, #0								@ check for null of FROM
	BNE		strCat_copy_loop			@ null not found, copy next char
  BX  LR

leftString:
	CMP		R2, #0								@ check how many left to copy
	BEQ		leftString_exit				@ no more chars, then exit
	LDRB	R3, [R1], #1					@ load char from strIN & incr address
	STRB	R3, [R0], #1					@ store char to strOut & incr address
	SUB		R2, R2, #1						@ decr number of chars to copy
	CMP		R3, #0								@ check if we found null
	BNE		leftString						@ not null, loop
leftString_exit:
  BX  LR


decimalStringToInt16:         @ returns true (1) if the strings match, false (0) otherwise
                              @ a. bool isStrEqual(const char str1[], const char str2[])
                              @     R0                    R0                      R1
	PUSH  {R4}                	@ save R4 contents
  MOV   R1, R0              	@ copy our pointer out of return register
@	EOR		R0, R0, R0						 @ fancy way to zero a register & save a byte
  MOV   R0, #0               	@ set return value to zero
  MOV   R4, #10              	@ our Base multiplier
  MOV   R3, #1               	@ set the identity multiplier

	LDRB  R2, [R1], #1         	@ load 1st char & post-increment
	CMP   R2, #45              	@ is it minus sign?
  BNE   decimalString_loop   	@ not '-', continue to processing
	MOV   R3, #-1              	@ it was '-' so we need change identity multiplier
	LDRB  R2, [R1], #1        	@ load next char only if minus sign

decimalString_loop:
  CMP   R2, #0                @ check if string end found
  BEQ   decimalString_end     @ go to the end
  SUB   R2, R2, #48           @ subtract 0x30 or 48
  CMP   R0, #0                @ check lower bound
  MOVMI R0, #0                @ if R2 < 0 set return to zero
  BMI   decimalString_end     @ if R2 < 0 go to exit
  CMP   R2, #9                @ check if > 9 (upper bound)
  MOVGT R0, #0                @ if R2 > 9, set return to zero
  BGT   decimalString_end     @ if R2 > 9 go to exit
	MUL	  R0, R0, R4
	ADD   R0, R0, R2            @ add new digit to ones place
  LDRB  R2, [R1], #1          @ load the next digit
  B     decimalString_loop    @ now loop


decimalString_end:
	MUL   R0, R0, R3            @ multiply by our idenity value
  POP   {R4}                  @ restore R4 contents
	BX LR

hexStringToUint8:
  MOV   R1, R0          			@ copy our pointer out of return register
  MOV   R0, #0          			@ set return value to zero

hexStringToUint8_loop:
	LDRB  R2, [R1], #1    			@ load char & post-increment
  CMP   R2, #0          			@ check if string end found
  BEQ   hexStringToUint8_end  @ go to the end

	CMP		R2, #48								@ compare char  "0"
	BLO		invalid_char_exit			@ if < "0" branch to to invalid_char_exit
	CMP		R2, #57								@ if > "9"
	BHI		hexString_hexDigit    @ > 9 means we arent 0-9    
  @ we know we are between "0" and "9" so we process a 0-9 digit
	SUB		R2, R2, #48						@	subtract #48
	LSL		R0, R0, #4						@ mutliply current total by 2^4
	ADD		R0, R2								@ add the new digit
	B			hexStringToUint8_loop @ loop to next char
hexString_hexDigit:
	CMP		R2, #65								@ compare char to "A" #65
	BLO		invalid_char_exit			@ if char <  "A" branch to invalid_char_exit
	CMP		R2, #70								@ compare char to "F" #70
	BHI	invalid_char_exit				@ if char >  "F" jump to invalid_char_exit
	@ We know char between A & F so we process A-F digit
	SUB		R2, #55								@ subtract #55
	LSL		R0, R0, #4						@ multiply current total by 2^4
	ADD		R0, R2								@ add_digit
	B			hexStringToUint8_loop @ loop to next char
invalid_char_exit:
	MOV		R0, #0								@ set result to 0
hexStringToUint8_end:
  CMP R0, #0xFF               @ check if > 255
  MOVHI R0, #0                @ set return to 0 if > 255
	BX LR
