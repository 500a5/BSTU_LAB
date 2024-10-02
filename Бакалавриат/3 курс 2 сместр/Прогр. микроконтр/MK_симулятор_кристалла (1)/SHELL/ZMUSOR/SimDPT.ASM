   ;

org 0h
jmp MAIN
org 8100h

MAIN:
MOV R6, #50   ; v R6 gamma 0..100
MOV A,#10000010b
MOV DPL,#3                      ;nastraivaem BB55
MOVX @DPTR,A

setb P1.4
setb P1.5
setb P1.6
setb P1.7


mov A, TMOD
orl A, #00000001b
anl A, #11111101b
mov TMOD, A ; taimer 1 rezgim
WORKING:
 mov TL0, #0
 mov TH0, #0
 mov R7, #100 ; 100mc period povtorenia
   PERIOD:
    ; zapuskaem timer na 1 mc
     mov TH0, #HIGH(-1000)
     mov TL0, #LOW(-1000)
     mov A, R7
     subb A, R6
     jc fwd
     CALL right
     jmp go
fwd:
     CALL left
go:
     Setb TR0
     WaitTH0:                 ;zgdem perepolnenia timera
     JNB TF0, WaitTH0
     DJNZ R7, PERIOD
     jmp WORKING

         left:
     CLR P1.5
     CLR P1.7 ; vpered
     SETB P1.4
     SETB P1.6
         RET

         right:
     CLR P1.4
     CLR P1.6    ;nazad
     SETB P1.5
     SETB P1.7
         RET

end