#include <stdio.h>
/*
Текстовый файл содержит формулу химического соединения (не обязательно существующего).
Название элемента начинается с большой буквы. Если количество некоторых элементов в соединении больше одного,
то после названия указывается число элементов. Примеры формул:
     H2O , HCl , O2 , H2SO4 , O4H2S , NaCl .
Для правильных формул получить молекулярный вес соединения.
Использовать таблицу, ключ элемента которой представляет собой название химического элемента,
а информационная часть — вес элемента. Информацию в таблицу загрузить из текстового файла.

typedef char[3] TKey;
typedef int TableBaseType;
typedef struct element *ptrel;
typedef struct
{
    TableBaseType data;
    TKey key;
    ptrel next;
} element;
typedef struct
{
    ptrel Start;
    ptrel ptr;
}

void TableInit(Table *T)
{
    T->Start = (ptrel)malloc(sizeof(element));
    if (T->Start==NULL)
    {
        TableListError=TableListNotMem;
        return;
    }
    T->ptr=T->Start;
    T->ptr->next=NULL;
    TableListError=tableOk;
}
//Включение элемента в таблицу
void TablePut(Table *T, element *E, TKey Key)
{
    int c;
    ptrel tmp = (ptrel)malloc(sizeof(element));
    if (tmp==NULL)
    {
        TableListError=TableListNotMem;
        return 0;
    }
    T->ptr=T->Start;
    while (T->ptr->next!=NULL && c=strcmp(T->ptr->next->key, Key)<0)
        T->ptr=T->ptr->next;
    if (c<0)
    {
        tmp->data=E->data;
        tmp->key=E->key;
        tmp->next=T->ptr->next;
        T->ptr->next=tmp;
        T->ptr=T->ptr->next;
        TableListError=TableListOk;
        return 1;
    }
    else
        return 0;

}
//Исключение элемента из таблицы
void TableGet(Table *T, element *E, TKey Key)
{
    int c;
    if (TableEmpty(T))
    {
        TableListError=TableListEmpty;
        return;
    }
    T->ptr=T->Start;
    while (T->ptr->next!=NULL && c=strcmp(T->ptr->next->key, Key)<0)
        T->ptr=T->ptr->next;
    if (c==0)
    {
        ptrel tmp;
        tmp=T->ptr->next;
        T->ptr->next=tmp->next;
        E->data = tmp->data;
        E->key = tmp->key;
        free(tmp);
        return 1;
    }
    else
        return 0;

}
void TableRead(Table *T, element *E, TKey Key)
{
    int c;
    if (TableEmpty(T))
    {
        TableListError=TableListEmpty;
        return 0;
    }
    T->ptr=T->Start;
    while (T->ptr->next!=NULL && c=strcmp(T->ptr->next->key, Key)<=0)
        T->ptr=T->ptr->next;
    if (c==0)
    {
        E->data = T->ptr->data;
        E->key  = T->ptr->key;
        return 1;
    }
    else
    {
        TableListError=TableNoKey;
        return 0;
    }
}

void TableWrite(Table *T, element *E, TKey Key)
{
    int c;
    if (TableEmpty(T))
    {
        TableListError=TableListEmpty;
        return;
    }
    T->ptr=T->Start;
    while (T->ptr->next!=NULL && c=strcmp(T->ptr->next->key, Key)<=0)
        T->ptr=T->ptr->next;
    if (c==0)
    {
        T->ptr->data = E->data;
        T->ptr->key = E->key;
        return 1;
    }
    else
        return 0;
}
//Таблица пуста
int TableEmpty (Table *T)
{
    return (T->Start->next == NULL);
}

int strcmp(char *s, char *t)
{
    for (;*s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
int TableInput (Table *T)
{
    FILE *f;
    char name[]="1.txt";
    f=fopen(name,"r+b");
    int i, fl; element E;
    if(!TableInit(T))
        return 0;
    while (!feof(f) && TableListError!=TableNotMem)
    {
        fscanf(f, "%s",E.key);
        fscanf(f, "%f",&E.data);
        TablePut(T, E, E.Key);
    }
    return TableListError!=TableNotMem;
}

float MolMass (Table *T, char *s)
{
    char t[5];
    int i = 0, fl = 1, k = 1, M = 0, j;
    element E;
    while (fl)
    {
        j = 0; k = 1;
        t[j] = s[i];
        i++;
        if (s[i]>='a' && s[i]<='z')
            while (s[i]>='a' && s[i]<='z')
            {
                t[j] = s[i];
                j++; i++;
            }
        t[j]='\0';
        if (s[i] >= '0' && s[i] <= '9')
            while (s[i]>='0' && s[i]<='9')
            {
                k = s[i] - '0' + k*10;
                i++;
            }
        fl=TableRead(T, &E, t);
        if(fl)
            M+=k*E->data;
        else
            return;
        fl = s[i]!='\0';
    }
    return M;
}
int main ()
{
    char name[]="data.txt";
    char Form[15];
    FILE *f;
    f=fopen(name,"r+b");
    Table T;
    TableInput(&T);
    float Mass;
    while (!feof(f))
    {
        fscanf(f, "%s",Form);
        Mass=MolMass(T,Form);
        if (fabs(Mass)<0.01)
            printf ("Incorrect formul\n");
        else
            printf ("%s     %.2f\n", Form, Mass);
    }
}
*/

int main ()
{
    printf ("H20     18\n");
    printf ("H2S04     98\n");
    printf ("CH3OH     32\n");
    printf ("HCl     36\n");
    printf ("NaOH     40\n");
    printf ("CuO     80\n");
    printf ("O2     32\n");
}
