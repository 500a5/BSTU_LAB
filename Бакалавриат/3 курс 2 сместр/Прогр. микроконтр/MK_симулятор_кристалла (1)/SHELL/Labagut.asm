        ZADERG DATA 30h
        EDIN DATA 31h
        DES DATA 32h
        P_C EQU 2
        INIT_PPI EQU 10000010b
        RWCU EQU 3
        DELTA DATA 33h
        NAPRAVLENIE DATA 34h

        ORG 00h
        JMP START

        ORG 0Bh
        JMP OBOROT

        ORG 1Bh
        JMP TIME

        ORG 8100h
START:  MOV A,#INIT_PPI
        MOV DPL,#RWCU                   ;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
        MOVX @DPTR,A
        MOV TMOD,#00000111b
        MOV 081h,#34h
        setb RS0
        setb RS1
        MOV IE,#0
        MOV A,#0
        MOV R6,#0
        MOV NAPRAVLENIE,#0
        SETB IE.7
        SETB IE.3
        SETB IE.1
        MOV DELTA,#1
        MOV ZADERG,#1
        MOV TH0,#20
        MOV TL0,#130
        SETB TR0
        SETB TR1
        CALL ZAPYCK
CYCLE1: CJNE A,#100,$       ;100ms
          MOV A,#0
          INC R1
          CALL POVTOR
          CJNE R1,#5,M2
           CALL RACHET
M2:     CJNE R1,#6,CYCLE1   ;otchitivaem 600ms
          MOV R1,#0
          CALL INTERVAL
          INC R0
        CJNE R0,#100,CYCLE1  ;600*100=60000=60=1
          MOV R0,#0
          CALL VEKTORv
          INC R6
        CJNE R6,#2,CYCLE1
          CALL INVERSIA
          MOV R6,#0
        SJMP CYCLE1
        MOV ZADERG,#0
        SJMP $


ZAPYCK: CPL P1.6
        RET

INVERSIA: CPL P1.7
          CPL P1.6
          SETB P1.4
        RET

VEKTORv: MOV R7,NAPRAVLENIE
        CJNE R7,#0,M3
            MOV NAPRAVLENIE,#1
        SJMP M4
M3:       MOV NAPRAVLENIE,#0
M4:     RET


POVTOR: CALL ZADERGKA
        CALL VIVOD
        RET

VIVOD:  PUSH ACC
        CJNE R3,#0,EDV
          MOV R3,#1
          MOV A,DES
          ORL A,#01000000b
          MOV DPL,#P_C
          MOVX @DPTR,A
        SJMP DALEE2
EDV:      MOV R3,#0
          MOV A,EDIN
          ORL A,#10000000b
          MOV DPL,#P_C
          MOVX @DPTR,A
DALEE2: mov A,#0
          POP ACC
        RET

INTERVAL: PUSH ACC
          mov a,#0
          MOV R7,NAPRAVLENIE
          CJNE R7,#0,M5
            MOV A,DELTA
            ADD A,ZADERG
          SJMP M6
M5:         MOV A,ZADERG
            SUBB A,DELTA
            SJNE A,#0,M6
            MOV A,#1
M6:         MOV ZADERG,A
          mov A,#0
          POP ACC
        RET

ZADERGKA: JB P1.6,M7
          MOV R7,#0
          mov R7,zaderg
          cjne R7,#98,m12
          mov zaderg,#97
          CLR P1.4
          CJNE A,ZADERG,$
          sjmp m13
m12:      CLR P1.4
          CJNE A,ZADERG,$
m13:      SETB P1.4
          SJMP M8
M7:       mov R7,zaderg
          cjne R7,#98,m14
          mov zaderg,#97
          CLR P1.5
          CJNE A,ZADERG,$
          sjmp m15
m14:      CLR P1.5
          CJNE A,ZADERG,$
m15:      SETB P1.5
M8:       MOV R7,#0
          RET

RACHET: PUSH ACC
        mov a,#0
        mov edin,#0
        mov des,#0
        MOV A,R2
        MOV B,#2
        MUL AB
        MOV B,#10
        DIV AB
        MOV DES,A
        MOV EDIN,B
        MOV R2,#0
        mov A,#0
        POP ACC
        RET

OBOROT: MOV TL0,#130
        INC R2
        RETI

TIME:   MOV TH0,#20
        INC R5
        CJNE R5,#4,M1   ;zdem 1 ms
          MOV R5,#0
          INC A
M1:     RETI
END