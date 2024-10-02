#include "grad_metod.h";#include "pch.h"
#include "stdio.h"
#include "math.h"
#define N 2//целевая функция у = f (x1, х2)
double f_x1x2(double x1, double x2) {
	double znach = 2 * x1 * x1 * x1 * x1 + 4 * x2 * x2 * x2 * x2 - 3 * x1 * x2 + 2;
	return znach;
}
//градиент целевой функции grad (f (x1, х2)
void find_grad(double x1, double x2, double a[]) {
	a[0] = 8 * x1 * x1 * x1 - 3 * x2;
	a[1] = 16 * x2 * x2 * x2 - 3 * x1;
}
// Метод градиента с дроблением
int metod_grad_whith_drob(double *x1, double *x2, double exp, int n, double alf, double bet, double gam) {
	double x1_0 = *x1, x2_0 = *x2;
	double grad[N];
	double left, right;
	double f_0;
	int i;

	for (int j = 1; j <= n; j++) {
		i = 0;
		f_0 = f_x1x2(x1_0, x2_0);
		find_grad(x1_0, x2_0, grad);
		left = f_x1x2((x1_0 - alf * pow(gam, i) * grad[0]), (x2_0 - alf * pow(gam, i) * grad[1])) - f_0;
		right = (-1) * bet * alf * pow(gam, i) * (pow(grad[0], 2) + pow(grad[1], 2));

		while (left >= right) {
			i++;
			left = f_x1x2((x1_0 - alf * pow(gam, i) * grad[0]), (x2_0 - alf * pow(gam, i) * grad[1])) - f_0;
			right = (-bet) * alf * pow(gam, i) * (pow(grad[0], 2) + pow(grad[1], 2));
		}
		x1_0 = x1_0 - alf * pow(gam, i) * grad[0];
		x2_0 = x2_0 - alf * pow(gam, i) * grad[1];
		if ((fabs(f_0 - f_x1x2(x1_0, x2_0))) < exp) {
			*x1 = x1_0;
			*x2 = x2_0;
			return 1;
		}
	}

	return 0;
}
