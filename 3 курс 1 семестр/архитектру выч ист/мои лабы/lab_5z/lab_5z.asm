.386
.model flat, stdcall
option casemap: none
 
; --- Подключение файлов с кодом, макросами, константами, прототипами функций и т.д.
 include c:\masm32\include\windows.inc
 include c:\masm32\include\kernel32.inc
 include c:\masm32\include\user32.inc
 include c:\masm32\include\msvcrt.inc

 ; --- Подключаемые библиотеки ---
 includelib c:\masm32\lib\user32.lib
 includelib c:\masm32\lib\kernel32.lib
 includelib c:\masm32\lib\msvcrt.lib

 
.data
    fmatr dd ?
    smatr dd ?
    k dd ?
    q_num dq 0.0
    in_fr db "%i", 0
    in_fr2 db "%lf", 0
    out_fr db "%lf ", 0
    out_fr2 db 13, 10, 0
.code
 
;allc_matr(double** matr, int m, int n)
allc_matr proc
    PUSH EAX
    PUSH EBX
    PUSH ECX
    PUSH EDX
    MOV EDX, 0
    MOV EAX, [ESP + 24]
    MOV EBX, [ESP + 28]
    MOV ECX, 8
 
    MUL EBX                 ;Вычисляем размер памяти
    MUL ECX
 
    MOV EBX, [ESP + 20]     ;ebx = **matr
    call GetProcessHeap     ;Получаем указатель на кучу
    PUSH EAX
    PUSH 0
    PUSH EAX
    call HeapAlloc
    MOV [EBX], EAX
 
    POP EDX
    POP ECX
    POP EBX
    POP EAX
    RET 12
allc_matr endp  
 
;free_matr(double** matr, int m, int n)
free_matr proc
free_matr endp
 
;read_matr(double* matr, int m, int n)
read_matr proc
    PUSH ECX
    PUSH EBX
 
    MOV EBX, [ESP + 12]         ;указатель на матрицу
    MOV ECX, [ESP + 16]
    rm_cycl1:
        PUSH ECX
        MOV ECX, [ESP + 24]
        rm_cycl2:
            PUSH ECX
            
            PUSH EBX
            PUSH offset in_fr2
            call crt_scanf
            ADD ESP, 8
 
            POP ECX
            ADD EBX, 8
        LOOP rm_cycl2
        POP ECX
    LOOP rm_cycl1
 
    POP EBX
    POP ECX
    RET 12
read_matr endp
 
;write_matr(double* matr, int m, int n)
write_matr proc
    PUSH ECX
    PUSH EBX
 
    MOV EBX, [ESP + 12]         ;указатель на матрицу
    MOV ECX, [ESP + 16]
    wr_cycl1:
        PUSH ECX
        MOV ECX, [ESP + 24]
        wr_cycl2:
            PUSH ECX
            
            PUSH DWORD PTR [EBX + 4]
            PUSH DWORD PTR [EBX]
            PUSH offset out_fr
            call crt_printf
            ADD ESP, 12
            POP ECX
 
            ADD EBX, 8
        LOOP wr_cycl2
        PUSH offset out_fr2
        call crt_printf
        ADD ESP, 4
        POP ECX
    LOOP wr_cycl1
 
    POP EBX
    POP ECX
    RET 12
write_matr endp
 
;solve(double* fmatr, double* smatr, int k)
solve proc
    PUSH ESI
    PUSH EDI
    PUSH ECX
 
    MOV ESI, [ESP + 16]
    MOV EDI, [ESP + 20]
    MOV ECX, [ESP + 24]
 
    FINIT
    sl_c1:
        PUSH ECX
        MOV ECX, [ESP + 28]
        sl_c2:
            CMP ECX, [ESP]
            JE step_skip
                FLD QWORD PTR [ESI]
                FSTP QWORD PTR [EDI]
                ADD EDI, 8
            step_skip:
            ADD ESI, 8
        LOOP sl_c2
        POP ECX
    LOOP sl_c1
 
    POP ECX
    POP EDI
    POP ESI
    RET 12
solve endp
start:
    PUSH offset k 
    PUSH offset in_fr
    call crt_scanf
    ADD ESP, 8
    PUSH DWORD PTR k
    PUSH DWORD PTR k
    PUSH offset fmatr
    call allc_matr
    MOV EBX, k 
    SUB EBX, 1
    PUSH EBX
    PUSH DWORD PTR k
    PUSH offset smatr
    call allc_matr
 
    PUSH DWORD PTR k
    PUSH DWORD PTR k
    PUSH DWORD PTR fmatr
    call read_matr
 
    PUSH DWORD PTR k
    PUSH DWORD PTR smatr
    PUSH DWORD PTR fmatr
    call solve
 
    PUSH EBX
    PUSH DWORD PTR k
    PUSH DWORD PTR smatr
    call write_matr
 call crt__getch
    push 0
    call ExitProcess
end start





