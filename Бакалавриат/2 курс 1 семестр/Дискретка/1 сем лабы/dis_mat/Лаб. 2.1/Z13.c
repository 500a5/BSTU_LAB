#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;
int k;
int s;

void set_init(int m[])
{
    for (int i = 0; i < n; i++)
        m[i] = i;
}

void output_set (int a[])
{
    int m = 0;
    for (int i = 0; i < k; i++)
        printf("%d ", a[i]);

    if (n == 0)
        printf("Пустое множество");
    puts("");
}

int resid(int m[], int n, int b[], int x)
{
    int len_b = 0;
    for (int i = 0; i < n; i++)
        if (m[i] != x)
        {
            b[len_b] = m[i];
            ++len_b;
        }
    return len_b;
}

void arrangement(int a[], int i, int m[], int t)
{
    for (int j = 0; j < t; j++)
    {
        a[i] = m[j];
        if (i == k - 1)
        {
            ++s;
            output_set(a);
        }else
        {
            int b[t - 1], len_b;
            len_b = resid(m, t, b, a[i]);
            arrangement(a, i+1, b, len_b);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    printf("Введите мощность множества: ");
    scanf("%d", &n);
    printf ("Введите колличество мест для размещения: ");
    scanf("%d", &k);
    int m[n];
    set_init(m);
    int a[k];
    int i = 0;
    int t = n;
    s = 0;
    arrangement(a, i, m, t);
    printf("Количество размещений: %d\n", s);
}
