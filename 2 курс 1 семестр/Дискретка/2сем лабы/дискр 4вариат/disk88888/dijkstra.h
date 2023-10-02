#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
//��������� ���������� ������ �� ����� input.txt
int** ReadGraph(int *N);

//����� ����������� �����
void WriteGraph(int** G, int N);

//�������� ��������
void Dijkstra(int** G, int N, int start);

//����� ����������� ���� �� ������� start �� ������� vertex
void WritePath(int* T, int Start, int Vertex);

//������� ������ ��� ������� G
void FreeMem(int** G, int N);

#endif // DIJKSTRA_H_INCLUDED
