#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CreateFile.h"

void CreateFile2(char *path, int n) {
	FILE *f = fopen(path, "wb");//подготовка f для записи в файл path
	int a1, a2;
	for (int i = 0; i < n; i++) {
		printf("--------%d--------\n", i + 1);
		printf("Кол-во станций: ");
		scanf("%d", &a1);//Кол-во станций
		fwrite(&a1, sizeof(int), 1, f);
		for(int j = 0; j < a1; j++){
			printf("%d->", i+1);
			scanf("%d", &a2);//Связь со станцией
			a2 -= 1;
			fwrite(&a2, sizeof(int), 1, f);
			printf("\tВремя:");
			scanf("%d", &a2);//Время до станции
			fwrite(&a2, sizeof(int), 1, f);
		}
	}
	fclose(f);
}

void CreateFile3(char *path, int n) {
	FILE *f = fopen(path, "wb");//подготовка f для записи в файл path
	int a1, a2;
	for (int i = 0; i < n; i++) {
		printf("------%d---------\n", i + 1);
		printf("Введите кол-во общих станций: ");
		scanf("%d", &a1);//Кол-во общих станций
		fwrite(&a1, sizeof(int), 1, f);
		for (int j = 1; j < a1; j++) {
			printf("Введите пересадку: ");
			scanf("%d", &a2);//информация о пересадке
			fwrite(&a2, sizeof(int), 1, f);
		}
	}
	fclose(f);
}