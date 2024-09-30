.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
.DATA
r dw -6248
s db 1
.CODE
START:
MOVSX EAX, r 
MOV EBX,EAX
XOR EAX,EAX
MOVSX EAX,s
XCHG EAX, EBX
CDQ
IDIV EBX
XOR EDX,EDX
ADC EAX,5*5*5*5*5
IMUL EAX
IMUL EAX
DEC EAX
push NULL
call ExitProcess
END START