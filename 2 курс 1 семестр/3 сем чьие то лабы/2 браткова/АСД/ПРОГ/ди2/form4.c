#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "form4.h"

void InputStr(string1* s)
{
    char ch=0;
    int i=0, n=0;
    while (ch!='\n')
    {
        ch = getchar();
        (*s).st[i]=ch;
        i++;
    }
    i--;
    (*s).n = i;
    (*s).st[i] = '\0';
   // printf("%d ", s.n);
}

void OutputStr(string1 s)
{
    int i=0, len = s.n;
    for (i=0; (i<len) && (s.st[i]!='\0'); i++)
        //printf("%c", s.st[i]);
        putchar(s.st[i]);
}

void WriteToStr (string1 stt, char *s) //запись данных в строку st, из строки s
{
	int i = 0;

	while (*s++!= '\0')
	{
		stt.st[i]=s[i];
		i++;
	}
	return;
}


void WriteFromstr(char *s1, string1 s) //запись данных в строку s, из строки st
{
	int i = 0;
	int len = s.n;
	if (len > 255)
    {
//        StrError = OK;
        while (s.st[i] != '\0')
            {
                s1[i] = s.st[i];
                i++;
            }
        s1[i] = '\0';
        return;
    }
	else
    {
        //StrError = OUT;
       //printf("«апись не может быть произведена!");
       // return 0;
    }
}

int CComp(string1 s1, string1 s2)
{
	int i;
	for (i = 0; s1.st[i] == s2.st[i]; i++)
		if (s1.st[i] == '\0')
			return 0;
		return s1.st[i] - s2.st[i];
}

void Delete(string1* s, unsigned ind, unsigned cou)
{
	int i=0, k=s->n;
	for (i = ind; i < k; i++)
	{
		s->st[i] = s->st[cou+1];
		cou++;
	}
}

void Insert(string1 SubS, string1* s, unsigned Index) //встав€лет подстроку SubS в строку s, начина€ с позиции index
{
	int i, j = 0, k=s->n;
	int len = SubS.n;
	char c;

	for (i=k+len; i > Index+len; i--)
	{
//		(*s).st[i] = s->st(i - len);
		s->st[i] = s->st[i-len];
		for (i=Index+2; i<=Index+len; i++)
            s->st[i] = SubS.st[i-Index];
	}
}

void Concat(string1 s1, string1 s2, string1* srez)
{
    unsigned i=0;
    (*srez).n=s1.n+s2.n;
    if ((*srez).n < s1.n+s2.n)
    {
//        StrError = OUT;
       // printf("–езультирующуа€ длина меньше!");
       //return 0;
    }
    else
    {
        while (i<s1.n)
            {
                (*srez).st[i] = s1.st[i];
                i++;
            }
        while (i<s2.n + s1.n)
            {
                (*srez).st[i] = s2.st[i-s1.n];
                i++;
            }
        (*srez).st[i]='\0';
        return;
    }
}

void Copy(string1 s, unsigned Index, unsigned Count, string1* Subs)
{
	int i;

	if (Subs->n < Count)
    {
//        StrError = OK;
        for (i = Index + 2; i <= Index+Count+2; i++)
            {
                Subs->st[i-Index] = s.st[i];
                Subs->st[i-Index+1] = '\0';
            }
        return;
    }
	else
    {
//        StrError = OUT;
       // printf("—трока не может быть скопирована!");
       // return 0;
    }
}

unsigned Pos(string1 SubS, string1 s) //возврвщает позицию, с которой в строке s располагаетс€ подстрока SubS
{
	int i, j;
	i=j=0;
	while (SubS.st[i] != '\0')
	{	if (SubS.st[i] == s.st[i])
			return i;
		j++;
	}
	return 0;
}

unsigned LastPos(string1 s1, string1 s2)
{
     int l1=s1.n;
     int l2=s2.n;
     int i;
     if (l1-l2 < 0)
     {
//         SrtError = OUT;
         printf("Dlina podstroki bolshe dlini stroki!");
         return 0;
     }
     else
     {
         for(i=l1-l2;i>=0;i--)
            {
                int j=0;
                for(;j<l2;j++)
                    if(s1.st[i+j]!=s2.st[j])
                         break;
                if(j==l2)
                    return i+1;
     }
     return 0;
     }
}




