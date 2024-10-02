
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



void GetVector(int * vect, int pos, int ** matr, int m, int n)
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

int ** GetTableTrue(int m, int n)
{
	int ** matr = new int * [m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new int [n + 1 + 1 + 1 + 1 + 1];
	}

	auto vect = new int [n];
	GetVector(vect, 0, matr, m, n);
	delete[] vect;
	return matr;
}
//Вычисление функции f(x1,x2,x3,x4,x5)
void fun(int ** a, int m, int n)
{
	//for (int j = 0; j < n; ++j)
	{
		//	std::cout  << j;
	}
	//std::cout << "|f\n";
	for (size_t i = 0; i < m; i++)
	{
		int t2 = 4 * (a[i][3] ? 1 : 0) + 2 * (a[i][4] ? 1 : 0) + 1 * (a[i][0] ? 1 : 0);
		int t22 =t2==1 ? 1 : 0; //(x4x5x1) = 1
		if (t22==0) {
			int t1 = 2 * (a[i][1] ? 1 : 0) + 1 * (a[i][2] ? 1 : 0) + 4 * (a[i][3] ? 1 : 0) + 2 * (a[i][4] ? 1 : 0) + 1 * (a[i][0] ? 1 : 0);
			int t11 = (5 <= t1) && (t1 <= 8);		//5≤(x2x3 + x4x5x1)≤8
			a[i][n] = t11;
		}
		else a[i][n] = -1;
	for (int j = 0; j < n; ++j)
		{
			std::cout << (a[i][j] ? 1 : 0);
		}
	if(a[i][n]==-1)std::cout << "|-" << '\n';
	else std::cout <<'|' << (a[i][n] ? 1 : 0)  << '\n';
	}
}
void comp1(int ** a, int m, int n)
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
}
void comp0(int ** a, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		if (!a[i][n])
		{
			std::string t;
			t = "(";
			t += (!a[i][0] ? "x1" : "!x1");
			t += "+";
			t += (!a[i][1] ? "x2" : "!x2");
			t += "+";
			t += (!a[i][2] ? "x3" : "!x3");
			t += "+";
			t += (!a[i][3] ? "x4" : "!x4");
			t += "+";
			t += (!a[i][4] ? "x5" : "!x5");
			t += ")";
			std::cout << t << " * ";
			//std::cout << '|' << (a[i][n] ? 1 : 0) << '\n';
		}
	}
}



//DNF

int   f1(int  x1, int  x2, int  x3, int  x4, int  x5)
{
	int  w = 0;
	int  z1 = x2 && x3;
	int  z2 = !x4 && x5;
	int  z3 = x1 && x2;
	int  z4 = !x1 && x2;
	int  z5 = !x3 && x4;
	int  z6 = !x2 && x4;
	int  z7 = x3 && x4;

	int  u1 = z1 && z2;
	int  u2 = !x4 && z3;
	int  u3 = x1 && !x5;
	int  u4 = z4 && z5;
	int  u5 = x5 && z6;
	int  u6 = !x5 && z7;

	int  v1 = u1 || u2;
	int  v2 = u3 || u4;
	int  v3 = u5 || u6;

	int  w = v1 || v2;
	int  f = v3 || w;
	return f;
}

//KNF

int   f2(int  x1, int  x2, int  x3, int  x4, int  x5)
{
	int  z1 = !x2 || !x4;
	int  z2 = x1 || x3;
	int  z3 = x1 || x2;
	int  z4 = x3 || x5;
	int  z5 = !x3 || !x5;
	int  z6 = !x1 || !x5;

	int  u1 = x4 || x5;
	int  u2 = x2 || x4;
	int  u3 = z2 || x4;
	int  u4 = z3 || z4;
	int  u5 = z1 || z5;
	int  u6 = z1 || z6;

	int  v1 = u1 && u2;
	int  v2 = u3 && u4;
	int  v3 = u5 && u6;

	int  w = v1 && v2;

	int  f = v3 && w;
	return f;


}


