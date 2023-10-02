
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
long unsigned d[N];

//�뤥����� ����� �����
int **getMemoryMatr(int str, int tab) {
    int **matr = (int **)malloc(str * sizeof(int *));
    for (int i = 0; i < str; i++)
        matr[i] = (int *)malloc(tab * sizeof(int));
    return matr;
}
//���� ��� ���짮��⥫�� � �������� �ணࠬ��� ����
void input_knf(int** a, int* b, int m, int n) {
    int i, j;

    printf("��� ��ਬ����: ");
    for (i = 0; i<n; i++) {
        b[i] = 'A' + i;
        printf("%c ", b[i]);
    }
    printf("\n");
    printf("������祭��:\n");
    printf("����稥 ��६����� : 1\n");
    printf("���栭�� ��६�����: -1\n");
    printf("������⢨� ��६�����: 0 \n");

    for (i = 0; i < m; i++) {
        printf("C����� %d:\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%i", &a[i][j]);
    }
}

//�뢮� ��� �� �࠭
void output_forml(int **a, int* b, int m, int n) {
    int i = 0, j = 0;

    for (i = 0; i < m; i++) {
        printf("(");
        j = 0;
        while ((a[i][j] == 0) && (j < n))
            j++;
        if (j < n) {
            if (a[i][j] == -1)
                printf("!%c", b[j]);
            else
                printf("%c", b[j]);
        }
        j++;
        for (; j < n; j++) {
            if (a[i][j] == -1)
                printf(" + !%c", b[j]);
            if (a[i][j] == 1)
                printf(" + %c", b[j]);

        }
        printf(")");
        if ((i + 1) < m)
            printf("*");
    }
    printf("\n");
}

//�뢮� ����祭��� ⠡���� ��⨭����, � ��� ������ ���
int** output_tab(int **a, int *b, int m, int n) {
    int i, j, mask = 1, f, x, z, k;
    //�뢮� ������祭�� �⮫�� � ⠡��� ��⨭����
    for (i = 0; i < n; i++)
        printf("%c ", b[i]);
    printf("f\n");

    int all = pow(2, n);
    //⠡��� ��⨭����
    int **tabl = getMemoryMatr(all, n + 1);


    for (i = 0; i < all; i++) {
        //����祭�� ����筮�� ����� �᭮�뢠��� �� �।��饬 �����
        for (j = 0; j < n; j++) {
            tabl[i][j] = (mask & (i >> (n - 1 - j)));
            printf("%i ", tabl[i][j]);
        }
        f = 1;
        z = 0;
        //�����뢠��� ���� �� ����祭���� ����筮�� ������
        while ((z < m) && (f)) {
            x = 0;
            k = 0;
            while (k < n) {
                if (a[z][k] == 1)
                    x |= tabl[i][k];
                if (a[z][k] == -1)
                    x |= !tabl[i][k];
                k++;
            }
            f = f && x;
            z++;
        }
        tabl[i][n] = f;
        printf("%i\n", tabl[i][n]);
    }
    return tabl;
}


void output(long unsigned d[], int k, int* b, int** tabl, int n, int *ABC) {
    size_t i, j;
    for (i = 0; i < k; i++)
        if (d[i]) {
            printf("(");
            for (j = 0; j < n - 1; j++) {
                if (tabl[b[i]][j] == 1)
                    printf("!%c+", ABC[j]);
                else
                    printf("%c+", ABC[j]);
            }
            if (tabl[b[i]][n - 1] == 1)
                printf("!%c", ABC[n - 1]);
            else
                printf("%c", ABC[n - 1]);
            printf(")");
        }
}


void  consequences(size_t i, int k, int* b, int** tabl, int n, int* ABC) {
    short unsigned x;
    for (x = 0; x <= 1; x++) {
        d[i] = x;
        if (i == k - 1) {
            output(d, k, b, tabl, n, ABC);
            printf("\n");
        }
        else
            consequences(i + 1, k, b, tabl, n, ABC);
    }
}
//�뤥����� ����� ���ᨢ�
int *getMemoryArr(int size) {
    return (int *)malloc(size * sizeof(int));
}
//��饭�� ����� ���ᨢ�
void freeMemoryArr(int *arr) {
    free(arr);
}


//��饭�� ����� ������
void freeMemoryMatr(int **matr, int str) {
    for (int i = 0; i < str; i++)
        free(matr[i]);
    free(matr);
}



int main() {

    int **tabl;
    printf("������⢮ ᪮��� � ���: ");
    int m;
    scanf("%i", &m);
    printf("������⢮ ��६�����: ");
    int n;
    scanf("%i", &n);
    int *b = getMemoryArr(pow(2, n));
    //����� ���� ���
    //��ப� ������ - ���� ᪮��� ���
    //����� �⮫��� �����᪨� �易� � ����� ��६�����
    //���祭�� � �祩�� �ࠪ�ਧ�� ����稥(1), ���栭��(-1) ��� ������⢨�(0) ��६�����
    int **a = getMemoryMatr(m, n);

    //���ᨢ ��६����� � ���� ᨬ�����
    int *ABC = getMemoryArr(n);

    //���� ���
    input_knf(a, ABC, m, n);
    //�뢮� ��� � �ਢ�筮� �ଥ
    output_forml(a, ABC, m, n);
    //����஥��� ⠡���� ��⨭���� � �뢮� �� �� �࠭
    tabl = output_tab(a, ABC, m, n);

    for (int j = 0; j < pow(2,n); ++j) {
        b[j]=j;
    }
    consequences(0, m+1, b, tabl, n, ABC);

    freeMemoryArr(ABC);
    freeMemoryMatr(a, m);
    freeMemoryMatr(tabl, pow(2, m));
    return 0;
}

