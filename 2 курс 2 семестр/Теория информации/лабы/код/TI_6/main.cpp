#include "polynom.h"
#include <locale.h>

int choose(std::string s, int min, int max){
    int answer;
    do{
        std::cout << s << std::endl;
        std::cin >> answer;
    }while (answer < min || answer > max);
    return answer;
}

/*
 * Конвертация строки в массив булев
 */
// С конца строки копируем ее в массив.
void str_to_bools(std::string s, bool a[]){
    int i = 0;
    for (std::string::iterator it=s.begin(); it!=s.end(); it++) {
        a[i] = *it - '0';
        i++;
    }
    while (i < size){
        a[i] = 0;
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    system("cls");
    int count = 0;
    // Инициализируем ГПСЧ
    srand(time(NULL));
    // Флаг выхода
    bool exit_f = false;

    while (!exit_f) {


        std::string i_str;
        std::string raw_str = "10011000101";

        std::string f_name;
        std::cout << "Прочитано: " << raw_str << std::endl;
        std::cout << "Длина сообщения - " << raw_str.length() << std::endl;
        std::cout << "Кодируем ее блоками по  " << 4 << std::endl ;

        int tcount = 0;
        std::cout << "Добавим 4 бита, в котором укажем, сколько битов было добавлено к последнему блоку" << std::endl << std::endl;
        if (raw_str.length() % 4 != 0) {
            int tmp = raw_str.length() % 4;
            switch (tmp) {
                case 1:
                    raw_str = "0011" + raw_str;
                    raw_str += "000";
                    break;
                case 2:
                    raw_str = "0010" + raw_str;
                    raw_str += "00";
                    break;
                case 3:
                    raw_str = "0001" + raw_str;
                    raw_str += "0";
                    break;
            }
        }
        else {
            raw_str = "0000" + raw_str;
        }
        int pos = 0;
        std::string *res = new std::string[raw_str.length() / 4];
        for (int i = 0; i < raw_str.length(); i++) {
            res[pos] += raw_str[i];
            tcount++;
            if (tcount == 4) {
                res[pos] += " ";
                pos++;
                tcount = 0;
            }
        }
        pos = 0;
        std::string::iterator it = raw_str.begin();
        // Заменить 4 на реальную длину
        while(it + 4 <= raw_str.end()) {
            count++;
            i_str.clear();
            i_str.resize(4);
            for (int i = 0; i<4; i++){
                i_str[i] = *it;
                it++;
            }
            //std::cout << "Кодируем блок: " << i_str << std::endl;
            bool i_array[size];
            str_to_bools(i_str, i_array);
            Polynomial i(i_array);
            std::cout << i_str << " <=> " << "i(x) = " << i.str() << "\t";

            /// Кодирование
            Polynomial g(const_g);
            Polynomial xr(const_xr);
            //std::cout << "Получаем кодовое слово по формуле c(x) = x^r * i(x) + Rem_g(x) (x^r * i(x))" << std::endl;
            //std::cout << "g(x) = " << g.str() << std::endl;
            //std::cout << "x^r = " << xr.str() << std::endl;
            Polynomial t = xr * i;
            // std::cout << "x^r * i(x) = " << t.str() << std::endl;
            Polynomial r = t % g;
            //std::cout << "Rem = (x^r * i(x)) % g(x) = " << r.str() << std::endl;
            Polynomial c = t + r;
            std::cout << "C(х)=" << c.str() << "\t";
            res[pos] += " \t ";
            res[pos] += c.str_bit();
            //std::cout << "c(x) = x^r * i(x) + Rem = " << c.str() << std::endl;
            //std::cout << "В канал связи передается последовательность " << c.str_bit() << std::endl << std::endl;

            bool corrupt_bit;

            // выбираем, какой бит


            //corrupt_bit = rand() % 3; // Вероятность не получить ошибку 1/3

            // Если ошибку требуется вносить всегда, выбери эту строку
            corrupt_bit = true;

            // Если выбираем внесение ошибки вручную, выбери эту строку
            //corrupt_bit = choose("Внести ошибку в передаваемое сообщение? 1 - не вносить, 2 - внести: ", 1, 2) - 1;


            Polynomial y;

            if (corrupt_bit) {
                int bit =4;
                Polynomial e(bit, size);
                //std::cout << "Вносим ошибку в " << bit << "-й бит передаваемого слова c, получаем слово y(x) = c(x) + e(x)" << std::endl;
                y = c + e;
                //std::cout << "y(x) = " << c.str() << " + " << e.str() << " = " << y.str() << std::endl << std::endl;
                std::cout << "\tу(х) = " << y.str() << " ";
                res[pos] += " \t "; res[pos] += y.str_bit();
                //std::cout << "Декодер принял последовательность " << y.str_bit() << std::endl;
                //std::cout << y.str_bit();
                //std::cout << "Для проверки правильности принятого кода вычисляем y(e) = ";
                std::cout << std::endl <<"y(e) = " << y.str_epsilon() << "=";
                Polynomial syndrome = y.sum_epsilon();
                std::cout << syndrome.str('e');
                int e_d = syndrome.error_digit();

                if (e_d >= 3) {
                    std::cout << "=e" << e_d;
                }
                //std::cout << std::endl;

                //std::cout << "Ошибка произошла в " << e_d << "-м бите" << std::endl << std::endl;
                Polynomial re_e(e_d, size);
                y += re_e;
                res[pos] += " \t "; res[pos] += std::to_string(e_d);
                //std::cout << y.str() << "\t";
                //std::cout << "Чтобы исправить ошибку, выполним сложение y(x) = y(x) + e(x) = " << y.str() << std::endl << std::endl;
            } else {
                y = c;
            }

            //std::cout << "Для проверки правильности принятого кода вычисляем y(e) = ";
            // std::cout << y.str_epsilon() << " = ";
            Polynomial syndrome = y.sum_epsilon();
            //std::cout << syndrome.str('e'); //<< std::endl;
            int e_d = syndrome.error_digit();
            if (e_d == -1) {
                //std::cout << "Ошибок не обнаружено" << std::endl << std::endl;
            } else {
                //std::cout << "Ошибка произошла в " << e_d << "-м бите" << std::endl;
            }

            y <<= 3;
            //std::cout << "Отбрасываем проверочные биты, получаем многочлен " << y.str() << std::endl;
            std::cout << "\tDecode: i(x)=" << y.str() << std::endl;// << "=" << y.str_bit() << std::endl;
            //std::cout << "Он соответствует информационному слову " << y.str_bit() << std::endl << std::endl;
            //std::cout << y.str_bit();
            pos++;
            getchar();
            if ((raw_str.length() - count * 4) < 4) {
                std::cout << "Сообщ.   Кодов. сл. \t С ошибкой \tСиндром" << std::endl;
                for (int i = 0; i < raw_str.length() / 4; i++) {
                    std::cout << res[i] << std::endl;
                }
                std::cout << "Success coding!" << std::endl;
                exit(0);
            }
        }
        std::cout << "Finish" << std::endl;
        exit_f = (choose("Code again? 1/0", 1, 0) == 0);
    }
    return 0;
}
