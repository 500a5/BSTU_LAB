 org 0000h
 jmp START

 org 000Bh
 jmp COUNTER

 org 001Bh
 jmp TIMER

 org 8100h

AREA EQU 18h ;nomer uchastka R0
MS EQU 19h ;milliseconds R1
DELTA EQU 1Ah ;prirascheniye R2
N EQU 1Bh ;skorost' R3
CPOVT EQU 1Ch ;R4
CNT EQU 1Dh ;R5
CNT1 EQU 1Eh ;R6
SEC EQU 1Fh ;R7 1 secunda
REG6 EQU 44h
EDIN EQU 45h
N1 EQU 46h
DESTK EQU 47h
N2 EQU 48h
SEC1 EQU 49h
adr EQU 50h
A1 EQU 53h

   START:
    ;zagruzka upravl slova
    mov DPTR, #3h
    mov A,  #10000010b
    movx @DPTR, A
    mov DPTR, #2h

   ;timer
   mov 55h, 2Fh
   mov 2Fh, TMOD
   setb 78h
   setb 79h
   setb 7Ah
   mov TMOD, 2Fh
   mov 2Fh, 55h
   mov CPOVT, #0FFh

   mov CNT, #0h
   setb PSW.3
   setb PSW.4
   mov R0, #0h
   mov R1, #0h
   mov R2, #0h
   mov R3, #0h
   mov R4, #0h
   mov R5, #0h
   mov R6, #0h
   mov R7, #0h
   mov A, #0h
   mov N1, #0h
   mov N2, #0h
   mov adr, #45h
   mov 51h, #0h

   mov TL0, #5h
   setb ET0 ;razreshenie prerivaniya
   setb ET1
   setb EA
   setb TR0
 ;dvizhenie
 call STEP1
 call STEP2
 call STEP3
 call STEP4
 call STEP5
 call STEP6
 jmp $

 STEP1:
  mov A, #11h
  mov DELTA, #11h
  mov AREA, #1h
  setb TR1 ; go!
  call vpered
  clr TR1
  RET

 STEP2:
  mov A, #64h
  mov DELTA, #1h
  mov AREA, #2h
  setb TR1 ; go!
  call vpered
  clr TR1
  RET
 STEP3:
  mov A, #13h
  mov 51h, #13h
  mov DELTA, #11h
  mov AREA, #3h
  setb TR1 ; go!
  call nazad
  clr TR1
  RET
 STEP4:
  mov A, #32h
  mov 51h, #64h
  mov DELTA, #1h
  mov AREA, #4h
  setb TR1 ; go!
  call vpered
  clr TR1
  RET
 STEP5:
  mov A, #13h
  mov 51h, #13h
  mov DELTA, #11h
  mov AREA, #5h
  setb TR1 ; go!
  call vpered
  clr TR1
  RET

 STEP6:
  mov A, #19h
  mov 51h, #64h
  mov DELTA, #1h
  mov AREA, #6h
  setb TR1 ; go!
  call vpered
  clr TR1
  call STOP
  RET
 ;
 vpered:
  setb P1.7
  clr P1.6
  CICLE1F:
  setb P1.5
  clr P1.4
  C1F: cjne A, MS, C1F
  clr P1.5
  setb P1.4
  C2F: cjne R1, #63h, C2F
  mov 54h, A
  mov A, #95h
  subb A, R4
  mov A, 54h
  jnc CICLE1F
  mov R4, #0h
  ret
   ;
 nazad:
  setb P1.6
  clr P1.7
  CICLE1B:
  setb P1.4
  clr P1.5
  C1B: cjne A, MS, C1B
  clr P1.4
  setb P1.5
  C2B: cjne R1, #63h, C2B
  mov 54h, A
  mov A, #95h
  subb A, R4
  mov A, 54h
  jnc CICLE1B
  mov R4, #0h
  ret
  ;
 STOP:
  mov P1,#11111111b
  ret
 SPEED:
  mov REG6, A
  mov A, N
  mov N, #0
  RL A ;nado umnozhit na 2
  ; proishodit 2 oborota
  RL A
  mov B, #10
  DIV AB
  ORL A, #01000000b
  mov DESTK, A
  mov A, B
  ORL A, #10000000b
  mov EDIN, A
  mov A, REG6
  RET
 COUNTER:
  mov TL0, #5h
  inc N
  RETI
 TIMER:
  mov TH0, #9h
  inc CNT
  cjne R5, #4h, LABEL1
  inc MS
  cjne R1, #64h, LABEL2
  inc CPOVT
  cjne R6, #0Fh, LBL6
  cjne R0, #1h, LBL1
  add A,DELTA
  dec DELTA
  dec DELTA
 LBL1:
  cjne R0, #2h, LBL2
  subb A,DELTA
  inc DELTA
  inc DELTA
 LBL2:
  cjne R0, #3h, LBL3
  mov A, 51h
  add A,DELTA
  mov 51h, A
  RR A
  ANL A, #01111111b
  dec DELTA
  dec DELTA
 LBL3:
  cjne R0, #4h, LBL4
  mov A, 51h
  subb A,DELTA
  mov 51h, A
  RR A
  ANL A, #01111111b
  inc DELTA
  inc DELTA
 LBL4:
  cjne R0, #5h, LBL5
  mov A, 51h
  add A,DELTA
  mov 51h, A
  RR A
  ANL A, #01111111b
  RR A
  ANL A, #01111111b
  dec DELTA
  dec DELTA
 LBL5:
  cjne R0, #6h, LBL8
  mov A, 51h
  subb A,DELTA
  mov 51h, A
  RR A
  ANL A, #01111111b
  RR A
  ANL A, #01111111b
  inc DELTA
  inc DELTA
 LBL8:
  mov CNT1, #0h
 LBL6:
  cjne R7, #9h, LBL7
  call SPEED
  mov SEC, #0h
 LBL7:
  inc CNT1
  inc SEC
  mov MS, #0h
 LABEL2:
  mov CNT, #0h
 LABEL1:
  ;
  mov REG6, A
  mov A1, R1
  mov R1, adr
  mov A, @R1
  movx @DPTR, A
  cjne R1, #48h, exit2
  mov adr, #44h
 exit2:
  inc adr
  mov R1, A1
  mov A, REG6
  RETI
   END
