#pragma once

#ifndef PROCESSORS_H_
#define PROCESSORS_H_

#include "Structs.h"

//инициализация процессора
void InitCPU(CPU *p, TypeTask T);

//свободен ли процессло?
int isFreeCPU(CPU* p);

//возвращает тип задачи, которую может решать процессор
TypeTask getTypeTaskCPU(CPU* p);

//положить задачу в процессор
void putTaskCPU(CPU* p, TInquiry *task);

//делать вычисления 
int doCPU(CPU *);

#endif
