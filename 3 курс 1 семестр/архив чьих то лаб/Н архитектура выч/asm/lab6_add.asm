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
s db "    ",13, 10, 0
t db "%.2X:", 0
a dd -1;24448;0100h
b dd ?
kk db "%d",13, 10, 0
.CONST
N dd 32
.CODE



;my_BSR (int *a,int b)
my_bst proc
	PUSH EAX
	PUSH EDX
	PUSH ESI
	PUSH ECX
	PUSH EDI
	MOV ESI,[ESP+4*5+4]
	MOV EAX,[ESP+4*6+4]
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	MOV ECX,32
	MOV EDX,0
	MOV EDI,0
	
	fr:
	ROL EAX,1
	MOV EBX,EAX
	AND EBX,1h
	CMP EBX,1h
	JE j1
	INC EDI
	
	;MOV EDX,EAX
	;AND EAX,1
	LOOP fr
	
	CMP EAX,0
	JE j5
	JMP h
	j5:SUB EAX,EAX
	MOV EDI,0
	MOV ECX,1
	h:
	j1:
	DEC ECX
	MOV [ESI],ECX;EDI
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	POP EDI
	POP ECX
	POP ESI
	POP EDX
	POP EAX
	RET 8
my_bst endp

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
	MOV EAX, [ESP+4*5] ; Взять из стека аргумент, т.е. число, которое
	;нужно вывести в двоичном представлении
	MOV ECX, N ; Чтобы вывести 16-битное число, необходим цикл.
	;Помещаем в ECX количество итераций
j1:
	ROL EAX, 1 ; Сделать циклический сдвиг числа на один разряд влево. 
	;Таким образом старший бит попадёт на место младшего
	MOV EBX, EAX ; BX = AX
	AND EBX, 1b;0000 0000 0000 0001b ; Оставить только младший бит, остальные обнулить
	ADD EBX, '0' ; Прибавить к BX код символа "0"
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
	;AFTER
	PUSH  a
	CALL output
	CALL new_line
	
	PUSH a
	PUSH offset b
	CALL my_bst
	
	PUSH  b
	PUSH offset kk
	CALL crt_printf
	ADD ESP,8
	;CALL output
	;CALL new_line
	
	BSR EAX,a
	
	PUSH  EAX
	;CALL output
	;CALL new_line
	PUSH offset kk
	CALL crt_printf
	ADD ESP,8
	CALL crt__getch
	push NULL
	call ExitProcess
END START