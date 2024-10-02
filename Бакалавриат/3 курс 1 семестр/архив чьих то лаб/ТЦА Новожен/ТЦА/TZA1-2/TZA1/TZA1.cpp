// TZA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

void GetVector(bool * vect,int pos,bool **matr, int m, int n)
{
	static int s = 0;
	for (size_t i = 0; i < 2; i++)
	{
		 vect[pos]=i;
		if (pos == n-1)
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

bool ** GetTableTrue(int m, int n)
{
	bool **matr = new bool*[m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new bool[n+1+1+1+1+1];
	}

	auto vect = new bool[n ];
	GetVector(vect, 0, matr, m, n);
	delete vect;
	return matr;
}
//Вычисление функции f(x1,x2,x3,x4,x5)
void fun(bool **a, int m, int n)
{
	//for (int j = 0; j < n; ++j)
	{
	//	std::cout  << j;
	}
	//std::cout << "|f\n";
	for (size_t i = 0; i < m; i++)
	{
		
		int t = 2 *( a[i][1]?1:0) + 1 * (a[i][2] ? 1 : 0 )+ 4 * (a[i][3] ? 1 : 0) + 2 * (a[i][4] ? 1 : 0) + 1 * (a[i][0] ? 1 : 0);
		a[i][n] = (5 <= t) && (t <= 8);
			/*for (int j = 0; j < n; ++j)
			{
				std::cout << (a[i][j] ? 1 : 0);
			}
		std::cout <<'|' << (a[i][n] ? 1 : 0)  << '\n';*/
	}
}
void comp1(bool **a, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		if (a[i][n])
		{
			std::string t;
			t = "(";
			t += (a[i][0] ? "x1" : "!x1");
			t += "*";
			t +=  (a[i][1] ? "x2" : "!x2");
			t += "*";
			t += (a[i][2] ? "x3" : "!x3");
			t += "*";
			t +=  (a[i][3] ? "x4" : "!x4");
			t += "*";
			t+=(a[i][4] ? "x5" : "!x5");
			t += ")";
			std::cout << t <<" + ";
			//std::cout << '|' << (a[i][n] ? 1 : 0) << '\n';
		}
	}
}
void comp0(bool **a, int m, int n)
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
//x1¬x2x4∨x2x4¬x5∨¬x2x3x4∨¬x2x4x5∨x1x2¬x4x5∨x2x3¬x4x5∨¬x1x2¬x3x4
bool  f1(bool x1, bool x2, bool x3, bool x4, bool x5)
{
	//return (x1 && !x2 && x4) || (x2 && x4 && !x5) || (!x2 && x3 && x4) ||
	///	(!x2 && x4 && x5) || (x1 && x2 && !x4 && x5) || (x2 && x3 && !x4 && x5) || (!x1 && x2 && !x3 && x4);
	bool z1 = x4 && !x2;
	bool z2 = !x4 && x2;
	bool z3 = x1 && x5;
	bool z4 = x3 && x5;
	bool z5 = !x1 && x2;
	bool z6 = !x3&&  x4;
	bool z7 = x2 &&  x4;

	bool u6 = !x5 && z7;
	bool u1 = z2 && z3;
	bool u4 = x5 && z1;
	bool u5 = x3 && z1;
	bool u7 = x1 && z1;
	bool u2 = z2 && z4;
	bool u3 = z5 && z6;

	bool v3 = u5 || u6;
	bool v2 = u3 || u4;
	bool v1 = u1 || u2;

	bool w4 = u7 || v1;
	bool w5 = v2 || v3;
	bool f = w4 || w5;
	return f;
}

//KNF
//(x2∨x4)∧(x4∨x5)∧(x1∨x3∨x4)∧(x1∨x2∨x3∨x5)∧(¬x1∨¬x2∨¬x4∨¬x5)∧(¬x2∨¬x3∨¬x4∨¬x5)
bool  f2(bool x1, bool x2, bool x3, bool x4, bool x5)
{
	//return (x2 || x4) && (x4 || x5) && (x1 || x3 || x4) && 
	//	(x1 || x2 || x3 || x5) && (!x1 || !x2 || !x4 || !x5) && ( !x2 || !x3 || !x4 || !x5);
	bool z1 = x3 || x1;
	bool z2 = !x2 || !x4;
	bool z3 = !x1 || !x5;
	bool z4 = !x5 || !x3;
	bool z5 = x5 || x2;
	bool u1 = z2 || z3;
	bool u2 = z2 || z4;
	bool u3 = z1 || z5;
	bool u4 = x2 || x4;
	bool u5 = x4 || x5;
	bool u6 = x4 || z1;
	bool v1 = u1 && u2;
	bool v2 = u3 && u4;
	bool v3 = u6 && u5;
	bool r = v1 && v2;
	bool f = v3 && r;
	return f;


}


void viev(bool **a, int m, int n)
{
	std::cout << "12345|f|f1|f2\n";
	for (size_t i = 0; i < m; i++)
	{
		a[i][n + 1] = f1(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		a[i][n + 2] = f2(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
		
			for (int j = 0; j < n; ++j)
			{
				std::cout << (a[i][j] ? 1 : 0);
			}
			std::cout << '|' << (a[i][n] ? 1 : 0) << '|' << (a[i][n+1] ? 1 : 0) << '|' << (a[i][n+2] ? 1 : 0) << '\n';
	}
}

bool  f31(bool x1, bool x2, bool x3, bool x4, bool x5)//и не
{
	bool a1 = !(x2 && x2);
	bool a2 = !(x4 && x4);
	bool a3 = !(x1 && x1);
	bool a4 = !(x3 && x3);

	bool b1 = !(x4 && a1);
	bool b2 = !(x2 && a2);
	bool b3 = !(x1 && x5);
	bool b4 = !(x3 && x5);
	bool b5 = !(x2 && a3);
	bool b6 = !(x4 && a4);
	bool b7 = !(x2 && x4);

	bool z1 = !(b1 && b1);
	bool z2 = !(b2 && b2);
	bool z3 = !(b3 && b3);
	bool z4 = !(b4 && b4);
	bool z5 = !(b5 && b5);
	bool z6 = !(b6 && b6);
	bool z7 = !(b7 && b7);


	bool c1= !(x5 && x5);

	bool u1 = !(z2 && z3);
	bool u2 = !(z2 && z4);
	bool u3 = !(z5 && z6);
	bool u4 = !(z1 && x5);
	bool u5 = !(z1 && x3);
	bool u6 = !(z7 && c1);
	bool u7 = !(z1 && x1);

	bool v3 = !(u5 && u6);
	bool v1 = !(u1 && u2);
	bool v2 = !(u3 && u4);

	bool d1 = !(v1 && v1);
	bool d2 = !(v2 && v2);
	bool d3 = !(v3 && v3);

	bool w1 = !(d1 && u7);
	bool w2 = !(d3 && d2);

	bool e1= !(w1 && w1);
	bool e2= !(w2 && w2);

	bool f= !(e1 && e2);

	return f;
}

bool  f32(bool x1, bool x2, bool x3, bool x4, bool x5)//или не 
{

	bool a1 = !(x4 || x4);
	bool a2 = !(x2 || x2);
	bool a3 = !(x1 || x1);
	bool a5 = !(x3 || x3);
	bool a6 = !(x5 || x5);
	bool a7 = a2;
	bool a8 = a1;
	bool a9 = a2;
	bool a10 = a1;
	bool a4 = a6;

	bool z1 = !(x2 || a1);
	bool z2 = !(x4 || a2);
	bool z3 = !(a3 || a4);
	bool z4 = !(a5 || a6);
	bool z5 = !(x1 || a7);
	bool z6 = !(x3 || a8);
	bool z7 = !(a9 || a10);


	bool b1 = !(z2 || z2);
	bool b2 = !(z3 || z3);
	bool b3 = b1;
	bool b4 = !(z4 || z4);
	bool b5 = !(z5 || z5);
	bool b6 = !(z6 || z6);
	bool b7 = !(z1 || z1);
	bool b8 = a6;
	bool b9 = b7;
	bool b10 = a5;
	bool b11 = !(z7 || z7);
	bool b12 = b7;
	bool b13 = a3;


	bool u1 = !(b1 || b2);
	bool u2 = !(b3 || b4);
	bool u3 = !(b5 || b6);
	bool u4 = !(b7 || b8);
	bool u5 = !(b9 || b10);
	bool u6 = !(x5 || b11);
	bool u7 = !(b12 || b13);


	bool c1 = !(u1 || u2);
	bool c2 = !(u3 || u4);
	bool c3 = !(u5 || u6);


	bool v1 = !(c1 || c1);
	bool v2 = !(c2 || c2);
	bool v3 = !(c3 || c3);

	bool d1 = !(v1 || u7);
	bool d2 = !(v2 || v3);
	

	bool w1 = !(d1 || d1);
	bool w2 = !(d2 || d2);

	bool e1 = !(w1 || w2);

	bool f = !(e1 || e1);
	return f;
}
bool  f51(bool x1, bool x2, bool x3, bool x4, bool x5)//и не
{
	bool a1 = !(x1 && x1);
	bool a2 = !(x3 && x3);
	bool a3 = !(x5 && x5);
	bool a4 = !(x2 && x2);

	bool z1 = !(a1 &&a2);
	bool z2 = !(x2 && x4);
	bool z3 = !(x1 && x5);
	bool z4 = !(x3 && x5);
	bool z5 = !(a3 && a4);

	bool b1 = a4;
	bool b3 = !(z3 && z3);
	bool b5 = !(z2 && z2);
	bool b4 = b5;
	bool b6 = !(z4 && z4);
	bool b7 = !(z1 && z1);
	bool b8 = !(x4 && x4);
	bool b9 = b7;
	bool b10 = !(z5 && z5);
	bool b2 = b8;
	bool b11 = b8;
	bool b12 = a3;

	bool u1 = !(b3 && b4);
	bool u2 = !(b5 && b6);
	bool u3 = !(b9 && b10);
	bool u4 = !(b1 && b2);
	bool u5 = !(b11 && b12);
	bool u6 = !(b7 && b8);

	bool c1 = !(u4 && u3);
	bool c2 = !(u1 && u2);
	bool c3 = !(u5 && u6);

	bool v1 = !(c2 && c2);
	bool v2 = !(c1 && c1);
	bool v3 = !(c3 && c3);

	bool d1 = !(v1 && v2);

	bool w1 = !(d1 && d1);

	bool e1 = !(w1 && v3);

	bool f = !(e1 && e1);
	return f;
}
bool  f52(bool x1, bool x2, bool x3, bool x4, bool x5)//или не 
{
	bool a1 = !(x2 || x2);
	bool a2 = !(x4 || x4);
	bool a3 = !(x1 || x1);
	bool a4 = !(x5 || x5);
	bool a5 = a4;
	bool a6 = !(x3 || x3);

	bool b1 = !(x1 || x3);
	bool b2 = !(a1 || a2);
	bool b3 = !(a3 || a4);
	bool b4 = !(a5 || a6);
	bool b5 = !(x2 || x5);


	bool z1 = !(b1 || b1);
	bool z2 = !(b2 || b2);
	bool z3 = !(b3 || b3);
	bool z4 = !(b4 || b4);
	bool z5 = !(b5 || b5);

	bool u1 = !(z3 || z2);
	bool u2 = !(z2 || z4);
	bool u3 = !(z1 || z5);
	bool u4 = !(x2 || x4);
	bool u5 = !(x4 || x5);
	bool u6 = !(z1 || x4);

	bool v1 = !(u1 || u2);
	bool v2 = !(u4 || u3);
	bool v3 = !(u5 || u6);

	bool c1 = !(v2 || v2);
	bool c2 = !(v1 || v1);

	bool w1 = !(c1 || c2);

	bool d1 = !(w1 || w1);
	bool d2 = !(v3 || v3);

	bool f = !(d1 || d2);
	return f;
}

void viev_lab2(bool **a, int m, int n)
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
void compsk(bool** a, int m, int n)//1 lvl склеик
{
	auto tm = GetTableTrue(m, n);
	for (size_t i = 0; i < m; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			
		}
	}





	for (int j = 0; j < m; ++j)
	{
		delete[] tm[j];
	}
	delete[] tm
}

void test()
{
	f2(false, true, false, false, true);
	f52(false, true, false, false, true);
}
// Главная программа
int main() {
	//setlocale(LC_ALL, "Russian");
	int n = 5;
	int m = 32;
	auto a=GetTableTrue(m, n);
	std::cout << '\n';
	fun(a, m, n);
	//comp1(a, m, n);
	//comp0(a, m, n);

	test();
	viev_lab2(a, m, n);
	//viev(a, m, n);
	// Конец программы
	return 0;
}
