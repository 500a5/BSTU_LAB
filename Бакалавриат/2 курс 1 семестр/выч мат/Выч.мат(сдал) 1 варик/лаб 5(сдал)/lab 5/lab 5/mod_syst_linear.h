#pragma once

#ifndef MOD_SYST_LINEAR_H_
#define MOD_SYST_LINEAR_H_

double f1_xy(double, double);// Первая функция уравнения системы

double f2_xy(double, double);// Вторая функция уравнения системы

double df1_dx(double);// Частная производная первой функции по х

double df1_dy(double);// Частная производная первой функции по у

double df2_dx(double);// Частная производная второй функции по х

double df2_dy(double);// Частная производная второй функции по у

int system_two_lin_equat(double *x, double *y, double exp, int n);

#endif