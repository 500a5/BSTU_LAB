#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

int line_neup (int *a, int x, size_t n, int *k)
{
    int i=0;
    while ((i<n) && (a[i]!=x))
    {
        i++;
        (*k)+=2;
    }
     (*k)+=3;
    if (i<n)
        return 1;
    else
        return 0;

}


int speed_line_neup (int *a, int x, size_t n, int *k)
{
    int i=0;
    while (a[i]!=x)
    {
        i++;
        (*k)++;
    }
    (*k)+=2;
    if (i==n)
        return 0;
    else
        return 1;

}

int line_upor (int *a, int x, size_t n, int *k)
{
    int i=0;
    while (a[i]<x)
    {
        i++;
        (*k)++;
    }
    (*k)+=3;
    if (i==n || a[i]!=x)
        return 0;
    else
        return 1;
}

int binary_upor (int *a, int x, size_t n, int *k)
{
    int left = 0, right = n, midl;
    while (left<=right) //1
    {
        midl = (left+right)/2;
        if (a[midl]==x)
        {
            (*k)++;
            return 1;
        }
        else
        {
            (*k)++;
            if (x < a[midl])
                right = midl-1;
            else
                left = midl+1;
        }
        (*k)++;
    }
    (*k)++;
    return 0;
}

int blocs_upor (int *a, int x, size_t n, int *k)
{
    int i, j=(int)sqrt(n);
    i=j-1;
    while ((i<=(j*j-1)) && (a[i]<x))
    {
        i+=j;
        (*k)+=2;
    }
    (*k)+=4;
    if ((i==(j*j-1)) && (a[i]==x)) return i;
    else if ((i<(j*j-1)) && (a[i]>x))
        {
            i-=j;
            j=i+j;
            (*k)+=2;
            while ((i<j) && (a[i]!=x))
            {
                i++;
                (*k)+=2;
            }
            (*k)+=3;
            if (i<n) return i;
            else return -1;
        }
    else
    {
        i=i-j+1;
        while ((i<n) && (a[i]!=x))
        {
            i++;
            (*k)+=2;
        }
        (*k)+=3;
        if (i<n) return i;
        else return -1;
    }
}
