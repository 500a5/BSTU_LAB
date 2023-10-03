
TIME EQU 100            ;0,1ms
N_SEC DATA 37h          ;YACHEIKA PAMATI SCHITAUSCHYAIA 1sec 100*5ms=500ms clrSEC, ZATEM 500ms setbSEC
C_SEC EQU 100           ;CONSTANTA DLYA SECUNDOMERA

 org 00h
 jmp start

 org 8100h

 start:
        mov DPTR,#03h   ;Выбор регистра управления в 55-ом
        mov A,#82h      ;Выбор команды (B-ввод,C-вывод, A-вывод)
        movx @DPTR,A
        MOVX @DPTR,A
        MOV A,TMOD
        ORL A,#00000111b
        MOV TMOD,A                      ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT NA RXD,TXD

        mov P1,#01010000b

        ;clr A
        ;mov th0,A
        ;mov TL0,A
        ;mov P1,#10100000b
        ;MOV TH0,#NOT(TIME-1)
        ;setb tr1
        ;jnb tf1,$
        ;mov P1,#00h
        ;MOV N_SEC,#C_SEC               ;ZADANIE NACHAL'NOGO ZNACHENIA DLYA SECUNDOMERA
        ;clr TF1

       ;sjmp start


;Преобразование числа



 end