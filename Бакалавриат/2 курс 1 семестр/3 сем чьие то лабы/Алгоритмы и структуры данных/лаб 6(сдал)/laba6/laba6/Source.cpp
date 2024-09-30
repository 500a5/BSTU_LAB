#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"

#include "System.h"

int main() {
	
	systemInit();

	int teak = 0;
	do {
		doSystem(teak++);
	} while (!isFinishSystem());
	doSystem(teak++);

	getchar();
	getchar();
	getchar();
	return 0;
}