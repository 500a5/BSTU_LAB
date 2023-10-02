#pragma once

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "FIFO.h"
#include "Stack.h"
#include "processors.h"

//���������� �������� �����
#define COUNT_TASK 3 

//-------���������� ����������---------
extern Fifo fifo;
extern Stack stack;

extern CPU cpu1;
extern CPU cpu2;
extern CPU cpu3;

extern short CountFinishTask;//���������� �������� ������

//�������� (����) �����
TInquiry* createTask(void);

//����������� ������
void freeTask(TInquiry* task);

//��������� �����
void generatorTasks(void);

//�������������� �����
void distributorTasks(void);

//������������� �������
void systemInit(void);

//������ ������� (���������� ���������� �������� �����)
void doSystem(int teak);

//������� ��������� ���� ������? (��� ������ ������)
int isFinishSystem(void);

#endif