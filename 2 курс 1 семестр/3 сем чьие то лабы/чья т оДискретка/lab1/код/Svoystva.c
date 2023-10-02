#include <stdio.h>
#include "operations.h"
#include "svoystva.h"

int reflex(int **a, size_t n)
{
    int f = 1,i = 0;
    while (i < n && f)
        f = a[i][i++];
    return f;
}
int anti_reflex(int **a, size_t n)
{
    int f = 1, i = 0;
    while (i < n && f)
        f = !a[i][i++];
    return f;
}
int symmetr(int **a, size_t n)
{
    int f = 1,i = 0,j;
    while (i < n && f)
    {
        j = 0;
        while (j < n && f)
        {
            f = a[i][j] == a[j][i];
            j++;
        }
        i++;
    }
    return f;
}
int anti_symmetr(int **a, size_t n)
{
    int f = 1,i = 0,j;
    while (i < n && f)
    {
        j = 0;
        while (j < n && f)
        {
            f = a[i][j] != a[j][i];
            j++;
        }
        i++;
    }
    return f;
}
int transit(int **a, size_t n)
{
    int f = 1,x = 0,y,z;
    while (x < n && f)
    {
        y = 0;
        while (y < n && f)
        {
            z = 0;
            f = 0;
            while (z < n && !f)
            {
                f = a[x][y] & a[x][z] & a[z][y];
                z++;
            }
            y++;
        }
        x++;
    }
    return f;
}
int anti_transit(int **a, size_t n)
{
    int f = 1,x = 0,y,z;
    while (x < n && f)
    {
        y = 0;
        while (y < n && f)
        {
            z = 0;
            f = 0;
            while (z < n && !f)
            {
                f = !a[x][y] & a[x][z] & a[z][y];
                z++;
            }
            y++;
        }
        x++;
    }
    return f;
}
int full(int **a, size_t n)
{
    int f = 1, x = 0,y;
    while (x < n && f)
    {
        y = 0;
        while (y < n && f)
        {
            if (y != x)
                f = a[x][y] || a[y][x];
                y++;
        }
        x++;
    }
    return f;
}
int tolerant(int **a, size_t n)
{
    return reflex(a,n) && symmetr(a,n);
}
int equival(int **a, size_t n)
{
    return reflex(a,n) && symmetr(a,n) && transit(a,n);
}
int poryadok(int **a, size_t n)
{
    return anti_symmetr(a,n) && transit(a,n);
}
