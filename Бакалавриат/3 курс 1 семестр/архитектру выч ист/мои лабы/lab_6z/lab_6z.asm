.386 ; Тип процессора
 .model flat, stdcall ; Модель памяти и стиль вызова подпрограмм
 option casemap: none ; Чувствительность к регистру

 ; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include C:\masm32\include\windows.inc
 include C:\masm32\include\kernel32.inc
 include C:\masm32\include\user32.inc
 include C:\masm32\include\msvcrt.inc

 ; --- Подключаемые библиотеки ---
 includelib C:\masm32\lib\user32.lib
 includelib C:\masm32\lib\kernel32.lib
 includelib C:\masm32\lib\msvcrt.lib

 ; --- Сегмент данных ---
.data
    a dq ? ; 64 бита

    input_a db "Input: A = ", 0
    in_a db "%X %X", 0
 
	result db "Result:    %08X %08X", 10, 0

.code
start:
    PUSH offset input_a
    call crt_printf         ; вывод "Input: A = "
    ADD ESP, 4              

    PUSH offset dword ptr a
    PUSH offset dword ptr a + 4
    PUSH offset in_a        
    call crt_scanf          ; ввод а
    add esp, 3 * 4          ; очистка стека

	MOV EAX, dword ptr a        ; EAX = младшие биты a
    MOV EDX, dword ptr a + 4    ; EDX = старшие биты a

    XOR ESI, ESI        ; ESI = 0
    XOR EBP, EBP        ; EBP = 0

    MOV ECX, 8          ; ECX = 8
j0:
    PUSH ECX            ; сохранение ECX

    MOV EBX, EAX        ; EBX = EAX
    MOV ECX, EDX        ; ECX = EDX
   
    SHR EAX, 4          ; сдвиг вправо на 4 бита
    SHR EDX, 4          ; сдвиг вправо на 4 бита

    PUSH EAX            ; сохранение EAX
    PUSH EDX            ; сохранение EDX

    SHL EAX, 4          ; сдвиг влево на 4 бита
    SHL EDX, 4          ; сдвиг влево на 4 бита

    XOR EAX, EBX        ; EAX = EAX xor EBX
    XOR EDX, ECX        ; EDX = EDX xor ECX

    MOV ECX, [ESP + 2 * 4]  ; помещаем значение из стека в ECX
    DEC ECX             ; ECX = ECX - 1
    CMP ECX, 0          ; сравнение ECX и 0
    JE j2               ; если ECX = 0

j1:
    SHL EAX, 4          ; сдвиг влево на 4 бита
    SHL EDX, 4          ; сдвиг влево на 4 бита

    LOOP j1             ; ECX = ECX - 1. Переход в начало цикла (j1), если ECX ≠ 0

j2:
    OR ESI, EAX         ; ESI = ESI or EAX
    OR EBP, EDX         ; EBP = 

    POP EDX             ; восстановление EDX
    POP EAX             ; восстановление EAX

    POP ECX             ; восстановление ECX
    LOOP j0             ; ECX = ECX - 1. Переход в начало цикла (j0), если ECX ≠ 0

    PUSH EBP
    PUSH ESI
    PUSH offset result  ; вывод результата
    call crt_printf
    ADD ESP, 3 * 4      ; очистка стека

    call crt__getch ; задержка ввода

    push 0
    call ExitProcess ; выход из программы

end start




