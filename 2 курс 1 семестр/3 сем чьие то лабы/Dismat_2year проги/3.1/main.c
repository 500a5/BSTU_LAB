#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
//A = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и (y < x+1 и x != 2y)}
void get_A(int **a){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if((x != 2*y)&&(y < x+1))
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
//B = {(x,y) | x ∈ N и y ∈ N и x < 11 и x-четно и x+y<10}
void get_B(int **b){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if((x % 2 == 0)&&(x + y < 10))
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

//C = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и (x,y) принадлежит {2,3,8}*{1,4,5,8}
void get_C(int **c){
    int x,y;
    for(x = 1; x <= N; x++)
        for(y = 1; y <= N; y++)
            if((x == 2 || x == 3 || x == 8) &&
                    (y == 1|| y == 4 || y == 5 || y == 8))
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

// отношение пустое ? 1:0
int isVoid(int **a) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (a[i][j] == 1)
				return 0;
	return 1;
}
// универсум ? 1:0
int isUniv(int **a) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (a[i][j] == 0)
				return 0;
	return 1;
}


//1.4. Программно реализовать операции над отношениями.
int equation_of_relation(int **a, int **b){ //равенство отношений
    int i,j,f = 1;
    for(i = 1; (i <= N)&&(f == 1); i++)
        for(j = 1; (j <= N)&&(f == 1); j++)
            f = (a[i][j] == b[i][j]);
    return f;
}

int podmn_of_relation(int **a, int **b){ //отношение а - подмножество b
    int i,j,f = 1;
    for(i = 1; (i <= N)&&(f == 1); i++)
        for(j = 1; (j <= N)&&(f == 1); j++)
            if (a[i][j] > b[i][j])
                return 0;
    return 1;
}


short is_void(int **a)
{
    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            if(a[i][j])
                return 0;
    return 1;
}

short is_universum(int **a)
{
    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            if(!a[i][j])
                return 0;
    return 1;
}

short A_equal_B(int **a, int **b)
{
    short f = 1;
    for(size_t i = 1; (i <= N) && (f == 1); i++)
        for(size_t j = 1; (j <= N) && (f == 1); j++)
            f = (a[i][j] == b[i][j]);
    return f;
}

short A_include_B(int **a, int **b)
{
    short f = 1;
    for(size_t i = 1; (i <= N) && (f == 1); i++)
        for(size_t j = 1; (j <= N) && (f == 1); j++)
            f = a[i][j] <= b[i][j];
    return f;
}

short A_strict_unclude_B(int **a, int **b)
{
    return(A_include_B(a, b) && !(A_equal_B(a, b)));
}

void A_union_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] || b[i][j];
}

void A_intersection_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] && b[i][j];
}

void A_difference_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = a[i][j] > b[i][j];
}

void A_symmetric_difference_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = (a[i][j] != b[i][j]);
}

void dop_A(int **a, int **c){
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            c[i][j] = !a[i][j];
}

void obr__of_relation(int **a, int **c){ //обращение отношения
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = a[j][i];
}

void comp_of_relation(int **a, int **b, int **c){ //композиция отношений
    int i,j,k;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++){
            c[i][j] = 0;
            for(k = 1; k <= N; k++)
                c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
        }
}


void power_A(int **a, int **b, int n) {
    if (n >= 2) {
        comp_of_relation(a, b, b);
        for (int i = 3; i < n; i++)
            comp_of_relation(b, a, b);
    }
}

