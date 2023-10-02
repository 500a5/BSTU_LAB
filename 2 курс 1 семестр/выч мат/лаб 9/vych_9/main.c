#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"

//����⠭�� �訡��
const short NoSolution = 0; //��� �襭��
const short Ok = 1; //�ᯥ譠� ࠡ��
const short ZERO = 2; //������� �� ����
double EPS = 0.1;
short Err; //��६����� �訡��
int countP; //���-�� ���������� � ��⥬�
int countEq; //���-�� �ࠢ����� � ��⥬�




//�뤥����� ����� ���ᨢ�
double *getMamorArr(int n) {
    double *arr = (double *)malloc(n * sizeof(double));
    return arr;
}

//��饭�� ����� ���ᨢ�
void freeMemorArr(double *arr) {
    free(arr);
}

//�뤥����� ����� �����
double **getMemorMatr() {
    double** matr = (double**)malloc(countEq * sizeof(double *));
    for (int i = 0; i < countEq; i++)
        matr[i] = (double *)malloc((countEq + 1) * sizeof(double));
    return matr;
}

//��饭�� ����� �����
void freeMemorMatr(double **matr) {
    for (int i = 0; i < countEq; i++)
        free(matr[i]);
    free(matr);
}
//���塞 ��ப� ������ ���⠬�
void swapStrMatr(double **matr, int i, int j) {
    double *tmp = matr[i];
    matr[i] = matr[j];
    matr[j] = tmp;
}

//����஢���� arr1 ���ᨢ� � ���ᨢ arr2
void copyArr(double *arr1, double *arr2, int size) {
    for (int i = 0; i < size; i++)
        arr2[i] = arr1[i];
}

//᫮����� ���� ���᢮�
void additionArr(double *a, double *b, double *res, int size) {
    for (int i = 0; i < size; i++)
        res[i] = a[i] + b[i];
}

//���⠭�� ���� ���ᨢ��
void subtractionArr(double *a, double *b, double *res, int size) {
    for (int i = 0; i < size; i++)
        res[i] = a[i] - b[i];
}
//����஢���� tab �⮫���� ������ matr � res ���ᨢ
void copyTabMatrInArr(double** matr, double* res, int tab) {
    for (int i = 0; i < countP; i++)
        res[i] = matr[i][tab];
}


//�஢�ઠ ��ப� ������ �� ��������쭮� �८��������: 1 - 㤢���⢮���, ���� 0
int proverka(double *str, int lenStr, int currentElem) {
    double sum = 0;
    for (int i = 0; i < lenStr; i++)
        if (i != currentElem)
            sum += fabs(str[i]);
    return (fabs(str[currentElem]) > sum) ? 1 : 0;
}
//�ਢ������ ������ � �ॡ㥬�� ���
void pravn(double **matr) {
    int flag = 1;
    for (int i = 0; i < countEq; i++) {	//室�� �� ��ப�� �����
        if (!proverka(matr[i], countEq, i)) {	//�᫨ ��ப� �� 㤮���⢮��� ��襬� �᫮���
            for (int j = i + 1; j < countEq; j++)//��ࢠ� ����⪠
                if (proverka(matr[j], countEq, i)) {
                    swapStrMatr(matr, i, j);
                    flag = 0;
                }
            if (flag) {//���� ����⪠
                double *arrTmp = getMamorArr(countEq + 1);// ᮧ��� �������⥫�� ���ᨢ, ��� �ᯥਬ��⮢
                copyArr(matr[i], arrTmp, countEq + 1);
                int j = 0;//��⠢����� ������ �ࠢ�����
                while (!proverka(arrTmp, countEq, i) && (j < countEq)) {
                    if (j != i)
                        additionArr(arrTmp, matr[j], arrTmp, countEq + 1);
                    j++;
                }
                if (!proverka(arrTmp, countEq, i)) {//�᫨ ���� ����⪠ �� 㤠����
                    copyArr(matr[i], arrTmp, countEq + 1);
                    int j = 0;//��⠢����� ������ �஢�����
                    while (!proverka(arrTmp, countEq, i) && (j < countEq)) {
                        //subtractionArr(arrTmp, matr[j++], arrTmp, countEq + 1);
                        if (j != i) {
                            subtractionArr(matr[j], arrTmp, arrTmp, countEq + 1);
                        }
                        j++;
                    }
                    if (!proverka(arrTmp, countEq, i)) {//�᫨ ��祣� �� �������
                        printf("�� 㤠���� �ਢ��� � ��ଠ�쭮 �ଥ\n");
                        return;
                    }
                    else
                        copyArr(arrTmp, matr[i], countEq + 1);
                }
                else
                    copyArr(arrTmp, matr[i], countEq + 1);
            }
        }
        flag = 1;
    }
}

//��ࠦ���� ��६�����
void virach_perem(double **matr) {
    double *tmp = getMamorArr(countEq);
    for (int i = 0; i < countEq; i++) {//室�� �� ��ப��
        tmp[i] = matr[i][i]; // ��������� X
        matr[i][i] = 0;
        for (int j = 0; j < countEq; j++)//���塞 ����� �� ��⨢�������
            if (i != j)
                matr[i][j] = -matr[i][j];
    }
    for (int i = 0; i < countEq; i++)
        for (int j = 0; j < (countEq + 1); j++)
            if (tmp[i] != 0)
                matr[i][j] = matr[i][j] / tmp[i];
            else {
                Err = ZERO;
                return;
            }
}


