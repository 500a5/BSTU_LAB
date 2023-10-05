
#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    int i, N=10+1;
    int **r;
    r=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        r[i]=(int *)calloc(N,sizeof(int));
    int **b;

    form_R(r, N); printf ("\nОтношение R\n"); output (r,N);

}
void decision (int **a, int **b, int **c, int **d, int N)
{
    int i;
    //выделение памяти для вспомогательных матриц
    int **e;
    e=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        e[i]=(int *)calloc(N,sizeof(int));
    int **g;
    g=(int **)calloc(N,sizeof(int*));
    for (i=0;i<N;i++)
        g[i]=(int *)calloc(N,sizeof(int));
    compose (b,b,e,N);
    compose (a,e,d,N); //output (e,N);
    clear (e,N);
    add(c,e,N);
    subs(d,e,g,N); output (g,N);
    clear (e,N); clear (d, N);
    resort (c,e,N);
    unit(g,e,d,N);
}
int form_R (int **a, int N)
{
    int x,y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            if ((x%3==0 && y%3==0) || (x%5==0 && y%5==0) || (x==y))
                a[x][y]=1;
    return 0;
}

int form_B (int **b, int N)
{
    int x,y;
    for (y=1;y<N;y+=2)
        for (x=2;x<N;x+=2)
                b[x][y]=1;
    return 0;
}

int form_C (int **c, int N)
{
    int x,y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            if (x*y%3==0)
                c[x][y]=1;
    return 0;
}

//проврка на равенство
int equal (int **a, int **b, int N)
{
    int x,y,f=1;
    for (x=1;(x<N)&&(f);x++)
        for (y=1;(y<N)&&(f);y++)
            f=(a[x][y]==b[x][y]);
    return f;
}
//проверка на включение
int incl (int **a, int **b, int N)
{
    int x,y,f=1;
    for (x=1;(x<N)&&(f);x++)
        for (y=1;(y<N)&&(f);y++)
            f=(a[x][y]<=b[x][y]);
    return f;
}
//объединение
void unit (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[x][y] || b[x][y];
}

//пересечение
void cross (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[x][y] && b[x][y];
}

//разность
void subs (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y] = a[x][y] > b[x][y];
}

//симметрическая разность
void symm_subs (int **a, int **b, int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y] = (a[x][y]>b[x][y]) || (b[x][y]>a[x][y]);
}

//дополнение
void add (int **a,int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=!a[x][y];
}

//обращение
void resort (int **a,int **res, int N)
{
    int x, y;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
            res[x][y]=a[y][x];
}

//композиция
void compose (int **a,int **b, int **res, int N)
{
    int x, y, z;
    for (x=1;x<N;x++)
        for (y=1;y<N;y++)
        {
            res[x][y]=0;
            for(z=1;z<N;z++)
                res[x][y]=res[x][y] || a[x][z] && b[z][y];
        }
}

void output (int **a, int n)
{
    int x,y;
    for (x=1;x<n;x++)
    {
        for (y=1;y<n;y++)
            printf ("%d  ",a[x][y]);
        printf("\n");
    }
}

void clear (int **a, int n)
{
    int x,y;
    for (x=0;x<n;x++)
        for (y=0;y<n;y++)
            a[x][y]=0;
}

//рефлексивность
int refl (int **a, int N)
{
    int i;
    for (i=1;i<N && a[i][i];i++);
    if (i==N)
        printf ("\nОтношение рефлексивно\n");
    else
        printf ("\nОтношение не рефлексивно\n");
    return (i==N);
}
//антирефлексивность
int arefl (int **a, int N)
{
    int i;
    for (i=1;i<N && !a[i][i];i++);

    if (i==N)
        printf ("\nОтношение антирефлексивно\n");
    else
        printf ("\nОтношение не антирефлексивно\n");
    return (i==N);
}
//симметричность
int simm (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=x+1;y<N && fl;y++)
            fl=a[x][y]==a[y][x];
    if (fl)
        printf ("\nОтношение симметрично\n");
    else
        printf ("\nОтношение не симметрично\n");
    return fl;
}
//антисимметричность
int asimm (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N-1 && fl;x++)
        for (y=x+1;y<N && fl; y++)
            fl= a[x][y]!=a[y][x];
    if (fl)
        printf ("\nОтношение антисимметрично\n");
    else
        printf ("\nОтношение не антисимметрично\n");
    return fl;
}
//транзитивность
int tranz (int **a, int N)
{
    int x,y,z,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=1;y<N && fl;y++)
            for(z=1;z<N && fl;z++)
                fl=!((a[x][z]&&a[z][y]))||a[x][y];
    if (fl)
        printf ("\nОтношение транзитивно\n");
    else
        printf ("\nОтношение не транзитивно\n");
    return fl;
}

//антитранзитивность
int atranz (int **a, int N)
{
    int x,y,z,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=1;y<N && fl;y++)
            for(z=1;z<N && fl;z++)
                fl=((a[x][z]&&a[z][y]))||a[x][y];
    if (fl)
        printf ("\nОтношение антитранзитивно\n");
    else
        printf ("\nОтношение не антитранзитивно\n");
    return fl;
}

//полнота
int poln (int **a, int N)
{
    int x,y,fl=1;
    for (x=1;x<N && fl;x++)
        for (y=x+1;y<N && fl;y++)
            fl = (a[x][y] || a[y][x]);
    if (fl)
        printf ("\nОтношение полно\n");
    else
        printf ("\nОтношение не полно\n");
    return fl;
}
int check (int **a, int N)
{
    int r,t,s,ar,as,at,p;
    r=refl(a,N);
    ar=arefl(a,N);
    s=simm(a,N);
    as=asimm(a,N);
    t=tranz(a,N);
    at=atranz(a,N);
    p=poln(a,N);
    if(s&&r)
        printf ("\nОтношение толерантности\n");
    if (r&&s&&t)
        printf("\nОтношение эквивалентности\n");
    if (as&&t)
        printf("\nОтношение порядка\n");
    if (as&&t&&r)
        printf("\nОтношение нестрогого порядка\n");
    if (as&&t&&ar)
        printf("\nОтношение строгого порядка\n");
    if (as&&t&&p)
        printf("\nОтношение линейного порядка\n");
    if (as&&t&&r&&p)
        printf("\nОтношение нестрогого линейного порядка\n");
    if (as&&t&&ar&&p)
        printf("\nОтношение строгого линейного порядка порядка\n");
}
