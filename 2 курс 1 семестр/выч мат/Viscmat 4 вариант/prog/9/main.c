#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GetMemMatr (float ***a, size_t); //��������� ������ ������ �� ������� ��� ������ ��������
void InputMatr (float **a, size_t); //���� ������ ������� ��� ������ ��������
void GetMemMass (float **a, size_t n); //��������� ������ �� ������
int CountZpFile (char *f_name); //���-�� ����
void InputFileMatr (float **a, size_t n, char* f_name); //���� �� �����
void OutputMatr (float **a, size_t n); //����� �������
void OutputMass (float *a, size_t n); //����� �������
void InputMass (float *a, size_t n); //���� �������
void OutputMatrAndMass (float **a, float *b, size_t n); //��������� ����� ������ � ������� ����
int CheckDiag (float** a, size_t n); //�������� ������������ ������������?
void FormResh (float **a, float *h, float **b, float *c, size_t n); //����������� ������� C � ������� B
float NormVecOne (float *a, size_t n); //����� ������� 1
float NormVecBesk (float *a, size_t n); //����� ������� ����
float NormMatrOne (float **a, size_t n); //1 ����� �������
float NormMatrBesk (float **a, size_t n); //����������� ����� �������
int ApriorK (float **b, float *c, size_t n, float e); //��������� ������
void MultMatrVec (float **a, float *b, float *c, size_t n); //��������� ������� �� �������
void SummVect (float *a, float *b, float *c, size_t n);
void RuznVect (float *a, float *b, float *c, size_t n);
void CopyVect (float *a, float *b, size_t n);
int MethIt (float **b, float *c, float *x0, size_t n, float e);

int main()
{
    int n;
    char f_name [10] ="K1.txt";
    n = CountZpFile(f_name); //���������� ������� � �����

    float **a, *x0, *h; //�������� � �������� ������
    GetMemMatr(&a, n);
    GetMemMass(&x0, n);
    GetMemMass(&h, n);

    InputFileMatr(a, n, f_name); //������� ������� �� �����, �� �x=h
    h[0] = 7.2, h[1] = -4.7, h[2] = 8.5;
    printf("System: \n");
    OutputMatrAndMass(a, h, n); //����� �� ����� "������� ���������"

    float **b, *c; //�������� � �������� ������, ��� x = Bx+C
    GetMemMass(&c, n);
    GetMemMatr(&b, n);

    FormResh(a, h, b, c, n); //���������� ������� b � ������� ���������� � c cnjk,wf
    printf("\nB and C: \n");
    OutputMatrAndMass(b, c, n);

    //����������� ����� ������� c � ������� b
    float cnb = NormVecBesk(c, n), bnb = NormMatrBesk(b, n);
    printf("\nNorm C besk = %.2f\n", cnb);
    printf("Norm B besk = %.2f\n", bnb);

    float eps = 0.1;
    //������ �����:
    int k = ApriorK(b, c, n, eps), k2 = MethIt(b, c, x0, n, eps);
    printf("\nAprior k = %d\n", k); //��������� ������
    printf("It k = %d\n\n", k2); //���������� ����� ��������

    //����� �������
    OutputMass(x0, n);
    return 0;
}

void GetMemMatr (float ***a, size_t n)
{
    int i;
    (*a) = (int**)calloc(n, sizeof(float*));
    for (i=0; i<n; i++)
        (*a)[i]=(int*)calloc(n, sizeof(float*));
}

void GetMemMass (float **a, size_t n)
{
    (*a) = (int**)calloc(n, sizeof(float*));
}

void InputMatr (float **a, size_t n)
{
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%f", &a[i][j]);
}

void InputFileMatr (float **a, size_t n, char* f_name)//���� ������� ����� t ������� n �� ����� f_name.
{
    FILE *F = fopen(f_name, "r");
    int i, j;
    for (i=0; i<n; i++)
       for (j=0; j<n; j++)
            fscanf(F, "%f", &a[i][j]);
    fclose(F);
}

int CountZpFile (char *f_name)//���������� ���������� ������� ����� f_name.
{
    char ch;
    int i, kol=0;
    FILE *F = fopen(f_name, "r");
    while (!feof(F))
    {
        ch=fgetc(F);
        if (ch=='\n')
            kol++;
    }
    fseek(F, 0, SEEK_SET);
    fclose(F);
    return kol;
}

