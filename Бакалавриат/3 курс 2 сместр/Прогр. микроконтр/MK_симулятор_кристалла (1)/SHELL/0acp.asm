	ORG 0h
	JMP START
	
	org 0Bh
	ljmp timer_interrupt

	org 8100h
START:
	setb EA
	setb ET0
	orl TMOD, #00000001b
	mov TH0, #0FCh
	mov TL0, #17h

	call stop
	MOV A, #10000010b
	MOV DPL, #3
	MOVX @DPTR, A
	MOV A, #00010001b
	MOV DPL, #0
	MOVX @DPTR, A
	MOV A, TMOD
	ORL A, #00000001b
	MOV TMOD,A 

	clr PSW.3
	clr PSW.4
	mov a, #0
	mov dptr, #8600h
	movx  @dptr, A

main:
	mov dptr, #8600h
	movx A, @dptr
	jnz go
	call ACP
	call print
	jmp main

	mov R1, 0
	mov @100, 0
mk1:
	mov R0, 0
	cjne R0, @100, $
	
	mov R0, 255
	mov A, R0
	subb A, @100
	mov @101, A
	mov R0, 0
	cjne R0, @101, $
	inc @100

	inc R1
	cjne R1, 100, mk1

go:
	mov dptr, #8600h
	movx A, @dptr
	mov B, A
	mov A, R0
	cjne A, B, m1
	jmp stoim
m1:
	inc b
	cjne A, B, m2
	jmp stoim
m2:
	dec b
	cjne A, B, m3
	jmp stoim
m3:
	subb A, B
	jc m4
	call back
	jmp stoim
m4:
	call forward
stoim:
	call ACP
	call print
	jmp go

ACP:
	SETB P1.6
	SETB P1.7
	CLR C 
	CLR P1.7
	JB P1.6, $

	MOV DPTR, #01h
	MOVX A, @DPTR
	mov R0,A
	mov B, #10
	div AB
	mov R7, B
	mov B, #7
	mul AB
	mov R0, A
	mov A, R7
	mov B, #7
	mul AB
	mov B, #10
	div AB
	subb A, R0
	mov R0, A
	mov R6, #0b

delenie:
	mov R7, A
	INC R6
	subb A, #00001010b
	jnc delenie
	DEC R6
ret

print:
	mov DPTR, #2
	MOV A, R6
	ANL A, #00001111b
	ORL a, #01000000b
	MOVX @DPTR, A
	CALL pause
	mov A, #0h
	movx @DPTR, A
	MOV A,R7
	ANL A, #00001111b
	ORL A, #10000000b
	MOVX @DPTR, A
	CALL pause
	mov A, #0h
	movx @DPTR, A
ret

pause:
       MOV TH0, #HIGH(64000)
       MOV TL0, #LOW(64000)
       SETB TR0
       JNB TF0, $
       CLR TF0
       CLR TR0
RET

stop:
	setb P1.6
	setb P1.7
ret

forward:
	clr P1.7
	setb P1.6
ret

back:
	clr P1.6
	setb P1.7
ret

timer_interrupt:
	clr TR0
	inc R0
	mov TH0, #0FCh
	mov TL0, #17h
	setb TR0
	reti

END