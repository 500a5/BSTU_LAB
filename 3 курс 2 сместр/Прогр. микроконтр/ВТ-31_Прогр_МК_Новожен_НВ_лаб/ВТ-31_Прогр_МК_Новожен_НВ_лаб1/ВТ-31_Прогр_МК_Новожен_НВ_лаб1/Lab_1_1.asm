; Символы клавиатуры
org 500h
db 031h, 032h, 033h, 043h, 044h, 034h, 035h, 036h, 045h, 046h, 037h, 038h, 039h, 047h, 048h, 041h, 030h, 042h, 049h, 04Ah

org 0h

loop1:
; Для сканирования выставим 1 на всем порте 0, кроме последнего бита 
mov p0, #11111110b
mov a, p1
; Если кнопки не нажаты, пропускаем
cjne a, 0ffh, j1 
jmp j1_
j1:
; Определяем нажатую кнопку
    jnb p1.0, j10
    jnb p1.1, j11
    jnb p1.2, j12    
    jnb p1.3, j13
    jnb p1.4, j14
; Берем индекс нажатой клавиши
	j10:
		mov a, #0
		jmp j1end
	j11:
		mov a, #1
		jmp j1end
	j12: 
		mov a, #2
		jmp j1end
	j13:
		mov a, #3
		jmp j1end
	j14:
		mov a, #4
    j1end:    
; Отправляем в UART символ с индексом a
    mov dptr, #500h
    movc a, @a + dptr
    mov sbuf, a
    mov sbuf, #10
    mov sbuf, #13
j1_:

; Аналогично первому варианту, но сканируем следующий бит
mov p0, #11111101b
mov a, p1
cjne a, 0ffh, j2 
jmp j2_
j2:
    jnb p1.0, j20
    jnb p1.1, j21
    jnb p1.2, j22    
    jnb p1.3, j23
    jnb p1.4, j24

	j20:
		mov a, #0
		jmp j2end
	j21:
		mov a, #1
		jmp j2end
	j22: 
		mov a, #2
		jmp j2end
	j23:
		mov a, #3
		jmp j2end
	j24:
		mov a, #4
    j2end:    
    mov dptr, #505h
    movc a, @a + dptr
    mov sbuf, a
    mov sbuf, #10
    mov sbuf, #13
j2_:

mov p0, #11111011b
mov a, p1
cjne a, 0ffh, j3 
jmp j3_
j3:
    jnb p1.0, j30
    jnb p1.1, j31
    jnb p1.2, j32    
    jnb p1.3, j33
    jnb p1.4, j34

	j30:
		mov a, #0
		jmp j3end
	j31:
		mov a, #1
		jmp j3end
	j32: 
		mov a, #2
		jmp j3end
	j33:
		mov a, #3
		jmp j3end
	j34:
		mov a, #4
    j3end:    
    mov dptr, #50Ah
    movc a, @a + dptr
    mov sbuf, a
    mov sbuf, #10
    mov sbuf, #13
j3_:

mov p0, #11110111b
mov a, p1 
cjne a, 0ffh, j4 
jmp j4_
j4:
    jnb p1.0, j40
    jnb p1.1, j41
    jnb p1.2, j42    
    jnb p1.3, j43
    jnb p1.4, j44

	j40:
		mov a, #0
		jmp j4end
	j41:
		mov a, #1
		jmp j4end
	j42: 
		mov a, #2
		jmp j4end
	j43:
		mov a, #3
		jmp j4end
	j44:
		mov a, #4
    j4end:    
    mov dptr, #50Fh
    movc a, @a + dptr
    mov sbuf, a
    mov sbuf, #10
    mov sbuf, #13
j4_:
; Повторяем опрос
ljmp loop1

end
