#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"

//��������� ������
const short NoSolution = 0; //��� �������
const short Ok = 1; //�������� ������
const short ZERO = 2; //������� �� ����
double EPS = 0.1;
short Err; //���������� ������
int countP; //���-�� ����������� � �������
int countEq; //���-�� ��������� � �������
void copyTabMatrInArr(double** matr, double* res, int tab);//����������� tab ��������� ������� matr � res ������
int stop(double* tmpRes, double* res);//������� ���������: 1 - ������� ������� � ������ ���������, ����� 0
void iterationMethod(double** matr, double* res);//������� ��� ������� ��������
double accuracyCalc(double normB);//�������� ����������
int countIteration(double normB, double normC);//������ ����� ��������
int proverka(double *str, int lenStr, int currentElem);//�������� ������ ������� �� ������������ ������������: 1 - �������������, ����� 0
double Approximation(double **matr);//����������� ����� ������� ���������� �����������
double normFirst(double **matr);//���������� 1 ����� �������
double normEndless(double **matr);//���������� ����������� ����� �������
void additionArr(double *a, double *b, double *res, int size);//�������� ���� �������
void subtractionArr(double *a, double *b, double *res, int size);//��������� ���� ��������
void outputMatr(double **matr);//����� �������
void swapStrMatr(double **matr, int i, int j);//������ ������ ������� �������
void copyArr(double *arr1, double *arr2, int size);//����������� ������ ������� �� ������
double** initMatr(void);//������������� ������� (������ �������� �� �����)
double *getMamorArr(int n);//��������� ������ �������
void freeMemorArr(double *arr);//�������� ������ �������
double **getMemorMatr();//��������� ������ �������
void freeMemorMatr(double **matr);//�������� ������ �������
void pravn(double **matr);//���������� ������� � ��������� �����
void virach_perem(double **matr);//��������� ����������

int main() {
	setlocale(0, "Rus");
	printf("������� ���-�� ��������� � ������� � ���-�� ����������� ");
	scanf("%d%d", &countP, &countEq);
	double** matr = initMatr();//������� ����������� ���
	double* res = getMamorArr(countP);//��������� ������
	iterationMethod(matr, res);//������� ��� ������� ��������
	if (Err == Ok) {
		printf("\n���������:\n");
		for (int i = 0; i < countP; i++)
			printf("%2.4lf\n", res[i]);
	}
	else
		printf("\n������� ��� \n");
	freeMemorArr(res);
	freeMemorMatr(matr);
	getchar();
	getchar();
	return 0;
}

//������� ��� ������� ��������
void iterationMethod(double** matr, double* res) {
	if (countP > countEq) {//�������� �� ������� �������
		Err = NoSolution;
		return;
	}
	pravn(matr);//���������� ������� � ���������� ����
	outputMatr(matr);
	printf("\n");
	virach_perem(matr);//��������� �����������
	outputMatr(matr);
	printf("\n");
	double normC = Approximation(matr);//����������� ����� ������� ���������� �����������
	double normB1 = normFirst(matr);//���������� 1 ����� �������
	double normBn = normEndless(matr);//���������� ����������� ����� �������	
	double normB = (normB1 < normBn) ? normB1 : normBn;//����� ���������� �����	
	int countIter = countIteration(normB, normC);//������ ����� ��������	
	EPS = accuracyCalc(normB);//�������� ����������
	printf("E = %lf\n", EPS);	
	double* tmpRes = getMamorArr(countP);// ��� �������� �� ��������� ���������� �����������
	copyTabMatrInArr(matr, tmpRes, countP);	
	int q = 0;//���������� ����������� � ������� �������
	while (q < countIter) {
		q++;
		int i, j;
		for (i = 0; i < countP; i++) {
			res[i] = 0;
			for (j = 0; j < countP; j++)
				res[i] += matr[i][j] * tmpRes[j];
			res[i] += matr[i][countP];
		}
		if (stop(tmpRes, res)) {//������� ���������
			Err = Ok;
			freeMemorArr(tmpRes);
			return;
		}
		else {
			copyArr(res, tmpRes, countP);
			int t;
			for (t = 0; t < countP; t++)
				printf("%lf ", res[t]);
			printf("\n");
		}
	}
	if (q == countIter)
		Err = NoSolution;
	freeMemorArr(tmpRes);
	getchar();
	getchar();
}

//����������� tab ��������� ������� matr � res ������
void copyTabMatrInArr(double** matr, double* res, int tab) {
	for (int i = 0; i < countP; i++)
		res[i] = matr[i][tab];
}

//������� ���������: 1 - ������� ������� � ������ ���������, ����� 0
int stop(double* tmpRes, double* res) {
	double max = 0, f = 0;
	for (int i = 0; i < countP; i++)
		if ((f = fabs(res[i] - tmpRes[i])) > max)
			max = f;
	return (max <= EPS) ? 1 : 0;
}

//�������� ����������
double accuracyCalc(double normB) {
	return (double)(1 - normB)*EPS / normB;
}

//������ ����� ��������
int countIteration(double normB, double normC) {
	return (int)(log(EPS) + log(1 - normB) - log(normC)) / log(normB);
}

//��������� ����������
void virach_perem(double **matr) {
	double *tmp = getMamorArr(countEq);
	for (int i = 0; i < countEq; i++) {//����� �� �������
		tmp[i] = matr[i][i]; // ��������� X
		matr[i][i] = 0;
		for (int j = 0; j < countEq; j++)//������ ����� �� ��������������
			if (i != j)
				matr[i][j] = -matr[i][j];
	}
	for (int i = 0; i < countEq; i++) 
		for (int j = 0; j < (countEq + 1); j++)
			if (tmp[i] != 0)
				matr[i][j] = matr[i][j] / tmp[i];
			else {
				Err = ZERO;
				return;
			}
}

