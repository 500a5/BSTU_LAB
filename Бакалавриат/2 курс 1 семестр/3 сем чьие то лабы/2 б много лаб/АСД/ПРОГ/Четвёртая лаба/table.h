#define N450

typedef struct
{
    unsigned key;
    unsigned data;
} t_element;

typedef struct
{
    t_element buf[N];
    size_t uk;
} t_table;
