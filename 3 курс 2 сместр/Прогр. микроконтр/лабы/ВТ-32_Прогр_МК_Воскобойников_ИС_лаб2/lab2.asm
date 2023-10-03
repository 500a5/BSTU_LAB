ORG 0h
	jmp main
step_time_int: 
        ORG 0Bh;Тут прерывание от таймера номер 0
        CLR TF0;Очищаем флаг прерывания
	
	call step_time
	
        RETI ;выход из перывания

semi_out_int:
        ORG 1Bh;Тут прерывание от таймера номер 1
        CLR TF1;Очистка флага прерывания
	MOV P1, #0FFh
	setb p3.3
	setb p3.4
	setb p3.6
	setb p3.7
	
	;первая лампочка
        CJNE R0, #0h, lam_skip_1
        mov A, r1;берем число соответствующее лампочке
        clr p3.3;выбираем лампочку

        lam_skip_1:        
      	;вторая лампочка
        CJNE R0, #1h, lam_skip_2
        mov A, r2
        setb p3.3
        clr p3.4
        
        lam_skip_2:        
        CJNE R0, #2h, lam_skip_3
        mov A, r3
        setb p3.4
        clr p3.6
        
        lam_skip_3:        
        CJNE R0, #3h, lam_skip_4
        mov A, r4
        setb p3.6
        clr p3.7
        
        lam_skip_4:        

	;Заносим цифру в A и вызываем функцию которая отображает ее в P1
	call get_semi_code	
	
        CJNE R0, #1h, term;если вывод на вторую лампочку то там ставится точка, она получится по центру
        CLR P1.7
        
   term:
        inc R0	;переходим к следующему сегменту
        CJNE R0, #00000100b, end_semo_circle ;Если дошли до конца семи сегментного индикатора то обнуляем счетчик лампочек
        MOV R0,#0b
        
   end_semo_circle:
        RETI;Выход из прерывания вывода
        
main:        

;T1 M1=1 M0=0 по прерыванию первого таймера мы выводим в индикатор
	;T0 M1=0 M0=1 по этому прерыванию увеличиваем время
	MOV TMOD,#00100001b

	MOV TH0, #0DCh;2^16-10000=55536=0D8F0h
	MOV TL0, #0h
	
        ;разрешаем прерывание от таймера 0
        SETB ET0
        ;разрешаем прерывание от таймера 1
        SETB ET1
        ;разрешаем выполнение прерываний
        SETB EA
        

        SETB TR1;запускаем таймер 1

        ;инициализация начальных значений
	call init_timer
	
        SETB TR0;запускаем таймер 0
        
        jmp $;Бесконечный цикл работы

;шаг таймера
step_time:
        MOV TH0, #0DCh;обновляем настройки таймера
	MOV TL0, #0h

	;получаем десятки секунд в r1
        MOV A, r6
        MOV B, #0Ah
        DIV AB
        MOV r1,A
        
	;получаем количество секунд в r2
        MOV r2,B
        
        ;получаем сотни милисекунд в r3
        MOV A, r5
        MOV B, #0Ah
        DIV AB
        MOV r3,A
        
        ;получаем десятки милисекунд в r4
        MOV r4,B

        INC r5
        CJNE r5, #100, MS;Если не получили 1000 милисекунд прыгаем дальше
        ;Если получили обновляем счетчик
        MOV r5, #0
        
        INC r6
        CJNE r6, #0, MS;Если не получили 60 секунд прыгаем дальше
        MOV r6, #0;Если получили обновляем счетчик
        
   MS:	
	RET
	
;отображение цифры из А в P1
get_semi_code:
	cjne a,#9, num8
		mov p1,#10010000b
		ret
	num8:
	cjne a,#8, num7
		mov p1,#10000000b
		ret
	num7:
	cjne a,#7, num6
		mov p1,#11111000b
		ret
	num6:
	cjne a,#6, num5
		mov p1,#10000010b
		ret
	num5:
	cjne a,#5, num4
		mov p1,#10010010b
		ret
	num4:
	cjne a,#4, num3
		mov p1,#10011001b
		ret
	num3:
	cjne a,#3, num2
		mov p1,#10110000b
		ret
	num2:
	cjne a,#2, num1
		mov p1,#10100100b
		ret
	num1:
	cjne a,#1, num0
		mov p1,#11111001b
		ret
	num0:
	mov p1,#11000000b
	ret

init_timer:
	;считываем кол-во десятков часов
	call read_sim
	call pause
	;закидываем считанное в соответствующие регистры
	mov a, r7
	mov r1, a
	mov b, #0Ah
	MUL ab
	;переносим что бы оно не затерлось
	mov 50h, a
	
	;считываем кол-во часов
	call read_sim
	call pause
	;восстанавливаем значение a
	mov a, 50h
	;закидываем считанное в соответствующие регистры
	mov b, r7
	mov r2, b
	add a, b
	mov r6, a

	;считываем кол-во десятков минут
	call read_sim
	call pause
	;закидываем считанное в соответствующие регистры
	mov a, r7
	mov r3, a
	mov b, #0Ah
	MUL ab
	;запоминаем a что б не потерлось
	mov 50h, a

	;считываем кол-во минут
	call read_sim
	;восстанавливаем a
	mov a, 50h
	;закидываем считанное в соответствующие регистры
	mov b, r7
	mov r4, b
	add a, b
	mov r5, a
	
	ret

read_sim:
	mov r7, #0
read_loop:
	;пока не считываем число в не выходим из цикла
	cjne r7, #0, read_out
	call scanKeyBoard
	jmp read_loop
	
read_out:
	ret

; Сканирование по рядам
scanKeyBoard:
	mov p0, #11111111b

	clr p0.3
 	CALL scanRow1

	setb p0.3
	clr  p0.2
 	CALL scanRow2
 	
	setb p0.2
	clr  p0.1
 	CALL scanRow3
 	
	setb p0.1
	clr  p0.0
 	CALL scanRow4

	ret

; Сканирование первого ряда
scanRow1:
	MOV A, #1h
 	JNB P0.6, pressKeyR1
	
	MOV A, #2h
 	JNB P0.5, pressKeyR1
	
	MOV A, #3h
	JNB P0.4, pressKeyR1
 	
	ret ; ключ не найден
	
     pressKeyR1:
	call putc
	ret

; Сканирование второго ряда
scanRow2:
	MOV A, #4h
 	JNB P0.6, pressKeyR2
	
	MOV A, #5h
 	JNB P0.5, pressKeyR2
	
	MOV A, #6h
	JNB P0.4, pressKeyR2
 	
	ret ; ключ не найден
	
     pressKeyR2:
	call putc
	ret
	
; Сканирование третьего ряда
scanRow3:
	MOV A, #7h
 	JNB P0.6, pressKeyR3
	
	MOV A, #8h
 	JNB P0.5, pressKeyR3
	
	MOV A, #9h
	JNB P0.4, pressKeyR3
 	
	ret ; ключ не найден
	
     pressKeyR3:
	call putc
	ret

; Сканирование четвертого ряда
scanRow4:
	MOV A, #0
 	JNB P0.5, pressKeyR4
 	
	ret ; ключ не найден
	
     pressKeyR4:
	call putc
	ret
	
;перевеод числа из A в r7
putc:
	mov r7, a
	ret

;ожидание что бы цифра проявилась
pause:
	mov b,#200
	djnz b, $
	ret
END