//���������� 1 ����� ������� (������)
double normFirst(double **matr) {
	double sum = 0;//���� ������������ ����� �� ������ � ��������
	double MaxSum = 0;
	for (int i = 0; i < countEq; i++) {
		for (int j = 0; j < countEq; j++)
			sum += fabs(matr[j][i]);
		if (MaxSum < sum) MaxSum = sum;
		sum = 0;
	}
	return MaxSum;
}

//����������� ����� ������� ���������� �����������
double Approximation(double **matr) {
	double max = 0;
	for (int i = 0; i < countEq; i++)
		if (fabs(matr[i][countEq]) > max) 
			max = fabs(matr[i][countEq]);
	return max;
}

//���������� ����������� ����� ������� (������)
double normEndless(double **matr) {
	double sum = 0;//���� ������������ ����� �� ������ � �������
	double MaxSum = 0;
	for (int i = 0; i < countEq; i++) {
		for (int j = 0; j < countEq; j++)
			sum += fabs(matr[i][j]);
		if (MaxSum < sum) MaxSum = sum;
		sum = 0;
	}
	return MaxSum;
}

//������ ������ ������� �������
void swapStrMatr(double **matr, int i, int j) {
	double *tmp = matr[i];
	matr[i] = matr[j];
	matr[j] = tmp;
}

//����������� arr1 ������� � ������ arr2
void copyArr(double *arr1, double *arr2, int size) {
	for (int i = 0; i < size; i++)
		arr2[i] = arr1[i];
}

//�������� ���� �������
void additionArr(double *a, double *b, double *res, int size) {
	for (int i = 0; i < size; i++)
		res[i] = a[i] + b[i];
}

//��������� ���� ��������
void subtractionArr(double *a, double *b, double *res, int size) {
	for (int i = 0; i < size; i++)
		res[i] = a[i] - b[i];
}

//���������� ������� � ��������� �����
void pravn(double **matr) {
	int flag = 1;
	for (int i = 0; i < countEq; i++) {	//����� �� ������� �������
		if (!proverka(matr[i], countEq, i)) {	//���� ������ �� ������������� ������ �������
			for (int j = i + 1; j < countEq; j++)//������ �������
				if (proverka(matr[j], countEq, i)) {
					swapStrMatr(matr, i, j);
					flag = 0;
				}			
			if (flag) {//������ �������				
				double *arrTmp = getMamorArr(countEq + 1);// ������ �������������� ������, ��� �������������
				copyArr(matr[i], arrTmp, countEq + 1);				
				int j = 0;//����������� ������ ���������
				while (!proverka(arrTmp, countEq, i) && (j < countEq)) {
					if (j != i)
						additionArr(arrTmp, matr[j], arrTmp, countEq + 1);
					j++;
				}				
				if (!proverka(arrTmp, countEq, i)) {//���� ������ ������� �� �������
					copyArr(matr[i], arrTmp, countEq + 1);					
					int j = 0;//����������� ������ ���������
					while (!proverka(arrTmp, countEq, i) && (j < countEq)) {
						//subtractionArr(arrTmp, matr[j++], arrTmp, countEq + 1);
						if (j != i) {
							subtractionArr(matr[j], arrTmp, arrTmp, countEq + 1);
						}
						j++;
					}					
					if (!proverka(arrTmp, countEq, i)) {//���� ������ �� �������
						printf("�� ������� �������� � ��������� �����\n");
						return;
					}
					else 
						copyArr(arrTmp, matr[i], countEq + 1);
				}
				else 
					copyArr(arrTmp, matr[i], countEq + 1);
			}
		}
		flag = 1;
	}
}

//������������� ������� (������ �������� �� �����)
double** initMatr(void) {
	double **matr = getMemorMatr();
	FILE *f = fopen("we.txt", "r");
	for (int i = 0; i < countEq; i++)
		for (int j = 0; j <= countEq; j++)
			fscanf(f, "%lf", &matr[i][j]);
	fclose(f);
	return matr;
}

//����� �������
void outputMatr(double **matr) {
	for (int i = 0; i < countEq; i++) {
		for (int j = 0; j <= countEq; j++)
			printf("%lf ", matr[i][j]);
		printf("\n");
	}
}

//�������� ������ ������� �� ������������ ������������: 1 - �������������, ����� 0
int proverka(double *str, int lenStr, int currentElem) {
	double sum = 0;
	for (int i = 0; i < lenStr; i++)
		if (i != currentElem)
			sum += fabs(str[i]);
	return (fabs(str[currentElem]) > sum) ? 1 : 0;
}

//��������� ������ �������
double *getMamorArr(int n) {
	double *arr = (double *)malloc(n * sizeof(double));
	return arr;
}

//�������� ������ �������
void freeMemorArr(double *arr) {
	free(arr);
}

//��������� ������ �������
double **getMemorMatr() {
	double** matr = (double**)malloc(countEq * sizeof(double *));
	for (int i = 0; i < countEq; i++)
		matr[i] = (double *)malloc((countEq + 1) * sizeof(double));
	return matr;
}

//�������� ������ �������
void freeMemorMatr(double **matr) {
	for (int i = 0; i < countEq; i++)
		free(matr[i]);
	free(matr);
}