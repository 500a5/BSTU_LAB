#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include "inout.h"

// ���������� ������ ������������� ��������� ��������� Ax+By+Cz+D;
float *urav (tochka *t, int nom, size_t n);

// ���������� 1, ���� ����� ����� � ����� ��������� � 0 � ��������� ������.
int check (tochka *t, size_t n, float *koeff);

int orientation (float *koeff, size_t n);

void toch_new (int or, tochka *t, tochka_xy *p, size_t n);

int x_min (tochka_xy *t, size_t n);

int x_max (tochka_xy *t, size_t n);

float* abc_xy(tochka_xy tmin, tochka_xy tmax);

void swap_xy(int i, int j, tochka_xy *tn);

void swap_t(int i, int j, tochka *tn);

int compare_xy(tochka_xy t1, tochka_xy t2, float *abc);

void sort_vst (tochka_xy *tn, tochka *pn, size_t n, float *abc);

void sortt (tochka_xy *pn, tochka *tn, size_t n, float *abc);

//���������� 1, ���� ����� ����� �� ����� ����� � 0 � ��������� ������ ������������.
int one_line_prostr (tochka *t, size_t n);

int one_line_prostr2 (tochka *t, size_t n);

int one_line_prostr3 (tochka *t, size_t n);

int one_line_prostr4 (tochka *t, size_t n);

int one_line_prostr5 (tochka *t, size_t n);

int one_line_prostr6 (tochka *t, size_t n);

#endif // POINT_H_INCLUDED
