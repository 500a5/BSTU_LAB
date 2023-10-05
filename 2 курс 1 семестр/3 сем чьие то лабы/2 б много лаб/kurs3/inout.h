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

//Вывод массива точек t размера n на экран.
void output (tochka *t, size_t n);

//Ввод с клавиатуры массива точек t размера n.
void input (tochka *t, size_t n);

//Вывод массива точек t размера n на экран.
void output_xy (tochka_xy *t, size_t n);

//Возвращает количество записей файла f_name.
int kol_zap_file (char *f_name);

//Ввод массива точек t размера n из файла f_name.
void input_file (tochka **t, size_t n, char* f_name);

//Запись данных в файл
void output_file (tochka *t, size_t n);


#endif // INOUT_H_INCLUDED
