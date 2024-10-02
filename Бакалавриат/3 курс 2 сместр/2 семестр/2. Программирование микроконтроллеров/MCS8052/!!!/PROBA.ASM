    org 00h
    jmp start
    ORG 8100h
OutpDigit_Cur:              ;Вывод текущего угла
    mov dptr, #port_c       ;Вывод через порт С
    mov A, R2               ;В R2 единицы
    movx @dptr, A           ;Выводим на 2 индикатор
    call Delay
    mov A, R1               ;В R1 десятки
    movx @dptr, A           ;Выводим на 1 индикатор
    call Delay
ret
OutpDigit_Targ:             ;Вывод целевого угла
    mov dptr, #port_c       ;Вывод через порт С
    mov A, 53h              ;В 53h десятки
    ;mov A, #01h
    orl A, #40h             ;Выбираем 3 индикатор
    ;add A, #40h
    ;orl A, #01000000b
    movx @dptr, A           ;Выводим на 3 индикатор
    call Delay
    mov A, 54h              ;В 54h единицы
    ;mov A, #02h
    orl A, #80h             ;Выбираем 3 индикатор
    ;add A, #80h
    ;orl A, #10000000b
    movx @dptr, A           ;Выводим на 3 индикатор
    call Delay
ret
Read_ADC:                   ;чтение с АЦП
    mov R1, #010h
    mov R2, #020h
    ;mov R3, #040h
    ;mov R4, #080h
    setb p1.0
    clr p1.0
    jb p1.1,$
    mov DPTR, #port_b
    movx A, @DPTR
ret
Perevod:
    mov B, #46h
    mul AB
    mov R7, A
    mov A, B
    mov B, #0Ah
    div AB
    swap A
    mov R6, A
    mov A, B
    mov A, R7
    clr Acc.0
    clr Acc.1
    clr Acc.2
    clr Acc.3
    add A, B
    swap A
    mov B, #0Ah
    div AB
    add A, R6
    mov R6, A
    mov A, R7
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    swap A
    add A, B
    swap A
    mov B, #0Ah
    div AB
    mov R5, A
    mov A, B
    add A, R4
    mov R4, A
    mov A, R6
    mov B, #0Ah
    div AB
    swap A
    mov R6, A
    mov A, R5
    swap A
    add A, B
    swap A
    mov B, #0Ah
    div AB
    add A, R6
    mov R6, A
    mov A, B
    add A, R3
    mov R3, A
    mov A, R6
    mov B, #0Ah
    div AB
    add A, R1
    mov R1, A
    mov A, B
    add A, R2
    mov R2, A
ret
Translate:                  ; Процедура перевода собирающая R1 и R2 вместе
    mov A, R2
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    mov R2, A
    mov A, R1
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    ;swap A
    mov B, #0Ah
    mul AB
    add A, R2
ret
Delay:
    mov 32h, #5
cicl:
    mov 33h, #100
    djnz 33h, $
    djnz 32h, cicl
ret

    port_a equ 0h
    port_b equ 01h
    port_c equ 02h
    port_d equ 03h
    _bis_ equ 82h
    for_A equ 011h

start:
    clr RS0
    clr RS1
    orl TMOD, #01h
    mov DPTR, #port_d
    mov A, #_bis_
    movx @DPTR, A
    mov DPTR, #port_a
    mov A, #for_A
    movx @DPTR, A
    ;call Read_ADC           ;чтение из АЦП
    ;call Perevod            ;перевод в градусы
    ;call OutpDigit_Cur      ;вывод текущего угла
    ;call Translate          ;перевод (соединение R1 и R2)
    mov 50h,#2dh
    mov 51h,#0Ah
    ;mov 51h,#50h
    mov 52h,#5Ah
   ; mov 53h,#00h
    mov R0,#50h
    ;mov 54h,#00h

    ;mov 50h, A              ;сохранение в 50h
    ;mov 70h, #08h           ;в 70h 2 градуса

begin:
    setb p1.6               ;запуск МЭО
    clr p1.7                ;запуск МЭО
    ;clr p1.6
    ;setb p1.7
    ;mov 41h, #2Dh
    ;mov 42h, #14h
    ;mov 43h, #50h
    ;mov 44h, #0h
    ;mov R0, 41h
go:
    ;mov A, 70h
    ;rl A                    ;сдвиг вправо - получаем 4 градуса
    ;mov 70h, A
    ;jbc p1.7, decrem
    ;add A, 50h              ;прибавляем к текущему углу
    ;mov 50h, A              ;сохраняем текущий угол
    ;jmp hod
;decrem:
    ;mov A, 50h
    ;subb A, 70h
    ;mov 50h, A
    ;setb p1.7
    ;clr p1.6
    ;jmp hod
;hod:

    ;mov A,50h
    mov A,@R0
    mov B, #0Ah             ;в В 10
    div AB                  ;делим содержимое А на 10
    mov 53h, A              ;в 53h частное
    mov 54h, B              ;в 54h остаток
    call OutpDigit_Targ     ;вывод целевого угла
m:
    call Read_ADC           ;чтение с АЦП
    call Perevod            ;перевод
    call OutpDigit_Cur      ;вывод текущего угла
    call OutpDigit_Targ
    call Translate
    cjne A, #0h, more_zero  ;если текущий угол не равен 0, то на more_zero
    jmp mend                ;иначе на mend
more_zero:
    cjne A, #5Ah, less_90   ;если текущий угол не равен 90, то на less_90
    jmp mend                ;иначе на mend
less_90:
    ;cjne A, R0, m          ;если текущий не равен целевому то на m
;    mov 50h,@R0
    cjne A,50h, m
    mov R0,#50h
    inc R0
    mov 50h,@r0
 ;    setb p1.6
;     setb p1.7
     ;                       jmp reverse_trace
    ;cjne A,@R0,m
    jbc p1.6, reverse_trace ;если установлен p1.6 d единицу то на reverse_trace
forward_trace:              ;прямой ход
    setb p1.6
    clr p1.7
    ;inc R0
    ;mov 77h, #2Dh
    ;mov 50h, A

    jmp go
    ;setb p1.7
    ;clr p1.6
reverse_trace:              ;реверс
    ;mov 50h,
    ;mov 50h,#14h

    ;mov 50h,
    clr p1.6
    setb p1.7
    ;mov 77h, #14h
    ;inc R0
    ;mov 50h, A
    ;clr p1.7
    ;setb p1.6
    jmp go
mend:                       ;останов МЭО
    setb p1.6
    setb p1.7
    jmp $
end
