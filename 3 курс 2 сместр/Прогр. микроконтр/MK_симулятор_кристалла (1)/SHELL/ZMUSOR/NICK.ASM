start_tormoz_length EQU 2Fh
start_imp_length EQU 2Eh
sector EQU R7                           ;ychastok
kol_obor EQU 2Dh
time_counter1 EQU R4
time_counter2 EQU R6
speed EQU 2Ch

ORG 00h
JMP START

org 000BH
jmp COUNTER

org 001Bh
jmp TIMER

ORG 8100h

START:
                mov DPTR,#3
                mov A,#82h
                movx @DPTR,A
                mov DPTR, #2

                mov R5, #15;���.����� ��������
                mov start_imp_length, R5
                mov A, #255
                subb A, R5
                mov R0, A ;counter_space
                mov R3, A ;counter_decrement
                mov start_tormoz_length, A

                mov R2, #1 ;counter_impuls
                mov kol_obor, #0

        mov sector, #0

        mov TMOD,#00100111b
        mov IE, #10011010b ;razresheniye preryvaniya

        setb P1.5
        setb P1.7

        clr P1.4
        clr P1.6

        mov TH0, #5
        setb TR1
        mov TL0, #5
        setb TR0

vivod:
        mov A, speed
        mov B,#10
        div AB

        add A, #01000000b
        movx @DPTR, A
        nop
        nop
        mov A, B
        add A, #10000000b
        movx @DPTR, A
        nop
        nop
        jmp vivod

        jmp $

COUNTER:
        inc kol_obor
        mov TL0, #5
RETI

TIMER:
        inc time_counter1
        cjne time_counter1,#255,label_select
        inc time_counter2
        mov time_counter1, #0
        cjne time_counter2,#16,label_select
        mov time_counter2,#0
        mov R1, A
        mov A,kol_obor
        mov B, #2
        mul AB
        mov speed, A
        mov kol_obor,#0
        mov A, R1

        label_select:
        cjne sector,#0,label1
        call razgon

        label1:
        cjne sector,#1,label2
        call constant

        label2:
        cjne sector,#2,label3
        call tormoz

        label3:
        mov TH0, #5
RETI

razgon:
        jb P1.6,INTERVAL
        dec R2
        cjne R2,#0,NEXT
        inc R5
        mov A, R5
        mov R2, A
        setb P1.6
        clr P1.7
        jmp NEXT

        INTERVAL:
        dec R0
        cjne R0,#0,NEXT
        dec R3
        mov A,R3
        mov R0,A

        setb P1.7
        clr P1.6

        cjne R3,#0,NEXT
        mov R7,#1

        mov R0, #255
        mov R3, #255

NEXT:
RET

constant:
        setb P1.5
        setb P1.7
        clr P1.4
        clr P1.6

        dec R0
        cjne R0,#0,const_end
        dec R3
        mov A,R3
        mov R0,A

        cjne R3,#0,const_end
        mov R7,#2

        mov R0, #254
        mov R2, #255
        mov R3, #255
        mov R5, #255
const_end:
RET

tormoz:

jb P1.6,INTERVAL_t

        dec R2
        cjne R2,#15,tormoz_end
        dec R5
        mov A, R5
        mov R2, A
        setb P1.6
          clr P1.7
        jmp tormoz_end

        INTERVAL_t:
        inc R0
        cjne R0,#255,tormoz_end
        dec R3
        mov A,R3
        mov R0,A

        setb P1.7
        clr P1.6

        cjne R3,#15,tormoz_end
        mov R7,#0

        clr P1.4
        clr P1.6
        setb P1.5
        setb P1.7


        mov R0, #255
        mov R2, #50
        mov R3, #255
tormoz_end:
RET

END