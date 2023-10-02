#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float f (float x1, float x2);
float grad (float *x1, float *x2);
int check(float x1, float x2, float e, float A, float B, float Y, int n);

int main()
{
    setlocale(LC_ALL,"Rus");
    float a,b,e, t,x1, x2;int n,fl;
    printf ("M0:    ");
    scanf("%f%f",&x1,&x2);
    printf ("\nТочность:    ");
    scanf ("%f",&e);
    printf ("\nМаксимальное количество итераций:    ");
    scanf ("%d",&n);
    float A=1, B=1, Y=0.5;
    printf ("\n%d",check(x1, x2, e, A, B, Y,n));
}

float f (float x1, float x2)
{
    return (x1*x1+x2*x2-3*x1+3*x2+8);
}

float grad (float *x1, float *x2)
{
    *x1=2*(*x1)-3;
    *x2=2*(*x2)+3;
    return ((*x1)*(*x1)+(*x2)*(*x2));
}

int check(float x1, float x2, float e, float A, float B, float Y, int n)
//x1,x2 - начальные значения
//А,B,Y - альфа, бета, гамма
{
    float t1=x1,t2=x2,y1=Y, fx,ft,g1,g2, mg, R;
    int i=1,j=0;
    Y=1;
    FILE *F=fopen("rez.txt","w+b");
    fprintf (F,"M0  %f   %f\n", x1,x2);

    do
    {
        do
        {
            Y=Y*y1;
            i++;
            g1=x1; g2=x2;
            mg = grad(&g1,&g2);
            fx=f(x1-A*Y*g1,x2-A*Y*g2);
            ft=f(x1,x2);
            if (fx-ft>-B*A*Y*mg)
            {
                x1=x1-A*Y*g1;
                x2=x2-A*Y*g2;
                fprintf (F,"\nx1 = %f   x2 = %f\n", x1,x2);
            }
            else
            {
                t1=x1;
                t2=x2;
            }
            j++;
        } while ((fx-ft>-B*A*Y*mg));
        Y=1; i=1;
    } while (f(x1,x2)-f(t1,t2)>e && j<n);
    printf ("\nx1 = %f  x2 = %f", x1, x2);
    printf ("\nf(x1,x2) = %f",f(x1,x2));
    printf ("\nj = %d", j);

    fprintf (F,"\n\nx1 = %f   x2 = %f\n", x1,x2);
    fprintf (F,"\n\nf(x1,x2) = %f",f(x1,x2));
    fprintf (F,"\n\nj = %d", j);
    fclose(F);

    return (j<n);
}
