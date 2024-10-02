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
	a db 0FFh,0DDh,0BBh,0CCh, 0BBh,0AAh,0FFh,0AAh
	b db 0AAh,0AAh,0AAh,0AAh, 0AAh,0AAh,0AAh,0AAh
	r db 16 dup(?)
	
	fmt db "%04X %04X %04X %04X", 0
.code
start:
	xor edi, edi
	; Обрабатываем младшие 4 байта.
	mov eax, dword ptr a[0]
	mul dword ptr b[0]
	mov ebx, edx
	
	mov dword ptr r[0], eax
	
	; Обрабатываем младшие 8 байт.
	mov eax, dword ptr a[0]
	mul dword ptr b[4]
	add eax, ebx
	
	mov ebx, eax
	mov ecx, edx
	
	mov eax, dword ptr a[4]
	mul dword ptr b[0]
	add ebx, eax
	adc ecx, edx
	adc edi, 0
	
	mov dword ptr r[4], ebx
	
	; Обрабатываем младшие 12 байт.
	mov eax, dword ptr a[4]
	mul dword ptr b[4]
	add ecx, eax
	add edx, edi
	
	mov dword ptr r[8], ecx
	
	mov dword ptr r[12], edx
	
	; Вывод результата.
	push dword ptr r[0]
	push dword ptr r[4]
	push dword ptr r[8]
	push dword ptr r[12]
	push offset fmt
	call crt_printf
	add esp, 4 * 5
	
	call crt__getch
	
	push 0
	call ExitProcess
end start
