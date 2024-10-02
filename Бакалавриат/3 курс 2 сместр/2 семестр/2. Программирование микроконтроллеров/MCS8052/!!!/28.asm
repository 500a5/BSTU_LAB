	ORG 0
	MOV R2,#8
	mov r0,#24
	mov r1,#16
mo:	mov a,@r1
	xch a,@r0
	mov @r1,a
	inc r0
	inc r1
	djnz r2,mo
	jmp$
	end