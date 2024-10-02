

#ifndef TI_CRC_H
#define TI_CRC_H

#include "HemingMatr.h"


class CRC {
private:
    size_t m,n,k,e;
    HemingMatr *G;
    void makeG();
    bool isSimple(size_t);
    size_t getMinSimpleDiv(size_t);
public:
    CRC(size_t);
    HemingMatr &codings(HemingMatr &);
    HemingMatr &coding(HemingMatr &);
    HemingMatr &deCodings(HemingMatr &);
    size_t getSindrom(HemingMatr &);
    HemingMatr &getInfBit(HemingMatr &);
    size_t getN();
    ~CRC();
};



#endif //TI_CRC_H
