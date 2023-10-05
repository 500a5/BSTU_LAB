#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#if !defined(__FORM1_H)
//#define __FORM1_H
//const ...; // Определение исключительных ситуаций
typedef char string1[256];
// Признак конца строки - символ '\0'
enum ER {
    ERROR_INSERT,
    ERROR_DELETE,
    ERROR_CONCAT,
    ERROR_COPY,
    ERROR_POS
        };
int ERR=0;
void StErr ();
int Length(string1 s);
//Запись данных в строку st из строки s. Строка s заканчивается нулевым символом '\0'.
void WriteToStr(string1 st, char *s)
{
    while (*st++ = *s++);
}
//Запись данных в строку s из строки st. Строка s заканчивается нулевым символом '\0'.
void WriteFromStr(char *s, string1 st)
{
    while (*s++ = *st++);
}

//Ввод строки s с клавиатуры.
void InputStr(string1 s)
{
    gets(s);
}

//Вывод строки s на экран монитора.
void OutputStr(string1 s)
{
    puts(s);
}
// Сравнивает строки s1 и s2. Возвращает 0 если s1 = s2; 1, если s1 > s2; -1, если s1 < s2.
int Comp(string1 s1, string1 s2)
{
    for (;*s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

//Удаляет Count символов из строки s, начиная с позиции Index.
void Delete(string1 s, unsigned Index, unsigned Count)
{
    int i;
    if (i+Count>Length(s))
    {
        ERR=1;
        StErr();
    }

    for (i=Index;s[i];i++)
        s[i]=s[i+Count];
}
//Вставляет подстроку SubS в строку s, начиная с позиции  Index.
void Insert(string1 Subs, string1 s, unsigned Index)
{
    unsigned i,j,l1,l2;
    l1=Length(s);
    l2=Length(Subs);
    if (l1<l2+Index-1)
    {
        ERR=2;
        StErr();
    }
    else
    {
        s[l1+l2]='\0';
        for (i=l1+l2-1,j=Index+l2-1;i>Index-1;i--,j--)
            s[i]=s[j];
        for (i=Index,j=0;j<l2;i++,j++)
            s[i]=Subs[j];
    }
}

//Выполняет конкатенацию строк s1 и s2. Результат помещает в srez.
void Concat(string1 s1, string1 s2, string1 srez)
{
    if (Length(s1)+Length>255)
    {
        ERR=3;
        StErr();
    }
    while (*srez++ = *s1++);
    *srez--;
    while (*srez++ = *s2++);
}

//Записывает Count символов в строку Subs из строки s, начиная с позиции Index.
void Copy(string1 s, unsigned Index, unsigned Count, string1 Subs)
{
    int i,l,j;
    if (Index+Count<255)
    {
        ERR=4;
        StErr();
    }
    for (i=Index,j=0;i<=Count;i++,j++)
        Subs[i]=s[j];

}

//Возвращает текущую длину строки S
int Length(string1 s)
{
    int i=0;
    while (s[i])
        i++;
    return i;
}

//Возвращает позицию, начиная с которой в строке s располагается под-строка SubS.
unsigned Pos(string1 SubS, string1 s)
{
    int i=0,j=0,k,fl=1;
    while (s[i])
    {
        while (s[i]!=SubS[j])
            i++;
        if (!s[i] || i+Length(SubS)<255)
        {
            ERR=1;
            StErr();
        }
        k=i++;
        for (j++,i++;SubS[j] &&s[i] && fl;i++,j++)
            fl=s[i]==SubS[j];
        if(fl)
            break;
        i=k;
        j=0;
        fl=1;
    }
    return k;
}
//нахождение длины той части строки s, которая не сoдержит символы из строки s1.
void main ()
{
    setlocale (LC_ALL, "Rus");
    string1 s,s1;
    unsigned k;
    InputStr(s);
    InputStr(s1);
    k=StrCSpn(s,s1);
    printf ("k = %d\n",k);
    StErr();
}

int StrCSpn(string1 s, string1 s1)
 {
     int i,j,k=0,fl=1;

     for (i=0;s[i]!=0;i++)
     {
         for (j=0;s1[j]!=0 && fl;j++)
         {
             fl=(s[i]!=s1[j]);
         }
         if (fl)
            k++;
         fl=1;
     }
     return k;
 }

 void StErr ()
 {
     switch (ERR)
     {
         case 0: printf ("\nОшибок не произошло\n");
                exit(ERR);
         case 1: printf ("\nОшибка в функции Delete\n");
                exit(ERR);
         case 2: printf ("\nОшибка в функции Insert\n");
                exit(ERR);
         case 3: printf ("\nОшибка в функции Concat\n");
                exit(ERR);
         case 4: printf ("\nОшибка в функции Copy\n");
                exit(ERR);
         case 5: printf ("\nОшибка в функции Pos\n");
                exit(ERR);
     }
 }
//int StrError; // Переменная ошибок
      //...
//    #endif

