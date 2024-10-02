#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"
#include "System.h"

int main() {
	systemInit();
	int teak = 0;
	do {
		if(rand() % 2)
			generatorTasks();
		doSystem(teak++);
	} while (!isFinishSystem());

	


	getchar();
	getchar();
	getchar();
	return 0;
}