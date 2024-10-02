#include <stdio.h>
#include <stdlib.h>
#define N 10
#include <locale.h>

void new_matr33 (char a[N][N])
{
    int i=0, j=0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (i=j) a[i][j]=1;
        }

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if ((i+j)%2!=0) a[i][j]=1;
        }
}

void new_matrABC (char a[N][N], char b[N][N], char c[N][N])
// создание матриц A, B, C
{
    int i=0, j=0;

    for (i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            if ((i+j>8)&&((i+j)%2==0))
                a[i][j]=1;
            else
                a[i][j]=0;
        }

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (((2*j)+i) > 20)
                b[i][j]=1;
            else
                b[i][j]=0;
        }

     for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if ((i==1)||(i==2)||(i==4)||(i==8))
            {
                if ((j==3)||(j==5)||(j==7)||(j==10))
                    c[i][j]=1;
            }
        }
}

void null_matr (char s[N][N])
{
    int i=0, j=0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            s[i][j]=0;
}

void output_matr(char a[N][N])
// вывод матрицы
{
    int i, j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

char raven (char a[N][N], char b[N][N])
//равенство отношений
{
    size_t i=0,j=0;
    char f=1;
    while(i<N && f)
    {
        j=1;
        while(j<N && f)
        {
            f=a[i][j]==b[i][j];
            j++;
        }
        i++;
    }
    return f;
}

char vkl (char a[N][N], char b[N][N])
//равенство отношений
{
    size_t i=0,j=0;
    char f=1;
    while(i<N && f)
    {
        j=1;
        while(j<N && f)
        {
            f=a[i][j]<=b[i][j];
            j++;
        }
        i++;
    }
    return f;
}

void obed (char a[N][N], char b[N][N], char c[N][N])
// объединение
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            c[i][j]=(a[i][j]+b[i][j]);
}

void peres (char a[N][N], char b[N][N], char c[N][N])
// пересечение
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            c[i][j]=(a[i][j]*b[i][j]);
}

void razn (char a[N][N], char b[N][N], char c[N][N])
// разность
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            c[i][j]=(a[i][j]>b[i][j]);
}

void simrazn (char a[N][N], char b[N][N], char c[N][N])
// разность
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            c[i][j]=(a[i][j]!=b[i][j]);
}

void dop (char a[N][N], char c[N][N])
// дополнение
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            c[i][j]=(1-a[i][j]);
}

void obrash (char a[N][N], char c[N][N])
//обращение -1
{
    size_t i=0, j=0;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++) c[i][j]=a[j][i];
}

void kompoz (char a[N][N], char b[N][N], char c[N][N])
// композиция
{
    size_t i=0, j=0, k=0;
    char f=1;
     for (i=0;i<N;i++)
        for (j=0;j<N;j++)
        {
            c[i][j] = 0;
            for (k=0; k<N; k++)
            {
                c[i][j]=(c[i][j]+a[i][j]*b[i][j]);
            }
        }
}

void kompoz2 (char a[N][N], char b[N][N], char c[N][N])
// композиция
{
    size_t i=0, j=0, k=0;
    char f=1;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            c[i][j] = 0;
            k = 0;
            while (c[i][j]==0 && k<N)
            {
                c[i][j]=(c[i][j]+a[i][j]*b[i][j]);
                k++;
            }
        }
}

int refl(char a[N][N], int v)
{
    int i=0;
    for (i=0; i<N; i++)
    {
        if (a[i][i]==0)
        {
            if (v)
                printf("Не рефлексивно, так как (%d,%d) не принадлежит отношению\n",i+1,i+1);
            return 0;
        }
    }
    if (v)
        printf("Рефлексивно\n");
    return 1;
}

int anti_refl(char a[N][N], int v)
{
    int i=0;
    for (i=0; i<N; i++)
    {
        if (a[i][i]==1)
        {
            if (v)
                printf("Не антирефлексивно, так как (%d,%d) не принадлежит отношению\n",i+1,i+1);
            return 0;
        }
    }
    if (v)
        printf("Антирефлексивно\n");
    return 1;
}

int simmetr (char a[N][N], int v)
{
    int i=0, j=0;;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (a[i][j]!=a[j][i])
            {
                if (v)
                    printf("Не симметрично, так как из %dR%d не следует %dR%d\n",i+1,j+1,j+1,i+1);
                return 0;
            }
        }
    if (v)
        printf("Симметрично\n");
    return 1;
}

int anti_simmetr (char a[N][N], int v)
{
    int i=0, j=0;;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (a[i][j]==a[j][i])
            {
                if (v)
                    printf("Не антисимметрично, так как из %dR%d следует %dR%d\n",i+1,j+1,j+1,i+1);
                return 0;
            }
        }
    if (v)
        printf("Антимметрично\n");
    return 1;
}

int polnoe (char a[N][N], int v)
{
    int i, j;
	for (i=0; i<N; i++)
	  for(j=0; j<N; j++)
      {
          if (a[i][j]||a[j][i]!=1)
          {
              if (v)
                printf("Не полное\n",i+1,j+1);
              return 0;
          }
      }
    if (v)
        printf("Полное\n");
    return 1;
}

