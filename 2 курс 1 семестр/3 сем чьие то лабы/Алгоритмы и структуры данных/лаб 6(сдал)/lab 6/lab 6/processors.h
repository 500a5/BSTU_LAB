#pragma once

#ifndef PROCESSORS_H_
#define PROCESSORS_H_

#include "Structs.h"

void InitCPU(CPU *p);//������������� ����������
int isFreeCPU(CPU* p);//�������� �� ���������?
void putTaskCPU(CPU* p, TInquiry *task);//�������� ������ � ���������
int doCPU(CPU* p);//������ ����������
void getTaskCPU(CPU* p, TInquiry *task);//������� ������ �� ����������

#endif