//���᫥��� 1 ���� ������ (�⮫��)
double normFirst(double **matr) {
    double sum = 0;//�饬 ���ᨬ����� �㬬� �� ����� � �⮫���
    double MaxSum = 0;
    for (int i = 0; i < countEq; i++) {
        for (int j = 0; j < countEq; j++)
            sum += fabs(matr[j][i]);
        if (MaxSum < sum) MaxSum = sum;
        sum = 0;
    }
    return MaxSum;
}

//��᪮��筠� ��ଠ ����� ��砫쭮�� �ਡ�������
double Approximation(double **matr) {
    double max = 0;
    for (int i = 0; i < countEq; i++)
        if (fabs(matr[i][countEq]) > max)
            max = fabs(matr[i][countEq]);
    return max;
}

//���᫥��� ��᪮��筮� ���� ������ (��ப�)
double normEndless(double **matr) {
    double sum = 0;//�饬 ���ᨬ����� �㬬� �� ����� � ��ப��
    double MaxSum = 0;
    for (int i = 0; i < countEq; i++) {
        for (int j = 0; j < countEq; j++)
            sum += fabs(matr[i][j]);
        if (MaxSum < sum) MaxSum = sum;
        sum = 0;
    }
    return MaxSum;
}


//�筮��� ���᫥���
double accuracyCalc(double normB) {
    return (double)(1 - normB)*EPS / normB;
}

//�業�� �᫠ ���権
int countIteration(double normB, double normC) {
    return (int)(log(EPS) + log(1 - normB) - log(normC)) / log(normB);
}





//�᫮��� ��⠭����: 1 - �襭�� ������� � ������ �筮����, ���� 0
int stop(double* tmpRes, double* res) {
    double max = 0, f = 0;
    for (int i = 0; i < countP; i++)
        if ((f = fabs(res[i] - tmpRes[i])) > max)
            max = f;
    return (max <= EPS) ? 1 : 0;
}



//���樠������ ������ (����� ������ �� 䠩��)
double** initMatr(void) {
    double **matr = getMemorMatr();
    FILE *f = fopen("w.txt", "r");
    for (int i = 0; i < countEq; i++)
        for (int j = 0; j <= countEq; j++)
            fscanf(f, "%lf", &matr[i][j]);
    fclose(f);
    return matr;
}

//�뢮� ������
void outputMatr(double **matr) {
    for (int i = 0; i < countEq; i++) {
        for (int j = 0; j <= countEq; j++)
            printf("%lf ", matr[i][j]);
        printf("\n");
    }
}

//�襭�� ��� ��⮤�� ���権
void iterationMethod(double** matr, double* res) {
    if (countP > countEq) {//�஢�ઠ �� ����稥 �襭��
        Err = NoSolution;
        return;
    }
    pravn(matr);//�ਢ������ ������ � �ॡ㥬��� ����
    outputMatr(matr);
    printf("\n");
    virach_perem(matr);//��ࠦ���� ����������
    outputMatr(matr);
    printf("\n");
    double normC = Approximation(matr);//��᪮��筠� ��ଠ ����� ��砫쭮�� �ਡ�������
    double normB1 = normFirst(matr);//���᫥��� 1 ���� ������
    double normBn = normEndless(matr);//���᫥��� ��᪮��筮� ���� ������
    double normB = (normB1 < normBn) ? normB1 : normBn;//�롮� �������襩 ����
    int countIter = countIteration(normB, normC);//�業�� �᫠ ���権
    EPS = accuracyCalc(normB);//�筮��� ���᫥���
    printf("E = %lf\n", EPS);
    double* tmpRes = getMamorArr(countP);// ��� �஢�ન �� ��⠭���� ���᫥��� �ਡ�������
    copyTabMatrInArr(matr, tmpRes, countP);
    int q = 0;//���᫥��� �ਡ������� � �筮�� �襭��
    while (q < countIter) {
        q++;
        int i, j;
        for (i = 0; i < countP; i++) {
            res[i] = 0;
            for (j = 0; j < countP; j++)
                res[i] += matr[i][j] * tmpRes[j];
            res[i] += matr[i][countP];
        }
        if (stop(tmpRes, res)) {//�᫮��� ��⠭����
            Err = Ok;
            freeMemorArr(tmpRes);
            return;
        }
        else {
            copyArr(res, tmpRes, countP);
            int t;
            for (t = 0; t < countP; t++)
                printf("%lf ", res[t]);
            printf("\n");
        }
    }
    if (q == countIter)
        Err = NoSolution;
    freeMemorArr(tmpRes);
}



void rez(double **m, double *x){
    double a[10]={0};
    printf("\n");
    for (int i = 0; i < countEq; ++i) {
        for (int j = 0; j < countEq; ++j) {
           a[i]+= m[i][j]*x[j];
        }
        printf("%2.4lf ",a[i]);
    }

}

int main() {

    printf("������ ���-�� �ࠢ����� � ��⥬� � ���-�� ���������� ");
    scanf("%d%d", &countP, &countEq);
    double** matr = initMatr();//����� ����業⮢ ���
    double* res = getMamorArr(countP);//१���� �����
    iterationMethod(matr, res);//�襭�� ��� ��⮤�� ���権

    if (Err == Ok) {
        printf("\n१����:\n");
        for (int i = 0; i < countP; i++)
            printf("%2.4lf\n", res[i]);
    }
    else
        printf("\n�襭�� ��� \n");
    matr = initMatr();
    printf("����� ���離�");
    rez(matr,res);
    freeMemorArr(res);
    freeMemorMatr(matr);
    return 0;
}

