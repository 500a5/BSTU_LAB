org 00h
jmp start

org 0Bh
inc r0
;cjne r0, #15, j_reti
cjne r0, #1, j_reti
mov r0, #0h
jmp inc_sec
j_reti:
	reti

org 30h
start: 
mov r0, #0h
mov r1, #0h
mov r2, #0h
mov r3, #0h
mov r4, #0h
mov r5, #0h
mov r6, #0h
;глобальное разрешение прерываний и прерывание таймера 0
mov ie, #10000010b
;переключение таймера 0 в 1 режим
mov tmod, #1h
;запуск таймера 0 
setb tr0
main_loop:
 	;сегмент 1
	clr p3.3
	clr p3.4
	mov a,r2
	call prep_seg
	call delay
	mov p1,#0FFh

 	;сегмент 2
	setb p3.3
	clr p3.4
	mov a,r3
	call prep_seg
	call delay
	mov p1,#0FFh

 	;сегмент 3
	clr p3.3
	setb p3.4
	mov a,r4
	call prep_seg
	call prep_dot
	call delay
	mov p1,#0FFh

	;сегмент 4
	setb p3.3
	setb p3.4
	mov a,r5
	call prep_seg
	call delay
	mov p1,#0FFh
jmp main_loop

prep_dot:
	cjne r6,#0,reset_dot
		setb p1.7
		ret
	reset_dot:
		clr p1.7
		ret

prep_seg:
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

inc_sec:
	mov a, r6
	cpl a
	mov r6, a		; инверсия флага точки
	inc r1			; секунды
	;cjne r1, #60, end_inc_sec
	cjne r1, #1, end_inc_sec
	  mov r1, #0h		
	  inc r2		; единицы минут
	  ;cjne r2, #10, end_inc_sec
	  cjne r2, #1, end_inc_sec
	    mov r2, #0h
	    inc r3		; десятки минут
	    ;cjne r3, #6, end_inc_sec
	    cjne r3, #1, end_inc_sec
	      mov r3, #0h
	      inc r4		; единицы часов
	      cjne r5, #2, hour_full ; если десятки часов не равны 2
	        cjne r4, #4, end_inc_sec
	          mov r4, #0h
	          mov r5, #0h
	          reti
	        hour_full:
	          cjne r4, #10, end_inc_sec
	            mov r4, #0h
	            inc r5
	end_inc_sec:
		reti

delay:
	mov b,#200
	djnz b, $
	ret
