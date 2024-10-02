#include <stdio.h>
#include <stdlib.h>
#define MAX 30000

void coup();
void LastSearch();

unsigned int ar[MAX];
unsigned int *p;
int main() 
{
	p = ar;
	unsigned int com;
	while ((com = getchar()) != '!')
		switch (com){
		case '>':
			p++;
			break;
		case '<':
			p--;
			break;
		case '+':
			(*p)++;
			break;
		case '-':
			(*p)--;
			break;
		case '.':
			printf("%d ", *p);
			break;
		case ',':
			scanf_s("%d", p);
			break;
		case '\n':
			break;
		case '%':
			coup();
			break;
		default:
			printf("error: unknown command\n");
			break;
		}
	return 0;
}

void coup() {
	int i = 2;
	int path;
	LastSearch();

	while (*p != 0) {
		path = *p;
		*p = 0;
		p += i;
		i += 1;
		*p = path;
		p -= i;
		i += 1;
	}
	p += i/2;
}

void LastSearch() {
	while (*p != 0)
		p++;
	p--;
}



