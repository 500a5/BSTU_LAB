ORG 0h
	jmp main
t0ISR: 
        ORG 0Bh;��������� ��� ��������� ���������� ���������� ������� 0
        CLR TF0;������ �������� ����������� �������� ������� ������� ����� ����������
        MOV TH0,#0ECh;������ �������� ������������ �������
	MOV TL0,#078h
        ;�������� ���������� ������ ���������� �� ����� �0 � ��������� ������� ���������� �� ������ �1
        MOV R0,#1b;����� ���������� ��������� ������ �����
        L:
        MOV P0,R0;��������� � �������� � ����
        jb P0.0,stroca1;���� ��� ����� 1 �� ���������� ��������������� ������
        jb P0.1,stroca2
        jb P0.2,stroca3
        ;������ 4-� ������:
        jmp stroca4
        stroca1:
            JNB P1.0,CH1;������� ���� ��� ����� 0 (������� ������� ����� ��� �� �����)
	    Stolbik2:
            JNB P1.1,CH2
            Stolbik3:
	    JNB P1.2,CH3
            Stolbik4:
	    JNB P1.3,CHC
            Stolbik5:
	    JNB P1.4,CHD
            jmp netnacshatiy
            CH1:
	       MOV A,#31h
	       LCall Uart;������ ������������ �� ������ �������
               jmp Stolbik2;������������ ��� ����������� ������ ��������
            CH2:
	       MOV A,#32h
	       LCall Uart
               jmp Stolbik3
            CH3:
	       MOV A,#33h
	       LCall Uart
               jmp Stolbik4
            CHC:
	       MOV A,#43h
	       LCall Uart
               jmp Stolbik5
            CHD:
	       MOV A,#44h
	       LCall Uart
               jmp netnacshatiy
        stroca2:
            JNB P1.0,CH4;������� ���� ��� ����� 0 (������� ������� ����� ��� �� �����)
	    Stolbik22:
            JNB P1.1,CH5
            Stolbik32:
	    JNB P1.2,CH6
            Stolbik42:
	    JNB P1.3,CHE
            Stolbik52:
	    JNB P1.4,CHF
            jmp netnacshatiy
            CH4:
	       MOV A,#34h
	       LCall Uart;������ ������������ �� ������ ������� 4
               jmp Stolbik22;������������ ��� ����������� ������ �������� ���� ������
            CH5:
	       MOV A,#35h
	       LCall Uart
               jmp Stolbik32
            CH6:
	       MOV A,#36h
	       LCall Uart
               jmp Stolbik42
            CHE:
	       MOV A,#45h
	       LCall Uart
               jmp Stolbik52
            CHF:
	       MOV A,#46h
	       LCall Uart
               jmp netnacshatiy
        stroca3:
            JNB P1.0,CH7;������� ���� ��� ����� 0 (������� ������� ����� ��� �� �����)
	    Stolbik23:
            JNB P1.1,CH8
            Stolbik33:
	    JNB P1.2,CH9
            Stolbik43:
	    JNB P1.3,CHG
            Stolbik53:
	    JNB P1.4,CHH
            jmp netnacshatiy
            CH7:
	       MOV A,#37h
	       LCall Uart;������ ������������ �� ������ �������
               jmp Stolbik23;������������ ��� ����������� ������ ��������
            CH8:
	       MOV A,#38h
	       LCall Uart
               jmp Stolbik33
            CH9:
	       MOV A,#39h
	       LCall Uart
               jmp Stolbik43
            CHG:
	       MOV A,#47h
	       LCall Uart
               jmp Stolbik53
            CHH:
	       MOV A,#48h
	       LCall Uart
               jmp netnacshatiy
        stroca4:
            JNB P1.0,CHA;������� ���� ��� ����� 0 (������� ������� ����� ��� �� �����)
	    Stolbik24:
            JNB P1.1,CH0
            Stolbik34:
	    JNB P1.2,CHB
            Stolbik44:
	    JNB P1.3,CHI
            Stolbik54:
	    JNB P1.4,CHJ
            jmp netnacshatiy
            CHA:
	       MOV A,#41h
	       LCall Uart;������ ������������ �� ������ �������
               jmp Stolbik24;������������ ��� ����������� ������ ��������
            CH0:
	       MOV A,#30h
	       LCall Uart
               jmp Stolbik34
            CHB:
	       MOV A,#42h
	       LCall Uart
               jmp Stolbik44
            CHI:
	       MOV A,#49h
	       LCall Uart
               jmp Stolbik54
            CHJ:
	       MOV A,#4Ah
	       LCall Uart
        netnacshatiy:
        MOV A,R0;������ ����� ���� ����� � ������� ������������
        RL A
        MOV R0,A
        CJNE R0,#00010000b,LL;��������� �������� � ���������� � �������, ���� �� �����
        sjmp D
        LL: ljmp L;������� ��� ���� ����� ��������� � L
        D:
        MOV R0,#0b;���������� R0 � A � �������� ��������� ����� ���������� �� ������ �� �������� � �������� �� ������� ������
        MOV A,#0b
        RETI;����� �� ����������� ����������
Uart:	
	MOV SBUF,A;���������� � ���������������� ���� ������� �������
	;������� �� ����� ������
	MOV A,#13
	MOV SBUF,A
	MOV A,#10
	MOV SBUF,A
	RET
main:        
        ;T1 M1=1 M0=0 ����� � ������� �����
	;T0 M1=0 M0=1 ��� ������� ����������/16���
	MOV TMOD,#00100001b
	;�������� � ��������� 9600=(2^smod*Fosc)/(32*12*[256-TH])=31250/(256-TH)
	MOV TH1,#0FDh
        ;1-� ����� �������� (����������� 8 ��� � �����)
	SETB SM1
	CLR SM0
	;����� ���������� � �������� 200��(5��)
	MOV TH0,#0ECh;2^16-5000=60536=0EC78h
	MOV TL0,#78h
        ;��������� ���������� �� ������� 0
        SETB ET0
        ;��������� ���������� ����������
        SETB EA
        SETB TR0;��������� ������ 0
        jmp $;����������� ���� ��������
END
