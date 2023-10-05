#include <stdio.h>
#include "FifoArray.h"
/*���������� ������*/
int FifoError;
/*������������� �������*/
void FifoInit (Fifo *F)
{
    F->uk1 = 0;
    F->uk2 = 0;
    F->n = 0;
    FifoError = fifoOk;
}
/*��������� � �������*/
void FifoPut(Fifo *F, BaseType E)
{
/*���� ������� �����������*/
    if (FifoFull(F))
        return;

/*�����*/
    F->buf[F->uk2] = E;									// ��������� ��������
    F->uk2 = (F->uk2 + 1) % FifoSize;			// ����� ���������
    F->n++;												// ���������� ���������� ��������� �������
}
/*���������� �� �������*/
void FifoGet (Fifo *F, BaseType *E)
{
/*���� ������� �����*/
    if (FifoEmpty(F))
        return;
/*�����*/
    *E = F->buf[F->uk1];								// ������ �������� � ����������
    F->uk1 = (F->uk1 + 1) % FifoSize;		// ����� ���������
    F->n--;												// ���������� �����
}
/*��������: ����� �� �������*/
int FifoFull(Fifo *F)
{
    return (F->n == FifoSize);
}
/*��������: ����� �� �������*/
int FifoEmpty(Fifo *F)
{
    return (F->len == 0);
}
