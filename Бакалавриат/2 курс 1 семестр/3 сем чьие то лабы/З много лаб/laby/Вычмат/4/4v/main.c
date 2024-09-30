#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


typedef float (*func)(float, float);

float mR (float d1, float d2,int p);
float Eil (func Fxy, int n, float h, float b, float x,float y,int k);
float EilK (func Fxy, int n, float h, float b, float x,float y, int k);
float MEil (func Fxy, int n, float h, float b, float x,float y, int k);
float RK (func Fxy, int n, float h, float b, float x,float y, int k);
float Fx (float x, float y);

int main()
{
    setlocale (LC_ALL, "Rus");
    float x0,y0,a,b,h1,h2,e,d1,d2,p;
    int n1,n2,i=0,t=15,fl=1,k;

    printf ("x0 = "); scanf ("%f",&x0);
    printf ("y0 = "); scanf ("%f",&y0);
    printf ("a = "); scanf ("%f",&a);
    printf ("b = "); scanf ("%f",&b);
    printf ("h1 = "); scanf ("%f",&h1); n1=(int)((a+b)/h1); n1+=1;
    printf ("h2 = "); scanf ("%f",&h2); n2=(int)((a+b)/h2); n2+=1;
    printf ("\nТребуемая точность ");
    scanf ("%f",&e);
    printf ("Метод решения: \n1 - Метод Эйлера\n2 - Метод Эйлера-Коши\n3 - Модифицированный метод Эйлера\n4 - Метод Рунге-Кутты   \n");
    scanf ("%d", &k);
    i=0;
    switch (k)
    {
        case 1:
            while (fl)
            {
                d1=Eil(Fx,n1,h1,b,x0,y0,k);
                d2=Eil(Fx,n2,h2,b,x0,y0,k);
                p=mR(d1,d2,1);
                fl=(p>e)&& i<t;
                h1=h2; n1=n2;
                h2/=2; n2=n2*2-1;
                i++;
            }
            break;
        case 2:
            while (fl)
            {
                d1=EilK(Fx,n1,h1,b,x0,y0,k);
                d2=EilK(Fx,n2,h2,b,x0,y0,k);
                p=mR(d1,d2,1);
                fl=(p>e)&& i<t;
                h1=h2; n1=n2;
                h2/=2; n2=n2*2-1;
                i++;
            }
            break;
        case 3:
            while (fl)
            {
                d1=MEil(Fx,n1,h1,b,x0,y0,k);
                d2=MEil(Fx,n2,h2,b,x0,y0,k);
                p=mR(d1,d2,2);
                fl=(p>e)&& i<t;
                h1=h2; n1=n2;
                h2/=2; n2=n2*2-1;
                i++;
            }
            break;
        case 4:
            while (fl)
            {
                d1=RK(Fx,n1,h1,b,x0,y0,k);
                d2=RK(Fx,n2,h2,b,x0,y0,k);
                p=mR(d1,d2,4);
                fl=(p>e)&& i<t;
                h1=h2; n1=n2;
                h2/=2; n2=n2*2-1;
                i++;
            }
            break;
    }
    if (i<t)
        printf ("\nДостичь заданной точности не удалось");
    printf ("\nВычисленные значения  ");


    printf ("Записать результат работы в файл? Да - 1, имя файла. Нет - 0");
    scanf ("%d",&k);
    if (k)
    {
        char s[15];
        gets (s);
        wr(s,d2+p);
    }
}

float mR (float d1, float d2,int p)
{
    return (float)(d1-d2)/(pow(2,p)-1);
}

float Eil (func Fxy, int n, float h, float b, float x,float y, int k)
{
    int i;
    float **pa;
    pa=(float **) calloc(n,sizeof(float *));
    for (i=0;i<n;i++)
        pa[i]=(float *) calloc(3,sizeof(float));
    pa[0][0]=x;
    for (i=1;i<n;i++)
        pa[i][0]=pa[i-1][0]+h;
    pa[0][1]=y;
    pa[0][2]=Fxy(pa[0][0],pa[0][1]);
    for (i=1;i<n;i++)
    {
        pa[i][1]=pa[i-1][1]+h*pa[i-1][2];
        pa[i][2]=Fxy(pa[i-1][1],pa[i-1][2]);
    }
    return pa[n-1][1];
}

