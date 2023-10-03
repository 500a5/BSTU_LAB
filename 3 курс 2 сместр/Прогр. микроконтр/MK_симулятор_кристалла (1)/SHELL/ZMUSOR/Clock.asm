ORG 0h
JMP BEGIN
ORG 000BH 
JMP TIME

ORG 8100H 
BEGIN:
MOV A, #82h    ; ��������� �����
MOV DPTR, #3
MOVX @DPTR, A
MOV DPTR, #2

SETB EA			;��������� ���������� �� �������
SETB ET0
MOV A,TMOD	;16-�� ��������� ������ �������
ORL A,#00000001B
MOV TMOD,A
MOV IP, #00010000B

MOV TH0, #4CH 	; ���������� ��������� � ������ ��� ������� �������
MOV TL0, #00h

MOV R1,0
MOV R5, #11	   	;����
MOV R6, #59	   	;������
MOV R7, #0		;�������
SETB TR0

PRINT:
;-------�����-----------
;��������� ����� ����� �� ������� � ������� �������� �� ������
;������� � �, ������� � �
MOV A, R5 		
MOV B, #10		;1� ���������
DIV AB
ADD A, #10h
MOVX @DPTR, A
MOV R3, #0
CALL DELAY

MOV A, B 		
ADD A, #20h		;2� ���������
MOVX @DPTR, A
MOV R3, #0
CALL DELAY


MOV A, #0
MOVX @DPTR, A
MOV R3, #0
CALL DELAY
;--------------------------------------------------------------------
mov B, #2 		;�������� ������� �� ��������. ���� ������, ������� ������
mov A, R7
DIV AB
MOV A, B
CJNE A , #0,  PRINT
;---------------------------------------------------------------------
;��������� ����� ����� �� ������� � ������� �������� �� ������
;������� � �, ������� � �
MOV A, R6 		
MOV B, #10
DIV AB
ADD A, #40h		;3� ���������
MOVX @DPTR, A
MOV R3, #0
CALL DELAY

MOV A, B 		
ADD A, #80h		;4� ���������
MOVX @DPTR, A
MOV R3, #0
CALL DELAY

MOV A, #0
MOVX @DPTR, A
MOV R3, #0
CALL DELAY
JMP PRINT
;---------���������� �� �������------
TIME:
MOV TH0, #4CH 
MOV TL0, #00h

INC R1
CJNE R1, #20, exit
MOV R1,0

INC R7 ;sec
CJNE R7, #60, exit
MOV R7, #0

INC R6 ; min
CJNE R6, #60, exit
MOV R6, #0

INC R5 ; hour
CJNE R5, #24, exit
MOV R5, #0
exit:
RETI
;----��������----------
DELAY:
NOP
INC R3
CJNE R3, #200, DELAY
RET
END