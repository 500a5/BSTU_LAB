#include <iostream>
#include <math.h>
#include <string>

using namespace std;
const int NotUsed = system("color F0");

int func(bool x1, bool x2, bool x3, bool x4, bool x5)  //возвращает результат функции 1
{
    return abs((4 * x2 + 2 * x1 + 0) - (4 * x3 + 2 * x4 + x5));
}

bool function(bool *x, int xn, bool flag) //моделирование работы схемы МДНФ
{
    int tx;
    if (xn != 0)
    {
        tx = x[xn - 1];
        if (flag)
            x[xn - 1] = 1;
        else
            x[xn - 1] = 0;
    }
    bool z1 = x[0] &&!x[1],
         z2= !x[0] && x[1],
         z3 = !x[2] && !x[4],
         z4 = x[2] && x [4],
         z5 = !x[3] && x[0],
         z6 = !x[0] && x[3];

    bool u1 = z1 && z5,
         u2 = z2 && z6,
         u3 = z1 && z3,
         u4 = z3 && z5,
         u5 = z6 && z4,
         u6 = z2 && z4;

    bool y1 = u1 || u2,
            y2 = u3 || u4,
            y3 = u5 || u6,
            k1 = y1 ||  y2;



    if (xn != 0)
        x[xn - 1] = tx;
    return k1|| y3;
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
    //получение результата функции и запись его в f при значениях, записанных в i-той строке table
    for (int i = 0; i < n; i++)
    {


        fres[i] = function(table[i], 0, false);

    }
}

string check_test(int xn, bool flag) {
    bool test[6][5] = {{0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 1, 0},
                       {0, 1, 1, 1, 0},
                       {0, 1, 1, 1, 1},
                       {1, 0, 0, 0, 0}};
    if (function(test[0], xn, flag)) {
        if (function(test[1], xn, flag)) {
            if (function(test[4], xn, flag)) {
                return "error f9 (x5 = 0)";
            } else {
                return "error f8 (x4 = 1)";
            }
        } else {
            if (function(test[3], xn, flag)) {
                if (function(test[5], xn, flag)) {
                    if (function(test[4], xn, flag)) {
                        return "error f3 (x2 = 0)";
                    } else {
                        return "error F";
                    }
                } else {
                    return "error f1 (x1 = 0)";
                }
            } else {
                if (function(test[4], xn, flag)) {
                    return "error f5 (x3 = 0)";
                } else {
                    return "error f7 (x4 = 0)";
                }
            }
        }
    } else {
        if (function(test[3], xn, flag)) {
            if (function(test[2], xn, flag)) {
                return "error f6 (x3 = 1)";
            } else {
                return "error f4 (x2 = 1)";
            }
        } else {
            if (function(test[1], xn, flag)) {
                return "error f2 (x1 = 1)";
            } else {
                return "error f10 (x5 = 1)";
            }
        }

    }
}

void output(int m, int n, bool **table, bool *fres)
{
    for (int i = 0; i < m; i++)
    {
        cout << "x" << i + 1 << "  ";
    }
    cout << "f\t";
    for (int i = 0; i < 10; i++)
    {
        cout << "R" << i + 1 << "\t";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << table[i][j] << "   ";
        }
       // cout << "x"<<i<<"\t";
        cout << fres[i] << "\t";
/*
        cout << function(table[i], 1, false) << "\t";
        cout << function(table[i], 1, true) << "\t";
        cout << function(table[i], 2, false) << "\t";
        cout << function(table[i], 2, true) << "\t";
        cout << function(table[i], 3, false) << "\t";
        cout << function(table[i], 3, true) << "\t";
        cout << function(table[i], 4, false) << "\t";
        cout << function(table[i], 4, true) << "\t";
        cout << function(table[i], 5, false) << "\t";
        cout << function(table[i], 5, true) << "\t";

*/
        cout << (function(table[i], 1, false) ^ fres[i]) << "\t";
        cout << (function(table[i], 1, true) ^ fres[i]) << "\t";
        cout << (function(table[i], 2, false) ^ fres[i]) << "\t";
        cout << (function(table[i], 2, true) ^ fres[i])  << "\t";
        cout << (function(table[i], 3, false) ^ fres[i]) << "\t";
        cout << (function(table[i], 3, true) ^ fres[i]) << "\t";
        cout << (function(table[i], 4, false) ^ fres[i]) << "\t";
        cout << (function(table[i], 4, true) ^ fres[i]) << "\t";
        cout << (function(table[i], 5, false) ^ fres[i]) << "\t";
        cout << (function(table[i], 5, true) ^ fres[i]) << "\t";

        cout << "\n";
    }
    cout << check_test(3, true)<<"\n\n";

}

void output6(int m, int n, bool **table, bool *fres)
{
    int a[11];
    for (int i = 0; i < n; i++)
    {

        a[1]= (function(table[i], 1, false) ^ fres[i]) ;
        a[2]= (function(table[i], 1, true) ^ fres[i]) ;
        a[3]= (function(table[i], 2, false) ^ fres[i]) ;
        a[4]= (function(table[i], 2, true) ^ fres[i])  ;
        a[5]=(function(table[i], 3, false) ^ fres[i]) ;
        a[6]= (function(table[i], 3, true) ^ fres[i]) ;
        a[7]= (function(table[i], 4, false) ^ fres[i]) ;
        a[8]= (function(table[i], 4, true) ^ fres[i]) ;
        a[9]= (function(table[i], 5, false) ^ fres[i]) ;
        a[10]= (function(table[i], 5, true) ^ fres[i]) ;

        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {

    }
    cout << check_test(2, true)<<"\n\n";

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
    truth_table(m, n, table, fres, f);
    output(m, n, table, fres);
    //check_similar(fres, f);
    //check_similar2(fres, f);
    system("pause");
    return  0;
}