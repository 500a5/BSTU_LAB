ORG 0h
	jmp main

t1ISR:
        ORG 1Bh;��������� ��� ��������� ���������� ���������� ������� 1
        mov DPL,#70h ;�������� ��������� ������
        mov A, R0;��������
        movc A,@A+DPTR ;��������� � ����������� ����� �� ��
        MOV P1,A;��������� ����� ��������
        inc R0
        mov A, R0
        CJNE A,#14h,vihod1 ;��������� ������������ � ���������� � �������, ���� �� �����
        mov R0,#0h
        vihod1:
        RETI;����� �� ����������� ����������
SINUS: 
ORG 70h
           db 0h
           db 6h
           db 18h
           db 35h
           db 58h
           db 80h
           db 0A7h
           db 0CAh
           db 0E7h
           db 0F9h
           db 0FFh
           db 0F9h
           db 0E7h
           db 0CAh
           db 0A7h
           db 80h
           db 58h
           db 35h
           db 18h
           db 6h
ORG 100h
main:        
        ;T1 M1=1 M0=0 ��� ������������ ��������� 8 ���
	 ;T0 M1=0 M0=1 ��� �������� �������/16���
	 MOV TMOD,#00100001b
        mov TH1,#0F3h
       
        ;��������� ���������� �� ������� 1
        SETB ET1
        ;��������� ���������� ����������
        SETB EA
        CLR p0.7
        SETB TR1;��������� ������ 1
        jmp $;����������� ���� ��������
END
