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
 * ����������� ������ � ������ �����
 */
// � ����� ������ �������� �� � ������.
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
    // �������������� ����
    srand(time(NULL));
    // ���� ������
    bool exit_f = false;

    while (!exit_f) {


        std::string i_str;
        std::string raw_str = "10011000101";

        std::string f_name;
        std::cout << "���������: " << raw_str << std::endl;
        std::cout << "����� ��������� - " << raw_str.length() << std::endl;
        std::cout << "�������� �� ������� ��  " << 4 << std::endl ;

        int tcount = 0;
        std::cout << "������� 4 ����, � ������� ������, ������� ����� ���� ��������� � ���������� �����" << std::endl << std::endl;
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
        // �������� 4 �� �������� �����
        while(it + 4 <= raw_str.end()) {
            count++;
            i_str.clear();
            i_str.resize(4);
            for (int i = 0; i<4; i++){
                i_str[i] = *it;
                it++;
            }
            //std::cout << "�������� ����: " << i_str << std::endl;
            bool i_array[size];
            str_to_bools(i_str, i_array);
            Polynomial i(i_array);
            std::cout << i_str << " <=> " << "i(x) = " << i.str() << "\t";

            /// �����������
            Polynomial g(const_g);
            Polynomial xr(const_xr);
            //std::cout << "�������� ������� ����� �� ������� c(x) = x^r * i(x) + Rem_g(x) (x^r * i(x))" << std::endl;
            //std::cout << "g(x) = " << g.str() << std::endl;
            //std::cout << "x^r = " << xr.str() << std::endl;
            Polynomial t = xr * i;
            // std::cout << "x^r * i(x) = " << t.str() << std::endl;
            Polynomial r = t % g;
            //std::cout << "Rem = (x^r * i(x)) % g(x) = " << r.str() << std::endl;
            Polynomial c = t + r;
            std::cout << "C(�)=" << c.str() << "\t";
            res[pos] += " \t ";
            res[pos] += c.str_bit();
            //std::cout << "c(x) = x^r * i(x) + Rem = " << c.str() << std::endl;
            //std::cout << "� ����� ����� ���������� ������������������ " << c.str_bit() << std::endl << std::endl;

            bool corrupt_bit;

            // ��������, ����� ���


            //corrupt_bit = rand() % 3; // ����������� �� �������� ������ 1/3

            // ���� ������ ��������� ������� ������, ������ ��� ������
            corrupt_bit = true;

            // ���� �������� �������� ������ �������, ������ ��� ������
            //corrupt_bit = choose("������ ������ � ������������ ���������? 1 - �� �������, 2 - ������: ", 1, 2) - 1;


            Polynomial y;

            if (corrupt_bit) {
                int bit =4;
                Polynomial e(bit, size);
                //std::cout << "������ ������ � " << bit << "-� ��� ������������� ����� c, �������� ����� y(x) = c(x) + e(x)" << std::endl;
                y = c + e;
                //std::cout << "y(x) = " << c.str() << " + " << e.str() << " = " << y.str() << std::endl << std::endl;
                std::cout << "\t�(�) = " << y.str() << " ";
                res[pos] += " \t "; res[pos] += y.str_bit();
                //std::cout << "������� ������ ������������������ " << y.str_bit() << std::endl;
                //std::cout << y.str_bit();
                //std::cout << "��� �������� ������������ ��������� ���� ��������� y(e) = ";
                std::cout << std::endl <<"y(e) = " << y.str_epsilon() << "=";
                Polynomial syndrome = y.sum_epsilon();
                std::cout << syndrome.str('e');
                int e_d = syndrome.error_digit();

                if (e_d >= 3) {
                    std::cout << "=e" << e_d;
                }
                //std::cout << std::endl;

                //std::cout << "������ ��������� � " << e_d << "-� ����" << std::endl << std::endl;
                Polynomial re_e(e_d, size);
                y += re_e;
                res[pos] += " \t "; res[pos] += std::to_string(e_d);
                //std::cout << y.str() << "\t";
                //std::cout << "����� ��������� ������, �������� �������� y(x) = y(x) + e(x) = " << y.str() << std::endl << std::endl;
            } else {
                y = c;
            }

            //std::cout << "��� �������� ������������ ��������� ���� ��������� y(e) = ";
            // std::cout << y.str_epsilon() << " = ";
            Polynomial syndrome = y.sum_epsilon();
            //std::cout << syndrome.str('e'); //<< std::endl;
            int e_d = syndrome.error_digit();
            if (e_d == -1) {
                //std::cout << "������ �� ����������" << std::endl << std::endl;
            } else {
                //std::cout << "������ ��������� � " << e_d << "-� ����" << std::endl;
            }

            y <<= 3;
            //std::cout << "����������� ����������� ����, �������� ��������� " << y.str() << std::endl;
            std::cout << "\tDecode: i(x)=" << y.str() << std::endl;// << "=" << y.str_bit() << std::endl;
            //std::cout << "�� ������������� ��������������� ����� " << y.str_bit() << std::endl << std::endl;
            //std::cout << y.str_bit();
            pos++;
            getchar();
            if ((raw_str.length() - count * 4) < 4) {
                std::cout << "�����.   �����. ��. \t � ������� \t�������" << std::endl;
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
