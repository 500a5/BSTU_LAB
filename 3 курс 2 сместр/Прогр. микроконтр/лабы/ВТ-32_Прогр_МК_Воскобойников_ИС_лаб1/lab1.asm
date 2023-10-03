ORG 0
	JMP main

; обработчик прерывания int1
org 13h	; int1
	call scanKeyBoard
	mov p0, #0
	reti

org 030h
main:
	; Настройка работы UART
	CLR SM0 
	SETB SM1 ; 2 режим, 8 бит, стоп/старт, четность

	MOV A, PCON 
	SETB ACC.7 
	MOV PCON, A ; 7 бит в PCON установлен в 1, множитель скорости 2 
	; Настройка таймера
	; При переполнении записывается из TL1 в TH1 (M1 = 1, M0 = 0)
	MOV TMOD, #20H 
	MOV TH1, #243
	MOV TL1, #243 
	SETB TR1 ; запуск таймера 1
	; Настройка прерывания
	SETB IT1 ; по срезу
	SETB EX1 ; прерывание от INT1
	SETB EA	; разрешить все прерывания
	
	mov r1, #0FFh
	mov r2, #0FFh
	mov r3, #0FFh
	mov r4, #0FFh
	
; Бесконечный цикл вывода в семи сегментный индикатор
mainLoop:
; Устанавливаем в порте 0, чтобы ждать прерывания при нажатии
	mov p0, #0
	mov b,#10
	djnz b, $
	CLR EX1
	
	call printToSeg
	
	SETB EX1
	jmp mainLoop
	
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
	MOV A, #31h
	MOV r0, #11111001b
 	JNB P0.6, pressKeyR1
	
	MOV A, #32h
	MOV r0, #10100100b
 	JNB P0.5, pressKeyR1
	
	MOV A, #33h
	MOV r0, #10110000b
	JNB P0.4, pressKeyR1
 	
	ret ; ключ не найден
	
     pressKeyR1:
	call putc
	ret

; Сканирование второго ряда
scanRow2:
	MOV A, #34h
	MOV r0, #10011001b
 	JNB P0.6, pressKeyR2
	
	MOV A, #35h
	MOV r0, #10010010b
 	JNB P0.5, pressKeyR2
	
	MOV A, #36h
	MOV r0, #10000010b
	JNB P0.4, pressKeyR2
 	
	ret ; ключ не найден
	
     pressKeyR2:
	call putc
	ret
	
; Сканирование третьего ряда
scanRow3:
	MOV A, #37h
	MOV r0, #11111000b
 	JNB P0.6, pressKeyR3
	
	MOV A, #38h
	MOV r0, #10000000b
 	JNB P0.5, pressKeyR3
	
	MOV A, #39h
	MOV r0, #10010000b
	JNB P0.4, pressKeyR3
 	
	ret ; ключ не найден
	
     pressKeyR3:
	call putc
	ret

; Сканирование четвертого ряда
scanRow4:
	MOV A, #02ah
	MOV r0, #01111111b
 	JNB P0.6, pressKeyR4
	
	MOV A, #30h
	MOV r0, #11000000b
 	JNB P0.5, pressKeyR4
	
	MOV A, #23h
	MOV r0, #10111111b
	JNB P0.4, pressKeyR4
 	
	ret ; ключ не найден
	
     pressKeyR4:
	call putc
	ret
	
;печать символа из А на UART и запись символа в буфер семисегментного индикатора
putc:
	MOV C, P
	MOV ACC.7, C ; бит чётности
	MOV SBUF, A 	;отправляем символ на печать
	JNB TI, $	;ожидаем пока выведется
	CLR TI		;очищаем флаг на будущее
	call shift
	ret
	
;вывод символов из регистров r1-r4 на семисегментный индикатор
printToSeg:
	
	SETB p0.7
	;сегмент 1
	clr p3.3
	clr p3.4
	mov p1, r1
	;для нормального отображения
	call pause
	mov p1, #0FFh

 	;сегмент 2
	setb p3.3
	clr p3.4
	mov p1, r2
	call pause
	mov p1, #0FFh

 	;сегмент 3
	clr p3.3
	setb p3.4
	mov p1, r3
	call pause
	mov p1, #0FFh
	
	;сегмент 4
	setb p3.3
	setb p3.4
	mov p1, r4
	call pause
	mov p1, #0FFh	
	
	ret

;ожидание что бы цифра проявилась
pause:
	mov b,#200
	djnz b, $
	ret

;функция делает следующее
;r4=r3
;r3=r2
;r2=r1
;r1=r0
shift:
	mov A, r3
	mov r4, A

	mov A, r2
	mov r3, A

	mov A, r1
	mov r2, A

	mov A, r0
	mov r1, A
	ret