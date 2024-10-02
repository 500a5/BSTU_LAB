
#include "coding.h"
#include "CRC.h"
int main(){
    system("chcp 65001");
    while (true) {
        int flagI = 0;
        cout << "Введите 1-кодирование/декодирование\n2-кодирование\n3-декодирование\n4-для выхода" << endl;
        cin >> flagI;
        if (flagI == 4)
            break;
        if (flagI < 3) {
            if (flagI == 1) {
                cout << "Введите m: ";
                int m;
                cin >> m;
                CRC crc = CRC(m);
                cout << "Введите длинну сообщения: ";
                size_t len;
                cin >> len;
                HemingMatr message = HemingMatr(1, len);
                message.inputMatr();
                int n = crc.getN();
                int k = n - m;
                uint8_t dopis = (k - message.lenghtCode() % k) % k;
                message.dopis(dopis);
                cout << "Код размера блока: " << PrintByte(n) << endl;
                cout << "Колличество дописанных нулей: " << PrintByte(dopis) << endl;
                HemingMatr code = crc.codings(message);
                cout << "Закодированное сообщение: ";
                code.NTprintMatr();
                cout << endl;
                cout << "Итог: " << PrintByte(n) << PrintByte(dopis);
                code.NTprintMatr();
                cout << endl;
                cout << "Введите 1 для внесения ошибки\nили 0 для продолжения\n";
                int flag = 0;
                cin >> flag;
                if (flag) {
                    int raz = -1;
                    while (raz < 0) {
                        cout << "Введите разряд в который хотите внести ошибку";
                        cin >> raz;
                        if (((raz-1) < 0) || ((raz - 1) >= code.lenghtCode())) {
                            cout << "Номер разряда выходит за границы";
                            raz = -1;
                        } else
                            code[0][raz - 1] = !code[0][raz - 1];
                    }
                    cout << "Ваш код с ошибкой: ";
                    code.NTprintMatr();
                    cout << endl;
                }
                HemingMatr newMessage = crc.deCodings(code);
                newMessage.cut(dopis);
                cout<<"Декодированное сообщение: ";
                newMessage.NTprintMatr();
                cout<<endl;
            } else {
                cout << "Введите m: ";
                int m;
                cin >> m;
                CRC crc = CRC(m);
                cout << "Введите длинну сообщения: ";
                size_t len;
                cin >> len;
                HemingMatr message = HemingMatr(1, len);
                message.inputMatr();

                int n = crc.getN();
                int k = n - m;
                uint8_t dopis = (k - message.lenghtCode() % k) % k;
                message.dopis(dopis);
                cout << "Код размера блока: " << PrintByte(n) << endl;
                cout << "Колличество дописанных нулей: " << PrintByte(dopis) << endl;


                HemingMatr code = crc.codings(message);
                cout << "Закодированное сообщение: ";
                code.NTprintMatr();
                cout << endl;
                cout << "Итог: " << PrintByte(n) << PrintByte(dopis);
                code.NTprintMatr();
                cout << endl;
            }
        } else {
            cout << "Введите сообщение: ";
            string message;
            cin >> message;
            string tmpN = "";
            string tmpDopis = "";
            string tmpMessage = "";
            for (int i = 0; i < 8; ++i) {
                tmpN+=message[i];
                tmpDopis+=message[i+8];
            }
            for (int i = 16; i < message.length(); ++i)
                tmpMessage+=message[i];
            uint8_t n = getMN(tmpN);
            uint8_t dopis = getMN(tmpDopis);
            HemingMatr code = HemingMatr(1, tmpMessage.length());
            code.inputMatr(tmpMessage);
            CRC crc = CRC(log2(n+1));
            cout << "Размер блока: " << (int)n << endl;
            cout << "Колличество дописанных нулей: " << (int)dopis << endl;
            HemingMatr newMessage = crc.deCodings(code);
            newMessage.cut(dopis);
            cout<<"Декодированное сообщение: ";
            newMessage.printMatr();
            cout<<endl;
        }
    }
    system("pause");
}
