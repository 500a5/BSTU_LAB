
#include "Graf.h"

void input(station **a, int *n) {//ввод списка смежности(данных о метро)
	char c;
	puts("Вручную или из файла(m/f): ");
	getchar();
	c = getchar();
	if (c == 'm') {
		printf("Введите количество станций метро: ");
		scanf("%d", &n);
		*a = (station*)malloc(sizeof(station) * (*n));
		inputManually(*a, *n);//ввод вручную
	}
	else {//работа с файлами
		FILE *f;
		char path1[MAXSTRLN];//файл названий
		char path2[MAXSTRLN];//файл связей
		char path3[MAXSTRLN];//файл общих станций
		printf("Выберите схему метро СПБ/Тест (S/T)\n");
		scanf("%c", &c);
		if (c == 'S') {
			char path[] = "SPB.txt";
			getPath(path, n, path1, path2, path3);
		}
		else {
			char path[] = "Test.txt";
			getPath(path, n, path1, path2, path3);
		}
		*a = (station*)malloc(sizeof(station) * (*n));
		inputFile(*a, *n, path1, path2, path3);//ввод из файла
	}
	return;
}

void getPath(char *path, int *n, char *name, char *connection, char *together) {
	FILE *f = fopen(path, "r");
	char num[MAXSTRLN];
	fgets(num, MAXSTRLN, f);
	*n = gorn(num);
	fgets(name, MAXSTRLN, f);
	reorg(name);
	fgets(connection, MAXSTRLN, f);
	reorg(connection);
	fgets(together, MAXSTRLN, f);
	reorg(together);
	fclose(f);
}

void inputManually(station *a, int n) {//ввод вручную
	inputManuallyName(a, n);//ввод вручную названий станций
	inputManuallyConnection(a, n); //ввод вручную связей между станциями
	inputManuallyTogether(a, n);//ввод вручную общих станций
	return;
}

void inputManuallyName(station *a, int n) {//ввод вручную названий станций
	printf("Введение названий станций\n");
	getchar();//символ \n
	for (int i = 0; i < n; i++) {
		printf("\t%d - ", i + 1);//выводим номер станции
		gets(a[i].name);//считываем название станции с консоли
	}//введение названия станций
	return;
}

void inputManuallyConnection(station *a, int n) {//ввод вручную связей между станциями
	for (int i = 0; i < n; i++) {
		printf("Cтанции связи с %d \n", i + 1);//выводим номер станции
		printf("Введите количество станций связанных с ней: ");//доп информация
		scanf("%d", &a[i].c_connection);//введение количества станций
		a[i].connection = (int*)malloc(sizeof(int) * 2 * a[i].c_connection);//выделение памяти для дуг(путей и времени)
		for (int j = 0; j < a[i].c_connection; j++) {
			printf("%d -> ", i + 1);//вывод номера дуги
			scanf("%d", &((a[i].connection)[j]));//считывание прихода дуги
			(a[i].connection)[j] -= 1;
			printf("Введите время прохождения между станциями: ");
			scanf("%d", &((a[i].connection)[a[i].c_connection + j]));//ввод времени прохода по дуге
		}
	}
	return;
}

void inputManuallyTogether(station *a, int n) {//ввод вручную общих станций
	printf("Введение общих станций(переходов между линиями)\n");
	for (int i = 0; i < n; i++) {
		printf("Станция %d\n", i + 1);//выводим номер станции
		printf("Введите количество общих станций: ");
		scanf("%d", &a[i].c_together);//вводим количество общих станций
		if (a[i].c_together > 1) {//нет смысла выделять память, если станция одиночка
			a[i].together = (int*)malloc(sizeof(int)*a[i].c_together);//выделение памяти для общих станций
			for (int j = 0; j < a[i].c_together - 1; j++) {
				printf("Введите общие: ");
				scanf("%d", &((a[i].together)[j]));//ввод общих станций
				(a[i].together)[j] -= 1;
			}
		}
	}
	return;
}

void inputFile(station *a, int n, char *path1, char *path2, char* path3) {//ввод из файла
	inputFileName(a, n, path1);//ввод из файла названий станций
	inputFileConnection(a, n, path2);//ввод из файла связей между станциями
	inputFileTogether(a, n, path3);//ввод из файла общих станций
	return;
}

