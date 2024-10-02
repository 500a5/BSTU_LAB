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

//1.3. Написать программы, формирующие матрицы заданных отношений (см.Варианты заданий, п.а).
//A = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и (x-четное и x+y<10)}
void get_A(int **a){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if((x % 2==0)&&(x+y<10))
                a[x][y] = 1;
            else
                a[x][y] = 0;
    printf("{");
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if(a[x][y] == 1)
                printf("(%d,%d), ",x,y);
    printf("}\n");
}
//B = {(x,y) | x ∈ N и y ∈ N и x+2y<20}
void get_B(int **b){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if(x+2*y<20)
                b[x][y] = 1;
            else
                b[x][y] = 0;
    printf("{");
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if(b[x][y] == 1)
                printf("(%d,%d), ",x,y);
    printf("}\n");
}

//C = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и x>7 или y кратно 3}
void get_C(int **c){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if(x>7 || y%3==0)
                c[x][y] = 1;
            else
                c[x][y] = 0;
    printf("{");
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if(c[x][y] == 1)
                printf("(%d,%d), ",x,y);
    printf("}\n");
}

//1.4. Программно реализовать операции над отношениями.

int inclusion(int **a, int **b) {// 1. включение
    int f = 1;
    int x = 1;
    int y;
    while (x <= N && f) {
        y = 1;
        while (y <= N && f) {
            f = a[x][y] <= b[x][y] ? 1 : 0;
            y++;
        }
        x++;
    }
    return f;
}

int equally(int **a, int **b) {// 2. равенство
    int f = 1;
    int x = 1;
    int y;
    while (x <= N && f) {
        y = 1;
        while (y <= N && f) {
            f = a[x][y] = b[x][y];
            y++;
        }
        x++;
    }
    return f;
}

int sinclusion(int **a, int **b) {// 3. строгое включение
    if (inclusion(a, b) && !equally(a, b))
        return 1;
    else
        return 0;
}


void A_union_B(int **a, int **b, int **c){ // 4. объединение
    for(size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] || b[i][j];
}

void A_intersection_B(int **a, int **b, int **c){ // 5. пересечение
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] && b[i][j];
}

void A_dif_B(int **a, int **b, int **c){ // 6. разность
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] > b[i][j];
}

void A_symmetric_dif_B(int **a, int **b, int **c){ //  7. симметрческая разность
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = (a[i][j] != b[i][j]);
}


void dop_A(int **a, int **c){ // 8. дополнение
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = !a[i][j];
}

void obr__of_relation(int **a, int **c){ // 9. обращение
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = a[j][i];
}

void comp_of_relation(int **a, int **b, int **c){ //  10. композиция
    int i,j,k;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
        {
            c[i][j] = 0;
            for(k = 1; k <= N; k++)
                c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
        }
}


int podmn_of_relation(int **a, int **b){ //отношение а - подмножество b
    int i,j,f = 1;
    for(i = 1; (i <= N)&&(f == 1); i++)
        for(j = 1; (j <= N)&&(f == 1); j++)
            f = a[i][j] <= b[i][j];
    return f;
}



void write_arr(int **a){
    int i,j;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++)
            printf("%d ", a[j][i]);
        printf("\n");
    }
}



//2.0

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
//1.5. Написать программу, вычисляющую значение выражения (см. ―Варианты заданий, п.б) и
// вычислить его при заданных отношениях (см.Варианты заданий, п.а).

int main(){
    int **a = get_mem();
    get_A(a);
    printf("A = \n");
    write_arr(a);
    printf("\n\n");


    int **b = get_mem();
    get_B(b);
    printf("B = \n");
    write_arr(b);
    printf("\n\n");

    int **c = get_mem();
    get_C(c);
    printf("C = \n");
    write_arr(c);
    printf("\n\n");

    int **d = get_mem();
    int **e = get_mem();
    int **m = get_mem();

  /**  dop_A(a, d);//дополнение А
    printf("!A = \n");
    write_arr(d);
    printf("\n\n");

   A_dif_B(a,b,e); // ( A-B)
    printf("A-B = \n");
    write_arr(e);
    printf("\n\n");

    comp_of_relation(e,e,m );
    printf("(A-B)^-1 = \n");
    write_arr(m);
    printf("\n\n");

    A_intersection_B(c,d,d);
    printf("C and !A = \n");
    write_arr(d);
    printf("\n\n");

    A_union_B(m,d,e);
    printf("(A-B)^-1 or C and !A = \n");
    write_arr(e);
    printf("\n\n");
**/
    free_mem(a);
    free_mem(b);
    free_mem(c);
    free_mem(d);
    free_mem(e);
    free_mem(m);
    return 1;
}
