#include "stdio.h"
#include "malloc.h"
// выводит на экран монитора двоичное представление переменной а
//типа int
void printByte(char);
//выводит на экран монитора двоичное представление переменной a
//произвольного типа размера size байт
void printVar(void *, size_t);
//вводит с консоли символы в строку s и возвращает количество прочитанных символов
int inputBits(char []);
//преобразовывает последовательностей нулей и единиц в строковой константе в последовательность бит
//возврщает нетипизированный указатель
void *transfVar(char *, int);

int main() {
    char s[100];
	int size = inputBits(s);
	int char *b = (int *) transfVar(s, size);
	printf("%d ",*b);

}

int inputBits(char s[]) {//ввод строки битов
	int count = 0;
	char c;
	while ((c = getchar()) != '\n')
		*(s + count++) = c;
	*(s + count) = '\0';
	return count;
}

void *transfVar(char *s, int size) {
	int sizeOfByts = size / 8;
	char * rez =(char *) malloc(sizeOfByts * sizeof(char));
	int i, j, pos;
	for (i = 0; i < sizeOfByts; i++) {
		pos = sizeOfByts - i - 1;
		rez[pos] = 0;
		for (j = 0; j < 8; j++) {
			rez[pos] = rez[pos] << 1;
			rez[pos] = rez[pos] | (s[i * 8 + j] == '1' ? 1 : 0);
		}
	}
	return rez;
}

void printByte(char a) {
	int i;
	char mask = 1 << 7;
	for (i = 0; i < 8; i++) {
		printf("%i" , (a & mask) ? 1 : 0);
		a <<= 1;
	}
}

void printVar(void *a, size_t size) {
	int i;
	char * p = (char *) a;
	for (i = size - 1; i >= 0; i--)
		printByte(*(p + i));

	printf("\n");}
