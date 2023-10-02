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
    printf("1 - ���� �� �����;\n2 - ���� � ����������;\n��� �����: ");
    // scanf("%d", &v);
    v=1;
    switch (v)
    {
    case 1:
    {
        //k4=k1  k5=k2  k6=k3 (����������� �����-�� ����������)

        //k8 - ����� �� ����� ������
        //K1 - OTRIC
        printf("\n������� ��� �����: ");
        char f_name [10]="K10.txt";
        //scanf("%s", &f_name);
        n=kol_zap_file(f_name);
        if (n<3)
        {
            printf("\n������������� �� ����� ���� ��������.");
            return 0;
        }
        t = (tochka*)calloc(n, sizeof(tochka));
        input_file(&t, n, f_name);
        printf("\n�� ����� ������� �����: ");
        output(t, n);
        printf("\n");
        break;
    }
    case 2:
    {
        printf("\n������� ���������� �����: ");
        scanf("%d", &n);
        if (n<3)
        {
            printf("\n������������� �� ����� ���� ��������.");
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
        printf("\n��� ����� ����� �� ����� ������.\n");
        printf("���������� ����������.\n");
        return 0;
    }

    float *ur = (float*)calloc(4, sizeof(float));
    ur = urav(t, nom, n); //������� ������������ ��������� ���������
    if (!check(t, n, ur))
    {
        printf("����� �� ����� � ����� ���������.\n");
        return 0;
    }
    //printf("��������� ���������: \n");    printf("%.2f, %.2f, %.2f, %.2f\n\n", ur[0], ur[1], ur[2], ur[3]);
    int or = orientation(ur, n);
    tochka_xy *p = (tochka_xy*)calloc(n, sizeof(tochka_xy));
    toch_new(or, t, p, n);
    //printf("\n����������� � ������������ �����: \n");
    int imin = x_min(p, n), imax = x_max(p, n);   // printf("(%.2f; %.2f) (%.2f; %.2f)\n\n", p[imin].xn, p[imin].yn, p[imax].xn, p[imax].yn);
    float *abc;
    abc = abc_xy(p[imin], p[imax]);
   // printf("��������� ������: \n");    printf("%.2f, %.2f, %.2f\n\n", abc[0], abc[1], abc[2]);
   // swap_t(0, imin, t); swap_xy(0, imin, p);
    sort_vst2(p, t, n, abc);
    //sortt(p, t, n, abc);
    printf("\n���������:");
    output(t, n);
    printf("\n���������:\n");
    output_xy(p, n);
    free(t);
//    free(p);
    return 0;
}
