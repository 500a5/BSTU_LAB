#pragma once

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "FIFO.h"
#include "Stack.h"
#include "processors.h"

//количество решаемых задач
#define COUNT_TASK 3 

//-------Глобальные переменные---------
extern Fifo fifo;
extern Stack stack;

extern CPU cpu1;
extern CPU cpu2;
extern CPU cpu3;

extern short CountFinishTask;//количество решённых задачы

//создание (ввод) задач
TInquiry* createTask(void);

//уничтожение задачи
void freeTask(TInquiry* task);

//генератор задач
void generatorTasks(void);

//распределитель задач
void distributorTasks(void);

//инициализация системы
void systemInit(void);

//работа системы (возвращает количество решённыз задач)
void doSystem(int teak);

//система закончила свою работу? (все задачи решены)
int isFinishSystem(void);

#endif