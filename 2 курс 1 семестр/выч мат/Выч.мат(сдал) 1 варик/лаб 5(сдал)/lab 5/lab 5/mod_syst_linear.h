#pragma once

#ifndef MOD_SYST_LINEAR_H_
#define MOD_SYST_LINEAR_H_

double f1_xy(double, double);// ������ ������� ��������� �������

double f2_xy(double, double);// ������ ������� ��������� �������

double df1_dx(double);// ������� ����������� ������ ������� �� �

double df1_dy(double);// ������� ����������� ������ ������� �� �

double df2_dx(double);// ������� ����������� ������ ������� �� �

double df2_dy(double);// ������� ����������� ������ ������� �� �

int system_two_lin_equat(double *x, double *y, double exp, int n);

#endif