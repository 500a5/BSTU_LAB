#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TInquiry
{
    char Name[10]; // имя запросаsdf
    unsigned Time1; // время обслуживания
    // unsigned Time2; // время обслуживания
    unsigned short int P; // приоритет 0 — высший, 1 — средний, 2 - нисший
} TInquiry;

/****************************************************************************************************************/
#define SIZE_STACK_ARRAY 100
/*Описание исключительных ситуаций*/
const int okStackArray = 0;											// Все нормально
const int fullStackArray = 1;										// Стек переполнен
const int emptyStackArray = 2;										// Стек пуст
/*********************************/
/*Переменная ошибок*/
extern int errorStackArray;
/*Базовый тип стека*/
typedef TInquiry stackArrayBaseType;
/*Дескриптор стека*/
typedef struct {
stackArrayBaseType buf[SIZE_STACK_ARRAY];						// Буфер стека
unsigned uk;													// Указатель
} StackArray;

/*Переменная ошибок*/
int errorStackArray;
/*Инициализация стека*/
void initStackArray(StackArray *S)
{
    S->uk = 0;
    errorStackArray = okStackArray;
}
/*Включение в стек*/
void putStackArray(StackArray *S, stackArrayBaseType E)
{
    /*Если стек переполнен*/
    if (isFullStackArray(S))
        return;
    /*Иначе*/
    S->buf[S->uk] = E;				// Включение элемента
    S->uk++;							 	// Сдвиг указателя
}
/*Исключение из стека*/
void getStackArray(StackArray *S, stackArrayBaseType *E)
{
    /*Если стек пуст*/
    if (isEmptyStackArray(S))
        return;
    /*Иначе*/
    *E = S->buf[S->uk - 1];		// Считывание элемента в переменную
    S->uk--;							 	// Сдвиг указателя
}
/*Предикат: полон ли стек*/
int isFullStackArray(StackArray *S)
{
    if (S->uk == SIZE_STACK_ARRAY)
        {
            errorStackArray = fullStackArray;
            return 1;
        }
    return 0;
}
/*Предикат: пуст ли стек*/
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
/*Описание исключительных ситуаций*/
const int okQueueArray = 0;									// Все нормально
const int fullQueueArray = 1;								// Очередь переполнена
const int emptyQueueArray = 2;								// Очередь пуста
/**********************************/
/*Переменная ошибок*/
extern int errorQueueArray;
/*Базовый тип очереди*/
typedef TInquiry queueArrayBaseType;
/*Дескриптор очереди*/
typedef struct
{
    queueArrayBaseType buf[SIZE_QUEUE_ARRAY];				// Буфер очереди
    unsigned ukEnd;											// Указатель на хвост (по нему включают)
    unsigned ukBegin;										// Указатель на голову (по нему исключают)
    unsigned len;											// Количество элементов в очереди
} QueueArray;

int errorQueueArray;
/*Инициализация очереди*/
void initQueueArray(QueueArray *F)
{
    F->ukBegin = 0;
    F->ukEnd = 0;
    F->len = 0;
    errorQueueArray = okQueueArray;
}
/*Включение в очередь*/
void putQueueArray(QueueArray *F, queueArrayBaseType E)
{
    /*Если очередь переполнена*/
    if (isFullQueueArray(F))
        return;
    /*Иначе*/
    F->buf[F->ukEnd] = E;									// Включение элемента
    F->ukEnd = (F->ukEnd + 1) % SIZE_QUEUE_ARRAY;			// Сдвиг указателя
    F->len++;												// Увеличение количества элементов очереди
}
/*Исключение из очереди*/
void getQueueArray(QueueArray *F, queueArrayBaseType *E)
{
/*Если очередь пуста*/
    if (isEmptyQueueArray(F))
        return;
    /*Иначе*/
    *E = F->buf[F->ukBegin];								// Запись элемента в переменную
    F->ukBegin = (F->ukBegin + 1) % SIZE_QUEUE_ARRAY;		// Сдвиг указателя
    F->len--;												// Уменьшение длины
}
/*Предикат: полна ли очередь*/
int isFullQueueArray(QueueArray *F)
{
    if (F->len == SIZE_QUEUE_ARRAY)
    {
        errorQueueArray = fullQueueArray;
        return 1;
    }
    return 0;
}
/*Предикат: пуста ли очередь*/
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
    printf("n >> "); //количество запросов
   // scanf("%d", &n);
    TInquiry P1, P2, tmp0, tmp00, tmp1, tmp2, workz;
