#define _CRT_SECURE_NO_WARNINGS

#include "System.h"
#include "stdio.h"
#include "malloc.h"
#include "processors.h"

//-------���������� ����������---------
Fifo fifo;
Stack stack;

CPU cpu[3];

short CountFinishTask = 0; //���������� �������� ������

//����� ������
void outputList(List *list) {
	TInquiry* tmp = NULL;
	ListPtrBegin(list);
	while (!ListEnd(list)) {
		tmp = (TInquiry*)ListRead(list);
		printf("%s (Type: %d, Time: %d)\n", tmp->Name, tmp->T, tmp->Time);
		ListMoveNext(list);
	}
}

 //�������� (����) �����
TInquiry* createTask(void) {
	TInquiry* tmp = (TInquiry*)malloc(sizeof(TInquiry));
	printf("-------------------------\n");

	printf("Enter name of task: ");
	scanf("%s", tmp->Name);

	printf("Enter type of task (1,2,3): ");
	scanf("%d", &tmp->T);

	printf("Enter time for solution: ");
	scanf("%d", &tmp->Time);
	
	return tmp;
}

//����������� ������
void freeTask(TInquiry* task) {
	free(task);
}

//��������� �����
void generatorTasks(void) {
	int count = 0;// ������� ��������� �����
	TInquiry* tmp;
	while (count < COUNT_TASK) {
		tmp = createTask();//������ ������
		PutFifo(&fifo, tmp); //����� � � �������
		count++;
	}

}

//�������������� �����
void distributorTasks(void) {
	TInquiry* tmp = NULL;
	//���� ������� �� ����� � �� �� ���������� ��� ����������
	int count = 0;
	while (!EmptyFifo(&fifo) && (count < 3)) {
		tmp = (TInquiry*)GetFifo(&fifo);
		//���� ���������� ���������
		for (int i = 0; i < 3; i++) {
			if (tmp->T == getTypeTaskCPU(&cpu[i])) // ���� ��������� ����������� ����
				if (isFreeCPU(&cpu[i])) { //���� �� ��������
					putTaskCPU(&cpu[i], tmp);
					break;
				} else  // ��������� � ���� ��������
					PutStack(&stack, tmp);
		}
		count++;
	} 
	count = 0;
	//���� ���� �� ���� � �� �� ���������� ��� ����������
	while (!EmptyStack(&stack) && (count < 3)) {
		tmp = (TInquiry*)GetStack(&stack);
		//���� ���������� ���������
		for (int i = 0; i < 3; i++) {
			if (tmp->T == getTypeTaskCPU(&cpu[i])) // ���� ��������� ����������� ����
				if (isFreeCPU(&cpu[i])) { //���� �� ��������
					putTaskCPU(&cpu[i], tmp);
					break;
				}
				else  // ��������� � ���� ��������
					PutStack(&stack, tmp);
		}
		count++;
	}

}

//������������� �������
void systemInit(void) {
	InitStack(&stack);
	InitFifo(&fifo);

	for (int i = 0; i < 3; i++)
		InitCPU(&cpu[i], i + 1);

	generatorTasks(); //��������� ������
}



//������ ������� (���������� ���������� �������� �����)
void doSystem(int teak) {
	printf("----------Teak #%d------------\n", teak);
	//����� �������
	printf("Fifo:\n");
	outputList(&fifo);

	distributorTasks(); // ������������ �����

	//����� �����
	printf("Stack:\n");
	outputList(&stack);

	for (int i = 0; i < 3; i++)
		CountFinishTask += doCPU(&cpu[i]);
}

//������� ��������� ���� ������? (��� ������ ������)
int isFinishSystem(void) {
	return (CountFinishTask == COUNT_TASK) ? 1 : 0;
}	