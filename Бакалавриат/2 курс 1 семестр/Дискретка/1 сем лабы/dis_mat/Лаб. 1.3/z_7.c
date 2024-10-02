#include <stdio.h>
#include <math.h>
#include <locale.h>

#define HOWSETS 3
#define HOWVEC (int)pow(2, HOWSETS)

void form_code (unsigned int a[][HOWSETS])
{
    for (unsigned int i = 0; i < HOWVEC; i++){
        unsigned int mask = 1 << HOWSETS-1;
        for  (unsigned int j = 0; j < HOWSETS; j++){
            a[i][j] = (i&mask)!=0?1:0;
            mask >>= 1;
        }
    }
}

void write_multi_arr (unsigned int a[][HOWSETS])
{
    for (int i = 0; i < HOWVEC; i++){
        for (int j = 0; j < HOWSETS; j++)
            printf ("%d ", a[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

void write_arr (int a[])
{
    for (int i = 0; i < HOWVEC; i++){
        printf ("%d ", a[i]);
    }
    printf ("\n");
}

int main()
{
    setlocale (LC_ALL, "rus");

    unsigned int binary_vec[HOWVEC][HOWSETS];
    form_code (binary_vec);
    printf ("«начение всех двоичных векторов дл€ заданного кол-ва исходных множеств:\n");
    write_multi_arr (binary_vec);

    unsigned int truth_table_first[HOWVEC];
    for (int i = 0; i < HOWVEC; i++){
        int f_op = binary_vec[i][0] & binary_vec[i][1];
        int s_op = binary_vec[i][0] & !binary_vec[i][2];
        truth_table_first[i] = f_op | s_op | binary_vec[i][2] | !binary_vec[i][1];
    }

    printf ("“аблица истинности первого выражени€:\n");
    write_arr (truth_table_first);

    unsigned int truth_table_second [HOWVEC];
    for (int i = 0; i < HOWVEC; i++){
        int f_op = binary_vec[i][0] & binary_vec[i][1];
        int s_op = binary_vec[i][0] & !binary_vec[i][2];
        truth_table_second[i] = f_op | s_op | binary_vec[i][2] | !binary_vec[i][1];
    }

    printf ("“аблица истинности второго выражени€:\n");
    write_arr (truth_table_second);
}
