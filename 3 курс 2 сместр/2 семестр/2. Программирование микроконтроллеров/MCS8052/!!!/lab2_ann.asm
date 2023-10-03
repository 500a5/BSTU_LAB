org 0h
	ljmp start

org 0Bh
	JMP TIMERONE

org 1Bh
	JMP TIMER
	
ORG 8100h

start:
	MOV A, TMOD					;3 ����� ������ 0 ������� (TL0-�������, TH0-������)
	ANL A, #0F0h
	ORL A, #00000111b 
	MOV TMOD, A	
	
	SETB TR1					;��������� ������
	SETB TR0					;��������� �������
	
	SETB IE.7
        SETB IE.3 
	SETB IE.1
	
	MOV TL0, #243
	
	MOV R1, #0					;� ��������� (0..100)
    MOV R4, #0                  ;� ��������� (1 - 100 .. 9 - 900)
	MOV R2, #0					;t1 ��������
	MOV R3, #100				;� ����������
    MOV R5, #1                  ;���� �������
	
    MOV DPTR, #3h
    MOV A, #82h
    MOVX @DPTR, A       ;����������� ����� �� 55
    
mloop:
	;������� �� �����
	mov DPTR, #2h           ;���� �

    ;mov A, 50h               ;1 �����     
	;ORL A, #00010000b
    ;movx @DPTR, A
	
	;mov A, 51h             ;2 �����   
	;ORL A, #00100000b
	;movx @DPTR, A
	
	mov A, 52h             ;3 �����   
	ORL A, #01000000b
    movx @DPTR, A

	mov A, 53h             ;4 �����     
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
	MOV A, #01100000b            ;��������� 1-� � 3-� �����������
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
	MOV A, #01010000b            ;��������� 1-� � 4-� �����������
	MOV P1, A
	
	;����� ��� ������
	;�����
	MOV B, #10
	MOV A, R1
	DIV AB
	MOV 50h, A
	MOV 51h, B
	
	;�������
	MOV B, #10
	MOV A, R0
	DIV AB
	MOV 52h, A
	MOV 53h, B
	
	MOV R0, #0

	JMP interval_END

rever:
    MOV R1, #100		         ;� ��������� (0..100)
    MOV R4, #9                   ;� ��������� (1 - 100 .. 9 - 900)
	MOV R2, #100				 ;t1 ��������
	MOV R3, #100			     ;� ����������

    JMP interval_END

ReTIMER:
    DEC R2
	MOV A, R2
	JNZ NOTOFF2
	MOV A, #01100000b            ;��������� 1-� � 3-� �����������
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
	MOV A, #10100000b            ;��������� 2-� � 3-� �����������
	MOV P1, A
	
	;����� ��� ������
	;�����
	MOV B, #10
	MOV A, R1
	DIV AB
	MOV 50h, A
	MOV 51h, B
	
	;�������
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
