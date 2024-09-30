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
 x dw ?
 y dw ?
 z dw ?
   fin db "%d %d %d", 0
   format db "EAX = %d", 10, 13, 0
   fh db "EAX(h) = %x; EAX = %d", 0
   output dd 0 
 ; --- Сегмент кода ---
 .code
 start:
 push offset z
 push offset y
 push offset x
 push offset fin
 call crt_scanf	
 add esp, 4*4 ;очистка стека
 push 0

 MOVSX AX, x          ; AX = x
 SUB EAX, 3*3*3*3     ;EAX = EAX - 3^4 = (x-3^4)
 IMUL EAX             ; EAX = EAX * EAX	 = (x-3^4)^2
 MOVSX CX, y          ; CX = y
 SUB ECX,4            ; ECX = ECX - 4= (y-4)
 IMUL ECX             ; ECX = ECX * ECX	 = (y-4)^2
 ADD EAX, ECX         ; EAX = EAX + ECX = (x-3^4)^2 + (y-4)^2
 MOVSX BX, z          ; BX = z
 ADD BX, 5            ; EBX = EBX + 5 = (z+5)
 IMUL EBX             ; EBX = EBX * EBX = (z+5)^2
 ADD EAX, EBX         ; EAX = EAX + EBX = (x-3^4)^2 + (y-4)^2 + (z+5)^2
 MOVSX DX, 4          ; DX = 4  
 XCHG EAX, EDX        ; Обмен местами содержимого EAX и EDX
 CDQ			; Расширение перед делением до двойного слова
 IDIV EDX             ; EAX = EDX:EAX  = (x-3^4)^2 + (y-4)^2 + (z+5)^2 / 4  
 push output
 push output
 push offset fh
 call crt_printf
 add esp, 4*3 ;очистка стека

	
  push 0

	
 push NULL
 call ExitProcess
 end start
