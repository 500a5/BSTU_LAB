ORG 40h
ST:
setb P1.0
setb IT0
setb EA
setb IE0
setb ET0
jmp $

ORG 0
jmp ST

ORG 3
mov TMOD, #00000000b
jb P1.0, one
mov TH0, #11111100
mov TL0,#11011
one:
mov TH0,#11110110
mov TL0,#10011
set TR0
RETI
ORG 0BH
cpl P1.0
RETI
