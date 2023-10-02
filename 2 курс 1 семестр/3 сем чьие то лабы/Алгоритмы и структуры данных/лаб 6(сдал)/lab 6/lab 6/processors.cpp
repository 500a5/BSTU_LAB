#include "processors.h"
#include "stdlib.h"
#include "stdio.h"
#include "System.h"

//������������� ����������
void InitCPU(CPU *p) {
	p->flag = 1;
	p->task = NULL;
}

//�������� �� ������c��? (1 - ��������, ����� 0 - �����)
int isFreeCPU(CPU *p) {
	return p->flag;
}

//�������� ������ � ���������
void putTaskCPU(CPU* p, TInquiry *task) {
	p->task = task;
	p->flag = 0;
}

//������� ������ �� ����������
void getTaskCPU(CPU* p, TInquiry *task) {
	task = p->task;
	p->flag = 0;
}

//������ ����������
int doCPU(CPU* p) {
	printf("CPU: ");
	if (p->task == NULL) { //���� ��������� ��� ������
	//�������
		printf("-------\n");
	}
	else {
		printf("%s (Priority: %c, Time: %d)\n", p->task->Name, p->task->P, p->task->Time);
		p->task->Time--;
		if (p->task->Time <= 0) { //���� ������ ������, �� ���������� ���������
			p->flag = 1; // ������������� ��������� ��������
			//freeTask(p->task);
			p->task = NULL; //������� ������ �� ����������
			//printf("-------\n");
			return 1;
		}
	}
	return 0;
}