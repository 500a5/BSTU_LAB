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
	MOV AX, [ESP+4*5] ; Взять из стека аргумент, т.е. число, которое
	;нужно вывести в двоичном представлении
	MOV ECX, N ; Чтобы вывести 16-битное число, необходим цикл.
	;Помещаем в ECX количество итераций
j1:
	ROL AX, 1 ; Сделать циклический сдвиг числа на один разряд влево. 
	;Таким образом старший бит попадёт на место младшего
	MOV BX, AX ; BX = AX
	AND BX, 1b;0000 0000 0000 0001b ; Оставить только младший бит, остальные обнулить
	ADD BX, '0' ; Прибавить к BX код символа "0"
	; Команда для вывода символа на экран crt_putch
	;изменяет регистры EAX и ECX, поэтому нужно сохранить их в стеке
	PUSH EAX 
	PUSH ECX
	
	; Поместить выводимый символ в стек, т.е. передать его
	;в качестве аргумента функции crt__putch
	PUSH EBX 
	CALL crt__putch ; Вызвать функцию
	ADD ESP, 4 ; Удалить аргумент из стека, так как функция crt__putch этого не делает
	POP ECX ; Восстановить ECX
	POP EAX ; Восстановить EAX
	LOOP j1 ; ECX = ECX - 1 Выполнять цикл пока ECX > 0
	POP ECX ; Восстановить ECX
	POP EBX ; Восстановить EBX
	POP EAX ; Восстановить EAX
	POP EDX
	RET 4 ; Возврат к основной программе и очистка стека от аргумента размером 4 байта
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

START:
	XOR EAX,EAX
	XOR EDX,EDX
	XOR EDI,EDI
	XOR ECX,ECX
	MOV ECX,N; ECX=16
	MOV EAX,1
j2:
	PUSH ECX;SAVE 
	PUSH EAX;OUTPUT
	CALL output
	CALL new_line;NEW LINE
	MOV DX,AX; DX=AX
	DEC ECX; --ECX
	CMP ECX,0
	je j4
	j3:	
		SHL DX, 1
		MOV DI,DX
		OR DI,AX
		PUSH EDX
		PUSH EDI
		CALL output
		POP EDX
		CALL new_line
		LOOP j3
	j4:
	SHL AX, 1
	POP ECX ;RETURN ECX
	LOOP j2
	CALL crt__getch
	push NULL
	call ExitProcess
END START