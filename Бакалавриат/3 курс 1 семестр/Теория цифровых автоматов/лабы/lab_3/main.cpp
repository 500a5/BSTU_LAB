#include <iostream>


const int NotUsed = system("color F0");
int TableValue3(int *X)
{
    bool Value =  X[1]&&X[2]&&X[3]&&X[5] || !X[2]&&X[3]&&X[4]&&X[5] || !X[1]&&X[3]&&X[4]&&!X[5] || !X[1]&&!X[3]&&X[4]&&X[5]
            || !X[1]&&!X[2]&&!X[3]&&!X[5] || X[1]&&X[2]&&!X[3]&&X[4]&&!X[5] || X[1]&&!X[2]&&X[3]&&!X[4]&&!X[5] || X[1]&&!X[2]&&!X[3]&&!X[4]&&X[5];
        return Value;
}
int TableValue6(int *X)
{
    bool Value = (!X[1]||!X[3]||X[4]||!X[5])&&(X[1]||!X[2]||!X[3]||!X[5])&&(!X[2]||X[3]||!X[4]||X[5])&&(X[1]||!X[3]||X[4]||X[5])&&(X[1]||X[3]||X[4]||
            !X[5])&&(X[1]||X[2]||!X[3]||X[5])&&(X[1]||X[2]||X[3]||!X[5])&&(!X[1]||!X[4]||X[5])&&(!X[1]||!X[2]||X[3])&&
                    (X[2]||!X[4]||!X[5])&&(!X[1]||X[3]||X[5]);
    return Value;
}

int f1(int *x)
{
    bool Value = (x[1]&&x[3]&&x[4]||x[1]&&x[2]&&x[3]||x[1]&&x[3]);
    return Value;
}
int f2(int *x)
{
    bool Value = (!x[1]&&x[2]||x[1]&&!x[2]);
    return Value;
}
int f3(int *x)
{
    bool Value = (x[2]&&!x[3]||x[1]&&x[2]&&x[3]);
    return Value;
}

int main(int argc, const char * argv[]) {
    int X[6];
    for (int i = 1; i < 6; i++)
        printf(" x%d|", i);
    printf("  f1   f2  f3  \n");

    for (X[1] = 0; X[1] < 2; X[1]++)
        for (X[2] = 0; X[2] < 2; X[2]++)
            for (X[3] = 0; X[3] < 2; X[3]++)
                for (X[4] = 0; X[4] < 2; X[4]++)
                    for (X[5] = 0; X[5] < 2; X[5]++)
                    {
                        for (int i = 1; i < 6; i++)
                            printf(" %2d|", X[i]);
                        printf(" %2d   %2d   %2d   ", f1(X),f2(X),f3(X));

                        printf("\n");
                    }
    return 0;
}