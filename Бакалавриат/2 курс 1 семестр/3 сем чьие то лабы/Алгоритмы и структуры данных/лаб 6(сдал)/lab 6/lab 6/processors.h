#pragma once

#ifndef PROCESSORS_H_
#define PROCESSORS_H_

#include "Structs.h"

void InitCPU(CPU *p);//инициализация процессора
int isFreeCPU(CPU* p);//свободен ли процессло?
void putTaskCPU(CPU* p, TInquiry *task);//положить задачу в процессор
int doCPU(CPU* p);//делать вычисления
void getTaskCPU(CPU* p, TInquiry *task);//достать задачу из процессора

#endif