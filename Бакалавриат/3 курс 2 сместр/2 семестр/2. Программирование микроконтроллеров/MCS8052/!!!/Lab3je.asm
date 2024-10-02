org 0
ljmp start

org 000Bh
	ljmp m1



org 8100h
start:

; автозаполнение значений графика функции во внешнюю пам€ть------------------------------------
    mov r5, #0
	MOV R0, #10
	mov A,#1
    mov dptr,#8200h 
	
M7:	
    mov r6,#10
m17:
	
	movx @dptr,A
	inc r5	
	inc DPTR
	mov R7, A
	mov A,#0
	movx @dptr,A
	mov A,R7
	inc DPTR
	inc r5
	djnz r6, m17
	dec A
	djnz R0,M7
	
	MOV R0, #5
    
M8:	
    mov r6,#10
m18:
	
	movx @dptr,A
	inc r5	
	inc DPTR
	mov R7, A
	mov A,#0
	movx @dptr,A
	mov A,R7
	inc DPTR
	inc r5
	djnz r6, m18
	inc A
	djnz R0,M8
	
	MOV R0, #30
	mov A, #20
M9:	
    mov r6,#10
m19:
	
	movx @dptr,A
	inc r5	
	inc DPTR
	mov R7, A
	mov A,#1
	movx @dptr,A
	mov A,R7
	inc DPTR
	inc r5
	djnz r6, m19
	djnz R0,M9
	
	MOV R0, #30
	mov A, #40
	
	M10:	
    mov r6,#10
m20:
	
	movx @dptr,A
	inc r5	
	inc DPTR
	mov R7, A
	mov A,#1
	movx @dptr,A
	mov A,R7
	inc DPTR
	inc r5
	djnz r6, m20
	djnz R0,M10
	
	MOV R0, #30
	mov A, #60
	
	M11:	
    mov r6,#10
m21:
	
	movx @dptr,A
	inc r5	
	inc DPTR
	mov R7, A
	mov A,#1
	movx @dptr,A
	mov A,R7
	inc DPTR
	inc r5
	djnz r6, m21
	djnz R0,M11

; конец автозаполнени€-----------------------------------------------------------------------------------------------	
; начало программы	
	setb ea
 mov a,tmod
 clr acc.0
clr acc.1
clr acc.2
clr acc.3

    mov tmod,a
	setB IE.7
	setB IE.1
	
	setB tcon.4
    mov dptr, #000h
m6:	
	movx a, @dptr
	mov r3, a
	inc dptr
	movx a, @dptr
	mov r1, a ; в регистре теперь хранитьч€ 0 или 1 котора€ отвечает за сторону вращени€
	mov a, #255
	
	
	subb a,r3
	mov r0,a
	mov a,r3
	
	cjne r1,#0, crut
t9:
	
	setB p1.7
	setB p1.5
	jnz t9
    mov a,r0
	
t8:	
	
	clr p1.7
	clr p1.5
	jnz t8
cob:	
	inc dptr
	djnz r5,m6
jmp $

crut:
    t19:
	
	setB p1.6
	setB p1.4
	jnz t19
    mov a,r0
	
t18:	
	
	clr p1.6
	clr p1.4
	jnz t18
jmp cob

m1: 
	dec a
reti


end