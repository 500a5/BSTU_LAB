#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


typedef float (*func)(float, float);

float F (float x, float y);
float dF_dx (float x, float y);
float dF_dy (float x, float y);
float Fi (float x, float y);
float dFi_dx (float x, float y);
float dFi_dy (float x, float y);

int ch (func F,func dF_dx,func dF_dy,func Fi,func dFi_dx,func dFi_dy, int n, float e, float x, float y);


int main()
{
    setlocale (LC_ALL, "Rus");
    float x,y,e;
    int n;
    printf ("x = "); scanf ("%f",&x);
    printf ("y = "); scanf ("%f",&y);
    printf ("e = "); scanf ("%f",&e);
    printf ("Максимальное количество итераций: "); scanf ("%d",&n);

    return (ch(F,dF_dx,dF_dy,Fi, dFi_dx, dFi_dy, n, e, x, y));

}

int ch (func F,func dF_dx,func dF_dy,func Fi,func dFi_dx,func dFi_dy, int n, float e, float x, float y)
{
    int i;
    float l,h,s1,s2;
    float **pa;
    pa=(float **) calloc(2,sizeof(float *));
    for (i=0;i<2;i++)
        pa[i]=(float *) calloc(3,sizeof(float));
    i = 0;
    while (i<n && s1+s2>e)
    {
        pa[0][0]=dF_dx(x,y);
        pa[0][1]=dF_dy (x,y);
        pa[0][2]=-F(x,y);
        pa[1][0]=dFi_dx(x,y);
        pa[1][1]=dFi_dx(x,y);
        pa[1][2]=-Fi(x,y);

        decision (pa,2,3);
        back_stroke (pa,2,3);
        h=pa[0][2];
        l=pa[1][2];

        x+=h;
        y+=l;

        s1=fabs(F(x,y));
        s2=fabs(Fi(x,y));
    }

    if(s1+s2<e)
    {
        printf ("\nЗаданная точность достигнута");
        printf ("\nx = %f, y = %f",x,y);
        return 1;
    }
    else
    {
        printf ("\nЗаданная точность недостигнута");
        printf ("\nx = %f, y = %f",x,y);
        return 0;
    }


}

float F (float x, float y)
{
    return (sin(4*x)-2.2*y-0.1);
}

float dF_dx (float x, float y)
{
    return (4*cos(4*x));
}

float dF_dy (float x, float y)
{
    return (-2.2);
}

float Fi (float x, float y)
{
    return (x*x+y*y-4);
}

float dFi_dx (float x, float y)
{
    return (2*x);
}

float dFi_dy (float x, float y)
{
    return (2*y);
}

void subs (float **a, int m, int n,int i)
{
    int j,y;
    float k;
    y=i;
    for (++i;i<m;i++)
    {
        k=-a[i][y]/a[y][y];
        for (j=0;j<n;j++)
            a[i][j]+=k*a[y][j];
    }
}

void sub (float **a, int m, int n,int i)
{
    int j,y;
    float k;
    y=i;
    for (--i;i>=0;i--)
    {
        k=-a[i][y]/a[y][y];
        for (j=0;j<n;j++)
            a[i][j]+=k*a[y][j];
    }
    for (j=y+1;j<n;j++)
        a[y][j]/=a[y][y];
    a[y][y]=1;
}
void swap (float **a, int x, int y, int n)
{
    int i; float *k;
    k=a[x];
    a[x]=a[y];
    a[y]=k;
}
//m - кол-во строк, j - проверяемый столбец
int search (float **a, int m, int j)
{
    int i, nom;
    float max;
    nom = j; max = a[j][j];
    for (i=j+1;i<m;i++)
        if (fabs(a[i][j])-fabs(max)>0.001)
        {
            max=fabs(a[i][j]);
            nom=i;
        }
    return nom;
}

int decision (float **a, int m, int n)
{
    int i,j=0,nom,t=0;
    for (i=0;i<m-1;i++)
    {
        if (a[i][i]==0)
            return 0;
        nom=search(a,m,j);
        if (nom!=i)
        {
            swap(a,i,nom,n);
        }
        subs(a,m,n,i);
        j++;
    }
}
 void back_stroke (float **a, int m, int n)
 {
     int i,j,g,k;
     float sum;
     for (k=m;k<n;k++)
     {
        for (i=m-1;i>=0;i--)
        {
            sum=0;
            for(j=m-1;j>i;j--)
                sum+=a[i][j]*a[j][k];
            a[i][k]=(a[i][k]-sum)/a[i][i];
        }
     }
 }



