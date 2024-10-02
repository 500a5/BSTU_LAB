.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
.CODE
START:
MOV ESI, 'c' 
CMP BP, DI
ADD AL, [EBP+ESI+3] 
SUB BYTE PTR [EBP], 45h 
AND [ESI*2], CX 
push NULL
call ExitProcess
END START