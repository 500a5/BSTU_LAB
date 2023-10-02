#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TInquiry
{
    char Name[10]; // ��� �������sdf
    unsigned Time1; // ����� ������������
    // unsigned Time2; // ����� ������������
    unsigned short int P; // ��������� 0 � ������, 1 � �������, 2 - ������
} TInquiry;

/****************************************************************************************************************/
#define SIZE_STACK_ARRAY 100
/*�������� �������������� ��������*/
const int okStackArray = 0;											// ��� ���������
const int fullStackArray = 1;										// ���� ����������
const int emptyStackArray = 2;										// ���� ����
/*********************************/
/*���������� ������*/
extern int errorStackArray;
/*������� ��� �����*/
typedef TInquiry stackArrayBaseType;
/*���������� �����*/
typedef struct {
stackArrayBaseType buf[SIZE_STACK_ARRAY];						// ����� �����
unsigned uk;													// ���������
} StackArray;

/*���������� ������*/
int errorStackArray;
/*������������� �����*/
void initStackArray(StackArray *S)
{
    S->uk = 0;
    errorStackArray = okStackArray;
}
/*��������� � ����*/
void putStackArray(StackArray *S, stackArrayBaseType E)
{
    /*���� ���� ����������*/
    if (isFullStackArray(S))
        return;
    /*�����*/
    S->buf[S->uk] = E;				// ��������� ��������
    S->uk++;							 	// ����� ���������
}
/*���������� �� �����*/
void getStackArray(StackArray *S, stackArrayBaseType *E)
{
    /*���� ���� ����*/
    if (isEmptyStackArray(S))
        return;
    /*�����*/
    *E = S->buf[S->uk - 1];		// ���������� �������� � ����������
    S->uk--;							 	// ����� ���������
}
/*��������: ����� �� ����*/
int isFullStackArray(StackArray *S)
{
    if (S->uk == SIZE_STACK_ARRAY)
        {
            errorStackArray = fullStackArray;
            return 1;
        }
    return 0;
}
/*��������: ���� �� ����*/
int isEmptyStackArray(StackArray *S)
{
    if (S->uk == 0)
        {
            errorStackArray = emptyStackArray;
            return 1;
        }
return 0;
}

/****************************************************************************************************************/
#define SIZE_QUEUE_ARRAY 10
/*�������� �������������� ��������*/
const int okQueueArray = 0;									// ��� ���������
const int fullQueueArray = 1;								// ������� �����������
const int emptyQueueArray = 2;								// ������� �����
/**********************************/
/*���������� ������*/
extern int errorQueueArray;
/*������� ��� �������*/
typedef TInquiry queueArrayBaseType;
/*���������� �������*/
typedef struct
{
    queueArrayBaseType buf[SIZE_QUEUE_ARRAY];				// ����� �������
    unsigned ukEnd;											// ��������� �� ����� (�� ���� ��������)
    unsigned ukBegin;										// ��������� �� ������ (�� ���� ���������)
    unsigned len;											// ���������� ��������� � �������
} QueueArray;

int errorQueueArray;
/*������������� �������*/
void initQueueArray(QueueArray *F)
{
    F->ukBegin = 0;
    F->ukEnd = 0;
    F->len = 0;
    errorQueueArray = okQueueArray;
}
/*��������� � �������*/
void putQueueArray(QueueArray *F, queueArrayBaseType E)
{
    /*���� ������� �����������*/
    if (isFullQueueArray(F))
        return;
    /*�����*/
    F->buf[F->ukEnd] = E;									// ��������� ��������
    F->ukEnd = (F->ukEnd + 1) % SIZE_QUEUE_ARRAY;			// ����� ���������
    F->len++;												// ���������� ���������� ��������� �������
}
/*���������� �� �������*/
void getQueueArray(QueueArray *F, queueArrayBaseType *E)
{
/*���� ������� �����*/
    if (isEmptyQueueArray(F))
        return;
    /*�����*/
    *E = F->buf[F->ukBegin];								// ������ �������� � ����������
    F->ukBegin = (F->ukBegin + 1) % SIZE_QUEUE_ARRAY;		// ����� ���������
    F->len--;												// ���������� �����
}
/*��������: ����� �� �������*/
int isFullQueueArray(QueueArray *F)
{
    if (F->len == SIZE_QUEUE_ARRAY)
    {
        errorQueueArray = fullQueueArray;
        return 1;
    }
    return 0;
}
/*��������: ����� �� �������*/
int isEmptyQueueArray(QueueArray *F)
{
    if (F->len == 0)
    {
        errorQueueArray = emptyQueueArray;
        return 1;
    }
return 0;
}

/****************************************************************************************************************/
void WriteOneZapr (TInquiry a)
{
    printf("name  : %s\n", a.Name);
    printf("time  : %d\n", a.Time1);
  //  printf("time  : %d\n", a.Time2);
    printf("prior : %d\n", a.P);
}

void ReadOneZapr (TInquiry a)
{
    scanf("%s", &a.Name);
    scanf("%d", &a.Time1);
  //  scanf("%d", &a.Time2);
    scanf("%d", &a.P);
}

void ReadZapros (TInquiry *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("name  >> ");
        scanf("%s", &a[i].Name);
        printf("time1  >> ");
        scanf("%d", &a[i].Time1);
      //  printf("time2  >> ");
      //  scanf("%d", &a[i].Time2);
        printf("prior >> ");
        scanf("%d", &a[i].P);
    }
}

