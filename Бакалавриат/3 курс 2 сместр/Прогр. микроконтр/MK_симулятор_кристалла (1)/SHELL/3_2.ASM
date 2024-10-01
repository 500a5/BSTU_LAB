des DATA 34h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
edin DATA 35h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
TIME EQU 5000           ;5ms
time_0_to_90 DATA 31h
time_90_to_0 DATA 32h

ORG 0h
JMP START
org 000Bh
jmp TIMER

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


povtor:
mov R1,#0
call read_with_acp
jz since_0_to_90
call nazad
jmp povtor

since_0_to_90:

setb TR0
call vpered
call read_with_acp
cjne A,#80h,since_0_to_90
mov time_0_to_90,R1
mov R1,#0

since_90_to_0:

setb TR0
call nazad
call read_with_acp
cjne A,#0h,since_90_to_0
mov time_90_to_0,R1
mov R1,#0
call stop
m3: cjne R1,#30,m2
jmp m_end
m2: call vivod
    jmp m3
m_end:
clr TR0
mov R1,#0
jmp start


vivod:

MOV DPTR,#0002H ; Адрес регистра С

MOV A,time_0_to_90
MOV B,#10
div AB
ORL A,#10H
MOVX @DPTR,A
cjne R2,#1,$


MOV A,B
ORL A,#20H
MOVX @DPTR,A
cjne R2,#2,$


MOV A,time_90_to_0
MOV B,#10
div AB
ORL A,#40H
MOVX @DPTR,A
cjne R2,#3,$


MOV A,B
ORL A,#80H
MOVX @DPTR,A
cjne R2,#4,$

mov R2,#0
ret




read_with_acp:
SETB P1.0 ; Инициализация порта Р1.0
SETB P1.1 ; Инициализация порта Р1.1
CLR C ; Сбос  С
CLR P1.0 ; Запуск АЦП

ACP: JB P1.1, ACP ; Ждём сигнала с АЦП

MOV DPTR,#01h; Если пришёл сигнал от АЦП выбираем регистр В
MOVX  A,@DPTR ; Загружаем содержимое регистра В в регистр А

ret



Timer:
        inc R0
        inc R2
        cjne R0,#200,m1
    inc R1
        mov R0,#0
m1:     MOV TH0,#HIGH(NOT(TIME-1))
    MOV TL0,#LOW(NOT(TIME-1))
RETI


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