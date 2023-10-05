#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ABC = 'Z' - 'A' + 1;

void printDis(int *m) //вывод
{
	int j = 0;
	while (m[j] == 0 && j < ABC)
		j++;
	if (j == ABC)
    {
		printf("0");
		return;
	}
	if (m[j] == 1)
		printf("%c", 'A' + j);
	else
		printf("-%c", 'A' + j);
	j++;
	for (; j < ABC; j++)
		switch (m[j])
		{
			case 0:
            {
				break;
			}
			case 1:
            {
				printf("|%c", 'A' + j);
				break;
			}
			case -1:
            {
				printf("|-%c", 'A' + j);
				break;
			}
		}
}

void printPatch(int **s, int i, int j, int k)
{
	printf("(");
	printDis(s[i]);
	printf(") & (");
	printDis(s[j]);
	printf(") = ");
	printDis(s[k]);
	printf("\n");
}

int isOneDif(int **s, int i1, int i2)
{
	int n_dif = 0, j = 0, ind;
	while (n_dif < 2 && j < ABC)
    {
		if (s[i1][j] != s[i2][j])
		{
			n_dif++;
			ind = j;
		}
		j++;
	}
	if (n_dif == 1)
		return ind;
	return -1;
}

//возвращает 1, если есть одинаковые строки
int Search(int**s, int *m, int len)
{
	int i, j, f=0;
	for (i = 0; i < len && !f; i++)
	{
		f = 1;
		for (j = 0; j < ABC && f; j++)
		 	f = s[i][j] == m[j];
	}
	return f;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	//формирование матрицы s
    char form[100], sled[100];

	printf("Введите посылки: \n");
	gets(form);
	printf("Введите следствие: \n");
	gets(sled);

	int n = 1, i = 0, k = 0; //n - количество посылок, ввод через запятую
	while (form[i] != '\0')
		if (form[i++] == ',')
            n++;

	int n_sled = 0; //n_sled - количество термов в следствии
	i = 0;
	while (sled[i] != '\0')
		if (sled[i++] >= 'A' && sled[i] <= 'Z')
			n_sled++;

	int **s = (int**)malloc((n + n_sled) * sizeof(int*));
	for (k = 0; k < n + n_sled; k++)
		s[k] = (int*)calloc(ABC, sizeof(int));

	/*Заполнение строк для посылок*/
	i = 0;
	for (k = 0; k < n; k++)
    {
		while (form[i] != ',' && form[i] != '\0')
        {
			if (form[i] >= 'A' && form[i] <= 'Z')
			{
				if (i > 0)
				{
					if (form[i - 1] == '-')
						s[k][form[i] - 'A'] = -1;
					else
						s[k][form[i] - 'A'] = 1;
				}
                else
					s[k][form[i] - 'A'] = 1;
			}
			i++;
		}
		i++;
	}
	for (i = 0; k < n + n_sled;)
    {
		while (sled[i] != '\0')
        {
			if (sled[i] >= 'A' && sled[i] <= 'Z')
			{
				if (i > 0)
				{
					if (sled[i - 1] == '-')
						s[k++][sled[i] - 'A'] = 1;
					else
						s[k++][sled[i] - 'A'] = -1;
				}
                else
					s[k++][sled[i] - 'A'] = -1;
			}
			i++;
		}
		i++;
	}

	int len = n + n_sled, old_len, isExit = 0, j, isNULL;
	int m[ABC];
	j = 1;
	int t, p;
	while (!isExit)//ИНДИКАТОР ИЗМЕНЕНИЯ ДЛИНЫ
    {
		old_len = len;
		i = 0;
		while (i < old_len - 1 && !isExit)
		{
			while (j < old_len && !isExit)
			{
				if (i != j)
				{
					k = isOneDif(s, i, j); //индекс по которому массивы различаются, ил -1, если раздичий > 1
					if (k != -1)
                        {
						for (t = 0; t < ABC; t++)
							m[t]=s[i][t];
						m[k]=0;
						if (!Search (s, m, len)) //если такой строчки нет
						{
							len++;
							s = (int**)realloc(s, len * sizeof(int*));
							s[len - 1] = (int*)calloc(ABC, sizeof(int));
							isNULL = 1; //индикатор наличия пустой строки
							for (p = 0; p < ABC; p++)
							{
								s[len - 1][p] = s[i][p];
								if (s[len - 1][p] != 0 && p != k)
									isNULL = 0;
							}
							s[len - 1][k] = 0; //s[len - 1] - строка новой склейки
							printPatch(s, i, j, len-1);
							if (isNULL)
                            {
								printf("Теорема доказана.\n");
								isExit = 1;
							}
						}
					}
				}
				j++;
			}
			i++;
			j = i + 1;
		}
		if (old_len == len)
        {
			printf("Теорема не доказана.\n");
			isExit = 1;
		}
		j = old_len;
	}
}
//AAlklkASD
