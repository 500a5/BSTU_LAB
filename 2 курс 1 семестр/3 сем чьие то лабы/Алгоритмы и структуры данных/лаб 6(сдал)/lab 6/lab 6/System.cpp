#define _CRT_SECURE_NO_WARNINGS
#include "System.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "processors.h"
#include "Structs.h"
#include "Turn.h"


//-------���������� ����������---------
Fifo fifo0;
Fifo fifo1;
Fifo fifo2;
Stack *stack;
CPU cpu;
short CountFinishTask = 0; //���������� �������� �����
						   
//����� �������� � ������
void outputFifo() {
	
}

void outputStack() {

}

//�������� (����) �����
TInquiry* createTask(void) {
	TInquiry* tmp = (TInquiry*)malloc(sizeof(TInquiry));
	printf("------------------------------------\n");
	printf("Enter name of task: ");
	scanf("%s", tmp->Name);
	printf("Enter priority of task (0,1,2): ");
	scanf("%c", &tmp->P);
	printf("Enter time for solution: ");
	scanf("%d", &tmp->Time);
	return tmp;
}

//�������� ����� ������
TInquiry* createTaskRandom() {
	TInquiry* tmp = (TInquiry*)malloc(sizeof(TInquiry));
	printf("------------------------------------\n");
	printf("Enter name of task: ");
	scanf("%s", tmp->Name);
	tmp->P = CharINT(rand() % 3);
	printf("Priority of task: %c\n", tmp->P);
	tmp->Time = rand() % 10;
	printf("Enter time for solution: %d\n", tmp->Time);
	return tmp;
}

//������� �� ����� � ������(���������)
char CharINT(int a) {
	return '0' + a;
}

//����������� ������
void freeTask(TInquiry* task) {
	free(task);
}

//��������� �����
void generatorTasks(void) {
	int count = rand()%4;// ������� ��������� �����
	TInquiry* tmp;
	for (int i = count; i > 0; i--) {
		tmp = createTaskRandom();//������ ������
		switch (tmp->P) {
		case('0'):
			PutFifo(&fifo0, tmp); //����� � � �������
			break;
		case('1'):
			PutFifo(&fifo1, tmp); //����� � � �������
			break;
		case('2'):
			PutFifo(&fifo2, tmp); //����� � � �������
		}
		count++;
	}
}

//�������������� �����------------
void distributorTasks(void) {
	BaseType *E;
	TInquiry tmpStack;
	TInquiry *tmp;
	char priority = '4';
	
	if (!EmptyStack(stack) && isFreeCPU(&cpu)) {
		ReadStack(stack, &tmpStack);
		priority = tmpStack.P;
	}
	
	if (priority < '1' && isFreeCPU(&cpu)) {
		putTaskCPU(&cpu, &tmpStack);
		GetStack(stack, &tmpStack);
		return;
	}
	
	if (!EmptyFifo(&fifo0)) {
		if (cpu.flag) {
			GetFifo(&fifo0, &E);
			putTaskCPU(&cpu, (TInquiry*)E);
			return;
		}
		else {
			if (cpu.task->P != '0') {
				getTaskCPU(&cpu, &(*tmp));
				PutStack(stack, *tmp);
				GetFifo(&fifo0, &(*E));
				putTaskCPU(&cpu, (TInquiry*)E);
				return;
			}
		}
	}
	
	if (priority < '2' && isFreeCPU(&cpu)) {
		putTaskCPU(&cpu, &tmpStack);
		GetStack(stack, &tmpStack);
		return;
	}

	if (!EmptyFifo(&fifo1)) {
		if (cpu.flag) {
			GetFifo(&fifo0, &E);
			putTaskCPU(&cpu, (TInquiry*)E);
			return;
		}
		else {
			if (cpu.task->P > '2') {
				getTaskCPU(&cpu, &(*tmp));
				PutStack(stack, *tmp);
				GetFifo(&fifo0, &(*E));
				putTaskCPU(&cpu, (TInquiry*)E);
				return;
			}
		}
	}

	if (priority < '3' && isFreeCPU(&cpu)) {
		putTaskCPU(&cpu, &tmpStack);
		GetStack(stack, &tmpStack);
		return;
	}

	if (!EmptyFifo(&fifo2)) {
		if (cpu.flag) {
			GetFifo(&fifo0, &E);
			putTaskCPU(&cpu, (TInquiry*)E);
			return;
		}
		else {
			if (cpu.task->P > '3') {
				getTaskCPU(&cpu, &(*tmp));
				PutStack(stack, *tmp);
				GetFifo(&fifo0, &(*E));
				putTaskCPU(&cpu, (TInquiry*)E);
				return;
			}
		}
	}

}

//������������� �������
void systemInit(void) {
	InitStack(&stack);
	InitFifo(&fifo0, sizeof(TInquiry), 1000);
	InitFifo(&fifo1, sizeof(TInquiry), 1000);
	InitFifo(&fifo2, sizeof(TInquiry), 1000);
	InitCPU(&cpu);
}

//������ ������� (���������� ���������� �������� �����)
void doSystem(int teak) {
	printf("----------Teak #%d------------\n", teak);
	//����� �������
	printf("Fifo:\n");
	outputFifo();
	distributorTasks(); // ������������ �����
	//����� �����
	printf("Stack:\n");
	outputStack();
	CountFinishTask += doCPU(&cpu);
}

//������� ��������� ���� ������? (��� ������ ������)
int isFinishSystem(void) {
	return (CountFinishTask == COUNT_TASK) ? 1 : 0;
}

