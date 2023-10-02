#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vi6.h"


float OptPoisk (func f, float a, float b, float eps)
{
    float xmin = a, fmin = f(a), del = b-a, xi, fi; //первая точка - мин, del = разность концов отрезка
    float k = (del/eps)-1; // найдем нужное- колво-шагов
    int n = (int)k, i;  //количество шагов
    //printf("%d ", n);
    float h = del/(n+1); //определяем шаг
    for (i=0; i<n; i++)
    {
        xi = a+i*h;
        fi = f(xi);
        if (fi<=fmin)
        {
            xmin = xi;
            fmin = fi;
        }
    }
    return xmin;
}

float DelOtr(func f, float a, float b, float eps)
{
    float ol = eps/2, al = a, bl = b, xa, xb;
    float del = (bl-al)/2;
    while (del > eps)
    {
        xa = (al + bl) / 2 - ol;
        xb = (al + bl) / 2 + ol;
        if (f(xa) > f(xb))
                al = xa;
            else
                bl = xb;
        del = (bl-al)/2;
    }
    return (al + bl) / 2;
}

int F(int i)
{  if(i==0) return 1;
   else if (i==1) return 1;
        else if(i>=2) return F(i-1) + F(i-2);
}

float MetFib (func f, float a, float b, float eps)
{
    float del = b-a;
    float l = (del/eps)-1;
    int n = (int)l, k;
    float a0 = a+(b-a)*F(n-1)/F(n+1);
    float b0 = a+(b-a)*F(n)/F(n+1);
    for (k=1; k<n; k++)
    {
        if (f(a0)<=f(b0))
        {
            b=b0;
            b0=a0;
            a0=a + (double)F(n-k-1)/F(n-k+1)*(b-a);//
        }
        else
        {
            a=a0;
            a0=b0;
            b0 = a + (double)F(n-k)/F(n-k+1)*(b-a);
        }
    }
    return (a+b)/2;
}

/*double minFib(func f, double a, double b, double eps)
{
  int k, n;
  double a0, b0;
  for(n=0;F(n)<(b-a)/eps;n++);
  n--;
  printf("n=%d\n",n);

  a0=a+(b-a)*F(n-1)/F(n+1);
  b0=a+(b-a)*F(n)/F(n+1);

  for(k=1;k<n;k++)
  {
    //printf(" k=%i ,a=%lf,b=%lf , a0=%lf,b0=%lf\n" , k , a ,b,a0 , b0);
    if(f(a0)<=f(b0))
    {
     b=b0;
     b0=a0;
     a0 = a + (double)F(n-k-1)/F(n-k+1)*(b-a);//
    }
   else
   {
    a=a0;
    a0=b0;
    b0 = a + (double)F(n-k)/F(n-k+1)*(b-a);
   }
  }
return (a+b)/2;
}*/
