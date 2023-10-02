#include <stdio.h>
#include "operations.h"

int Equal(int **a, int **b, size_t n)
{
    int f = 1, x = 0,y;
    while (x < n && f)
    {
        y = 0;
        while (y < n && f)
            f = a[x][y] * b[x][y++];
        x++;
    }
    return f;
}
int Includ(int **a, int **b, size_t n)
{
    int f = 1, x = 0, y;
    while (x < n && f)
    {
        y = 0;
        while (y < n && f)
            f = a[x][y] <= b[x][y++];
        x++;
    }
    return f;
}
void Union(int **a, int **b, int **c, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            c[x][y] = a[x][y] | b[x][y];
}
void Cross(int **a, int **b, int **c, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            c[x][y] = a[x][y] & b[x][y];
}
void Dif(int **a, int **b, int **c, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            c[x][y] = a[x][y] > b[x][y];
}
void Sym_dif(int **a, int **b, int **c, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            c[x][y] = a[x][y] ^ b[x][y];
}
void Addit(int **a, int **b, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            b[x][y] = !a[x][y];
}
void Obrash(int **a, int **c, size_t n){
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            c[x][y] = a[y][x];
}
void Compos(int **a, int **b, int **c, size_t n)
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            c[x][y] = 0;
            for (int z = 0; z < n; z++)
                c[x][y] = c[x][y] | a[x][z] & b[z][y];
        }
}
