#ifndef ZAP_H_INCLUDED
#define ZAP_H_INCLUDED

typedef struct TInquiry
{
    char Name[10]; // ��� �������sdf
    unsigned Time; // ����� ������������
    unsigned short int P; // ��������� 0 � ������, 1 � �������, 2 � ������
} TInquiry;


void WriteOneZapr (TInquiry a);
void ReadOneZapr (TInquiry a);

#endif // ZAP_H_INCLUDED
