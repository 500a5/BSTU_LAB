	ORG 0
	MOV R1,#8
	mov r0,#24
	mov dptr,#100
mo:	mov a,#0
	movc a,@a+dptr
	mov @r0,a
	inc r0
	inc dptr
	djnz r1,mo
	jmp$
	end