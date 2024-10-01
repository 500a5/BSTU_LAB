	org 00h
	jmp begin
	org 8100h
begin:
	clr rs0
	clr rs1
	mov dptr,#03h
	mov A,#10000010b
	movx @dptr,A
	mov dptr,#00h
	mov A,#00010000b
	movx @dptr,a
strob:
	setb P1.0
	clr P1.0
	jb P1.1,$
read:	
	mov dptr,#01h
	movx A,@dptr
	mov r1,#020h
	mov r2,#040h
	mov r3,#080h
	subb A,#080h
	jnc setplus
	cpl A
setminus:
	mov r4,#01ah	;r4-знак(минус)
setplus:
	mov r4,#01ch	;r4-знак(плюс)
	mov B,#04h
	mul AB
hextodec:
	mov r0,A
	clr acc.0
	clr acc.1
	clr acc.2
	clr acc.3
	add A,B
	swap A
	mov B,#0Ah
	div AB
	xch A,r0
	clr acc.4
	clr acc.5
	clr acc.6
	clr acc.7
	xch A,B
	swap A
	add A,B
	mov B,#0Ah
	div AB
	mov r5,A
	mov A,B
	add A,r3
	mov r3,A		;r3-единицы
	mov A,r5	
	xch A,r0
	swap A		
	add A,r0
	mov B,#0Ah
	div AB
	add A,r1
	mov r1,A		;r1-сотни
	mov A,B
	add A,r2
	mov r2,A 		;r2-десятки
out:	
	mov dptr,#02h
	mov A,r4		
	movx @dptr,a	;вывод знака
	call delay
	mov A,r1
	movx @dptr,a	;вывод сотен
	call delay
	mov A,r2
	movx @dptr,a	;вывод десятков
	call delay
	mov A,r3
	movx @dptr,a	;вывод единиц
	call delay
	jmp strob
delay:
	mov r6,#5
cikl1:	
	mov r7,#100
cikl2:
	djnz r7, cikl2
	djnz r6, cikl1
ret
end	
