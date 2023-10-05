#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mod_matr.h"
#include "gauss.h"

void main()
{
    setlocale(LC_ALL,"Rus");
    int n, m, i=0, j=0, k, l, ch;
    float **a, **b, **s, **s2, **s3, **s4;

  /*  printf("m >> ");
    scanf("%d", &m);

    a = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) a[i]=(float*)calloc(m, sizeof(float));
    b = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) b[i]=(float*)calloc(m, sizeof(float));
    s = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) s[i]=(float*)calloc(m, sizeof(float));
    s2 = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) s2[i]=(float*)calloc(m, sizeof(float));
    s3 = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) s3[i]=(float*)calloc(m, sizeof(float));
    s4 = (float**)calloc(m, sizeof(float*));
    for (i=0; i<m; i++) s4[i]=(float*)calloc(m, sizeof(float));

    printf("Ввод A: \n");
    input_matr(a, m, m);

    printf("Ввод B: \n");
    input_matr(b, m, m);

    umn_matr (a, a, s, m); // A*A
    ch = summ(a, m, m, s, m, m, s3);
    umn_matr (b, a, s2, m);
    razn(s3, m, m, s2, m, m, s4);
    printf("Результат \n");

    output_matr(s4, m, m);*/



    printf("1 - определитель.\n");
    printf("2 - обратная матрица.\n");
    printf("3 - СЛАУ.\n");
    scanf("%d", &ch);

    if (ch==1)
    {
        printf("Размер матрицы: ");
        scanf("%d", &m);
        a = (float**)calloc(m, sizeof(float*));
        for (i=0; i<m; i++) a[i]=(float*)calloc(m, sizeof(float));
        printf("Введите матрицу: \n");
        input_matr(a, m, m);
        printf("\n");
        printf("Вы ввели: \n");
        output_matr(a, m, m);
        float det = gauss_det(a, m, m);
        printf("det A = %.2f", det);
    }

    if (ch==2)
    {
        printf("Размер матрицы: ");
        scanf("%d", &m);
        n=m+m;
        a = (float**)calloc(m, sizeof(float*));
        for (i=0; i<m; i++) a[i]=(float*)calloc(n, sizeof(float));
        printf("Введите матрицу: \n");
        input_matr(a, m, m);
        printf("\n");
        for (i=0;i<m;i++)
            for (j=m; j<n; j++)
            {
                if ((j-i)==m) a[i][j]=1;
                else a[i][j]=0;
            }
        printf("Вы ввели: \n");
        output_matr(a, m, n);
        printf("\n");
        printf("Обратная матрица: \n");
        ch = gauss_obrat(a, m, n);
    }

    if (ch==3)
    {
        int p;
        printf("Размер матрицы: ");
        scanf("%d", &m);
        printf("Правых столбцов: ");
        scanf("%d", &p);
        n=m+p;
        a = (float**)calloc(m, sizeof(float*));
        for (i=0; i<m; i++) a[i]=(float*)calloc(n, sizeof(float));
        printf("Введите матрицу+правые части уравнений: \n");
        input_matr(a, m, n);
        printf("Вы ввели: \n");
        output_matr(a, m, n);
        printf("\n");
        printf("Решение СЛАУ: \n");
        gauss_slau(a, m, n);
    }


    for (i=0;i<m;i++)free(a[i]);
    free(a);
    for (i=0;i<m;i++)free(b[i]);
    free(b);
    for (i=0;i<m;i++)free(s[i]);
    free(s);
    for (i=0;i<m;i++)free(s2[i]);
    free(s2);
    for (i=0;i<m;i++)free(s3[i]);
    free(s3);
    for (i=0;i<m;i++)free(s4[i]);
    free(s4);
}














