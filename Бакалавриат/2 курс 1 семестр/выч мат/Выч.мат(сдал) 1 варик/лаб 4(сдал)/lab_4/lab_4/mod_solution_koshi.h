#pragma once

#ifndef MOD_SOLUTION_KOSHI_H_
#define MOD_SOLUTION_KOSHI_H_

#define x_0 1
#define x_n 2
#define y_x0  3

double metod_eilera(double, double);// Решение Задачи Коши методом Эйлера
double metod_eilera_koshi(double, double);// Решение Задачи Коши методом Эйлера-Коши
double metod_eilera_mod(double, double);// Решение Задачи Коши модифицированным методом Эйлера
double metod_runge_kutti(double, double);// Решение Задачи Коши методом Рунге-Кутты
double y_sh(double, double); // y' 
double toch_znach(double); // Точное значение

#endif