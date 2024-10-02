.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
include E:\masm32\include\msvcrt.inc
includelib E:\masm32\lib\msvcrt.lib

.DATA
s db " sqrt(%d) = %10.7f ",13, 10, 0
x dd 0


.CODE


root proc
	PUSH EAX
	PUSH ECX 
	PUSH EDX
	PUSH EBX
	
	MOV ECX ,[ESP+20]
	XOR EBX,EBX
lop:
	INC EBX
	MOV dword ptr[x],EBX
	FILD [x]
	FSQRT 
	FSTP qword ptr [ESP] ; Вытолкнуть число типа Dfloat на вершину стека
	MOV EAX, [ESP] ; Скопировать в регистр
	MOV EDX, [ESP+4] ; Скопировать в регистр
	PUSH EDX
	PUSH EAX
	PUSH EBX
	PUSH offset s;ВЫВОД
	CALL crt_printf
	SUB ESP,8
	loop lop
	
	POP EBX 
	POP EDX
	POP ECX
	POP EAX
root endp

START:
XOR EDX,EDX
XOR ESI,ESI
XOR EDI,EDI
XOR ECX,ECX
MOV EAX,100


PUSH eax
CALL root
pop eax


CALL crt__getch
push NULL
call ExitProcess
END START