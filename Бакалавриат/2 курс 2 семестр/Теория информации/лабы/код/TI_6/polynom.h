

#ifndef TINF7_POLYNOM_H
#define TINF7_POLYNOM_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

/*
// Конструируется многочлен начиная с младшей степени
// Здесь, к примеру, будет 1 + x^2
bool c1[size] = {1, 0, 1};
Polynomial p1(c1);

// А здесь (0 + 0x +) x^2 + x^3
bool c2[size] = {0, 0, 1, 1};
 */

/* Для кода (7; 4) многочлены уже заранее посчитаны, поэтому в программе считать их не будем. Лучше зададим
 * константой. Разложение x7+1 = (x+1)(x3+x+1)(x3+x2+1). Из этих многочленов порождающим выбран g(x) = x3+x+1.
 * Кодовое слово получается из введенного вектора i по формуле c(x) = xr * i(x) + Rem(g(x)*i(x)), r = 3 (наибольшая степень g(x))
 * Проверочный многочлен это h(x) = (x7 + 1)/g(x) = x4+x2+x+1.
 * В канале связи к слову c(x) может прибавиться случайная ошибка e(x)
 * Пускай принято слово y(x) = c(x) + e(x). Тогда нужно подставить в многочлен y(x) некоторый epsilon, соответствующий полю.
 * Если y(epsilon) = 0, то многочлен принят верно, иначе степень epsilon локализует ошибку.
 *
 * Таблица элементов поля GF(2^3):
 * 0    0
 * 1    1
 * e    e
 * e2   e2
 * e3   e+1
 * e4   e2+e
 * e5   e2+e+1
 * e6   e2+1
 * e7   1
 * ...
 */

const size_t size = 7;

const bool epsilon[][size] = {
        {0},        // 0
        {1},        // 1
        {0, 1},     // e
        {0, 0, 1},  // e2
        {1, 1},     // e3 = e + 1
        {0, 1, 1},  // e4 = e2 + e
        {1, 1, 1},  // e5 = e2 + e +1
        {1, 0, 1}   // e6 = e2 + 1
};

const bool const_g[size] = {1, 1, 0, 1};    // Соответствует x3+x+1
const bool const_xr[size] = {0, 0, 0, 1};   // Соответствует x3

class Polynomial{
private:
    // Коэффициенты многочлена, начиная с 0-й степени
    bool *coefficients{};
    static void divide(const Polynomial& left, const Polynomial& right, Polynomial **result, Polynomial **remainder);
    size_t max_power() const;
    static bool equal(const bool ar1[size], const bool ar2[size]);
public:
    // Строковое представление полинома
    std::string str() const;
    std::string str(char c) const;
    // Двоичное представление полинома
    std::string str_bit() const;
    // Числовое представление полинома
    unsigned short bit() const;
    // Равный 0 полином
    Polynomial() : coefficients(new bool[size]) {}
    // Полином с заданными коэффициентами
    Polynomial(const bool coefficients[]);
    // Одночлен n-й степени
    Polynomial(size_t n, size_t sz);
    // Полином из числа
    Polynomial(unsigned short value);
    Polynomial(const Polynomial& object);

    // Выводит представление многочлена, в который подставили epsilon и заменили их по таблице для поля GF(2^3)
    std::string str_epsilon();
    // Возвращает получающийся после подстановки эпсилонов многочлен
    Polynomial sum_epsilon();

    friend Polynomial& operator+=(Polynomial& left, const Polynomial& right);
    friend Polynomial& operator<<=(Polynomial& left, size_t offset);
    friend Polynomial& operator>>=(Polynomial& left, size_t offset);
    friend const Polynomial operator+(const Polynomial& left, const Polynomial& right);
    friend const Polynomial operator*(const Polynomial& left, const Polynomial& right);
    friend const Polynomial operator/(const Polynomial& left, const Polynomial& right);
    friend const Polynomial operator%(const Polynomial& left, const Polynomial& right);
    friend const Polynomial operator>>(const Polynomial& left, size_t offset);
    int error_digit();
};


#endif //TINF7_POLYNOM_H
