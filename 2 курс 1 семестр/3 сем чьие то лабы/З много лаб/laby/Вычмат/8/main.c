#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float Root (float a, float b, float e);
int main()
{
    setlocale (LC_ALL, "Rus");
    float a,b,e;
    int n,i;
    printf ("a = ");
    scanf ("%f",&a);
    printf ("b = ");
    scanf ("%f",&b);
    printf ("e = ");
    scanf ("%f",&e);
    Root(a,b,e);
}

float f (float x)
{
    return (x*x*x-7*x*x+7*x+15);
}

float fxdx (float x)
{
    return (3*x*x-14*x+7);
}

float fxdxdx (float x)
{
    return (6*x-14);
}

float Chord (float x, float t)
{
    return (x - (float)(f(x)*(x-t)/( f(t)-f(x))));
}

float Newton (float x)
{
    return (x-(float)(f(x)/fxdx(x)));
}

float Root (float a, float b, float e)
{
    float xc,xk;
    if (f(a)*fxdxdx(a)>0)
    {
        xc=b;
        xk=a;
    }
    else
    {
        xk=b;
        xc=a;
    }
    while (fabs(xc-xk)>e)
    {
        xc=Chord(xk,xc);
        xk=Newton(xk);
    }
    float x=(float)((xc+xk)/2);
    printf ("\nx = %f",x);
    printf ("\nf(x) = %f", f(x));
    return x;
}
