#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n;
int s;

void set_init(int m[])
{
    for (int i = 0; i < n; i++)
        m[i] = i + 1;
}

void output_set (int p[])
{
    int m = 0;
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    if (n == 0)
        printf("Пустое множество");
    puts("");
}

int resid(int m[], int n, int b[], int x)
{
    int len_b = 0;
    for (int i = 0; i < n; i++)
        if (m[i] != x){
            b[len_b] = m[i];
            ++len_b;
        }
    return len_b;
}

void permutation(int p[], int i, int m[], int t)
{
    for (int j = 0; j < t; j++){
        p[i] = m[j];
        if (i == n-1){
            ++s;
            output_set(p);
        }else{
            int b[t-1], len_b;
            len_b = resid(m, t, b, p[i]);
            permutation(p, i+1, b, len_b);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    printf("Введите мощность множества: ");
    scanf("%d", &n);
    int m[n];
    set_init(m);
    int p[n];
    int i = 0;
    int t = n;
    s = 0;
    permutation(p, i, m, t);
    printf("Количество перестановок: %d\n", s);
}
