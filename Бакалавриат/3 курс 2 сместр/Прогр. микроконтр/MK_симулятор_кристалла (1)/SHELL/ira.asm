org 00h
jmp start

org 0013h
mov P1,#255
RETI

start: SETB IT1
       SETB EA
       SETB EX1
       jmp  $
END