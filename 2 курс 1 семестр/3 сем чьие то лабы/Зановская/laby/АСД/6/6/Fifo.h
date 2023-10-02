#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

/*������ �������*/
#define SIZE_QUEUE_ARRAY 3
/*�������� �������������� ��������*/
const int okQueueArray = 0;									// ��� ���������
const int fullQueueArray = 1;								// ������� �����������
const int emptyQueueArray = 2;								// ������� �����

/*���������� ������*/
extern int errorQueueArray;
/*������� ��� �������*/
typedef int queueArrayBaseType;
/*���������� �������*/
typedef struct {
queueArrayBaseType buf[SIZE_QUEUE_ARRAY];				// ����� �������
unsigned ukEnd;											// ��������� �� ����� (�� ���� ��������)
unsigned ukBegin;										// ��������� �� ������ (�� ���� ���������)
unsigned len;											// ���������� ��������� � �������
} QueueArray;

/*������� ������ � ��������*/
void initQueueArray(QueueArray *F);								// ������������� �������
void putQueueArray(QueueArray *F, queueArrayBaseType E);		// ��������� � �������
void getQueueArray(QueueArray *F, queueArrayBaseType *E);		// ���������� �� �������
int isFullQueueArray(QueueArray *F);							// ��������: ����� �� �������
int isEmptyQueueArray(QueueArray *F);							// ��������: ����� �� �������

#endif // FIFO_H_INCLUDED
