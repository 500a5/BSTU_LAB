#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include "bch_code.h"
using namespace std;
int main(){
    system("cls");
    BCH r(4);
    ifstream f;
    f.open("inp.txt", ifstream::in); /// Ввод информационного слова осуществляется из файла
    //блоки по 7
    vector<int> info;
    string inp;
    f >> inp;
    cout << endl <<"Прочитано сообщение:" << endl << inp << endl << "Длина сообщения:" << inp.length() << endl;
    int pos = 0, count = 0, added = 0;
    if (inp.length() % 7 != 0) { ///если длина не кратна 7 то добавляем нолики.
        for (int i = 0; i <inp.length() % 7; i++) {
            inp += "0";
            added++;
        }
    }
    bitset <7> tmp = added; ///массив бит для первого участка информационного слова размером 7 (В начале количество добавленных битов)
    inp = tmp.to_string() + inp;
    string* res = new string[(inp.length() / 7) + 1];
    for (int i = 0; i < inp.length(); i++) {
        res[pos] += inp[i];
        count++;
        if (count == 7) {
            //cout << res[pos] << endl;
            pos++;
            count = 0;
        }
    }


    for (int i = 0; i < inp.length() / 7; i++) {
        for (int j = 0; j < res[i].length(); j++) {
            info.push_back(res[i][j] - '0');
        }
        cout << endl;

        vector<int> code = r.coding(info);
        res[i] += " \t ";
        for (int k = 0; k < code.size(); k++) {
            res[i] += code[k] + '0';
        }
        vector <int> tmpcode = code;

        r.putMistake(tmpcode);/// добавление ошибки

        res[i] += " \t ";
        for (int k = 0; k < tmpcode.size(); k++) {
            res[i] += tmpcode[k] + '0';
        }
        res[i] += " \t ";

        for (int l = 0; l < code.size(); l++) {
            if (code[l] != tmpcode[l]) {
                res[i] += to_string(l);
                res[i] += "  ";
            }
        }
        info = r.decoding(tmpcode);

        info.clear();
    }
    cout << endl << "Сообщение \t Кодовое слово \t\t С ошибкой \t\t Синдром" << endl;
    for (int i = 0; i < inp.length() / 7; i++) {
        cout << res[i] << endl;
    }
}
