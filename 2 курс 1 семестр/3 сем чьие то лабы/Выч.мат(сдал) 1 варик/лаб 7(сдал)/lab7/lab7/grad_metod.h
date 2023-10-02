#pragma once

#ifndef GRAD_METOD_H_
#define GRAD_METOD_H_
//целевая функция у = f (x1, х2)
double f_x1x2(double, double);
//градиент целевой функции grad (f (x1, х2))
void find_grad(double, double, double[]);
// Метод градиент с дроблением шага
int metod_grad_whith_drob(double *x1, double *x2, double exp, int n, double alf, double bet, double gam);
#endif
