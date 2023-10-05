#include <iostream>
#include<math.h>
#include "knf.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    char i=0;

    cout << "¬ведите количество скобок: ";
    int m; // строк
    cin >> m;

    cout << "¬ведите количество литералов: ";
    int n; //столбцов
    cin >> n;

    int** a = new int*[m];
    for (i=0; i<m; i++)
        a[i]= new int[n];

    char *name = new char[n];

    bool *fun = new bool [n]; //массив функции

    input_knf(a, name, m, n);

    output_form(a, name, m, n);
    output_table(a, name, fun, m, n);

    cout << "\n" << endl;

    output_TF(a, name, fun, m, n);
    return 0;
}
