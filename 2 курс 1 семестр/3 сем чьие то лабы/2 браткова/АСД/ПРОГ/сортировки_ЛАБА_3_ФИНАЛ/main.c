#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#define N 45000

void input_mass (int A[], size_t nn);
void output_mass(int A[], size_t nn);
void vkl_sort(int A[],int nn);              //Сортировка включением
void vibor_sort(int A[],int nn);            //Сортировка выбором
void o_sort(int A[], int nn);               //Сортировка обменом
void BblSort_1(int* mas, int n);
void BblSort_2(int* A, int n);

void shell_sort(int A[], int nn);           //Сортировка шелла
void q_sort(int A[], int l, int r);         //Соритровка Хоара
void hoar_sort(int A[], int nn);
void sift(int A[], int l, int r);            //Сорировка Пирамиды
void heap_sort(int A[], int nn);

void time_obrupor (int nn);
void time_upor (int nn);
void time_neupor (int nn);

void obrat_vkl_sort(int A[],int nn);   // БРАТ

int main()
{
    setlocale(LC_ALL, "Rus");

    int a[N], b[N], c[N], d[N], e[N], f[N], g[N], k[N], i=0, t;
    for(i=0; i<N; i++)
    {
        a[i] = rand() % 100;
        b[i] = a[i];
        c[i] = b[i];
        d[i] = b[i];
        e[i] = b[i];
        f[i] = a[i];
        g[N] = a[i];
        k[N] = a[i];
    }

    obrat_vkl_sort(a, N);
    obrat_vkl_sort(b, N);
    obrat_vkl_sort(c, N);
    obrat_vkl_sort(d, N);
    obrat_vkl_sort(e, N);
    obrat_vkl_sort(f, N);
    obrat_vkl_sort(g, N);
    obrat_vkl_sort(k, N);

    clock_t time_start= clock();
    vkl_sort(a, N);
    clock_t time_end = clock() - time_start;
    printf("Включением %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    vibor_sort(b, N);
    time_end = clock() - time_start;
    printf("Выбором %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    o_sort(c, N);
    time_end = clock() - time_start;
    printf("Обменом %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    BblSort_1(g, N);
    time_end = clock() - time_start;
    printf("Обменом ул 1  %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    BblSort_2(k, N);
    time_end = clock() - time_start;
    printf("Обменом ул 2  %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    shell_sort(d, N);
    time_end = clock() - time_start;
    printf("Шелла %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    hoar_sort(e, N);
    time_end = clock() - time_start;
    printf("Хоара %f\n", (double)time_end / CLOCKS_PER_SEC);

    time_start= clock();
    heap_sort(f, N);
    time_end = clock() - time_start;
    printf("Пирамида %f\n", (double)time_end / CLOCKS_PER_SEC);

    return 0;
}

void input_mass (int A[], size_t nn)
{
    int i;
    for (i=0; i<nn; i++)
        scanf("%d", &A[i]);
}
void output_mass(int A[], size_t nn)
{
    int i;
    for (i=0; i<nn; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void vkl_sort(int A[],int nn)
//Сортировка включением
{
    int i, j, k;
    for (j=1; j<nn; j++)
        {
            k = A[j];
            i = j-1;
            while ((k<A[i]) && (i>=0))
                {
                    A[i+1] = A[i];
                    i -= 1;
                }
            A[i+1] = k;
        }
}

int vkl_o (int nn)
{
    return nn*nn;
}

void vibor_sort(int A[],int nn)
//Сортировка выбором
{
    int i, j, x, k;
    for (i=0; i<nn-1; i++)
        {
            x = A[i];
            k = i;
            for (j=i+1; j<nn; j++)
                if (A[j] < x)
                {
                    k = j;
                    x = A[k];
                }
    A[k] = A[i];
    A[i] = x;
        }
}

void o_sort(int A[], int nn)
//Сортировка обменом
{
    int i, j, tmp;
    for (i=0; i<nn-1; i++)
        {
            for (j=(nn-1); j>i; j--)
                {
                    if (A[j-1]>A[j])
                    {
                        tmp = A[j-1];
                        A[j-1] = A[j];
                        A[j] = tmp;
                    }
                }
        }
}

void BblSort_1(int* mas, int n)
/*улучшенная сортировка обменом №1*/
{
    int i,j,k,p;
    for(i=0;i<n-1;i++)
        {
            p=0;
            for(j=n-1;j>i;j--)
                if(mas[j]<mas[j-1])
                {
                    k=mas[j];
                    mas[j]=mas[j-1];
                    mas[j-1]=k;
                    p=1;
                }
                if(p==0)
                    break;
        }
}
void BblSort_2(int *A,int n) //сортировка обменом 2
{
    int i,j,k,p,kol=0;
    i=0;
    while (i<n)
    {
        p=n+1;
        for(j=n-1;j>i;j--)
        {
            if (A[j]<A[j-1])
                {
                    k=A[j];
                    A[j]=A[j-1];
                    A[j-1]=k;
                    p=j-1;
                    kol++;
                }
            kol++;
        }
        i=p;
    }
    //return kol;
}

void shell_sort(int A[], int nn)
{
    int i, j, step;
    int tmp;
    for (step=nn/2; step>0; step/=2)
        for (i=step; i<nn; i++)
        {
            tmp = A[i];
            for (j=i; j>=step; j-=step)
            {
                if (tmp < A[j-step])
                    A[j] = A[j-step];
                else
                    break;
            }
            A[j] = tmp;
        }
}

void q_sort(int A[], int l, int r)
{
    int x = A[l], i = l, j = r, t;
    while (i<=j)
        {
            while (A[i]<x)
                i++;
            while (A[j]>x)
                j--;
            if (i<=j)
                {
                    t = A[i];
                    A[i] = A[j];
                    A[j] = t;
                    i++;
                    j--;
                }
        }
        if (l<j)
            q_sort(A,l,j);
        if (i<r)
            q_sort(A,i,r);
}
void hoar_sort(int a[], int nn)
{
  q_sort(a, 0, nn-1);
}

void sift(int A[], int l,int r)
{
    int i, j, x, k;
    i = l;
    j = 2*r+1;
    x = A[l];
    if ((j<r) && (A[j]<A[j+1]))
        j++;
    while ((j<=r) && (x<A[j]))
    {
        k = A[i];
        A[i] = A[j];
        A[j]=k;
        i = j;
        j = 2*j+1;
        if ((j<r) && (A[j]<A[j+1]))
            j++;
    }
}

void heap_sort(int A[], int nn)
{
    int l, r, x, i;
    l = nn/2;
    r = nn-1;
    /*  Построение пирамиды из исходного массива */
	while (l>0)
        {
            l = l-1;
            sift(A, l, r);
        }
 /* Сортировка: пирамида => отсортированный массив */
	while (r>0)
        {
            x = A[0];
            A[0] = A[r];
            A[r] = x;
            r--;
            sift(A, l, r);
        }
}

void time_obrupor (int nn)
{
    printf("Обратно упорядоченные массивы\n");
    printf("Включением: %d\n", nn*nn);
    printf("Выбором: %d\n", nn*nn);
    printf("Обменом: %d\n", nn*nn);
    printf("Обменом 1, 2: %d\n", nn*nn);
    printf("Шелла: %d\n", nn*nn);
    printf("Хоара: %d\n", nn*nn);
    printf("Пирамидальная: %.2f\n", nn*log(nn));
}

void time_upor (int nn)
{
    printf("Обратно упорядоченные массивы\n");
    printf("Включением: %d\n", nn);
    printf("Выбором: %d\n", nn*nn);
    printf("Обменом: %d\n", nn*nn);
    printf("Обменом 1, 2: %d\n", nn);
    printf("Шелла: %.2f\n", nn*log(nn));
    printf("Хоара: %.2f\n", nn*log(nn));
    printf("Пирамидальная: %.2f\n", nn*log(nn));
}

void time_neupor (int nn)
{
    printf("Обратно упорядоченные массивы\n");
    printf("Включением: %d\n", nn*nn);
    printf("Выбором: %d\n", nn*nn);
    printf("Обменом: %d\n", nn*nn);
    printf("Обменом 1, 2: %d\n", nn*nn);
    printf("Шелла: %.2f\n", nn*(log(nn)*log(nn)));
    printf("Хоара: %.2f\n", nn*log(nn));
    printf("Пирамидальная: %.2f\n", nn*log(nn));
}

void obrat_vkl_sort(int A[],int nn)
//Сортировка включением
{
    int i, j, k;
    for (j=1; j<nn; j++)
        {
            k = A[j];
            i = j-1;
            while ((k>A[i]) && (i>=0))
                {
                    A[i+1] = A[i];
                    i -= 1;
                }
            A[i+1] = k;
        }
}
