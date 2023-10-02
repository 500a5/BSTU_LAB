#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int n=10;

int main()
{
    setlocale (LC_ALL, "Rus");
    int i,x,k,a[451], b1[100],b2[100],b3[100],b4[100],b5[100];
    srand(6737);
    printf ("%d", (49-48)/2);
    /*
    form(a,1);
    for (i=1;i<100;i++)
    {
        //srand(1047*i);
        //n=i*50;

        if (rand()%2)
            x=a[(rand()+29)%n];
        else x=rand()%(2*n);
        // printf ("\nx = %d",x);
        b1[i]=n_lin(a,x,n);
        a[n]=x;
        b2[i]=n_qlin(a,x);

    }

    printf ("\n\n");
    for (i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf ("\n\n");
    */
    form(a,2);
    for (i=1;i<10;i++)
    {
        if (rand()%2)
            x=a[rand()%n];
        else x=rand()%n;//printf ("\n%d",x);
        k=0;

   //     u_lin(a,x,k,n,&k); b3[i]=k; k=0;
   //       u_bin(a,x,n,&k); b4[i]=k;k=0;
        u_blok (a,x,n,&k);// b5[i]=k;
        printf ("\nk = %d",k);
        printf ("\n\n");
    }
    //output(a);
/*
    printf ("b1");
    m(b1); output (b1);
       printf ("\nb2");
    m(b2); output (b2);

    printf ("\nb3");
    m(b3); output (b3);   */
//    printf ("\nb4");
//     m(b4); output (b4);
    //printf ("\nb5");
    //m(b5);// output (b5);

}
void output (int *b)
{
    printf ("\n\n");
    int i;
    for(i=1;i<100;i++)
        printf ("%d  ",b[i]);
}
void m (int *b)
{
    int i,s=0,max=b[1];
    for (i=1;i<100;i++)
    {
        s+=b[i];
        if (b[i]>max)
            max=b[i];
    }
    s/=100;
    printf ("\nСреднее = %d\nМаксимальное = %d",s,max);
}

int u_lin (int *a, int x,int i, int n, int *k)
{
    *k=i;
    //int i;
    //printf ("\nuli = %d\n",i);
    for (;i<n && a[i]<x;i++);
    *k=i-*k;
    if (i<n)
        return i;
    else
        return 0;
}

int u_blok (int *a, int t, int n,int *k)
{
    int i,x,j,f,p;
    j=x=sqrt(n);
    *k=1;
    for (i=0;i<j;i++)
    {
        (*k)++;
        if (a[j*i+x]>t)
        {
            printf ("\n1) j*i+x = %d   k = %d",j*i+x, *k);
            p=u_lin (a, t, j*i+1, j*i+x-1, &f);
             printf ("\nk = %d  f = %d",*k,f);
             printf ("\n1) j*i+1 = %d   j*i+x-1 = %d",j*i+1, j*i+x-1);
            *k+=f;
            return p;
        }
        else
            if (a[j*i+x]==t)
            {
                printf ("\n2) j*i+x = %d   k = %d",j*i+x, *k);
                return (j*i+x);
            }
        printf ("\n3) j*i+x = %d  k = %d",j*i+x, *k);
    }
    p=u_lin (a,t,x*x+1,n,&f);
    printf ("\nk = %d  f = %d",*k,f);
    *k+=f;
    return(p);
}

void form (int a[], int k)
{
    int i;
    switch (k)
    {
    case 1:
        srand(1022);
        for (i=0;i<n;i++)
            a[i]=i+rand()%n;

        break;
    case 2:
        for (i=0;i<n;i++)
            a[i]=i;
    }

}
