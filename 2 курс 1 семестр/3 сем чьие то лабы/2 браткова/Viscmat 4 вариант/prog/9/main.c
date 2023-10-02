#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GetMemMatr (float ***a, size_t); //выделение памяти только на матрицу без правых столбцов
void InputMatr (float **a, size_t); //ввод только матрицы без правых столбцов
void GetMemMass (float **a, size_t n); //выделение памяти на массив
int CountZpFile (char *f_name); //кол-во запи
void InputFileMatr (float **a, size_t n, char* f_name); //ввод из файла
void OutputMatr (float **a, size_t n); //вывод матрицы
void OutputMass (float *a, size_t n); //вывод массива
void InputMass (float *a, size_t n); //ввод массива
void OutputMatrAndMass (float **a, float *b, size_t n); //форматный вывод матицы и массива коэф
int CheckDiag (float** a, size_t n); //Обладает диагональным преобладаием?
void FormResh (float **a, float *h, float **b, float *c, size_t n); //определение вектора C и матрицы B
float NormVecOne (float *a, size_t n); //норма вектора 1
float NormVecBesk (float *a, size_t n); //норма вектора беск
float NormMatrOne (float **a, size_t n); //1 норма матрицы
float NormMatrBesk (float **a, size_t n); //бесконечная норма матрицы
int ApriorK (float **b, float *c, size_t n, float e); //априорная оценка
void MultMatrVec (float **a, float *b, float *c, size_t n); //умножение матрицы на вектора
void SummVect (float *a, float *b, float *c, size_t n);
void RuznVect (float *a, float *b, float *c, size_t n);
void CopyVect (float *a, float *b, size_t n);
int MethIt (float **b, float *c, float *x0, size_t n, float e);

int main()
{
    int n;
    char f_name [10] ="K1.txt";
    n = CountZpFile(f_name); //количество записей в файле

    float **a, *x0, *h; //объявили и выделили память
    GetMemMatr(&a, n);
    GetMemMass(&x0, n);
    GetMemMass(&h, n);

    InputFileMatr(a, n, f_name); //считали матрицу из файла, тк Аx=h
    h[0] = 7.2, h[1] = -4.7, h[2] = 8.5;
    printf("System: \n");
    OutputMatrAndMass(a, h, n); //вывод на экран "системы уравнений"

    float **b, *c; //объявили и выделили память, это x = Bx+C
    GetMemMass(&c, n);
    GetMemMatr(&b, n);

    FormResh(a, h, b, c, n); //нахождение матрицы b с нулевой диагональю и c cnjk,wf
    printf("\nB and C: \n");
    OutputMatrAndMass(b, c, n);

    //бесконечные нормы вектора c и матрицы b
    float cnb = NormVecBesk(c, n), bnb = NormMatrBesk(b, n);
    printf("\nNorm C besk = %.2f\n", cnb);
    printf("Norm B besk = %.2f\n", bnb);

    float eps = 0.1;
    //оценки шагов:
    int k = ApriorK(b, c, n, eps), k2 = MethIt(b, c, x0, n, eps);
    printf("\nAprior k = %d\n", k); //априорная оценка
    printf("It k = %d\n\n", k2); //фактческое число итераций

    //вывод решения
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

void InputFileMatr (float **a, size_t n, char* f_name)//Ввод массива точек t размера n из файла f_name.
{
    FILE *F = fopen(f_name, "r");
    int i, j;
    for (i=0; i<n; i++)
       for (j=0; j<n; j++)
            fscanf(F, "%f", &a[i][j]);
    fclose(F);
}

int CountZpFile (char *f_name)//Возвращает количество записей файла f_name.
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





