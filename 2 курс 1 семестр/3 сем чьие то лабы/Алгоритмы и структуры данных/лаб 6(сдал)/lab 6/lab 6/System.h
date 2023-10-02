#pragma once
#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "Turn.h"
#include "Stack.h"
#include "processors.h"
//���������� �������� �����
#define COUNT_TASK 5
//-------���������� ����������---------
extern Fifo f0;
extern Fifo f2;
extern Fifo f3;
extern Stack *stack;
extern CPU cpu1;
extern CPU cpu2;
extern CPU cpu3;
extern short CountFinishTask;//���������� �������� ������

void outputFifo();//����� �������
void outputStack();//����� �����
TInquiry* createTask(void);//�������� (����) �����
TInquiry* createTaskRandom();//�������� ����� ������
char CharINT(int a);//������� �� ����� � ������(���������)
//void freeTask(TInquiry* task);//����������� ������
void generatorTasks(void);//��������� �����
void distributorTasks(void);//�������������� �����
void systemInit(void);//������������� �������
void doSystem(int teak);//������ ������� (���������� ���������� �������� �����)
int isFinishSystem(void);//������� ��������� ���� ������? (��� ������ ������)
#endif