void inputFileName(station *a, int n, char *path) {//ввод из файла названий станций
	FILE *f;//переменная для файла
	//char path[MAXSTRLN] = "nameMetro.txt";//----------------------------------------------------
	f = fopen(path, "r");//Подготовка f, для чтения файла path(текстовый файл)
	printf("Названия станций: \n");
	for (int i = 0; i < n; i++) {
		fgets(a[i].name, MAXSTRLN, f);//считывание названий станций
		printf("%d - ", i + 1);
		puts(a[i].name);
	}
	fclose(f);
	return;
}

void inputFileConnection(station *a, int n, char *path) {//ввод из файла связей между станциями
	FILE *f;
	//char path[MAXSTRLN] = "SpbNetwork.bin";//---------------------------------------------------
	f = fopen(path, "rb");//Подготовка f, для чтения файла path(бинарный файл)
	for (int i = 0; i < n; i++) {
		fread(&(a[i].c_connection), sizeof(int), 1, f);//количество станций
		printf("Введите количество станций связанных с ней: %d", a[i].c_connection);
		printf("\n");
		a[i].connection = (int*)malloc(sizeof(int) * 2 * a[i].c_connection);//выделение памяти для дуг(путей и времени)
		for (int j = 0; j < a[i].c_connection; j++) {
			fread(&(a[i].connection)[j], sizeof(int), 1, f);//связь со станцией
			printf("%d -> %d", i + 1, (a[i].connection)[j] + 1);
			printf("\n");
			fread(&((a[i].connection)[a[i].c_connection + j]), sizeof(int), 1, f);//время до станции
			printf("Введите время прохождения между станциями: %d", (a[i].connection)[a[i].c_connection + j]);
			printf("\n");
		}
	}
	fclose(f);
	return;
}

void inputFileTogether(station *a, int n, char *path) {//ввод из файла общих станций
	FILE *f;
	//char path[MAXSTRLN] = "general.bin";//-----------------------------------------------------
	f = fopen(path, "rb");//Подготовка f, для чтения файла path(бинарный файл)
	for (int i = 0; i < n; i++) {
		fread(&a[i].c_together, sizeof(int), 1, f);//считываем количество общих станций
		if (a[i].c_together > 1) {
			a[i].together = (int*)malloc(sizeof(int)*a[i].c_together);
			for (int j = 0; j < a[i].c_together - 1; j++) {
				fread(&((a[i].together)[j]), sizeof(int), 1, f);//считываем с файла в структуру информацию о общих станциях
				(a[i].together)[j] -= 1;
			}
		}
	}
	fclose(f);
	return;
}

void gets(char *str) {
	char c;
	int i = 0;
	while ((c = getchar()) != '\n')
		str[i++] = c;
	str[i] = '\0';
}//считываем строку

void dijkstra_1(station *a, int n, int *rez) { //поиск самого короткого пути по времени
	int start;//станция отправки
	int u;//самый минимальный не проверенный
	int min;//сохранение минимального значения
	int i, j, count;//счётчики
	int *was = (int*)malloc(sizeof(int)*n);//пройденные станции
	for (i = 0; i < n; i++) {//создание пустых массивов данных
		rez[i] = INT_MAX;//установка максимального значения для времени пути
		rez[n + i] = -1;//пустое значение для предыдущей станции
		was[i] = 0;//установка ложного значения
	}
	printf("Введите станцию отправки: ");
	scanf("%d", &start);//введение станции отпавки
	start -= 1;//установка на массив

	rez[start] = 0;//начальная станция

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//максимальное значение инт
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//Ищем значение старта
			}
		was[u] = 1;//были на станции u
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && rez[u] <= rez[(a[u].connection)[j]]) {//самый бррр, два цикла, из-за сдвига динамического и статического массива
					rez[(a[u].connection)[j]] = rez[u];//считаем пересадки
					rez[n + (a[u].connection)[j]] = u;//запоминаем предыдущую станцию
				}
			}
		for (i = 0; i < (a[u].c_together - 1); i++) {
			if (!was[(a[u].together)[i]] && rez[u] != INT_MAX && rez[u] < rez[(a[u].together)[i]]) {
				rez[(a[u].together)[i]] = rez[u] + 1;//считаем пересадки
				rez[n + (a[u].together)[i]] = u;//запоминаем предыдущую станцию
			}
		}
	}
	free(was);
	return;
}

