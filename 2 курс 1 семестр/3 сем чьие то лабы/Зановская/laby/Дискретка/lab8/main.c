#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void Vivod(int *A,int n)
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
            if(*(A+i*n+j)>9)
                printf("%d  ",*(A+i*n+j));
            else printf("%d   ",*(A+i*n+j));
        printf("\n");
    }
    printf("\n");
}

void Sort(int *A, int N)
{
    int t,i,j;
    for(i=0; i<N-1; i++)
        for(j=i+1; j<N; j++)
            if(*(A+2*N+i)>*(A+2*N+j))
            {
                t=*(A+i);
                *(A+i)=*(A+j);
                *(A+j)=t;
                t=*(A+N+i);
                *(A+N+i)=*(A+N+j);
                *(A+N+j)=t;
                t=*(A+2*N+i);
                *(A+2*N+i)=*(A+2*N+j);
                *(A+2*N+j)=t;
            }

}

void Kras(int *A,int n,int N,int *B)
{
    int i,k=0,k1=0,t;
    int C[n];
    for(i=0; i<n; i++)
        C[i]=i+1;
    for(i=0; i<N; i++)
    {
        if(*(A+i)!=0&&C[*(A+i)-1]!=C[*(A+N+i)-1])
        {
            if (C[*(A+i)-1]<C[*(A+N+i)-1])
            {
                *(B+k1)=*(A+i);
                *(B+N+k1)=*(A+N+i);
                *(B+2*N+k1)=*(A+2*N+i);
                k1++;
                t=C[*(A+N+i)-1];
                for(k=0; k<n; k++)
                    if (C[k]==t)
                        C[k]=C[*(A+i)-1];
            }
            else
            {
                *(B+k1)=*(A+i);
                *(B+N+k1)=*(A+N+i);
                *(B+2*N+k1)=*(A+2*N+i);
                k1++;
                t=C[*(A+i)-1];
                for(k=0; k<n; k++)
                    if (C[k]==t)
                        C[k]=C[*(A+N+i)-1];
            }

        }
    }
}

void obn2(int *A,int N)
{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            *(A+i*N+j)=0;
    }
}

void Kras1(int *A,int n,int N,int *B)
{
    int i,k=0,k1=0,t,f=1,min,minInd=0;
    int C[n];
    for(i=0; i<n; i++)
        C[i]=i+1;
    int V[n][n];
    obn2(&V[0][0],n);

    while(f)
    {
        min=10000;
        for(i=0;i<N;i++)
            if(*(A+2*N+i)<=min&&!V[*(A+i)-1][*(A+N+i)-1])
        {
            minInd=i;
            min=*(A+2*N+i);
        }


        V[*(A+minInd)-1][*(A+N+minInd)-1]=V[*(A+N+minInd)-1][*(A+minInd)-1]=1;

        if(*(A+minInd)!=0&&C[*(A+minInd)-1]!=C[*(A+N+minInd)-1])
        {
            if (C[*(A+minInd)-1]<C[*(A+N+minInd)-1])
            {
                *(B+k1)=*(A+minInd);
                *(B+N+k1)=*(A+N+minInd);
                *(B+2*N+k1)=*(A+2*N+minInd);
                k1++;
                t=C[*(A+N+minInd)-1];
                for(k=0; k<n; k++)
                    if (C[k]==t)
                        C[k]=C[*(A+minInd)-1];
            }
            else
            {
                *(B+k1)=*(A+minInd);
                *(B+N+k1)=*(A+N+minInd);
                *(B+2*N+k1)=*(A+2*N+minInd);
                k1++;
                t=C[*(A+minInd)-1];
                for(k=0; k<n; k++)
                    if (C[k]==t)
                        C[k]=C[*(A+N+minInd)-1];
            }
        }
        f=0;
        k=1;
        for(i=0;i<n&&!f;i++)
            if (C[i]>k) f=1;
    }
}

void prim(int *A,int n,int N,int *B){
    int i,k=0,k1=0,t,y,j;
    int C[n];
    int T[n],D[n];
    for(i=0; i<n; i++){
        C[i]=0;
        T[i]=0;
        D[i]=100000;
    }
     C[0]=y=1;

     for(i=1;i<=n;i++)
       for(j=0;j<N;j++)
         if(C[i-1]!=1&&(i==*(A+j)||(i==*(A+N+j))&&(y==*(A+j)||y==*(A+N+j))))
           if(i==*(A+j));
//              D[]
}

void obn1(int *A, int *B,int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        B[i]=N-1;
        for(j=0; j<N; j++)
            if(i!=j)
            *(A+i*N+j)=1;
           else
            *(A+i*N+j)=0;
    }
}

void obn_r(int *A,int N)
{
    int i,j;
    for(i=0; i<3; i++)
        for(j=0; j<N; j++)
            *(A+i*N+j)=0;
}

void rand_r(int *R, int N,int m)
{
    int A[N][N];
    int B[N];
    obn1(&A[0][0],B,N);
    int k=(N*(N-1))/2,i,j;
    srand(time(NULL)+rand());
    while(k>m)
    {
        i = rand()%(N);
        j = rand()%(N);
        if(A[i][j]&&(i!=j)&&(B[i]>1)&&(B[j]>1))
        {
            A[i][j]=A[j][i]=0;
            k--;
            B[i]--;
            B[j]--;
        }
    }
    k=0;

    for(i=0;i<N;i++)
        for(j=0;j<=i;j++)
          if(A[i][j]){
            *(R+k)=i+1;
            *(R+m+k)=j+1;
            *(R+2*m+k)=1+rand()%40;
            k++;
          }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int R[3][10];
    int R1[3][10];
    rand_r(&R[0][0],5,10);
    Vivod(&R[0][0],10);
    obn_r(&R1[0][0],10);
    Kras1(&R[0][0],5,10,&R1[0][0]);
    Vivod(&R1[0][0],10);
    Sort(&R[0][0],10);
    Vivod(&R[0][0],10);
    obn_r(&R1[0][0],10);
    Kras(&R[0][0],5,10,&R1[0][0]);
    Vivod(&R1[0][0],10);


    return 0;
}
