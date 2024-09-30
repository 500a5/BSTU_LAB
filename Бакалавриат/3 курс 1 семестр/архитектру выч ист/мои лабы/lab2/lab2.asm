.386 ; Тип процессора
 .model flat, stdcall ; Модель памяти и стиль вызова подпрограмм
 option casemap: none ; Чувствительность к регистру
 ; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include c:\masm32\include\windows.inc
 include c:\masm32\include\kernel32.inc
 include c:\masm32\include\user32.inc

 ; --- Подключаемые библиотеки ---
 includelib c:\masm32\lib\user32.lib
 includelib c:\masm32\lib\kernel32.lib

 ; --- Сегмент данных ---
 .data 
 ; --- Сегмент кода ---
 .code
 start:
MOV ESI, 'c'
 OR DI, 11110001b 
 MOV DWORD PTR [EBX], 'L'
 TEST AX, [EDI+4Fh]  
 ADC CL, AL 
 CMP [EDX*4+ESI+7], ECX
 push NULL
 call ExitProcess
 end start
