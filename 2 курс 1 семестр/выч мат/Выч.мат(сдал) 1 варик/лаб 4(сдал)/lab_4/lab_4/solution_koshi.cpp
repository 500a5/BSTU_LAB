#include "mod_solution_koshi.h";

#include "stdio.h"
#include "math.h"

#define x_0 1
#define x_n 2
#define y_x0  3

double toch_znach(double x) {
	double znach = x*x*x*x - x*x + 2*x*x*x;
	return znach;
}
// y'
double y_sh(double x, double y) {
	double y_shtrih = x*x*x + x + 3*y/x;
	return y_shtrih;
}

//Решение задачи Коши методом Эйлера
double metod_eilera(double h, double exp) {
	double y_pred;// у_i-1
	double y = y_x0;//y_i 
	double x_pred = x_0, x = x_pred + h;//Предыдущий и настоящий x
	while (x <= (x_n)) {
		y_pred = y;
		y = y_pred + h * (y_sh(x_pred, y_pred));
		x_pred = x;
		x = x + h;
	}
	if ((toch_znach(x_n) - y) > exp) {
		double h_dop = h / 2;
		y = metod_eilera(h_dop, exp);
	}
	return y;
}

// Решение Задачи Коши методом Эйлера-Коши
double metod_eilera_koshi(double h, double exp) {
	double y_pred;// у_i                                                                                                                                                                                                                                                                                                                      
	double y = y_x0;//y_i 
	double x_pred = x_0, x = x_pred + h;//Предыдущий и настоящий x
	while (x <= (x_n)) {
		y_pred = y;
		y = y_pred + (h / 2) * (y_sh(x_pred, y_pred) + y_sh((x_pred + h), (y_pred + h * y_sh(x_pred, y_pred))));
		x_pred = x;
		x = x + h;
	}
	if ((toch_znach(x_n) - y) > exp) {
		double h_dop = h / 2;
		y = metod_eilera(h_dop, exp);
	}
	return y;
}

//Модифицированный метод Эйлера
double metod_eilera_mod(double h, double exp) {
	double y_pred;// у_i                                                                                                                                                                                                                                                                                                                      
	double y = y_x0;//y_i 
	double x_pred = x_0, x = x_pred + h;//Предыдущий и настоящий x
	while (x <= (x_n)) {
		y_pred = y;
		y = y_pred + h * y_sh((x_pred + h / 2), (y_pred + (h / 2) * y_sh(x_pred, y_pred)));
		x_pred = x;
		x = x + h;
	}
	if ((toch_znach(x_n) - y) > exp) {
		double h_dop = h / 2;
		y = metod_eilera(h_dop, exp);
	}
	return y;
}

//Метод Рунге Кутты
double metod_runge_kutti(double h, double exp) {
	double y_pred;// у_i                                                                                                                                                                                                                                                                                                                      
	double y = y_x0;//y_i 
	double x_pred = x_0, x = x_pred + h;//Предыдущий и настоящий x
	double k_1, k_2, k_3, k_4;
	while (x <= (x_n)) {
		y_pred = y;
		k_1 = y_sh(x_pred, y_pred);
		k_2 = y_sh((x_pred + h / 2), (y_pred + h / 2 * k_1));
		k_3 = y_sh((x_pred + h / 2), (y_pred + h / 2 * k_2));
		k_4 = y_sh(x, (y_pred + h * k_3));
		y = y_pred + h / 6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4);
		x_pred = x;
		x = x + h;
	}
	if ((toch_znach(x_n) - y) > exp) {
		double h_dop = h / 2;
		y = metod_eilera(h_dop, exp);
	}
	return y;
}
