#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CreateFile.h"

void CreateFile2(char *path, int n) {
	FILE *f = fopen(path, "wb");//���������� f ��� ������ � ���� path
	int a1, a2;
	for (int i = 0; i < n; i++) {
		printf("--------%d--------\n", i + 1);
		printf("���-�� �������: ");
		scanf("%d", &a1);//���-�� �������
		fwrite(&a1, sizeof(int), 1, f);
		for(int j = 0; j < a1; j++){
			printf("%d->", i+1);
			scanf("%d", &a2);//����� �� ��������
			a2 -= 1;
			fwrite(&a2, sizeof(int), 1, f);
			printf("\t�����:");
			scanf("%d", &a2);//����� �� �������
			fwrite(&a2, sizeof(int), 1, f);
		}
	}
	fclose(f);
}

void CreateFile3(char *path, int n) {
	FILE *f = fopen(path, "wb");//���������� f ��� ������ � ���� path
	int a1, a2;
	for (int i = 0; i < n; i++) {
		printf("------%d---------\n", i + 1);
		printf("������� ���-�� ����� �������: ");
		scanf("%d", &a1);//���-�� ����� �������
		fwrite(&a1, sizeof(int), 1, f);
		for (int j = 1; j < a1; j++) {
			printf("������� ���������: ");
			scanf("%d", &a2);//���������� � ���������
			fwrite(&a2, sizeof(int), 1, f);
		}
	}
	fclose(f);
}