#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

void allocmem(double*** a, int m, int n)                         //выделение памяти для матрицы в ДП
{
	*a = (double**)calloc(m, sizeof(double*));
	for (int i = 0; i < m; i++)
		(*a)[i] = (double*)calloc(n, sizeof(double));
}

void freemem(double*** a, int m)                        //освобождение матрицы из ДП
{
	for (int i = 0; i < m; ++i)
		free((*a)[i]);
	free(*a);
}

void writeDoubleMas(double* a, int n)
{
	cout << fixed;

	cout.precision(3);

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
	cout << endl;
}

void writeIntMas(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void writeBoolMas(bool* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void writeMatr(double** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << fixed;

			cout.precision(3);

			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void readMatr(double** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
}

void initMas(double* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

void copyDoubleMass(double* b, double* a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}


bool straight_hod(double** a, int m, int n, int i1, int j1)                   //прямой ход метода Гаусса
{
	int k;
	double M;
	double max;
	int j = 0;
	if (a[i1][j1] != 0) //если нужный элемент != 0
	{
		for (int i = 0; i < m; i++)
		{
			if (i != i1)
			{
				M = -((a[i][j1]) / (a[i1][j1]));
				for (j = 0; j < n; j++)
				{
					a[i][j] += M * a[i1][j];
					if (fabs(a[i][j]) < 0.00001)
						a[i][j] = 0.0;
				}

			}
			else
			{
				M = a[i1][j1];
				for (int j = 0; j < n; j++)
				{
					a[i1][j] = a[i1][j] / M;
					if (fabs(a[i1][j]) < 0.00001)
						a[i1][j] = 0.0;
				}
				j = j1 + 1;
			}

		}
		return true;
	}
	else
	{
		//cout << "Базиса нет!" << endl;
		return false;
	}
}

bool TestNull(double** a, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
				return false;
	return true;
}

bool basicBasis(double* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			return false;

	return true;
}


void makeBoolArr(int* a, bool* mas, int n)
{
	for (int i = 0; i < n; i++)
		mas[i] = false;

	for (int i = 0; i < n; i++)
		if (a[i] >= 0)
			mas[a[i]] = true;
}

void makeNegMas(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = -1;
}

void copyMass(bool* b, bool* a, int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

int nullString(double** matr, int m, int n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (matr[i][j] == 0)
				count++;
			if (count >= n - 1)
				return (i);
		}
	}
	return -1;
}

int searchString(double** matr, int m, int n, int k)
{
	int count;
	int pos;
	//cout << "k =" << k << endl;
	//writeMatr(matr, m, n);
	for (int i = k; i < n; i++)
	{
		count = 0;
		pos = m - 1;
		for (int j = 0; j < m; j++)
		{
			if (matr[j][i] == fabs(0))
				count++;
			if (matr[j][i] == 1.0)
				pos = j;
			if (count == m - 1)
				return pos;
		}
	}
	cout << "базисный столбец не найден" << endl;
	return -1;
}

int compBoolMas(double** matr, bool* a, bool* b, int& k, int& count, int& i1, int& j1, double* bas, int m, int n)
{
	//cout << "Сравниваемые массивы" << endl;
   //writeBoolMas(a, n);
   //writeBoolMas(b, n);

	for (int i = k; i < n; i++)
	{
		while ((a[i] == b[i]) && (a[i] == 1))
		{
			i++;
			count++;
			k = i;
		}

		if ((b[i] == 1) && (a[i] == 0))
		{
			if ((b[2] == 1) && (b[3] == 1) && (b[4] == 1) && (i == 3))
			{
				i1 = m - 1;
				j1 = i;
				return (i + 2);
			}
			i1 = searchString(matr, m, n + 1, k);
			j1 = i;
			k = i;
			return i;

		}
	}
}

bool equalBoolMass(bool* a, bool* b, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;

	return true;
}

void nullDoubleMass(double* mas, int n)
{
	for (int i = 0; i < n; i++)
		mas[i] = 0.0;
}

void FirstBasis(double** matr, double* basis, bool* aArr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		straight_hod(matr, m, n, i, i);
	}

	for (int i = 0; i < m; i++)
		basis[i] = matr[i][n - 1];

	cout << endl;
	//	cout << "А вот и матрица!" << endl;
	//	cout << endl;
		//writeMatr(matr, m, n);

	if (basicBasis(basis, n - 1))
	{
		cout << "1-е Опорное решение" << endl;
		writeDoubleMas(basis, n - 1);
	}
	cout << "1-е Базисное решение " << endl;
	writeDoubleMas(basis, n - 1);
	int* a = new int[n];
	for (int i = 0; i < n - 1; i++)
		a[i] = 0;
	for (int i = 0; i < m; i++)
		a[i] = i;

	makeBoolArr(a, aArr, n - 1);
	//	cout << "первый булевский " << endl;
	//	writeBoolMas(aArr, n - 1);
		//cout << "ВЫвод закончен" << endl;
}

void makeBasis(double** matr, double* basis, int m, int n)
{
	int count;
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		pos = -1;
		count = 0;
		for (int j = 0; j < m; j++)
		{
			if (matr[j][i] == fabs(0))
				count++;
			if (matr[j][i] == 1.000)
				pos = j;

			if (count == m - 1)
			{
				if (pos != -1)
					basis[i] = matr[pos][n - 1];
				else
					basis[i] = matr[m - 1][n - 1];
			}
		}
	}
}

double targetFunction(double* a, int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i];

	return sum;
}

