.686 ; Тип процессора

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

.data
  digit db 6 dup(10101010b)
  digitMask db 5 dup(00000000b), 00001111b
  useN db 4
  canUse db 10100011b, 10100101b, 10100111b, 10101111b
  format db "%X", 0
  formatN db 10, 0
.code
  outputArray proc
    PUSH EDI
    PUSH ESI
    MOV EDI, [ESP + 16] 	; digit[0]
    MOV ESI, [ESP + 12] 	; n
    PUSH EAX
    PUSH EBX
    PUSH EDX
    PUSH ECX
    
    MOV EBX, [ESP + 36] 	; index
    
    SUB ESP, 6 				; Буфер под локальную строку формата
    MOV BYTE PTR [ESP], '%'		; Сформируем локальную строку формата для вывода
    MOV BYTE PTR [ESP + 1], '2'
    MOV BYTE PTR [ESP + 2], 'd'
    MOV BYTE PTR [ESP + 3], ':' 
    MOV BYTE PTR [ESP + 4], ' '
    MOV BYTE PTR [ESP + 5], 0h
    MOV EBP, ESP

    PUSH EBX    
    PUSH EBP
    call crt_printf
    ADD ESP, 14    
    
    MOV ECX, 0
    cycle:
      XOR EAX, EAX
      MOV AL, [EDI+ECX]
      push ECX
      push EAX
      
      PUSH EAX
      push offset format
      call crt_printf
      ADD ESP, 8

      pop EAX
      pop ECX
      INC ECX 
      CMP ESI, ECX
      JNE cycle
    push offset formatN
    call crt_printf
    ADD ESP, 4
    POP ECX
    POP EDX
    POP EBX
    POP EAX
    POP ESI
    POP EDI
    RET 12
  outputArray endp
start:
  MOV ECX, 4
  XOR EBX, EBX
  MOV ESI, 1  
  mainLoop:   
    PUSH ECX
    DEC ECX
    MOV BL, canUse[ECX]    
    MOV digit[5], BL
    MOV ECX, 6
    subLoop:
      PUSH ECX
      SUB ECX, 2
      MOV EDX, ECX
      MOV ECX, 2
      doubleLoop:
        PUSH ESI
        PUSH offset digit
        PUSH 6
        CALL outputArray
        INC ESI
        
        MOV EBX, -1
        CMP EBX, EDX
        JNE swapNear
          ROL digit[0], 4
          JMP endDoubleLoop
        swapNear:
          ROL word ptr digit[EDX], 4
        endDoubleLoop:
          LOOP doubleLoop      
      POP ECX
      LOOP subLoop
    endLoop:
      MOV digit[0], 10101010b
      POP ECX
    LOOP mainLoop
    
  call crt__getch
  push 0
  call ExitProcess
end start
