#pragma once

#ifndef GRAD_METOD_H_
#define GRAD_METOD_H_
//������� ������� � = f (x1, �2)
double f_x1x2(double, double);
//�������� ������� ������� grad (f (x1, �2))
void find_grad(double, double, double[]);
// ����� �������� � ���������� ����
int metod_grad_whith_drob(double *x1, double *x2, double exp, int n, double alf, double bet, double gam);
#endif
