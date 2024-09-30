

#include "HemingMatr.h"

HemingMatr &operator^(HemingMatr &a, HemingMatr &b) {
    HemingMatr *result = new HemingMatr(a.n, b.m);
    for (size_t i = 0; i < a.n; ++i)
        for (size_t j = 0; j < b.m; ++j)
            for (size_t k = 0; k < a.m; ++k)
                (*result)[i][j] ^= a[i][k] & b[k][j];

    return *result;
}

uint8_t *HemingMatr::operator[](size_t index) {
    return matr[index];
}

HemingMatr &HemingMatr::printMatr() {
    cout << "Ваша матрица размера " << n << "x" << m << endl;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            cout << (unsigned int)matr[i][j];
        if(i!= n - 1)
            cout << endl;
    }
    return *this;
}

HemingMatr &HemingMatr::rotateR() {
    uint8_t **newMatr = (uint8_t **)calloc(m,n);
    for (size_t i = 0; i < m; ++i)
        newMatr[i] = (uint8_t *)calloc(n, sizeof(uint8_t));

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            newMatr[j][n-i-1] = matr[i][j];

    freeMem();
    matr = newMatr;
    swap(m,n);

    return *this;
}

void HemingMatr::freeMem() {
    for (size_t i = 0; i < n; ++i)
        free(matr[i]);
    free(matr);
}

HemingMatr::~HemingMatr() {
    freeMem();
}

void HemingMatr::locMem() {
    matr = (uint8_t **)calloc(n, sizeof(uint8_t *));
    for (size_t i = 0; i < n; ++i)
        matr[i] = (uint8_t *)calloc(m, sizeof(uint8_t));
}

HemingMatr::HemingMatr(size_t n, size_t m):n(n),m(m){
    locMem();
}

HemingMatr &HemingMatr::inputMatr() {
    cout << "Введите матрицу " << n << "x" << m << endl;
    char checkTmp = 0;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j) {
            cin >> checkTmp;
            if(checkTmp == '1')
                matr[i][j] = 1;
            else
                matr[i][j] = 0;
        }
    return *this;
}

bool HemingMatr::checkZero() {
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if(matr[i][j] != 0)
                return false;
    return true;
}

int HemingMatr::lenghtCode() {
    return m;
}

HemingMatr &HemingMatr::NTprintMatr() {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            cout << (unsigned int)matr[i][j];
        if(i!= n - 1)
            cout << endl;
    }
    return *this;
}

void HemingMatr::dopis(uint8_t d) {
    matr[0] = (uint8_t *)(realloc(matr[0], m + d));
    for (int i = m; i < m+d; ++i) {
        matr[0][i] = 0;
    }
    m+=d;
}

void HemingMatr::cut(uint8_t c) {
    matr[0] = (uint8_t *)(realloc(matr[0], m - c));
    m-=c;
}

HemingMatr &HemingMatr::inputMatr(string message) {
    for (int i = 0; i < m; ++i) {
        if(message[i] == '1')
            matr[0][i] = 1;
        else
            matr[0][i] = 0;
    }
    return *this;
}

HemingMatr::HemingMatr(size_t num) {
    size_t size = 0;
    size_t tmp = num;
    while(tmp){
        ++size;
        tmp>>=1;
    }
    n = 1;
    m = size;
    locMem();
    size_t position = size - 1;
    while (num){
        (*matr)[position] = num & 1;
        num >>= 1;
        --position;
    }
}

HemingMatr &HemingMatr::MNprintMatr() {
    for (int i = m-1; i >= 0; --i) {
        if ((*matr)[m-i-1]) {
            if (i)
                cout << "+X^" << i;
            else
                cout << "+1";
        }
    }
    cout<<endl;
    return *this;
}

HemingMatr &HemingMatr::reverse() {
    for (int i = 0; i < m/2; ++i) {
        swap((*matr)[i], (*matr)[m-i-1]);
    }
    return *this;
}


Heming::Heming(size_t m):m(m){
    n = (1<<m) - 1;
    k = n - m;

    makeH();
    makeP();
    makeG();
}

