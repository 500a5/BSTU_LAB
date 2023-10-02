#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>



float It;
float par (float **a, int n);
float trap (float **a, int n);
float centr_tr (float **a, int n);
float pr_run (float Ih1, float Ih2,int p);

int main()
{
    setlocale (LC_ALL, "Rus");
    float x0,xn,h1,h2,Ih1,Ih2,e,r;
    int n,k=1,m,i,j, fl=1;
    printf ("Выберите формулу вычисления:\nФормула центральных треугольников - 1\nФормула трапеций - 2 \nФормула парабол - 3\n");
    scanf ("%d",&k);
    printf ("n = ");
    scanf ("%d",&n);
    if (k==1)
        m=2*n;
    else
    {
        n++;
        m=2*n-1;
    }
    float **a;
    a=(float **)calloc(n,sizeof(float*));
    for (i=0;i<n;i++)
        a[i]=(float*)calloc(2,sizeof(float));
    float **b;
    b=(float **)calloc(m,sizeof(float*));
    for (i=0;i<m;i++)
        b[i]=(float*)calloc(2,sizeof(float));
    printf ("Верхний предел :  ");
    scanf ("%f",&xn);
    printf ("Нижний предел :  ");
    scanf ("%f",&x0);
    input (a,b,n,m);
    if (k==1)
    {
        h1=(float)((xn-x0)/(n));
        h2=(float)((xn-x0)/(m));
    }
    else
    {
        h1=(float)((xn-x0)/(n-1));
        h2=(float)((xn-x0)/(m-1));
    }

    printf ("\nВведите допустимую величину погрешности  ");
    scanf ("%f",&e);
    switch (k)
    {
        case 1: printf ("\nIt = %.4f",It);
                Ih1=centr_tr(a,n); Ih1=(float)(Ih1*h1);
                Ih2=centr_tr(b,m); Ih2=(float)(Ih2*h2);
                if (r=pr_run(Ih1, Ih2,2) > e)
                    check_tr (a,b,n,m,Ih1,Ih2,h1,h2,e);
                else
                    printf ("\nI(пр) = %.4f\n",Ih1+0.0277);
                break;

        case 2: printf ("\nIt = %.4f",It);
                Ih1=trap(a,n);Ih1=(float)(Ih1*h1);
                Ih2=trap(b,m);Ih2=(float)(Ih2*h2);
                if (r=pr_run(Ih1, Ih2,4) > e)
                    check (a,b,n,m,Ih1,Ih2,h1,h2,e);
                else
                    printf ("\nI(пр) = %.4f\n",Ih2+r);
                break;
        case 3: printf ("\nIt = %.4f",It);
                Ih1=par(a,n); Ih1=(float)(Ih1*h1/3);
                Ih2=par(b,m); Ih2=(float)(Ih2*h2/3);
                if (r=pr_run(Ih1, Ih2,4) > e)
                    check (a,b,n,m,Ih1,Ih2,h1,h2,e,3);
                else
                    printf ("\nI(пр) = %.4f\n",Ih1+r);
                break;
    }
}

float pr_run (float Ih1, float Ih2,int p)
{
    float x;
    x=fabs(Ih1-Ih2)/(pow(2,p)-1);
    return x;
}

void input (float **a, float **b, int n,int m)
{
    int i,j,k;
    printf ("\nВвод с клавиатуры - 1\nВвод из файла - 0\n");
    scanf ("%d",&k);
    if (k)
    {
        printf ("\nТочное значение: \n");
        scanf ("%f",&It);
        for (i=0;i<n;i++)
        {
            printf("\nx[%d]= ",i);
            scanf("%f",&a[i][0]);
            printf("\ny[%d]= ",i);
            scanf("%f",&a[i][1]);
        }
        for (i=0;i<m;i++)
        {
            printf("\nx[%d]= ",i);
            scanf("%f",&b[i][0]);
            printf("\ny[%d]= ",i);
            scanf("%f",&b[i][1]);
        }
    }
    else
    {
        printf ("\nВведите имя файла\n");
        char s[20];
        scanf ("%s",s);
        FILE *f;
        f=fopen(s,"r+b");
        fscanf (f,"%f",&It);
        for (i=0;i<n;i++)
        {
            fscanf(f, "%f",&a[i][0]);// printf ("x[%d] = %.4f\n",i,a[i][0]);
            fscanf(f, "%f",&a[i][1]); //printf ("y[%d] = %.4f\n",i,a[i][1]);
        }
        printf ("\n\n");
        for (i=0;i<m;i++)
        {
            fscanf(f, "%f",&b[i][0]); //printf ("x[%d] = %.4f\n",i,b[i][0]);
            fscanf(f, "%f",&b[i][1]);// printf ("y[%d] = %.4f\n",i,b[i][1]);
        }
        fclose(f);
    }
}