float EilK (func Fxy, int n, float h, float b, float x,float y, int k)
{
    int i;
    float **pa;
    pa=(float **) calloc(n,sizeof(float *));
    for (i=0;i<n;i++)
        pa[i]=(float *) calloc(4,sizeof(float));
    pa[0][0]=x;
    for (i=1;i<n;i++)
        pa[i][0]=pa[i-1][0]+h;
    pa[0][1]=y;
    pa[0][2]=0;//вспомогательная функция
    pa[0][3]=Fxy(pa[0][0],pa[0][1]);//производная
    for (i=1;i<n;i++)
    {
        pa[i][2]=Fxy(pa[i-1][0]+h,pa[i-1][1]+h*pa[i-1][2]);
        pa[i][1]=pa[i-1][1]+h/2*(pa[i-1][3]+h*pa[i-1][2]); //y
    }
    return pa[n-1][1];
}



float MEil (func Fxy, int n, float h, float b, float x,float y, int k)
{
    int i;
    float **pa;
    pa=(float **) calloc(n,sizeof(float *));
    for (i=0;i<n;i++)
        pa[i]=(float *) calloc(4,sizeof(float));
    //float h; h=(a+b)/n;
    pa[0][0]=x;
    for (i=1;i<n;i++)
        pa[i][0]=pa[i-1][0]+h;
    pa[0][1]=y;
    pa[0][2]=0;//вспомогательная функция
    pa[0][3]=Fxy(pa[0][0],pa[0][1]);//производная
    for (i=1;i<n;i++)
    {
        pa[i][2]=Fxy(pa[i-1][0]+h/2,pa[i-1][1]+h/2*pa[i-1][3]);
        pa[i][1]=pa[i-1][1]+h*pa[i][2]; //y
        pa[i][3]=Fxy(pa[i][0],pa[i][1]);
    }
    return pa[n-1][1];
}

float RK (func Fxy, int n, float h, float b, float x,float y, int k)
{
    int i;
    float **pa;
    pa=(float **) calloc(n,sizeof(float *));
    for (i=0;i<n;i++)
        pa[i]=(float *) calloc(6,sizeof(float));
    //float h; h=(a+b)/n;
    pa[0][0]=x;
    for (i=1;i<n;i++)
        pa[i][0]=pa[i-1][0]+h;
    pa[0][1]=y;
    pa[0][2]=Fxy(pa[0][0],pa[0][1]);//m1
    pa[0][3]=Fxy(pa[0][0]+h/2,pa[0][1]+h/2*pa[0][2]);//m2
    pa[0][4]=Fxy(pa[0][0]+h/2,pa[0][1]+h/2*pa[0][3]);//m3
    pa[0][5]=Fxy(pa[0][0]+h,pa[0][1]+h*pa[0][4]);//m4
    for (i=1;i<n;i++)
    {
        pa[i][1]=pa[i-1][1]+h/6*(pa[i-1][2]+2*pa[i-1][3]+2*pa[i-1][4]+pa[i-1][5]);
        pa[i][2]=Fxy(pa[i][0],pa[i][1]);//m1
        pa[i][3]=Fxy(pa[i][0]+h/2,pa[i][1]+h/2*pa[i][2]);//m2
        pa[i][4]=Fxy(pa[i][0]+h/2,pa[i][1]+h/2*pa[i][3]);//m3
        pa[i][5]=Fxy(pa[i][0]+h,pa[i][1]+h*pa[i][4]);//m4
    }
    return pa[n-1][1];
}

float Fx (float x, float y)
{
    return (5+(2*x-5)/(x*x))*y;
}

void wr (char *s,float x)
{
    FILE *f;
    f=fopen(s,"w+b");
    fprintf (f,"%f", x);
    fclose (f);
}
