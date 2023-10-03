 org 0h
 jmp start
 org 000Bh
 jmp timer
 org 8100h
 timer:
   setb RS0
   clr RS0
 reti
 showtimeorspeed: ; ����� ������� � �������� �� ���������
   mov A, R7
   rl A
   rl A
   mov R7, A
   cjne A, #00000001b, i1
   mov A, TL0
   mov B, #3
   mul AB
   mov B, #2
   div AB
   mov B, #10
   div AB
   orl A, #00010000b ; ������ ���������
   movx @DPTR, A
   ret
i1:cjne A, #00000100b, i2
   mov A, TL0
   mov B, #3
   mul AB
   mov B, #2
   div AB
   mov B, #10
   div AB
   mov A, B
   orl A, #00100000b ; ������ ���������
   movx @DPTR, A
   ret
i2:cjne A, #00010000b, i3
   mov A, R0
   mov B, #10
   div AB
   orl A, #01000000b ; ������ ���������
   movx @DPTR, A
   ret
i3:mov A, R0
   mov B, #10
   div AB
   mov A, B
   orl A, #10000000b ; �������� ���������
   movx @DPTR, A
 ret
 
 constlevel:
   mov P1, A
�1:
   mov R1, #128
�2:
   mov TL0, #0
   mov R2, #0
�3:
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   djnz R2, �3
   call showtimeorspeed
   djnz R1, �2
   djnz R0, �1
 ret
 ; �������� �������
 linelevel:
   mov R5, A
   mov R6, B
j1:
   mov R2, #128
j2:
   mov A, R1
   mov R3, A
   mov A, #0
   subb A, R1
   addc A, #1
   mov R4, A
   mov TL0, #0h
   mov P1, R5
j3:
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   djnz R3, j3 ; ����������� ������ ��������
   mov P1, R6
j4:
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   djnz R4, j4 ; ����������� ������ ��������
   call showtimeorspeed
   djnz R2, j2
   dec R1
   dec R1
   dec R1
   dec R1
   djnz R0, j1
 ret
start:
 setb EA
 setB IE.7
 setB IE.1
 mov DPTR, #3
 mov A, #82h
 movx @DPTR, A
 mov DPTR, #2
 mov A, TMOD
 anl A, #0F0h ; �� ������� ������ ������
 orl A, #05h
 mov TMOD, A ; ����� ������ ������� 0 - ������
 setb TR0 ; ��������� ������ 0
 mov R7, #1
 ; --- ������ ������ ---
 mov R0, #60 ;  ���������� ������
 mov A, #10100000b ; ������� ��������� � ���� �������
 call constlevel
 ; --- ������ ������ ---
 mov R0, #60 ; ����� ����������, � ��������
 mov R1, #0 ; ��������� �������� - ������������ (60 �������� � �������)
 mov A, #10100000b
 mov B, #10010000b
 call linelevel
 ; --- ������ ���� ---
 mov R0, #30  ; ������������ - 30 ������
 mov A, #11110000b   ; ������������� ���������
 call constlevel
 ; --- 4 ������ ---
 mov R0, #30 ; ����� ����������, � ��������
 mov R1, #0 ; ��������� �������� - �������
 mov A, #01100000b
 mov B, #01010000b
 call linelevel
 ; --- ����� ������ ---
 mov R0, #30
 mov R1, #128 ; ��������� �������� - 30 �������� � �������
 mov A, #01010000b
 mov B, #01100000b
 call linelevel
 mov P1, #0FFh ; ������������� ���������
 mov A, #00000000b
 movx @DPTR, A
 jmp $
end