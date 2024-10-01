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
OSTATOK DATA 38h
BUF DATA 39h

ORG 0h
JMP START


ORG 8100h
START:
       mov 040h,#35
       mov 041h,#71
       mov 042h,#0
       mov 043h,#107
       mov 044h,#0
       mov 045h,#255

       setb RS0
       setb RS1

        mov R0,#40h

        call stop
        MOV A,#10000010b
        MOV DPL,#3                   ;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
        MOVX @DPTR,A
        MOV A,#00010001b
        MOV DPL,#0                    ;NASTROIKA KOMUTATOROV NAPRYASHGENIA
        MOVX @DPTR,A
        MOV A,TMOD
          ORL A,#0000001b
          MOV TMOD,A                    ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT

povtor:
MOV TH0,#HIGH(NOT(TIME-1))
MOV TL0,#LOW(NOT(TIME-1))

SETB P1.0 ; Инициализация порта Р1.0
SETB P1.1 ; Инициализация порта Р1.1
CLR C ; Сбос  С
CLR P1.0 ; Запуск АЦП


ACP: JB P1.1, ACP ; Ждём сигнала с АЦП


MOV DPTR,#01h; Если пришёл сигнал от АЦП выбираем регистр В
MOVX  A,@DPTR ; Загружаем содержимое регистра В в регистр А
mov R1,A

call vivod
call dvigenie

cjne @R0,#255,povtor
call stop
jmp $

dvigenie:
        push ACC
        mov A,R1 ;isx
        mov B,@R0  ;zadannoe
        cjne A,B,next
        inc R0
        jmp dv_end

        next:
              subb A,B
              jc vp
                call nazad
                jmp dv_end
                vp:call vpered

        dv_end:pop ACC
ret

vivod:
       push ACC
        mov B,#10
        div AB
        mov OSTATOK, B
        mov B,#7
        mul AB
      mov B,#10
      div AB
      swap A
      add A,B
        mov BUF, A

        mov A, OSTATOK
      mov B,#7
        mul AB
      mov B,#10
        div AB

      mov B, BUF
        add A,B



        mov BUF,A
      anl A,#11110000b
      swap A
        mov des,A

      mov A,BUF
      anl A,#00001111b
        mov edin,A

        mov DPTR,#2

        MOV A,des
        ANL A,#00001111B
        ORL A,#40H
        MOVX @DPTR,A
        CALL DELAY

        MOV A,edin
        ANL A,#00001111B
        ORL A,#80H
        MOVX @DPTR,A
        CALL DELAY
        pop ACC
ret

DELAY:
        SETB TR0
        JNB TF0,$
        CLR TF0
        CLR TR0
        MOV TH0,#HIGH(NOT(TIME-1))
        MOV TL0,#LOW(NOT(TIME-1))
RET


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

END