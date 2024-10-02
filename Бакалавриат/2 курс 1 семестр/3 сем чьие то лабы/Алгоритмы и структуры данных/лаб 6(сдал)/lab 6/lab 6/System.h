#pragma once
#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "Turn.h"
#include "Stack.h"
#include "processors.h"
//количество решаемых задач
#define COUNT_TASK 5
//-------Глобальные переменные---------
extern Fifo f0;
extern Fifo f2;
extern Fifo f3;
extern Stack *stack;
extern CPU cpu1;
extern CPU cpu2;
extern CPU cpu3;
extern short CountFinishTask;//количество решённых задачы

void outputFifo();//вывод очереди
void outputStack();//вывод стека
TInquiry* createTask(void);//создание (ввод) задач
TInquiry* createTaskRandom();//создание задач рандом
char CharINT(int a);//перевод из числа в символ(единичное)
//void freeTask(TInquiry* task);//уничтожение задачи
void generatorTasks(void);//генератор задач
void distributorTasks(void);//распределитель задач
void systemInit(void);//инициализация системы
void doSystem(int teak);//работа системы (возвращает количество решённыз задач)
int isFinishSystem(void);//система закончила свою работу? (все задачи решены)
#endif