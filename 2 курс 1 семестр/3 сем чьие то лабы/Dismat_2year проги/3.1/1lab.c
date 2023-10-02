#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "1lab.h"
#define n 10

int** get_mem()
{
    int **a = (int**)malloc((n + 1) * sizeof(int*));
    for (size_t i = 0 ; i < n + 1 ; i++)
        a[i] = (int*)malloc((n + 1) * sizeof(int));
    return a;
}

void free_mem(int **a)
{
    for (size_t i = 0; i < n + 1; i++)
        free(a[i]);
    free(a);
}

void output(int **a)
{
    for(size_t i = 1; i <= n; i++)
        {
        for(size_t j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
        }
}

// A = {(x, y) | x пр. N и y пр. N и x < 11 и y < 11 и y < x + 1 и x != 2*y}
void get_A(int **a)
{
    size_t x, y;
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            a[x][y] = (x != 2*y) && (y < x + 1 ) ? 1 : 0;
    printf("A = {");
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            if(a[x][y])
                printf(" (%d, %d), ", x, y);
    printf("}\n");
}
// B = {(x, y) | x пр. N и y пр. N и x < 11 и x - четно и x + y < 10}
void get_B(int **b)
{
    size_t x, y;
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            b[x][y] = (x % 2 == 0)&&(x + y < 10) ? 1 : 0;
    printf("B = {");
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            if(b[x][y])
                printf(" (%d, %d), ", x, y);
    printf("}\n");
}

// C = {(x,y) | x пр. N и y пр. N и x < 11 и y < 11 и (x, y) пр. {2, 3, 8}*{1, 4, 5, 8}}
void get_C(int **c)
{
    size_t x, y;
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            c[x][y] = (x == 2 || x == 3 || x == 8)
                && (y == 1|| y == 4 || y == 5 || y == 8) ? 1 : 0;
    printf("C = {");
    for(x = 1; x <= n; x++)
        for(y = 1; y <= n; y++)
            if(c[x][y])
                printf("(%d, %d), ",x, y);
    printf("}\n");
}

short is_void(int **a)
{
	for (size_t i = 1; i <= n; i++)
		for (size_t j = 1; j <= n; j++)
			if(a[i][j])
				return 0;
	return 1;
}

short is_universum(int **a)
{
	for (size_t i = 1; i <= n; i++)
		for (size_t j = 1; j <= n; j++)
			if(!a[i][j])
				return 0;
	return 1;
}

short A_equal_B(int **a, int **b)
{
    short f = 1;
    for(size_t i = 1; (i <= n) && (f == 1); i++)
        for(size_t j = 1; (j <= n) && (f == 1); j++)
            f = (a[i][j] == b[i][j]);
    return f;
}

short A_include_B(int **a, int **b)
{
    short f = 1;
    for(size_t i = 1; (i <= n) && (f == 1); i++)
        for(size_t j = 1; (j <= n) && (f == 1); j++)
            f = a[i][j] <= b[i][j];
    return f;
}

short A_strict_unclude_B(int **a, int **b)
{
    return(A_include_B(a, b) && !(A_equal_B(a, b)));
}

void A_union_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for (size_t j = 1; j <= n; j++)
            c[i][j] = a[i][j] || b[i][j];
}

void A_intersection_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            c[i][j] = a[i][j] && b[i][j];
}

void A_difference_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            c[i][j] = a[i][j] > b[i][j];
}

void A_symmetric_difference_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            c[i][j] = (a[i][j] != b[i][j]);
}

void dop_A(int **a, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            c[i][j] = !a[i][j];
}

void obr_A(int **a, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            c[i][j] = a[j][i];
}

void A_composition_B(int **a, int **b, int **c)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
    {
        c[i][j] = 0;
        for(size_t k = 1; k <= n; k++)
            c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
    }
}

/////////////////////////////////////////////////////////

// порождение тождественного отношения
int **create_identical()
{
	int **a = get_mem();
	for (size_t i = 1; i <= n; i++)
		for (size_t j = 1; j <= n; j++)
			a[i][j] = (i == j) ? 1 : 0;
	return a;
}

