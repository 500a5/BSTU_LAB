.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
.DATA
strs DB 10, 13, "Summ:", 0
sum DD ?
mas DW 4 DUP(5)
longFloat DQ 154.5
.CODE
START:
MOV EAX, sum
MOV EBX, 4
MOV ESI, 0
ADD AX, mas[ESI]
ADD ESI, 2
MUL EBX
MOV sum, EAX
push NULL
call ExitProcess
END START