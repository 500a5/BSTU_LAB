#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

//«адача, воспроизвести звук использу€ этот код

int main()
{
    sound(440);
    sleep(1);
    nosound();
    return 0;
}
