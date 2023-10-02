#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float f (float x);
float DivTo2 (float a, float b, float e);
float PasSearch (float a, float b, float e);
float Fib (float a, float b, float e);

int main()
{
    setlocale(LC_ALL,"Rus");
    float a,b,e=0.001, t,x;
    printf ("¬ведите а  ");
    scanf ("%f", &a);
    printf ("¬ведите b  ");
    scanf ("%f", &b);
    printf ("¬ведите точное значение  ");
    scanf ("%f", &t);

    //t=f(t);

    x=PasSearch(a,b,e); //x=f(x);
    printf ("\nMeтод пассивного поиска");
    printf ("\nх = %f    D = %f    d = %f%% ",x, (float)fabs(x-t),(float)fabs((x-t)/t*100));
    printf ("\nMeтод делени€ отрезка пополам");
    x=DivTo2(a,b,e);
    printf ("\nх = %f    D = %f    d = %f%% ",x, (float)fabs(x-t),(float)fabs((x-t)/t*100));
    printf ("\nMeтод чисел ‘ибоначчи");
    x=Fib(a,b,e);
    printf ("\nх = %f    D = %f    d = %f%% ", x,(float)fabs(x-t),(float)fabs((x-t)/t*100));
}

float f (float x)
{
    //return -((float)exp(x*x+1)/(x+1));
    return (2*x*x-4)/(log(x*x));
}

float PasSearch (float a, float b, float e)
{
    int n,i,min;
    n=(b-a)/e;
    float **p;
    p=(float **)calloc (2,sizeof (float*));
    for (i=0;i<2;i++)
        p[i]=(float *)calloc(n,sizeof(float));
    //перва€ строка - х, втора€ - у
    p[0][0]=a;
    p[1][0]=f(a);
    min=0;
    for (i=1;i<n;i++)
    {
        p[0][i]=p[0][i-1]+e;
        p[1][i]=f(p[0][i]);
        if(p[1][min]>p[1][i])
            min=i;
    }
    return p[0][min];
}

float DivTo2 (float a, float b, float e)
{
    float Al=0,Be=0;
    int i=0,t=100;
    while (fabs(b-a)>e && i<t)
    {
        Al=(float)((a+b)/2-e);
        Be=(float)((a+b)/2+e);
        if (f(Al)<=f(Be))
            b=Be;
        else
            a=Al;
        i++;
    }
    return (Al);

}

float Fib (float a, float b, float e)
{
    int k,k1,k2,t=0,n=0,i,j;
    float Al,Be,d;
    k=(int)(1/e);

    k1=k2=1; n=2;
    while (t<k)
    {
        t=k1+k2;
        k1=k2;
        k2=t;
        n++;
    }
    n+=1;
    int *F;
    F=(int *)calloc (n,sizeof (int));
    F[0]=F[1]=1;
    i=2;
    while (i<n)
    {
        F[i]=F[i-1]+F[i-2];
        i++;
    }
    n-=2;
    k=0;
    d=(float)(b-a);
    while (d>e)
    {
        Al=(a+(float)F[n-k-1]/F[n-k+1]*d);
        Be=(a+(float)F[n-k]/F[n-k+1]*d);
        if (f(Al)<=f(Be))
            b=Be;
        else
            a=Al;
        k++;
        d=(float)(b-a);
    }
    return (a);
}
