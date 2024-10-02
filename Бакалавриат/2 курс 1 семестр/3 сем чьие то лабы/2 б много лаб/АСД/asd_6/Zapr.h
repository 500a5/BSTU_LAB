#ifndef ZAPR_H_INCLUDED
#define ZAPR_H_INCLUDED

typedef struct TInquiry
{
    char Name[10]; // им€ запросаsdf
    unsigned Time; // врем€ обслуживани€
    unsigned short int P; /* приоритет 0 Ч высший, 1 Ч средний, 2 Ч низший */
} TInquiry;

void ReadZapros (TInquiry *a, size_t n);
void WriteZapros (TInquiry *a, size_t n);
void GenZapros (TInquiry *a);
void WriteOneZapr (TInquiry a);
void GenMassZapros (TInquiry *a, size_t n);

#endif // ZAPR_H_INCLUDED
