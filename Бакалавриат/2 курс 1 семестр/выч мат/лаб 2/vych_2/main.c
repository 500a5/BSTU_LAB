#include <stdio.h>
#include <stdlib.h>

void sort(float **a, size_t n)
{
    float *x = malloc((n+1)*sizeof(float*));
    for (int i = 0; i <= n; i++)
        for (int j = n; j > i; j--)
            if (a[j-1][0] > a[j][0])
            {
                x = a[j-1];
                a[j-1] = a[j];
                a[j] = x;
            }
}

int check(float **a, size_t n)
{
    int i = 2,f = 1;
    float x = a[1][0], h = a[1][0] - a[0][0];
    while (i <= n && f)
    {
        f = a[i][0] - x == h;
        x = a[i][0];
        i++;
    }
    return f;
}

float raz_razn(float **a, size_t n, float x)
{
    for (int i = 2; i < n + 2; i++)
        for (int j = 0; j < n - i + 2; j++)
            a[j][i] = (a[j+1][i-1] - a[j][i-1])/(a[j+i-1][0] - a[j][0]);
    double s = 0, p = 1, f = 1;
    for (int i = 1; i < n + 2; i++)
    {
        p = 1;
        for (int k = 0; k < i - 1; k++)
            p = p*(x-a[k][0]);
        s = s + a[0][i]*p;
    }
    return s;
}

int fact(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
        p = p * i;
    return p;
}

double kon_razn(float **a, size_t n, float x)
{
    for (int i = 2; i < n + 2; i++)
        for (int j = 0; j < n - i + 2; j++)
            a[j][i] = (a[j+1][i-1] - a[j][i-1]);
    float q = (x - a[0][0])/(a[1][0] - a[0][0]);
    double s = 0, p = 1;
    for (int i = 1; i < n + 2; i++)
    {
        p = 1;
        for (int k = 0; k < i - 1; k++)
            p = p*(q-k);
        s = s + a[0][i]/fact(i-1)*p;
    }
    return s;
}

void write_matr(float **a, size_t n)
{
    for (int i = 0; i <= n + 3 - i; i++)
    {
        for (int j = 0; j < n-i+2; j++)
            printf("%.2f\t",a[i][j]);
        printf("\n");
    }
}

int main()
{
    size_t n;
    scanf("%i",&n);
    float **a = malloc((n+1)*sizeof(float*));
    float x;
    double s;
    for (int i = 0; i <= n; i++)
    {
        a[i] = malloc((n+3)*sizeof(float));
        scanf("%f %f",&a[i][0],&a[i][1]);
    }
    scanf("%f",&x);
    sort(a,n);
    if (check(a,n))
        s = kon_razn(a,n,x);
    else
        s = raz_razn(a,n,x);
    write_matr(a,n);
    printf("I = %lf",s);
    for (int i = 0; i <= n; i++)
        free(a[i]);
    free(a);
}
