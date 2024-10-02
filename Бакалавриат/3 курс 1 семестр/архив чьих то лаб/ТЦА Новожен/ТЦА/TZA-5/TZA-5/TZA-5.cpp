#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <array>

void dl(int** a, int m)
{
	for (size_t i = 0; i < m; i++)
	{
		delete[] a[i];

	}
	delete[] a;
	a = nullptr;
}


struct MyStruct
{
	int f1;
	int f2;
	int f3;
};

MyStruct   f123(int  x1, int  x2, int  x3, int  x4, int  x5)
{
	MyStruct str;
	int  z1 = x1 && !x2;
	int  z2 = !x1 && x4;// 01101
	int  z3 = x2 && !x3;
	int  z4 = x3 && !x5;
	int  z5 = !x3 && x4;
	int  z6 = x4 && x5;
	int  z7 = !x1 && x2;
	int  z8 = x3 && !x4;
	int  z9 = !x1 && !x3;
	int  z10 = !x4 && !x5;
	int  z11 = !x4 && x5;
	int  z12 = !x1 && !x2;
	int  z13 = !x1 && x2;

	int  h1 = x5 && z7;
	int  h2 = x4 && z4;


	int  u1 = z1 && z5;// 01101-
	int  u2 = z1 && z6;// 01101-
	int  u3 = z2 && z3;// 01101-
	int  u4 = z2 && z4;// 01101-
	int  u5 = z8 && h1;// 01101
	int  u6 = z9 && z10;
	int  u7 = z7 && z11;
	int  u8 = z8 && z12;
	int  u9 = z13 && h2;
	int  u10 = !x4 && z9;
	int  u11 = !x1 && z3;

	int  v1 = u1 || u2;
	int  v2 = u3 || u4;
	int  v3 = u6 || u7;
	int  v4 = u8 || u9;
	int  v5 = u10 || u11;


	int  g1 = u5 || v1;
	//01101
	int  f1 = v2 || g1;
	int  f2 = v3 || v4;
	int  f3 = v5 || u1;

	str.f1 = f1;
	str.f2 = f3;
	str.f3 = f2;
	return str;
}



/*
MyStruct   f2_123(int  x1, int  x2, int  x3, int  x4, int  x5)
{
	MyStruct str;


	int  z1 = !x1 && x3;
	int  z2 = x1 && !x2;
	int  z3 = !x1 && !x3;
	int  z4 = x4 && !x5;
	int  z5 = x2 && x4;
	int  z6 = x2 && !x4;
	int  z7 = !x3 && x4;
	int  z8 = x4 && x5;
	int  z9 = !x1 && !x2;
	int  z10 = x3 && !x4;

	int  h1 = x5 && z1;

	int  u1 = z1 && z4;
	int  u2 = z3 && z5;
	int  u3 = z6 && h1;
	int  u4 = z2 && z7;
	int  u5 = z2 && z8;
	int  u6 = !x4 && z3;
	int  u7 = z9 && z10;

	int  v1 = u2|| u4;
	int  v2 = u1 || u3;

	int  g1 = u5 ||v1;
	int  g2 = u6 || u7;

	int  f1 = v2 || g1;
	f1 =(!x1 && x3 && x4 && !x5) || (!x1 && x2 && !x3 && x4) || (!x1 && x2 && x3 && !x4 && x5) || (x1 && !x2 && !x3 && x4) || (x1 && !x2 && x4 && x5);
	int  f2 = u6 || v1;
	f2=(!x1 && x2 && !x3 && x4) || (x1 && !x2 && !x3 && x4) || (!x1 && !x3 && !x4);
	int  f3 = v2 || g2;
	f3=(!x1 && x3 && x4 && !x5) || (!x1 && x2 && x3 && !x4 && x5) || (!x1 && !x2 && x3 && !x4) || (!x1 && !x3 && !x4);

	str.f1 = f1;
	str.f2 = f2;
	str.f3 = f3;
	return str;
}
*/



MyStruct   f2_123(int  x1, int  x2, int  x3, int  x4, int  x5)
{
	MyStruct str;


	int  z1 = !x1 && x4;
	int  z2 = !x1 && x3;
	int  z3 = x1 && !x2;
	int  z4 = !x1 && !x4;
	int  z5 = x2 && !x3;
	int  z6 = x3 && !x5;
	int  z7 = x2 && !x4;
	int  z8 = !x3 && x4;
	int  z9 = x4 && x5;
	int  z10 = x2 && x4;
	int  z11 = !x2 && x3;


	int  z12 = !x1 && !x4;
	int  z13 = !x2 && !x5;

	int  h1 = x5 && z2;
	int  h2 = !x5 && z2;
	 


	int  u1 = z1 && z6;
	int  u2 = z1 && z5;
	int  u3 = z7 && h1;
	int  u4 = z3 && z8;
	int  u5 = z3 && z9;
	int  u6 = h2 && z10;
	int  u7 = z4 && z11;
	int  u8 = z4 && z5;
	int  u9 = !x3 && z12;
	int  u10 = z13 && z12;

	int  v1 = u3 || u6;
	int  v2 = u1 || u2;
	int  v3 = u4 || u5;
	int  v4 = u4 || u8;
	int  v5 = u7 || u8;


	int  g1 = v2 || v1;
	int  g2 = u10 || v1;

	int  f1 = v3 || g1;
	int  f2 = v4 || u9;
	int  f3 = v5 || g2;
/*
	int  f1 = v2 || g1;
	f1 = (!x1 && x3 && x4 && !x5) || (!x1 && x2 && !x3 && x4) || (!x1 && x2 && x3 && !x4 && x5) || (x1 && !x2 && !x3 && x4) || (x1 && !x2 && x4 && x5);
	int  f2 = u6 || v1;
	f2 = (!x1 && x2 && !x3 && x4) || (x1 && !x2 && !x3 && x4) || (!x1 && !x3 && !x4);
	int  f3 = v2 || g2;
	f3 = (!x1 && x3 && x4 && !x5) || (!x1 && x2 && x3 && !x4 && x5) || (!x1 && !x2 && x3 && !x4) || (!x1 && !x3 && !x4);
*/
	str.f1 = f1;
	str.f2 = f2;
	str.f3 = f3;
	return str;
}


