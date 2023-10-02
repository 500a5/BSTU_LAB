
#include "windows.h"
#include "stdio.h"
#include "time.h"
#include "conio.h"

#define N 15

int *log_v;// 3 �������� ��६���� ��� �஢�ન ������⮭��� ���
int **graf;
int *a;


//�뤥����� ����� ��� ��� � ����� ������ ��樤��⭮�� n*m
int ** get_memory_matr(int n, int m) {
    int i;
    int **a;

    // �뤥����� ����� ��� 㪠��⥫� �� ��ப�
    a = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 1; i <= n; i++) {
        // �뤥����� ����� ��� �࠭���� ��ப
        a[i] = (int*)malloc((m + 1) * sizeof(int));
    }
    return a;
}

// ��饭�� ����� ��� ������
void free_memory(int **a, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        free(a[i]);
    }
    free(a);
}
int * init_posl(int n) {
    int *a;
    // �뤥����� �����
    a = (int*)malloc(n * sizeof(int));
    return a;
}

// ���������� ������ n*m ��ﬨ
void clear_matr(int ** a, int n, int m) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            a[i][j] = 0;
        }
    }
    return;
}

// ������� ��砩���� ��� n ���設 � m ॡ��
void init_matr_rand_numbers(int ** a, int n, int m) {
    int i, j, k;
    srand(clock());
    for (j = 1; j <= m; j++) {
        i = rand() % (n)+1;
        a[i][j] = 1;
        k = i;
        while (i == k)
            k = rand() % (n)+1;
        a[k][j] = 1;
    }
    return;
}


// ������� �� ��� �吝�
int is_sviaz(int ** graf, int n, int m) {
    int a[N] = { 0 };
    int i = 1, j, k;
    a[i] = 1;
    int count = 1;
    for (i = 1; i <= n; i++) {
        if (a[i] == i) {
            for (j = 1; j <= m; j++) {
                if (graf[i][j] == 1) {
                    for (k = 1; k <= n; k++) {
                        if ((k != i) && (graf[k][j] == 1) && (a[k] == 0))
                            a[k] = i + 1;
                    }
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        if (a[i] == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_smezh_ver(int a, int b, int m) {
    for (int j = 1; j <= m; j++) {
        if (graf[a][j] && graf[b][j])
            return 1;
    }
    return 0;
}

// ������� �� ����� ��� ����஢�
int is_eil_graf(int ** graf, int n, int m) {
    int count = 0;
    int flag = 1;
    int i = 1, j = 1;
    if (is_sviaz(graf, n, m)) {
        while ((i <= n) && flag) {
            while ((j <= m) && flag) {
                if (graf[i][j] == 1)
                    count++;
                j++;
            }
            if (((count + 1) % 2) == 0)
                flag = 0;
            i++;
            j = 0;
        }
    }
    else
        flag = 0;
    return flag;
}

int find_gam_cikl(int i, int n, int m) {
    int x;
    for (x = 1; x <= n; x++) {
        if ((is_smezh_ver(a[i - 1], x, m)) && (x != a[i - 1]) && (log_v[x] == 0)) {
            a[i] = x;
            if ((a[i] == a[0]) && (i == n))
                return 1;
            else {
                log_v[x] = 1;
                if (find_gam_cikl((i + 1), n, m))
                    return 1;
                log_v[x] = 0;
            }
        }
    }
    return 0;
}


// ������� �� ����� ��� ������⮭���
int is_gam_graf(int ** graf, int n, int m) {
    if (is_sviaz(graf, n, m)) {
        int i;

        for (i = 0; i < n; i++)
            a[i] = 0;

        for (i = 0; i <= n; i++)
            log_v[i] = 0;

        a[0] = 1;

        if (find_gam_cikl(1, n, m))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}




void ten_sec_gen(int n, int last) {
    double time_spent = 0;
    int count_eil = 0, count_gam = 0, count_un = 0;
    int m = n + 1;
    // �뤥����� �����
    graf = get_memory_matr(n, m);
    a = init_posl((n));
    log_v = init_posl((n + 1));
    printf("__________________________________________________________________________________________________\n");
    printf("| ���-�� ���設 | ������⢮ ॡ�� | ����� ����஢�� ��䮬 | ������⮭���� ��䮢 | ��� ��䮢 |\n");
    while (m <= last) {
        while (time_spent < 10) {
            clock_t begin = clock();
            clear_matr(graf, n, m);
            init_matr_rand_numbers(graf, n, m);
            clock_t end = clock();
            time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

            // �஢�ઠ, ���� �� ᣥ���஢���� ��� ������⮭���, �᫨ ��, � count_gam++
            if (is_gam_graf(graf, n, m))
                count_gam++;

            // �஢�ઠ, ���� �� ᣥ���஢���� ��� ��஢�, �᫨ ��, � count_eil++
            if (is_eil_graf(graf, n, m))
                count_eil++;

            count_un++;
        }
        // �뢮� ��� n � m १���⮢ ��ᨢ�
        printf("| %13d | %16d | %22d | %20d | %11d |\n", n, m, count_eil, count_gam, count_un);
        // ��饭�� �����
        free_memory(graf, n);
        m++;
        // �뤥����� �����
        graf = get_memory_matr(n, m);
        time_spent = 0;
        count_eil = 0;
        count_gam = 0;
        count_un = 0;
    }

    return;
}





int main() {


    printf("\n\n������ ��� 8 ���設: \n");
    ten_sec_gen(8, 28);
    free(a);
    free(log_v);

    printf("\n\n������ ��� 9 ���設: \n");
    ten_sec_gen(9, 36);
    free(a);
    free(log_v);

    printf("\n\n������ ��� 10 ���設: \n");
    ten_sec_gen(10, 45);
    free(a);
    free(log_v);

    getchar();
    getchar();
    getchar();
    return 0;
}
