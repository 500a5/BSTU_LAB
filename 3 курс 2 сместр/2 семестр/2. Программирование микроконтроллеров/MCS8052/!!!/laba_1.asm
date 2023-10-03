	org 0h
	; Save initial state of keyboard in R1-R4
	mov P0, #1h
	mov R1, P1
	mov P0, #2h
	mov R2, P1
	mov P0, #4h
	mov R3, P1
	mov P0, #8h
	mov R4, P1
	; Program main loop
start:
	mov P0, #1h
	mov R0, #1h
m1:
	; Check changes in input port
	mov A, P1
	xrl A, @R0
jz m3
	; Get a number of pressed key in row with number R0
	mov @R0, P1
	mov R5, #0h
m2:
	inc R5
	rrc A
jnz m2
	; Set to A value (row * 5 + col + 'A' - 1)
	mov A, R0
	mov B, #5h
	dec A
	mul AB
	add A, R5
	add A, #40h

	; Print to console
	mov SBUF, A
	clr TI
	mov SBUF, #13
	clr TI
	mov SBUF, #10
	clr TI
m3:
	; Go to next row of keyboard
	mov A, P0
	rl A
	mov P0, A
	inc R0
jnb P0.4, m1
jmp start
	end