#include <stdio.h>
#include <windows.h>
#include "tasks.h"
#include "tasks.c"
7
int main(){
	int a = 1;
	int flag = 1;
	while(flag) {
        printf("Enter number of task (3-7)\nOr another button for exit from app: ");
        scanf("%d", &a);
		switch (a) {
			case (3):
				num3();
				break;
			case (4):
				num4();
				break;
			case (5):
				num5();
				break;
			case (6):
				num6();
				break;
			case (7):
				num7();
                break;
			default:
				flag = 0;
		}
	}
	getchar();
	getchar();
	return 0;
}