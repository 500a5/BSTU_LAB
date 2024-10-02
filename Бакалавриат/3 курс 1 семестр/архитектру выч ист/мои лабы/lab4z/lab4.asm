.386 ; Тип процессора
 .model flat, stdcall ; Модель памяти и стиль вызова подпрограмм
 option casemap: none ; Чувствительность к регистру
 ; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include c:\masm32\include\windows.inc
 include c:\masm32\include\kernel32.inc
 include c:\masm32\include\user32.inc
 include c:\masm32\include\msvcrt.inc

 ; --- Подключаемые библиотеки ---
 includelib c:\masm32\lib\user32.lib
 includelib c:\masm32\lib\kernel32.lib
 includelib c:\masm32\lib\msvcrt.lib

 ; --- Сегмент данных ---
 .data 
 n db 10
x db ?, ?, ?, ?, ?, ?, ?, ?, ?, ?
 
 ; --- Сегмент кода ---
 .code


 ;процедура ввода массива void input_array(short* a, int n)
input_arr proc
	push EAX	;сохраняем значение EAX
	push ECX	;сохраняем значение ECX
	push EDX	;сохраняем значение EDX
	
	push offset i_invite
	call crt_printf
	add esp, 4

	MOV EAX, [ESP + 16] ;Достаем из памяти указатель на начало массива
	MOV ECX, [ESP + 20] ;Достаем из памяти размер массива

    i1:
	push ECX	;сохраняем состояние регистра потому что
	push EAX	;crt_printf их затирает
	push offset i_d
	call crt_scanf 	;ввод очередного элемента
	add esp, 4	;очистка стека после ввода
	pop EAX		;восстанавливаем значение регистров
	pop ECX		;
	INC EAX		;переход к следующему элементу
	LOOP i1		;продолжение цикла

	pop EDX		;EDX
	pop ECX 	;Достаем сохраненные регистры ECX
	pop EAX		;EAX
	ret 4*2		;выход
input_arr endp

;функция возведения в целую степень int p(int x, int p)
p proc
	push ECX	;сохраняем значение ECX
	push EDX	;сохраняем значение EDX
	
	MOV EDX, [ESP + 12] ;Достаем из памяти число возводимое в степень
	MOV ECX, [ESP + 16] ;Достаем из памяти степень
	
	MOV EAX, EDX	;переносим число в EAX

    p1:
	
	IMUL EAX, EDX	;накручиваем степень
	LOOP p1
	
	pop EDX		;EDX
	pop ECX 	;Достаем сохраненные регистры ECX
	ret 4*3		;выход
p endp

;функция задания void f (short* a, int n)
f proc
	MOV ECX,n  ;
 	MOV ESI,a ; Начнем с начала
	
	a:
	 MOV EAX,[EDI] ; Возьмем элемент
	 CMP EAX,[p(EDI,3)] ; Если он равен  тому-то
 
 	ADD EDI,4
	next:
 	ADD ESI,4
 	 MOV EAX,[ESI] ;Чтоб затереть этот элемент следующим за ним
 	 MOV [EDI],EAX
	 loop a;
	 ret
f endp

;процедура для вывода void output_array(short* a, int n)
output_arr proc
	push EAX	;сохраняем значение EAX
	push ECX	;сохраняем значение ECX
	push EDX	;сохраняем значение EDX
	
	push offset o_print
	call crt_printf
	add esp, 4

	MOV EAX, [ESP + 16] ;Достаем из памяти указатель на начало массива
	MOV ECX, [ESP + 20] ;Достаем из памяти размер массива

    o1:
	push ECX	;сохраняем состояние регистра потому что
	push EAX	;crt_printf их затирает
	MOV  AL, [EAX]	;передаем то что нужно вывести в AL
	MOVSX AX, AL	;расширяем AL до AX что бы использовать push
	push AX		;push не любит 1(
	push offset o_d
	call crt_printf ;вывод очередного элемента
	add esp, 6	;очистка стека после ввода
	pop EAX		;восстанавливаем значение регистров
	pop ECX		;
	INC EAX		;переход к следующему элементу
	LOOP o1		;продолжение цикла
	
	push offset br
	call crt_printf
	add esp, 4

	pop EDX		;EDX
	pop ECX 	;Достаем сохраненные регистры ECX
	pop EAX		;EAX
	ret 4*2		;выход
output_arr endp



 start:
 add esp, 4	;чистим стек
 MOVSX CX, n	;перемещаем n в CX и расширяем его
	MOVSX ECX, CX	;перемещаем n в ECX и расширяем его

	push ECX	;передаем параметры для input_arr в стек
	push offset x	;
	call input_arr	;вызов ввода
        push ECX	;
	push offset x	;
	call f;
        push ECX	;вывод массива
	push offset x	;
	call output_arr	;

  add esp, 8	;чистим стек	

	push NULL
	call ExitProcess ; Выход из программы

	
 push NULL
 call ExitProcess
 end start
