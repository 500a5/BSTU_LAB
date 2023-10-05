#include <stdio.h>
#include <stdlib.h>

int line_neup (int *a, int x, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
      if (a[i]==x)
        return 1;
    }
    return 0;
}

int speed_line_neup (int *a, int x, size_t n)
{
    int i=0;
    a[n]=x;
    while (i<n)
    {
        if (a[i]==x)
            return 1;
        i++;
    }
    if (a[i]==a[n])
        return 0;
}

int line_upor (int *a, int x, size_t n)
{
    int i=0;
    while ((i<n)&&(a[i]<x))
    {
        if (a[i]==x)
            return 1;
        //if (a[i]>x)
           // return 0;
        i++;
    }
    return 0;
}

int binary_upor (int *a, int x, size_t n)
{
    int left = 0, right = n, midl;
    while (left<=right)
    {
        midl = (left+right)/2;
        if (a[midl]==x)
            return 1;
        if (x < a[midl])
            right = midl-1;
        else
            left = midl+1;
    }
    return 0;
}

int blocs_upor (int *a, int x, size_t n)
{
     int f=1, i=0, l;
     int z=(int)pow(n,(1/2));
     while ((i<=n)&&(f))
        {
            i=i+z;
            if (i>n) i=n;
            int r=i;
            l=i-3;
            if (x<a[i])
                {
                    while ((l<=r)&&(x!=a[l]))
                    l++;
                    f=0;
                    if (x==a[l])
                        return 1;
                }
        }
     return 0;
}