void GetVector(int* vect, int pos, int** matr, int m, int n)
{
	static int s = 0;
	for (size_t i = 0; i < 2; i++)
	{
		vect[pos] = i;
		if (pos == n - 1)
		{
			for (int j = 0; j < n; ++j)
			{
				matr[s][j] = vect[j];
				//std::cout << vect[j];
			}
			//std::cout << '\n';
			++s;
		}
		else GetVector(vect, pos + 1, matr, m, n);
	}
}

int** GetTableTrue(int m, int n)
{
	int** matr = new int* [m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new int[n  +3/*+1+ 1 + 1 + 1 + 1*/];
	}
	auto vect = new int[n];
	GetVector(vect, 0, matr, m, n);
	delete[] vect;
	return matr;
}

//Вычисление функции f1,f2,f3
void fun(int** a, int m, int n)
{
	for (int j = 0; j < n; ++j)
	{
			std::cout  << j;
	}
	std::cout << "|f1|f2|f3\n";
	for (size_t i = 0; i < m; i++)
	{
		int t1 = 2 * (a[i][1] ? 1 : 0) + 1 * (a[i][2] ? 1 : 0) + 4 * (a[i][3] ? 1 : 0) + 2 * (a[i][4] ? 1 : 0) + 1 * (a[i][0] ? 1 : 0);
		int g11 = (5 <= t1) && (t1 <= 8);		//5≤(x2x3 + x4x5x1)≤8

		t1 = 2 * (a[i][0] ? 1 : 0) + 1 * (a[i][1] ? 1 : 0) + 4 * (a[i][2] ? -1 : 0) + 2 * (a[i][3] ? -1 : 0) + 1 * (a[i][4] ? -1 : 0);
		int g12 = (-2 <= t1) && (t1 <= 1);		

	    t1 = 2 * (a[i][1] ? 1 : 0) + 1 * (a[i][2] ? 1 : 0) + 4 * (a[i][3] ? -1 : 0) + 2 * (a[i][4] ? -1 : 0) + 1 * (a[i][0] ? -1 : 0);
		int g13 = (-2 < t1) && (t1 <= 3);

		t1 = 2 * (a[i][3] ? 1 : 0) + 1 * (a[i][4] ? 1 : 0) + 4 * (a[i][0] ? -1 : 0) + 2 * (a[i][1] ? -1 : 0) + 1 * (a[i][2] ? -1 : 0);
		int g14 = (-2 <= t1) && (t1 < 2);

		a[i][n] = g11 && g14;
		a[i][n+1] = g12 && g14;
		a[i][n+2] = g13 && g14;

		for (int j = 0; j < n; ++j)
		{
			std::cout << (a[i][j] ? 1 : 0);
		}
		std::cout << "|" << (a[i][n] ? 1 : 0) << " |" << (a[i][n + 1] ? 1 : 0) << " |" << (a[i][n + 2] ? 1 : 0);// << '\n';

		auto tr = f123(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		std::cout << "  |" << (tr.f1 ? 1 : 0) << " |" << (tr.f2 ? 1 : 0) << " |" << (tr.f3 ? 1 : 0) << " |";// << '\n';
		
		
		auto tr1 = f2_123(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		std::cout << "  |" << (tr1.f1 ? 1 : 0) << " |" << (tr1.f2 ? 1 : 0) << " |" << (tr1.f3 ? 1 : 0) << '\n';

	}
}

void comp1(int** a, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		if (a[i][n])
		{
			std::string t;
			t = "(";
			t += (a[i][0] ? "x1" : "!x1");
			t += "*";
			t += (a[i][1] ? "x2" : "!x2");
			t += "*";
			t += (a[i][2] ? "x3" : "!x3");
			t += "*";
			t += (a[i][3] ? "x4" : "!x4");
			t += "*";
			t += (a[i][4] ? "x5" : "!x5");
			t += ")";
			std::cout << t << " + ";
			//std::cout << '|' << (a[i][n] ? 1 : 0) << '\n';
		}
	}
	std::cout << "\n";
}

int main()
{
	//f123(0, 1, 1, 0, 1);
	setlocale(LC_ALL, "Russian");
	int n = 5;
	int m = 32;
	auto a = GetTableTrue(m, n);
	fun(a, m, n);
	std::cout << " f1 :\n";
	comp1(a, m, n);
	std::cout << " f2 :\n";
	comp1(a, m, n+1);
	std::cout << " f3 :\n";
	comp1(a, m, n+2);



}

