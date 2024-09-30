.386 
.model flat, stdcall 
option casemap: none 
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\windows.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\kernel32.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\user32.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\msvcrt.inc
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\user32.lib
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\kernel32.lib
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\msvcrt.lib
.DATA 
	x db 1
	z db -2
	y dd 0
	format db "a = %d", 0
.CODE
START:
	MOVSX EAX, x			;EAX = x
	MOVSX EBX, z 			;EBX = z
	MOV ECX, y				;ECX = y
	
	CDQ 
	
	CMP EAX, 0
	JGE one					;EAX >= 0
	
	CMP EBX, 2
	JL three
	
	CMP EBX, 8
	JG three
	
	
	
	IMUL ECX			;EDX:EAX = EAX*ECX = xy
	ADD EBX, 1			;EBX = EBX + 1 = z+1
	
	ADD EAX, EBX 		;z+1+xy
	ADC EDX, 0
	
	JMP j_out
	
one:
	MOV EAX, y
	MOVSX ECX, x			;ECX = x
	;CDQ
	
	IMUL EAX ;YY
	ADD EAX, ECX ;EAX = ECX+EAX = yy+xy
	ADC EDX, 0	
	
	MOV ECX, EAX
	MOV EAX, 1
	IDIV ECX 		;1/yy+x
	
	MOV ECX, EAX
	
	MOV EAX, EBX
	;CDQ
	
	MUL EAX
	MUL EBX 
	
	ADD EAX, ECX
	
	JMP j_out

three:
	MOV ESI, 7
	MUL ESI	;EDX:EAX = EAX * ESI = 7*x
	
	MOV ECX, EAX
	MOV EDI, EDX	;7*x
	
	MOV EAX, EBX 	;EAX = Z
	;CDQ
	
	MOV ESI, 2
	MUL ESI	;EDX:EAX = EAX * ESI = 2*z

	SUB ECX, EAX
	SUB EDI, EDX
	
	MOV EAX, ECX 
	JMP j_out
	; 2 1 -2 = 1
	; 1 3 5 = 124.1
	; -2 4 9 = -32
j_out:
	push EAX
	push offset format
	call crt_printf 	;Вывод результата на экран
	call crt__getch 	;Задержка ввода
	push 0
	call ExitProcess 	;Выход из программы
END START






















