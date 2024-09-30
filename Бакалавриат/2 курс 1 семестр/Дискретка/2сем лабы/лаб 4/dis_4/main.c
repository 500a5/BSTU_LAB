#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x,y;
}Point;

int** get_mem(int n){

    int ** res = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i <= n ; i++)
        res[i] = (int *)malloc(n * sizeof(int));

    return res;
}

void free_mem(int **a, int n){
    for (int i = 0; i <= n; i++)
        free(a[i]);
    free(a);
}

void get_matr(int **a, Point *M, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if((M[i].x - M[j].x) <= (M[j].y - M[i].y)) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
}

void write_arr(int **a,int n){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void mn_T1(Point *M1)
{
    int k = 0;
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
        {
            M1[k].x = i;
            M1[k].y = j;
            k++;
        }
}

void mn_T2(Point *M2)
{
    int k = 0;
    for (int i = -2; i < 3; i++)
        for (int j = abs(i) - 2; j <= abs(abs(i) -2); j++)
        {
            M2[k].x = i;
            M2[k].y = j;
            k++;
        }
}



void dominations(int **a, int **b, int n)
{
    int t, z, i, j;

    for (j = 0; j < n; j++)
        for (i = 0; i < j; i++)
            if (a[i][j] == 1)
            {
                t = 0;
                for (z = i + 1; (z < j && t == 0); z++)
                    t = a[i][z] && a[z][j];
                b[i][j] = !t;
            }
}

int check_otr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            return 0;
    return 1;
}

void sort(int **a, int n)
{
    int *w = calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i] += a[j][i];

    int k = 0;
    while (!check_otr(w,n))
    {
        printf("%i level > ", k);
        for (int i = 0; i < n; i++)
            if(w[i] == 0)
            {
                printf("%i ",i+1);
                w[i] = -(k + 1);
            }
        for (int i = 0; i < n; i++)
            if (w[i] == -(k+1))
                for (int j = 0; j < n; j++)
                    w[j] -= a[i][j];
        k++;
        printf("\n");
    }
}




int main() {
    int n1=9,n2=13;
    Point M1[n1],M2[n2];
    mn_T1(M1);
    mn_T2(M2);
    int **a=get_mem(n2),
        **b=get_mem(n2);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n1; ++j) {
            b[i][j]=0;
        }
    }
    get_matr(a,M1,n1);

    dominations(a,b,n1);
    printf("M1:\n");
    //write_arr(b,n1);
sort(b,n1);
    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n2; ++j) {
            b[i][j]=0;
        }
    }
    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < n2; ++j) {
            a[i][j]=0;
        }
    }

    get_matr(b,M2,n2);

   dominations(b,a,n2);
    printf("M2:\n");
    sort(a,n2);
   // write_arr(a,n2);

    return 0;
}