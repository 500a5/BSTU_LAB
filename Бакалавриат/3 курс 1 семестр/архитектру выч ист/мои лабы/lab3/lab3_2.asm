.386
.model flat, stdcall
option casemap: none

; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include C:\masm32\include\windows.inc
 include C:\masm32\include\kernel32.inc
 include C:\masm32\include\user32.inc
 include C:\masm32\include\msvcrt.inc
 ; --- Подключаемые библиотеки ---
 includelib C:\masm32\lib\user32.lib
 includelib C:\masm32\lib\kernel32.lib
 includelib C:\masm32\lib\msvcrt.lib
.data
	op1 db 0h,0h,0h,0h, 0h,0h,0h,0h, 0h,0h,0h,0h, 0h,0h,0h,0h, 0FFh,0FFh
	op2 db 0h,0h,0h,0h, 0h,0h,0h,0h, 0h,0h,0h,0h, 0h,0h,0h,0h, 0FFh,0FEh
	res dd 18 dup(?)
	format db "Res = %x%x%x%x%x", 0
	
.code
start:

        ; Обрабатываем последние 2 байта (всего - 18 байт)
	mov ax, word ptr op1[16]
	adc ax, word ptr op2[16]
	push eax
	mov word ptr res[16], ax
	
        ; Обрабатываем следующие 4 байта (всего - 16 байт).
	mov eax, dword ptr op1[12]
	adc eax, dword ptr op2[12]
	push eax
	mov dword ptr res[12], eax

        ; Обрабатываем следующие 4 байта (всего - 12 байт).
	mov eax, dword ptr op1[8]
	adc eax, dword ptr op2[8]
	push eax
	mov dword ptr res[8], eax

        ; Обрабатываем следующие 4 байта (всего - 8 байт).
	mov eax, dword ptr op1[4]
	adc eax, dword ptr op2[4]
	push eax
	mov dword ptr res[4], eax


	
  	push offset format
  	call crt_printf
  	add esp, 4*6 ;очистка стека
	call crt__getch

	
	
	
	push 0
	call ExitProcess
end start
