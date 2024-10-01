org 0h
jmp main;
	
;процедура сканирования клавиатуры. После нажатия клавиши в R4-скан-код
scan:
	acall waitBisy
	mov R4,#1 			;сброс scancode
	mov R7,#4 			;загрузка счетчика сканирования
	mov R6,#11111110b 	;загрузка исходного байта сканирования
cycle:
	mov A,R6
	mov P1,A 			;вывод текущего байта сканирования 
	RL A             	;сдвиг байта сканирования 
	mov R6,A          	;сохранение текущего байта сканирования 
	mov A,P2           	;ввод байта возврата 
	mov R5,#5         	;загрузка счетчика опросов 
rotate:
	RRC A             	;сдвиг байта возврата 
	JNC asciiByScan		    ;выход из процедуры при обнаружении первой нажатой клавиши 
	INC R4            	;инкремент SCANCODE 
	DJNZ R5,rotate    	;декремент счетчика опросов и цикл, если не нуль
	DJNZ R7,cycle      	;декремент счетчика сканирования и цикл, если не 0
	JMP SCAN          	;начать сканирование сначала 	
ret

;Ждать, пока клавиша нажата
waitBisy:
	mov A,#0FFH 
	sleep  : 
		CJNE A,P2,sleep ;если клавиша нажата, то ждать
ret

; Заполнение ASCII кодов
initAscii:
	mov R1, #1Fh 
	mov @R1, #031h 	;1
	mov R1, #20h 
	mov @R1, #032h 	;2
	mov R1, #21h 
	mov @R1, #033h 	;3
	mov R1, #22h 
	mov @R1, #043h 	;C
	mov R1, #23h 	
	mov @R1, #044h	;D
	mov R1, #024h	
	mov @R1, #034h	;4
	mov R1, #025h
	mov @R1, #035h	;5
	mov R1, #026h	
	mov @R1, #036h	;6
	mov R1, #027h
	mov @R1, #045h	;E
	mov R1, #028h
	mov @R1, #046h	;F
	mov R1, #029h
	mov @R1, #037h	;7
	mov R1, #02Ah	
	mov @R1, #038h	;8
	mov R1, #02Bh
	mov @R1, #039h	;9
	mov R1, #02Ch
	mov @R1, #047h	;g
	mov R1, #02Dh
	mov @R1, #048h	;h
	mov R1, #02Eh
	mov @R1, #041h	;a
	mov R1, #02Fh
	mov @R1, #030h	;0
	mov R1, #030h
	mov @R1, #042h	;b
	mov R1, #031h
	mov @R1, #049h	;i
	mov R1, #032h
	mov @R1, #04Ah	;j
ret

asciiByScan:
	mov A,R4
	add A,#30
	mov R1,A
	mov A,@R1
	mov R4,A
	jmp sendAscii
ret

; Настройка приемо-передатчика
configUapp:
	setb SCON.7		; Устанавливаем 3-ый режим работы 
	setb SCON.6 	; приемо-передатчика
	clr SCON.5		; Запрещаем 
	clr SCON.4		; прием
	setb SCON.3 	; устанавливаем программируемый девятый бит в единицу.
	
	; Настраиваем таймер
	orl TMOD,#00100000b ; Исп. внутрениий генератор,  разрешить режим автоподгрузки
	mov SCON,#01100010b ; Перейти в первый режим работы, запретить прием..... 
	mov TH0, #0fdh      ; Настроить скорость 
	mov TL0, #0fdh		; на 9600	
ret

; Включаем таймер устанавливая соответствующий бит
startTimer:
	setb TCON.6  
ret

; Выключение таймера
stopTImer:
	clr TCON.6
ret

; Отправка данных во внешнюю память 
sendAscii:
	mov A,R4
	mov C,PSW.0
	mov SCON.3,C
	movx @DPTR,A
	inc DPTR
	mov SBUF,A
	jmp scan
ret
	
main:
	mov DPTR,#0
	acall configUapp
	acall startTimer
	acall initAscii
	acall scan
exit:
	acall stopTimer
	jmp $
end