void Heming::makeH() {
    H = new HemingMatr(this->m,n);
    for (size_t i = 0; i < 15; ++i) {
        size_t tmp = i + 1;
        for (int j = m - 1; j >= 0; --j) {
            (*H)[j][i] = tmp & 1;
            tmp >>= 1;
        }
    }
    Ht = new HemingMatr(n,m);
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            (*Ht)[j][i] = (*H)[i][j];
}

Heming &Heming::printAllMatr() {
    cout << "H матрица" << endl;
    (*H).printMatr();
    cout << endl;
    cout << "P матрица" << endl;
    (*P).printMatr();
    cout << endl;
    cout << "G матрица" << endl;
    (*G).printMatr();
    cout << endl;
    return *this;
}
int isPow2(int a) {
    return !(a&(a-1));
}
void Heming::makeP() {
    P = new HemingMatr(m, k);
    int count = 0;
    for (int j = 0; j < n; ++j) {
        if (!isPow2(j+1)) {
            for (size_t i = 0; i < m; ++i)
                (*P)[i][count] = (*H)[i][j];
            ++count;
        }
    }
    P->rotateR();
}

void Heming::makeG() {
    G = new HemingMatr(k, n);
    int positionP = 0;
    int positionOne = 0;
    for (int j = 0; j < n; ++j) {
        if (isPow2(j+1)){
            for (size_t i = 0; i < k; ++i)
                (*G)[i][j] = (*P)[i][positionP];
            ++positionP;
        }else{
            (*G)[positionOne][j] = 1;
            ++positionOne;
        }
    }
}

HemingMatr &Heming::coding(HemingMatr &message) {
    HemingMatr *newMatr = new HemingMatr(1,(message.lenghtCode()/k)*n);
    HemingMatr mask = HemingMatr(1, k);
    int i = 0;
    int l = 0;
    while (i<message.lenghtCode()){
        for (int j = 0; j < k; ++j) {
            mask[0][j] = message[0][i+j];
        }
        HemingMatr &tmp = mask^(*G);
        for (int j = 0; j < n; ++j) {
            (*newMatr)[0][j + l] = tmp[0][j];
        }
        i+=k;
        l+=n;
    }

    return *newMatr;
}

HemingMatr &Heming::deCoding(HemingMatr &code) {
    HemingMatr *newMatr = new HemingMatr(1,(code.lenghtCode()/n)*k);
    HemingMatr mask = HemingMatr(1, n);
    int i = 0;
    int l = 0;
    while (i<code.lenghtCode()){
        for (int j = 0; j < n; ++j) {
            mask[0][j] = code[0][i+j];
        }
        HemingMatr &sindrom = mask^(*Ht);
        if (!sindrom.checkZero()) {
            int position = getNumberBin(sindrom);
            cerr << "Искажение в " << position + i << " бите" << endl;
            mask[0][position- 1] = !mask[0][position - 1];
        }
        i+=n;
        HemingMatr &tmpI = getInfBit(mask);
        for (int j = 0; j < k; ++j) {
            (*newMatr)[0][j+l] = tmpI[0][j];
        }
        l+=k;
    }


    return *newMatr;
}

HemingMatr &Heming::getInfBit(HemingMatr &message) {
    HemingMatr *inf = new HemingMatr(1,k);
    size_t position = 0;
    for (size_t i = 0; i < n; ++i)
        if(!isPow2(i+1)){
            (*inf)[0][position] = message[0][i];
            ++position;
        }
    return *inf;
}

int Heming::getNumberBin(HemingMatr &sindrom) {
    int result = 0;
    for (size_t i = 0; i < m; ++i) {
        result <<= 1;
        result |= sindrom[0][i];
    }
    return result;
}

size_t Heming::getN() {
    return n;
}

string PrintByte(uint8_t a)
{
    string res = "";
    for (int i = 7; i > -1 ; --i)
        if((a >> i) & 1)
            res += '1';
        else
            res += '0';
    return res;

}

uint8_t getMN(string str) {
    uint8_t res = 0;
    for (int i = 0; i < 8 ; ++i) {
        res<<=1;
        if(str[i] == '1')
            res|=1;
    }
    return res;
}


