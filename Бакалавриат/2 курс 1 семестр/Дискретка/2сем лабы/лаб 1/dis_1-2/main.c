#include <stdio.h>
#include <stdlib.h>

int **creating_matr_A(int **A)
{
    int x, y;
    A = (int**) malloc(10 * sizeof(int*));
    for(y = 0; y < 10; y++)
        A[y] = (int*) malloc(10 * sizeof(int));

    for(y = 1; y < 11; y++)
    {
        for(x = 1; x < 11; x++)
        {
            if((y % 2==0)&&(x+y<10))
                A[x-1][y-1] = 1;
            else{
                A[x-1][y-1] = 0;
            }
        }
    }

    return A;
}

int **creating_matr_B(int **B)
{
    int x, y;
    B = (int**) malloc(10 * sizeof(int*));
    for(y = 0; y < 10; y++)
        B[y] = (int*) malloc(10 * sizeof(int));

    for(y = 1; y < 11; y++)
    {
        for(x = 1; x < 11; x++)
        {
            if(y+2*x<20)
                B[x-1][y-1] = 1;
            else{
                B[x-1][y-1] = 0;
            }
        }
    }

    return B;
}

int **creating_matr_C(int **C)
{
    int x, y;
    C = (int**) malloc(10 * sizeof(int*));
    for(y = 0; y < 10; y++)
        C[y] = (int*) malloc(10 * sizeof(int));

    for(y = 1; y < 11; y++)
    {
        for(x = 1; x < 11; x++)
        {
            if(y>7 || x%3==0)
                C[x-1][y-1] = 1;
            else{
                C[x-1][y-1] = 0;
            }
        }
    }

    return C;
}

void print_matr(int **A)
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
            printf("%d ", A[x][y]);
        printf("\n");
    }
}

//рефлексивно
int reflexively(int **A)
{
    int i = 0;
    while(i < 10)
    {
        if(A[i][i] != 1)
            return 0;
        i++;
    }
    return 1;
}

//антирефлексивно
int anti_reflexively(int **A)
{
    int i = 0;
    while(i < 10)
    {
        if(A[i][i] != 0)
            return 0;
        i++;
    }
    return 1;
}

//симметрично
int symmetrically(int **A)
{
    int i = 0;
    int j = 0;
    while(i < 10)
    {
        j = 0;
        while(j < 10)
        {
            if((A[i][j] != A[j][i]) && (A[i][j] == 1))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

//антисимметрично
int anti_symmetrically(int **A)
{
    int i = 0;
    int j = 0;
    while(i < 10)
    {
        j = 0;
        while(j < 10)
        {
            if((A[i][j] == A[j][i]) && (A[i][j] == 1))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

//транзитивно
int transitively(int **A)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int n = 0;
    while(x < 10)
    {
        z = 0;
        while(z < 10)
        {
            if(A[x][z] == 1)
            {
                y = 0;
                while(y < 10)
                {
                    if(A[z][y] == 1)
                        n = 1;
                    if((A[z][y] == 1) && (A[x][y] != 1) && (n > 0))
                        return 0;
                    y++;
                }
            }
            z++;
        }
        x++;
    }
    if(n == 0)
        return 0;
    return 1;
}

//антитранзитивно
int anti_transitively(int **A)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int n = 0;
    while(x < 10)
    {
        z = 0;
        while(z < 10)
        {
            if(A[x][z] == 1)
            {
                y = 0;
                while(y < 10)
                {
                    if(A[z][y] == 1)
                        n = 1;
                    if((A[z][y] == 1) && (A[x][y] == 1) && (n > 0))
                        return 0;
                    y++;
                }
            }
            z++;
        }
        x++;
    }
    if(n == 0)
        return 0;
    return 1;
}

//полно
int polno(int **A)
{
    int x = 0;
    int y = 0;
    int z = 0;
    while(x < 10)
    {
        y = 0;
        while(y < 10)
        {
            if(x != y)
                if((A[x][y] != 1) || (A[y][x] != 1))
                    return 0;

            y++;
        }
        x++;
    }
    return 1;
}
//толерантности
int tolerant(int **A)
{
    if((reflexively(A) == 1) && (symmetrically(A) == 1))
        return 1;
    return 0;
}
//эквивалентности
int equivalent(int **A)
{
    if((reflexively(A) == 1) && (symmetrically(A) == 1) && (transitively(A) == 1))
        return 1;
    return 0;
}
//порядка
int orders(int **A)
{
    if((anti_symmetrically(A) == 1) && (transitively(A) == 1))
        return 1;
    return 0;
}

void check_svoistva(int **A)
{
    int x;
    x = reflexively(A);
    printf("\nРефлексивно: %d\n", x);
    x = anti_reflexively(A);
    printf("Анти рефлексивоно: %d\n", x);
    x = symmetrically(A);
    printf("Симетрично: %d\n", x);
    x = anti_symmetrically(A);
    printf("Анти семетрично : %d\n", x);
    x = transitively(A);
    printf("Транзетивносто: %d\n", x);
    x = anti_transitively(A);
    printf("Анти транзетивно: %d\n", x);
    x = polno(A);
    printf("Полно: %d\n", x);
}

void check_proizvod_svoistva(int **A)
{
    int x;
    x = tolerant(A);
    printf("\nТолерантно : %d\n", x);
    x = equivalent(A);
    printf("Эквивалентно : %d\n", x);
    x = orders(A);
    printf("Порядка: %d\n", x);
}


void free_matr(int **A)
{
    for (int y = 0; y < 10; y++)
       free(A[y]);
    free(A);
}

int main()
{
    int **A = NULL;
    int **B = NULL;
    int **C = NULL;
    int x;










    printf("Matr A:\n");
    A = creating_matr_A(A);
    print_matr(A);
    check_svoistva(A);
    check_proizvod_svoistva(A);

    printf("\nMatr B:\n");
    B = creating_matr_B(B);
    print_matr(B);

    check_svoistva(B);
    check_proizvod_svoistva(B);

    printf("\nMatr C:\n");
    C = creating_matr_C(C);
    print_matr(C);


    check_svoistva(C);
    check_proizvod_svoistva(C);


    free_matr(A);
    free_matr(B);
    free_matr(C);
    return 0;
}
