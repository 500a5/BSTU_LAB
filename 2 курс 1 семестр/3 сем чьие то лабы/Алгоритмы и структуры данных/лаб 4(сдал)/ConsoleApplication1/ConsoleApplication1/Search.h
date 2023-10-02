#pragma once

#ifndef __SEARCH_H_
#define __SEARCH_H_

#define MAX_SIZE_ARR 452

const short ORDERLY = 0; // упорядоченная 
const short DISORDERED = 1; // не упорядоченная

//переменная - счётчик сравнений
extern short countSravn;

// заполнение массива 
void initArr(int *arr, int n, short t);

//линейный поиск
int lineSearch(int *a, int n, int key);

//бысрый линейный поиск
int fastLineSearch(int *a, int n, int key);

//бинарный поиск
int binSearch(int *a, int n, int key);

//блочный поиск
int blockSearch(int *a, int n, int key);

//эксперимент
void experiment(void);


#endif
