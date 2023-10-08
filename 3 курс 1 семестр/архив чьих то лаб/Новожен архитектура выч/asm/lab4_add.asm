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
n dd ?
a dd ?
s dd 2 dup(?)  
output_format db "(%ld)^2 = %ld", 13, 10, 0
input_format db "%d %d", 0
.CODE


t proc
MOV EAX,[ESP+4];EAX
MOV EBX,[ESP+8];
CDQ
IMUL EBX
IMUL EAX
RET 8
t endp
;; EAX,EDX,EBX

cln proc
XOR EAX,EAX
XOR EDX,EDX
RET 0
cln endp

START:
PUSH offset a
PUSH offset n
PUSH offset input_format
CALL crt_scanf
ADD ESP,12
MOV ECX,n
XOR ESI,ESI
j1: 
INC ESI
PUSH ECX
MOV EAX,a
CDQ
IMUL ESI
PUSH  EDX
PUSH  EAX
CALL cln
PUSH ESI
PUSH  a
CALL t
POP EDI
POP EBX
PUSH EDX
PUSH EBX
PUSH EAX
PUSH EDI
PUSH offset output_format 
CALL crt_printf
ADD ESP, 4*5
CALL cln
XOR ECX,ECX
POP ECX
LOOPE j1
CALL crt__getch
push NULL
call ExitProcess
END START