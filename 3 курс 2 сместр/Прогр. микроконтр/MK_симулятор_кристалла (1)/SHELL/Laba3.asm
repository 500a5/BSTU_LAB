INIT_PPI EQU 10000010b  ;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN EQU  00010001b  ;VIBOR 2-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT
MK_ADC BIT P1.0                 ;SIGNAL GASHENIE/PREOBRAZOVANIE
ADC_MK BIT P1.1         ;SIGNAL GOTOV
RWCU EQU 3              ;ADDRESS UPRAV. SLOVA BB55
ZNACH DATA 33h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
des DATA 34h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
edin DATA 35h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
TIME EQU 5000           ;5ms
N_SEC DATA 37h          ;YACHEIKA PAMATI SCHITAUSCHYAIA 1sec 100*5ms=500ms clrSEC, ZATEM 500ms setbSEC
C_SEC EQU 100           ;CONSTANTA DLYA SECUNDOMERA
P_A EQU 0               ;ADDRESS PORTA A V BB55
P_B EQU 1               ;ADDRESS PORTA B
P_C EQU 2               ;ADDRESS PORTA C


ORG 0h
JMP START


ORG 8100h
START:
        MOV A,#INIT_PPI
        MOV DPL,#RWCU                   ;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
        MOVX @DPTR,A
        MOV A,#INIT_KN
        MOV DPL,#P_A                    ;NASTROIKA KOMUTATOROV NAPRYASHGENIA
        MOVX @DPTR,A
        MOV R0,#0ch                      ;ZNACHENIE PERVOGO KOFICIENTA
        MOV R1,#00H
        MOV A,TMOD
          ORL A,#0000001b
          MOV TMOD,A                    ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT
          MOV TH0,#HIGH(NOT(TIME-1))
          MOV TL0,#LOW(NOT(TIME-1))

        CALL ADC
        JB ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"

        MOV DPL,#01h
        MOVX A,@DPTR
        MOV R3,A

Met1:
        MOV A,R3

        CJNE R1,#00H,MET5 ;ПРОЕРКА НА ЗАДАНИЕ РЕЖИМА ВРАЩЕНИЯ
        ADD A,R0
        clr p1.7
        setb p1.6
        MOV R1,#01H
        JMP MET6

MET5:   SUBB A,R0
        clr p1.6
        setb p1.7

        MOV R1,#00H

MET6:   MOV ZNACH,A

MET2:   CALL ADC
        JB ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
          call rasch
          call VIVOD

        MOV DPL,#01h
        MOVX A,@DPTR

        CJNE A,#00H,MET3
        JMP EXIT

MET3:   CJNE A,#119,MET4
        JMP EXIT

MET4:   CJNE A,ZNACH,MET2 ;проверка на равенство значеию отклонения
        MOV A,R0
        MOV B,#02h
        MUL AB
        MOV R0,A
        JMP MET1


;PODPROGRAMMA STARTA "ADC"
ADC:
        SETB MK_ADC             ;SBROS "ADC"
        NOP
        NOP
        NOP
        NOP
        CLR MK_ADC               ;NACHAT' PREOBRAZOVANIE
RET

rasch:
        mov b,#04h
        div ab
        mov b,#03h
        mul ab
        mov b,#0ah
        div ab
        mov des,a
        mov edin,b
ret

VIVOD:

        MOV A,edin
        ORL A,#01000000b                ;VIVOD 1 CIFRI
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY              ;ZADERSHKA 10ms
        MOV A,des
        ORL A,#00100000b
        MOVX @DPTR,A
        CALL DELAY

RET


DELAY:
        SETB TR0
        JNB TF0,$
        DJNZ N_SEC,DALLEE
        CPL P1.3                        ;PODACHA SIGNALA NA SECUNDOMER
        MOV N_SEC,#C_SEC
DALLEE:
        CLR TF0
        CLR TR0
        MOV TH0,#HIGH(NOT(TIME-1))
        MOV TL0,#LOW(NOT(TIME-1))
RET

EXIT:
        clr p1.7
        clr p1.6
END