#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include "num.h"

int main(){
	int a = 1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("¬ведите номер: ");
	scanf("%d", &a);

	switch (a) {
	case(3):
		num3();
		break;
	case(4):
		num4();
		break;
	case(5):
		num5();
		break;
	case(6):
		num6();
		break;
	case(7):
		num7();
	}
	getchar();
	getchar();
	return 0;
}