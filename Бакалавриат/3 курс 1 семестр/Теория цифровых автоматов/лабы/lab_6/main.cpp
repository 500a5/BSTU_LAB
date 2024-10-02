#include <iostream>
#include <math.h>
#include <string>

using namespace std;
const int NotUsed = system("color F0");


bool check_g5(int i)  //возвращает 1, если i входит в заданный диапазон, иначе возвращает 0
{
    return 2 < i && i <= 5;
}

int G5(bool x1, bool x2, bool x3, bool x4, bool x5)  //возвращает результат функции g5
{
    return abs((4 * x2 + 2 * x1 + 0) - (4 * x3 + 2 * x4 + x5));
}

bool check_g8(int i)  //возвращает 1, если i входит в заданный диапазон, иначе возвращает 0
{
    return 2 <= i && i <= 4;
}

int G8(bool x1, bool x2, bool x3, bool x4, bool x5)  //возвращает результат функции g8
{
    return abs((2 * x1 + x2) - (4 * x3 + 2 * x4 + x5));
}

bool check_g6(int i)  //возвращает 1, если i входит в заданный диапазон, иначе возвращает 0
{
    return 0 < i && i <= 2;
}

int G6(bool x1, bool x2, bool x3, bool x4, bool x5)  //возвращает результат функции g6
{
    return abs((4 * x1 + 2 * x2 + x4) - (2 * x3 + x5));
}

bool check_g7(int i)  //возвращает 1, если i входит в заданный диапазон, иначе возвращает 0
{
    return 3 < i && i < 8;
}

int G7(bool x1, bool x2, bool x3, bool x4, bool x5)  //возвращает результат функции g7
{
    return (4 * x1 + 2 * x2 + x3) + (2 * x4 + x5);
}

void tt_F1(int m, int n, bool **table, int *f1) //функция для построения таблицы истинности
{
    bool *g5 = new bool[n];
    bool *g8 = new bool[n];
    //заполнение table двоичными векторами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            table[i][j] = ((i >> (m - 1 - j)) & 1);
        }
    }
    //получение результата функции и                                                                                            запись его в f1 при значениях, записанных в i-той строке table
    for (int i = 0; i < n; i++)
    {
        int res_g8 = G8(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
        if (check_g8(res_g8))
        {
            f1[i] = 0;
            int res_f1 = G5(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
            if (check_g5(res_f1))
                f1[i] = 1;
        }
        else
            f1[i] = 2;
    }
}

void tt_F2(int m, int n, bool **table, int *f2) //функция для построения таблицы истинности
{
    bool *g6 = new bool[n];
    bool *g8 = new bool[n];
    //заполнение table двоичными векторами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            table[i][j] = ((i >> (m - 1 - j)) & 1);
        }
    }
    //получение результата функции и запись его в f1 при значениях, записанных в i-той строке table
    for (int i = 0; i < n; i++)
    {
        int res_g8 = G8(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
        if (check_g8(res_g8))
        {
            f2[i] = 0;
            int res_f2 = G6(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
            if (check_g6(res_f2))
                f2[i] = 1;
        }
        else
            f2[i] = 2;
    }
}

void tt_F3(int m, int n, bool **table, int *f3) //функция для построения таблицы истинности
{
    bool *g7 = new bool[n];
    bool *g8 = new bool[n];
    //заполнение table двоичными векторами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            table[i][j] = ((i >> (m - 1 - j)) & 1);
        }
    }
    //получение результата функции и запись его в f1 при значениях, записанных в i-той строке table
    for (int i = 0; i < n; i++)
    {
        int res_g8 = G8(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
        if (check_g8(res_g8))
        {
            f3[i] = 0;
            int res_f3 = G7(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
            if (check_g7(res_f3))
                f3[i] = 1;
        }
        else
            f3[i] = 2;
    }
}

void mdnf_task2(bool x1, bool x2, bool x3, bool x4, bool x5)
{

    bool f1 = x2&&x4&&x5 || x2&&x3&&x4 || x1&&!x5 || x1&&x4,
     f2 = !x2&&x3 || x2&&!x3,
     f3 = x3&&!x4 || x2&&x3&&x4;


    cout << "\t" << "        " << f1 << "   " << f2 << "   " << f3 << "";
}

void mdnf_task4(bool x1, bool x2, bool x3, bool x4, bool x5)
{
    bool z1 = x2 && x4;


    bool u1 = x5 && z1,
         u2 = x3 && z1,
         u3 = !x2 && x3,
         u4 = x2 && !x3,
         u5 = x3 && !x4,
         u6 = x1 && x4,
         u7 = x2 && x4;

    bool y2 = u3 || u4,
         y3 = u1 || u6,
         y1 = u7 || y3;



    bool f1 = u2 || y1,
     f2 = y1 || y2,
     f3 = u2 || u5;

    cout << "\t" << "   " << f1 << "   " << f2 << "   " << f3 << "\n";
}

void output(int m, int n, bool **table, int *f1, int *f2, int *f3)
{
    for (int i = 0; i < m; i++)
    {
        cout << "x" << i + 1 << "  ";
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "f" << i + 1 << "  ";
    }
    cout << "Task 2:";
    for (int i = 0; i < 3; i++)
    {
        cout << "f" << i + 1 << "  ";
    }
    cout << "Task 4:";
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
        if (f1[i] == 2)
            cout << "-" << "   " << "-" << "   " << "-" << "";
        else
            cout << f1[i] << "   " << f2[i] << "   " << f3[i] << "";
        mdnf_task2(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
        mdnf_task4(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
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
    int *f1 = new int[n];
    int *f2 = new int[n];
    int *f3 = new int[n];

    tt_F1(m, n, table, f1);
    tt_F2(m, n, table, f2);
    tt_F3(m, n, table, f3);
    output(m, n, table, f1, f2, f3);
    system("pause");
}
