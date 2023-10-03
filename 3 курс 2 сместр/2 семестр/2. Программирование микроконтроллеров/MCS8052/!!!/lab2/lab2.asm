org 0h
jmp main;
	
;��������� ������������ ����������. ����� ������� ������� � R4-����-���
scan:
	acall waitBisy
	mov R4,#1 			;����� scancode
	mov R7,#4 			;�������� �������� ������������
	mov R6,#11111110b 	;�������� ��������� ����� ������������
cycle:
	mov A,R6
	mov P1,A 			;����� �������� ����� ������������ 
	RL A             	;����� ����� ������������ 
	mov R6,A          	;���������� �������� ����� ������������ 
	mov A,P2           	;���� ����� �������� 
	mov R5,#5         	;�������� �������� ������� 
rotate:
	RRC A             	;����� ����� �������� 
	JNC asciiByScan		    ;����� �� ��������� ��� ����������� ������ ������� ������� 
	INC R4            	;��������� SCANCODE 
	DJNZ R5,rotate    	;��������� �������� ������� � ����, ���� �� ����
	DJNZ R7,cycle      	;��������� �������� ������������ � ����, ���� �� 0
	JMP SCAN          	;������ ������������ ������� 	
ret

;�����, ���� ������� ������
waitBisy:
	mov A,#0FFH 
	sleep  : 
		CJNE A,P2,sleep ;���� ������� ������, �� �����
ret

; ���������� ASCII �����
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

; ��������� ������-�����������
configUapp:
	setb SCON.7		; ������������� 3-�� ����� ������ 
	setb SCON.6 	; ������-�����������
	clr SCON.5		; ��������� 
	clr SCON.4		; �����
	setb SCON.3 	; ������������� ��������������� ������� ��� � �������.
	
	; ����������� ������
	orl TMOD,#00100000b ; ���. ���������� ���������,  ��������� ����� �������������
	mov SCON,#01100010b ; ������� � ������ ����� ������, ��������� �����..... 
	mov TH0, #0fdh      ; ��������� �������� 
	mov TL0, #0fdh		; �� 9600	
ret

; �������� ������ ������������ ��������������� ���
startTimer:
	setb TCON.6  
ret

; ���������� �������
stopTImer:
	clr TCON.6
ret

; �������� ������ �� ������� ������ 
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