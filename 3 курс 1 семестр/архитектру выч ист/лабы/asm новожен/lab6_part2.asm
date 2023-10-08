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
t db "%.2X:", 0
a db 40 dup(1)
b dd 0
res db 80 dup(?)
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
	MOV EAX, [ESP+4*5]
	MOV ECX, [ESP+4*6]; ����� �� ����� ��������, �.�. �����, �������
	;����� ������� � �������� �������������
	;MOV ECX, N ; ����� ������� 16-������ �����, ��������� ����.
	;�������� � ECX ���������� ��������
	XOR EDI,EDI
j1:
	;ROL AX, 1 ; ������� ����������� ����� ����� �� ���� ������ �����. 
	;����� ������� ������� ��� ������ �� ����� ��������
	;MOV BX, AX ; BX = AX
	;AND BX, 1b;0000 0000 0000 0001b ; �������� ������ ������� ���, ��������� ��������
	XOR EBX,EBX
	MOV BL, [EAX+EDI] ;[EAX+EDI];[EAX+ECX-1] ; ��������� � BX ��� ������� "0"
	; ������� ��� ������ ������� �� ����� crt_putch
	;�������� �������� EAX � ECX, ������� ����� ��������� �� � �����
	INC EDI
	PUSH EAX 
	PUSH ECX
	
	; ��������� ��������� ������ � ����, �.�. �������� ���
	;� �������� ��������� ������� crt__putch
	PUSH EBX 
	PUSH offset t
	CALL crt_printf ; ������� �������
	ADD ESP, 8; ������� �������� �� �����, ��� ��� ������� crt__putch ����� �� ������
	POP ECX ; ������������ ECX
	POP EAX ; ������������ EAX
	LOOP j1 ; ECX = ECX - 1 ��������� ���� ���� ECX > 0
	POP ECX ; ������������ ECX
	POP EBX ; ������������ EBX
	POP EAX ; ������������ EAX
	POP EDX
	RET 8 ; ������� � �������� ��������� � ������� ����� �� ��������� �������� 4 �����
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






;������� ���������:  a � ����� ������� ����� � ������, n � ������� ������. 
;�������� ���������: res � ����� �������, ���� ������������ ���������.
multiplication proc ;multiplication(char* a, int n, char* res) ��� �����
	PUSH EAX; SAVE
	PUSH EDX; SAVE
	PUSH ESI; SAVE
	PUSH EDI; SAVE
	PUSH ECX; SAVE
	PUSH EBX; SAVE
	MOV ESI,[ESP +4*7]; GET CHAR *a
	MOV ECX,[ESP +4*8]; GET INT n
	MOV EDI,[ESP +4*9]; GET CHAR *res
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CMP ECX,80
	JGE j9
	
	PUSH ECX
	MOV ECX,40
	jk:
	MOV DL,[ESI+ECX-1]
	MOV[EDI+ECX-1],DL	
	LOOP jk
	POP ECX
	
fr:
	PUSH ECX
	MOV ECX ,80
	DEC ECX
	SHR BYTE PTR[EDI],1
	MOV EBX,0
	
	lp:
	INC EBX
	RCR BYTE PTR[EDI+EBX],1
	LOOP lp
	
	
	POP ECX
	LOOP fr
	
;	SHR [ESI],1
	
j9:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	POP EBX;RETURN VALUE 
	POP ECX;RETURN VALUE
	POP EDI;RETURN VALUE
	POP ESI;RETURN VALUE
	POP EDX;RETURN VALUE
	POP EAX;RETURN VALUE
	RET 12
multiplication endp 
START:
	;AFTER
	MOV EAX,40
    PUSH EAX
	PUSH OFFSET a
	CALL output
	CALL new_line
	
	
	

	MOV ECX,2
	PUSH OFFSET res
	PUSH ECX
	PUSH OFFSET a
	CALL multiplication
	CALL new_line
	;BEFORE
	MOV EAX,80
    PUSH EAX
	PUSH OFFSET res
	CALL output
	CALL new_line
	CALL crt__getch
	push NULL
	call ExitProcess
END START