#ifndef FORM4_H_INCLUDED
#define FORM4_H_INCLUDED

//#define OK 0
//#define OUT 1
//const int out = 1;
//const int ok = 0;

typedef struct
{
    char st[1024];
    unsigned n; // Динамическая длина строки с учетом нольсимволоа
} string1;

void InputStr(string1* s);
void OutputStr(string1 s);
void WriteToStr (string1 stt, char *s);
void WriteFromstr(char *s1, string1 s);
int CComp(string1 s1, string1 s2);
void Delete(string1* s, unsigned ind, unsigned cou);
void Concat(string1 s1, string1 s2, string1* srez);
void Copy(string1 s, unsigned Index, unsigned Count, string1* Subs);
unsigned Pos(string1 SubS, string1 s);
unsigned LastPos(string1 s1, string1 s2);

int StrError; //переменая ошибок

#endif // FORM4_H_INCLUDED
