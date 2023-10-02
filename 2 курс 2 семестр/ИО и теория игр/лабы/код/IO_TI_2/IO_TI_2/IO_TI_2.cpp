#include <iostream>
#include "Fraction.h"
#include <stdio.h>
#include <windows.h>

Fraction** readMatr(int m, int n)
{
    Fraction** matr = (Fraction**)calloc(m, sizeof(Fraction*));
    std::cout << "введите расширенную матрицу:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        matr[i] = (Fraction*)calloc(n + 1, sizeof(Fraction));
        for (int j = 0; j <= n; j++)
            std::cin >> matr[i][j];
    }
    return matr;
}

Fraction* readFun(int n)
{
    std::cout << "введите коэффициенты целевой функции:" << std::endl;
    Fraction* z = (Fraction*)calloc(n + 1, sizeof(Fraction));
    for (int i = 0; i <= n; i++)
        std::cin >> z[i];
    return z;
}

void writeTabl(Fraction** matr, int m, int n)
{
    std::cout << "БП\t СЧ\t ";
    for (int i = 1; i < n; i++)
        std::cout << "x[" << i << "]\t ";
    std::cout << std::endl;
    for (int i = 0; i <= m; i++)
    {
        if (i == m)
            std::cout << "Z\t";
        else
            std::cout << "x[" << matr[i][0].numerator << "]\t";
        for (int j = 1; j <= n; j++)
        {
            if (matr[i][j] >= 0)
                std::cout << " ";
            std::cout << matr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int checkStringNull(Fraction* a, int n)
{
    for (int i = 1; i < n; i++)
        if (a[i] == 0)
            return 0;
    return 1;
}

int checkOptimalPlan(Fraction** a, int m, int n)
{
    for (int i = 0; i < m; i++)
        if (a[i][n] < 0)
            return 0;
    return 1;
}

int checkBasis(Fraction** a, int m, int n, int* vec)
{
    int k = 0;
    Fraction s;
    for (int j = 0; j < n; j++)
    {
        s = 0;
        for (int i = 0; i < m && s < 2; i++)
        {
            if (a[i][j] == 0 || a[i][j] == 1 && vec[j] == 0)
            {
                if (a[i][j] == 1)
                    vec[j] = i + 2;
                s = s + a[i][j];
            }
            else
                s = 2;
        }
        if (s == 1)
            k++;
        else
            vec[j] = 0;
    }
    return (k == m);
}

Fraction** searchBasis(Fraction** a, int* m, int n, int* vec)
{
    if (!checkBasis(a, *m, n, vec))
    {
        for (int i = 0; i < n; i++)
            vec[i] = 0;
        for (int k = 0, jm = 0; k < *m; k++)
            if ((a[k][jm]) != 0)
            {
                vec[jm] = 1;
                for (int i = n; i >= k; i--)
                    a[k][i] = a[k][i] / a[k][jm];
                for (int i = 0; i < *m; i++)
                    if (i != k)
                        for (int j = n; j >= k; j--)
                            a[i][j] = a[i][j] - a[k][j] * (a[i][jm] / a[k][jm]);
                jm++;
            }
            else
                if (!checkStringNull(a[k], n))
                {
                    for (int i = 0; i < n; i++)
                        a[k][i] = a[*m - 1][i];
                    (*m)--;
                }
        int l = 0, t = 0, k = 0;
        while (!checkOptimalPlan(a, *m, n) && k < 1 << n)
        {
            l = 0;
            for (int i = 0, im = 0, temp = k; i < n; i++, l += temp % 2, temp /= 2)
                vec[i] = temp % 2;
            if (l == *m)
            {
                int f = 1;
                for (int i = 0, im = 0; f && i < n, im < *m; i++)
                    if (vec[i])
                    {
                        if (a[im][i] == 0)
                        {
                            f = 0;
                            break;
                        }
                        if (a[im][i] != 1)
                        {
                            Fraction koef = a[im][i];
                            for (int j = 0; j <= n; j++)
                                a[im][j] = a[im][j] / koef;
                        }
                        for (int j = 0; j < *m; j++)
                            if (j != im)
                            {
                                Fraction koef = a[j][i] / a[im][i];
                                for (int t = 0; t <= n; t++)
                                    a[j][t] = a[j][t] - a[im][t] * koef;
                            }
                        im++;
                    }
            }
            k++;
        }
    }
    return a;
}

Fraction** toFirstTable(Fraction** a, int* m, int n, Fraction* z)
{
    int* vec = (int*)calloc(n, sizeof(int));
    Fraction** b = searchBasis(a, m, n - 1, vec);
    Fraction** tabl = (Fraction**)calloc(*m + 1, sizeof(Fraction*));
    for (int i = 0; i < *m; i++)
    {
        tabl[i] = (Fraction*)calloc(n + 1, sizeof(Fraction));
        for (int j = 0; j < n - 1; j++)
            tabl[i][j + 2] = b[i][j];
        tabl[i][1] = b[i][n - 1];
    }
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (vec[i])
        {
            if (vec[i] > 1)
                tabl[vec[i] - 2][0] = i + 1;
            else
                tabl[k++][0] = i + 1;
        }
    }
    tabl[*m] = (Fraction*)calloc(n + 1, sizeof(Fraction));
    for (int i = 2; i <= n; i++)
        tabl[*m][i] = -z[i - 2];
    tabl[*m][1] = z[n - 1];

    for (int i = 0; i < *m; i++)
    {
        int x = tabl[i][0].numerator;
        Fraction koef = tabl[*m][x + 1];
        if (koef != 0)
            for (int j = 1; j <= n; j++)
                tabl[*m][j] = tabl[*m][j] - tabl[i][j] * koef;
    }

    return tabl;
}

int searchMin(Fraction* a, int n)
{
    Fraction m = a[2];
    int im = 2;
    for (int i = 3; i <= n; i++)
        if (a[i] < m)
        {
            m = a[i];
            im = i;
        }
    return im;
}

int searchGen(Fraction** a, int m, int jm)
{
    Fraction min;
    Fraction temp;
    int im = 0;
    for (int i = 0; i < m; i++)
        if (a[i][jm] > 0)
        {
            if (min == 0)
            {
                min = a[i][1] / a[i][jm];
                im = i;
            }
            temp = a[i][1] / a[i][jm];
            if (temp < min)
            {
                min = temp;
                im = i;
            }
        }
    return im;
}

Fraction** toEndTable(Fraction** a, int m, int n)
{
    int jm, im;
    Fraction z = a[m][1];
    while (a[m][(jm = searchMin(a[m], n))] < 0 && a[m][1] >= z)
    {
        z = a[m][1];
        im = searchGen(a, m, jm);
        if (a[im][jm] <= 0)
        {
            std::cout << "Решений нет";
            return NULL;
        }
        a[im][0] = jm - 1;
        Fraction koef = a[im][jm];
        for (int i = 1; i <= n; i++)
            a[im][i] = a[im][i] / koef;
        for (int i = 0; i <= m; i++)
            if (i != im)
            {
                koef = a[i][jm];
                for (int j = 1; j <= n; j++)
                    a[i][j] = a[i][j] - a[im][j] * koef;
            }
        writeTabl(a, m, n);
    }
    return a;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, n;
    printf("введите количество уравнений : ");
   scanf("%i", &m);
   printf("введите количество переменных : ");
   scanf("%i", &n);
    Fraction** a = readMatr(m, n);
    Fraction* z = readFun(n);
    n++;
    Fraction** b = toFirstTable(a, &m, n, z);
    std::cout << "\nПервая Симплекс таблица: \n";
    writeTabl(b, m, n);
    std::cout << "\n";
    Fraction** c = toEndTable(b, m, n);
    if (c)
    {
        writeTabl(c, m, n);
        std::cout << "\n\nZmax = " << c[m][1] << std::endl;
        std::cout << "В точке (";
        Fraction* maxPoint = (Fraction*)calloc(n, sizeof(Fraction));
        for (int i = 0; i < m; i++)
        {
            maxPoint[c[i][0].numerator - 1] = c[i][1];
        }
        for (int i = 0; i < n - 2; i++)
        {
            maxPoint[i].printFrac();
            std::cout << "; ";
        }
        maxPoint[n - 2].printFrac();
        std::cout << ")\n";
    }
    system("pause");
}
