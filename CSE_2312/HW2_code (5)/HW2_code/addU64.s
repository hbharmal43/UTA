.global addU64 
.text

addU64:
    ADDS R0, R0, R2
    ADC R1, R1, R3
    BX LR


