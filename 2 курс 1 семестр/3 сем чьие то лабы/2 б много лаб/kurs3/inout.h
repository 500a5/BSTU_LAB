#ifndef INOUT_H_INCLUDED
#define INOUT_H_INCLUDED

typedef struct
{
    float x, y, z;
} tochka;

typedef struct
{
    float xn, yn;
} tochka_xy;

//����� ������� ����� t ������� n �� �����.
void output (tochka *t, size_t n);

//���� � ���������� ������� ����� t ������� n.
void input (tochka *t, size_t n);

//����� ������� ����� t ������� n �� �����.
void output_xy (tochka_xy *t, size_t n);

//���������� ���������� ������� ����� f_name.
int kol_zap_file (char *f_name);

//���� ������� ����� t ������� n �� ����� f_name.
void input_file (tochka **t, size_t n, char* f_name);

//������ ������ � ����
void output_file (tochka *t, size_t n);


#endif // INOUT_H_INCLUDED
