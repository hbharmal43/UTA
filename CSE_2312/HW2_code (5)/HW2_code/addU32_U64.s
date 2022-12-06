.global addU32_U64

.text

addU32_U64:
	ADDS R0,R0,R1
	MOV  R1, #0
	MOVCS R1,#1
	BX LR
	
