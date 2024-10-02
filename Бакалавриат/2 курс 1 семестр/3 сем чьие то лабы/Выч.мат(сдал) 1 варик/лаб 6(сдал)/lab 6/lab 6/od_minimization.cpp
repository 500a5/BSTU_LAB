#include "od_minimization.h";
#include "stdio.h"
#include "math.h"
double f_x(double x) {
	return ((x*x - 4)*(2*x*x - 3));
}
double optimal_find(double exp, double a, double b) {
	double min = f_x(a);
	double znach;
	for (double count = a + exp; count <= b; count = count + exp) {
		znach = f_x(count);
		if (znach < min)
			min = znach;
	}
	return min;
}
double cat_in_half(double exp, double a, double b) {
	double alf, bet;
	while ((b - a) < exp) {
		alf = ((a + b) / 2) - 0.001;
		bet = ((a + b) / 2) + 0.001;
		if (f_x(alf) >= f_x(bet))
			a = alf;
		else
			b = bet;
	}
	return f_x(((a + b) / 2));
}
double metod_fibanachi(double exp, double a, double b) {
	int fib[12] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };
	double alf, bet;
	int i = 0;
	while (((b - a) < exp) && (i <= 11)) {
		alf = a + (fib[(11 - i - 1)] * (b - a) / fib[(11 - i + 1)]);
		bet = a + (fib[(11 - i)] * (b - a) / fib[(11 - i + 1)]);
		if (f_x(alf) >= f_x(bet))
			a = alf;
		else
			b = bet;
		i++;
	}
	return f_x(((a + b) / 2));
}
