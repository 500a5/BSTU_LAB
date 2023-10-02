#ifndef FIFOARRAY_H
#define FIFOARRAY_H
/*������ �������*/
const short FifoSize = 100;
/*�������� �������������� ��������*/
const int fifoOk = 0;									// ��� ���������
const int fifoFull = 1;								// ������� �����������
const int fifoEmpty = 2;								// ������� �����

/*���������� ������*/
extern short FifoError;
/*������� ��� �������*/
typedef int BaseType;

typedef struct
{
    BaseType buf[FifoSize];				// ����� �������
    int uk1;											// ��������� �� ����� (�� ���� ��������)
    int uk2;										// ��������� �� ������ (�� ���� ���������)
    int n;											// ���������� ��������� � �������
} Fifo;


void FifoInit (Fifo *F);								// ������������� �������
void FifoPut (Fifo *F, BaseType E);		// ��������� � �������
void FifoGet (Fifo *F, BaseType *E);		// ���������� �� �������
int FifoEmpty (Fifo *F);							// ��������: ����� �� �������
int FifoFull (Fifo *F);							// ��������: ����� �� �������

#endif
