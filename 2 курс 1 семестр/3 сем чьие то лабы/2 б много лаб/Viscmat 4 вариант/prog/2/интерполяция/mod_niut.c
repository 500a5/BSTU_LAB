#include <stdio.h>
#include <stdlib.h>
#include "mod_niut.h"
#include <math.h>

void output_mass (float* b, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%.2f ", b[i]);
    }
}

long fact(long a)
{
  if(a==0 || a==1)
     return 1;
  else
     return a*fact(a-1);
}

void output (tochka* t, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        {
            printf("%d >> %+lf | %+lf |\n", i, t[i].x, t[i].y);
        }
}

void input (tochka* a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        {
            scanf("%f", &a[i].x);
            scanf("%f", &a[i].y);
            printf("\n");
        }
}

int checc (tochka* a, size_t n)
{
    int i, f=1;
    double step = a[1].x - a[0].x;
    for (i = 2; i < n && f; i++)
        f = ((a[i].x - a[i - 1].x) == step);
    return f;
}

void* end_razn (tochka* a, size_t n, float x)
{
    int i;
    float* k = (float*)calloc(n, sizeof(float));
    float step = a[1].x - a[0].x;
    float t =  (x - a[0].x)/step;
    float t2 = (x - a[0].x)/step;
    for (i = 0; i < n; i++)
        {
            k[i] = t2;
            t2 *= (t - 1 - i);
        }
    return k;
}

void* del_razn (tochka* a, size_t n, float x)
{
    int i;
    float* k = (float*)calloc(n, sizeof(float));
    float t = x - a[0].x;
    for (i = 0; i < n - 1; i++)
        {
            k[i] = t;
            t *= (x - a[i + 1].x);
        }
    return k;
}

float RECend_razn(tochka* a, int exp, int num)
{
    if (exp == 1)
        return (a[exp].y - a[num].y);
    return (RECend_razn(a, exp - 1, num + 1) - RECend_razn(a, exp - 1, num));
}

float  RECdel_razn(tochka* a, int exp, int num)
{
    if (exp == 1)
        return (a[exp].y - a[num].y) / (a[exp].x - a[num].x);
    return (RECdel_razn(a, exp-1, num+1) - RECdel_razn(a, exp-1, num)) / (a[exp + num].x - a[num].x);
}














