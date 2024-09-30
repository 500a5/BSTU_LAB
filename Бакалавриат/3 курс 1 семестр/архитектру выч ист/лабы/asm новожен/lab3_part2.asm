.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE
include E:\masm32\include\windows.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\user32.inc
includelib E:\masm32\lib\user32.lib
includelib E:\masm32\lib\kernel32.lib
.DATA
a db 2Ah, 03h, 12h, 0DEh, 43h, 0E2h, 34h , 0Ah, 0FDh, 0DDh, 0C1h, 55h, 8Dh, 0B0h, 46h, 11h, 0D6h, 0AAh, 5Ah, 11h; 20 байт 
b db 15h, 0DDh, 34h, 4Bh, 57h, 7Fh, 0CDh, 15h, 0DDh, 34h, 4Bh, 57h, 7Fh, 0CDh, 0AAh, 56h, 5Fh, 99h, 4Ch, 9Bh ; 20 байт
res db 21 dup(?) ; Для результата резервируется на один байт больше
.CODE
START:
MOV ESI ,offset a
MOV EDI ,offset b
MOV EAX,DWORD PTR[ESI] 
MOV EBX,DWORD PTR[EDI]
XOR EDX,EDX

ADD EAX,EBX
MOV DWORD PTR[res],EAX

MOV EAX,DWORD PTR[ESI+4] 
MOV EBX,DWORD PTR[EDI+4]
ADD EAX,EDX
XOR EDX,EDX
ADD EAX,EBX
MOV DWORD PTR[res+4],EAX

MOV EAX,DWORD PTR[ESI+8] 
MOV EBX,DWORD PTR[EDI+8]
ADD EAX,EDX
XOR EDX,EDX
ADD EAX,EBX
MOV DWORD PTR[res+8],EAX

MOV EAX,DWORD PTR[ESI+12] 
MOV EBX,DWORD PTR[EDI+12]
ADD EAX,EDX
XOR EDX,EDX
ADD EAX,EBX
MOV DWORD PTR[res+12],EAX

MOV EAX,DWORD PTR[ESI+16] 
MOV EBX,DWORD PTR[EDI+16]
ADD EAX,EDX
XOR EDX,EDX
ADD EAX,EBX
MOV DWORD PTR[res+16],EAX

XOR AL,AL
ADC AL,DL
MOV [res+20],AL

push NULL
call ExitProcess
END START