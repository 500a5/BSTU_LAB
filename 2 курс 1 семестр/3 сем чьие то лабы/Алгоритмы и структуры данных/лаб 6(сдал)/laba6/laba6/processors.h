#pragma once

#ifndef PROCESSORS_H_
#define PROCESSORS_H_

#include "Structs.h"

//������������� ����������
void InitCPU(CPU *p, TypeTask T);

//�������� �� ���������?
int isFreeCPU(CPU* p);

//���������� ��� ������, ������� ����� ������ ���������
TypeTask getTypeTaskCPU(CPU* p);

//�������� ������ � ���������
void putTaskCPU(CPU* p, TInquiry *task);

//������ ���������� 
int doCPU(CPU *);

#endif
