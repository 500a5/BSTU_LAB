#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10
int W[N];
int le;
typedef struct point
{
    int a, b;
} point;
point S[20];
int main()
{
    setlocale(LC_ALL, "Rus");
    int n = 4, m = 5; //размеры матриц смежности

    char s[]="10.txt";
    FILE *F = fopen(s, "r");
    int v, u, i, j;
    int **sm = (int**)calloc(m, sizeof(int*));
    for(v=0; v<m; v++)
        sm[v]=(int*)calloc(m,sizeof(int));

    int **sm1 = (int**)calloc(m, sizeof(int*));
    for(v=0; v<m; v++)
        sm1[v]=(int*)calloc(m,sizeof(int));

    for (v=0; v<n; v++)
        for (u=0; u<m; u++)
            fscanf(F, "%d", &sm[v][u]);
    printf("Матрица смежности:\n");
    OutputMatr(sm, n, m);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            sm1[j][i] = sm[i][j];
    fclose(F);

    printf("Матрица смежности:\n");
    OutputMatr(sm1, m, n);



    point x, start;
    start.a = start.b = 0;
    sm[0][1] = -1;
    le = 0;
    for (j = 0; j <= 10 ; j++)
        printf ("%d-%d ",S[j].a,S[j].b);
  //  W[0] = 1;

    MakeCycles(sm,sm1,n,m,3,1,1);

    return 0;

}

void OutputMatr(int **a, size_t n, size_t m)
{
    int i, j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void OutputMarch (int* a, size_t n)
{
    int i;
    printf("[ ");
    for (i=0; i<n; i++)
    {
        printf("%i ", a[i]);
        //if (i!=n-1)
          //  printf(",  ");
    }
    printf("]\n");
}

void MakeMarshouts (int **g, size_t n, size_t l, int i, int x)
// g - матрица смежности рафа, n - размер, l -длина марш.
// заполняемое место = i
{
    W[i-1] = x;
    int j;
    for (j=0; j<n; j++)
    {
       if (g[x-1][j])
        {
           if (i!=l)
                MakeMarshouts(g, n, l, i+1, j+1);
           else
           {
               W[i]=j+1;
               OutputMarch(W, l+1);
           }
        }
    }
}

void MakeCycles (int **g, int **a, size_t n, size_t m, size_t l, int i, int v)
// g - матрица смежности рафа, n - размер, l -длина марш.
// заполняемое место = i
{

    int x;
    for (x=0; x<n; x++)
    {
        if (g[v-1][x] && CheckEl(i,x+1))
        {
            W[i-1] = v;
            if (x+1 == W[0] && i >= 3 && i%2 == 1)
            {
               W[i]=x+1;
               OutputMarch(W, i+1);
            }
            else
                MakeCycles (a,g,m,n,l,i+1,x+1);
        }
    }
}
void MakeCycles2 (int **g, size_t n, size_t m, size_t l, int i, int v)
// g - матрица смежности рафа, n - размер, l -длина марш.
// заполняемое место = i
{
    W[i-1] = v;
    int x;
    for (x=0; x<n; x++)
    {
        if (g[x][v-1] && CheckEl(i,x+1))
        {
            if (x+1 == W[0] && i >= 3 && i%2 == 1)
            {
               W[i]=x+1;
               OutputMarch(W, i+1);
            }
            //else
               // MakeCycles1 (g,n,m,l,i+1,x+1);
        }
    }
}


int CheckEl(int len, int a)
{
    int i;
    for (i=1;i<len;i++)
        if(W[i]==a)
            return 0;
    return 1;
}
//f = 1 - string, f = 2 - column
// всегда начинать искать со строк
void MakeCyclesPoint(int **T, int n, int m, int p, int f, point x, point start)
{
    if (isExit() || le)
        return;
    S[p] = x;


    int i,j;
    if (f == 1)
    {
        for (i = 0; i < n; i++)
        {
        //    system("pause");
            printf ("\n%d (%d,%d) %d %d %d    ",CheckStr(x.a,p), x.a, x.b, i, p, f);
            for (j = 0; j <= p ; j++)
                printf ("%d-%d ",S[j].a,S[j].b);
            if (T[x.a][i] && i != x.b)
            {
                x.b = i;
                MakeCyclesPoint(T,n,m,p+1,(f+1)%2,x, start);
            }
        }
    }
    else
    if (f == 0)
    {
        for (i = 0; i < n; i++)
        {
       //     system("pause");
            printf ("\n%d (%d,%d) %d %d %d    ",CheckStr(x.a,p), x.a, x.b, i, p,f);
            for (j = 0; j <= p ; j++)
                printf ("%d-%d ",S[j].a,S[j].b);
            if (T[i][x.b] && i != x.a)
            {
                if (S[p].a == S[0].a && S[p].b == S[0].b && p > 3)
                {
                    for (j = 0; j < p ; j++)
                        printf ("%d-%d 1 ",S[j].a,S[j].b);
                    printf ("\n");
                    le = 1;
                }
                else //(CheckStr(x.a,p) && i != start.b)
                {
                    x.a = i;
                    MakeCyclesPoint(T,n,m,p+1,(f+1)%2,x, start);
                }
            }
        }
    }

}
int isExit()
{
    int i;
    for (i = 1; i < 10; i++)
        if (S[i].a == S[0].a && S[i].b == S[0].b)
        {
            le = 1;
            return 1;
        }

    return 0;
}
int CheckStr (int x, int len)
{
    int i;
    for (i = 0; i < len; i++)
        if (S[i].a == x || S[i].b == x)
            return 0;
    return 1;
}
