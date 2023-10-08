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
;s db " %d: arctg(%lli)^(7/5) = %10.5f ; (5 * %d)^2=%d ",13, 10, 0
s db " %08d: arctg( %08lli)^(7/5) = %10.5f ; (5 * %08d)^2=%08lli ",13, 10, 0
a dd ?
b dd ?
.CONST
stp dd 1.4
.CODE
Pow proc
    FINIT
    FLD qword ptr[ESP + 8] ;x
    FLD dword ptr[ESP + 4] ;y
    
	FLDZ
	;0, Y, X
	db 0dbh, 0f0h+1;FCOMIP st(0),st(1)
	je j66; Y==0
	
    db 0dbh, 0f0h+2;FCOMIP st(0),st(1)
	je j2; X==0
	
	JMP j3
	j2:
	db 0dbh, 0f0h+1;
	jb j20 ;0<Y
	
	j3:
	db 0dbh, 0f0h+2;
	ja j4 ;0>X
	JMP j5
	j4:
	FLD st(1); Создаем еще одну копию 
	;Y,0,Y,X
	FRNDINT; Округляем
	FSUBR st(0), st(2);  ST(0) = z - trunc(z)
	db 0dbh, 0f0h+1;
	je j6 ;(ST0-ST1==0)X-ЦЕЛОЕ 
	
	JMP j5
	;ERR 5 6
	j6:
	;FLD1
	FLD dword ptr[ESP + 4] ;Y
	;FDIVP st,st(1)
    FLD qword ptr[ESP + 8] ;x
	 
	FCHS
	FYL2X; Стек FPU теперь содержит : ST(0) = z = y * log2(x) :
	; Теперь считаем 2 * *z:
	FLD st(0); Создаем еще одну копию z
	FRNDINT; Округляем
	FSUBR st(0), st(1); ST(1) = z, ST(0) = z - trunc(z)
	F2XM1; ST(1) = z, ST(0) = 2 * *(z - trunc(z)) - 1
	FLD1
	FADDP st(1), st(0); ST(1) = z, ST(0) = 2 * *(z - trunc(z))
	FXCH st(1)
	FRNDINT
	FXCH st(1)
	FSCALE; ST(1) = z, ST(0) = (2 * *trunc(z))*(2 * *(z - trunc(z))) = 2 * *t
    FXCH st(1)
	FSTP st; Результат остается на вершине стека ST(0)
	FCHS
	JMP j20
	
	j5:
	FLD dword ptr[ESP + 4] ;y
    FLD qword ptr[ESP + 8] ;x
	FYL2X; Стек FPU теперь содержит : ST(0) = z = y * log2(x) :
	; Теперь считаем 2 * *z:
	FLD st(0); Создаем еще одну копию z
	FRNDINT; Округляем
	FSUBR st(0), st(1); ST(1) = z, ST(0) = z - trunc(z)
	F2XM1; ST(1) = z, ST(0) = 2 * *(z - trunc(z)) - 1
	FLD1
	FADDP st(1), st(0); ST(1) = z, ST(0) = 2 * *(z - trunc(z))
	FXCH st(1)
	FRNDINT
	FXCH st(1)
	FSCALE; ST(1) = z, ST(0) = (2 * *trunc(z))*(2 * *(z - trunc(z))) = 2 * *t
    FXCH st(1)
	FSTP st; Результат остается на вершине стека ST(0)
	JMP j20
	
	j66:
	FLD1 ;1 ,0, Y ,X
	j20:
	SUB ESP, 8 ; Выделение памяти в стеке
    FSTP qword ptr [ESP] ; Вытолкнуть число типа Dfloat на вершину стека
    MOV EAX, [ESP] ; Скопировать в регистр
	MOV EDX, [ESP+4] ; Скопировать в регистр
    ADD ESP, 8 ; Вернуть стек в исходное состояние
	
	RET 12
Pow endp

funrad proc
    PUSH EBX
	MOV EAX ,[ESP+8]
    MOV EBX,EAX 
	IMUL EAX,5
	ADD EAX,3
	ADC EDX,0
	IMUL EBX
	POP EBX
	RET 4
funrad endp

funarctg proc

    FILD qword ptr[ESP+4]
	FLD1
    FPATAN
	SUB ESP, 8 ; Выделение памяти в стеке
    FSTP qword ptr [ESP] ; Вытолкнуть число типа Dfloat на вершину стека
    MOV EAX, [ESP] ; Скопировать в регистр
	MOV EDX, [ESP+4] ; Скопировать в регистр
    ADD ESP, 8 ; Вернуть стек в исходное состояние
	RET 8
funarctg endp

ff proc
PUSH EBX
PUSH EAX
PUSH EDX
MOV EBX ,offset a
MOV EAX ,[ESP+4+8+4]
IMUL EAX ,5
IMUL EAX
MOV   dword ptr[EBX],EAX
MOV EBX ,offset b
MOV     dword ptr[b], EDX
POP EDX
POP EAX
POP EBX
RET 4
ff endp

START:
XOR EDX,EDX
XOR ESI,ESI
XOR EDI,EDI
XOR ECX,ECX
MOV ECX,050
j55:
PUSH ECX
ADD ESI,1
PUSH ESI
CALL funrad


;PUSH EDX
;PUSH EAX
MOV EDI ,EDX
MOV EBX,EAX

PUSH EDX
PUSH EAX


CALL funarctg

;PUSH EDX
;PUSH EAX




PUSH  EDX;OR EAX
PUSH EAX;;;;;;;;;;;;;;
PUSH  stp

CALL Pow




PUSH ESI
CALL ff


;XOR EAX,EAX
;MOV EDX ,1
;PUSH EDX
;PUSH EAX
;PUSH EAX
;PUSH EAX
;PUSH EDX
;PUSH EDX
;PUSH EAX
;PUSH EAX
PUSH   dword ptr [ b]
PUSH   dword ptr [ a]





PUSH ESI
PUSH EDX
PUSH EAX;rez



PUSH EDI ;ARCTG()
PUSH EBX

PUSH ESI ;n
PUSH offset s

CALL crt_printf
ADD ESP,36

POP ECX
LOOP j55
 
CALL crt__getch
push NULL
call ExitProcess
END START