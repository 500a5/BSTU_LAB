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
; Процедура для вывода двоичного представления 16-битного числа
; void output (int a). Процедура в качестве аргумента
;принимает  32-разрядное целое число, но в процедуре
;используется только 2 младшиx байтf числа, остальные игнорируются
output proc
;Сохранить в стеке значения регистров, которые будут
;использованы
    PUSH EDX ; Запомнить EAX
	PUSH EAX ; Запомнить EAX
	PUSH EBX ; Запомнить EBX
	PUSH ECX ; Запомнить ECX
	XOR EBX, EBX ; Обнулить EBX
	MOV EAX, [ESP+4*5]
	MOV ECX, [ESP+4*6]; Взять из стека аргумент, т.е. число, которое
	;нужно вывести в двоичном представлении
	;MOV ECX, N ; Чтобы вывести 16-битное число, необходим цикл.
	;Помещаем в ECX количество итераций
	XOR EDI,EDI
j1:
	;ROL AX, 1 ; Сделать циклический сдвиг числа на один разряд влево. 
	;Таким образом старший бит попадёт на место младшего
	;MOV BX, AX ; BX = AX
	;AND BX, 1b;0000 0000 0000 0001b ; Оставить только младший бит, остальные обнулить
	XOR EBX,EBX
	MOV BL, [EAX+EDI] ;[EAX+EDI];[EAX+ECX-1] ; Прибавить к BX код символа "0"
	; Команда для вывода символа на экран crt_putch
	;изменяет регистры EAX и ECX, поэтому нужно сохранить их в стеке
	INC EDI
	PUSH EAX 
	PUSH ECX
	
	; Поместить выводимый символ в стек, т.е. передать его
	;в качестве аргумента функции crt__putch
	PUSH EBX 
	PUSH offset t
	CALL crt_printf ; Вызвать функцию
	ADD ESP, 8; Удалить аргумент из стека, так как функция crt__putch этого не делает
	POP ECX ; Восстановить ECX
	POP EAX ; Восстановить EAX
	LOOP j1 ; ECX = ECX - 1 Выполнять цикл пока ECX > 0
	POP ECX ; Восстановить ECX
	POP EBX ; Восстановить EBX
	POP EAX ; Восстановить EAX
	POP EDX
	RET 8 ; Возврат к основной программе и очистка стека от аргумента размером 4 байта
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






;Входные параметры:  a – адрес первого числа в памяти, n – степень двойки. 
;Выходные параметры: res – адрес массива, куда записывается результат.
multiplication proc ;multiplication(char* a, int n, char* res) без знака
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