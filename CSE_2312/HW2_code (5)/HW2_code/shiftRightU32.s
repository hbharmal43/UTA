.global shiftRightU32
.text

shiftLeftU16:
	MOV R0, R0, LSR R1
	BX LR
