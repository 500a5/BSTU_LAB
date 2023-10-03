MK_ADC BIT P1.0                 ;SIGNAL GASHENIE/PREOBRAZOVANIE
ADC_MK BIT P1.1         ;SIGNAL GOTOV
INIT_PPI EQU 10000010b  ;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN EQU  00010001b ;VIBOR 2-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT
P_A EQU 0               ;ADDRESS PORTA A V BB55
P_B EQU 1               ;ADDRESS PORTA B
P_C EQU 2               ;ADDRESS PORTA C
RWCU EQU 3              ;ADDRESS UPRAV. SLOVA BB55
P_V BIT P1.7
P_N BIT P1.6
TIME_V DATA 31h
TIME_N DATA 34h
DES_V DATA 32h          ;DESYATKI
EDIN_V DATA 33h         ;EDINICI
DES_N DATA 35h          ;DESYATKI
TIMER EQU 10000         ;5ms
sotni data 36h

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
        MOV A,TMOD
        ORL A,#0000001b
        MOV TMOD,A                      ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT
        SETB RS0
        SETB RS1
        MOV TH0,#HIGH(NOT(TIMER-1))
        MOV TL0,#LOW(NOT(TIMER-1))
        CYCLE2:
                CALL ADC
                JB ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
               ; cpl adc_mk
                MOV DPL,#P_B
                MOVX A,@DPTR
                call RACHET
                CALL VIVOD
                sjmp cycle2

        SJMP $

;PODPROGRAMMA STARTA "ADC"
ADC:
        SETB MK_ADC             ;SBROS "ADC"
        NOP
        NOP
        NOP
        NOP
        CLR MK_ADC               ;NACHAT' PREOBRAZOVANIE
RET


RACHET: mov b,#4
        div AB
        MOV b,#3
        mul AB
        MOV B,#10
        DIV AB
        MOV EDIN_v,B
       ; MOV B,#10
       ; DIV AB
        mov DES_V,A
       ; MOV sotni,A
        RET

VIVOD:  MOV A,sotni
        ORL A,#00100000b
        MOV DPL,#P_C
        MOVX @DPTR,A
        call DELAY
        MOV A,DES_V
        ORL A,#01000000b
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY
        MOV A,EDIN_v
        ORL A,#10000000b                ;VIVOD 1 CIFRI
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY              ;ZADERSHKA 10ms

RET

DELAY:
        SETB TR0
        JNB TF0,$
        CLR TF0
        CLR TR0
        MOV TH0,#HIGH(NOT(TIMER-1))
        MOV TL0,#LOW(NOT(TIMER-1))
RET


END