#include <stdio.h>
#include <stdlib.h>
enum colors{red, yellow, green};

void PrintByte (char a)
{
    int i;
    int mask = 1<<7;
    for (i=0;i<8;i++)
    {
        printf("%d",(a&mask)?1:0);
        a<<=1;
    }
}

void PrintVar (void *a, unsigned size)
{
    int i;
    char*p=a;
    for (i=size-1;i>=0;i--)
        PrintByte(*(p+i));
    printf ("\n");
}

int main()
{
    int i,j,k;
    signed char a1;
    float a2;
    long double d;
    scanf("%lf",&d);
    PrintVar(&d,sizeof(d));

    scanf ("%d",&a1);
    PrintVar(&a1,sizeof(a1));
    scanf("%f",&a2);
    PrintVar(&a2,sizeof(a2));

    return 0;
}
