org 0000h
	jmp START

org 000Bh
	jmp COUNT
	
org 001Bh
	jmp TIMER
	
org 8100h

N EQU 28h ;skorost
Tarea EQU 29h ;vremya uchastka
etalon EQU 2Ah ;dlya zadaniya skvazhnosti
k EQU 2Bh ; 3 schetnyh peremennyh
i EQU 2Ch ;
j EQU 2Dh ;
REG0 EQU 40h
REG1 EQU 41h
REG2 EQU 42h
REG3 EQU 43h
REG4 EQU 44h
REG5 EQU 46h
area EQU 45h

START:
  ;zagruzka upravl slova
  setb P1.7
  setb P1.6
  setb P1.5
  setb P1.4
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
  setb ET0 ;dayem dobro na preryvanie
  setb ET1
  setb EA
  ;setb TR0 ; go!
  ;setb TR1

BEGIN:
  mov area, #1
  mov Tarea, #3
    call AREA1
	
  setb P1.7
  setb P1.6
  setb P1.5
  setb P1.4
jmp $

VPERED:
  setb P1.7
  clr P1.6
RET

NAZAD:
  setb P1.6
  clr P1.7
RET

AREA1:
  call VPERED
  mov A, #0
  mov i, #0
  mov j, #0
  mov k, #0
  mov etalon, #2
  setb TR1 ;zapuskaem taymer
  met1:
    mov A, REG0
    setb P1.5
	clr P1.4
	cjne A, etalon, $
	clr P1.5
	setb P1.4
  cjne A, #100, $ ;100
  mov REG0, #0
  inc i
  inc REG4
  mov A, REG4
  cjne A, #3, met2
    inc etalon
	mov REG4, #0
  met2:
  mov A, i
  cjne A, #100, met1 ;100
  inc j
  mov i, #0
  mov A, j
  cjne A, Tarea, met1
  clr TR1
RET

COUNT:

RETI

TIMER: 
  mov REG3, R0
  mov REG5, R1
  mov R1, area
  inc k
  mov R0, k
  cjne R1, #1, uch2
    cjne R0, #4, exit1
    inc A
    mov k, #0
	jmp exit1
  uch2:
    cjne R1, #2, uch3
      cjne R0, #2, exit1
      inc A
      mov k, #0
	  jmp exit1  
  uch3:
    cjne R1, #3, uch5
	  cjne R0, #131, exit1
      inc A
      mov k, #0
	  jmp exit1  
  uch5:
    cjne R0, #4, exit1
    inc A
    mov k, #0
exit1:
mov R0, REG3
mov R1, REG5
RETI

END
