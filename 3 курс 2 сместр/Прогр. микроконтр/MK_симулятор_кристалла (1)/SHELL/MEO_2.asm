PO_CHAS BIT P1.6
PR_CHAS BIT P1.7
MK_ADC BIT P1.0 		;SIGNAL GASHENIE/PREOBRAZOVANIE
ADC_MK BIT P1.1		;SIGNAL GOTOV
C1_T0 EQU 50000 		;50ms
C2_T0 EQU 5000 		;5ms
INIT_PPI EQU 10000010b 	;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN EQU 00010001b	;VIBOR 1-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT	(11h)
P_A EQU 0		;ADDRESS PORTA A V BB55
P_B EQU 1 		;ADDRESS PORTA B
P_C EQU 2 		;ADDRESS PORTA C
RWCU EQU 3		;ADDRESS UPRAV. SLOVA BB55
NACHALO EQU 85FFh
BUF_F_DPH DATA 30h
BUF_F_DPL DATA 31h
FI_Z DATA 32h		;ZADANNUI UGOL
FI_T DATA 33h		;TEKUSHII UGOL
C_VIV_UST EQU 200	;200*4*5ms=4s
C_VIV_OK EQU 15
INF_ADC DATA 34h
BUF_F_C BIT 27h.0
C_CLEAR EQU 10		;ZAPOLNYAEM FFh
C_NACH_ZNACH EQU 18	
C_VIVOD_2 EQU 10

;R0 - NE ISPOLZUEM !!!
;R1 - DLYA VIVODA USTAVKI
;R2 - BUFFER DLYA RASCHETA TEK_ZNACH ADC
;R3 - DLYA VIVODA OK
;R4 - DLYA OCHISTKI (CLEAR)
;R5 - DLYA VIVOD_2 (EDINICI V 10 RAZ CHASHE, CHEM DESYATKI)


ORG 0h
JMP START

ORG 8100h
START:
	MOV A,#INIT_PPI
	MOV DPTR,#RWCU		;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
	MOVX @DPTR,A
	MOV A,#INIT_KN
	MOV DPTR,#P_A 			;NASTROIKA KOMUTATOROV NAPRYASHGENIA
	MOVX @DPTR,A		
	MOV A,TMOD
	ORL A,#00000001b	
	MOV TMOD,A			
	MOV TH0,#HIGH(NOT(C1_T0-1))
	MOV TL0,#LOW(NOT(C1_T0-1))
	SETB RS1			;2-I BANK (0-3)
	CALL CLEAR
	CALL NACH_ZNACH
ZANOVO:
	MOV DPTR,#NACHALO
	MOV BUF_F_DPH,DPH
	MOV BUF_F_DPL,DPL
SLED:	
	CLR PO_CHAS
	CLR PR_CHAS
	MOV FI_Z,#0
	MOV FI_T,#0
	MOV R5,#C_VIVOD_2
	MOV DPH,BUF_F_DPH
	MOV DPL,BUF_F_DPL
	INC DPTR
	MOV BUF_F_DPH,DPH
	MOV BUF_F_DPL,DPL
	MOVX A,@DPTR
	CJNE A,#0FFh,DALEE		;ESLI V USTAVKE T_Z=FF,
	SJMP ZANOVO			;TO ETO SVIDETELSTVUET OB OKONCHANII
					;MASSIVA DANNIH, I VOZVRATU K NACHALU
DALEE:
	MOV FI_Z,A
	CALL PEREVOD
	CALL ADC		;DLYA VIVODA NACH.ZNACH FI
	CALL RASCHET		;DLYA VIVODA NACH.ZNACH FI
	CALL VIVOD_1
RABOTAEM:
	CALL ADC
	CALL RASCHET
	CALL REGUL
	CALL DELAY_1
	CALL VIVOD_2
	SJMP RABOTAEM

DELAY_1:			;50ms
	SETB TR0
	JNB TF0,$
	CLR TF0
	CLR TR0
	MOV TH0,#HIGH(NOT(C1_T0-1))
	MOV TL0,#LOW(NOT(C1_T0-1))	
RET

DELAY_2:			;5ms
	MOV TH0,#HIGH(NOT(C2_T0-1))
	MOV TL0,#LOW(NOT(C2_T0-1))
	SETB TR0
	JNB TF0,$
	CLR TF0
	CLR TR0
	MOV TH0,#HIGH(NOT(C1_T0-1))
	MOV TL0,#LOW(NOT(C1_T0-1))
