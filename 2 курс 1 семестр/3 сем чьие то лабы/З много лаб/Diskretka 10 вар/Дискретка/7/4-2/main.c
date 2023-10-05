//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

void alg_Kraskala(int **a, int *B, int n)
{
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (a[i][j])
            {
                if(B[i]!=B[j])
                {
                    int t=B[j];
                    B[j]=B[i];
                    for(int p=0; p<n ;++p)
                        if (B[p]==t)
							B[p]=B[i];
                }
            }
}

int proverka(int *B, int n)
{
    int *A;
    A=(int*)calloc(n,sizeof(int));
    int k=0;
    for(int i=0;i<n; ++i)
    {
        if (A[i]==0)
        {
            k++;
            A[i]=1;
            int t=B[i];
            for (int j=i+1; j<n; ++j)
               if(B[j]==t) A[j]=1;
        }
    }
    return k;
}

vector <int> e;

void  razbienie(int **a, int n, int k, int t)
{
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (a[i][j]==1)
            {
                int *B1;
                B1=(int*)calloc(n,sizeof(int));
                for(int i=0; i<n;++i)
                    B1[i]=i;
                a[i][j]=0;
                a[j][i]=0;
                e.push_back(i);
                e.push_back(j);
                if (++t==k)
                {
                    alg_Kraskala(a,B1,n);
                    if(proverka(B1,n)==3)
                    {
                        puts("Разбиение на 3 связные компоненты достигнуто");
                        printf("Удалили ребра\n");
                        for (int z = 0; z < e.size(); z += 2)
                        {
                            cout << e[z] << '-' << e[z+1] << ' ';
                        }
                        cout << endl;
                        for(int p=0; p<n; p++)
                            printf("%d",B1[p]);
                        printf("\n");
                        exit(0);
                    }
                }
                else
					razbienie(a,n,k,t);
                e.pop_back();
                e.pop_back();
                a[i][j]=1;
                a[j][i]=1;
            }
}

int main()
{
    setlocale(LC_CTYPE, "Rus");
    /*
    1. Удалить ребро
    2. Если t == k, проверить, 3 ли компоненты.
    3. Если 3 компоненты, то выводим и выходим.
    4. Запускаем рекурсию!
     */
    int n;
    puts("Введите количество вершин");
    scanf("%d",&n);
    int *B;
    B=(int*)calloc(n,sizeof(int));
    for(int i=0; i<n;++i)
        B[i]=i;
    puts("Введите матрицу смежности");
    int **a;
    a=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; ++i)
        a[i]= (int*)calloc(n,sizeof(int));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            scanf("%d",&a[i][j]);
    for(int k=1; k<n; k++)
        razbienie(a,n,k,0);
    return 0;
}
