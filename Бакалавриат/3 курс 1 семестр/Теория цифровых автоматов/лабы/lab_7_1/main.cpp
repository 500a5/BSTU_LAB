#include <iostream>
#include <math.h>

using namespace std;
const int NotUsed = system("color F0");
int F1(int *x)
{
    return (x[1]&&x[3]&&x[4]||x[1]&&x[2]&&x[3]||x[0]&&!x[4]||x[1]&&x[3]);
}

int F2(int *x)
{
    return (!x[1]&&x[2]||x[1]&&!x[2]);
}

int F3(int *x)
{
    return (x[2]&&!x[3]||x[1]&&x[2]&&x[3]);
}

int F(int *x)
{
    int res = 0;
    res |= F1(x) << 2;
    res |= F2(x) << 1;
    res |= F3(x);
    return res;
}

int f10(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x4&&x5||x2&&x3&&x4||x2&&x4) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x3&&!x4||x2&&x3&&x4);
    return res;
}

int f11(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x4&&x5||x2&&x3&&x4||!x5||x2&&x4) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x3&&!x4||x2&&x3&&x4);
    return res;
}

int f20(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x1&&!x5) << 2;
    res |= (x3) << 1;
    res |= (x3 && !x4);
    return res;
}

int f21(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x4&&x5||x3&&x4||x1&&!x5||x4) << 2;
    res |= (!x3) << 1;
    res |= (x3&&!x4||x3&&x4);
    return res;
}

int f30(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x4&&x5||x1&&!x5||x2&&x4) << 2;
    res |= (x2) << 1;
    res |= (0);
    return res;
}

int f31(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x4&&x5||x2&&x4||x1&&!x5||x2&&x4) << 2;
    res |= (!x2) << 1;
    res |= (!x4||x2&&x4);
    return res;
}

int f40(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x1&&!x5) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x3);
    return res;
}

int f41(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x5||x2&&x3||x1&&!x5||x2) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x2&&x3);
    return res;
}

int f50(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x3&&x4||x1||x2&&x4) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x3&&!x4||x2&&x3&&x4);
    return res;
}

int f51(int x1, int x2, int x3, int x4, int x5)
{
    int res = 0;
    res |= (x2&&x4||x2&&x3&&x4||x2&&x4) << 2;
    res |= (!x2&&x3||x2&&!x3) << 1;
    res |= (x3&&!x4||x2&&x3&&x4);
    return res;
}


void truth_table(int m, int n, int **table) //функция для построения таблицы истинности
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

int R(int F, int f) //F - мднф, f - функция неисправности
{
    if (F ^ f)
        return 1;
    else
        return 0;

}

void output(int m, int n, int **table)
{
    for (int i = 0; i < m; i++)
    {
        cout << "x" << i + 1 << "  ";
    }
    cout << "F" <<  "    ";
    for (int i = 0; i < 10; i++)
    {
        cout << "f" << i + 1 << "    ";
    }
    cout << "\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        //if (k == 0 || k == 2 || k == 5 || k == 13 || k == 17 || k == 27 || k == 28)
        //{
        for (int j = 0; j < m; j++)
        {
            cout << table[i][j] << "   ";
        }
        cout << F(table[i]) << "     ";
        cout << f10(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f11(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f20(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f21(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f30(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f31(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f40(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f41(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f50(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << f51(table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]) << "     ";
        cout << endl;


        //}
        //k++;
    }
}

int main()
{
    int m = 5, n = pow(2, m);
    int **table = new int*[n];
    for (int i = 0; i < n; i++)
    {
        table[i] = new int[m];
    }
    truth_table(m, n, table);
    output(m, n, table);
    system("pause");
    return 0;
}