RET

VIVOD_1:				;VIVOD NACHAL'NOGO FI & USTAVKI
	MOV R1,#C_VIV_UST
CYCLE:				
	MOV A,FI_T
	MOV B,#10
	DIV AB
	MOV DPTR,#P_C
	ORL A,#00010000b
	MOVX @DPTR,A
	CALL DELAY_2
	MOV A,B
	ORL A,#00100000b
	MOVX @DPTR,A
	CALL DELAY_2
	MOV A,FI_Z
	MOV B,#10
	DIV AB
	ORL A,#01000000b
	MOVX @DPTR,A
	CALL DELAY_2
	MOV A,B
	ORL A,#10000000b
	MOVX @DPTR,A
	CALL DELAY_2
	DJNZ R1,CYCLE
RET

VIVOD_2:				;VIVOD TEKESCHEGO FI
	MOV A,FI_T
	MOV B,#10
	DIV AB
	MOV DPTR,#P_C
	DJNZ  R5,NEXT
	MOV R5,#C_VIVOD_2
	ORL A,#01000000b
	MOVX @DPTR,A
	SJMP EEXIT
NEXT:
	MOV A,B
	ORL A,#10000000b
	MOVX @DPTR,A
EEXIT:
RET

ADC:
	SETB MK_ADC
	NOP
	NOP
	NOP
	NOP
	CLR MK_ADC
	JB ADC_MK,$
	MOV DPTR,#P_B
	MOVX A,@DPTR
	MOV INF_ADC,A
RET

RASCHET:
	MOV A,INF_ADC
	MOV B,#12		;K=90/120
	DIV AB			
	MOV R2,B	
	MOV B,#9
	MUL AB
	ADD A,R2
	MOV FI_T,A
RET

REGUL:
	CLR C
	MOV A,FI_Z
	MOV R3,FI_T
	SUBB A,R3		;IZ USTAVKI VICHITAEM TEKUSCHEE (FI_Z - FI_T)
	MOV BUF_F_C,C
	CJNE A,#0,GO_1
	CLR PO_CHAS
	CLR PR_CHAS
	CALL OK
	JMP SLED		;!!!!! SLEDUYSHEE ZNACHENIE
GO_1:
	JB BUF_F_C,GO_2
	CLR PR_CHAS		;ESLI USTAVKA BOLSHE, CHEM TEK.ZNACHENIE, TO KRUTIM
	SETB PO_CHAS		;PO CHASOVOI
	SJMP EXIT
GO_2:
	CLR PO_CHAS		;ESLI USTAVKA MEN'SHE, CHEM TEK.ZNACHENIE, TO KRUTIM
	SETB PR_CHAS		;PROTIV CHASOVOI
EXIT:
RET

OK:				;VIVODIM MIGAUSHIE EDINICI V TECHENII 3 SEKUND
	MOV DPTR,#P_C
	MOV R3,#C_VIV_OK
CYKLE:	
	MOV A,#11110001b		;GORYAT VO VSEH RAZRYADAH EDINICI
	MOVX @DPTR,A
	CALL DELAY_1
	MOV A,#0		;OFF ALL INDICATORS
	MOVX @DPTR,A
	CALL DELAY_1
	DJNZ R3,CYKLE
RET

CLEAR:
	MOV R4,#C_CLEAR
	MOV DPTR,#NACHALO
	MOV A,#0FFh
CUCLE:
	MOVX @DPTR,A
	INC DPTR
	DJNZ R4,CUCLE
RET

NACH_ZNACH:
	MOV A,#45
	MOV DPTR,#NACHALO
	MOVX @DPTR,A
	INC DPTR
	MOV A,#0
	MOVX @DPTR,A
	INC DPTR
	MOV A,#90
	MOVX @DPTR,A
	INC DPTR
	MOV A,#30
	MOVX @DPTR,A
	INC DPTR
	MOV A,#60
	MOVX @DPTR,A
RET

PEREVOD:
	MOV R0,FI_Z
	MOV A,R0
	SWAP A
	ANL A,#00001111b
	MOV B,#10
	MUL AB
	MOV B,A
	MOV A,R0
	ANL A,#00001111b
	MOV R0,A
	MOV A,B
	ADD A,R0
	MOV FI_Z,A
RET

END