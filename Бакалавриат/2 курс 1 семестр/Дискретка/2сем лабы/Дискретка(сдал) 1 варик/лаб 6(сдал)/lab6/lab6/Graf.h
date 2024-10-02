#pragma once
#include <stdio.h>
#include <stdlib.h>

void out(int *rez, int n);
int** grafRandom(int n, int m);
void grafZero(int **graf, int n);
void grafFree(int ** graf, int n);
void grafOut(int** graf, int n);
void grafFree(int ** graf, int n);
int isGrafConnect(int ** graf, int n);
int isGrafGamilton(int** graf, int n);
int findGamCikl(int** graf, int* a, int* log_v, int i, int n);
int isÑontVer(int** graf, int a, int b, int n);
int isGrafEil(int ** graf, int n, int m);