void print_ralation_as_matrix(int **a){
    int i,j;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
//-------------Лог. выражения-----------------
int identically(int **a, int **b) {//равенство
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

int inclusion(int **a, int **b) {//включение
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

int sinclusion(int **a, int **b) {//строгое включение
	if (inclusion(a, b) && !identically(a, b))
		return 1;
	else
		return 0;
}


// порождение тождественного отношения
int **create_identical(){
    int **a = get_mem();
    for (size_t i = 1; i <= N; i++)
        for (size_t j = 1; j <= N; j++)
            a[i][j] = (i == j) ? 1 : 0;
    return a;
}

//------------------Свойства отношений---------------------

short is_reflective(int **a){
    for(size_t i = 1; i <= N; i++)
        if(!a[i][i])
        {
            printf("not reflective, because pair (%d, %d) == 0\n", i, i);
            return 0;
        }
    return 1;
}

short is_anti_reflective(int **a){
    for(size_t i = 1; i <= N; i++)
        if(a[i][i])
        {
            printf("not antireflective, because pair (%d, %d) == 1\n", i, i);
            return 0;
        }
    return 1;
}

short is_symmetrical(int **a)
{
    short flag = a[1][2] == a[2][1];
    size_t j = flag == 1? 3 : 2, i = 1;
    while(i <= N && flag){
        while(j <= N && flag){
            if(flag = a[i][j] == a[j][i])
                j++;
        }
        if(flag){
            i++;
            j = i;
        }
    }
    if(i < N || j < N)
        if(a[i][j])
            printf("not symmetrical, because exists a pair (%d, %d), but not (%d, %d)\n", i, j, j, i);
        else
            printf("not symmetrical, because exists a pair (%d, %d), but not (%d, %d)\n", j, i, i, j);
    return flag;
}


short is_anti_symmetrical(int **a){
    short result = 1;
    size_t j = 2, i = 1;
    while(i <= N && result){
        while(j <= N && result && i != j){
            if(result = (a[i][j] != a[j][i]) || (a[i][j] == 0 && a[j][i] == 0))
                j++;
        }
        if(result){
            i++;
            j = i+1;
        }
    }
    if(i < N || j < N)
        printf("not antisymmetrical, because exists a pair (%d, %d) && (%d, %d)\n", i, j, j, i);
    return result;
}

short is_transitive(int **a){
    short result = 1;
    size_t i = 1, j, z = 1;
    while(i <= N && result){
        j = 1;
        while(j <= N && result){
            z = 1;
            while(z <= N && result) {
                if (a[i][z] && a[z][j])
                    result = a[i][j];
                if (result)
                    z++;
            }
            if(result)
                j++;
        }
        if(result)
            i++;
    }
    if(i < N || j < N)
        printf("not transitive, because (%d, %d) && (%d, %d), but not (%d, %d)\n", i, z, z, j, i, j);
    return result;
}

short is_anti_transitive(int **a){
    short result = 1;
    size_t i = 1, j, z = 1;
    while(i <= N && result){
        j = 1;
        while(j <= N && result){
            z = 1;
            if(i != j)
            {
                while(z <= N && result){
                    if(z == i || z == j)
                        z++;
                    else {
                        if(a[i][z] && a[z][j])
                            result = !a[i][j];
                        if(result)
                            z++;

                    }
                }
            }

            if(result)
                j++;
        }
        if(result)
            i++;
    }
    if(i < N || j < N)
        printf("not antitransitive, because (%d, %d)&&(%d, %d)&&(%d, %d)\n", i, z, z, j, i, j);
    return result;
}

short is_full(int **a){
    for(size_t i = 1; i <= N; i++)
        for(size_t j = 1; j <= N; j++)
            if(i != j && !(a[i][j] == 1 || a[j][i] == 1)){
                printf("not full, because not a pairs (%d, %d), (%d, %d)\n", i, j, j, i );
                return 0;
            }
    return 1;
}

short is_full2(int **a){
    int **f = get_mem();
    int **f2 = get_mem();
    int **a2 = get_mem();
    int **I = create_identical();
    A_union_B(a, I, f);
    A_union_B(f, a2, f2);
    short flag =  is_universum(f2);
    free_mem(f);
    free_mem(f2);
    free_mem(a2);
    free_mem(I);
    return flag;
}

/////////////////////////////////////////////////////////

short is_tolerant(int **a){
    return(is_reflective(a) && is_symmetrical(a));
}

short is_equivalence(int **a){
    return(is_reflective(a) && is_symmetrical(a) && is_transitive(a));
}

short is_ordering(int **a){
    return(is_anti_symmetrical(a) && is_transitive(a));
}

short is_lax_ordering(int **a){
    return(is_ordering(a) && is_reflective(a));
}

short is_strict_ordering(int **a){
    return(is_ordering(a) && is_anti_reflective(a));
}

short is_linear_ordering(int **a){
    return(is_ordering(a) && is_full(a));
}

short is_lax_linear_ordering(int **a){
    return(is_lax_ordering(a) && is_full(a));
}

short is_strict_linear_ordering(int **a){
    return(is_strict_ordering(a) && is_full(a));
}

void info_about_relation(int **a) {
    if (is_reflective(a)) printf("relation is reflective\n");
    if (is_anti_reflective(a)) printf("relation is antireflective\n");
    if (is_symmetrical(a)) printf("relation is symmetrical\n");
    if (is_anti_symmetrical(a)) printf("relation is antisymmetrical\n");
    if (is_transitive(a)) printf("relation is transitive\n");
    if (is_anti_transitive(a)) printf("relation is antitransitive\n");
    if (is_full(a)) printf("relation is full\n");
}

void print__(int **a) {
    int x, y;
    int count = 0;
    printf("!A /\\ A^(-1) & B o C = \n{");
    for (x = 1; x <= N; x++)
        for (y = 1; y <= N; y++) {
            if (a[x][y] == 1) {
                printf("(%d, %d), ", x, y);
                count++;
            }
            if (count == 5) {
                count = 0;
                printf("\n");
            }
        }
    printf("}\n");
}

//1.5. Написать программу, вычисляющую значение выражения (см. ―Варианты заданий, п.б) и
// вычислить его при заданных отношениях (см.Варианты заданий, п.а).
//  !A /\ A^(-1) && B o C
int main(){
    int flag = getchar();

    int **a = get_mem();
    get_A(a);
    printf("A = \n");
    print_ralation_as_matrix(a);
    printf("\n\n");

    int **b = get_mem();
    get_B(b);
    printf("B = \n");
    print_ralation_as_matrix(b);
    printf("\n\n");

    int **c = get_mem();
    get_C(c);
    printf("C = \n");
    print_ralation_as_matrix(c);
    printf("\n\n");

    int **d = get_mem();
    int **e = get_mem();


    if (flag == '1'){
        printf("A\n");
        info_about_relation(a);
        printf("\n\n");
        printf("B\n");
        info_about_relation(b);
        printf("\n\n");
        printf("C\n");
        info_about_relation(c);
        printf("\n\n");
    } else {
        dop_A(a, d);//дополнение А
        printf("!A = \n");
        print_ralation_as_matrix(d);
        printf("\n");

        obr__of_relation(a, a);//обращение отношения
        printf("A^(-1) = \n");
        print_ralation_as_matrix(a);
        printf("\n");

        A_intersection_B(a, b, a);//пересечение
        printf("A^(-1) * B  = \n");
        print_ralation_as_matrix(a);
        printf("\n");

        comp_of_relation(a, c, e);//композиция отношений
        printf("A^(-1) * B o C = \n");
        print_ralation_as_matrix(e);
        printf("\n");

        A_symmetric_difference_B(d, e, a);//симметрическая разность отношений
        printf("!A /\\ A^(-1) * B o C = \n");
        print_ralation_as_matrix(a);
        printf("\n\n");

        print__(a);
    }

    free_mem(a);
    free_mem(b);
    free_mem(c);
    free_mem(d);
    free_mem(e);
    return 1;
}
