#include <stdio.h>
#include <stdlib.h>
char flow[10000];
int main()
{
    int i=0, k=0, whs=0, j=0;
    char *s, t, name[20];
    FILE *f;
    s=(char *) malloc((1000) * sizeof(char));
    printf("Input filename:\n");
    scanf("%s",name);
    f=fopen(name,"r");
    while(!feof(f))
    {
        fscanf(f,"%c",&t);
        s[i]=t;
        i++;
        k++;
    }
    fclose(f);
    s=realloc(s,k*sizeof(char));
    s[k-1]='\0';
    printf("\n%s\n",s);
    for (j = 0; s[j] != '\0'; j++)
    {
        if (s[j] == '>')
            i++;
        else if (s[j] == '<')
            i--;
        else if (s[j] == '+')
            flow[i]++;
        else if (s[j] == '-')
            flow[i]--;
        else if (s[j] == '.')
            printf("%c", flow[i]);
        else if (s[j] == ',')
            flow[i] = getchar();
        else if (s[j] == '[')
            if (flow[i] == 0)
            {
                whs++;
                while (whs > 0)
                {
                    j++;
                    if (s[j] == '[')
                        whs++;
                    if (s[j] == ']')
                        whs--;
                }
            }
            else
                continue;
        else if (s[j] == ']')
            if (flow[i] == 0)
                continue;
            else
            {
                if (s[j] == ']')
                    whs++;
                while(whs > 0)
                {
                    j--;
                    if (s[j] == '[')
                        whs--;
                    if (s[j] == ']')
                        whs++;
                }
                j--;
            }
    }
    return 0;
}
