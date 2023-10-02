#define _CRT_SECURE_NO_WARNINGS

#include "System.h"
#include "stdio.h"
#include "malloc.h"
#include "processors.h"

//-------Глобальные переменные---------
Fifo fifo;
Stack stack;

CPU cpu[3];

short CountFinishTask = 0; //количество решённых задачы

//вывод списка
void outputList(List *list) {
	TInquiry* tmp = NULL;
	ListPtrBegin(list);
	while (!ListEnd(list)) {
		tmp = (TInquiry*)ListRead(list);
		printf("%s (Type: %d, Time: %d)\n", tmp->Name, tmp->T, tmp->Time);
		ListMoveNext(list);
	}
}

 //создание (ввод) задач
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

//уничтожение задачи
void freeTask(TInquiry* task) {
	free(task);
}

//генератор задач
void generatorTasks(void) {
	int count = 0;// счётчик созданных задач
	TInquiry* tmp;
	while (count < COUNT_TASK) {
		tmp = createTask();//создаём задачу
		PutFifo(&fifo, tmp); //кладём её в очередь
		count++;
	}

}

//распределитель задач
void distributorTasks(void) {
	TInquiry* tmp = NULL;
	//пока очередь не пуста и мы не обработали все процессоры
	int count = 0;
	while (!EmptyFifo(&fifo) && (count < 3)) {
		tmp = (TInquiry*)GetFifo(&fifo);
		//ищим подходящий процессор
		for (int i = 0; i < 3; i++) {
			if (tmp->T == getTypeTaskCPU(&cpu[i])) // ищем процессор подходящего типа
				if (isFreeCPU(&cpu[i])) { //если он свободен
					putTaskCPU(&cpu[i], tmp);
					break;
				} else  // закидывам в стек ожидания
					PutStack(&stack, tmp);
		}
		count++;
	} 
	count = 0;
	//пока стек не пуст и мы не обработали все процессоры
	while (!EmptyStack(&stack) && (count < 3)) {
		tmp = (TInquiry*)GetStack(&stack);
		//ищим подходящий процессор
		for (int i = 0; i < 3; i++) {
			if (tmp->T == getTypeTaskCPU(&cpu[i])) // ищем процессор подходящего типа
				if (isFreeCPU(&cpu[i])) { //если он свободен
					putTaskCPU(&cpu[i], tmp);
					break;
				}
				else  // закидывам в стек ожидания
					PutStack(&stack, tmp);
		}
		count++;
	}

}

//инициализация системы
void systemInit(void) {
	InitStack(&stack);
	InitFifo(&fifo);

	for (int i = 0; i < 3; i++)
		InitCPU(&cpu[i], i + 1);

	generatorTasks(); //генерация задачи
}



//работа системы (возвращает количество решённыз задач)
void doSystem(int teak) {
	printf("----------Teak #%d------------\n", teak);
	//вывод очереди
	printf("Fifo:\n");
	outputList(&fifo);

	distributorTasks(); // распределние задач

	//вывод стека
	printf("Stack:\n");
	outputList(&stack);

	for (int i = 0; i < 3; i++)
		CountFinishTask += doCPU(&cpu[i]);
}

//система закончила свою работу? (все задачи решены)
int isFinishSystem(void) {
	return (CountFinishTask == COUNT_TASK) ? 1 : 0;
}	