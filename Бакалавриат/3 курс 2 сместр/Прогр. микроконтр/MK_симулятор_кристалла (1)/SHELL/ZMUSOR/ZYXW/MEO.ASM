des DATA 34h
edin DATA 35h
TIME EQU 5000
a_now DATA 31h
a_zad DATA 32h

ORG 0h
JMP START
ORG 8100h
START:
		call stop
        MOV A,#10000010b
        MOV DPL,#3                   ;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
        MOVX @DPTR,A
        MOV A,#00010001b
        MOV DPL,#0                    ;NASTROIKA KOMUTATOROV NAPRYASHGENIA
        MOVX @DPTR,A
        MOV A,TMOD
        ORL A,#0000001b
        MOV TMOD,A                      ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT
        setb SM0
        setb REN
        mov A,IE
        orl IE, #10000010b ;razresheniye preryvaniya
        MOV TH0,#HIGH(NOT(TIME-1))
        MOV TL0,#LOW(NOT(TIME-1))
		MOV R0,#99h		
		pnt: call proverka
		call read_with_acp
		call vivod
		MOV A,a_zad
		cjne A,#99h,cycle
		sjmp pnt
cycle:
	call read_with_acp
	call vivod
	call sravn
	jb P1.7,cycle
	jb P1.6,cycle
	MOV R0,#99h		
	pnt2: call proverka
	call read_with_acp
	call vivod
	MOV A,a_zad
cjne A,#99h,cycle
sjmp pnt2

vivod:

MOV DPTR,#0002H ; Адрес регистра С

MOV A,a_now
ANL A,#0F0H
SWAP A
ORL A,#10H
MOVX @DPTR,A
call TIMER


MOV A,a_now
ANL A,#0FH
ORL A,#20H
MOVX @DPTR,A
call TIMER

ret

sravn:
MOV R1,a_zad
MOV R3,a_now
sr1: dec R1
	 MOV A,R1
	 jz n_zad
	 dec R3
	 MOV A,R3
	 jz n_now
	 sjmp sr1
n_zad: dec R3
	   MOV A,R3
	   jnz n_zad2
	   call stop
	   sjmp sr_ex
n_zad2: call nazad
		sjmp sr_ex
n_now: call vpered
	 
sr_ex:
ret


read_with_acp:
SETB P1.0 ; Инициализация порта Р1.0
SETB P1.1 ; Инициализация порта Р1.1
CLR C ; Сбос  С
CLR P1.0 ; Запуск АЦП

ACP: JB P1.1, ACP ; Ждём сигнала с АЦП

MOV DPTR,#01h; Если пришёл сигнал от АЦП выбираем регистр В
MOVX  A,@DPTR ; Загружаем содержимое регистра В в регистр А
MOV R1,A
MOV B,#8d
DIV AB	;perevod v ugol
ADD A,R1
MOV R2,A
ANL A,#0FH
MOV 2FH,A
MOV A,R2
JNB 2FH.3,rwa_ex
JB 2FH.2,rwa_izm
JB 2FH.1,rwa_izm
sjmp rwa_ex
rwa_izm:
	MOV A,R2
	CLR C
	SUBB A,#0Ah
	ADD a,#10h
rwa_ex:
MOV a_now,A
ret



Timer:
setb TR0
JNB TF0,$
CLR TF0
CLR TR0        
MOV TH0,#HIGH(NOT(TIME-1))
MOV TL0,#LOW(NOT(TIME-1))
ret

proverka:
 MOV a_zad,R0
 MOV A,R0
 jz pp2
 MOV R1,#0
 pp: inc R1
	 dec A
	 jz pp2
	 cjne R1,#90h,pp
	 MOV a_zad,#99h
 pp2:
ret

stop:
        clr P1.6
        clr P1.7
ret

vpered:
        clr P1.7
        setb P1.6
ret

nazad:
        clr P1.6
        setb P1.7
ret

exit:
END