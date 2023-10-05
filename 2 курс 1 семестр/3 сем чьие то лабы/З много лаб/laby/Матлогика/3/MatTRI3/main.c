#include <stdio.h>
#include <stdlib.h>
int Matr_poiskblyat (int **M, int n, int m, int i, int *f);
void osnovnaya (int **M, int n, int m);
void copy_z (int *z, int **M, int **V, int n, int m, int *g);



void osnovnaya (int **M, int n, int m)
{
    int i, j, k,g=0,h, f=1;
    int **V,*z;
    V=(int **)calloc(m,sizeof(int*));
    for (i=0;i<m;i++)
        V[i]=(int *)calloc(n,sizeof(int));
    z=(int *)calloc(m,sizeof(int));
    while (f)
    {
        for(i=0;i<m;i++)
        {
            k=Matr_poiskblyat(M,n,m,i,&j);//приделать вывод  //i-я и j-я строки, которые различаются по k-му элементу
            if (k)
            {
                for (h=0;h<n;h++)
                    V[g][h]=M[i][h];
                V[g][k]=0;
                g++;
                z[i]=z[j]=1;
            }
        }

int Matr_poiskblyat (int **M, int n, int m, int i, int *f)
//n - количество переменных
//m - количество строк
//f - найденная строка
//k - найденная позиция
{
    int j, k;

    for (j=i+1;j<n;j++)
    {
        *f=search(M,m,i,j,&k);
        if(*f)
            return k;
    }
    return 0;
}
        copy_z(z,M,V,n,m,g);
        for (i=0;i<n;i++)
            z[i]=0;
    }
}

void copy_z (int *z, int **M, int **V, int n, int m, int *g)
{
    int i,j,k=0;
    for (i=0;i<m;i++)
    {
        if(!z[i])
        {
            for (j=0;j<n;j++)
                V[*g][j]=M[i][j];
            (*g)++;
        }
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
