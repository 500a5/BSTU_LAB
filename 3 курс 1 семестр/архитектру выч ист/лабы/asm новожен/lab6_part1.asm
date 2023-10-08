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
s db 13, 10, 0

.CONST
N dd 16
.CODE

; ��������� ��� ������ ��������� ������������� 16-������� �����
; void output (int a). ��������� � �������� ���������
;���������  32-��������� ����� �����, �� � ���������
;������������ ������ 2 ������x ����f �����, ��������� ������������
output proc
;��������� � ����� �������� ���������, ������� �����
;������������
    PUSH EDX ; ��������� EAX
	PUSH EAX ; ��������� EAX
	PUSH EBX ; ��������� EBX
	PUSH ECX ; ��������� ECX
	XOR EBX, EBX ; �������� EBX
	MOV AX, [ESP+4*5] ; ����� �� ����� ��������, �.�. �����, �������
	;����� ������� � �������� �������������
	MOV ECX, N ; ����� ������� 16-������ �����, ��������� ����.
	;�������� � ECX ���������� ��������
j1:
	ROL AX, 1 ; ������� ����������� ����� ����� �� ���� ������ �����. 
	;����� ������� ������� ��� ������ �� ����� ��������
	MOV BX, AX ; BX = AX
	AND BX, 1b;0000 0000 0000 0001b ; �������� ������ ������� ���, ��������� ��������
	ADD BX, '0' ; ��������� � BX ��� ������� "0"
	; ������� ��� ������ ������� �� ����� crt_putch
	;�������� �������� EAX � ECX, ������� ����� ��������� �� � �����
	PUSH EAX 
	PUSH ECX
	
	; ��������� ��������� ������ � ����, �.�. �������� ���
	;� �������� ��������� ������� crt__putch
	PUSH EBX 
	CALL crt__putch ; ������� �������
	ADD ESP, 4 ; ������� �������� �� �����, ��� ��� ������� crt__putch ����� �� ������
	POP ECX ; ������������ ECX
	POP EAX ; ������������ EAX
	LOOP j1 ; ECX = ECX - 1 ��������� ���� ���� ECX > 0
	POP ECX ; ������������ ECX
	POP EBX ; ������������ EBX
	POP EAX ; ������������ EAX
	POP EDX
	RET 4 ; ������� � �������� ��������� � ������� ����� �� ��������� �������� 4 �����
output endp

new_line proc
	PUSH EDX
	PUSH EAX
	PUSH ECX
	PUSH offset s
	CALL crt_printf
	ADD ESP, 4
	POP ECX
	POP EAX 
	POP EDX
	RET 0
new_line endp

START:
	XOR EAX,EAX
	XOR EDX,EDX
	XOR EDI,EDI
	XOR ECX,ECX
	MOV ECX,N; ECX=16
	MOV EAX,1
j2:
	PUSH ECX;SAVE 
	PUSH EAX;OUTPUT
	CALL output
	CALL new_line;NEW LINE
	MOV DX,AX; DX=AX
	DEC ECX; --ECX
	CMP ECX,0
	je j4
	j3:	
		SHL DX, 1
		MOV DI,DX
		OR DI,AX
		PUSH EDX
		PUSH EDI
		CALL output
		POP EDX
		CALL new_line
		LOOP j3
	j4:
	SHL AX, 1
	POP ECX ;RETURN ECX
	LOOP j2
	CALL crt__getch
	push NULL
	call ExitProcess
END START