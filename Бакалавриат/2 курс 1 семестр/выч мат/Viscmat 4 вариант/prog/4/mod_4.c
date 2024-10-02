#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "mod_4.h"
#define EPPS 0.00000001
float det_2 (float a11, float a12, float a21, float a22)
{
    return a11*a22-a12*a21;
}

int kram_resh (float a11, float a12, float a21, float a22, float b1, float b2, float* x1, float* x2)
{
    float maindet = det_2(a11, a12, a21, a22); //общий определитель
    if (fabs(maindet)>EPPS)
    {
        float det1 = det_2(b1, a12, b2, a22);
        float det2 = det_2(a11, b1, a21, b2);
        (*x1) = det1/maindet;
        (*x2) = det2/maindet;
        return 1;
    }
    else return 0;
}

int booll (func_2 f, func_1 df_dx, func_1 df_dy, func_2 g, func_1 dg_dx, func_1 dg_dy, float*x0, float*y0, float eppss, int n)
{
    double x, y, h, l;
    int i=0;
    x=(*x0);
    y=(*y0);
    while(fabs(f(x,y))+fabs(g(x,y))>eppss && i++<n)
    {
        int flag = kram_resh(df_dx(x), df_dy(y), dg_dx(x), dg_dy(y), f(x,y), g(x,y), &h, &l);
        if(!flag)
            return 0;
        else
        {
            x+=h;
            y+=l;
        }
    }
    if (i<=n)
    {
        (*y0)=y;
        (*x0)=x;
        return 1;
    }
    else return 0;
}