/////////////////////////////////////////////////////////

short is_reflective(int **a)
{
    for(size_t i = 1; i <= n; i++)
        if(!a[i][i])
        {
            printf("relation is not reflective, because exists a pair (%d, %d)\n", i, i);
            return 0;
        }
    return 1;
}

short is_anti_reflective(int **a)
{
    for(size_t i = 1; i <= n; i++)
        if(a[i][i])
        {
            printf("relation is not antireflective, because exists a pair (%d, %d)\n", i, i);
            return 0;
        }
    return 1;
}

short is_symmetrical(int **a)
{
    short flag = a[1][2] == a[2][1];
    size_t j = flag == 1? 3 : 2, i = 1;
    while(i <= n && flag)
    {
      while(j <= n && flag)
      {
          if(flag = a[i][j] == a[j][i])
              j++;
      }
      if(flag)
      {
        i++;
        j = i;
      }
    }
     if(i < n || j < n)
        if(a[i][j])
        printf("relation is not symmetrical, because exists a pair (%d, %d), but not exists (%d, %d)\n", i, j, j, i);
      else
        printf("relation is not symmetrical, because exists a pair (%d, %d), but not exists (%d, %d)\n", j, i, i, j);
    return flag;
}

short is_symmetrical2(int **a){
    int **s = get_mem();
    obr_A(a, s);
    short result = A_equal_B(a, s);
    free_mem(s);
    return result;
}

short is_anti_symmetrical(int **a){
    short result = 1;
    size_t j = 2, i = 1;
    while(i <= n && result){
      while(j <= n && result && i != j){
          if(result = (a[i][j] != a[j][i]) || (a[i][j] == 0 && a[j][i] == 0))
              j++;
      }
      if(result){
        i++;
        j = i+1;
      }
    }
     if(i < n || j < n)
        printf("relation is not antisymmetrical, because exists a pair (%d, %d) and exists (%d, %d)\n", i, j, j, i);
    return result;
}

short is_anti_symmetrical2(int **a){
    int **as = get_mem();
    int **I = create_identical();
    obr_A(a, as);
    A_intersection_B(a, as, as);
    short result = A_include_B(as, I);
    free_mem(as);
    free_mem(I);
    return result;
}

short is_transitive(int **a){
    short result = 1;
    size_t i = 1, j, z = 1;
    while(i <= n && result){
        j = 1;
        while(j <= n && result){
            z = 1;
            while(z <= n && result){
                if(a[i][z] && a[z][j])
                    result = a[i][j];
                if(result)
                    z++;
        }
        if(result)
            j++;
      }
      if(result)
          i++;
    }
    if(i < n || j < n)
      printf("relation is not transitive, because exists (%d, %d) and (%d, %d), but not exists (%d, %d)\n", i, z, z, j, i, j);
    return result;
}

short is_anti_transitive(int **a){
    short result = 1;
    size_t i = 1, j, z = 1;
    while(i <= n && result)
    {
        j = 1;
        while(j <= n && result)
        {
            z = 1;
            while(z <= n && result && i != j)
            {
                if(a[i][z] && a[z][j])
                    result = !a[i][j];
                if(result)
                    z++;
        }
        if(result)
            j++;
      }
      if(result)
          i++;
    }
    if(i < n || j < n)
      printf("relation is not antitransitive, because exists (%d, %d) and (%d, %d) and exists (%d, %d)\n", i, z, z, j, i, j);
    return result;
}

short is_full(int **a)
{
    for(size_t i = 1; i <= n; i++)
        for(size_t j = 1; j <= n; j++)
            if(i != j && !(a[i][j] == 1 || a[j][i] == 1))
            {
                printf("relation is not full, because not exists a pairs (%d, %d), (%d, %d)\n", i, j, j, i );
                return 0;
            }
    return 1;
}

short is_full2(int **a)
{
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
	return(is_reflective(a) && is_symmetrical2(a));
}

short is_equivalence(int **a){
	return(is_reflective(a) && is_symmetrical2(a) && is_transitive(a));
}

short is_ordering(int **a){
	return(is_anti_symmetrical2(a) && is_transitive(a));
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
