
#include "Graf.h"

void input(station **a, int *n) {//���� ������ ���������(������ � �����)
	char c;
	puts("������� ��� �� �����(m/f): ");
	getchar();
	c = getchar();
	if (c == 'm') {
		printf("������� ���������� ������� �����: ");
		scanf("%d", &n);
		*a = (station*)malloc(sizeof(station) * (*n));
		inputManually(*a, *n);//���� �������
	}
	else {//������ � �������
		FILE *f;
		char path1[MAXSTRLN];//���� ��������
		char path2[MAXSTRLN];//���� ������
		char path3[MAXSTRLN];//���� ����� �������
		printf("�������� ����� ����� ���/���� (S/T)\n");
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
		inputFile(*a, *n, path1, path2, path3);//���� �� �����
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

void inputManually(station *a, int n) {//���� �������
	inputManuallyName(a, n);//���� ������� �������� �������
	inputManuallyConnection(a, n); //���� ������� ������ ����� ���������
	inputManuallyTogether(a, n);//���� ������� ����� �������
	return;
}

void inputManuallyName(station *a, int n) {//���� ������� �������� �������
	printf("�������� �������� �������\n");
	getchar();//������ \n
	for (int i = 0; i < n; i++) {
		printf("\t%d - ", i + 1);//������� ����� �������
		gets(a[i].name);//��������� �������� ������� � �������
	}//�������� �������� �������
	return;
}

void inputManuallyConnection(station *a, int n) {//���� ������� ������ ����� ���������
	for (int i = 0; i < n; i++) {
		printf("C������ ����� � %d \n", i + 1);//������� ����� �������
		printf("������� ���������� ������� ��������� � ���: ");//��� ����������
		scanf("%d", &a[i].c_connection);//�������� ���������� �������
		a[i].connection = (int*)malloc(sizeof(int) * 2 * a[i].c_connection);//��������� ������ ��� ���(����� � �������)
		for (int j = 0; j < a[i].c_connection; j++) {
			printf("%d -> ", i + 1);//����� ������ ����
			scanf("%d", &((a[i].connection)[j]));//���������� ������� ����
			(a[i].connection)[j] -= 1;
			printf("������� ����� ����������� ����� ���������: ");
			scanf("%d", &((a[i].connection)[a[i].c_connection + j]));//���� ������� ������� �� ����
		}
	}
	return;
}

void inputManuallyTogether(station *a, int n) {//���� ������� ����� �������
	printf("�������� ����� �������(��������� ����� �������)\n");
	for (int i = 0; i < n; i++) {
		printf("������� %d\n", i + 1);//������� ����� �������
		printf("������� ���������� ����� �������: ");
		scanf("%d", &a[i].c_together);//������ ���������� ����� �������
		if (a[i].c_together > 1) {//��� ������ �������� ������, ���� ������� ��������
			a[i].together = (int*)malloc(sizeof(int)*a[i].c_together);//��������� ������ ��� ����� �������
			for (int j = 0; j < a[i].c_together - 1; j++) {
				printf("������� �����: ");
				scanf("%d", &((a[i].together)[j]));//���� ����� �������
				(a[i].together)[j] -= 1;
			}
		}
	}
	return;
}

void inputFile(station *a, int n, char *path1, char *path2, char* path3) {//���� �� �����
	inputFileName(a, n, path1);//���� �� ����� �������� �������
	inputFileConnection(a, n, path2);//���� �� ����� ������ ����� ���������
	inputFileTogether(a, n, path3);//���� �� ����� ����� �������
	return;
}

void inputFileName(station *a, int n, char *path) {//���� �� ����� �������� �������
	FILE *f;//���������� ��� �����
	//char path[MAXSTRLN] = "nameMetro.txt";//----------------------------------------------------
	f = fopen(path, "r");//���������� f, ��� ������ ����� path(��������� ����)
	printf("�������� �������: \n");
	for (int i = 0; i < n; i++) {
		fgets(a[i].name, MAXSTRLN, f);//���������� �������� �������
		printf("%d - ", i + 1);
		puts(a[i].name);
	}
	fclose(f);
	return;
}

void inputFileConnection(station *a, int n, char *path) {//���� �� ����� ������ ����� ���������
	FILE *f;
	//char path[MAXSTRLN] = "SpbNetwork.bin";//---------------------------------------------------
	f = fopen(path, "rb");//���������� f, ��� ������ ����� path(�������� ����)
	for (int i = 0; i < n; i++) {
		fread(&(a[i].c_connection), sizeof(int), 1, f);//���������� �������
		printf("������� ���������� ������� ��������� � ���: %d", a[i].c_connection);
		printf("\n");
		a[i].connection = (int*)malloc(sizeof(int) * 2 * a[i].c_connection);//��������� ������ ��� ���(����� � �������)
		for (int j = 0; j < a[i].c_connection; j++) {
			fread(&(a[i].connection)[j], sizeof(int), 1, f);//����� �� ��������
			printf("%d -> %d", i + 1, (a[i].connection)[j] + 1);
			printf("\n");
			fread(&((a[i].connection)[a[i].c_connection + j]), sizeof(int), 1, f);//����� �� �������
			printf("������� ����� ����������� ����� ���������: %d", (a[i].connection)[a[i].c_connection + j]);
			printf("\n");
		}
	}
	fclose(f);
	return;
}

void inputFileTogether(station *a, int n, char *path) {//���� �� ����� ����� �������
	FILE *f;
	//char path[MAXSTRLN] = "general.bin";//-----------------------------------------------------
	f = fopen(path, "rb");//���������� f, ��� ������ ����� path(�������� ����)
	for (int i = 0; i < n; i++) {
		fread(&a[i].c_together, sizeof(int), 1, f);//��������� ���������� ����� �������
		if (a[i].c_together > 1) {
			a[i].together = (int*)malloc(sizeof(int)*a[i].c_together);
			for (int j = 0; j < a[i].c_together - 1; j++) {
				fread(&((a[i].together)[j]), sizeof(int), 1, f);//��������� � ����� � ��������� ���������� � ����� ��������
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
}//��������� ������

void dijkstra_1(station *a, int n, int *rez) { //����� ������ ��������� ���� �� �������
	int start;//������� ��������
	int u;//����� ����������� �� �����������
	int min;//���������� ������������ ��������
	int i, j, count;//��������
	int *was = (int*)malloc(sizeof(int)*n);//���������� �������
	for (i = 0; i < n; i++) {//�������� ������ �������� ������
		rez[i] = INT_MAX;//��������� ������������� �������� ��� ������� ����
		rez[n + i] = -1;//������ �������� ��� ���������� �������
		was[i] = 0;//��������� ������� ��������
	}
	printf("������� ������� ��������: ");
	scanf("%d", &start);//�������� ������� �������
	start -= 1;//��������� �� ������

	rez[start] = 0;//��������� �������

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//������������ �������� ���
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//���� �������� ������
			}
		was[u] = 1;//���� �� ������� u
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && rez[u] <= rez[(a[u].connection)[j]]) {//����� ����, ��� �����, ��-�� ������ ������������� � ������������ �������
					rez[(a[u].connection)[j]] = rez[u];//������� ���������
					rez[n + (a[u].connection)[j]] = u;//���������� ���������� �������
				}
			}
		for (i = 0; i < (a[u].c_together - 1); i++) {
			if (!was[(a[u].together)[i]] && rez[u] != INT_MAX && rez[u] < rez[(a[u].together)[i]]) {
				rez[(a[u].together)[i]] = rez[u] + 1;//������� ���������
				rez[n + (a[u].together)[i]] = u;//���������� ���������� �������
			}
		}
	}
	free(was);
	return;
}

void dijkstra_2(station *a, int n, int *rez) { //����� ������ ��������� ���� �� �������
	int start;//������� ��������
	int u;//����� ����������� �� �����������
	int min;//���������� ������������ ��������
	int i, j, count;//��������
	int *was = (int*)malloc(sizeof(int)*n);//���������� �������
	for (i = 0; i < n; i++) {//�������� ������ �������� ������
		rez[i] = INT_MAX;//��������� ������������� ��������
		rez[n + i] = -1;//������ �������� ��� ���������� �������
		was[i] = 0;//��������� ������� ��������
	}
	printf("������� ������� ��������: ");
	scanf("%d", &start);//�������� ������� �������
	start -= 1;//��������� �� ������

	rez[start] = 0;

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//������������ �������� ���
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//���� �������� ������
			}
		was[u] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && (rez[u] + 1)%1000 < (rez[(a[u].connection)[j]])%1000) {//����� ����, ��� �����, ��-�� ������ ������������� � ������������ �������
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

void dijkstra_3(station *a, int n, int *rez) { //����� ������ ��������� ���� �� �������
	int start;//������� ��������
	int u;//����� ����������� �� �����������
	int min;//���������� ������������ ��������
	int i, j, count;//��������
	int *was = (int*)malloc(sizeof(int)*n);//���������� �������
	for (i = 0; i < n; i++) {//�������� ������ �������� ������
		rez[i] = INT_MAX;//��������� ������������� ��������
		rez[n + i] = -1;//������ �������� ��� ���������� �������
		was[i] = 0;//��������� ������� ��������
	}
	printf("������� ������� ��������: ");
	scanf("%d", &start);//�������� ������� �������
	start -= 1;//��������� �� ������

	rez[start] = 0;

	for (count = 0; count < n; count++) {
		min = _CRT_INT_MAX;//������������ �������� ���
		for (i = 0; i < n; i++)
			if (!was[i] && (rez[i] <= min)) {
				min = rez[i];
				u = i;//���� �������� ������
			}
		was[u] = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < a[u].c_connection; j++) {
				if (!was[i] && rez[u] != INT_MAX && a[u].connection[j] == i && rez[u] + (a[u].connection)[j + a[u].c_connection] < rez[(a[u].connection)[j]]) {//����� ����, ��� �����, ��-�� ������ ������������� � ������������ �������
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
	printf("������� ������� ��������: ");
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