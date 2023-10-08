.386 
.model flat, stdcall 
option casemap: none 
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\windows.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\kernel32.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\user32.inc
include C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\include\msvcrt.inc
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\user32.lib
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\kernel32.lib
includelib C:\Users\HYSTOU\Desktop\3kmmr\asv\masm32\lib\msvcrt.lib
.data
; оригинал кода: 
	CONST_1 dq 1.0
	CONST_2 dq 2.0
	CONST_3 dq 3.0
	CONST_5 dq 5.0
	CONST_Q dq 1.7320508075688772
    n dd 50
	fmt db "n = %2.d; S = %lf.", 10, 0
.code
	pow proc
		FINIT						;инициализация сопроц.		
		FLD QWORD PTR [ESP+4]	 	;st: x
		FLDZ						;st: 0 x
		DB 0DBh, 0F0h+1         	;FCOMI 0, x (сравнение х и 0)
		JE exit	             		;x = 0 -> выход, st0 = 0
		FLD QWORD PTR [ESP+12]		;st: y 0 x
		DB 0DBh, 0F0h+1         	;FCOMI y, 0 (сравнение y и 0)
		FLD1						;st: 1 y 0 x
		JE exit                 	;y = 0 -> выход st0 = 1
		FINIT						;отчистка+инициализация
		FLD QWORD PTR [ESP+4] 		;st: x
		FLD	ST(0)					;st: x x
		FABS						;st: abs(x) x
		FDIV ST(0), ST(1)	        ;st: abs(x)/x (sign(x))
		FXCH ST(1)	                ;st: x, sign(x)
		FLD	QWORD PTR [ESP+12] 		;st: y, x, sign(x)
		FXCH ST(1)	                ;st: x, y, sign(x)
		FYL2X                       ;st: t, sign(x)
		FLD1						;st: 1, t, sign(x)
		FSCALE                      ;st: 2^[t], t, sign(x)
		FLD1						;st: 1, 2^[t], t, sign(x)
		FLD	ST(2)					;st: t, 1, 2^[t], t, sign(x)
		FPREM                       ;st: {t}, 1, 2^[t], t, sign(x) (действие только над st(0)
		F2XM1                       ;st: 2^{t}-1, 1, 2^[t], t, sign(x)
		FADD	ST(0), ST(1)        ;st: 2^{t}, 1, 2^[t], t, sign(x)
		FMUL	ST(0), ST(2)        ;st: 2^[t]*2^{t}
		FMUL	ST(0), ST(4)        ;st: abs(x)^y*sign(x)
	exit:
		RET		16
	pow endp
start: ;могу писать вк о.о
	MOV    ECX, n				;ecx = n
	MOV    ESI, 0				;esi = 0 (новое n)
	FLDZ						;st: 0 
	SUB ESP, 8					;выделение памяти +8
	FSTP QWORD PTR [ESP]	    ;частичная сумма ряда
;цикл====================================================
  loop1:
	INC ESI						;увеличение n
	CMP ESI, ECX				;сравнение, если ecx=esi -> выход
	JG     exit1	
;1------------------------------------------
	FLD    CONST_1				;st: 1
	PUSH   ESI					;esi -> стек +12
	FILD   DWORD PTR [ESP]		;st: n 1	
	POP    ESI					;esi из стека +8 а не минус?
	FMULP  ST(1), ST(0)			;st: 1*n
	FLD    CONST_1				;st: 1 1*n
	FDIVP  ST(1), ST(0)			;st: 1*n/1
	FLD    CONST_Q				;st: q, 1*n/1
	SUB    ESP, 16				;выделение памяти в стеке +24 ++
	FSTP   QWORD PTR [ESP + 0]	;st:[esp+0] = q 
	FSTP   QWORD PTR [ESP + 8]	;st:[esp+8] = 1*n/1
	CALL   pow					;вызов pow, st0 = q^n  
	FLD    CONST_1				;st: 1 q^n
	FDIVRP ST(1), ST(0)			;st: 1/q^n
	FLD    QWORD PTR [ESP]		;st: 0, 1/q^n
	FADD   ST(0), ST(1)			;st: 0+1/q^n, 1/q^n
	FSTP   QWORD PTR [ESP]		;esp = 1/q^n
	;1------------------------------------------
	;2------------------------------------------
	FLD    CONST_2				;st: 2
	PUSH   ESI					;esi -> стек
	FILD   DWORD PTR [ESP]		;st: n 2
	POP    ESI					;esi из стека
	FMULP  ST(1), ST(0)			;st: n*2
	FLD    CONST_3				;st: 3, 2*n
	FDIVP  ST(1), ST(0)			;st: 2*n/3
	FLD    CONST_Q				;st: 1, 2*n/3
	SUB    ESP, 16				;Выделение памяти в стеке +40
	FSTP   QWORD PTR [ESP + 0]	;st:[esp+0] = q 
	FSTP   QWORD PTR [ESP + 8]	;st:[esp+8] = 1*n
	CALL   pow					;вызов pow
	FLD    CONST_3				;st: 3, q^(2*n/3)
	FDIVRP ST(1), ST(0)			;st: 3/(q^(2*n/3))
	FLD    QWORD PTR [ESP]		;st: sum, 3/(q^(2*n/3))
	FADD   ST(0), ST(1)			;st: sum+3/(q^(2*n/3)), 3/(q^(2*n/3))
	FSTP   QWORD PTR [ESP]		;esp: sum+3/(q^(2*n/3))
	;2------------------------------------------
	;3------------------------------------------
	FLD    CONST_2				;Аналогичны действиям выше
	PUSH   ESI
	FILD   DWORD PTR [ESP]
	POP    ESI
	FMULP  ST(1), ST(0)
	FLD    CONST_5
	FDIVP  ST(1), ST(0)
	FLD    CONST_Q
	SUB    ESP, 16
	FSTP   QWORD PTR [ESP + 0]
	FSTP   QWORD PTR [ESP + 8]
	CALL   pow
	FLD    CONST_5
	FDIVRP ST(1), ST(0)
	FLD    QWORD PTR [ESP]
	FADD   ST(0), ST(1)
	FST    QWORD PTR [ESP]		;esp = sum+5/(q^(2*n/5))
	;3------------------------------------------  1 = 2 = 3, но меняются некоторые множитили, типа строка 114, 102, 90, 83, ща секунду, бака нет, т.к. винду переставляли)0)) (да, бака!!!)
	PUSH   ECX				;ecx->стек
	SUB    ESP, 8			;выделение памяти
	FSTP   QWORD PTR [ESP]	;выталкиваем в esp сумму 
	PUSH   ESI				;n
	PUSH   offset fmt
	CALL   crt_printf
	ADD    ESP, 16
	POP    ECX
JMP    loop1
;цикл====================================================
  exit1:
end start