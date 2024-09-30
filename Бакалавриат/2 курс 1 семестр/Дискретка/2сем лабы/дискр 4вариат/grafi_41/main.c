#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void OutputMatr(int **a, size_t n);
int IsMarsh (int **a, size_t n);
int IsChikle (int **a, size_t n);

int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 7; //размеры матриц смежности
   // printf("input name of file: ");
    //char s[20];
    //gets(s);
    char s1[]="Matr2.txt";
    FILE *F = fopen(s1, "r");
    int v, u;
    int **matr = (int**)calloc(n, sizeof(int*));
    for(v=0; v<n; v++)
        matr[v]=(int*)calloc(n,sizeof(int));
    for (v=0; v<n; v++)
        for (u=0; u<n; u++)
            fscanf(F, "%d", &matr[v][u]);
    fclose(F);

    printf("Матрица смежности:\n");
    OutputMatr(matr, n);
    printf("\n %d", IsChikle(matr, n));

    return 0;
}

void OutputMatr(int **a, size_t n)
{
    int i, j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int IsMarsh (int **a, size_t n)
{
    int i=0, l;
    printf("Длина маршрута: ");
    scanf("%i",&l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++)
        scanf("%i",&m[i]);
    if(m[0]==m[l-1])
        return 0;
    i=0;
    while (i<l-1 && (a[m[i]-1][m[i+1]-1]!=0))
        i++;
    if (i==l-1)
        return 1;
    else
        return 0;
}


int IsChikle (int **a, size_t n)
{
    int i=0, l;
    printf("Длина маршрута: ");
    scanf("%i",&l);
    int *m=(int*)calloc(l, sizeof(int));
    for (i=0;i<l;i++)
        scanf("%i",&m[i]);
    if(m[0]!=m[l-1])
        return 0;
    while (i<l-1)
    {
        if(a[m[i]-1][m[i+1]-1]==0)
            return 0;
        i++;
    }
    return 1;
}




