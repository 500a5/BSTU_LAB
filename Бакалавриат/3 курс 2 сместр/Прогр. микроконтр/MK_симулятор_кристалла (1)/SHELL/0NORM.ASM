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
       jmp stoim
m1:
	inc b
       cjne A,B,m2
       jmp stoim
m2:
	dec b
	dec b
       cjne A,B,dvij
       jmp stoim
       dvij:
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
	;SETB P1.6
       SETB P1.1
	;SETB P1.7
       CLR C 
       CLR P1.0
	;CLR P1.7 
       JB P1.1, $ ; ∆дЄм сигнала с ј÷ѕ
	;JB P1.6, $ ; ∆дЄм сигнала с ј÷ѕ

       MOV DPTR,#01h
       MOVX  A,@DPTR
       mov R0,A;  сигнал с ацп
	mov B,#10;
	div Ab
	mov r7,b
	mov b, #7
	mul ab
	mov r0,a
	mov a, r7
	mov b, #7
	mul ab
	mov b, #10
	div ab
	subb a,r0
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
	ANL A, #0001111b
	ORL a,#01000000b
       MOVX @DPTR,A
       CALL jdem
mov A, #0h
movx @DPTR, A
       MOV A,R7
	ANL A, #00001111b
	ORL a,#10000000b
       MOVX @DPTR,A
       CALL jdem
mov A, #0h
movx @DPTR, A
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