void WriteZapros (TInquiry* a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("name  : %s\n", a[i].Name);
        printf("time  : %d\n", a[i].Time1);
       // printf("time  : %d\n", a[i].Time2);
        printf("prior : %d\n", a[i].P);
        printf("\n");
    }
}

void GenZapros (TInquiry *a)
{
    int i;
    for (i=0; i<10; i++)
        a->Name[i] = rand()%(90-65+1) + 65;
    a->P = rand()%(0-0+1) + 0;
    a->Time1 = rand()%(10-2+1) + 2;
    //a->Time2 = rand()%(5-1+1) + 1;
}

void GenMassZapros (TInquiry *a, size_t n)
{
    int i;
    for (i=0; i<n; i++)
        GenZapros(&a[i]);
}

void MassFifoRaspr (TInquiry *a, QueueArray *F0, QueueArray *F1, QueueArray *F2, size_t n)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (a[i].P == 0)
            putQueueArray(&F0, a[i]);
        if (a[i].P == 1)
            putQueueArray(&F1, a[i]);
        if (a[i].P == 2)
            putQueueArray(&F2, a[i]);
    }
}

void FifoRaspr (TInquiry a, QueueArray *F0, QueueArray *F1, QueueArray *F2)
{
    if (a.P == 0)
        putQueueArray(&F0, a);
    if (a.P == 1)
        putQueueArray(&F1, a);
    if (a.P == 2)
        putQueueArray(&F2, a);

}

/****************************************************************************************************************/
/*
int main()
{
    srand(time(NULL));
    int n=3, i=0;
    printf("n >> "); //���������� ��������
   // scanf("%d", &n);
    TInquiry P1, P2, tmp0, tmp00, tmp1, tmp2, workz;
//    TInquiry *a = (TInquiry*)calloc(n, sizeof(TInquiry)); //��������� ������ �� ������ ��������
   // GenMassZapros(a, n); //��������� ������� ��������
    //WriteZapros(a, n);

    TInquiry a[3];
    a[0].Name[10] = "1234567890";
    a[1].Name[10] = "0987654321";
    a[2].Name[10] = "0129384756";
    a[0].P=0; a[0].P=1; a[0].P=2;
    a[0].Time1=10; a[1].Time1=4; a[2].Time1=13;

    QueueArray F0, F1, F2;

    initQueueArray(&F0);

    initQueueArray(&F1);

    initQueueArray(&F2);


    StackArray S1, S2;
    initStackArray(&S1);

    initStackArray(&S2);


    MassFifoRaspr(a, &F1, &F2, &F0, n); //������������ ������� �� ��������

    printf("n >> ");

    while (isEmptyStackArray(&S1) || isEmptyStackArray(&S2) || !isEmptyQueueArray(&F0) || !isEmptyQueueArray(&F1) || !isEmptyQueueArray(&F2) || P1.Time1!=0 || P2.Time1!=0)
    {
        printf("n >> ");
        if (!isEmptyQueueArray(&F0)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &P1);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &tmp0);
            }
        }

        //������ �� ������ ��������
        if (!isEmptyQueueArray(&F1)&&isEmptyQueueArray(&F0)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
        }
        //������ � ������� ��������
        if (!isEmptyQueueArray(&F2)&&isEmptyQueueArray(&F0)&&isEmptyQueueArray(&F1)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
        }
        if (isEmptyQueueArray(&F0)&&isEmptyQueueArray(&F1)&&isEmptyQueueArray(&F2))     return 0;

    }

    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    return 0;
}
*/

int main()
{
    srand(time(NULL));
    int n, i=0;
    printf("n >> "); //���������� ��������
    scanf("%d", &n);
    TInquiry P1, P2, tmp0, tmp00, tmp1, tmp2, workz;
    QueueArray F0, F1, F2;
    initQueueArray(&F0);    initQueueArray(&F1);    initQueueArray(&F2);

    StackArray S1, S2;
    initStackArray(&S1);    initStackArray(&S2);

    GenZapros(&tmp0);    i=1;
    while (i>n || isEmptyStackArray(&S1) || isEmptyStackArray(&S2) || !isEmptyQueueArray(&F0) || !isEmptyQueueArray(&F1) || !isEmptyQueueArray(&F2) || P1.Time1!=0 || P2.Time1!=0)
    {
        if (!isEmptyQueueArray(&F0)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &P1);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &tmp0);
            }
        }

        //������ �� ������ ��������
        if (!isEmptyQueueArray(&F1)&&isEmptyQueueArray(&F0)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
        }
        //������ � ������� ��������
        if (!isEmptyQueueArray(&F2)&&isEmptyQueueArray(&F0)&&isEmptyQueueArray(&F1)) //���� ������� �� �����
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //���������� �����
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //���� ������, �� ���� ������
            {
               // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //�������� �� ��� �������
                putStackArray(&S1, P1); //��������� � ���� �� ��� ����
                P1=tmp0; //�������� ����� �������
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //��������� � ���� �� ��� ����
                P2=tmp0; //�������� ����� �������
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //��������� ����� � ���������� 1
                P1.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
            if (P2.Time1!=0) //��������� ����� � ���������� 1
                P2.Time1--;
            else //����� ����� �������� ���-�� �� �����
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
        }
        if (i<n)
        {
            GenZapros(&tmp0);
            i++;
        }
        FifoRaspr(tmp0, &F0, &F1, &F2);
    }

    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    return 0;
}
