#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

#define MAXSTRLN 30


Table* inputExceptions(char *path, h_f hash_func, func equal);
void Identif(char *path, Table *T, func equal);
int equal(void* a, void* b);
int HashFunc(void* str, int index, int n);

int TableError;

int main() {
	char path1[MAXSTRLN] = "Sintaxys.txt";
	char path2[MAXSTRLN] = "Programme.txt";
	h_f hash_func = HashFunc;
	func f = equal;
	Table *T = inputExceptions(path1, hash_func, f);
	Identif(path2, T, f);
	getchar();
	return 0;
}

//¬вод таблицы исключений
Table* inputExceptions(char *path, h_f hash_func, func equal) {
	FILE *f;
	int i;
	f = fopen(path, "r");
	Table *T;
	T = TableInit(hash_func, 50, 0);
	while (!feof(f)) {
		char *word = (char*)malloc(sizeof(char) * MAXSTRLN);
		i = 0;
		fscanf(f, "%c", &word[i]);
		while (word[i] != ' ' && word[i] != '\0' && word[i] != '\n') {
			i++;
			fscanf(f, "%c", &word[i]);
		}
		word[i] = '\0';
		TablePut(T, word);
	}
	return T;
}


void Identif(char *path, Table *T, func equal) {
	FILE *f = fopen(path, "r");
	int i;
	char* word;
	while (!feof(f)) {
		word = (char*)malloc(sizeof(char) * MAXSTRLN);
		*word = '\0';
		i = 0;
		fscanf(f, "%c", &word[i]);
		while (word[i] != ' ' && word[i] != '\0' && word[i] != '\n') {
			i++;
			fscanf(f, "%c", &word[i]);
		}
		word[i] = '\0';

		if (!TableRead(T, word, equal))
			puts(word);
		free(word);
	}
	printf("-------------The end-----------");
}

int equal(void* a, void* b) {
	char* path1 = (char*)a;
	char* path2 = (char*)b;
	if (path1 == NULL || path2 == NULL || path1[0] == '\0')
		return 0;
	int i;
	for (i = 0; path1[i] == path2[i] && (path1[i] != '\0' && path2[i] != '\0') && i < MAXSTRLN; i++)
		;
	if (path1[i] == '\0' && path2[i] == '\0')
		return 1;
	else
		return 0;
}

int HashFunc(void* str, int index, int n) {
	char *a = (char*)str;
	int i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	return (i + index) % n;
}