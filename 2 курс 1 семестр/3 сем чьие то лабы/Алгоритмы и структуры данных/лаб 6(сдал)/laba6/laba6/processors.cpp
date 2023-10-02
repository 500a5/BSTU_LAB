#include "processors.h"
#include "stdlib.h"
#include "stdio.h"

#include "System.h"

//������������� ����������
void InitCPU(CPU *p, TypeTask T) {
	p->flag = 1;
	p->T = T;
	p->task = NULL;
}

//�������� �� ���������? (1 - ��������, ����� 0 -  �����)
int isFreeCPU(CPU *p) {
	return p->flag;
}

//���������� ��� ������, ������� ����� ������ ���������
TypeTask getTypeTaskCPU(CPU* p) {
	return p->T;
}

//�������� ������ � ���������
void putTaskCPU(CPU* p, TInquiry *task) {
	p->task = task;
	p->flag = 0;
}

//������ ���������� 
int doCPU(CPU* p) {
	printf("CPU #%d: ", p->T);
	if (p->task == NULL) { //���� ��������� ��� ������
		//�������
		printf("-------\n");
	} else {
		printf("%s (Type: %d, Time: %d)\n", p->task->Name, p->task->T, p->task->Time);
		p->task->Time--;
		//���� ������ ������, �� ���������� ���������
		if (p->task->Time <= 0) {
			p->flag = 1; // ������ ��������� ��������
			freeTask(p->task);
			p->task = NULL; //������� ������ �� ����������
			//printf("-------\n");
			return 1;
		}
	}
	return 0;
}