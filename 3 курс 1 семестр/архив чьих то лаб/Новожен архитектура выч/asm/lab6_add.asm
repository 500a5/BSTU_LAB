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
s db "    ",13, 10, 0
t db "%.2X:", 0
a dd -1;24448;0100h
b dd ?
kk db "%d",13, 10, 0
.CONST
N dd 32
.CODE



;my_BSR (int *a,int b)
my_bst proc
	PUSH EAX
	PUSH EDX
	PUSH ESI
	PUSH ECX
	PUSH EDI
	MOV ESI,[ESP+4*5+4]
	MOV EAX,[ESP+4*6+4]
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	MOV ECX,32
	MOV EDX,0
	MOV EDI,0
	
	fr:
	ROL EAX,1
	MOV EBX,EAX
	AND EBX,1h
	CMP EBX,1h
	JE j1
	INC EDI
	
	;MOV EDX,EAX
	;AND EAX,1
	LOOP fr
	
	CMP EAX,0
	JE j5
	JMP h
	j5:SUB EAX,EAX
	MOV EDI,0
	MOV ECX,1
	h:
	j1:
	DEC ECX
	MOV [ESI],ECX;EDI
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	POP EDI
	POP ECX
	POP ESI
	POP EDX
	POP EAX
	RET 8
my_bst endp

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
	MOV EAX, [ESP+4*5] ; ����� �� ����� ��������, �.�. �����, �������
	;����� ������� � �������� �������������
	MOV ECX, N ; ����� ������� 16-������ �����, ��������� ����.
	;�������� � ECX ���������� ��������
j1:
	ROL EAX, 1 ; ������� ����������� ����� ����� �� ���� ������ �����. 
	;����� ������� ������� ��� ������ �� ����� ��������
	MOV EBX, EAX ; BX = AX
	AND EBX, 1b;0000 0000 0000 0001b ; �������� ������ ������� ���, ��������� ��������
	ADD EBX, '0' ; ��������� � BX ��� ������� "0"
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
	;AFTER
	PUSH  a
	CALL output
	CALL new_line
	
	PUSH a
	PUSH offset b
	CALL my_bst
	
	PUSH  b
	PUSH offset kk
	CALL crt_printf
	ADD ESP,8
	;CALL output
	;CALL new_line
	
	BSR EAX,a
	
	PUSH  EAX
	;CALL output
	;CALL new_line
	PUSH offset kk
	CALL crt_printf
	ADD ESP,8
	CALL crt__getch
	push NULL
	call ExitProcess
END START