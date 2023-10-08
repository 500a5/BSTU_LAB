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
	i_invite db "Input size of array = ", 0
	i_d db "Input array: ", 0
	fmt db "%d", 0
	msg db "Your array: ", 0
	fmtout db "%d", 13, 10, 0
	
.code
	; void enter_arr(int *arr, size_t n); 
	enter_arr proc
		pushad	

		push offset i_d
		call crt_printf
		add esp, 4
		
		mov		eax, [esp+36]	; eax = arr
		mov		ecx, [esp+40]	; ecx = n
		cmp		ecx, 0
		jle		retl
		
		loop1:
		push	eax				; сохраняем eax
		push	ecx				
		push	eax
		push	offset fmt
		call	crt_scanf		; вводим *arr
		add		esp, 8
		pop		ecx
		pop		eax			
		add		eax, 4			; arr = arr + 4
		loop	loop1
		
		retl:
		popad
		ret		8
	enter_arr	endp
	
	is_pow_3 proc
		push ebx
		mov eax, [esp+8] ; eax = x
		cmp eax, 1 ; если x = 1, вернуть ложь
		jle ret0

		;степень тройки если eax and 11b = 0
		and eax, 11b ; eax = eax AND ebx
		cmp eax, 0
		je ret0
		jmp ret1

		ret0:
		mov eax, 0
		jmp retlb

		ret1:
		mov eax, 1

		retlb:
		pop ebx
		ret 4
	is_pow_3 endp
	
	; void del_3(int *adr, size_t *pn); 
	del_3 proc
		pushad	
		mov		ebx, [esp+36]	; eax = adr
		mov		ecx, [esp+40]	; ecx = pn
		push	[ecx]			
		mov		esi, 0			; esi = i - индекс прохода по массиву
		mov		edi, 0			; edi = j - индекс записи элементов
		mov		[ecx], esi		
		pop		ecx				
		
		cmp		ecx, 0
		jle		retl
		
		loop1:
		push	dword ptr [ebx+esi*4]
		call	is_pow_3
		cmp		eax, 0			
		jne		nwrite
		
		mov		eax, [ebx+esi*4]
		mov		[ebx+edi*4],eax	; adr[j] = adr[i]
		inc		edi				; j++
		mov		edx, [esp+40]
		mov		[edx], edi		; *pn = j
		
		nwrite:
		inc		esi				; i++
		loop	loop1
		
		retl:
		popad
		ret		8
	del_3 endp
	
	out_arr proc
		pushad
		mov		eax, [esp+36]
		mov		ecx, [esp+40]
		cmp		ecx, 0
		jle		retl		
		
		loop1:
		push	eax
		push	ecx
		push	[eax]
		push	offset fmtout
		call	crt_printf
		add		esp, 8
		pop		ecx
		pop		eax
		add		eax, 4
		loop	loop1
		
		retl:
		popad
		ret		8
	out_arr endp
	
	start:	
		mov		eax, offset fmtout
		add		eax, 5		
		push	eax
		push 	offset i_invite
		call	crt_printf
		add		esp, 4
		pop		eax
		
		push	eax
		push	eax
		push	offset fmt
		call	crt_scanf
		add		esp, 8
		pop		eax
		
		push	[eax]
		add		eax, 4
		push	eax
		call	enter_arr
		sub		eax, 4
		
		push	eax
		push 	offset msg
		call	crt_printf
		add		esp, 4
		pop		eax
		
		push	eax
		add		eax, 4
		push	eax
		call	del_3
		sub		eax, 4
		
		push	[eax]
		add		eax, 4
		push	eax
		call	out_arr
		add		esp, 8
		sub		eax, 4
		call crt__getch
		push	0
		call 	ExitProcess
	
	end start