

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char *p;
void Interpret (char *com,int *i);
void main ()
{
    char acc[1000];
    char *cpu=calloc(3000,sizeof(char));
    p = cpu;
    gets(acc);
    int i,j=0;
    int brc = 0;
    for (i = 0; acc[i]; ++i) {
        if (acc[i] == '>')
            j++;
        if (acc[i] == '<')
            j--;
        if (acc[i] == '+')
            cpu[j]++;
        if (acc[i] == '-')
            cpu[j]--;
        if (acc[i] == '.')
             putchar(*p);
        if (acc[i] == ',')
             (*p)=getchar();
        if (acc[i] == '[') {
            if (!cpu[j]) {
                ++brc;
                while (brc) {
                    ++i;
                    if (acc[i] == '[')
                        ++brc;
                    if (acc[i] == ']')
                        --brc;
                }
            } else
                continue;
        } else if (acc[i] == ']') {
            if (!cpu[j])
                continue;
            else {
                if (acc[i] == ']')
                    brc++;
                while (brc) {
                    --i;
                    if (acc[i] == '[')
                        brc--;
                    if (acc[i] == ']')
                        brc++;
                }
                --i;
            }
        }
    }
    }

void Interpret (char *com,int *i)
{
    int j,k,brc;
    switch (com[*i])
    {
        case '+':
        {
                (*p)++;
                break;
            }
            case '-':
            {
                (*p)--;
                break;
            }
            case '>':
            {
                p++;
                break;
            }
            case '<':
            {
                p--;
                break;
            }
            case '.':
            {
                putchar(*p);
                break;
            }
            case ',':
            {
                (*p)=getchar();
                break;
            }
/*            case '[':
            {
                k=*i;
                k++;
                while(*p)
                {
                    for (j=k;com[j]!=']';j++)
                    {
                        Interpret (com,i);
                    }
                }
                break;
            }
            case ']':
            {
                printf ("\nError");
                return;
            }
        */
        case '[':
       {
            if (!(*p)) {
                ++brc;
                while (brc) {
                    ++(*i);
                    if (com[*i] == '[')
                        ++brc;
                    if (com[*i] == ']')
                        --brc;
                }
            } //else
//                continue;
            break;
        }
        case ']' :
        {
//            if (!(*p))
//                continue;
  //          else
  {
                if (*p == ']')
                    brc++;
                while (brc) {
                    --(*i);
                    if (*p == '[')
                        brc--;
                    if (*p == ']')
                        brc++;
                }
                --(*i);
    }
}
    }
}
