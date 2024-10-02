#include "cyclic_coding.h"

void CyclicCode::compute_GF()
{
    E_[0].resize(1, 1);
    std::vector<int> eps(2, 1);
    eps[0] = 0;
    for (int i = 1; i < r_; i++) {
        E_[i] = E_[i - 1] * eps;
    }
    E_[r_] = g_;
    E_[r_].resize(E_[r_].size() - 1);
    dellNull(E_[r_]);
    for (int i = r_ + 1; i < E_.size(); i++) {
        E_[i] = E_[i - 1] * eps;
        if (E_[i].size() == r_ + 1) {
            E_[i].resize(E_[i].size() - 1);
            dellNull(E_[i]);
            E_[i] = E_[i] + E_[r_];
        }
    }
}

std::vector<int> CyclicCode::coding(const std::vector<int>& info)
{
    std::vector<int> c_info(info);
    std::vector<int> xr(g_.size(), 0);
    xr[g_.size() - 1] = 1;
    std::vector<int> xr_i = xr * c_info;
    dellNull(xr_i);
    dellNull(g_);
    std::vector<int> rest = xr_i % g_;
    std::vector<int> code = xr_i + rest;
    output_bound();
    std::cout << "Кодирование: " << std::endl;
    std::cout << "Информационное слово i = ";
    output_vector(info);
    std::cout << std::endl;
    std::cout << "Информационный многочлен i(x) = " << info << std::endl;
    std::cout << "x^r * i(x) = " << xr << " * (" << info << ")" << " = " << xr_i << std::endl;
    std::cout << "Остаток от деления Res(x) = " << rest << std::endl;
    code.resize(n_, 0);
    std::cout << "Кодовое слово c = ";
    output_vector(code);
    std::cout << std::endl;
    std::cout << "Кодовый многочлен c(x) = " << code << std::endl;
    output_bound();
    return code;
}

std::vector<int> CyclicCode::decoding(std::vector<int>& code)
{
    output_bound();
    std::cout << "Декодирование: " << std::endl;
    std::cout << "Принятое слово y = ";
    output_vector(code);
    std::cout << std::endl;
    std::cout << "Принятый многочлен y(x) = " << code << std::endl;
    std::cout << "y(e) = ";
    std::vector<int> c_code = computeE(code);
    std::vector<int> info(k_);
    std::cout << " = \n";
    if (c_code.size() == 0) {
        std::cout << "0 => y(x) = c(x)" << std::endl;
    }
    else {
        output_E(c_code);
        int i = r_;
        while (E_[i] != c_code) {
            i++;
        }
        if (i >= r_) {
             std::cout << " = e" << i;
        }
        std::cout << " => ошибка в " << i << " бите" << std::endl;
        code[i] = (code[i]) ? 0 : 1;
        std::cout << "Исправленное кодовое слово c = {";
        output_vector(code);
        std::cout << "}" << std::endl;
    }
    std::copy(code.begin() + n_ - k_, code.end(), info.begin());
    std::cout << "Информационное слово i = ";
    output_vector(info);
    std::cout << std::endl;
    std::cout << "Информационный многочлен i(x) = " << info << std::endl;
    output_bound();
    return info;
}

void CyclicCode::output_GF()
{
    std::cout << "Сгенерированное поле GF(" << "2^" << r_ << "): " << std::endl;
    for (int i = 0; i < E_.size(); i++) {
        std::cout << "e" << i << " = ";
        output_E(E_[i]);
        std::cout << std::endl;
    }
}

void CyclicCode::output_E(const std::vector<int>& x)
{
    int i = x.size() - 1;
    while (i >= 0 && x[i] == 0) {
        i--;
    }
    if (i > 0) {
        std::cout << "e" << i;
        i--;
        for ( ; i > 0; i--) {
            if (x[i] != 0) {
                std::cout << " + e" << i;
            }
        }
        if (x[0] != 0) {
            std::cout << " + " << x[0];
        }
    } else if (i == 0) {
        std::cout << x[0];
    }
    else {
        std::cout << "0";
    }
}

void CyclicCode::output_bound()
{
    for (int i = 0; i < 100; i++) {
       std::cout << "_";
    }
    std::cout << std::endl;
}

void CyclicCode::output_vector(const std::vector<int>& x)
{
    for (int i = 0; i < x.size(); i++) {
        std::cout << x[i];
    }
}

std::vector<int> CyclicCode::generate_info()
{
    int k = 0;
    std::vector<int> info(k_);
    for (int i = 0; i < k_; i++) {
        k += (info[i] = random(0, 1));
    }
    if (k == 0) {
        info[random(0, k_ - 1)] = 1;
    }
    return info;
}

std::vector<int> CyclicCode::read_info()
{
    std::string c;
    std::cout << "Информационное слово  ";
    std::cin >> c;
    std::vector<int> info(c.size());
    for (int i = 0; i < c.size(); i++)
        info[i] = c[i] - '0';
    /*
    int k = 0;
    std::vector<int> info(k_);
    for (int i = 0; i < k_; i++) {
        k += (info[i] = random(0, 1));
    }
    if (k == 0) {
        info[random(0, k_ - 1)] = 1;
    }
    */
    return info;
}

