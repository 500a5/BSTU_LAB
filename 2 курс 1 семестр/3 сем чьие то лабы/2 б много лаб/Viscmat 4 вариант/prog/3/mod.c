#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "mod.h"

float fun_1(float x)
{
    return (1/(pow(x, 2)));
}

float fun_2(float x)
{
    return (cos(2*x));
}

float fun_3(float x)
{
    return (powf(5, x));
}

float CentrPry (func_f f, float a, float b, size_t n)
{
    float h = (b-a)/n;
    float sum=0, xi2=0;
    int i;
    for (i=0; i<n; i++)
    {
       xi2 =a+(i+0.5)*h;
       sum+=f(xi2);
    }
    return h*sum;
}

float RungeCentrPry (func_f f, float a, float b, size_t n)
{
    float in = CentrPry(f, a, b, n);
    float in2 = CentrPry(f, a, b, 2*n);
    float ch = fabs(in2-in);
    return ch/3;
}

float Trap (func_f f, float a, float b, size_t n)
{
    float h = (b-a)/n;
    float sum = 0, xi=0;
    int i;
    for (i=1, xi=a+h; i<=n-1; i++)
    {
       sum+=f(xi);
       xi +=h;
    }
    sum += (f(a)+f(b))/2;
    return h*sum;
}

float RungeTrap (func_f f, float a, float b, size_t n)
{
    float in = Trap(f, a, b, n);
    float in2 = Trap(f, a, b, 2*n);
    float ch = fabs(in2-in);
    return ch/3;
}

float Simp (func_f f, float a, float b, size_t n)
{
    float h = (b-a)/n;
    float xi=0, sum=0;
    int i;
    for (i=1; i<n; i++)
    {
        xi= a+i*h;
        sum+=f(xi-h)+4*f(xi)+f(xi+h);
    }
    return sum*h/3;
}

float RungeSimp (func_f f, float a, float b, size_t n)
{
    float in = Simp(f, a, b, n);
    float in2 = Simp(f, a, b, 2*n);
    float ch = fabs(in2-in);
    return ch/15;
}


float Gauss (func_f f, float a, float b, size_t n)
{
    float A[n];
 	float t[n];
 	switch (n)
    {
 	case 1:
 	    t[0] = 0;
        A[0] = 2;
 	break;
 	case 2:
        t[0] = -0.5773503;
        A[0] = 1;
        t[1] = 0.5773503;
        A[1] = 1;
 	break;
 	case 3:
        t[0] = -0.7745967;
        A[0] = 0.5555556;
        t[1] = 0;
        A[1] = 0.8888889;
        t[2] = 0.7745967;
        A[2] = 0.5555556;
 	break;
 	case 4:
        t[0] = -0.8611363;
        A[0] = 0.3478548;
        t[1] = -0.3399810;
        A[1] = 0.6521451;
        t[2] = 0.3399810;
        A[2] = 0.6521451;
        t[3] = 0.8611363;
        A[3] = 0.3478548;
 	break;
    }

    float h=(b-a)/n;
    float sum=0, xi=0, tmp1=(b+a)/2, tmp2=(b-a)/2;
    int i;
    for (i=0; i<n; i++)
    {
       sum+=A[i]*f(tmp1+tmp2*t[i]);
    }
    return sum*tmp2;
}









