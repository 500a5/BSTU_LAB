

#include "CRC.h"

CRC::CRC(size_t m) : m(m) {
    n = (1<<m) - 1;
    k = n -m;
    makeG();
    cout << "Ваш Пораждающий многочлен: ";
    G->MNprintMatr();
}

HemingMatr &CRC::codings(HemingMatr &message) {
    HemingMatr *newMatr = new HemingMatr(1,(message.lenghtCode()/k)*n);
    HemingMatr mask = HemingMatr(1, k);
    int i = 0;
    int l = 0;
    while (i<message.lenghtCode()){
        for (int j = 0; j < k; ++j) {
            mask[0][j] = message[0][i+j];
        }
        HemingMatr &tmp = coding(mask);
        for (int j = 0; j < n; ++j) {
            (*newMatr)[0][j + l] = tmp[0][j];
        }
        i+=k;
        l+=n;
    }

    return *newMatr;
}

HemingMatr &CRC::coding(HemingMatr &message) {
    message.reverse();
    HemingMatr *code = new HemingMatr(1, n);
    HemingMatr tmp = HemingMatr(1, n);
    for(int i = 0; i<message.lenghtCode(); ++i){
        (*code)[0][i] = message[0][i];
        tmp[0][i] = message[0][i];
    }

    for (int i = 0; i < k; ++i) {
        if (tmp[0][i] != 0)
            for (int j = 0; j < (*G).lenghtCode(); ++j)
                tmp[0][i+j] ^= (*G)[0][j];

    }

    for (int i = 0; i < n; ++i)
        (*code)[0][i] |= tmp[0][i];
    code->reverse();
    return  *code;
}

HemingMatr &CRC::deCodings(HemingMatr &code) {
    HemingMatr *newMatr = new HemingMatr(1,(code.lenghtCode()/n)*k);
    HemingMatr mask = HemingMatr(1, n);
    int i = 0;
    int l = 0;
    while (i<code.lenghtCode()){
        for (int j = 0; j < n; ++j) {
            mask[0][j] = code[0][i+j];
        }
        size_t sindrom = getSindrom(mask);
        if (sindrom) {
            cerr << "Искажение в " << sindrom<< " бите" << endl;
            cout << "Синдром E^" << sindrom << endl;
            mask[0][sindrom - 1] = !mask[0][sindrom - 1];
            cout << "Исправленное сообщение: ";
            mask.NTprintMatr();
            cout << endl;
        }
        i+=n;
        mask.reverse();
        HemingMatr &tmpI = getInfBit(mask);
        tmpI.reverse();
        for (int j = 0; j < k; ++j) {
            (*newMatr)[0][j+l] = tmpI[0][j];
        }
        l+=k;

    }


    return *newMatr;
}

HemingMatr &CRC::getInfBit(HemingMatr &message) {
    HemingMatr *inf = new HemingMatr(1,k);
    for (size_t i = 0; i < k; ++i)
        (*inf)[0][i] = message[0][i];
    return *inf;
}

size_t CRC::getN() {
    return n;
}

CRC::~CRC() {
    delete G;
}

void CRC::makeG() {

    if (m == 3){
        G = new HemingMatr(11);
        e = 1;
    }else if(m==4){
        G = new HemingMatr(19);
        e = 2;
    }else{
        cout << "Пожалуйста введите порождающий многочлен в двоичном представлении";
        string mnog;
        cin >> mnog;
        G = new HemingMatr(1, mnog.length());
        G->inputMatr(mnog);
    }
}

size_t CRC::getMinSimpleDiv(size_t num) {
    size_t rez = 11;
    for (int i = 2; i <=num; ++i)
        if(isSimple(i))
            if((num % i) == 0)
                return i;
    return rez;
}

bool CRC::isSimple(size_t num) {
    for(int i = 2; i<num; i++)
        if ((num % i) == 0 && num > 3)
            return false;
    return true;
}

int getW(HemingMatr &matr){
    size_t count = 0;
    for (int i = 0; i < matr.lenghtCode(); ++i)
        if(matr[0][i])
            ++count;
    return count;
}

void circleL(HemingMatr &matr){
    int head = matr[0][0];
    for (int i = 0; i < matr.lenghtCode() - 1; ++i)
            matr[0][i] = matr[0][i+1];
    matr[0][matr.lenghtCode() - 1] = head;
}
void circleR(HemingMatr &matr){
    int last = matr[0][matr.lenghtCode() - 1];
    for (int i = matr.lenghtCode() - 1; i >= 1; --i) {
        matr[0][i] = matr[0][i-1];
    }
    matr[0][0] = last;
}
size_t CRC::getSindrom(HemingMatr &message) {
    HemingMatr tmp = HemingMatr(1, n);
    for (int i = 0; i < message.lenghtCode(); ++i)
        tmp[0][i] = message[0][i];
    tmp.reverse();
    HemingMatr processTmp = HemingMatr(1, n);
    for (int i = 0; i < message.lenghtCode(); ++i)
        processTmp[0][i] = tmp[0][i];
    processTmp.printMatr();
    cout<<endl;
    size_t countCircle = 0;
    while (getW(processTmp) > e){
        for (int i = 0; i < message.lenghtCode(); ++i)
            processTmp[0][i] = tmp[0][i];
        for (int i = 0; i < k; ++i) {
            if (processTmp[0][i] != 0)
                for (int j = 0; j < (*G).lenghtCode(); ++j)
                    processTmp[0][i + j] ^= (*G)[0][j];
        }
        circleL(tmp);
        ++countCircle;
    }
    circleR(tmp);
    --countCircle;
    for (int i = 0; i < n; ++i)
        tmp[0][i] ^= processTmp[0][i];
    for (int i = 0; i < countCircle; ++i)
        circleR(tmp);
    size_t sindrom = 0;
    tmp.reverse();
    for (int i = 0; i < tmp.lenghtCode(); ++i)
        if(tmp[0][i] != message[0][i])
            sindrom= i + 1;
    return sindrom;

}
