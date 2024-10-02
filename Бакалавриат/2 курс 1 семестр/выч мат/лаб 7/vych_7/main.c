#include <stdio.h>
#include "math.h"
#define N 2//целевая функция у = f (x1, х2)
double f_x1x2(double x1, double x2) {
    double znach = x1 * x1 +  x2 * x2 + 2 * x1 - 3 * x2 + 4;
    return znach;
}
//градиент целевой функции grad (f (x1, х2)
void find_grad(double x1, double x2, double a[]) {
    a[0] = 2 * x1 + 2;
    a[1] = 2 * x2 - 3;
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
}


    int main() {
        int n;
        double exp;
        double x1, x2;
        double znach;
        double alf, bet, gam;

        printf("Введите требуюмую точность решения E: ");
        scanf("%lf", &exp);

        printf("Введите начальное приближение M0(x1_0,x2_0) к точке локального минимума: ");
        scanf("%lf %lf", &x1, &x2);

        printf("\nВведите параметры метода градиента с дроблением шага alf, bet, gam: ");
        scanf("%lf %lf %lf", &alf, &bet, &gam);

        printf("\nВведите максимальное колличество итераций для проверки: ");
        scanf("%d", &n);


        if (metod_grad_whith_drob(&x1, &x2, exp, n, alf, bet, gam)) {
            znach = f_x1x2(x1, x2);
            printf("\nВычисление приближенного значения точки локального минимума и минимального значения целевой функции методом градиента с дроблением шага: Мт (%lf ; %lf) со значением в ней: y(Mт) = %lf\n\n", x1, x2, znach);
        }
        else
            printf("\nЗа данное количество операций задача решение с точностью E не найдено!");
        return 0;
    }

