 .386 ; Тип процессора
 .model flat, stdcall ; Модель памяти и стиль вызова подпрограмм
 option casemap: none ; Чувствительность к регистру
; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
include D:\my_bstu\arch_sys\masm32\include\windows.inc
include D:\my_bstu\arch_sys\masm32\include\kernel32.inc
include D:\my_bstu\arch_sys\masm32\include\user32.inc
include D:\my_bstu\arch_sys\masm32\include\msvcrt.inc

; --- Подключаемые библиотеки ---
includelib D:\my_bstu\arch_sys\masm32\lib\user32.lib
includelib D:\my_bstu\arch_sys\masm32\lib\kernel32.lib
includelib D:\my_bstu\arch_sys\masm32\lib\msvcrt.lib
  
 ; --- Сегмент данных ---
.data
    n dd 12
    a db 40 dup(0BAh), 43h, 21h
    res db 84 dup(0)
    
.code
multiplication proc				; multiplication (char* a, int n, char* res); -- Умножение беззнакового 40-байтового числа a на 2^n. Результат в res
  PUSHF
  PUSHAD
	
  MOV EDI, [ESP + 38]				; Адрес числа a
  MOV EBP, [ESP + 46]				; Адрес res
  MOV EAX, [ESP + 42]				; Степень двойки, n
  MOV EDX, 0h					; Для избежания переполнения при делении
  MOV ECX, 8h					; Кол-во бит в байте
  IDIV ECX					; Узнаем, на сколько бит сдвинется каждый байт, и сколько нулевых байтов мы запишем в результат

  MOV ECX, EAX 			; ECX = N / 8 (Количество смещенных байтов)  
  PUSH EBP

  INC EBP ; ADD EBP, ECX  		; Смещаем начало числа на байты
  
  PUSH EAX
  MOV ECX, 41
  moveBytes:
    MOV AL, BYTE PTR [EDI + ECX] 	; a
    MOV BYTE PTR [EBP + ECX], AL 	; res
  LOOP moveBytes
  MOV AL, BYTE PTR [EDI] 		; a
  MOV BYTE PTR [EBP], AL 		; res
  AND BYTE PTR [EBP], 01111111b 	; Пока что убираем знаковый бит
  POP EAX
  POP EBP

  CMP EDX, 0
  JE endLoop  

  MOV ECX, EDX  
  MOV ESI, 0h					; Номер текущего байта для для записи
  outer_loop:
    PUSH ECX
    PUSH EAX
    MOV ECX, 42
    ADD ECX, EAX

    mov AL, byte ptr [EBP+ECX]
    mov BL, byte ptr [EBP+ECX]

    rol BL, 1
    and BL, 00000001b			; сдвинутый бит
    shl AL, 1				; готовый байт
    mov byte ptr [EBP+ECX], AL
    inner_loop:
      dec ESI
      mov AL, byte ptr [EBP+ECX]
      mov DL, byte ptr [EBP+ECX]
      rol DL, 1
      and DL, 00000001b		; сдвинутый бит
      sal AL, 1			; cмещенный байт
      or AL, BL			; готовый байт с учетом сдвинутого бита старшего байта
      mov byte ptr [EBP+ECX], AL
      mov BL, DL			; запомнить сдвинутый бит для младшего байта
    loop inner_loop
    POP EAX
    pop ECX
  loop outer_loop
  endLoop:

  MOV AL, BYTE PTR [EDI] 		; a
  AND AL, 10000000b
  MOV BYTE PTR [EBP], AL 		; res  

  POPAD
  POPF
  RET 12
multiplication endp

output_res proc				; output_res(char* a, int n, char* res) -- Вывод на экран числа a и res в 16-ричном виде
  PUSHF
  PUSHAD
  SUB ESP, 14h				; Буфер для локальной строки формата
  MOV BYTE PTR [ESP], 'a'
  MOV BYTE PTR [ESP + 1], ' '
  MOV BYTE PTR [ESP + 2], '='
  MOV BYTE PTR [ESP + 3], ' '
  MOV BYTE PTR [ESP + 4], 0h

  MOV BYTE PTR [ESP + 5], '%'
  MOV BYTE PTR [ESP + 6], '0'
  MOV BYTE PTR [ESP + 7], '2'
  MOV BYTE PTR [ESP + 8], 'X'
  MOV BYTE PTR [ESP + 9], ' '
  MOV BYTE PTR [ESP + 10], 0h

  MOV BYTE PTR [ESP + 11], 10			; Символ перехода на новую строку
  MOV BYTE PTR [ESP + 12], 13
  MOV BYTE PTR [ESP + 13], 0h
  
  ; Выведем число a длиною в 42 байт
  MOV EBP, ESP					; Сохранили адрес локальной строки формата
  PUSH EBP
  CALL crt_printf				; Вывод пояснения о том, что выводится число a
  ADD ESP, 4h
  ADD EBP, 5h					; Переход к след. строке формата
  MOV EDI, [ESP + 58]				; Достали указатель на число a
  MOV ESI, 0h					; Индекс для вывода числа a
  MOV ECX, 42					; Выводим 21 раз по 2 байта
  output_a_again:
    PUSH ECX					; printf изменит ECX, поэтому мы сохраним его копию
    XOR ECX, ECX
    MOV CL, BYTE PTR [EDI + ESI] 		;ch
    PUSH ECX
    PUSH EBP					; Положили в стек адрес строки формата
    CALL crt_printf
    ADD ESP, 8h
    INC ESI
    POP ECX					; Вернули состояние ECX
  LOOP output_a_again
  ADD EBP, 6h					; Вывод символа перехода на новую строку
  PUSH EBP
  CALL crt_printf
  ADD ESP, 4h
  MOV EBP, ESP					; Возвращаемся к первой строке формата
  
  ; Выведем число res длиною 42 + n / 4 + 1 байт
  MOV BYTE PTR [ESP], 'r'			; Заменим пояснение вывода a на r
  PUSH EBP
  CALL crt_printf

  ADD ESP, 4h
  ADD EBP, 5h					; Перешли к след. строке формата

  MOV EAX, [ESP + 62]				; Достали n
  MOV ECX, 8h					; Кол-во бит в записи

  MOV EDX, 0h					; Для избежания переполнения при делении
  IDIV ECX					; EAX = n / 8

  ADD EAX, 42					; Теперь в EAX действительный размер числа res в байтах
  MOV ECX, 1h					; Кол-во байт для одновременного вывода
  MOV EDX, 0h					; Для избежания переполнения при делении
  IDIV ECX					; Теперь в EAX кол-во итераций вывода байт числа res по 2
  ADD EAX, 1h					; С округлением вверх
  MOV ECX, EAX
  
  MOV EDI, [ESP + 66]				; Достали указатель на число res
  MOV ESI, 0h					; Индекс для вывода числа res
  output_res_again:
    PUSH ECX					; printf изменит ECX, поэтому мы сохраним его копию
    XOR ECX, ECX
    MOV CL, BYTE PTR [EDI + ESI]
    
    PUSH ECX
    PUSH EBP					; Положили в стек адрес строки формата
    CALL crt_printf
    ADD ESP, 8h
    POP ECX					; Вернули состояние ECX
    INC ESI
  LOOP output_res_again
  ADD ESP, 14h					; Удалили буфер для локальной строки формата
  POPAD
  POPF
  RET 12
output_res endp

start:
    push offset res
    push n
    push offset a
    call multiplication

    PUSH OFFSET res
    PUSH n
    PUSH OFFSET a
    CALL output_res

    call crt__getch ; задержка ввода с клавиатуры
    push 0
    call ExitProcess
end start