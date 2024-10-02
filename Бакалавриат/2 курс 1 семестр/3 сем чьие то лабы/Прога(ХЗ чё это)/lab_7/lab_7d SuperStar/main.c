#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>


void readMatr(int **,int,int);
void writeMatr(int **,int,int);

int **getMemory(int,int);
void freeMemory(int **,int,int);

int test_Matr(int **, int **, int, int);
int test_str(int *, int *, int);


int main()
{
    int m,n;
    printf("Enter M: ");
    scanf("%d",&m);
    printf("Enter N: ");
    scanf("%d",&n);


    int **a;
    a = getMemory(m,n);
    int **b;
    b = getMemory(m,n);

    readMatr(a,m,n);
    readMatr(b,m,n);

    if(test_Matr(a, b, m, n))
        printf("YES!\n");
    else
        printf("No");

    freeMemory(a,m,n);
    freeMemory(b,m,n);
    return 0;
}

int **getMemory(int m, int n){
    int i;
    int **a = (int **) malloc(sizeof(int *) * m);
    for(i = 0; i < m; i++)
        a[i] = (int *) malloc(sizeof(int) * n);

    return a;
}

void freeMemory(int **a,int m, int n){
    int i;
    for(i = 0; i < m; i++)
        free(a[i]);
    free(a);
}

void readMatr(int **a,int m, int n){
    printf("----------------------------\n");
    int i,j;
    for(i = 0; i < m;i++)
        for(j = 0; j < n;j++)
            scanf("%d",&a[i][j]);
}

void writeMatr(int **a,int m, int n){
    printf("----------------------------\n");
    int i,j;
    for(i = 0; i < m;i++){
        for(j = 0; j < n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}



int test_Matr(int **a, int **b, int m, int n){

    int i = 0,j;//счетчики
    int flag = 1;//флаг

    while((i < m) && flag){
        j = 0;
        flag = 0;
        while((j < m) && (!flag)) {
            flag = test_str( a[i] , b[j] , n);
            j++;
        }
        i++;
    }
    return flag;
}

 int test_str(int *a, int *b, int n){
    int flag = 1;//
    int z = 0;//
        while((z < n) && (flag)){
            if (a[z] != b[z])
                flag = 0;
            z++;
            }
    return flag;
}
