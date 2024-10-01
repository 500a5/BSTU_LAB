desatki data 31h
edinicy data 32h
org 0000h
jmp MAIN

org 000BH
jmp count
org 001BH
jmp timer

org 8100h

count:
	MOV TL0,#82h
	INC 30h
RETI


raschet:
    PUSH ACC
        clr A
        mov edinicy,#0
        mov desatki,#0
        MOV A,36h
        MOV B,#2
        MUL AB
        MOV B,#10
        DIV AB
        MOV desatki,A
        MOV edinicy,B
        clr A
        POP ACC
   RET
   
vivod:
      PUSH ACC
          CJNE R3,#0,metka5
          MOV R3,#1
          MOV A,desatki
          ORL A,#00010000b
          MOV DPL,#2
          MOVX @DPTR,A
         jmp v_end
metka5:
      MOV R3,#0
          MOV A,edinicy
          ORL A,#00100000b
          MOV DPL,#2
          MOVX @DPTR,A
v_end:
       CLR A
           POP ACC
        RET

timer:  
	   INC 33h
	   MOV R5,33h
        CJNE R5,#4,m_end   ;zdem 1 ms
          mov 33h,#0
          INC 34h ;повышаем милисекунды
		  ;INC A
			MOV R5,34h
			CJNE R5,#250d,m_end
			MOV 34h,#0
			INC 35h
			MOV R5,35h
			CJNE R5,#4d,m_end
			MOV 36h,30h
			MOV 30h,#0
			MOV 34h,#0
			MOV 35h,#0
m_end:
	CALL raschet
    CALL vivod
    mov TH0,#5
RETI



PAUSA:
	MOV B,#02
	DIV AB
	MOV 14h,A
	CJNE A,#00h,ee
	jmp ee2
	ee:
		PAUSA2: MOV 10h,#10d 	;10
			PAUSA3: MOV 11h,#98d
				PAUSA4: 
				DJNZ 11h,PAUSA4
			DJNZ 10h,PAUSA3
		DJNZ 14h,PAUSA2
	ee2:
RET

per1:
	MOV 1Fh,#00d
	MOV 1Eh,#10d
	MOV 1Dh,#20d
	MOV 1Ch,#30d
	MOV 1Bh,#40d
	MOV 1Ah,#50d
	MOV 19h,#60d
	MOV 18h,#70d
	MOV 17h,#80d
	MOV 16h,#90d
	MOV 15h,#100d
ret

per2:
	mov 1fh,#00d
	mov 1eh,#10d
	mov 1dh,#20d
	mov 1ch,#30d
	mov 1bh,#40d
	mov 1ah,#50d
	mov 19h,#60d
	mov 18h,#70d
	mov 17h,#80d
	mov 16h,#90d
	mov 15h,#100d
ret

MAIN:
	;выбираем 0 БАНК
	CLR PSW.4	;RS1 0
	CLR PSW.3	;RS0 0            
	MOV 30h,#0
	MOV 33h,#0
	MOV 34h,#0
	MOV 35h,#0
	MOV 36h,#0
	;SETB RS0	;3 банк
	;SETB RS1
	MOV DPTR,#03h   
	MOV A,#82h
	MOVX @DPTR,A  
	mov IE, #10011010b ;razresheniye preryvaniya
	MOV A,TMOD
	ORL A,#00000111b
	MOV TMOD,A
	MOV TH0,#5 ;таймер
	MOV TL0,#82h ;счетчик
	SETB TR0	;запускаем таймеры
	SETB TR1

	;MOV TH0,#255d
	;MOV TL0,#82h
	
	;MOV R1,#040d    
	;MOV R2,#03Ch    
	
	;MOV A,R1
	;MOV B,#04h
	;DIV AB                  
	;MOV B,#01h
	;DIV AB  
	
	MOV A,#10d
	MOV R0,A
	MOV R4,A    
	
	
	

	;SETB TCON.4 ;запускаем таймер
	
	;MOV A,28d
	;MOV DPTR,#0002h
	;MOV B,#10d
	;DIV AB
	;SETB ACC.6
	;MOVX @DPTR,A ;66
	
	;MOV R2,#0FFh ;цикл 65мс
	;zad2:
	;	MOV R1,#0FFh
	;	za:
	;	DJNZ R1,za
	;DJNZ R2,zad2

period:
	;INC R5
	call per1
	MOV 12h,#10100000b ;A0 - 160
	MOV 13h,#01100000b ;60  - 96
	JMP start
	
period2:
	call per2
	MOV 12h,#01010000b ;50-80
	MOV 13h,#01100000b ;60-96 
start:    
	MOV R0,#1Fh 
	first1:
	
	JMP fit

	w1:JMP period2
	w2:JMP period
	fit:
		MOV R0,#15h
	first2:
		MOV DPH,#01h
		MOV R6,#0Ah
		INC R0
	L2:
		;CALL raschet
		MOV A,@R0
		MOV P1,12h              ;10100000
		LCALL PAUSA
		MOV A,@R0
		SUBB A,#100d    
		CPL A
		INC A
		MOV P1,13h              ;10010000
		LCALL PAUSA
		;CJNE R6,#06h,tyz
		;LCALL vivod1
		;tyz:
	DJNZ R6,L2
	;LCALL vivod2
	CJNE R0,#1Fh,first2
	MOV A,12h
	JB ACC.7,w1
	jmp w2

end