#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int n=450;

int main()
{
    setlocale (LC_ALL, "Rus");
    int i,x,k,a[451], b1[100],b2[100],b3[100],b4[100],b5[100];
    srand(6737);

    for (i=1;i<100;i++)
    {
        form(a,1);
        if (rand()%2)
            x=a[(rand()+29)%n];
        else x=rand()%(2*n);
        b1[i]=n_lin(a,x,n);
        form(a,1);
        a[n]=x;
        b2[i]=n_qlin(a,x);
    }

    form(a,2);
    for (i=1;i<100;i++)
    {
        if (rand()%2)
            x=a[rand()%n];
        else x=rand()%n;

        u_lin(a,x,k,n,&k); b3[i]=k;
        u_bin(a,x,n,&k); b4[i]=k;
        u_blok (a,x,n,&k); b5[i]=k;
    }

    printf ("\nНеупорядоченный массив\n\nЛинейный поиск");
    m(b1);
    printf ("\nБыстрый линейный поиск");
    m(b2);
    printf ("\n\n\nУпорядоченный поиск\n\nБыстрый линейный поиск");
    m(b3);
    printf ("\n\nБинарный поиск");
    m(b4);
    printf ("\n\nБлочный поиск");
    m(b5);

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
int n_lin (int *a, int x, int n)
{
    int i;
    for (i=0;i<n && a[i]!=x;i++);
    return i;
}

//необходимо a[n]:=х
int n_qlin (int *a, int x)
{
    int i;
    for (i=0;i<n && a[i]!=x;i++);
    return i;
}

int u_lin (int *a, int x,int i, int n, int *k)
{
    *k=i;
    for (;i<n && a[i]<x;i++);
    *k=i-*k;
    if (i<n)
        return i;
    else
        return 0;
}
int u_bin (int *a, int x, int n,int *k)
{
    int l, r,m;
    l=0;
    r=n-1;
    m=l+(r-l)/2;
    while (l<r)
    {
        (*k)++;
        if (a[m]==x)
            return m;
        if (a[m]<x)
            l=m+1;
        else
            r=m;
        m=l+(r-l)/2;
    }
    return -(1+l);
}

int u_blok (int *a, int t, int n,int *k)
{
    int i,x,j,f,p;
    j=x=sqrt(n);
    *k=1;
    for (i=0;i<j;i++)
    {
        (*k)++;
        if (a[j*i+x-1]>t)
        {
             p=u_lin (a, t, j*i, j*i+x-2, &f);
             *k+=f;
             return p;
        }
        else
            if (a[j*i+x-1]==t)
                return (j*i+x-1);
    }
    if (a[n-1]>t)
    {
             p=u_lin (a, t, j*i, j*i+x-2, &f);
             *k+=f;
             return p;
    }
    return -1;
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