void dijkstra_2(station *a, int n, int *rez) { //поиск самого короткого пути по времени
	int start;//станция отправки
	int u;//самый минимальный не проверенный
	int min;//сохранение минимального значения
	int i, j, count;//счётчики
	int *was = (int*)malloc(sizeof(int)*n);//пройденные станции
	for (i = 0; i < n; i++) {//создание пустых массивов данных
		rez[i] = INT_MAX;//установка максимального значения
		rez[n + i] = -1;//пустое значение для предыдущей станции
		was[i] = 0;//установка ложного значения
	}
	printf("Введите станцию отправки: ");
	scanf("%d", &start);//введение станции отпавки
	start -= 1;//установка на массив

	rez[start] = 0;

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//максимальное значение инт
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//Ищем значение старта
			}
		was[u] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && (rez[u] + 1)%1000 < (rez[(a[u].connection)[j]])%1000) {//самый бррр, два цикла, из-за сдвига динамического и статического массива
					rez[(a[u].connection)[j]] = rez[u] + 1;
					rez[n + (a[u].connection)[j]] = u;
				}
			}
		for (i = 0; i < (a[u].c_together - 1); i++) {
			if (!was[(a[u].together)[i]] && rez[u] != INT_MAX && rez[u]%1000 < rez[(a[u].together)[i]]%1000) {
				rez[(a[u].together)[i]] = rez[u] + 1001;
				rez[n + (a[u].together)[i]] = u;
			}
		}
	}

	for (i = 0; i < n; i++)
		rez[i] = rez[i] % 1000;
	free(was);
	return;
}

void dijkstra_3(station *a, int n, int *rez) { //поиск самого короткого пути по времени
	int start;//станция отправки
	int u;//самый минимальный не проверенный
	int min;//сохранение минимального значения
	int i, j, count;//счётчики
	int *was = (int*)malloc(sizeof(int)*n);//пройденные станции
	for (i = 0; i < n; i++) {//создание пустых массивов данных
		rez[i] = INT_MAX;//установка максимального значения
		rez[n + i] = -1;//пустое значение для предыдущей станции
		was[i] = 0;//установка ложного значения
	}
	printf("Введите станцию отправки: ");
	scanf("%d", &start);//введение станции отпавки
	start -= 1;//установка на массив

	rez[start] = 0;

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//максимальное значение инт
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//Ищем значение старта
			}
		was[u] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && rez[u] + (a[u].connection)[j + a[u].c_connection] < rez[(a[u].connection)[j]]) {//самый бррр, два цикла, из-за сдвига динамического и статического массива
					rez[(a[u].connection)[j]] = rez[u] + (a[u].connection)[j + a[u].c_connection];
					rez[n + (a[u].connection)[j]] = u;
				}
			}
		for (i = 0; i < (a[u].c_together - 1); i++) {
			if (!was[(a[u].together)[i]] && rez[u] != INT_MAX && rez[u] < rez[(a[u].together)[i]]) {
				rez[(a[u].together)[i]] = rez[u];
				rez[n + (a[u].together)[i]] = u;
			}
		}
	}
	free(was);
	return;
}

void output(station *a, int n, int *rez) {
	int end;
	printf("Введите станцию прибытия: ");
	scanf("%d", &end);
	end -= 1;
	out(a, n, rez, end);
	printf(" = %d", rez[end]);
	return;
}

void out(station *a, int n, int *rez, int num) {
	if (num == -1)
		return;
	else {
		out(a, n, rez, rez[n + num]);
		nameStation(a, num);
		printf("->");
	}
}

void nameStation(station *a, int n) {
	int i = 0;
	while (a[n].name[i] != '\n' && a[n].name[i] != '\0' && i < MAXSTRLN) {
		printf("%c", a[n].name[i]);
		i++;
	}
	return;
}

void freeMem(station *a, int *rez, int n) {
	for (int i = 0; i < n; i++) {
		free((a[i]).connection);
		if (a[i].c_together > 1)
			free((a[i]).together);
	}
	free(a);
	free(rez);
}

int gorn(char *str) {
	int S = str[0] - '0';
	for (int i = 1; str[i] != '\0' && str[i] != '\n' && i < MAXSTRLN; i++)
		S = S * 10 + str[i] - '0';
	return S;
}

void reorg(char *str) {
	int i;
	for (i = 0; str[i] != '\n' && str[i] != '\0' && i < MAXSTRLN; i++)
		;
	str[i] = '\0';
}