void CyclicCode::putMistake(std::vector<int>& code)
{
    int k;
//    std::cout << "0 - сгенерировать ошибки случайным образом" << std::endl;
//    std::cout << "1 - внести 1 ошибку вручную" << std::endl;
//    std::cout << "2 - внести 2 ошибки вручную" << std::endl;
//    std::cin >> k;
    k = 0;
    if (!k)
    {
        int nMistake = 2; //random(0, t_);
        if (nMistake) {
            std::cout << "Внесем " << nMistake << " ошибок:\n";
            for (int i = 0; i < nMistake; i++) {
                int index = random(0, n_ - 1);
                code[index] = (code[index]) ? 0 : 1;
                std::cout << "Внесена ошибка в " << index << " бит." << std::endl;
            }
            std::cout << "Кодовое слово с ошибками y = ";
            output_vector(code);
            std::cout <<  std::endl;
        }
    }
    else
    {
        int index;
        for (int i = 0; i < k; i++) {
            std::cout << "№ бита в который нужно внести ошибку  ";
            std::cin >> index;
            //int index = random(0, n_ - 1);
            code[index] = (code[index]) ? 0 : 1;
            //std::cout << "Внесена ошибка в " << index << " бит." << std::endl;
        }
        std::cout << "Кодовое слово с ошибками y = ";
        output_vector(code);
        std::cout <<  std::endl;
    }

}

int CyclicCode::random(int low, int high)
{
    return rand() % (high - low + 1) + low;
}

void dellNull(std::vector<int>& x)
{
    int i = x.size() - 1;
    while (i >= 0 && x[i] == 0) {
        i--;
    }
    if (i == -1) {
        x.resize(0);
    }
    else {
        x.resize(i + 1);
    }
}

std::vector<int> operator * (const std::vector<int>& x1, const std::vector<int>& x2)
{
    std::vector<int> result(x1.size() + x2.size() - 1, 0);
    for (int i = 0; i < x1.size(); i++) {
        for (int j = 0; j < x2.size(); j++) {
            result[i + j] = (result[i + j] + x1[i] * x2[j]) % 2;
        }
    }
    dellNull(result);
    return result;
}

std::vector<int> operator + (const std::vector<int>& x1, const std::vector<int>& x2)
{
    int min = (x1.size() < x2.size()) ? x1.size() : x2.size();
    std::vector<int> result(min);
    for (int i = 0; i < min; i++) {
        result[i] = (x1[i] + x2[i]) % 2;
    }
    if (x1.size() > x2.size()) {
        result.resize(x1.size());
        std::copy(x1.begin() + min, x1.end(), result.begin() + min);
    }
    else {
        result.resize(x2.size());
        std::copy(x2.begin() + min, x2.end(), result.begin() + min);
    }
    dellNull(result);
    return result;
}

std::vector<int> operator % (const std::vector<int>& dividend, const std::vector<int>& devider)
{
    std::vector<int> tmpDividend(dividend);
    int subSize = tmpDividend.size() - devider.size() + 1;
    while (subSize > 0) {
        std::vector<int> sub(subSize, 0);
        sub[subSize - 1] = 1;
        tmpDividend = tmpDividend + (sub * devider);
        subSize = tmpDividend.size() - devider.size() + 1;
    }
    return tmpDividend;
}

bool operator == (const std::vector<int>& x1, const std::vector<int>& x2)
{
    int i = 0;
    while (i < x1.size() && x1[i] == x2[i]) {
        i++;
    }
    if (i == x1.size() && i == x2.size()) {
        return true;
    }
    return false;
}

std::ostream& operator << (std::ostream& stream, const std::vector<int>& x)
{
    int i = x.size() - 1;
    while (i >= 0 && x[i] == 0) {
        i--;
    }
    if (i > 0) {
        stream << "x^" << i;
        i--;
        for ( ; i > 0; i--) {
            if (x[i] != 0) {
                stream << " + x^" << i;
            }
        }
        if (x[0] != 0) {
            stream << " + " << x[0];
        }
    } else if (i == 0) {
        stream << x[0];
    }
    return stream;
}

std::vector<int> CyclicCode::computeE(const std::vector<int>& s)
{
    std::vector<int> c_code(n_ - 1);
    int i = s.size() - 1;
    while (i > 0 && s[i] == 0) {
        i--;
    }
    if (i > 0) {
        c_code = c_code + E_[i];
        i--;
        for ( ; i > 0; i--) {
            if (s[i] != 0) {
                c_code = c_code + E_[i];
            }
        }
        if (s[0] != 0) {
            c_code = c_code + E_[0];
        }
    }
    else if (i == 0) {
        c_code = c_code + E_[0];
    }
    else {
    }
    dellNull(c_code);
    return c_code;
}

int CyclicCode::getNumE(const std::vector<int>& E)
{
    int i = 0;
    while (i < n_ && E_[i] != E) {
        i++;
    }
    return i;
}
