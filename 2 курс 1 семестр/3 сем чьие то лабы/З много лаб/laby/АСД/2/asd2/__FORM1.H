#ifndef __FORM1_H_INCLUDED
#define __FORM1_H_INCLUDED
typedef char string1[256];
// ������� ����� ������ - ������ '\0'

int StrErr=0;
//������ ������ � ������ st �� ������ s. ������ s ������������� ������� �������� '\0'.
void WriteToStr(string1 st, char *s)
{
    while (*st++ = *s++);
}
//������ ������ � ������ s �� ������ st. ������ s ������������� ������� �������� '\0'.
void WriteFromStr(char *s, string1 st)
{
    while (*s++ = *st++);
}

//���� ������ s � ����������.
void InputStr(string1 s)
{
    gets(s);
}

//����� ������ s �� ����� ��������.
void OutputStr(string1 s)
{
    puts(s);
}
// ���������� ������ s1 � s2. ���������� 0 ���� s1 = s2; 1, ���� s1 > s2; -1, ���� s1 < s2.
int Comp(string1 s1, string1 s2)
{
    for (;*s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

//������� Count �������� �� ������ s, ������� � ������� Index.
void Delete(string1 s, unsigned Index, unsigned Count)
{
    int i;
    if (i+Count>Length(s))
    {
        StrErr=1;
        StErr();
    }

    for (i=Index;s[i];i++)
        s[i]=s[i+Count];
}
//��������� ��������� SubS � ������ s, ������� � �������  Index.
void Insert(string1 Subs, string1 s, unsigned Index)
{
    unsigned i,j,l1,l2;
    l1=Length(s);
    l2=Length(Subs);
    if (l1<l2+Index-1)
    {
        StrErr=2;
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

//��������� ������������ ����� s1 � s2. ��������� �������� � srez.
void Concat(string1 s1, string1 s2, string1 srez)
{
    if (Length(s1)+Length>255)
    {
        StrErr=3;
        StErr();
    }
    while (*srez++ = *s1++);
    *srez--;
    while (*srez++ = *s2++);
}

//���������� Count �������� � ������ Subs �� ������ s, ������� � ������� Index.
void Copy(string1 s, unsigned Index, unsigned Count, string1 Subs)
{
    int i,l,j;
    if (Index+Count<255)
    {
        StrErr=4;
        StErr();
    }
    for (i=Index,j=0;i<=Count;i++,j++)
        Subs[i]=s[j];

}

//���������� ������� ����� ������ S
int Length(string1 s)
{
    int i=0;
    while (s[i])
        i++;
    return i;
}

//���������� �������, ������� � ������� � ������ s ������������� ���-������ SubS.
unsigned Pos(string1 SubS, string1 s)
{
    int i=0,j=0,k,fl=1;
    while (s[i])
    {
        while (s[i]!=SubS[j])
            i++;
        if (!s[i] || i+Length(SubS)<255)
        {
            StrErr=1;
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


#endif // __FORM1_H_INCLUDED
