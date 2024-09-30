#include <iostream>
#include<math.h>

using namespace std;

void input_knf (int** a, char* b, int m, int n)
{
    int i=0, j=0;

    cout << "Введите литералы: ";

    for(i = 0; i < n; i++)
        cin >> b[i];

    cout << "Литерал: 1";
    cout << "\nЛитерал c отрицанием: -1";
    cout << "\nОтсутствие литерала: 0" << endl;


    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            cin >> a[i][j];
}

void output_form (int **a, char* b, int m, int n)
{
    int i=0, j=0;

    for (i=0; i<m; i++)
    {
        cout << "(";
        j=0;
        while ((a[i][j]==0)&&(j<n))
            j++;
        if (j<n)
        {
            if (a[i][j]==-1)
                cout << "!" << b[j];
            else
                cout << b[j];
        }
        j++;
        for (j; j<n; j++)
        {
            if (a[i][j]==-1)
                cout << " V !" << b[j];
            if (a[i][j]==1)
                cout << " V " << b[j];

        }
        cout << ")";
    }
    cout << endl;
}

void output_table(int **a, char *b, bool *fun, int m, int n)
{
    for(int i = 0; i < n; i++)
        cout << b[i] << "\t";
    cout << "f\t" << endl;
    int all = pow(2,n);
    bool *mas = new bool[n];
//    bool *fun = new bool [n]; // массив функции
    for(int i = 0; i < all; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mas[j] = (i >> (n-1-j)) & 1;
            cout << mas[j] << "\t";
        }
        bool f = 1, x; // значение скобкиь-х f-форулы
        int j = 0, k;
        while(f && (j < m))
        {
            x = 0;
            k = 0;
            while(!x && (k < n))
            {
                if(a[j][k] == 1)
                    x |= mas[k];
                if(a[j][k] == -1)
                    x |= !mas[k];
                k++;
            }
            f &= x;
            j++;
        }
        fun[i]=f;
        cout << f << "\t" << endl;
    }
}

void output_TF(int **a, char *b, bool* fun, int m, int n)
{
    for(int i = 0; i < n; i++)
        cout << b[i] << "\t";

    cout << "f\t" << endl;

    int all = pow(2,n);

    bool *mas = new bool[n];

    for(int i = 0; i < all; i++)
    {
        if (!fun[i])
        {
           for(int j = 0; j < n; j++)
            {
                mas[j] = (i >> (n-1-j)) & 1;
                cout << mas[j] << "\t";
            }
            cout << fun[i] << "\t" << endl;
        }
    }
}
