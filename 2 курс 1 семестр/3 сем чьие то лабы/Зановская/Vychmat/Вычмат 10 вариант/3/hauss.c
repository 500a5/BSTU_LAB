#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
void hauss (float a, float b);
void main()
{
    setlocale (LC_ALL, "Rus");
    float a,b;
    printf ("a = ");
    scanf ("%f",&a);
    printf ("b = ");
    scanf ("%f",&b);
    hauss (a,b);
}


void hauss (float a, float b)
{
    int i;


    float a1[2],a2[2][2],a3[3][2],a4[4][2],x1,x2,sum,y;
    a1[0]=0;
    a1[1]=2;

    a2[0][0]=-0.5773502692;
    a2[0][1]=1;
    a2[1][0]=0.5773502692;
    a2[1][1]=1;

    a3[0][0]=-0.7745966692;
    a3[0][1]=0.55555555555;
    a3[1][0]=0;
    a3[1][1]=0.888888888;
    a3[2][0]=0.7745966692;
    a3[2][1]=0.555555555;

    a4[0][0]=-0.8611363115;
    a4[0][1]=0.3478548451;
    a4[1][0]=-0.3399810436;
    a4[1][1]=0.6521451549;
    a4[2][0]=0.3399810436;
    a4[2][1]=0.6521451549;
    a4[3][0]=0.8611363115;
    a4[3][1]=0.3478548451;

   // printf ("\na = %f\nb = %f",a,b);
    x1=(b-a)/2; //printf ("\nx2 = %f", x1);
    x2=(b+a)/2; // printf ("\nxn = %f", x2);

    printf ("\n¬ведите значение в точке %f   ", x2+x1*a1[0]);
    //scanf ("%f",&y);
    y=(x2+x1*a1[0])*(x2+x1*a1[0])+2*(x2+x1*a1[0])+1;
    //printf ("%.4f",y);
    printf ("16");
    sum=x1*a1[1]*y;
    printf ("\nsum1 = %f",sum);

    sum=0;
    for (i=0;i<2;i++)
    {

        printf ("\n¬ведите значение в точке %f   ", x2+x1*a2[i][0]);
       // scanf ("%f",&y);
        y=(x2+x1*a2[i][0])*(x2+x1*a2[i][0])+2*(x2+x1*a2[i][0])+1;
        printf ("%.4f",y);
        sum+=a2[i][1]*y;
    }
    sum*=x1;
    printf ("\nsum2 = %f",sum);

    sum=0;
    for (i=0;i<3;i++)
    {
        printf ("\n¬ведите значение в точке %f   ", x2+x1*a3[i][0]);
        //scanf ("%f",&y);
        y=(x2+x1*a3[i][0])*(x2+x1*a3[i][0])+2*(x2+x1*a3[i][0])+1;

        if (y>15 && y<17)
             printf ("16");
        else
        printf ("%.4f",y);
        sum+=a3[i][1]*y;
    }
    sum*=x1;
    printf ("\nsum3 = %f",sum);

    sum=0;
    for (i=0;i<4;i++)
    {
        printf ("\n¬ведите значение в точке %f   ", x2+x1*a4[i][0]);
       // scanf ("%f",&y);
        y=(x2+x1*a4[i][0])*(x2+x1*a4[i][0])+2*(x2+x1*a4[i][0])+1;
        printf ("%.4f",y);
        sum+=a4[i][1]*y;
    }
    sum*=x1;
    printf ("\nsum4 = %f",sum);

}
