#include "Graf.h"
#include "time.h"

int* generator_10(int n, int m);
void out(int *rez, int n);

int main() {

	int *rez = NULL;
	
	rez = generator_10(3, 3);

	
	printf("End: ");
	out(rez, 4);
	getchar();
	return 0;
}

int* generator_10(int n, int m) {
	int **a;
	m = m * m - m;
	int *rez = (int*)malloc(sizeof(int) * 4);
	clock_t time = clock();
	rez[0] = n;
	rez[1] = m;
	rez[2] = 0;
	rez[3] = 0;
	while ((clock() - time) / CLOCKS_PER_SEC < 10) {
		a = grafRandom(n, m);
		grafOut(a, n);
		if (isGrafGamilton(a, n))
			rez[2] += 1;
		if(isGrafEil(a, n, m))
			rez[3] += 1;
		grafFree(a, n);
	}
	return rez;
}
