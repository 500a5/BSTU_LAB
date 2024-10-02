#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
#include <fstream>

using namespace std;
typedef vector<double> t_probabilitys;
typedef vector<t_probabilitys> t_matrProb;
void inputProbability(t_probabilitys& probabilitys, size_t n);
void inputMatr(t_matrProb& matr);
void getAB(t_matrProb B_A, t_probabilitys pA, t_matrProb& AB);
void getABfor2(t_matrProb A_B, t_probabilitys pB, t_matrProb& AB);
void getA_B(t_matrProb AB, t_probabilitys pB, t_matrProb& A_B);
void getB_A(t_matrProb AB, t_probabilitys pa, t_matrProb& B_A);
void getPA(t_matrProb AB, t_probabilitys& pA);
void getPB(t_matrProb AB, t_probabilitys& pB);
bool wrongAB(t_matrProb AB);
bool wrongProb(t_probabilitys p);
void printMatr(t_matrProb matr);
void printArr(t_probabilitys arr);
double getEnthropy(t_probabilitys p);
double getUslEnthropyB(double HAB, double HA);
double getUslEnthropy(t_probabilitys p, t_matrProb matr);
double getVzEnthropy(double HA, double HB_A);
double getI(double HA, double HB, double HAB);
int main() {
   system("chcp 65001");
    int flagLoop = 1;
    while (flagLoop) {
        t_matrProb AB, A_B, B_A;
        t_probabilitys pA, pB;
        cout << "1 - для ввода B/A" << endl;
        cout << "2 - для ввода A/B" << endl;
        cout << "3 - для ввода AB" << endl;
        int flagTypeInput = 1;
        cin >> flagTypeInput;

        if (flagTypeInput == 1) {
            cout << "Введите B/A" << endl;
            inputMatr(B_A);
            cout << "Введите pA" << endl;
            inputProbability(pA, B_A.size());
            getAB(B_A, pA, AB);
            getPB(AB, pB);
            getA_B(AB, pB, A_B);
        }
        else {
            if (flagTypeInput == 2) {
                cout << "Введите A/B" << endl;
                inputMatr(A_B);
                cout << "Введите pB" << endl;
                inputProbability(pB, A_B.size());
                getABfor2(A_B, pB, AB);
                getPA(AB, pA);
                getB_A(AB, pA, B_A);
            }
            else {
                cout << "Введите AB" << endl;
                inputMatr(AB);
                getPA(AB, pA);
                getPB(AB, pB);
                getA_B(AB, pB, A_B);
                getB_A(AB, pA, B_A);
            }
        }
        if (wrongProb(pA) || wrongProb(pB)) {
            cout << "Неверно введены вероятности";
            continue;
        }
        if (wrongAB(AB)) {
            cout << "Неверно введена матрица";
            continue;
        }

        cout << "B/A" << endl;
        printMatr(B_A);
        cout << "A/B" << endl;
        printMatr(A_B);
        cout << "AB" << endl;
        printMatr(AB);
        cout << "pA" << endl;
        printArr(pA);
        cout << "pB" << endl;
        printArr(pB);

        double HA = getEnthropy(pA);
        cout << "H(A) = " << HA << endl;
        double HB = getEnthropy(pB);
        cout << "H(B) = " << HB << endl;

        double HA_B = getUslEnthropy(pB, A_B);
        cout << "H(A/B) = " << HA_B << endl;
        double HAB = getVzEnthropy(HB, HA_B);

        double HB_A = getUslEnthropyB(HAB, HA);
        cout << "H(B/A) = " << HB_A << endl;
        cout << "H(A,B) = " << HAB << endl;
        cout << "I(A,B) = " << getI(HA, HB, HAB) << endl;
        cout << "Введите 0 для прекращения 1 для продолжения";
        cin >> flagLoop;
    }

}


