org 0h
jmp begin
org 8060h
begin:
mov A,#82h
mov dptr,#3
movx @dptr,A
mov A,#40h
mov dptr,#0
movx @dptr,A
                     ;������ ��� �����������:
mov 30h,#0           ;����� � ����� B
mov R0,#0            ;�����  
mov R1,#0            ;������
mov R2,#0            ;�������� 
mov R3,#0            ;�����

loop:
clr p1.0
jb p1.1,$
mov dptr,#1
movx A,@dptr         ;������ ����� � ����� B
setb p1.0
                     ;���� ����� � ����� �:
cjne A,30h,loop6     ;��������, �� ����������� ��� � �������
jmp loop7            ;�� ��������, �� ����� �������
loop6:
mov 30h,A
call PROG1
call PROG2
loop7:
call VIVOD

jmp loop

PROG1:
jbc ACC.7,loop1      ;����������� �����
jnb ACC.7,loop2
loop1:               ;���� ���� �� R0=0
mov R0,#0
jmp loop3
loop2:               ;���� ����� �� R0=1
mov R0,#1
cjne A,#0,loop8
mov A,#128
jmp loop3
loop8:               ;���������� ��������� �����
cpl A
add A,#1
anl A,#127
loop3:               ;���������� ����� �� ���������
mov B,#10
div AB
mov R1,B             ;�������
mov B,#10
div AB
mov R2,B             ;�������
mov R3,A             ;�����
ret

PROG2:               ;��������� �� 4 ����� ��������� �� ���������
mov A,R1
mov B,#4
mul AB               ;��������� ������� �� 4
mov B,#10
div AB
mov R1,B
mov R4,A
mov A,R2
mov B,#4
mul AB               ;��������� �������� �� 4
add A,R4             ;����������� � �������� ��������
mov B,#10
div AB
mov R2,B
mov R4,A
mov A,R3
mov B,#4
mul AB               ;��������� ����� �� 4
add A,R4             ;����������� � ������ ��������
mov R3,A
ret

VIVOD:               ;����� ����� �� ���������
mov dptr,#2
cjne R0,#1,loop4
mov A,#00011100b
movx @dptr,A         ;����� �����
call DELAY
loop4:
mov A,R3
orl A,#00100000b
movx @dptr,A         ;����� �����
call DELAY
mov A,R2
orl A,#01000000b
movx @dptr,A         ;����� ��������
call DELAY
mov A,R1
orl A,#10000000b
movx @dptr,A         ;����� ������
call DELAY
ret

DELAY:               ;�������� ��� ������ �����
mov R7,#60
loop5:
movx @dptr,A
djnz R7,loop5
ret

end