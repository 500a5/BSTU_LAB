#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "__FORM1.H"

//���������� ����� ��� ����� ������ s, ������� �� �o������ ������� �� ������ s1.
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
     switch (StrErr)
     {
         case 0: printf ("\n������ �� ���������\n");
                exit(StrErr);
         case 1: printf ("\n������ � ������� Delete\n");
                exit(StrErr);
         case 2: printf ("\n������ � ������� Insert\n");
                exit(StrErr);
         case 3: printf ("\n������ � ������� Concat\n");
                exit(StrErr);
         case 4: printf ("\n������ � ������� Copy\n");
                exit(StrErr);
         case 5: printf ("\n������ � ������� Pos\n");
                exit(StrErr);
     }
 }
