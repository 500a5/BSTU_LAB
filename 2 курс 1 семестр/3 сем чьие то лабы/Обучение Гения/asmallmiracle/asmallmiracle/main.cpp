#include <stdio.h>
#include <locale.h>

#define MAXSTRLN 15

void gets(char *str);

int main() {
	setlocale(LC_ALL, "Rus");
	char str[MAXSTRLN];
	printf("Как жизнь,сучки?");
	gets(str);

	printf("Ты только что ответил:");
	puts(str);

	getchar();
	return 0;
}

void gets(char *str) {
	char c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		str[i] = c;
		i++;
	}
	str[i] = '\0';
}