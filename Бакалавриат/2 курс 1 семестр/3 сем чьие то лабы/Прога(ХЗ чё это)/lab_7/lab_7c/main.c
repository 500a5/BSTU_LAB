#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 2 //סעמכבצû

void readMatr(int [][N],int);
void writeMatr(int [][N],int);

void *getMemory(int);
void freeMemory(int (*)[N]);

int test_Matr(int *a, int *b, int m);
int test_str(int *a, int *b);


int main()
{
    printf("Enter M: ");
    int m;
    scanf("%d",&m);

    int (*a)[N];
    a = getMemory(m);

    int (*b)[N];
    b = getMemory(m);

    readMatr(a,m);
    readMatr(b,m);


    if(test_Matr(a, b, m))
        printf("Yes!");
    else
        printf("No");



    freeMemory(a);
    freeMemory(b);
    return 0;
}

void *getMemory(int m){
    return malloc(m*N*sizeof(int));
}

void freeMemory(int (*a)[N]){
    free(a);
}

void readMatr(int a[][N],int m){
    printf("--------------------------------\n");
    int i,j;
    for (i = 0; i < m; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
}

void writeMatr(int a[][N],int m){
    printf("--------------------------------\n");
    int i,j;
    for (i = 0; i < m; i++){
        for (j = 0; j < N; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

int test_Matr(int *a, int *b, int m){

    int i = 0,j;//סקועקטךט
    int flag = 1;//פכאד

    while((i < m) && flag){
        j = 0;
        flag = 0;
        while((j < N) && (!flag)) {

            flag = test_str(a + m*i, b + m*j);
            j++;
        }
        i++;
    }
    return flag;
}

 int test_str(int *a, int *b){
    int flag = 1;//
    int z = 0;//
        while((z < N) && (flag)){
            if (*(a + z) != *(b + z))
                flag = 0;
            z++;
            }
    return flag;
}
