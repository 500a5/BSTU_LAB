; PEREMENNIE
MK_ADC BIT P1.0                 ;SIGNAL GASHENIE/PREOBRAZOVANIE
INF_ADC DATA 30h        ;HRANITCA PRINYATOE OT ADC CHISLO
ADC_MK BIT P1.1         ;SIGNAL GOTOV
SOTNI DATA 31h          ;SOTNI VIVODIMOGO CHISLA
DES DATA 32h            ;DESYATKI
EDIN DATA 33h           ;EDINICI
TIME EQU 5000           ;5ms
INIT_PPI EQU 10000010b  ;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN EQU 0010000b    ;VIBOR 2-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT
P_A EQU 0               ;ADDRESS PORTA A V BB55
P_B EQU 1               ;ADDRESS PORTA B
P_C EQU 2               ;ADDRESS PORTA C
RWCU EQU 3              ;ADDRESS UPRAV. SLOVA BB55
C_TIME0 DATA 34h        ;YACHEIKA PAMATI - CONSTANTI TAIMERA
N_P DATA 35h            ;SHETHIK DLYA POL. CHISEL
PHS DATA 36h            ;PHASA OTOBRAJENIYA
C_F_P EQU 2             ;7*20ms
B_Z BIT 2Fh.7           ;FLAG OTRICATELNOGO CHISLA
SEC BIT P1.3            ;VIVOD NA SECUNDOMER
N_SEC DATA 37h          ;YACHEIKA PAMATI SCHITAUSCHYAIA 1sec 100*5ms=500ms clrSEC, ZATEM 500ms setbSEC
C_SEC EQU 200           ;CONSTANTA DLYA SECUNDOMERA

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
        MOV TMOD,A                      ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT NA RXD,TXD
        MOV TH0,#HIGH(NOT(TIME-1))
        MOV TL0,#LOW(NOT(TIME-1))
        SETB RS0
        SETB RS1
		MOV PHS,#0
        MOV N_SEC,#C_SEC                ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        GO:
                CALL ADC
                JB ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
                JMP OBSCH
                M2:
                ;CYCLE:
                        CALL VIVOD
                        ;DJNZ N_P,CYCLE
                SJMP GO

;PODPROGRAMMA STARTA "ADC"
ADC:
        SETB MK_ADC             ;SBROS "ADC"
        NOP
        NOP
        NOP
        NOP
        CLR MK_ADC               ;NACHAT' PREOBRAZOVANIE
RET


;PODPROGRAMA ZAPUSKAYUSHUASA PO SINGNALY GOTOV NA LINIY P1.1
OBSCH:

MOV 081h, #38h
        MOV N_P,#C_F_P
        MOV DPL,#P_B
        MOV A,#0
        MOV B,#0
        MOVX A,@DPTR
        MOV SOTNI,#0
        MOV DES,#0
        MOV EDIN,#0
        CLR C
        JNB ACC.7, OTRIC
        SUBB A,#127
        ;MOV ZNAK,#0
		CLR F0
        SJMP M3

;------------otric------------
OTRIC:  SUBB A,#128
        CPL A
        ;MOV ZNAK,#0Ah
		SETB F0
M3:
        MOV B,#10
        DIV AB
        PUSH ACC
        MOV A,#4
        MUL AB
        SUBB A,#10
        JB CY,ZAPIC1

        ADD A,#10
        MOV B,#10
        DIV AB
        MOV EDIN, B
        MOV DES,A
        SJMP DALEE

ZAPIC1:  ADD A,#10
        MOV EDIN,A

DALEE:  POP ACC
        JMP KONEC
DALEE2:
        CLR C
        MOV B,#10
        DIV AB
        PUSH B
        MOV B,#4
        MUL AB
        MOV SOTNI,A
        POP ACC
        MOV B,#4
        MUL AB
        ADD A,DES
        SUBB A,#10
        JB CY,ZAPIC2

        ADD A,#10
        MOV B,#10
        DIV AB
        ADD A,SOTNI
        MOV SOTNI,A
        MOV DES,B
        JMP M1


ZAPIC2: ADD A,#10
        MOV DES,A
KONEC:  CJNE A,#0,DALEE2
M1:     JMP M2
RET



;PODPROGRAMMA VIVODA NA INDICATORY
VIVOD:	MOV A,SOTNI
        ORL A,#00100000b                ;VIVOD 1 CIFRI
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY              ;ZADERSHKA 10ms
		MOV A,PHS
		CJNE A,#1,LB
        MOV A,DES
        ORL A,#01000000b
        MOVX @DPTR,A
        CALL DELAY
		MOV A,EDIN
        ORL A,#10000000b
        MOVX @DPTR,A
        CALL DELAY
		LB:
		MOV A,#0
		JB F0,LB2
		MOV A,#00010000b	;PLUS
		SJMP LAB3
		LB2:
        MOV A,#00010001b	;MINUS
		LAB3:
        MOVX @DPTR,A
        CALL DELAY
RET

;PODPROGRAMMA REGULIRUEMOI ZADERZHKI
DELAY:
        SETB TR0
        JNB TF0,$
        DJNZ N_SEC,DALLEE
   ;     CPL SEC                 ;PODACHA SIGNALA NA SECUNDOMER
		MOV N_SEC,#C_SEC
		INC PHS
		MOV A,PHS
		CJNE A,#2,DALLEE
		MOV PHS,#0
DALLEE:
        CLR TF0
        CLR TR0
        MOV TH0,#HIGH(NOT(TIME-1))
        MOV TL0,#LOW(NOT(TIME-1))
RET

END