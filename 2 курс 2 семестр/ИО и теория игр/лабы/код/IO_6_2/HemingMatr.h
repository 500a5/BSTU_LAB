

#ifndef TI_HEMINGMATR_H
#define TI_HEMINGMATR_H


#include <cstddef>
#include <vector>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string PrintByte(uint8_t a);
uint8_t getMN(string str);

class HemingMatr {
private:
    size_t n,m;
    uint8_t **matr;
    void freeMem();
    void locMem();
public:
    HemingMatr(size_t n, size_t m);
    HemingMatr(size_t num);
    HemingMatr &inputMatr();
    HemingMatr &inputMatr(string);
    HemingMatr &printMatr();
    HemingMatr &NTprintMatr();
    HemingMatr &MNprintMatr();
    HemingMatr &rotateR();
    HemingMatr &reverse();
    void dopis(uint8_t d);
    void cut(uint8_t c);
    int lenghtCode();
    bool checkZero();
    friend HemingMatr & operator^(HemingMatr &, HemingMatr &);
    uint8_t *operator[](size_t);
    ~HemingMatr();

};
class Heming{
private:
    HemingMatr *H, *P, *G, *Ht;
    size_t m,n,k;
    void makeH();
    void makeP();
    void makeG();
public:
    Heming(size_t m);
    Heming &printAllMatr();
    HemingMatr &coding(HemingMatr &);
    HemingMatr &deCoding(HemingMatr &);
    HemingMatr &getInfBit(HemingMatr &);
    size_t getN();
    int getNumberBin(HemingMatr &);
};


#endif //TI_HEMINGMATR_H
