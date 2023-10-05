#include <stdio.h>
#include <stdlib.h>
#include "inout.h"

void output (tochka *t, size_t n)
//����� ������� ����� t ������� n �� �����.
{
    printf("\n");
    int i, x;
    for (i=0; i<n; i++)
        {
            x=i+1;
            printf("%d: %.2f; %.2f; %.2f;\n", x, t[i].x, t[i].y, t[i].z);
        }
}


void input (tochka *t, size_t n)
//���� � ���������� ������� ����� t ������� n.
{
    int i, x;
    for (i=0; i<n; i++)
        {
            x=i+1;
            printf("%d: ", x);
            scanf("%f", &t[i].x);
            scanf("%f", &t[i].y);
            scanf("%f", &t[i].z);
        }
}
void output_xy (tochka_xy *t, size_t n)
//����� ������� ����� t ������� n �� �����.
{
    int i, x;
    for (i=0; i<n; i++)
        {
            x=i+1;
            printf("%d: %.2f, %.2f\n", x, t[i].xn, t[i].yn);
        }
}

int kol_zap_file (char *f_name)
//���������� ���������� ������� ����� f_name.
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

void input_file (tochka **t, size_t n, char* f_name)
//���� ������� ����� t ������� n �� ����� f_name.
{
    FILE *F = fopen(f_name, "r");
    int i;
    for (i=0; i<n; i++)
    {
        fscanf(F, "%f", &(*t)[i].x);
        fscanf(F, "%f", &(*t)[i].y);
        fscanf(F, "%f", &(*t)[i].z);
    }
    fclose(F);
}

//������ ������ � ����
void output_file (tochka *t, size_t n)
{
    printf("\n������� ��� ����� ��� ����������: ");
    char f_name [10];
    scanf("%s", &f_name);
    int i;
    FILE *F = fopen(f_name, "w");
    for (i=0; i<n; i++)
    {
        fprintf(F, "%.2f", t[i].x);
        fprintf(F, " %.2f", t[i].y);
        fprintf(F, " %.2f", t[i].z);
        fprintf(F, "\n");

    }
    fclose(F);
}
