cseg at 0h
jmp start

org 8100h
start:
mov dptr,#03h
mov a,#82h
movx @dptr,a
mov a,#0h
	clr rs0
	clr rs1
	mov 50h,#10h
	mov 51h,#20h
	mov 52h,#40h
	mov 53h,#80h
	mov 45h,#0h
mov tmod,#00100110b
;основная программа
	call perevod	;перевод
	call zapis		;запись
zp2:	call zaderjka	;задержка
	mov r0,#49h
	mov a,@r0
	cjne a,48h, zp1
	call schet
	call konvert
	call out
	jmp zp2
zp1:	call perevod	;перевод
	call zapis	;запись
	jmp zp2


schet:	;++++++++процедура подсчета++++++++
setb tcon.4

mov r0,#80d
sch1:
mov R1,#100d
sch2:
djnz r1,sch2
djnz r0,sch1
clr tr0
	mov a,Tl0
	mov 45h,a
mov tl0,#0h
mov th0,#0h
ret

konvert:
	clr RS0
	SetB RS1	;перешли в другой банк регистров
	mov r0,#40h
	mov a,45h
	mov b,#12h
	 div ab
	 mov b,#10d
	div ab
	 jz knachalo1
	 nop
	mov @r0,a
	 inc r0
	jmp knachalo
	nop
knachalo1: mov a,45h
	mov @r0,#0
	inc r0
knachalo:    mov b,#12h
	div ab
	mov @r0,a
	clr a
	xch a,b
	mov b,#10d
	mul ab
	mov b,#0h
	inc r0
	cjne r0,#45h,knachalo
	Clr RS1 	;вернули исходный банк регистров
ret

output:
	mov r1,#50h
	mov a,#01h
	subb a,40h
	jz out1
	nop
	jnz out2
 out1:	mov r0,#40h
	jmp onachalo
 out2:	mov r0,#41h
	jmp onachalo
	mov a,#00h
onachalo:    mov a,@r0
	add a,@r1
	mov dptr,#02h
	movx @dptr,a
	call delai
	inc r0
	inc r1
	mov a,#0
	cjne r1,#54h,onachalo
ret

delai:
mov r3,#0ffh
d1: djnz r3,d1
mov r3,#0ffh
d2: djnz r3,d2
mov r3,#0ffh
d3: djnz r3,d3
mov r3,#0ffh
d4: djnz r3,d4
mov r3,#0ffh
d5: djnz r3,d5
mov r3,#0ffh
d6: djnz r3,d6
mov r3,#0ffh
d7: djnz r3,d7

ret

perevod:	;+++++++паревод из dec в bin систему+++++++++++
	mov R0,#48h
	mov A,@R0	;считали число
	mov r0,#49h
	mov @r0,A
;переведем в bin систему
	clr c
	rrc a
	mov 22h,c
	rrc a
	mov 21h,c
	rrc a
	mov 20h,c
;Закончили перевод в bin. биты 20,21,22
;писать в порядке 20,21,22
ret

zapis:
	clr p1.6
	clr p1.7
	mov r1,#4h
vp5:	setb p1.6
	call zaderjka
	clr p1.6
	call zaderjka
	djnz r1,vp5		;пустые прошли
	jb 20h,loop7	;пошли писать нужные
	clr P1.7
	jmp loop8
loop7:	Setb P1.7
loop8:	nop
	nop
	nop
	Setb P1.6
	call zaderjka
	Clr P1.6
	call zaderjka
	jb 21h,loop9
	clr P1.7
	jmp loop10
loop9:	Setb p1.7
loop10: nop
	nop
	nop
	Setb P1.6
	call zaderjka
	Clr P1.6
	call zaderjka
	jb 22h,loop11
	clr P1.7
	jmp loop12
loop11: setb P1.7
loop12: nop
	nop
	nop
	Setb P1.6
	call zaderjka
	Clr P1.6
	call zaderjka	;
;=======Записали (канал выбран)=======
	ret

zaderjka:	;++++++++задержка+++++++++++
	mov R0,#255
zad:	nop
	nop
	djnz r0,zad
ret

out:
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
	call output
	call delai
ret

end