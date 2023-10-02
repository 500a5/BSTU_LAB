
#include <iostream>
#include "interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <locale.h>


using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");


    play r;
    r.run();


   
   
}

