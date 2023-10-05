typedef struct
{
    float x, y;
} tochka;

void output_mass(float* b, size_t n);
long fact(long a);
void output (tochka *t, size_t n);
void input (tochka *a, size_t n);
int checc (tochka* a, size_t n);
void* end_razn (tochka* a, size_t n, float x);
void* del_razn (tochka* a, size_t n, float x);
float RECend_razn(tochka* a, int exp, int num);
float RECdel_razn(tochka* a, int exp, int num);
