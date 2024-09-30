#include <windows.h>
#include "coding.h"


int main() {
    system("chcp 65001");
    t_probabilitys probabilitys;
    inputProbability(probabilitys);
    cout << "Введите размер блока: ";
    int block = 0;
    codeBase baseCode;
    while (block < 1)
        cin >> block;
    int flag = 0;
    int flagRun = 1;
    while (flagRun) {
        cout << "Введите 1 для Шенона-Фано, 0 для Хафмана";
        cin >> flag;
        if (flag == 1) {
            baseCode = getShenonFano(probabilitys, block);
            printCodeBase(baseCode, block);
        }
        else {
            baseCode = getHafman(probabilitys, block);
            printCodeBase(baseCode, block);
        }
        cout << "1 для кодирования, 0 для декодирования";
        cin >> flag;
        if (flag == 1) {
            cout << "Введите сообщение: ";
            string message;
            cin >> message;
            string cod = coding(baseCode, message, block);
            cout << "Ваш код: " << cod << endl;
        }
        else {
            cout << "Введите код: ";
            string cod;
            int dopis;
            cin >> dopis;
            cin >> cod;
            string message = deCoding(baseCode, cod, dopis);
            cout << "Ваше сообщение: " << message << endl;
        }
        cout << "Введите 0 для выхода: ";
        cin >> flagRun;
    }    system("pause");
}
