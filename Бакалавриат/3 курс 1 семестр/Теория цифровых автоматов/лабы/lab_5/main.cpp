#include <iostream>
#include <math.h>
#include <string>

using namespace std;
const int NotUsed = system("color F0");



void function_3(bool *x, bool &f1, bool &f2, bool &f3) //моделирование работы схемы МДНФ
{


    bool z2 = !x[1] && x[2],
         z3 = !x[0] && x[1],
         z4 = x[0] && x[4],
         z5 = !x[4] && z2,
         z6 = !x[2] && x[4],
         z7 = x[2] && !x[4],
         z8 = x[3] && x[4],
         z9 = !x[3] && !x[4],
         z10 = !x[2] &&!x[3],
         z11 = !x[0] && x[3],
         z12 = x[0] && !x[3],
         z13 = x[2] && !x[3],
         z14 = x[4] && z3,
         z15 = x[1] && x[3],
         z1 = !x[0] &&z15;

    bool u1 = z4 && z5,
            u2 = z1 && z6,
            u3 = z1 && z7,
            u4 = z2 && z8,
            u5 = z2 && z9,
            u6 = z3 && z10,
            u7 = z2 && z11,
            u8 = z3 && z6,
            u9 = z2 &&z4,
            u10 = z2 & z12,
            u11 = z13 && z14;

    bool y1 = u1 || u2,
            y2 = u3 || u4,
            y3 = u5 || u6,
            y4 = u7 || u8,
            y5 = u9 || y3,
            y6 = u5 || u3,
            y7 = u10 ||u11;

f1 = y1 || y2;
f2 = y4 || y5;
f3 = y6 || y7;

}


void function_6(bool *x, bool &f1, bool &f2, bool &f3) //моделирование работы схемы МДНФ
{

    bool z1 = !x[0] && x[1],
         z2 = !x[1] && x[2],
         z3 = x[0] && !x[3],
         z4 = !x[4] && z2,
         z5 = x[3] && z1,
         z6 = !x[2] && x[4],
         z7 = x[2] && !x[4],
         z8 = x[3] && z2,
         z9 = x[0] && x[4],
         z10 =!x[3] && !x[4],
         z11 = !x[2] && !x[3],
         z12 = x[2] && !x[3],
         z13 = x[4] && z1;

    bool u1 = z3 && z4,
            u2 = z5 && z6,
            u3 = z5 && z7,
            u4 = z8 && z9,
            u5 = z2 && z10,
            u6 = z1 && z11,
            u7 = !x[0] && z8,
            u8 = z2 && z3,
            u9 = z12 &&z13;

    bool y1 = u1 || u2,
            y2 = u3 || u4,
            y3 = u4 || u5,
            y4 = u6 || u7,
            y5 = u8 || y1,
            y6 = y3 || y4,
            y7 = u3 || u5,
            y8 = u8 || u9;

    f1 = y1 || y2;
    f2 = y5 || y6;
    f3 = y7 || y8;

}


void truth_table(int m, int n, bool **table, bool *fres,  bool **f) //функция для построения таблицы истинности
{
    //заполнение table двоичными векторами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            table[i][j] = ((i >> (m - 1 - j)) & 1);
        }
    }
    }

void output(int m, int n, bool **table, bool *fres)
{
    for (int i = 0; i < m; i++)
    {
        cout << "x" << i + 1 << "  ";
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "f" << i + 1 << "  ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << table[i][j] << "   ";
        }
       bool f1, f2, f3;
         function_6(table[i], f1,f2,f3) ;
        cout << f1<<"   "<< f2<< "   "<<f3;


        cout << "\n";
    }


}


int main()
{
    int m = 5, n = pow(2, m);
    bool **table = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        table[i] = new bool[m];
    }
    bool *fres = new bool[n];
    int mf = 10, nf = 32;
    bool **f = new bool*[nf];
    for (int i = 0; i < nf; i++)
    {
        f[i] = new bool[mf];
    }
     cout <<"схема 6\n";
    truth_table(m, n, table, fres, f);
    output(m, n, table, fres);

    system("pause");
    return  0;
}