#ifndef FRACTION_H
#define FRACTION_H


#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Fraction
{
public:
    int denominator, numerator;
public:
    friend int GCD(Fraction a)
    {
        a.denominator = abs(a.denominator);
        a.numerator = abs(a.numerator);
        while (a.denominator && a.numerator)
        {
            if (a.denominator > a.numerator)
                a.denominator %= a.numerator;
            else
                a.numerator %= a.denominator;
        }
        return (a.denominator > a.numerator) ? a.denominator : a.numerator;
    }
    void Zero()
    {
        if (denominator == 0)
            denominator = 1;
    }
    Fraction(int num, int den) : denominator(den), numerator(num)
    {
        int d = GCD(*this);
        numerator /= d;
        denominator /= d;
    };
    Fraction(int num) : denominator(1), numerator(num) {};
    Fraction() : numerator(0), denominator(1) {};
    friend Fraction operator + (Fraction a, Fraction b)
    {
        a.Zero();
        b.Zero();
        Fraction c(a.numerator, a.denominator);
        c.numerator = c.numerator * b.denominator + b.numerator * c.denominator;
        c.denominator *= b.denominator;
        int d = GCD(c);
        c.numerator /= d;
        c.denominator /= d;
        return c;
    }
    friend Fraction operator - (Fraction a, Fraction b)
    {
        a.Zero();
        b.Zero();
        Fraction c(a.numerator, a.denominator);
        c.numerator = c.numerator * b.denominator - b.numerator * c.denominator;
        c.denominator *= b.denominator;
        int d = GCD(c);

        c.numerator /= d;
        c.denominator /= d;
        return c;
    }

    friend Fraction operator * (Fraction a, Fraction b)
    {
        a.Zero();
        b.Zero();
        Fraction c(a.numerator, a.denominator);
        c.numerator *= b.numerator;
        c.denominator *= b.denominator;
        int d = GCD(c);

        c.numerator /= d;
        c.denominator /= d;
        return c;
    }
    friend Fraction operator / (Fraction a, Fraction b)
    {
        a.Zero();
        b.Zero();
        Fraction c(a.numerator, a.denominator);
        if (b.numerator < 0)
            c.numerator *= -b.denominator;
        else
            c.numerator *= b.denominator;
        c.denominator *= abs(b.numerator);
        int d = GCD(c);

        c.numerator /= d;
        c.denominator /= d;
        return c;
    }
    Fraction operator = (Fraction a)
    {
        a.Zero();
        numerator = a.numerator;
        denominator = a.denominator;
    }
    Fraction operator = (int a)
    {
        numerator = a;
        denominator = 1;
    }
    void printFrac()
    {
        if (numerator == 0)
            std::cout << 0;
        else
            if (denominator == 1)
                std::cout << numerator;
            else
                std::cout << numerator << "/" << denominator;
    }
    friend std::ostream& operator << (std::ostream& out, Fraction& a)
    {
        if (a.numerator == 0)
            out << 0;
        else
            if (a.denominator == 1)
                out << a.numerator;
            else
                out << a.numerator << "/" << a.denominator;
        int k = 0;
        int t1 = a.numerator, t2 = a.denominator;
        if (a < 0)
            k++;
        while (t1 > 0 || t2 > 0)
        {
            if (t1 > 0)
            {
                t1 /= 10;
                k++;
            }
            if (t2 > 0)
            {
                t2 /= 10;
                k++;
            }
        }
        if (k < 6)
            out << "\t";
        return out;
    }
    friend std::istream& operator >> (std::istream& in, Fraction& a)
    {
        char c;
        in >> a.numerator;
        c = getchar();
        if (c == '/')
            in >> a.denominator;
        else
            a.denominator = 1;
        int d = GCD(a);
        a.denominator /= d;
        a.numerator /= d;
        return in;
    }

    friend int operator > (Fraction& a, Fraction& b)
    {
        a.Zero();
        b.Zero();
        return (a.numerator * b.denominator > b.numerator* a.denominator);
    }
    friend int operator > (Fraction& a, float b)
    {
        a.Zero();
        return (a.numerator / a.denominator > b);
    }
    friend int operator > (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator > b* a.denominator);
    }
    friend int operator != (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator != b * a.denominator);
    }
    friend int operator == (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator == b * a.denominator);
    }
    friend int operator < (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator < b * a.denominator);
    }
    friend int operator < (Fraction& a, Fraction& b)
    {
        a.Zero();
        b.Zero();
        return (a.numerator * b.denominator < b.numerator * a.denominator);
    }
    friend int operator >= (Fraction& a, Fraction& b)
    {
        a.Zero();
        b.Zero();
        return (a.numerator * b.denominator >= b.numerator * a.denominator);
    }
    friend int operator <= (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator <= b * a.denominator);
    }
    friend int operator >= (Fraction& a, int b)
    {
        a.Zero();
        return (a.numerator >= b * a.denominator);
    }
    Fraction& operator - ()
    {
        numerator *= -1;
    }
};

#endif // FRACTION_H
