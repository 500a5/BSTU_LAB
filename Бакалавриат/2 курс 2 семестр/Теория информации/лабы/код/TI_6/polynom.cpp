#include "polynom.h"

/*
 * Конструкторы
 */
Polynomial::Polynomial(const bool *coefficients) : coefficients(new bool[size]) {
    for (int i = 0; i < size; i++){
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &object) : coefficients(new bool[size]) {
    for (int i = 0; i < size; i++){
        coefficients[i] = object.coefficients[i];
    }
}

Polynomial::Polynomial(size_t n, size_t sz) : coefficients(new bool[size]){
    for (int i = 0; i<size; i++){
        this->coefficients[i] = false;
    }
    this->coefficients[n] = true;
}

Polynomial::Polynomial(unsigned short value): coefficients(new bool[size]){
    for (int i = 0; i < size; i++){
        coefficients[i] = (value & 1);
        value >>= 1;
    }
}

/*
 * Преобразования вывода
 */

/*
 * В виде числа
 */
unsigned short Polynomial::bit() const {
    unsigned short result = 0;
    for (int i = 0; i < size; i++){
        result |= (coefficients[i] << i);
    }
    return result;
}

/*
 * Строковое двоичное представление
 */
std::string Polynomial::str_bit() const {
    std::stringstream result;
    for (int i = 0; i < size; i++){
        result << coefficients[i];
    }
    return result.str();
}

/*
 * Строковое представление как многочлена
 */
std::string Polynomial::str() const {
    std::stringstream result;
    bool more_than_one = false;
    for (int i = size - 1; i > 0; i--){
        if (coefficients[i]){
            if (more_than_one){
                result << "+";
            }
            result << "x";
            // Первую степень не отображаем
            if (i != 1){
                result << i;
            }
            more_than_one = true;
        }
    }
    if (coefficients[0]){
        if (more_than_one){
            result << "+";
        }
        result << "1";
    }else{
        if (!more_than_one) {
            result << "0";
        }
    }
    return result.str();
}

/*
 * Тоже строковое представление многочлена, но с параметром - подставляемой буквой
 */
std::string Polynomial::str(char c) const {
    std::stringstream result;
    bool more_than_one = false;
    for (int i = size - 1; i > 0; i--){
        if (coefficients[i]){
            if (more_than_one){
                result << "+";
            }
            result << c;
            // Первую степень не отображаем
            if (i != 1){
                result << i;
            }
            more_than_one = true;
        }
    }
    if (coefficients[0]){
        if (more_than_one){
            result << "+";
        }
        result << "1";
    }else{
        if (!more_than_one) {
            result << "0";
        }
    }
    return result.str();
}

/*
 * Строковое представление, получающееся при подстановке и замене соотв. степеней эпсилон
 */
std::string Polynomial::str_epsilon() {
    std::stringstream result;
    bool more_than_one = false;
    for (int i = size - 1; i > 0; i--){
        if (coefficients[i]){
            if (more_than_one){
                result << "+";
            }
            result << Polynomial(epsilon[i % 7 + 1]).str('e');
            more_than_one = true;
        }
    }
    if (coefficients[0]){
        result << "+1";
    }else{
        if (!more_than_one) {
            result << "0";
        }
    }
    return result.str();
}

/*
 * Вспомогательное
 */

/*
 * Обобщенная функция деления, возвращает и частное, и остаток
 */
void Polynomial::divide(const Polynomial &left, const Polynomial &right, Polynomial **result, Polynomial **remainder) {
    Polynomial dividend = left, divisor = right;
    bool new_coefficients[size] = {0};
    auto l_m = left.max_power(), r_m = right.max_power();
    // Если делимое меньше делителя, то делимое становится остатком, а частное 0
    while (l_m > r_m){
        // Сдвигаем делитель с тем, чтобы его степень стала равной степени делимого.
        // Это эквивалентно умножению на x^(l_m-r_m)
        dividend += (divisor >> (l_m - r_m));
        new_coefficients[l_m - r_m] = 1;
        l_m = dividend.max_power();
        r_m = divisor.max_power();
    }
    if (l_m == r_m){
        dividend += divisor;
        new_coefficients[0] = 1;
    }
    *remainder = new Polynomial(dividend);
    *result = new Polynomial(new_coefficients);
}

/*
 * Возвращает максимальную степень полинома
 */
size_t Polynomial::max_power() const {
    size_t max = 0;
    for (size_t i = 0; i < size; i++){
        if (coefficients[i]){
            max = i;
        }
    }
    return max;
}

/*
 * Подстановка эпсилонов из таблицы
 */
Polynomial Polynomial::sum_epsilon() {
    bool new_coefficients[size] = {0};
    // XOR'ом складываем все строки эпсилонов, заменяющие исходные степени
    for (int i = 0; i < size; i++){
        if (coefficients[i]){
            for (int j = 0; j < size; j++){
                // Делаем XOR для строки эпсилонов
                new_coefficients[j] = new_coefficients[j] != epsilon[i % 7 + 1][j];
            }
        }
    }
    return Polynomial(new_coefficients);
}

/*
 * Сравнение двух массивов
 */
bool Polynomial::equal(const bool ar1[size], const bool ar2[size]){
    int i = 0;
    while (i < size && ar1[i] == ar2[i]){
        i++;
    }
    return i == size;
}

/*
 * Получение номера ошибочного бита
 */
int Polynomial::error_digit(){
    for (int i = 0; i < sizeof(epsilon) / sizeof(epsilon[0]); i++){
        if (Polynomial::equal(this->coefficients, epsilon[i])){
            return i - 1;
        }
    }
    return -1;
}

/*
 * Перегрузка операторов
 */

const Polynomial operator+(const Polynomial &left, const Polynomial &right) {
    return Polynomial(left.bit() ^ right.bit());
}

const Polynomial operator*(const Polynomial &left, const Polynomial &right) {
    unsigned short num1 = left.bit(), num2 = right.bit(), result = 0;
    // Идея умножения следующая: результирующий полином включает в себя num1 << i, если i-й бит num2 равен 1.
    /*
     * num1    1011
     * num2
     * 1       1011+
     * 0      0000+
     * 0     0000+
     * 1    1011
     * res  1010011
     */
    for (int i = 0; i < size; i++){
        if (num2 & 1){
            result ^= (num1 << i);
        }
        num2 >>= 1;
    }
    return Polynomial(result);
}

Polynomial &operator+=(Polynomial &left, const Polynomial &right) {
    for (int i = 0; i < size; i++){
        left.coefficients[i] = left.coefficients[i] != right.coefficients[i];
    }
    return left;
}

Polynomial &operator<<=(Polynomial &left, size_t offset) {
    for (int i = 0; i < size - offset; i++){
        left.coefficients[i] = left.coefficients[i+offset];
    }
    for (int i = size - offset; i < size; i++){
        left.coefficients[i] = 0;
    }
    return left;
}

Polynomial &operator>>=(Polynomial &left, size_t offset) {
    for (int i = size - 1; i >= offset; i--){
        left.coefficients[i] = left.coefficients[i-offset];
    }
    for (int i = offset - 1; i >= 0; i--){
        left.coefficients[i] = 0;
    }
    return left;
}

const Polynomial operator>>(const Polynomial &left, size_t offset) {
    Polynomial result;
    for (int i = size - 1; i >= offset; i--){
        result.coefficients[i] = left.coefficients[i-offset];
    }
    for (int i = offset - 1; i >= 0; i--){
        result.coefficients[i] = 0;
    }
    return result;
}

const Polynomial operator/(const Polynomial &left, const Polynomial &right) {
    Polynomial *res, *rem;
    Polynomial::divide(left, right, &res, &rem);
    return *res;
}

const Polynomial operator%(const Polynomial &left, const Polynomial &right) {
    Polynomial *res, *rem;
    Polynomial::divide(left, right, &res, &rem);
    return *rem;
}