#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;
typedef vector<double> t_probabilitys;
int q = 0;
void inputProbability(t_probabilitys& probabilitys)
{
    bool flag = true;
    double sum;
    size_t n;
    
    while (flag) {
        probabilitys.clear();
        cout << "Введите количество вероятностей: ";
        cin >> n;
        
        cout << "Введите " << n << " Вероятностей: ";
        
        double tmp = 0;
        for (size_t i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp > 0) {
                q++;
            }
            probabilitys.push_back(tmp);
        }
        sum = 0;
        for (double i : probabilitys)
            sum += i;
        if ((fabs(1 - sum)) < 1e-5)
            flag = false;
        else {
            cout << "Сумма вероятнгостей равна " << sum << " что не равно единице" << endl;
            cout << "Пожалуйста перепроверьте исходные данные и введите ещё раз" << endl;
        }
    }
}

double getEntropy(const t_probabilitys& probabilitys)
{
    double rez = 0;
    for (double probability : probabilitys)
        if (probability != 0)
            rez -= probability * log2(probability);
    return rez;
}

int main() {
   
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag) {
        t_probabilitys probabilitys;
        inputProbability(probabilitys);
        double entropy = getEntropy(probabilitys);
        double m = log2(q);
        q = 0;
        cout << "Ваша энтропия шенону:  " << entropy << endl;
        cout << "Ваша энтропия хартли:  " << m << endl;
        cout << "Введите 0 для окончания работы программы 1 для продолжения: ";
        cin >> flag;
    }
}
