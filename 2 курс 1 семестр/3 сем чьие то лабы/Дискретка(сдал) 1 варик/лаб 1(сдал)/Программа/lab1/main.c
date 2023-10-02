#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 10
//1.3. Написать программы, формирующие матрицы заданных отношений (см.Варианты заданий, п.а).
//A = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и (x и y четные)}
void get_A(int **a){
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            if((i % 2 == 0)&&(j % 2 == 0))
                a[i][j] = 1;
            else
                a[i][j] = 0;
    return;
}
//B = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и |x – y| < 5}
void get_B(int **b){
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            if(abs(i - j) < 5)
                b[i][j] = 1;
            else
                b[i][j] = 0;
    return;
}

//C = {(x,y) | x ∈ N и y ∈ N и x < 11 и y < 11 и y^2 кратно x}

void get_C(int **c){
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            if((j*j) % i == 0)
                c[i][j] = 1;
            else
                c[i][j] = 0;
    return;
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
int ravn_ot(int **a, int **b){ //равенство отношений
    int i,j,f = 1;
    for(i = 1; (i <= N)&&(f == 1); i++)
        for(j = 1; (j <= N)&&(f == 1); j++)
            f = (a[i][j] == b[i][j]);
    return f;
}

int podmn_ot(int **a, int **b){ //отношение а - подмножество b
    int i,j,f = 1;
    for(i = 1; (i <= N)&&(f == 1); i++)
        for(j = 1; (j <= N)&&(f == 1); j++)
            f = a[i][j] <= b[i][j];
    return f;
}

void ob_ot(int **a, int **b, int **c){ //объединение отношений
    int i,j;
    for(i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            c[i][j] = (a[i][j])||(b[i][j]);
    return;
}

void per_ot(int **a, int **b, int **c){ //пересечение отношений
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = a[i][j]&&b[i][j];
    return;
}

void razn_ot(int **a, int **b, int **c){ //разность отношений
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = (a[i][j] > b[i][j]);
    return;
}

void sim_razn_ot(int **a, int **b, int **c){ //симметрическая разность отношений
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = !((a[i][j] == 1)&&(b[i][j] == 1));
    return;
}

void dop_ot(int **a, int **c){ //дополнение отношения
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = !a[i][j];
    return;
}

void obr_ot(int **a, int **c){ //обращение отношения
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            c[i][j] = a[j][i];
    return;
}

void comp_ot(int **a, int **b, int **c){ //композиция отношений
    int i,j,k;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
    {
        c[i][j] = 0;
        for(k = 1; k <= N; k++)
            c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
    }
    return;
}

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

void write_arr(int **a){
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

int **creatTochd() {//пораждение тождественного отношения
	int **a = get_mem();

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			a[i][j] = (i == j) ? 1 : 0;
	return a;
}

//------------------Свойства отношений---------------------
int reflex(int **r) { //рефлексивно+
    int i = 1, j = 1;
    int res = 1;

    while(i <= N){
        if(r[i][i] == 0){
            res = 0;
            printf("No petli %d ", i);
        }
        i++;
    }
	return res;
}

int areflex(int **r) { //антирефлексивно+
    int i = 1, j = 1;
    int res = 1;

    while(i <= N){
        if(r[i][i] == 1){
            res = 0;
            printf("Petly %d ", i);
        }
        i++;
    }
	return res;
}

int simetr(int **r) { //симметрично+
    int i = 1, j = 1;
    int res = 1;

    while(i <= N){
        while(j <= N){
            if(r[i][j] != r[j][i]){
                printf("No symmetry %d ", i);
                res = 0;
            }
            j++;
        }
        i++;
    }
    return res;
}

int antSimetr(int **r) { //антисимметрично+
    int i = 1, j = 1;
    int res = 1;

    while(i <= N){
        while(j <= N){
            if(r[i][j] == r[j][i]){
                printf("Symmetry %d ", i);
                res = 0;
            }
            j++;
        }
        i++;
    }
    return res;
}

int trans(int **r) { //транзитивно+
    int i = 1, j = 1;
    int res = 1;
	int **a = get_mem();
	comp_ot(r, r, a);

	while(i <= N){
        while(j <= N){
            if(a[i][j] && !r[i][j]){
                    res = 0;
                    printf("Only one train %d %d ", i, j);
            }
            j++;
        }
        i++;
	}
	free_mem(a);
	return res;
}

int antTrans(int **r) { //антитранзитивно+
    int i = 1, j = 1;
    int res = 1;
	int **a = get_mem();
	comp_ot(r, r, a);
	while(i <= N){
        while(j <= N){

            if(!(a[i][j] && r[i][j])){
                res = 0;
                printf("No one train %d %d", i, j);
            }
            j++;
        }
        i++;
	}
	free_mem(a);
	return res;
}

int full(int **r) { //полно+
    int i = 1, j = 1;
    int res = 1;

    while(i <= N){
        while(j <= N){
            if(r[i][j] == 0){
                printf("no train %d %d ", i, j);
                res = 0;
            }
            j++;
        }
        i++;
    }
	return res;
}

//------производные свойст--------

int toller(int **r) { // толерантное
	if (reflex(r) || simetr(r))
		return 1;
	else
		return 0;
}

int equal(int **r) { // эквивалентности
	if ((reflex(r) || simetr(r)) && trans(r))
		return 1;
	else
		return 0;
}

int poradok(int **r) { // порядка
	if (antSimetr(r) && trans(r))
		return 1;
	else
		return 0;
}

int neStrogPoradok(int **r) { // нестрогого порядка
	if (poradok(r) && reflex(r))
		return 1;
	else
		return 0;
}

int StrogPoradok(int **r) { // строгого порядка
	if (poradok(r) && areflex(r))
		return 1;
	else
		return 0;
}

int LinePoradok(int **r) { // линейного порядка
	if (poradok(r) && full(r))
		return 1;
	else
		return 0;
}

int neStrogLinePoradok(int **r) { // нестрогого линейного порядка
	if (neStrogPoradok(r) && full(r))
		return 1;
	else
		return 0;
}

int StrogLinePoradok(int **r) { // строгого линейного порядка
	if (StrogPoradok(r) && full(r))
		return 1;
	else
		return 0;
}


//1.5. Написать программу, вычисляющую значение выражения (см. ―Варианты заданий, п.б) и вычислить его при заданных отношениях (см.Варианты заданий, п.а).
void main(){
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

    printf("---- properties A ----\n");
	printf("reflexively? %d\n",reflex(a));
	printf("antireflexive? %d\n",areflex(a));
	printf("symmetrically? %d\n",simetr(a));
	printf("antisymmetrically? %d\n",antSimetr(a));
	printf("transitive? %d\n",trans(a));
	printf("antitransitively? %d\n",antTrans(a));
	printf("full? %d\n",full(a));
	printf("tolerant? %d\n",toller(a));
	printf("equivalence? %d\n",equal(a));
	printf("poradok? %d\n",poradok(a));
	printf("neStrogPoradok? %d\n",neStrogPoradok(a));
	printf("StrogPoradok? %d\n",StrogPoradok(a));
	printf("LinePoradok? %d\n",LinePoradok(a));
	printf("neStrogLinePoradok? %d\n",neStrogLinePoradok(a));
	printf("StrogLinePoradok? %d\n",StrogLinePoradok(a));

	printf("---- properties B ----\n");
	printf("reflexively? %d\n",reflex(b));
	printf("antireflexive? %d\n",areflex(b));
	printf("symmetrically? %d\n",simetr(b));
	printf("antisymmetrically? %d\n",antSimetr(b));
	printf("transitive? %d\n",trans(b));
	printf("antitransitively? %d\n",antTrans(b));
	printf("full? %d\n",full(b));
	printf("tolerant? %d\n",toller(b));
	printf("equivalence? %d\n",equal(b));
	printf("poradok? %d\n",poradok(b));
	printf("neStrogPoradok? %d\n",neStrogPoradok(b));
	printf("StrogPoradok? %d\n",StrogPoradok(b));
	printf("LinePoradok? %d\n",LinePoradok(b));
	printf("neStrogLinePoradok? %d\n",neStrogLinePoradok(b));
	printf("StrogLinePoradok? %d\n",StrogLinePoradok(b));

	printf("---- properties C ----\n");
	printf("reflexively? %d\n",reflex(c));
	printf("antireflexive? %d\n",areflex(c));
	printf("symmetrically? %d\n",simetr(c));
	printf("antisymmetrically? %d\n",antSimetr(c));
	printf("transitive? %d\n",trans(c));
	printf("antitransitively? %d\n",antTrans(c));
	printf("full? %d\n",full(c));
	printf("tolerant? %d\n",toller(c));
	printf("equivalence? %d\n",equal(c));
	printf("poradok? %d\n",poradok(c));
	printf("neStrogPoradok? %d\n",neStrogPoradok(c));
	printf("StrogPoradok? %d\n",StrogPoradok(c));
	printf("LinePoradok? %d\n",LinePoradok(c));
	printf("neStrogLinePoradok? %d\n",neStrogLinePoradok(c));
	printf("StrogLinePoradok? %d\n",StrogLinePoradok(c));
    printf("\n\n");


    ob_ot(a,b,d);//объединение отношений
    printf("A+B = \n");
    write_arr(d);
    printf("\n\n");

    dop_ot(d, d);//дополнение отношений
    printf("(A+B)^(-1) = \n");
    write_arr(d);
    printf("\n\n");

    comp_ot(d, c, b);//композиция отношений
    printf("(A+B)^(-1) o C = \n");
    write_arr(b);
    printf("\n\n");

    comp_ot(a,a,d);//возведение в квадрат
    printf("A^2 = \n");
    write_arr(d);
    printf("\n\n");

    sim_razn_ot(b,d, a);//симметрическая разность отношений
    printf("(A+B)^(-1) o C (del) A^2 = \n");
    write_arr(a);
    printf("\n\n");



    free_mem(a);
    free_mem(b);
    free_mem(c);
    free_mem(d);

    return;
}
