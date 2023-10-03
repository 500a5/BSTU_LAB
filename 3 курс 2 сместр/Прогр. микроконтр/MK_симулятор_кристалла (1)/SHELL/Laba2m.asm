
TIME EQU 100            ;0,1ms
sCH DATA 39h
N1_SEC DATA 37h         ;YACHEIKA PAMATI SCHITAUSCHYAIA 1sec 200*0,25ms=500ms clrSEC, ZATEM 500ms setbSEC
N2_SEC DATA 38h
N3_SEC DATA 36h
rezh DATA 35h
kol DATA 34h
kol1 DATA 33h
N4_SEC DATA 32h         ;ДЛЯ РЕЖИМА 3
C_SEC EQU 100           ;CONSTANTA DLYA SECUNDOMERA
C2_SEC EQU 10            ;CONSTANTA DLYA SECUNDOMERA выбранно опытным путём
C3_SEC EQU 75           ;количество повторений для 15-и секунд
SEC_REZH2 EQU 14          ;CONSTANTA DLYA SECUNDOMERA
TIME2 EQU 5000          ;5ms
imp EQU 125             ;Количество импульсов одного оборота

 org 00h
 jmp start

 org 000Bh
 jmp TIMER_0

 org 8100h

start:
        mov DPTR,#03h   ;Выбор регистра управления в 55-ом
        mov A,#82h      ;Выбор команды (B-ввод,C-вывод, A-вывод)
        movx @DPTR,A
        MOVX @DPTR,A
        MOV N3_SEC,#C3_SEC              ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        mov IE, #10000010b
        MOV A,TMOD
        ORL A,#00000111b
        MOV TMOD,A                      ;Режим 3
        MOV REZH,#01H                   ;задаём начальный режим для двигателя
        MOV R4,rezh
        MOV KOL,#06H
        setb tr0

        MOV DPL,#02h
          mov A,#11h
        MOVX @DPTR,A
        mov R5, #06H

    GO:
        mov TL0,#00H
        MOV SCH,#00H
        MOV Tl0,#NOT(imp-1)
        MOV N1_SEC,#C_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        MOV N2_SEC,#C2_SEC              ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        MOV N4_SEC,#SEC_REZH2               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        MOV kol1,#02h                   ;количество повторений режима за цикл
        CALL PYSK
        call preob
        CALL VIVOD
        dec R5
        mov R6, A
        mov A, R5
        jm Finish
        mov A, R6
        DJNZ N3_SEC,GO
        MOV N3_SEC,#C3_SEC              ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        inc rezh
        MOV R4,rezh

        DJNZ KOL,GO
        MOV REZH,#01H
        MOV R4,rezh
                djne KOL,

        MOV KOL,#06h                   ;количество циклов


 PYSK:                               ;подпрограмма анализа направления вращения
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        CJnE R4,#01H,REZH2           ;искючение 1-ого режима

  REZH1:mov P1,#10100000b
        MOV DPL,#02h
        mov A,#11h
        MOVX @DPTR,A
        JMP MET3

  REZH2:CJnE R4,#02H,REZH3           ;искючение 2-ого режима
        mov P1,#01010000b
        MOV DPL,#02h
        mov A,#81h
        MOVX @DPTR,A

   MET3:

        jnb tf1,$
        DJNZ N1_SEC,PYSK
        MOV N1_SEC,#C_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,PYSK
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ KOL1,PYSK
        mov A,SCH
        JMP EXIT

  REZH3:
        CJnE R4,#03H,REZH4
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#00000000b
        MOV DPL,#02h
        mov A,#81h
        MOVX @DPTR,A
        jnb tf1,$
        DJNZ N4_SEC,REZH3
        MOV N4_SEC,#14h               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,REZH3
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA

        MOV N4_SEC,#46h

met31:
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#01010000b
        jnb tf1,$
        DJNZ N4_SEC,met31
        MOV N4_SEC,#46H             ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,met31
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ KOL1,met31
        mov A,SCH
        JMP EXIT


  REZH4:
        CJnE R4,#04H,REZH5
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#00000000b

        MOV DPL,#02h
        mov A,#11h
        MOVX @DPTR,A

        jnb tf1,$
        DJNZ N4_SEC,REZH4
        MOV N4_SEC,#14h               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,REZH4
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA

        MOV N4_SEC,#46h

met41:
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#10100000b
        jnb tf1,$
        DJNZ N4_SEC,met41
        MOV N4_SEC,#46H             ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,met41
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ KOL1,met41
        mov A,SCH
        JMP EXIT

  REZH5:
        CJnE R4,#05H,REZH6           ;искючение 3-ого режима

        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#00000000b

        MOV DPL,#02h
        mov A,#11h
        MOVX @DPTR,A

        jnb tf1,$
        DJNZ N4_SEC,REZH5
        MOV N4_SEC,#3ch               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,REZH5
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA

        MOV N4_SEC,#1eh

met51:
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#10100000b
        jnb tf1,$
        DJNZ N4_SEC,met51
        MOV N4_SEC,#1eH             ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,met51
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ KOL1,met51

        mov A,SCH
        JMP EXIT

  REZH6:
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#00000000b

        MOV DPL,#02h
        mov A,#81h
        MOVX @DPTR,A

        jnb tf1,$
        DJNZ N4_SEC,REZH6
        MOV N4_SEC,#3ch               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,REZH6
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA

        MOV N4_SEC,#1eh

met61:
        clr TF1
        clr A
        mov th1,A
        MOV Th0,#NOT(TIME-1)
        setb tr1

        MOV P1,#01010000b
        jnb tf1,$
        DJNZ N4_SEC,met61
        MOV N4_SEC,#1eH             ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ N2_SEC,met61
        MOV N2_SEC,#C2_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        DJNZ KOL1,met61
        mov A,SCH
        JMP finish



  EXIT:
 RET

 preob:                                 ;преобразование
        MOV B,#05H
        mul AB
        MOV B,#0AH
        DIV AB
        MOV R0,b
        MOV R1,A
  RET
VIVOD:
        MOV B,#02H
        MOV A,N3_SEC
        DIV AB
        MOV DPL,#02h
        MOV R5,B
        CJNE R5,#01H,MET5

        MOV A,R0
        ORL A,#01000000b
        MOVX @DPTR,A
        jmp met6

MET5:   MOV A,R1
        ORL A,#00100000b
        MOVX @DPTR,A
MET6:
RET


TIMER_0:
  INC SCH
  MOV Tl0,#NOT(imp-1)
  setb tr0
RETI

FINISH:
        mov P1,0
end