.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
.DATA
x dd -20
y dw 44
z db 44
s db 8 dup(?) ; Для результата резервируется на один байт больше
res dd ?
.CODE
START:
CMP x,-15 ;x<-15
JL i1 ;IF TRUE
JMP j3

i1:;x<-15
CMP y,-10
JGE i2;IF операнд_1 ≥ операнд_2
JMP j2

i2:
CMP y,20
JLE j1; IF операнд_1 ≤ операнд_2
JMP j2


JMP j1
j1:
MOVSX EAX ,y
MOVSX EBX ,y
CDQ
IMUL EAX ;EAX=Y*Y
IMUL EBX,EBX,14 ;EBX=Y*14
IMUL EBX ;EAX=Y*14*Y*Y
IMUL x ;EAX=Y*14*Y*Y*X
MOV dword ptr s[0],EAX
MOV dword ptr s[4],EDX
JMP j_end

JMP j2 
j2:
MOVZX EBX,z ;EBX=Z
ADD EBX,x ;EBX=X+Z
MOV EAX,1 ;EAX=1
CDQ
MOVSX ECX,y ;ECX=Y
;;CMP ECX,0
;;JE null ;IF Y==0
IDIV ECX ;EAX=1/Y
ADD EAX,EBX ;EAX=1/Y +X+Z
MOV dword ptr s[0],EAX
XOR EAX,EAX
ADC EAX,0
MOV dword ptr s[4],EAX
JMP j_end

JMP j3
j3:
MOVZX EAX,z ;EAX=Z
MOVZX EBX,z ;EBX=Z
CDQ
IMUL EAX ;EAX=Z*Z 
IMUL EBX ;EAX=Z*Z*Z
MOV EBX,3 
IMUL EBX ;EAX=Z*Z*Z*3
IMUL x ;EAX=Z*Z*Z*3*X
MOV dword ptr s[0],EAX
MOV dword ptr s[4],EDX
JMP j_end

;;null:
j_end:
push NULL
call ExitProcess
END START