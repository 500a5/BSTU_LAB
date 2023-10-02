#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

#include "Source.h"


void num3() {
	int n, m;
	int *a; // ������ ������������������
	int **graf; // ������� �����

	printf("\n������� ������ ������������������: ");
	scanf("%d", &n);

	a = init_posl(n);

	printf("\n������� �������� ��������� ��������� �����: ");
	scanf("%d", &m);
	graf = init_graf(m);

	if (is_marshrut(a, graf, n)) {
		printf("\n ������ ������������������ ��� ������� ����� �������� ���������!");
		if (is_cep(a, n)) {
			printf("\n ������ ������������������ ��� ������� ����� �������� �����!");
			if (is_easy_cep(a, n, m))
				printf("\n ������ ������������������ ��� ������� ����� �������� ������� �����!");
			if (is_easy_cikl(a, n, m))
				printf("\n ������ ������������������ ��� ������� ����� �������� ������� ������!");
		}
		else {
			printf("\n ������ ������������������ ��� ������� ����� �� �������� �����, � ������ � ��. ����� � ��. ������!");
		}

		if (is_cikl(a, n))
			printf("\n ������ ������������������ ��� ������� ����� �������� ������!");
	}
	else {
		printf("\n ������ ������������������ ��� ������� ����� �� �������� ���������! ������������� � ����� ������.");
	}

}

void num4() {
	int n, l;
	int *a;
	int **graf;

	printf("\n������� ������ ��������: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\n������� �������� ��������� ��������� �����: ");
	scanf("%d", &n);
	graf = init_graf(n);

	printf("\n������� ������� ��� ������� ���������� ����� ��������: ");
	scanf("%d", &a[0]);

	marshruti(a, graf, 1, l, n);
}

void num5() {

	int i, j;
	int n, l;
	int *a;
	int **graf;
	int **r;
	printf("\n������� ������ ��������: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\n������� �������� ��������� ��������� �����: ");
	scanf("%d", &n);
	graf = init_graf(n);
	r = (int**)malloc((n + 1) * sizeof(int*));
	// ���� ��������� �����
	for (i = 1; i <= n; i++) {
		// ��������� ������ ��� �������� �����
		r[i] = (int*)malloc((n + 1) * sizeof(int));
		for (j = 1; j <= n; j++) {
			r[i][j] = 0;
		}
	}

	int v = 1;

	while (v <= n) {
		a[0] = v;
		marshruti(a, graf, 1, l, n);
		v++;
	}
	j = 1;
	for (i = (j + 1); i <= (n - 1); i++) {
		for (j = 1; j <= n; j++) {
			printf("����� ��������� %d � %d - %d ���������.\n", i, j, r[i][j]);
		}
	}
}

void num6() {
	int l, n;
	int *a;
	int **graf;
	printf("\n������� ������ ��������: ");
	scanf("%d", &l);
	a = init_posl((l + 1));

	printf("\n������� �������� ��������� ��������� �����: ");
	scanf("%d", &n);
	graf = init_graf(n);

	printf("\n������� 2 ������� ����� �������� ���������� ����� ��������: ");
	scanf("%d %d", &a[0], &a[l]);

	marshruti(a, graf, 1, l, n);
}

void num7() {
	int *log_v;
	int *a; // ������ ��������
	int n;// �������� ���������� ������� ��������� �����
	int **graf; // ������� �����
	printf("\n������� �������� ��������� ��������� �����: ");
	scanf("%d", &n);
	graf = init_graf(n);

	int i;
	a = init_posl((n));
	for (i = 0; i < n; i++)
		a[i] = 0;

	printf("\n������� ������� ��� ������� ���������� ����� ��� ������� ������������ ����: ");
	scanf("%d", &a[0]);

	log_v = init_posl((n + 1));
	for (i = 0; i <= n; i++)
		log_v[i] = 0;

	log_v[a[0]] = 1;

	all_max_easy_cepi(a, graf, log_v, i, n);

}