#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int** algKracksal(int** graf, int n, int centralTop);//�������� ��������
void recAlgKracksal(int **graf, int **tree, int n, int central, int *was);//��������� ������ �� ������� central(��������)
void arrZero(int* a, int n);//��������� ������� a ������� n
void arrMax(int* a, int n);//INT_MAX ������� a ������� n
int findCentralTop(int **graf, int n);//����� ����������� �������
int* eccentricity(int **graf, int n);//��������������� ������ �����
int distance(int **graf, int n, int v1, int v2);//����� ����������� ���� ����� ��������� v1 � v2
int recDistance(int **graf, int n, int *was, int v1, int v2, int min, int now);//�������� ��� ������ ���������� ����� ���������
int minIndex(int *a, int n);//������� ������� ����������� ��������
void matrFree(int **a, int n);//������������ ������
void arrOut(int *a, int n);//����� ������� a ������� n