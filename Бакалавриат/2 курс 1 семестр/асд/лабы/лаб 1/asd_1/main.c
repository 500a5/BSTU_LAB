#include <stdio.h>

void PrintByte (unsigned char a)
{
    int i;

    for (i = 7; i >= 0; i--)
    {
        printf ("%d", (a & 128) == 128);
        a = a << 1;
    }
    printf(" ");
}

void PrintVar (void *a, unsigned int size)
{
    char *s=(char *)a;
    int i;
    for (i = size-1; i >=0; i--)
    {
        PrintByte(s[i]);
        printf(" ");
    }
}

//вводит с консоли символы в строку s  и возвращает  количество прочитанных символов
int inputBits(int s[]) {
    int count = 0;
    char c;
    while ((c = getchar()) != '\n')
        *(s + count++) = c;
    *(s + count) = '\0';
    return count;
}

//преобразовывает последовательностей нулей и единиц в строке s размером size в последовательность бит
// возвращает не типизированный указатель
void *transfVar(char *s, int size) {
    int sizeOfByts = size / 8;
    char * rez =(char *) malloc(sizeOfByts);
    int i, j, pos;
    for (i = 0; i < sizeOfByts; i++) {
        pos = sizeOfByts - i - 1;
        rez[pos] = 0;
        for (j = 0; j < 8; i++) {
            rez[pos] = rez[pos] << 1;
            rez[pos] = rez[pos] | (s[i * 8 + j] == '1' ? 1 : 0);
        }
    }
    return rez;
}
void to_double_from_bin(const char *s){
    int size = sizeof(double);
    short sign = 1;
    int poryadoc = 0;
    int len_e = 10;
    double digit = 1.0;
    int two_power_e = 1024;
    double two_power_m = 1;
    for (int i = 0; i < size-1; i++)
        for (int j = i*8; j < i*8 + 8; j++) {
            if (i == 0 && j == 0) {
                if (s[0] == '1')
                    sign = -1;
            } else{
                if( len_e > 0){
                    poryadoc = (s[j] - '0') * two_power_e + poryadoc;
                    two_power_e = two_power_e >> 1;
                    len_e -= 1;
                } else if (len_e == 0) {
                    poryadoc = poryadoc - 1023;
                    if (poryadoc > 0) {
                        two_power_m = 2 << poryadoc;
                        digit = digit * two_power_m;
                        two_power_m = two_power_m * 0.5;
                    }else {
                        for (int pow = 0; pow < abs(poryadoc); ++pow) {
                            two_power_m = two_power_m * 0.5;
                        };
                        digit = digit * two_power_m;
                        two_power_m = two_power_m * 0.5;
                    }
                    len_e -= 1;
                } else{
                    digit = (s[j] - '0') * two_power_m + digit;
                    two_power_m = two_power_m * 0.5;
                }
            }
        }
    digit = sign * digit;
    printf("%lf", digit);
}

void to_int_from_bin(const char *s, int length){
    int power = 1;
    long int digit = 0;
    for (int i = length - 1; i >= 0; i--) {
        digit = (s[i] - '0') * power + digit;
        power = power << 1;
    }
    printf("%ld", digit);
}
char *m_byte(char *s)
{
    size_t len = strlen(s);

    unsigned char *a = calloc(len / 8, 1);
    unsigned char t;
    int i_byte = 0, i_bite = 0;
    for (int i = len - 1; i > -1 ; --i){

        t = s[i] - '0';

        a[i_byte] |= t << i_bite;

        i_bite++;

        if(i_bite == 8){

            i_bite = 0;

            i_byte++;

        }


    }

    return a;
}
int main ()
{
    char *s="01000001100000001111110010111001";
    char *m;
    char *s1="0000000001111000";
    char *s2="01000001100000001111110010111001";
    char *s3="01000001101010111001100110011010";

    unsigned short n1 = 120,b;
    float n2 ,c= 16.1234;
    float a[10][10];
    a[0][1]=21.45;


    m = m_byte(s1);
    b   = *((unsigned char*)m);
    printf("Число %u с типом usigned char:  \n",b);
    free(m);
    m = m_byte(s2);
    c      = *((float *)m);
    printf("Число %lf с типом float:\n", c);
    free(m);
    m = m_byte(s3);
    a[0][1] = *((float *)m);
    printf("Массив float: %f",a[0][1]);
    free(a);
/**
    printf ("\nЗначение числа %hu типа unsigned short: \n", n1);
    PrintVar(&n1, sizeof(unsigned short));

    printf ("\nЗначение числа %.4f типа float: \n", n2);
    PrintVar(&n2, sizeof(float));

    printf("\nЗначение числа a[0][1] типа float: \n");
    PrintVar(&a[0][1], sizeof(float));
    **/
}