void viev_lab3(int ** a, int m, int n)
{
	std::cout << "\n12345|f |f1|f2|f3|f4\n";
	for (size_t i = 0; i < m; i++)
	{
		a[i][n + 1] = (a[i][1] && a[i][2] && !a[i][3] && a[i][4]) || (a[i][0] && a[i][1] &&  !a[i][3]) || (a[i][0] && !a[i][4]) || (!a[i][0] && a[i][1] && !a[i][2] && a[i][3]) || (!a[i][1] && a[i][3] && a[i][4]) || (a[i][2] && a[i][3] && !a[i][4]);
		a[i][n + 2] = (a[i][3] || a[i][4]) && (a[i][1] || a[i][3]) && (a[i][0] || a[i][2] || a[i][3]) && (a[i][0] || a[i][1] || a[i][2] || a[i][4]) && (!a[i][1] || !a[i][2] || !a[i][3] || !a[i][4]) && (!a[i][0] || !a[i][1] || !a[i][3] || !a[i][4]);
		a[i][n + 3] = f1(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		a[i][n + 4] = f2(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);

		for (int j = 0; j < n; ++j)
		{
			std::cout << (a[i][j] ? 1 : 0);
		}
		if (a[i][n] != -1)std::cout << "|" << (a[i][n] ? 1 : 0);
		else std::cout << "|-";
		std::cout << "|" << (a[i][n + 1] ? 1 : 0)
				  << "|" << (a[i][n + 2] ? 1 : 0) 
				  << "|" << (a[i][n + 3] ? 1 : 0) 
				  << "|" << (a[i][n + 4] ? 1 : 0)
				  << '\n';
	}
}

int   f31(int  x1, int  x2, int  x3, int  x4, int  x5)//и не
{
	int  a1 = !(x2 && x2);
	int  a2 = !(x4 && x4);
	int  a3 = !(x1 && x1);
	int  a4 = !(x3 && x3);

	int  b1 = !(x4 && a1);
	int  b2 = !(x2 && a2);
	int  b3 = !(x1 && x5);
	int  b4 = !(x3 && x5);
	int  b5 = !(x2 && a3);
	int  b6 = !(x4 && a4);
	int  b7 = !(x2 && x4);

	int  z1 = !(b1 && b1);
	int  z2 = !(b2 && b2);
	int  z3 = !(b3 && b3);
	int  z4 = !(b4 && b4);
	int  z5 = !(b5 && b5);
	int  z6 = !(b6 && b6);
	int  z7 = !(b7 && b7);


	int  c1 = !(x5 && x5);

	int  u1 = !(z2 && z3);
	int  u2 = !(z2 && z4);
	int  u3 = !(z5 && z6);
	int  u4 = !(z1 && x5);
	int  u5 = !(z1 && x3);
	int  u6 = !(z7 && c1);
	int  u7 = !(z1 && x1);

	int  v3 = !(u5 && u6);
	int  v1 = !(u1 && u2);
	int  v2 = !(u3 && u4);

	int  d1 = !(v1 && v1);
	int  d2 = !(v2 && v2);
	int  d3 = !(v3 && v3);

	int  w1 = !(d1 && u7);
	int  w2 = !(d3 && d2);

	int  e1 = !(w1 && w1);
	int  e2 = !(w2 && w2);

	int  f = !(e1 && e2);

	return f;
}

int   f32(int  x1, int  x2, int  x3, int  x4, int  x5)//или не 
{

	int  a1 = !(x4 || x4);
	int  a2 = !(x2 || x2);
	int  a3 = !(x1 || x1);
	int  a5 = !(x3 || x3);
	int  a6 = !(x5 || x5);
	int  a7 = a2;
	int  a8 = a1;
	int  a9 = a2;
	int  a10 = a1;
	int  a4 = a6;

	int  z1 = !(x2 || a1);
	int  z2 = !(x4 || a2);
	int  z3 = !(a3 || a4);
	int  z4 = !(a5 || a6);
	int  z5 = !(x1 || a7);
	int  z6 = !(x3 || a8);
	int  z7 = !(a9 || a10);


	int  b1 = !(z2 || z2);
	int  b2 = !(z3 || z3);
	int  b3 = b1;
	int  b4 = !(z4 || z4);
	int  b5 = !(z5 || z5);
	int  b6 = !(z6 || z6);
	int  b7 = !(z1 || z1);
	int  b8 = a6;
	int  b9 = b7;
	int  b10 = a5;
	int  b11 = !(z7 || z7);
	int  b12 = b7;
	int  b13 = a3;


	int  u1 = !(b1 || b2);
	int  u2 = !(b3 || b4);
	int  u3 = !(b5 || b6);
	int  u4 = !(b7 || b8);
	int  u5 = !(b9 || b10);
	int  u6 = !(x5 || b11);
	int  u7 = !(b12 || b13);


	int  c1 = !(u1 || u2);
	int  c2 = !(u3 || u4);
	int  c3 = !(u5 || u6);


	int  v1 = !(c1 || c1);
	int  v2 = !(c2 || c2);
	int  v3 = !(c3 || c3);

	int  d1 = !(v1 || u7);
	int  d2 = !(v2 || v3);


	int  w1 = !(d1 || d1);
	int  w2 = !(d2 || d2);

	int  e1 = !(w1 || w2);

	int  f = !(e1 || e1);
	return f;
}
int   f51(int  x1, int  x2, int  x3, int  x4, int  x5)//и не
{
	int  a1 = !(x1 && x1);
	int  a2 = !(x3 && x3);
	int  a3 = !(x5 && x5);
	int  a4 = !(x2 && x2);

	int  z1 = !(a1 && a2);
	int  z2 = !(x2 && x4);
	int  z3 = !(x1 && x5);
	int  z4 = !(x3 && x5);
	int  z5 = !(a3 && a4);

	int  b1 = a4;
	int  b3 = !(z3 && z3);
	int  b5 = !(z2 && z2);
	int  b4 = b5;
	int  b6 = !(z4 && z4);
	int  b7 = !(z1 && z1);
	int  b8 = !(x4 && x4);
	int  b9 = b7;
	int  b10 = !(z5 && z5);
	int  b2 = b8;
	int  b11 = b8;
	int  b12 = a3;

	int  u1 = !(b3 && b4);
	int  u2 = !(b5 && b6);
	int  u3 = !(b9 && b10);
	int  u4 = !(b1 && b2);
	int  u5 = !(b11 && b12);
	int  u6 = !(b7 && b8);

	int  c1 = !(u4 && u3);
	int  c2 = !(u1 && u2);
	int  c3 = !(u5 && u6);

	int  v1 = !(c2 && c2);
	int  v2 = !(c1 && c1);
	int  v3 = !(c3 && c3);

	int  d1 = !(v1 && v2);

	int  w1 = !(d1 && d1);

	int  e1 = !(w1 && v3);

	int  f = !(e1 && e1);
	return f;
}
int   f52(int  x1, int  x2, int  x3, int  x4, int  x5)//или не 
{
	int  a1 = !(x2 || x2);
	int  a2 = !(x4 || x4);
	int  a3 = !(x1 || x1);
	int  a4 = !(x5 || x5);
	int  a5 = a4;
	int  a6 = !(x3 || x3);

	int  b1 = !(x1 || x3);
	int  b2 = !(a1 || a2);
	int  b3 = !(a3 || a4);
	int  b4 = !(a5 || a6);
	int  b5 = !(x2 || x5);


	int  z1 = !(b1 || b1);
	int  z2 = !(b2 || b2);
	int  z3 = !(b3 || b3);
	int  z4 = !(b4 || b4);
	int  z5 = !(b5 || b5);

	int  u1 = !(z3 || z2);
	int  u2 = !(z2 || z4);
	int  u3 = !(z1 || z5);
	int  u4 = !(x2 || x4);
	int  u5 = !(x4 || x5);
	int  u6 = !(z1 || x4);

	int  v1 = !(u1 || u2);
	int  v2 = !(u4 || u3);
	int  v3 = !(u5 || u6);

	int  c1 = !(v2 || v2);
	int  c2 = !(v1 || v1);

	int  w1 = !(c1 || c2);

	int  d1 = !(w1 || w1);
	int  d2 = !(v3 || v3);

	int  f = !(d1 || d2);
	return f;
}

void viev_lab2(int ** a, int m, int n)
{
	std::cout << "| 1 | 2 | 3 | 4 | 5 | f |f31|f32|f51|f52|\n";
	for (size_t i = 0; i < m; i++)
	{
		a[i][n + 1] = f31(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		a[i][n + 2] = f32(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		a[i][n + 3] = f51(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		a[i][n + 4] = f52(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);

		for (int j = 0; j < n; ++j)
		{
			std::cout << "| " << (a[i][j] ? 1 : 0) << ' ';
		}
		std::cout << "| "
			<< (a[i][n] ? 1 : 0)
			<< " | "
			<< (a[i][n + 1] ? 1 : 0)
			<< " | "
			<< (a[i][n + 2] ? 1 : 0)
			<< " | "
			<< (a[i][n + 3] ? 1 : 0)
			<< " | "
			<< (a[i][n + 4] ? 1 : 0)
			<< " | "
			<< '\n';
	}
}


void test()
{
	f1(false, false, true, true, true);
	f2(false, false, true, true, true);
}
void comp111(std::vector<std::array<int, 5>> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
			std::string t;
			t = "(";
			if (a[i][0] != -1) {
				t += (a[i][0] ? "x1" : "!x1");
				t += "*";
			}
			if (a[i][1] != -1) {
				t += (a[i][1] ? "x2" : "!x2");
				t += "*";
			}
			if (a[i][2] != -1) {
				t += (a[i][2] ? "x3" : "!x3");
				t += "*";
			}
			if (a[i][3] != -1) {
				t += (a[i][3] ? "x4" : "!x4");
				t += "*";
			}
			if (a[i][4] != -1) {
				t += (a[i][4] ? "x5" : "!x5");
			}
			t += ")";
			std::cout << t << " + ";
			//std::cout << '|' << (a[i][n] ? 1 : 0) << '\n';
	}
}

void comp000(std::vector<std::array<int, 5>> a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		std::string t;
		t = "(";
		if (a[i][0] != -1) {
			t += (!a[i][0] ? "x1" : "!x1");
			t += "+";
		}
		if (a[i][1] != -1) {
			t += (!a[i][1] ? "x2" : "!x2");
			t += "+";
		}
		if (a[i][2] != -1) {
			t += (!a[i][2] ? "x3" : "!x3");
			t += "+";
		}
		if (a[i][3] != -1) {
			t += (!a[i][3] ? "x4" : "!x4");
			t += "+";
		}
		if (a[i][4] != -1) {
			t += (!a[i][4] ? "x5" : "!x5");
		}
		t += ")";
		std::cout << t << " * ";
		//std::cout << '|' << (a[i][n] ? 1 : 0) << '\n';
	}
}

bool searc_eaqvel(std::vector<std::array<int, 5>> v, std::array<int, 5> arr)
{
	int count = 2;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		count = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if (arr[j] != -1)count++;
		}

		for (size_t j = 0; j < 5; j++)
		{
			if (arr[j] == -1)continue;
			if (arr[j] == it->at(j)) count--;
		}
		if (count==0)break;
	}
	return count == 0;
}
void compsk(int** a, int m, int n)//1 lvl склеик
{
	std::vector<std::array<int, 5>> vect1;
	std::vector<std::array<int, 5>> vect0;
	for (size_t i = 0; i < m; i++)
	{
		std::array<int,5> arr;
		if (a[i][5]==1)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[j] = a[i][j];
			}
			vect1.push_back(arr);//массив где ф равна 1
		}
		if (a[i][5] == 0)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[j] = a[i][j];
			}
			vect0.push_back(arr);//массив где ф равна 0
		}
	}


	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1**************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";

	std::vector<std::array<int, 5>> vect1_1;//1шаг
	for (int it = 0; it < vect1.size(); it++)
	{
		int k = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if (vect1[it][j] != -1)
			{
				int tt = vect1[it][j];
				vect1[it][j] = -1;
				if ((searc_eaqvel(vect0, vect1[it]) == false))
					if ((searc_eaqvel(vect1_1, vect1[it]) == false))
						vect1_1.push_back(vect1[it]), ++k;
					else ++k;
				vect1[it][j] = tt;
			}
		}
		if ((k == 0) && (searc_eaqvel(vect1_1, vect1[it]) == false))
			vect1_1.push_back(vect1[it]);
	}
	std::cout << "Первая склейка\n";
	for (auto it = vect1_1.begin(); it != vect1_1.end(); it++)
	{
		for (auto i = it->begin(); i < it->end(); i++)
		{
			if (*i == -1)std::cout << '-';
			else std::cout << *i;
		}
		std::cout << "\n";
	}
		std::vector<std::array<int, 5>> vect1_2;//2шаг
		for (int it = 0; it < vect1_1.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect1_1[it][j] != -1)
				{
					int tt = vect1_1[it][j];
					vect1_1[it][j] = -1;
					if ((searc_eaqvel(vect0, vect1_1[it]) == false))
						if ((searc_eaqvel(vect1_2, vect1_1[it]) == false))
							vect1_2.push_back(vect1_1[it]), ++k;
						else ++k;
					vect1_1[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect1_2, vect1_1[it]) == false))
				vect1_2.push_back(vect1_1[it]);
		}
		std::cout << "Вторая склейка\n";
		for (auto it = vect1_2.begin(); it != vect1_2.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}

		std::vector<std::array<int, 5>> vect1_3;//3шаг
		for (int it = 0; it < vect1_2.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect1_2[it][j] != -1)
				{
					int tt = vect1_2[it][j];
					vect1_2[it][j] = -1;
					if ((searc_eaqvel(vect0, vect1_2[it]) == false))
						if ((searc_eaqvel(vect1_3, vect1_2[it]) == false))
							vect1_3.push_back(vect1_2[it]), ++k;
						else ++k;
					vect1_2[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect1_3, vect1_2[it]) == false))
				vect1_3.push_back(vect1_2[it]);
		}
		std::cout << "Третья склейка\n";
		for (auto it = vect1_3.begin(); it != vect1_3.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}

		std::vector<std::array<int, 5>> vect1_4;//4шаг
		for (int it = 0; it < vect1_3.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect1_3[it][j] != -1)
				{
					int tt = vect1_3[it][j];
					vect1_3[it][j] = -1;
					if ((searc_eaqvel(vect0, vect1_3[it]) == false))
						if ((searc_eaqvel(vect1_4, vect1_3[it]) == false))
							vect1_4.push_back(vect1_3[it]), ++k;
						else ++k;
					vect1_3[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect1_4, vect1_3[it]) == false))
				vect1_4.push_back(vect1_3[it]);
		}
		std::cout << "4 склейка\n";
		for (auto it = vect1_4.begin(); it != vect1_4.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}




		{
			std::cout << " квайн F=1    |||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

			std::cout << "     |";
			for (auto ij = vect1.begin(); ij != vect1.end(); ij++)
			{
				for (size_t k = 0; k < ij->size(); k++)
				{
					if (ij->at(k) == -1)std::cout << '-';
					else std::cout << ij->at(k);
				}
				std::cout << "|";
			}
			std::cout << "\n";
			for (auto it = vect1_4.begin(); it != vect1_4.end(); it++)
			{


				for (auto i = it->begin(); i < it->end(); i++)
				{
					if (*i == -1)std::cout << '-';
					else std::cout << *i;
				}
				std::cout << "|";
				int count = 0;
				for (auto i = vect1.begin(); i != vect1.end(); i++)
				{
					count = 0;
					for (size_t j = 0; j < 5; j++)
					{
						if (it->at(j) != -1)count++;
					}

					for (size_t j = 0; j < 5; j++)
					{
						if (i->at(j) == -1)continue;
						if (i->at(j) == it->at(j)) count--;
					}
					if (count == 0) { std::cout << "  +  |"; }
					else { std::cout << "     |"; }
				}

				std::cout << "\n";
			}


		}

		comp111(vect1_4);

		std::cout << "F=0 **************************************************************************************************** \n";
		std::cout << "F=0 **************************************************************************************************** \n";
		std::cout << "F=0 **************************************************************************************************** \n";
		std::cout << "F=0 **************************************************************************************************** \n";
		std::cout << "F=0 **************************************************************************************************** \n";
		std::cout << "F=0 **************************************************************************************************** \n";



		std::vector<std::array<int, 5>> vect0_1;//1шаг
		for (int it = 0; it < vect0.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect0[it][j] != -1)
				{
					int tt = vect0[it][j];
					vect0[it][j] = -1;
					if ((searc_eaqvel(vect1, vect0[it]) == false))
						if ((searc_eaqvel(vect0_1, vect0[it]) == false))
							vect0_1.push_back(vect0[it]), ++k;
						else ++k;
					vect0[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect0_1, vect0[it]) == false))
				vect0_1.push_back(vect0[it]);
		}
		std::cout << "Первая склейка\n";
		for (auto it = vect0_1.begin(); it != vect0_1.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}
		std::vector<std::array<int, 5>> vect0_2;//2шаг
		for (int it = 0; it < vect0_1.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect0_1[it][j] != -1)
				{
					int tt = vect0_1[it][j];
					vect0_1[it][j] = -1;
					if ((searc_eaqvel(vect1, vect0_1[it]) == false))
						if ((searc_eaqvel(vect0_2, vect0_1[it]) == false))
							vect0_2.push_back(vect0_1[it]), ++k;
						else ++k;
					vect0_1[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect0_2, vect0_1[it]) == false))
				vect0_2.push_back(vect0_1[it]);
		}
		std::cout << "Вторая склейка\n";
		for (auto it = vect0_2.begin(); it != vect0_2.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}

		std::vector<std::array<int, 5>> vect0_3;//3шаг
		for (int it = 0; it < vect0_2.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect0_2[it][j] != -1)
				{
					int tt = vect0_2[it][j];
					vect0_2[it][j] = -1;
					if ((searc_eaqvel(vect1, vect0_2[it]) == false))
						if ((searc_eaqvel(vect0_3, vect0_2[it]) == false))
							vect0_3.push_back(vect0_2[it]), ++k;
						else ++k;
					vect0_2[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect0_3, vect0_2[it]) == false))
				vect0_3.push_back(vect0_2[it]);
		}
		std::cout << "Третья склейка\n";
		for (auto it = vect0_3.begin(); it != vect0_3.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}

		std::vector<std::array<int, 5>> vect0_4;//4шаг
		for (int it = 0; it < vect0_3.size(); it++)
		{
			int k = 0;
			for (size_t j = 0; j < 5; j++)
			{
				if (vect0_3[it][j] != -1)
				{
					int tt = vect0_3[it][j];
					vect0_3[it][j] = -1;
					if ((searc_eaqvel(vect1, vect0_3[it]) == false))
						if ((searc_eaqvel(vect0_4, vect0_3[it]) == false))
							vect0_4.push_back(vect0_3[it]), ++k;
						else ++k;
					vect0_3[it][j] = tt;
				}
			}
			if ((k == 0) && (searc_eaqvel(vect0_4, vect0_3[it]) == false))
				vect0_4.push_back(vect0_3[it]);
		}
		std::cout << "4 склейка\n";
		for (auto it = vect0_4.begin(); it != vect0_4.end(); it++)
		{
			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "\n";
		}


		//квайн F=0
		std::vector<std::vector<int>> vc;
		vc.resize(vect0_4.size());
		for (size_t i = 0; i < vc.size(); i++)
		{
			for (size_t j = 0; j < vect0.size(); j++)
			{
				vc[i].push_back(0);
			}
		}
		std::cout << " квайн F=0    |||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
		
		std::cout << "     |";
		for (auto ij = vect0.begin(); ij != vect0.end(); ij++)
		{
			for (size_t k = 0; k < ij->size(); k++)
			{
				if (ij->at(k) == -1)std::cout << '-';
				else std::cout << ij->at(k);
			}
			std::cout << "|";
		}
		std::cout << "\n";

		int jk = 0;
		for (auto it = vect0_4.begin(); it != vect0_4.end(); it++,jk++)
		{
			

			for (auto i = it->begin(); i < it->end(); i++)
			{
				if (*i == -1)std::cout << '-';
				else std::cout << *i;
			}
			std::cout << "|";
			int count = 0;
			int ik = 0;
			for (auto i = vect0.begin(); i != vect0.end(); i++,ik++)
			{
				count = 0;
				for (size_t j = 0; j < 5; j++)
				{
					if (it->at(j) != -1)count++;
				}

				for (size_t j = 0; j < 5; j++)
				{
					if (i->at(j) == -1)continue;
					if (i->at(j) == it->at(j)) count--;
				}
				if (count == 0) { std::cout << "  +  |"; vc[jk][ik] = 1; }
				else { std::cout << "     |"; }
			}
			
			std::cout << "\n";
		}
		comp000(vect0_4);


}
// Главная программа
int main() {
	setlocale(LC_ALL, "Russian");
	int n = 5;
	int m = 32;
	auto a = GetTableTrue(m, n);
	std::cout << '\n';
	test();
	fun(a, m, n);
	//comp1(a, m, n);
	//comp0(a, m, n);
	compsk(a, m, n);
	//////test();
	////viev_lab2(a, m, n);
	//viev(a, m, n);
	viev_lab3(a, m, n);
	// Конец программы
	return 0;
}
