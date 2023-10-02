#pragma once
#define _CRT_SECURE_NO_WARNINGS //для разрешения использования старых функций
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

#define MAXSTRLN 40//максимальная длинна строки

typedef struct {//структура станции
	char name[MAXSTRLN];//название
	int *connection; // int connection[2][кол-во станций соединения];
	int c_connection = 0;//кол-во станций
	int *together;//станции вместе
	int c_together;//количество станций вместе
}station;

void input(station **a, int *n);//ввод списка смежности(данных о метро)
void inputManually(station *a, int n);//ввод вручную
void inputManuallyName(station *a, int n);//ввод вручную названий станций
void inputManuallyConnection(station *a, int n);//ввод вручную связей между станциями
void inputManuallyTogether(station *a, int n);//ввод вручную общих станций
void inputFile(station *a, int n, char *path1, char *path2, char *path3);//ввод из файла
void inputFileName(station *a, int n, char *path);//ввод из файла названий станций
void inputFileConnection(station *a, int n, char *path);//ввод из файла связей между станциями
void inputFileTogether(station *a, int n, char *path);//ввод из файла общих станций
void gets(char *str);//считывает строку с консоли
void output(station *a, int n, int *rez); //вывод результата
void out(station *a, int n, int *rez, int num);//рекурсия вывод результата
void dijkstra_1(station *a, int n, int *rez);//Наименьшее количество пересадок
void dijkstra_2(station *a, int n, int *rez);
void dijkstra_3(station *a, int n, int *rez);//наименьшее время в пути(алгоритм Дейкстры)
void nameStation(station *a, int n);//вывод названия станции
void freeMem(station *a, int *rez, int n);//освобождение памяти
int gorn(char *str);
void reorg(char *str);
void getPath(char *path, int *n, char *name, char *connection, char *together);