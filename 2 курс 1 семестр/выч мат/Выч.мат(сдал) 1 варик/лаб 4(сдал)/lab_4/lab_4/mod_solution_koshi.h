#pragma once

#ifndef MOD_SOLUTION_KOSHI_H_
#define MOD_SOLUTION_KOSHI_H_

#define x_0 1
#define x_n 2
#define y_x0  3

double metod_eilera(double, double);// ������� ������ ���� ������� ������
double metod_eilera_koshi(double, double);// ������� ������ ���� ������� ������-����
double metod_eilera_mod(double, double);// ������� ������ ���� ���������������� ������� ������
double metod_runge_kutti(double, double);// ������� ������ ���� ������� �����-�����
double y_sh(double, double); // y' 
double toch_znach(double); // ������ ��������

#endif