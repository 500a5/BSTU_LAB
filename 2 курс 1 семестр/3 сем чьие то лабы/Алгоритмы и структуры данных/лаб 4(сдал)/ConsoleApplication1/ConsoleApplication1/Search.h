#pragma once

#ifndef __SEARCH_H_
#define __SEARCH_H_

#define MAX_SIZE_ARR 452

const short ORDERLY = 0; // ������������� 
const short DISORDERED = 1; // �� �������������

//���������� - ������� ���������
extern short countSravn;

// ���������� ������� 
void initArr(int *arr, int n, short t);

//�������� �����
int lineSearch(int *a, int n, int key);

//������ �������� �����
int fastLineSearch(int *a, int n, int key);

//�������� �����
int binSearch(int *a, int n, int key);

//������� �����
int blockSearch(int *a, int n, int key);

//�����������
void experiment(void);


#endif
