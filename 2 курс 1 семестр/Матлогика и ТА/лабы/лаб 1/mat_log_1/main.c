#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
const int N=100;
void input_knf (int a[][N], char* b, int m, int n)
{
    int i=0, j=0;
    printf( "������ ���ࠫ�: ");
    for(i = 0; i < n; i++)
        scanf("%s", &b[i]);
    printf( "���ࠫ ����: 1");
    printf( "\n���ࠫ c ���栭���: -1");
    printf("\n������⢨� ���ࠫ�: 0\n");
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf("%i",&a[i][j]);
}

void output_form (int a[][N], char* b, int m, int n)
{
    int i=0, j=0;
    for (i=0; i<m; i++)
    {
        printf( "(");
        j=0;
        while ((a[i][j]==0)&&(j<n))
            j++;
        if (j<n)
        {
            if (a[i][j]==-1)
                printf( "!%c",  b[j]);
            else
                printf("%c", b[j]);
        }
        j++;
        for (j; j<n; j++)
        {
            if (a[i][j]==-1)
                printf( "V!%c", b[j]);
            if (a[i][j]==1)
                printf( "V%c", b[j]);
        }
        printf( ")");
    }
    printf("\n");
}

void output_table(int a[][N], char *b, _Bool *fun, int m, int n)
{
    for(int i = 0; i < n; i++)
        printf("%c\t", b[i] );
    printf( "f\t\n");
    int all = pow(2,n);
    _Bool  mas[N] ;
    for(int i = 0; i < all; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mas[j] = (i >> (n-1-j)) & 1;
            printf( "%d\t", mas[j]  );
        }
        _Bool f = 1, x; // ���祭�� ᪮����-� f-����
        int j = 0, k;
        while(f && (j < m))
        {
            x = 0;
            k = 0;
            while(!x && (k < n))
            {
                if(a[j][k] == 1)
                    x |= mas[k];
                if(a[j][k] == -1)
                    x |= !mas[k];
                k++;
            }
            f &= x;
            j++;
        }
        fun[i]=f;
        printf(  "%d\t\n",f );
    }
}

void output_TF( char *b, _Bool* fun, int n)
{
    printf("������樨 �� ������ �㭪�� �ਭ����� ����� ���祭��\n");
    for(int i = 0; i < n; i++)
        printf("%c\t", b[i] );
    printf( "f\t\n" );
    int all = pow(2,n);
    _Bool mas [N];
    for(int i = 0; i < all; i++)
    {
        if (!fun[i])
        {
            for(int j = 0; j < n; j++)
            {
                mas[j] = (i >> (n-1-j)) & 1;
                printf("%i\t", mas[j] );
            }
            printf("%i\t\n", fun[i]);
        }
    }
}



int main()
{
    char i=0;
    printf( "������ ������⢮ ᪮���: ");
    int m; // ��ப
    scanf("%i", &m);
    printf( "������ ������⢮ ���ࠫ��: ");
    int n; //�⮫�殢
    scanf("%i", &n);
    int a [N][N];
    char name[N];
    _Bool fun [N]; //���ᨢ �㭪樨
    input_knf(a, name, m, n);
    output_form(a, name, m, n);
    output_table(a, name, fun, m, n);
    printf( "\n" );
    output_TF( name, fun, n);
    return 0;
}
