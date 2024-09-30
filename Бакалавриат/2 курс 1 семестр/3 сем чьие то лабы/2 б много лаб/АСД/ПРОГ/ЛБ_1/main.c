#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void PrintByte (unsigned char a)
{
   unsigned int m = 128;
   char i;
   unsigned char t = a;
   for (i=0; i<8; i++)
   {
       printf("%d", (t&m)?1:0);
       t<<=1;
   }
   printf(" ");
}

void PrintVar(void *a, unsigned int size)
{
    char i, j;
    unsigned char *bit = (unsigned char*)a;
    for (i=size-1; i>=0; i--) PrintByte(bit[i]);
    printf("\n");
    bit = NULL;
}


int conv_i (char *s)
{
    char len = strlen(s);
    char size = len/8;
    char a[size];
    int* b;
    int mask=1, i=0, j=0, st=0;
    for(i=size-1; i>=0; i--)
    {
        for(j=0; j<8; j++)
        {
            a[i]<<=1;
            if (s[st++]=='1')
                a[i]|=mask;
        }
    }
    b = (int*)a;
    return *b;
}

float conv_f(char *s)
{
    char len = strlen(s);
    char size = len/8;
    char a[size];
    float* b;
    int mask=1, i=0, j=0, st=0;
    for(i=size-1; i>=0; i--)
    {
        for(j=0; j<8; j++)
        {
            a[i]<<=1;
            if (s[st++]=='1')
                a[i]|=mask;
        }
    }
    b = (float*)a;
    return *b;
}



void main()
{
    char *s1 = "000000000000000000001111";
    char *s2 = "11000001101111100000000000000000";

   // char* s3;
   // scanf("%s", &s3);

    printf ("%i\n", conv_i(s1));
    printf ("%.4f\n", conv_f(s2));
  //  printf ("%.4f\n", conv_f(s3));
}







