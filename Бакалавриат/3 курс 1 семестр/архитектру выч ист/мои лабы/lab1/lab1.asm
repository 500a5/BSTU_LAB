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
	m DB 20 DUP (4)
	n DB 20 DUP (8)
	a DW 500
	b DD ?
	cc DQ 15.5
	d DD 7.5


	
	format db "NAME",9,"ADRESSS         END",9,"      SIZE", 9,"TYPE", 13, 10
	       db "m", 9, "%p", 9, "%p", 9,"20",                     9,"array 20 namber",   		13, 10
               db "n", 		9, "%p", 		9, "%p",  	               9,"20",	         9,"array 20 namber",	13, 10
               db "a", 	9, "%p", 		9, "%p", 		9,"2",	         9,"2 bate celoe",		13, 10
               db "b", 		9, "%p", 		9, "%p", 		9,"4",	         9,"4 bate simvol",	13, 10
	       db "cc", 		9, "%p", 		9, "%p", 		9,"8",	         9,"8 bate vehestvennoe",	13, 10
	       db "d", 		9, "%p", 		9, "%p", 		9,"4",	         9,"4 bate vehestvennoe",	13, 10
 ; --- Сегмент кода ---
 .code
 start:
  MOV EAX, 77 ; Поместить в регистр EAX число 77
  MOV EBX, 34 
  ADD EAX, EBX ; Сложение чисел 77 + 34
  MOV EDX, 4
  MUL EDX ; Умножение EDX = (77 + 34)*4

  
  
  
  push (offset d + 4-1) ;  
  push offset d
  push (offset cc + 8-1) ;  
  push offset cc
  push (offset b + 4-1)
  push offset b
  push (offset a + 2-1)
  push offset a
  push (offset n + 20-1)
  push offset n
  push (offset m + 20-1)
  push offset m
 
  

  push offset format
  call crt_printf
  push NULL
  call ExitProcess ; Выход из программы
 end start