//    TInquiry *a = (TInquiry*)calloc(n, sizeof(TInquiry)); //выделение памяти на массив запросов
   // GenMassZapros(a, n); //генерация массива запросов
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


    MassFifoRaspr(a, &F1, &F2, &F0, n); //распределили запросы по очередям

    printf("n >> ");

    while (isEmptyStackArray(&S1) || isEmptyStackArray(&S2) || !isEmptyQueueArray(&F0) || !isEmptyQueueArray(&F1) || !isEmptyQueueArray(&F2) || P1.Time1!=0 || P2.Time1!=0)
    {
        printf("n >> ");
        if (!isEmptyQueueArray(&F0)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &P1);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &tmp0);
            }
        }

        //работа со второй очередью
        if (!isEmptyQueueArray(&F1)&&isEmptyQueueArray(&F0)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
        }
        //работа с третьей очередью
        if (!isEmptyQueueArray(&F2)&&isEmptyQueueArray(&F0)&&isEmptyQueueArray(&F1)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
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
    printf("n >> "); //количество запросов
    scanf("%d", &n);
    TInquiry P1, P2, tmp0, tmp00, tmp1, tmp2, workz;
    QueueArray F0, F1, F2;
    initQueueArray(&F0);    initQueueArray(&F1);    initQueueArray(&F2);

    StackArray S1, S2;
    initStackArray(&S1);    initStackArray(&S2);

    GenZapros(&tmp0);    i=1;
    while (i>n || isEmptyStackArray(&S1) || isEmptyStackArray(&S2) || !isEmptyQueueArray(&F0) || !isEmptyQueueArray(&F1) || !isEmptyQueueArray(&F2) || P1.Time1!=0 || P2.Time1!=0)
    {
        if (!isEmptyQueueArray(&F0)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &P1);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F0))
                    getQueueArray(&F0, &tmp0);
            }
        }

        //работа со второй очередью
        if (!isEmptyQueueArray(&F1)&&isEmptyQueueArray(&F0)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S2))
                    getStackArray(&S2, &P2);
                else if (!isEmptyQueueArray(&F1))
                    getQueueArray(&F1, &tmp0);
            }
        }
        //работа с третьей очередью
        if (!isEmptyQueueArray(&F2)&&isEmptyQueueArray(&F0)&&isEmptyQueueArray(&F1)) //если нулевая не пуста
        {
            //getQueueArray(&F0, &tmp0);
            if (P1.Time1==0 && P2.Time1 == 0) //процессоры пусты
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1==0) //пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P2=tmp0;
            }
            if (P1.Time1==0 && P2.Time1!=0) //пуст первый, не пуст второй
            {
               // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                P1=tmp0;
            }
            if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P1.P)
            {
                 // getQueueArray(&F0, &tmp0); //достанем из нее элемент
                putStackArray(&S1, P1); //поместили в стек то что было
                P1=tmp0; //записали новый процесс
            }
            else if (P1.Time1!=0 && P2.Time1!=0 && tmp0.P<P2.P)
            {
                putStackArray(&S2, P2); //поместили в стек то что было
                P2=tmp0; //записали новый процесс
            }
        //getQueueArray(&F0, &tmp0);
        }
        else
        {
            if (P1.Time1!=0) //уменьшаем время в процессоре 1
                P1.Time1--;
            else //иначе нужно вытащить что-то из стека
            {
                if(!isEmptyStackArray(&S1))
                    getStackArray(&S1, &P1);
                else if (!isEmptyQueueArray(&F2))
                    getQueueArray(&F2, &tmp0);
            }
            if (P2.Time1!=0) //уменьшаем время в процессоре 1
                P2.Time1--;
            else //иначе нужно вытащить что-то из стека
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
