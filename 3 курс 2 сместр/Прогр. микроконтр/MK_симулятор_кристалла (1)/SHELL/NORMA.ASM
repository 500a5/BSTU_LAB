ORG 0h
JMP START

org 8100h
START:
       call stop
       MOV A,#10000010b
       MOV DPL,#3
       MOVX @DPTR,A
       MOV A,#00010001b
       MOV DPL,#0
       MOVX @DPTR,A
       MOV A,TMOD
       ORL A,#0000001b
       MOV TMOD,A

clr PSW.3
clr PSW.4  ; выбор банка
mov a,#0
mov dptr, #8600h;
movx  @dptr,A;

glavnii:
mov dptr, #8600h;
movx A, @dptr;
jnz dvijenie
call ACP
call vivod
jmp glavnii

dvijenie:
mov dptr, #8600h;
movx a,@dptr;
mov b,a
       mov A,R0
       cjne A,B,m1
       call stop
       jmp stoim
m1:
        dec a
        cjne a,b,m2
        call stop
        jmp stoim
m2:
        inc a
        inc a
       cjne A,B,dvij
       call stop
       jmp stoim
       dvij:
              mov A,R0
              subb A,B
              jc vp
                call nazad
                jmp stoim
                vp:
                 call vpered
         stoim:
call ACP
call vivod
jmp dvijenie


ACP:
       SETB P1.0
       SETB P1.1
       CLR C
       CLR P1.0
       JB P1.1, $ ; ∆дЄм сигнала с ј÷ѕ

       MOV DPTR,#01h
       MOVX  A,@DPTR
       mov R0,A;  сигнал с ацп
        mov B,#10;
        div Ab
        mov b, #10
        mul ab
        mov b,a
        MOV A, R0
        SUBB A,B
        mov b,#7
        mul ab
        mov b, #10
        div ab
        mov r7,a
        mov a, r0
        mov b, #10
        div ab
        mov b, #7
        mul ab
        add a,r7
        mov r0,a
        mov  R6, #0b
delenie:
mov R7, A
INC R6
subb a, #00001010b
jnc delenie
DEC R6
ret

vivod:
       mov DPTR,#2
       MOV A,R6
        ADD A, #01000000b
       MOVX @DPTR,A
       CALL jdem
       MOV A,R7
        ADD A, #10000000b
       MOVX @DPTR,A
       CALL jdem
ret

jdem:
       MOV TH0,#HIGH(64000)
       MOV TL0,#LOW(64000)
       SETB TR0
       JNB TF0,$
       CLR TF0
       CLR TR0
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