void inputProbability(t_probabilitys& probabilitys, size_t n) {
    double tmp;
    cout << "Введите 1 для ввода из файла";
    int flag = 0;
    cin >> flag;
    if (flag) {
        cout << "Введите имя файла";
        string fPath;
        cin >> fPath;
        ifstream input;
        input.open(fPath, ios::in);
        for (size_t i = 0; i < n; ++i) {
            input >> tmp;
            probabilitys.push_back(tmp);
        }
        input.close();
        return;
    }
    for (size_t i = 0; i < n; ++i) {
        cin >> tmp;
        probabilitys.push_back(tmp);
    }

}
void inputMatr(t_matrProb& matr) {
    size_t n;
    double tmp;
    t_probabilitys tmpVector;
    cout << "Введите n: ";
    cin >> n;
    matr.clear();
    cout << "Введите 1 для ввода из файла";
    int flag = 0;
    cin >> flag;
    if (flag) {
        cout << "Введите имя файла";
        string fPath;
        cin >> fPath;
        ifstream input;
        input.open(fPath, ios::in);
        for (size_t i = 0; i < n; ++i) {
            tmpVector.clear();
            for (size_t j = 0; j < n; ++j) {
                input >> tmp;
                tmpVector.push_back(tmp);
            }
            matr.push_back(tmpVector);
        }
        input.close();
        return;
    }
    for (size_t i = 0; i < n; ++i) {
        tmpVector.clear();
        for (size_t j = 0; j < n; ++j) {
            cin >> tmp;
            tmpVector.push_back(tmp);
        }
        matr.push_back(tmpVector);
    }
}
void getAB(t_matrProb B_A, t_probabilitys pA, t_matrProb& AB) {
    size_t n = B_A.size();
    t_probabilitys tmpVector;
    AB.clear();
    for (size_t i = 0; i < n; ++i) {
        tmpVector.clear();
        for (size_t j = 0; j < n; ++j) {
            tmpVector.push_back(B_A[i][j] * pA[i]);
        }
        AB.push_back(tmpVector);
    }
}
void getABfor2(t_matrProb A_B, t_probabilitys pB, t_matrProb& AB) {
    size_t n = A_B.size();
    t_probabilitys tmpVector;
    AB.clear();
    for (size_t i = 0; i < n; ++i) {
        tmpVector.clear();
        for (size_t j = 0; j < n; ++j) {
            tmpVector.push_back(A_B[i][j] * pB[j]);
        }
        AB.push_back(tmpVector);
    }
}
void getA_B(t_matrProb AB, t_probabilitys pB, t_matrProb& A_B) {
    size_t n = AB.size();
    t_probabilitys tmpVector;
    A_B.clear();
    for (size_t i = 0; i < n; ++i) {
        tmpVector.clear();
        for (size_t j = 0; j < n; ++j) {
            if ((AB[i][j] != 0) && (pB[j] != 0))
                tmpVector.push_back(AB[i][j] / pB[j]);
            else
                tmpVector.push_back(0);
        }
        A_B.push_back(tmpVector);
    }
}
void getB_A(t_matrProb AB, t_probabilitys pA, t_matrProb& B_A) {
    size_t n = AB.size();
    t_probabilitys tmpVector;
    B_A.clear();
    for (size_t i = 0; i < n; ++i) {
        tmpVector.clear();
        for (size_t j = 0; j < n; ++j) {
            if ((AB[i][j] != 0) && (pA[i] != 0))
                tmpVector.push_back(AB[i][j] / pA[i]);
            else
                tmpVector.push_back(0);
        }
        B_A.push_back(tmpVector);
    }
}
void getPA(t_matrProb AB, t_probabilitys& pA) {
    size_t n = AB.size();
    pA.clear();
    for (size_t i = 0; i < n; ++i) {
        pA.push_back(0);
    }
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            pA[i] += AB[i][j];
}
void getPB(t_matrProb AB, t_probabilitys& pB)
{
    size_t n = AB.size();
    pB.clear();
    for (size_t i = 0; i < n; ++i) {
        pB.push_back(0);
    }
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            pB[j] += AB[i][j];
}
bool wrongAB(t_matrProb AB)
{
    size_t n = AB.size();
    double sum = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            sum += AB[i][j];
    return fabs(1 - sum) > 1e-4;
}
bool wrongProb(t_probabilitys p) {
    size_t n = p.size();
    double sum = 0;
    for (size_t i = 0; i < n; ++i)
        sum += p[i];
    return fabs(1 - sum) > 1e-4;
}
void printMatr(t_matrProb matr) {
    size_t n = matr.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            cout << matr[i][j] << ' ';
        cout << endl;
    }
}
void printArr(t_probabilitys arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

double getEnthropy(t_probabilitys p)
{
    double rez = 0;
    for (double probability : p)
        if (probability != 0)
            rez -= probability * log2(probability);
    return rez;
}

double getUslEnthropy(t_probabilitys p, t_matrProb matr) {
    double rez = 0;
    size_t n = p.size();
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            if (matr[i][j] != 0)
                rez -= matr[i][j] * log2(matr[i][j]) * p[j];
    return rez;
}

double getUslEnthropyB(double HAB, double HA) {
    return HAB - HA;
}
double getVzEnthropy(double HA, double HB_A) {
    return HA + HB_A;
}
double getI(double HA, double HB, double HAB) {
    return HA + HB - HAB;
}