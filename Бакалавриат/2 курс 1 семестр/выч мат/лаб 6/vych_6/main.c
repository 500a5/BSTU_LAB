#include <stdio.h>
#include "min_f.h"

int main() {
    double exp;
    double a, b;
    double znach;

    printf("Введите требуюмую точность решения E: ");
    scanf("%lf", &exp);

    printf("\nВведите левую границу промежутка унимодальности : ");
    scanf("%lf", &a);
    printf("\nВведите левую границу промежутка унимодальности : ");
    scanf("%lf", &b);

    printf("\nМинимальное значение функции на данном отрезке с заданной точностью\n");
    znach = optimal_find(exp, a, b);
    printf("\nМетодом оптимального поиска : %lf\n", znach);
    znach = cat_in_half(exp, a, b);
    printf("\nМетодом оптимального поиска : %lf\n", znach);
    znach = metod_fibanachi(exp, a, b);
    printf("\nМетодом оптимального поиска : %lf\n", znach);


    return 0;
}