.global shiftRightS32
.text

shiftLeftU16:
	MOV R0, R0, ASR R1
	BX LR
