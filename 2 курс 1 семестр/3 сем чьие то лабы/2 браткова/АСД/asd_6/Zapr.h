#ifndef ZAPR_H_INCLUDED
#define ZAPR_H_INCLUDED

typedef struct TInquiry
{
    char Name[10]; // ��� �������sdf
    unsigned Time; // ����� ������������
    unsigned short int P; /* ��������� 0 � ������, 1 � �������, 2 � ������ */
} TInquiry;

void ReadZapros (TInquiry *a, size_t n);
void WriteZapros (TInquiry *a, size_t n);
void GenZapros (TInquiry *a);
void WriteOneZapr (TInquiry a);
void GenMassZapros (TInquiry *a, size_t n);

#endif // ZAPR_H_INCLUDED
