#ifndef ZAP_H_INCLUDED
#define ZAP_H_INCLUDED

typedef struct TInquiry
{
    char Name[10]; // им€ запросаsdf
    unsigned Time; // врем€ обслуживани€
    unsigned short int P; // приоритет 0 Ч высший, 1 Ч средний, 2 Ч низший
} TInquiry;


void WriteOneZapr (TInquiry a);
void ReadOneZapr (TInquiry a);

#endif // ZAP_H_INCLUDED
