org 0h
	ljmp start

org 0Bh
	JMP TIMERONE

org 1Bh
	JMP TIMER
	
ORG 8100h

start:
	MOV A, TMOD					;3 режим работы 0 таймера (TL0-счётчик, TH0-таймер)
	ANL A, #0F0h
	ORL A, #00000111b 
	MOV TMOD, A	
	
	SETB TR1					;запустили таймер
	SETB TR0					;запустили счётчик
	
	SETB IE.7
        SETB IE.3 
	SETB IE.1
	
	MOV TL0, #243
	
	MOV R1, #0					;№ интервала (0..100)
    MOV R4, #0                  ;№ интервала (1 - 100 .. 9 - 900)
	MOV R2, #0					;t1 открытия
	MOV R3, #100				;Т повторения
    MOV R5, #1                  ;флаг реверса
	
    MOV DPTR, #3h
    MOV A, #82h
    MOVX @DPTR, A       ;настраиваем порты ВК 55
    
mloop:
	;Выводим на экран
	mov DPTR, #2h           ;порт С

    ;mov A, 50h               ;1 цифра     
	;ORL A, #00010000b
    ;movx @DPTR, A
	
	;mov A, 51h             ;2 цифра   
	;ORL A, #00100000b
	;movx @DPTR, A
	
	mov A, 52h             ;3 цифра   
	ORL A, #01000000b
    movx @DPTR, A

	mov A, 53h             ;4 цифра     
	ORL A, #10000000b
    movx @DPTR, A

	jmp mloop
	
interval_END:

	RETI
	
TIMER:
    MOV A, R5
    CJNE A, #1, ReTIMER

	DEC R2
	MOV A, R2
	JNZ NOTOFF
	MOV A, #01100000b            ;открываем 1-й и 3-й транзисторы
	MOV P1, A

NOTOFF:
	DEC R3
	MOV A, R3
	JNZ interval_END
	INC R1
    MOV A, R1
    CJNE A, #100, not100 ;CJNE A, #100, not100 
    MOV R1, #0
	INC R4 
    MOV A, R4
	
	MOV B, #11
	MUL AB
	MOV R7, A
	
	MOV A, R4
    CJNE A, #9, not100
    DEC R5
    JMP rever 

not100: 
	MOV A, R7
	MOV R2, A 
	MOV R3, #100
	MOV A, #01010000b            ;открываем 1-й и 4-й транзисторы
	MOV P1, A
	
	;Вывод для экрана
	;Время
	MOV B, #10
	MOV A, R1
	DIV AB
	MOV 50h, A
	MOV 51h, B
	
	;Обороты
	MOV B, #10
	MOV A, R0
	DIV AB
	MOV 52h, A
	MOV 53h, B
	
	MOV R0, #0

	JMP interval_END

rever:
    MOV R1, #100		         ;№ интервала (0..100)
    MOV R4, #9                   ;№ интервала (1 - 100 .. 9 - 900)
	MOV R2, #100				 ;t1 открытия
	MOV R3, #100			     ;Т повторения

    JMP interval_END

ReTIMER:
    DEC R2
	MOV A, R2
	JNZ NOTOFF2
	MOV A, #01100000b            ;открываем 1-й и 3-й транзисторы
	MOV P1, A

NOTOFF2:
	DEC R3
	MOV A, R3
	JNZ interval_END
	DEC R1
    MOV A, R1
    CJNE A, #0, not0
	MOV R1, #100
    DEC R4 
    MOV A, R4
	
	MOV B, #11
	MUL AB
	MOV R7, A
	
	MOV A, R4
    CJNE A, #0, not0
	jmp start

not0: 
	MOV A, R7
	MOV R2, A 
	MOV R3, #100
	MOV A, #10100000b            ;открываем 2-й и 3-й транзисторы
	MOV P1, A
	
	;Вывод для экрана
	;Время
	MOV B, #10
	MOV A, R1
	DIV AB
	MOV 50h, A
	MOV 51h, B
	
	;Обороты
	MOV B, #10
	MOV A, R0
	DIV AB
	MOV 52h, A
	MOV 53h, B
	
	MOV R0, #0
	JMP interval_END

TIMERONE:
	INC R0
	MOV TL0, #243
	RETI

end