int combination(double** matr, int* a, int i, int pos, int m, int n, int n1, int k, bool* bArr, bool* aArr, double* bas, double& max, double* bestBasis)
{
	int i1 = 0;
	int j1 = 0;
	int x;

	int f = 0;
	for (x = pos; x <= (n1 - k + i); x++)
	{
		a[i - 1] = x;

		if (i == k)
		{
			//writeIntMas(a,k);
			printf("\n");
			makeBoolArr(a, bArr, n - 1);

			if (nullString(matr, m, n) != -1)
			{
				//cout << "NULL" << nullString(matr, m, n) << endl;
				delete[] matr[nullString(matr, m, n)];
				m = m - 1;
				//	cout << "Теперь столько строк " << m << endl;
			}

			int c = 0;
			int count = 1;
			nullDoubleMass(bas, n - 1);
			while (c < (n - 1))
			{
				if (!equalBoolMass(aArr, bArr, n - 1))
				{
					c = compBoolMas(matr, aArr, bArr, c, count, i1, j1, bas, m, n - 1);
					f = straight_hod(matr, m, n, i1, j1);
				}
				c++;
			}
			if (f)
			{
				//writeMatr(matr, m, n);
				cout << endl;
				//cout << "базис" << endl;
				makeBasis(matr, bas, m, n);

				if (basicBasis(bas, n - 1))
				{
					if (targetFunction(bas, n - 1) > max)
					{
						//max = targetFunction(bas, n - 1);
						copyDoubleMass(bestBasis, bas, n - 1);
						//cout << "max = " << max << endl;	
					}
					cout << "Опорное решение" << endl; ;

					writeDoubleMas(bas, n - 1);
				}
				cout << "Базисное решение" << endl; ;
				writeDoubleMas(bas, n - 1);
				nullDoubleMass(bas, n - 1);
			}
			copyMass(aArr, bArr, n - 1);

			printf("\n");
		}
		else combination(matr, a, i + 1, x + 1, m, n, n1, k, bArr, aArr, bas, max, bestBasis);
	}
	return 1;
}


int main()
{
	setlocale(LC_ALL, "rus");
	double** matr;
	int n, m;
	cout << "Введите строки и столбцы матрицы" << endl;
	cin >> m >> n;
	allocmem(&matr, m, n);

	bool* bArr = new bool[n];

	int* comb = new int[n];
	makeNegMas(comb, n);
	int k = m;

	cout << "Введите матрицу" << endl;
	readMatr(matr, m, n);
	int i1, j1;

	double* basis = new double[n];
	initMas(basis, n);

	bool* aArr = new bool[n - 1];
	FirstBasis(matr, basis, aArr, m, n);

	double max = 0.0;

	double* bestBasis = new double[n - 1];
	initMas(bestBasis, n);

	if (nullString(matr, m, n) != -1)
	{
		//cout << "NULL" << nullString(matr, m, n) << endl;
		delete[] matr[nullString(matr, m, n)];
		m = m - 1;
		//	cout << "Теперь столько строк " << m << endl;
	}

	k = m;
	double* bas = new double[n - 1];
	int n1 = n - 2;
	combination(matr, comb, 1, 0, m, n, n1, k, bArr, aArr, bas, max, bestBasis);

	//cout << "Оптимальное решение: " << endl;
	//writeDoubleMas(bestBasis, n - 1);

	return 0;
}

