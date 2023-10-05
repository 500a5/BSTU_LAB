#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

char *s = "+ * 2 4 * 3 5";

int isOperation(char c)
{
    return (c == '/' || c == '+' || c == '-' || c == '*');
}

int isDigit(char c)
{
    return (c >= '0'&& c <= '9');
}

void BuildTree(Tree *T)
{
    Tree *TS;
    int k;
    if (*s != '\0')
    {
        if (*s == ' ')
            s++;
        if (isOperation(*s))
        {
            WriteDataTree(T,*s);
            s++;
            CreateRoot(&TS);
            k = *T;
            MemTree[k].LSon = TS;
            MoveToLSon(T, &TS);
            BuildTree(&TS);
            CreateRoot(&TS);
            k = *T;
            MemTree[k].RSon = TS;
            MoveToRSon(T, &TS);
            BuildTree(&TS);
        }
        if (isDigit(*s))
        {
            WriteDataTree(T,*s - '0');
            s++;
        }
    }
}

void WritePostfix(Tree *T)
{
    Tree *TS;
    if (IsLSon(T))
    {
        MoveToLSon(T,&TS);
        WritePostfix(&TS);
    }
    if (IsRSon(T))
    {
        MoveToRSon(T,&TS);
        WritePostfix(&TS);
    }
    char c;
    ReadDataTree(T, &c);
    if (isDigit(c + '0'))
        c = c + '0';
    printf("%c ",c);
}

int WriteCalc(Tree *T)
{

    Tree *TS;
    int op1,op2,res;
    char c;
    if (IsLSon(T))
    {
        MoveToLSon(T,&TS);
        op1 = WriteCalc(&TS);
    }
    if (IsRSon(T))
    {
        MoveToRSon(T,&TS);
        op2 = WriteCalc(&TS);
        ReadDataTree(T, &c);
        switch (c)
        {
            case '*' :
                res = op1 * op2;
                break;
            case '/' :
                res = op1 / op2;
                break;
            case '+' :
                res = op1 + op2;
                break;
            case '-' :
                res = op1 - op2;
                break;
        }
        printf("%i %c %i = %i\n", op1, c, op2, res);
    }
    ReadDataTree(T, &c);
    if (isOperation(c))
        return res;
    else
        return c;
}

int main()
{
    Tree *T;
    InitTree(&T);
    CreateRoot(&T);
    printf("%s\n\n",s);
    BuildTree(&T);
    WritePostfix(&T);
    puts("\n");
    WriteCalc(&T);
}
