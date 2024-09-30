#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "inout.h"
#include "point.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    int v, n, i;
    tochka *t;
    printf("1 - Ввод из файла;\n2 - Ввод с клавиатуры;\nВаш выбор: ");
    // scanf("%d", &v);
    v=1;
    switch (v)
    {
    case 1:
    {
        //k4=k1  k5=k2  k6=k3 (параллельны какой-то плоскостит)

        //k8 - лежат на одной прямой
        //K1 - OTRIC
        printf("\nВведите имя файла: ");
        char f_name [10]="K10.txt";
        //scanf("%s", &f_name);
        n=kol_zap_file(f_name);
        if (n<3)
        {
            printf("\nМногоугольник не может быть построен.");
            return 0;
        }
        t = (tochka*)calloc(n, sizeof(tochka));
        input_file(&t, n, f_name);
        printf("\nИз файла считаны точки: ");
        output(t, n);
        printf("\n");
        break;
    }
    case 2:
    {
        printf("\nВведите количество точек: ");
        scanf("%d", &n);
        if (n<3)
        {
            printf("\nМногоугольник не может быть построен.");
            return 0;
        }
        t = (tochka*)calloc(n, sizeof(tochka));
        input(t, n);
        printf("\n");
        break;
    }
    default:
        return 0;
    }
    int nom3 = one_line_prostr3(t,n);
    int nom4 = one_line_prostr4(t,n);
    int nom5 = one_line_prostr5(t,n);
    int nom = one_line_prostr(t, n);
    int nom2 = one_line_prostr2(t, n);
    int nom6 = one_line_prostr6(t, n);


    printf("\n!!nom %d\n!!nom2 %d\nnom3 %d\n!!nom4 %d\nnom5 %d\n!!nom6 %d\n", nom, nom2, nom3, nom4, nom5, nom6);
    if (nom==-1)
    {
        printf("\nВсе точки лежат на одной прямой.\n");
        printf("Построение невозможно.\n");
        return 0;
    }

    float *ur = (float*)calloc(4, sizeof(float));
    ur = urav(t, nom, n); //находим коэффициенты уравнения плоскости
    if (!check(t, n, ur))
    {
        printf("Точки не лежат в одной плоскости.\n");
        return 0;
    }
    //printf("Уравнение плоскости: \n");    printf("%.2f, %.2f, %.2f, %.2f\n\n", ur[0], ur[1], ur[2], ur[3]);
    int or = orientation(ur, n);
    tochka_xy *p = (tochka_xy*)calloc(n, sizeof(tochka_xy));
    toch_new(or, t, p, n);
    //printf("\nМинимальная и максимальная точки: \n");
    int imin = x_min(p, n), imax = x_max(p, n);   // printf("(%.2f; %.2f) (%.2f; %.2f)\n\n", p[imin].xn, p[imin].yn, p[imax].xn, p[imax].yn);
    float *abc;
    abc = abc_xy(p[imin], p[imax]);
   // printf("Уравнение прямой: \n");    printf("%.2f, %.2f, %.2f\n\n", abc[0], abc[1], abc[2]);
   // swap_t(0, imin, t); swap_xy(0, imin, p);
    sort_vst2(p, t, n, abc);
    //sortt(p, t, n, abc);
    printf("\nРезультат:");
    output(t, n);
    printf("\nРезультат:\n");
    output_xy(p, n);
    free(t);
//    free(p);
    return 0;
}
