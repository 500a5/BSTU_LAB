#include <stdio.h>
#include <stdlib.h>
#define N  450

typedef struct
        {
            int key;
            int data;
        } t_element;

typedef struct
        {
            t_element buf[N+1];
            unsigned uk;
        }t_table;

int main()
{
    printf("Hello world!\n");
    return 0;
}