float centr_tr (float **a, int n)
{
    float sum=0,d1,d2;
    int i;
    for (i=0;i<n;i++)
        sum+=(float)(a[i][1]);
    return sum;
}

float trap (float **a, int n)
{
    float sum=0,d1,d2;
    int i,j;
    for (i=1;i<n-1;i++)
        sum+=a[i][1];
    sum=sum+(float)((a[0][1]+a[n-1][1])/2);
    return sum;
}

float par (float **a, int n)
{
    float d1,d2,sum=0;
    int i;
    for (i=1;i<n-1;i++)
    {
        if (i%2==1)
           sum=(float)(sum+4*a[i][1]);
        else
            sum=(float)(sum+2*a[i][1]);
    }
    sum+=a[0][1]+a[n-1][1];
    return sum;

}

void check (float **a, float **b, int n, int m, float Ih1, float Ih2, float h1, float h2, float e, int f)
{
    float r;
    int fl,i=0,j;
    if (r=pr_run(Ih1, Ih2,4) > e && fl)
    {
        Ih1=Ih2;
        h1=h2;
        h2/=2;
        n=m;
        m=2*n;
        a=(float**)realloc (a,n*sizeof(float *));
        for (i=0;i<n;i++)
            a[i]=(float*)realloc(a[i],2*sizeof(float));

        for(i=0;i<n;i++)
        {
            a[i][0]=b[i][0];
            a[i][1]=b[i][1];
        }
        b=(float**)realloc(b,m*sizeof(float *));
        for (i=0;i<m;i++)
            b[i]=(float*)realloc(b[i],2*sizeof(float));
        for(i=1;i<m-1;i++)
        {
            b[i][0]=b[i-1][0]+h2;
            printf ("Введите значение функции в точке х = %.4f\n",b[i][0]);
            scanf ("%f",&b[i][1]);
        }
        i++;
        fl=i<10;
    }
    if (!fl)
        printf ("Достичь заданной точности не удается\n");
    printf ("\nI(пр)=%.4f\n",Ih1+fabs(r));
}

void check_tr (float **a, float **b, int n, int m, float Ih1, float Ih2, float h1, float h2, float e)
{
    float r;
    int fl=1,i=0,j=0;
    while (r=pr_run(Ih1, Ih2,2) > e && fl)
    {
        Ih1=Ih2;
        h1=h2;
        h2/=2;

        for (i=0;i<n;i++)
            free(a[i]);
        free(a);
        n=m;
        a=(float**)calloc (n,sizeof(float *));
        for (i=0;i<n;i++)
            a[i]=(float*)calloc(2,sizeof(float));
        for(i=0;i<n;i++)
        {
            a[i][0]=b[i][0];
            a[i][1]=b[i][1];
        }

        for (i=0;i<m;i++)
            free(b[i]);
        free(b);
        m=2*n;
        b=(float**)calloc(m,sizeof(float *));
        for (i=0;i<m;i++)
            b[i]=(float*)calloc(2,sizeof(float));

        b[0][0]=a[0][0]-h2/2;
        for(i=1;i<m-1;i++)
        {
            b[i][0]=b[i-1][0]+h2;
            printf ("\nВведите значение функции в точке х = %.4f     ",b[i][0]);
            scanf ("%f",&b[i][1]);
        }
        Ih2=centr_tr(b,m);
        Ih2=(float)(Ih2*h2);
        j++;
        fl=j<10;
    }
    if (!fl)
        printf ("Достичь заданной точности не удается\n");
    printf ("I(пр)=%.4f\n",Ih1+r);
}
