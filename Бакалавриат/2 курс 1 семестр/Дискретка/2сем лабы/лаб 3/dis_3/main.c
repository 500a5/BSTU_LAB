#include <stdio.h>
#include <stdlib.h>

#define N 10
int** get_mem(){
    int n = N + 1;
    int ** res = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n ; i++)
        res[i] = (int *)malloc(n * sizeof(int));

    return res;
}

void free_mem(int **a){
    int n = N + 1;
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

void get_A(int **a){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if((x % 3==0 && y % 3==0 )|| (x % 5==0 && y % 5==0 )|| (x==y))
                a[x][y] = 1;
            else
                a[x][y] = 0;
}

void write_arr(int **a){
    int i,j;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
}

void write_split(int **A, int x){
    printf("\n{ ");
    for(int y = 1; y <= N; y++){
        if(A[x][y] != 0)
            printf("%d ", y);
    }
    printf("}");
}

int check_equal(int **A, int x){
    int y = 1, z, f = 0;
    while((y < x) && (f != 10)){
        f = 0;
        z = 0;
        while((z < 10) && (x != y))
        {
            if(A[x][z] == A[y][z])
                f++;
            z++;
        }
        y++;
    }
    if(f == 10)
        return 1;
    else{
        return 0;
    }

}

void split_matr(int **A){
    int x;
    for (x = 1; x <= N; x++){
        if((check_equal(A, x) == 0))
            write_split(A, x);
    }
}


int main(){
    int **a = get_mem();
    get_A(a);
    printf("Матрица:\n");
    write_arr(a);
    printf("\n");
    printf("Разбиение:");
    split_matr(a);
    free_mem(a);

    return 0;
}

