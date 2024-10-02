#include <stdio.h>
#include <stdlib.h>
#define MaxRoute 1000
#define N 6
#include <locale.h>

void Graph(int g[][N])
{ FILE *f;
  f=fopen("1.txt","r");
  int i,j;
  while(!feof(f))
	{ for(i=0;i<N;i++)
	   { for(j=0;j<N;j++)
           { fscanf(f,"%i",&g[i][j]);
             printf("%i ",g[i][j]);
           }
		 printf("\n");
	   }
	}
  printf("\n");
  fclose(f);
}

void write(int *a)
{ int i;
  for(i=0;i<N;i++)
    printf("%i ",a[i]);
  printf("\n");
}

void deikstr(int v1, int v2, int g[][N], int T[], int V[])
{
    //v1 v2 - начальная и конечная вершины, g - граф
    //V - множество вершин орграфа
    // Т - массив для хранения дерева кратчайших путей
    //D = d(xi) - кратчайшее расстояние от вершины v1 к вершине xi
    int min,f,i;
    int D[N]; // минимальное расстояние
    for(i=0;i<N;i++)
    {
        D[i]=MaxRoute;
        V[i]=0;
        T[i]=-1;
    }
    D[v1]=0;
    V[v1]=1;
    T[v1]=0;
    while(v1!=v2 && f)
    {
        f=0;
        for(i=0;i<N;i++)
        {
            if(g[v1][i] && D[v1]+g[v1][i]<D[i])
            {
                D[i]=D[v1]+g[v1][i];
                T[i]=v1+1;
            }
        }
        min=MaxRoute;
        for(i=0;i<N;i++)
            if(V[i]==0 && min>D[i])
              {
                  min=D[i];
                  v1=i;
                  f=1;
              }
     V[v1]=1;
   }
}

void derevo(int V[], int T[], int v1, int v2)
{
    int i,j;
     int f=1;
    while(v1!=v2 ) //пока не дошли до заданной вершины
    {
        j=0;
        for(i=0; i<N, j==0; i++)
        {//j - не обнаружена нужная вершина
            //printf("!!");
          // int f=1;
            if(T[i]==v1 && V[i]==1)
            {
                printf("%i->%i\n", v1, i+1);
                j=i;
                f=0;
            }

            /*if (T[i]==-1 && V[i]==0 )
            {

                exit(1);
            }*/
        }
        if (f)
            {
                printf("error");
                return;
            }

            f=1;
       //printf("error");
     v1=j+1; //перейти к следую
    }
}

int deikstr2(int v1, int v2, int g[][N], int T[], int V[], int *dl)
{

    int min,f,i, j, tmp=(*dl);
    int D[N]; // минимальное расстояние
    for(i=0;i<N;i++)
    {
        D[i]=MaxRoute;
        V[i]=0;
        T[i]=-1;
    }
    D[v1]=0;
    V[v1]=1;
    T[v1]=0;
    while(v1!=v2 && f)
    {
        f=0;
        for(i=0;i<N;i++)
        {
           if(g[v1][i] && D[v1]+g[v1][i]<D[i])
           {
               D[i]=D[v1]+g[v1][i];
                T[i]=v1+1;
           }
        }
        min=MaxRoute;
        for(i=0;i<N;i++)
            if(V[i]==0 && min>D[i])
            {
                min=D[i];
                v1=i;
                f=1;
            }
            if (min==MaxRoute)                return 0;

        V[v1]=1;
    }
    //if (min==MAX)                return 0;
    //write(D);
    /*for(i = 0; i < N; i++)
        for(j = i+1; j < N; j++)
            if(D[i] == D[j] && D[i] != MAX )
                return 0;*/
    for(i = 0; i < N; i++)
        for(j = i+1; j < N; j++)
            if(D[i] == D[j] && D[i] != MaxRoute)
            {
                tmp+=min;
                (*dl)=tmp;
                return 1;
            }
   //tmp+=min;
  // (*dl)=tmp;
   return 0;
//   return 0;
}




int main()
{
    setlocale(LC_ALL, "Rus");
    int g[N][N];
    Graph(g);
    int T[N], T1[N];
    int V[N], V1[N];
    int i, v1, z, v2, dl=0;
    printf("vvod v1->z->v2\n");
    scanf("%i%i%i",&v1,&z,&v2);
    printf("\n");




    if (deikstr2(v1-1, z-1, g, T, V, &dl))
        {
            printf("Нет пути из %d в %d.\n", v1, z);
            return 0;
        }
    else
    {
        derevo(V, T, v1, z);
        if (deikstr2(z-1, v2-1, g, T1, V1, &dl))
            {
                printf("Нет пути из %d в %d.\n", z, v2);
                return 0;
            }
        else
            derevo(V1, T1, z, v2);
            printf("%i", dl);
    }

    return 0;
}