void OutputMatr (float **a, size_t n)
{
    int i, j;
    for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                printf("%.2f ", a[i][j]);
            }
            printf("\n");
        }
}

void OutputMass (float *a, size_t n)
{
    int i;
    for (i=0; i<n ; i++)
        printf("%.2f\t", a[i]);
}

void InputMass (float *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        scanf("%f", &a[i]);
}

void OutputMatrAndMass (float **a, float *b, size_t n)
{
    int i, j;
   // printf("x\ty\tz\t\n");
    for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                printf("%.2f\t", a[i][j]);
            }
            printf(" = %.2f ", b[i]);
            printf("\n");
        }
}

int CheckDiag (float** a, size_t n)
{
    int i, j, f=1, s;
    for (i=0; i<n && f; i++)
    {
        s = 0;
        for (j=0; j<n; j++)
           if (i!=j)
             s+=fabs(a[i][j]);
        f=fabs(a[i][i])>s;
    }
    return i==n;
}

void FormResh (float **a, float *h, float **b, float *c, size_t n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
       for (j=0; j<n; j++)
    {
        if (i != j)
           b[i][j] = (-a[i][j])/a[i][i];
        else
        {
            b[i][j] = 0;
            c[i] = h[i] / a[i][j];
        }
     }
   }
}

float NormVecOne (float *a, size_t n)
{
    int i;
    float sum = 0;
    for (i=0; i<n; i++)
        sum += fabs(a[i]);
    return sum;
}

float NormVecBesk (float *a, size_t n)
{
    int i;
    float max = -1;
    for (i=0; i<n; i++)
        if (fabs(a[i]) > max)
          max=fabs(a[i]);
    return max;
}

float NormMatrOne (float **a, size_t n)
{
    int i, j;
    float max = 0, sum = 0;
    for (i=0; i<n; i++)
        {
            sum = 0;
            for (j=0; j<n; j++)
               sum += fabs(a[j][i]);
            if (sum > max)
                max = sum;
        }
    return max;
}

float NormMatrBesk (float **a, size_t n)
{
    int i, j;
    float max = 0, sum;
    for (i=0; i<n; i++)
        {
            sum=0;
            for (j=0; j<n; j++)
               sum += fabs(a[i][j]);
            if (sum > max)
                max=sum;
        }
    return max;
}

int ApriorK (float **b, float *c, size_t n, float e)
{
    float Bnorm, Cnorm;
    Bnorm = NormMatrBesk(b, n);
    Cnorm = NormVecOne(c, n);
    float p = (log(e)-log(Cnorm)+log(1-Bnorm))/log(Bnorm);
    int k;
    for (k=0; k<p; k++);
    return k;
}

void MultMatrVec (float **a, float *b, float *c, size_t n)
{
    int i, j;
    for (i=0; i<n; i++)
        c[i]=0;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            c[i] += a[i][j]*b[j];
}

void SummVect (float *a, float *b, float *c, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        c[i] = a[i] + b[i];
}

void RuznVect (float *a, float *b, float *c, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        c[i] = a[i]-b[i];
}

void CopyVect (float *a, float *b, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        b[i] = a[i];
}

int MethIt (float **b, float *c, float *x0, size_t n, float e)
{
    int p;
    float e1;
    float *x1;
    GetMemMass(&x1, n);
    float *xtmp;
    GetMemMass(&xtmp, n);
    float Bnorm = NormMatrBesk(b, n);
    p = ApriorK (b, c, n, e);
    e1 = (1-Bnorm)*e / Bnorm;
    int k = 0;

    do //x(1) = B * x (0) + c
    {
      MultMatrVec (b, x0, xtmp, n);
      SummVect (xtmp, c, x1, n);
      RuznVect (x1, x0, xtmp, n);
      CopyVect(x1, x0, n);
      k++;
    }
    while ((k<=p)&&(NormVecBesk(xtmp,n)>e1));
    return k;
}





/*float t;
   for (i=0;i<n;i++)
   {
       t=0;
       for (j=0;j<n;j++)
        t+=A[i][j]*x0[j];
       printf("%f   ",t);
   }*/