int tranzit (char a[N][N], int v)
{
    int i, j, k;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (a[i][j]==0)
                for (k=0; k<N; k++)
                {
//                    if (a[i][k]&&a[k][j])
                    if ((a[i][k]==1)&&(a[k][j]==1))
                    {
                        if (v)
                            printf("Не транзитивно, так как из %dR%d и %dR%d не следует %dR%d\n",i+1,k+1,k+1,j+1,i+1,j+1);
                        return 0;
                    }
                }
        }
    if (v)
        printf("Транзитивно\n");
    return 1;
 /*   int f=1;
    size_t i=0,j,z;

    while((i<N)&&f)
    {
        j=0;
        while((j<N)&&f)
        {
            z=0;
            while((z<N)&&f)
            {
                if((a[i][z]==1)&&(a[z][j]==1)) f=a[i][j];
                z++;
            }
            j++;
        }
        i++;
    }

    if(f) printf("transit\n");
        else printf("not transit:(a[%i][%i]=%i a[%i][%i]=%i) ==> a[%i][%i]=%i\n",i,z,a[i-1][z-1],z,j,a[z-1][j-1],i,j,f);

    return f;*/
}

int anti_tranzit (char a[N][N], int v)
{
    int i, j, k;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
        {
            if (a[i][j]==1)
                for (k=0; k<N; k++)
                {
                    if (a[i][k]&&a[k][j])
                    {
                        if (v)
                            printf("Не антитранзитивно, так как из %dR%d и %dR%d следует %dR%d\n",i+1,k+1,k+1,j+1,i+1,j+1);
                        return 0;
                    }
                }
        }
    if (v)
        printf("Антитранзитивно\n");
    return 1;
   /* int i, j, z, f=0;

    for(i=0;(i<N)&&!f;i++)
        for(j=0;(j<N)&&!f;j++)
            for(z=0;(z<N)&&!f;z++)
                if((a[i][z]==1)&&(a[z][j]==1)) f=a[i][j];

    if(!f) printf("antitransit\n");
        else printf("not antitransit:(a[%i][%i]=%i a[%i][%i]=%i) ==> a[%i][%i]=%i\n",i,z,a[i-1][z-1],z,j,a[z-1][j-1],i,j,f);

    return !f;*/
}

int tolerant (char a[N][N])
{
    int f1 = refl(a, 0);
    int f2 = simmetr(a, 0);
    return f1*f2;
}

int eqviv (char a[N][N])
{
    int f1 = tolerant(a);
    int f2 = tranzit(a, 0);
    return f1*f2;
}

int poryadka (char a[N][N])
{
    int f1 = anti_tranzit(a, 0);
    int f2 = tranzit(a, 0);
    return f1*f2;
}

int nestr_por (char a[N][N])
{
    int f1 = poryadka(a);
    int f2 = refl(a, 0);
    return f1*f2;
}

int strog_por (char a[N][N])
{
    int f1 =  poryadka(a);
    int f2 = anti_refl(a, 0);
    return f1*f2;
}
 int lin_por (char a[N][N])
 {
     int f1 = poryadka(a);
     int f2 = polnoe(a, 0);
     return f1*f2;
 }

int nestr_lin_por (char a[N][N])
{
    int f1 = nestr_por(a);
    int f2 = polnoe(a, 0);
    return f1*f2;
}

int str_lin_por (char a[N][N])
{
    int f1 = strog_por(a);
    int f2 = polnoe(a, 0);
    return f1*f2;
}

// генерация
void generation (int a[N][N], unsigned count1,int n)
{
    srand( n );
    unsigned i,j,k;
    for ( k=0;k<count1;++k)
     {
        do
        {
          i=rand()%N;
          j=rand()%N;
        }
        while (a[i][j]);
        a[i][j]=1;
     }
}

void output_mass(int a[N])
{
    int i;
    for(i=0; i<N; i++)
        printf("%d ", a[i]);
}

void init_mn(int a[N]){
	int i;
	for(i=0;i<N;i++)
	  a[i]=1;
}

int sr_mn(int* a,int* b){
	int i;
	for(i=0;i<N;i++)
	 if (a[i]!=b[i]) return(0);
    return(1);
}

void Pos_Kl_Ek(int a[N][N],int x, int b[N]){
	b[x]=1;
	int i;
	for( i=0;i<N;i++)
	  if(a[x-1][i]) b[i+1]=1;
}


void Rasb(int a[N][N])
{
	int b[N][N], s[N],k,f,i,j ;
	Pos_Kl_Ek(a,1,b[0]);
	k=1;
	for(i=0;i<10;i++)
    {
	   f=1;
       Pos_Kl_Ek(a,i,b[k]);
       for(j=0;j<=k&&f;j++) f=sr_mn(b[k],b[j]);
       if (!f) k++;
	}
	output_mass(b);
}



int main()
{
    setlocale(LC_ALL, "Rus");
    int a[N][N];

    null_matr(a);
    new_matr33(a);

    Rasb(a);

    output_matr(a);

}












































