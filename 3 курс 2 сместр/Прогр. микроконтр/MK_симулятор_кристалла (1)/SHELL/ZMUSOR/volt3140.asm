org 0h
jmp begin
org 8060h
begin:
mov A,#82h
mov dptr,#3
movx @dptr,A
mov A,#40h
mov dptr,#0
movx @dptr,A
                     ;память для запоминания:
mov 30h,#0           ;числа с порта B
mov R0,#0            ;знака  
mov R1,#0            ;едениц
mov R2,#0            ;десятков 
mov R3,#0            ;сотен

loop:
clr p1.0
jb p1.1,$
mov dptr,#1
movx A,@dptr         ;запись числа с порта B
setb p1.0
                     ;если число с порта В:
cjne A,30h,loop6     ;меняется, то преобразуем его и выводим
jmp loop7            ;не меняется, то сразу выводим
loop6:
mov 30h,A
call PROG1
call PROG2
loop7:
call VIVOD

jmp loop

PROG1:
jbc ACC.7,loop1      ;определение знака
jnb ACC.7,loop2
loop1:               ;если плюс то R0=0
mov R0,#0
jmp loop3
loop2:               ;если минус то R0=1
mov R0,#1
cjne A,#0,loop8
mov A,#128
jmp loop3
loop8:               ;нахождение обратного числа
cpl A
add A,#1
anl A,#127
loop3:               ;разделение числа по регистрам
mov B,#10
div AB
mov R1,B             ;еденицы
mov B,#10
div AB
mov R2,B             ;десятки
mov R3,A             ;сотни
ret

PROG2:               ;умножение на 4 числа разбитого по регистрам
mov A,R1
mov B,#4
mul AB               ;умножение еденииц на 4
mov B,#10
div AB
mov R1,B
mov R4,A
mov A,R2
mov B,#4
mul AB               ;умножение десятков на 4
add A,R4             ;прибавления к десяткам переноса
mov B,#10
div AB
mov R2,B
mov R4,A
mov A,R3
mov B,#4
mul AB               ;умножение сотен на 4
add A,R4             ;прибавления к сотням переноса
mov R3,A
ret

VIVOD:               ;вывод числа на индикатор
mov dptr,#2
cjne R0,#1,loop4
mov A,#00011100b
movx @dptr,A         ;вывод знака
call DELAY
loop4:
mov A,R3
orl A,#00100000b
movx @dptr,A         ;вывод сотен
call DELAY
mov A,R2
orl A,#01000000b
movx @dptr,A         ;вывод десятков
call DELAY
mov A,R1
orl A,#10000000b
movx @dptr,A         ;вывод едениц
call DELAY
ret

DELAY:               ;задержка для вывода числа
mov R7,#60
loop5:
movx @dptr,A
djnz R7,loop5
ret

end