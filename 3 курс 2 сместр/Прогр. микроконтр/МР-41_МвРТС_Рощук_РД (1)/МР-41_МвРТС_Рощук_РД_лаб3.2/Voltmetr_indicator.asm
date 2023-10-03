ORG 0h
	jmp main
t0ISR: 
        ORG 0Bh;��������� ��� ��������� ���������� ���������� ������� 0
        CLR TF0;������ �������� ����������� �������� ������� ������� ����� ����������
        jmp T
        
        ORG 100h
        T:
        MOV TH0,#0D8h;������ �������� ������������ �������
	 MOV TL0,#0F0h
        MOV 50h, #19h;��������� ��������� �������� ��� (2500��)
        MOV 51h, #00h
        MOV R2, #80h;��������� ��������� �������� ��� (128)
        ;��� �������� ������ ���������
        MOV 56h, #19h
        MOV 57h, #00h
        MOV 58h, #00h;�������
        MOV 59h, #80h;���
        ;�������� ��� ������ �����������
        CLR TR1;������������� 1 ������
        CLR P0.7
Priblishenie:    
        ;����������� ��������� ������
        MOV 58h, #0h
        
        Mov B, #2h;��� ������
        Mov A,56h
        Div AB
        MOV 56h, A
        Mov A,B
        JZ Net_perenoca;�������, ���� ����������� ����� ����
        MOV 58h, #32h;50
 Net_perenoca:
        Mov B, #2h 
        Mov A,57h
        Div AB
        ADD A,58h
        MOV 57h, A
        
        Mov B, #2h;��� ���
        Mov A,59h
        Div AB
        MOV 59h, A
        
        ;������ �����������
        mov P1,R2
        JNB P3.7,umenhit;�������, ���� ��� ����� 0
        Mov A,51h
        ADD A,57h
        Mov B,#64h;��������� �� �������
        Div AB
        Mov 51h,B
        ADD A,50h
        ADD A,56h
        Mov 50h,A
        Mov A,R2
        ADD A,59h
        Mov R2,A
        sjmp dalee
     umenhit:
        Mov A,50h
        SUBB A,56h
        Mov 50h,A
        Mov A,51h
        ;��������� �� �������
        SUBB A,57h
        JNC BEZPER;�������, ���� ������� �� ����� �������
        Mov A,51h;���� ����� �������� ������
        ADD A,#64h
        SUBB A,57h
        Mov 51h,A
        Mov A,R2
        SUBB A,59h
        Mov R2,A
        Mov A,50h;�������� 1 �� �������� ��������
        SUBB A,#1h
        Mov 50h,A
        jmp dalee
     BEZPER: Mov A,51h
        SUBB A,57h
        Mov 51h,A
        Mov A,R2
        SUBB A,59h
        Mov R2,A
        dalee:   
        inc R7
        CJNE R7,#7h,Priblishenie ;���������  � ���������� � �������, ���� �� �����
        mov R7,#0h
        
        ;��������� �� �������
        mov A,50h
        mov B, #0Ah
        div AB
        mov 52h,A
        mov 53h,B
        mov A,51h
        mov B, #0Ah
        div AB
        mov 54h,A
        mov 55h,B
        
        MOV A,#00h;����� �� ������� ��������
        MOV B,#00h
        ;�������� ���������� ������ ���
        SETB TR1;��������� 1 ������
        SETB P0.7
        RETI;����� �� ����������� ����������
t1ISR:
        ORG 1Bh;��������� ��� ��������� ���������� ���������� ������� 1
        CLR TF1;������ �������� ����������� �������� ������� ������� ����� ����������
        ;������� �� ��������� 
        MOV P1,#0FFh;������� �����
        CJNE R0,#0h,D1;�������
        mov R1,52h;��������� ��������� �����
        SETB p3.3;����������� ���� �� 4 ����������� �� �����
        SETB p3.4
        D1:        
        CJNE R0,#1h,D2;�������
        mov R1,53h
        CLR p3.3
        SETB p3.4
        D2:        
        CJNE R0,#2h,D3;�����
        mov R1,54h
        SETB p3.3
        CLR p3.4
        D3:        
        CJNE R0,#3h,D4;��������
        mov R1,55h
        CLR p3.3
        CLR p3.4
        D4:        
        ;������� ������ �����
        mov DPL,#70h ;�������� ��������� ������
        mov A, R1;��������
        movc A,@A+DPTR ;��������� � ����������� ����� �� ��
        MOV P1,A;��������� ����� ��������

        CJNE R0,#0h,T1;����� ����� ������
        CLR P1.7
        T1:
        inc R0
        CJNE R0,#00000100b,NET;��������� �������� � ���������� � �������, ���� �� �����
        MOV R0,#0b
        NET:
        RETI;����� �� ����������� ����������
        ORG 70h
        db 11000000b
        db 11111001b
        db 10100100b
        db 10110000b
        db 10011001b
        db 10010010b
        db 10000010b
        db 11111000b
        db 10000000b
        db 10010000b
ORG 200h
main:        
        ;T1 M1=1 M0=0 ��� ������������ ��������� 8 ���
	;T0 M1=0 M0=1 ��� ���/16���
	MOV TMOD,#00100001b
	;���������� ������ 100��(10��)
	MOV TH0,#0FFh;2^16-10000=55536=0D8F0h
	MOV TL0,#099h
        ;��������� ���������� �� ������� 0
        SETB ET0
        ;��������� ���������� �� ������� 1
        SETB ET1
        ;��������� ���������� ����������
        SETB EA
        SETB TR0;��������� ������ 0
        SETB TR1;��������� ������ 1
        jmp $;����������� ���� ��������
END
        