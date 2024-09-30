#include "processors.h"
#include "stdlib.h"
#include "stdio.h"

#include "System.h"

//инициализация процессора
void InitCPU(CPU *p, TypeTask T) {
	p->flag = 1;
	p->T = T;
	p->task = NULL;
}

//свободен ли процессло? (1 - свободен, иначе 0 -  занят)
int isFreeCPU(CPU *p) {
	return p->flag;
}

//возвращает тип задачи, которую может решать процессор
TypeTask getTypeTaskCPU(CPU* p) {
	return p->T;
}

//положить задачу в процессор
void putTaskCPU(CPU* p, TInquiry *task) {
	p->task = task;
	p->flag = 0;
}

//делать вычисления 
int doCPU(CPU* p) {
	printf("CPU #%d: ", p->T);
	if (p->task == NULL) { //если процессор без задачи
		//простой
		printf("-------\n");
	} else {
		printf("%s (Type: %d, Time: %d)\n", p->task->Name, p->task->T, p->task->Time);
		p->task->Time--;
		//если задача решена, то освободить процессор
		if (p->task->Time <= 0) {
			p->flag = 1; // делаем процессор свободен
			freeTask(p->task);
			p->task = NULL; //удаляем задачу из процессора
			//printf("-------\n");
			return 1;
		}
	}
	return 0;
}