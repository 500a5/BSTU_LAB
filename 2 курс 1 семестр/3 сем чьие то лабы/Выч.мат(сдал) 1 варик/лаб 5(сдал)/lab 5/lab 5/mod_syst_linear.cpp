#include "mod_syst_linear.h";
#include "stdio.h"
#include "math.h"

// ������ ������� ��������� �������
double f1_xy(double x, double y) {
	double a = sin((x + 1)) - y - 0.5;
	return a;
}
// ������ ������� ��������� �������
double f2_xy(double x, double y) {
	double a = x * x + y * y - 1;
	return a;
}
// ������� ����������� ������ ������� �� �
double df1_dx(double x) {
	double znach = cos((x + 1));
	return znach;
}
// ������� ����������� ������ ������� �� �
double df1_dy(double y) {
	double znach = -1;
	return znach;
}
// ������� ����������� ������ ������� �� �
double df2_dx(double x) {
	double znach = 2 * x;
	return znach;
}

// ������� ����������� ������ ������� �� �2
double df2_dy(double y) {
	double znach = 2 * y;
	return znach;
}

int system_two_lin_equat(double *x, double *y, double exp, int n) {
	int count = 0;
	double zn_f1, zn_f2, f1_x, f1_y, f2_x, f2_y; // ���������� ��� �������� ��. ������� � ������� �����
	double h, l;// ���������� ��� �������� ������������ h, l

	while (count < n) {
		// ������������� ���������� ��� ���� ����������� ��������
		zn_f1 = f1_xy(*x, *y);
		zn_f2 = f2_xy(*x, *y);
		f1_x = df1_dx(*x);
		f1_y = df1_dy(*y);
		f2_x = df2_dx(*x);
		f2_y = df2_dy(*y);

		h = (f1_y * zn_f2 - zn_f1 * f2_y) / (f2_y * f1_x - f1_y * f2_x);
		l = (-1 * zn_f2 - f2_x * h) / (f2_y);


		*x = *x + h;
		*y = *y + l;

		count++;
		if (((fabs(f1_xy(*x, *y)) + fabs(f2_xy(*x, *y))) < exp))
			return 1;
	}
	return 0;
}
