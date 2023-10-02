#include "processors.h"
#include "stdlib.h"
#include "stdio.h"
#include "System.h"

//инициализация процессора
void InitCPU(CPU *p) {
	p->flag = 1;
	p->task = NULL;
}

//свободен ли процесcор? (1 - свободен, иначе 0 - занят)
int isFreeCPU(CPU *p) {
	return p->flag;
}

//положить задачу в процессор
void putTaskCPU(CPU* p, TInquiry *task) {
	p->task = task;
	p->flag = 0;
}

//достать задачу из процессора
void getTaskCPU(CPU* p, TInquiry *task) {
	task = p->task;
	p->flag = 0;
}

//делать вычисления
int doCPU(CPU* p) {
	printf("CPU: ");
	if (p->task == NULL) { //если процессор без задачи
	//простой
		printf("-------\n");
	}
	else {
		printf("%s (Priority: %c, Time: %d)\n", p->task->Name, p->task->P, p->task->Time);
		p->task->Time--;
		if (p->task->Time <= 0) { //если задача решена, то освободить процессор
			p->flag = 1; // устанавливаем процессор свободен
			//freeTask(p->task);
			p->task = NULL; //удаляем задачу из процессора
			//printf("-------\n");
			return 1;
		}
	}
	return 0;
}