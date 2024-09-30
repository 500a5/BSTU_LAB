#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

void des_true (int **a, int m, int n)
{
    int i,j,k,fl=0,g,res=1,t=0;
    int *pa; int *pb;
    pa=(int*)calloc(m,sizeof(int)); //для НФ
    pb=(int*)calloc(n,sizeof(int)); //для переменных
    k=(int)pow(2,n);
    int **b;
    b=(int**)calloc(m,sizeof(int*));
    for (i=0;i<m;i++)
        b[i]=(int *)calloc(m,sizeof(int));
    for (i=0;i<k;i++)
    {
        for (j=0;j<m;j++)
            for (g=0;g<n;g++)
            {
                if (a[j][g]==0)
                    b[j][g]=-1;
                if (a[j][g]==-1)
                    b[j][g]=!pb[g];
                if (a[j][g]==1)
                    b[j][g]=pb[g];
            }
        for (j=0;j<m;j++)
        {   pa[j]=0;
            for (g=0;g<n;g++)
                if (b[j][g]>=0)
                    pa[j]=pa[j]||b[j][g];
        }
        res=1;
        for (j=0;j<m;j++)
            res=pa[j]&&res;
        if (res)
        {
            if (!fl)
            {
                printf ("\nИнтерпретации, при которых формула принимает истинное значение :\n");
                fl=1;
            }
            for (j=0;j<n;j++)
                printf ("%d  ", pb[j]);
            printf ("\n");
        }
        bin_vect(pb,n);
    }
    if (fl==0)
        printf ("\nИнтерпретации, при которых формула принимает истинное значение, нет\n");
}

void bin_vect (int *a, int n)
{
    int i,j=1,fl=a[n-1];
    i=n-1;
    a[i]=!a[i];
    i--;
    if (fl)
    {
        if (a[i]==0)
        {
            a[i]=1;
            i--;
        }
        else
        {
            while (a[i]==1 && i>=0)
            {
                a[i]=0;
                i--;
            }
            a[i]=1;
        }
    }
}
