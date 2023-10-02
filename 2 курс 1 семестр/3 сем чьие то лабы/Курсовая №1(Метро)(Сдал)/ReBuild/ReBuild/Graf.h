#pragma once
#define _CRT_SECURE_NO_WARNINGS //��� ���������� ������������� ������ �������
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define MAXSTRLN 40//������������ ������ ������

typedef struct {//��������� �������
	char name[MAXSTRLN];//��������
	int *connection; // int connection[2][���-�� ������� ����������];
	int c_connection = 0;//���-�� �������
	int *together;//������� ������
	int c_together;//���������� ������� ������
}station;

void input(station **a, int *n);//���� ������ ���������(������ � �����)
void inputManually(station *a, int n);//���� �������
void inputManuallyName(station *a, int n);//���� ������� �������� �������
void inputManuallyConnection(station *a, int n);//���� ������� ������ ����� ���������
void inputManuallyTogether(station *a, int n);//���� ������� ����� �������
void inputFile(station *a, int n, char *path1, char *path2, char *path3);//���� �� �����
void inputFileName(station *a, int n, char *path);//���� �� ����� �������� �������
void inputFileConnection(station *a, int n, char *path);//���� �� ����� ������ ����� ���������
void inputFileTogether(station *a, int n, char *path);//���� �� ����� ����� �������
void gets(char *str);//��������� ������ � �������
void output(station *a, int n, int *rez); //����� ����������
void out(station *a, int n, int *rez, int num);//�������� ����� ����������
void dijkstra_1(station *a, int n, int *rez);//���������� ���������� ���������
void dijkstra_2(station *a, int n, int *rez);
void dijkstra_3(station *a, int n, int *rez);//���������� ����� � ����(�������� ��������)
void nameStation(station *a, int n);//����� �������� �������
void freeMem(station *a, int *rez, int n);//������������ ������
int gorn(char *str);
void reorg(char *str);
void getPath(char *path, int *n, char *name, char *connection, char *together);