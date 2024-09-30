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

void GetVector2(int* vect, int pos, int** matr, int m, int n)
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
		else GetVector2(vect, pos + 1, matr, m, n);
	}
}

int** GetTableTrue(int m, int n)
{
	int** matr = new int* [m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new int[n + 3/*+1+ 1 + 1 + 1 + 1*/];
	}
	auto vect = new int[n];
	GetVector(vect, 0, matr, m, n);
	delete[] vect;
	return matr;
}

int** GetTableTrue2(int m, int n)
{
	int** matr = new int* [m];
	for (int i = 0; i < m; ++i) {
		matr[i] = new int[n + 9];
	}
	auto vect = new int[n];
	GetVector2(vect, 0, matr, m, n);
	delete[] vect;
	return matr;
}
//Вычисление функции f1,f2,f3
void fun(int** a, int m, int n)
{
	for (int j = 0; j < n; ++j)
	{
		std::cout << j;
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

		if (g14==1)
		{
			a[i][n] = g11 && g14;
			a[i][n + 1] = g12 && g14;
			a[i][n + 2] = g13 && g14;
		}else
		{
			a[i][n] = a[i][n + 1] = a[i][n + 2] = -1;
		}
		for (int j = 0; j < n; ++j)
		{
			std::cout << (a[i][j] ? 1 : 0);
		}
		if(g14==1)
		std::cout << "|" << (a[i][n] ? 1 : 0) << " |" << (a[i][n + 1] ? 1 : 0) << " |" << (a[i][n + 2] ? 1 : 0) << '\n';
		else
		std::cout << "|- |- |- |\n";

	
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






void comp111(std::vector<std::array<int, 8>> a)
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

void comp000(std::vector<std::array<int, 8>> a)
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

bool searc_eaqvel(std::vector<std::array<int, 8>> v, std::array<int, 8> arr)
{
	int count = 2;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		count = 0;
		for (size_t j = 1; j < 5; j++)
		{
			if (arr[j] != -1)count++;
		}

		for (size_t j = 1; j < 5; j++)
		{
			if (arr[j] == -1)continue;
			if (arr[j] == it->at(j)) count--;
		}
		if (count == 0)
		{
			if ((it->at(5) != -1) && (arr[5] != -1) && (it->at(5) == arr[5]))return true;
			if ((it->at(6) != -1) && (arr[6] != -1) && (it->at(6) == arr[6]))return true;
			if ((it->at(7) != -1) && (arr[7] != -1) && (it->at(7) == arr[7]))return true;
		}
		count = 2;
	}
	return false;
}



void compsk(int** a, int m, int n)//1 lvl склеик
{
	std::vector<std::array<int, 8>> vect1;
	std::vector<std::array<int, 8>> vect0;
	for (size_t i = 0; i < m; i++)
	{
		std::array<int, 8> arr;
		if (a[i][5] != -1 )
		{
			arr[0] = -1;
			for (int j = 1; j < 5; ++j)
			{
				arr[j] = a[i][j];
			}


			arr[5] = a[i][5]==1 ? 1 : -1;
			arr[6] = a[i][6]==1 ? 2 : -1;
			arr[7] = a[i][7]==1 ? 3 : -1;
			if (!(arr[5] == -1 && arr[6] == -1 && arr[7] == -1))

			if(searc_eaqvel(vect1, arr) == false)
			vect1.push_back(arr);//массив где ф равна 1
		}

		if (a[i][5] != -1)
		{
			arr[0] =  -1;
			for (int j = 1; j < 5; ++j)
			{
				arr[j] = a[i][j];
			}
			arr[5] = a[i][5]==0 ? 1 : -1;
			arr[6] = a[i][6]==0 ? 2 : -1;
			arr[7] = a[i][7]==0 ? 3 : -1;
			if (!(arr[5] == -1 && arr[6] == -1 && arr[7] == -1))
			if (searc_eaqvel(vect0, arr) == false)
			vect0.push_back(arr);//массив где ф равна 0
		}
	}
	std::cout << "\n";
	for (auto it = vect1.begin(); it != vect1.end(); it++)
	{
		for (auto i = it->begin(); i < it->end(); i++)
		{
			if (*i == -1)std::cout << '-';
			else std::cout << *i;
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	for (auto it = vect0.begin(); it != vect0.end(); it++)
	{
		for (auto i = it->begin(); i < it->end(); i++)
		{
			if (*i == -1)std::cout << '-';
			else std::cout << *i;
		}
		std::cout << "\n";
	}



	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1**************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	std::cout << "F=1 **************************************************************************************************** \n";
	int k;
	std::vector<std::array<int, 8>> vect1_1;//1шаг
	for (int it = 0; it < vect1.size(); it++)
	{
		 k = 0;
		for (size_t j = 0; j < 5; j++)
		{
			if (vect1[it][j] != -1)
			{
				int tt = vect1[it][j];
				vect1[it][j] = -1;
				if ((searc_eaqvel(vect0, vect1[it]) == false))
					//if ((searc_eaqvel(vect1_1, vect1[it]) == false))
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
	std::vector<std::array<int, 8>> vect1_2;//2шаг
	for (int it = 0; it < vect1_1.size(); it++)
	{
		 k = 0;
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

	std::vector<std::array<int, 8>> vect1_3;//3шаг
	for (int it = 0; it < vect1_2.size(); it++)
	{
		 k = 0;
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

	std::vector<std::array<int, 8>> vect1_4;//4шаг
	for (int it = 0; it < vect1_3.size(); it++)
	{
		 k = 0;
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

		std::cout << "        |";
		for (auto ij = vect1.begin(); ij != vect1.end(); ij++)
		{
			for (size_t k = 0; k < ij->size()-3; k++)
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
			
				if (searc_eaqvel(vect1, *it) ) { std::cout << "  +  |"; }
				else { std::cout << "     |"; }
			}

			std::cout << "\n";
		}


	}

	//comp111(vect1_4);

	std::cout << "F=0 **************************************************************************************************** \n";
	std::cout << "F=0 **************************************************************************************************** \n";
	std::cout << "F=0 **************************************************************************************************** \n";
	std::cout << "F=0 **************************************************************************************************** \n";
	std::cout << "F=0 **************************************************************************************************** \n";
	std::cout << "F=0 **************************************************************************************************** \n";



	std::vector<std::array<int, 8>> vect0_1;//1шаг
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
	std::vector<std::array<int, 8>> vect0_2;//2шаг
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

	std::vector<std::array<int, 8>> vect0_3;//3шаг
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

	std::vector<std::array<int, 8>> vect0_4;//4шаг
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
	for (auto it = vect0_4.begin(); it != vect0_4.end(); it++, jk++)
	{


		for (auto i = it->begin(); i < it->end(); i++)
		{
			if (*i == -1)std::cout << '-';
			else std::cout << *i;
		}
		std::cout << "|";
		int count = 0;
		int ik = 0;
		for (auto i = vect0.begin(); i != vect0.end(); i++, ik++)
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
	//comp000(vect0_4);


}


struct mst {
	std::array<int, 5> v;
	std::array<int, 2> pr;
};

std::vector < mst >  gt_lab6(int** a, int m, int n)
{
	std::vector < mst > v;

		for (int i = 0; i < m; i++)
		{
			if (a[i][n] != -1)
			{
				int t1 = a[i][n] * 4 + a[i][n + 1] * 2 + a[i][n + 2] * 1;
				for (int j = i+1; j < m; j++)
				{
					int t2 = a[j][n] * 4 + a[j][n + 1] * 2 + a[j][n + 2] * 1;
					if ((a[j][n] != -1) && (t1 != t2))
					{
						auto t3 = std::array<int, 5>{a[j][0]!= a[i][0], a[j][1] != a[i][1], a[j][2] != a[i][2], a[j][3] != a[i][3], a[j][4] != a[i][4]};
					
						auto t4 =std::array<int, 2>{i, j};
						v.push_back(mst{ t3,t4 });
					}
				}
			}
		}

		for (size_t j = 0; j < 7; j++)
		{
			int k = 0;
			for (auto i = v.begin(),end = v.end(); i < end; i++,k++)
			{

				if (j < 2) {
					std::cout.width(3);
					std::cout << i->pr[j];
				}
				else
				{
					std::cout.width(3);
					std::cout << i->v[j - 2];
				}
				
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "\n";
		for (size_t j = 0; j < 7; j++)
		{
			int k = 0;
			for (auto i = v.begin(), end = v.end(); i < end; i++, k++)
			{

				if (j == 0) {
					std::cout.width(2);
					std::cout << k;
				}
				else if(j >= 2)
				{
					std::cout.width(2);
					std::cout << i->v[j - 2];
				}

			}
			std::cout << "\n";
		}


		for (auto i = v.begin(), end = v.end(); i < end; i++)
		{
			std::cout.width(2);
			if (i->v[1] || i->v[2] || i->v[3] || i->v[4] )std::cout << "_";
			else std::cout << " ";

		}

		return v;
}

std::vector<std::array<int, 8>> gt_lab6st1(int** a, int m, int n)
{
		std::vector<std::array<int, 8>> v;
		//std::array<int, 5> v;
		for (int i = 0; i < m; i++)
		{
			if (a[i][n] != -1)
			{
				v.push_back(std::array<int, 8>{-1, a[i][1], a[i][2], a[i][3], a[i][4], a[i][n], a[i][n + 1], a[i][n + 2]});
			}
		}
		return v;
}

struct my { int f1, f2, f3; };

my f_var1(int x1, int x2, int x3, int x4, int x5)
{
	my ff;

	int z1 = x2 && x3;
	int z2 = x2 && !x3;

	int u1 = !x4 && z1;
	int u2 = !x5 && z1;
	int u3 = !x3 && x4;
	int u4 = x4 && !x2;
	int u5 = x3;
	int u6 = !x4 && z2;
	int u7 = !x4 && !x5;
	int u8 = x3 && !x4;

	int v1 = u1 || u2;
	int v2 = u3 || u4;
	int v3 = !u5 || u3;
	int v4 = u6 || u7;

	int w = u8 || v1;


	int f1 = v2 || v1;
	int f2 = u6 || v3;
	int f3 = w || v4;

	ff.f1 = f1;
	ff.f2 = f2;
	ff.f3 = f3;

	return ff;
}

my f_var2(int x1, int x2, int x3, int x4, int x5)
{
	my ff;

	int z1 = x2 && !x4;
	int z2 = x2 && x3;

	int u1 = x3 && z1;
	int u2 = !x3 && x4;
	int u3 = !x2 && x4;
	int u4 = x4 && !x5;
	int u5 = x3;
	int u6 = x3 && !x4;
	int u7 = !x4 && !x5;
	int u8 = z2 && !x5;
	int u9 = z1;

	int v1 = u1 || u2;
	int v2 = u3 || u4;
	int v3 = u6 || u7;
	int v4 = u8 || u9;

	int f1 = v2 || v1;
	int f2 = !u5;
	int f3 = v3 || v4;

	ff.f1 = f1;
	ff.f2 = f2;
	ff.f3 = f3;

	return ff;
}

void fun2(int** a, int m, int n)
{
	for (int j = 0; j < n; ++j)
	{
		std::cout << j;
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


		if (g14 == 1)
		{
			a[i][n] = g11 && g14;
			a[i][n + 1] = g12 && g14;
			a[i][n + 2] = g13 && g14;
		}
		else
		{
			a[i][n] = a[i][n + 1] = a[i][n + 2] = -1;
		}
		for (int j = 0; j < n; ++j)
		{
			std::cout << (a[i][j] ? 1 : 0);
		}
		if (g14 == 1)
			std::cout << "|" << (a[i][n] ? 1 : 0) << " |" << (a[i][n + 1] ? 1 : 0) << " |" << (a[i][n + 2] ? 1 : 0) << " |";
		else
			std::cout << "|- |- |- |";

		auto d = f_var1(a[i][0], a[i][0 + 1], a[i][0 + 2], a[i][0 + 3], a[i][0 + 4]);
		a[i][n + 4] = d.f1, a[i][n + 4 + 1] = d.f2, a[i][n + 4 + 2] = d.f3;
		 d = f_var2(a[i][0], a[i][0 + 1], a[i][0 + 2], a[i][0 + 3], a[i][0 + 4]);
		a[i][n + 4+3] = d.f1, a[i][n + 4 + 1+3] = d.f2, a[i][n + 4 + 2+3] = d.f3;
		std::cout << "v1    |" << (a[i][n+4] ? 1 : 0) << " |" << (a[i][n + 5] ? 1 : 0) << " |" << (a[i][n + 6] ? 1 : 0) << " |";
		std::cout << "v2    |" << (a[i][n+7] ? 1 : 0) << " |" << (a[i][n + 8] ? 1 : 0) << " |" << (a[i][n + 9] ? 1 : 0) << '\n';

	}
}



int main()
{
	//f123(0, 1, 1, 0, 1);
	setlocale(LC_ALL, "Russian");
	int n = 5;
	int m = 32;
	auto a = GetTableTrue(m, n);
	fun(a, m, n);
	//auto arr = gt_lab6(a, m, n);
	//compsk(a, m, n);

	int nn = 5;
	int mm = 32;
	auto aa = GetTableTrue2(m, n);
	fun2(aa, mm, nn);

}

