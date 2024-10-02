#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Ввод (inout = 1)/вывод(inout = 2) по ключу
int tryIN_OUT(Table *T, const char buffer[128], int i, int inout, int j){
//Проверка числа операндов
    //Пропустим пробелы
    while (buffer[i] == ' '){
        i++;
    }
//Считаем операнд
    char key = buffer[i];
    i++;
//Если операнд, не последний символ в строке, то ошибка
    if ((buffer[i] != '\n')&&(buffer[i] != '\0')){
        printf("Ошибка операнда в строке%d", j);
        return 0;
    }

    if (inout == 1) {
//Осуществление включение операнда в таблицу
        //Запрос ввода у пользователя
        float E, TEMP;
        scanf("%f", &E);
//Был ли элемент с данным ключом ранее
        //Если нет, то обновляем значение по ключу
        if (!ReadTable(T, &TEMP, key))
            PutTable(T, &E, key);
        else {
//Иначе обновляем
            WriteTable(T, &E, key);
        }
    } else{
        float TEMP;
        if (ReadTable(T, &TEMP, key))
            printf("%c = %2.1f\n", key, TEMP);
        else{
            printf("Неизвестный операнд из строки%d", j);
            return 0;
        }
    }
}

//Реализация арифметических операций
int tryArithmetics(Table *T, const char buffer[128], char key1, char key2 , int number){
    float TEMP2;
//Проверка, есть ли второй операнд в таблице
    if (!ReadTable(T, &TEMP2, key2)){
        return 0;
    }

//Если первого операнда нет, то добавить его
    float TEMP1;
    if (!ReadTable(T, &TEMP1, key1)){
        PutTable(T, 0, key1);
    }

//MUL
    if (number == 2){
        float mul = TEMP1*TEMP2;
        WriteTable(T,&mul,key1);
    }

//DIV
    if (number == 3){
        float div = TEMP1/TEMP2;
        WriteTable(T,&div,key1);
    }

//SUB
    if (number == 4){
        float sub = TEMP1-TEMP2;
        WriteTable(T,&sub,key1);
    }

//ADD
    if (number == 5){
        float add = TEMP1+TEMP2;
        WriteTable(T,&add,key1);
    }
    return 1;
}


//Реализация обработка двух операндов
//number = 1, при операции MOV
//2, если MUL
//3, если DIV
//4, если SUB
//5, если ADD
int tryTwoOperands(Table *T, const char buffer[128], int i, int number, int j){
//Пропуск пробелов
    while (buffer[i] == ' '){
        i++;
    }
//Пробуем считать операнды
    char key1 = buffer[i];
    i++;
    if (buffer[i] == ' ')
        i++;
    else{
        printf("Ошибка операнда 1 в строке %d", j);
        return 0;
    }
    char key2 = buffer[i];

    i++;
    if ((buffer[i] != '\n')&&(buffer[i] != '\0')){
        printf("Ошибка операнда 2 в строке %d", j);
        return 0;
    }

//Если команда не mov, то выполнить арифметическую команду
    if (number != 1) {
        int flag = tryArithmetics(T, buffer, key1, key2, number);
        return flag;
    }

//Если оба символа буквы, то выполним операцию MOV
    int key1temp = (int)key1;
    int key2temp = (int)key2;
    if (number == 1) {
        if ((key1temp >= 97) && (key1temp <= 123) && (key2temp >= 97) && (key2temp <= 123)) {

            float TEMP;
            if (ReadTable(T, &TEMP, key2))
                PutTable(T, &TEMP, key1);
            else {
                printf("Неизвестный операнд из строки %d", i);
                return 0;
            }
        } else {
            printf("Ошибка названия операнда в строке %d", i);
            return 0;
        }
    }
}


//Распознавание команды
int checkingComand(Table *T, const char comand[128], const char buffer[128], int i, int j){
    if ((comand[0] == 'I')&&(comand[1] == 'N')&&(comand[2] == ' ')){
        int flag  = tryIN_OUT(T, buffer, i, 1, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'M')&&(comand[1] == 'O')&&(comand[2] == 'V')&&(comand[3] == ' ')){
        int flag = tryTwoOperands(T, buffer, i, 1, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'M')&&(comand[1] == 'U')&&(comand[2] == 'L')&&(comand[3] == ' ')){
        int flag = tryTwoOperands(T, buffer, i, 2, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'D')&&(comand[1] == 'I')&&(comand[2] == 'V')&&(comand[3] == ' ')){
        int flag = tryTwoOperands(T, buffer, i, 3, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'S')&&(comand[1] == 'U')&&(comand[2] == 'B')&&(comand[3] == ' ')){
        int flag = tryTwoOperands(T, buffer, i, 4, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'A')&&(comand[1] == 'D')&&(comand[2] == 'D')&&(comand[3] == ' ')){
        int flag = tryTwoOperands(T, buffer, i, 5, j);
        return (!flag)?-1:1;
    }
    if ((comand[0] == 'O')&&(comand[1] == 'U')&&(comand[2] == 'T')&&(comand[3] == ' ')){
        int flag  = tryIN_OUT(T, buffer, i, 2, j);
        return (!flag)?-1:1;
    }
//Неизвестная команда
    return 0;
}

//Обработка очередной строки программы
int update(Table *T, const char buffer[128], int j){
//Позиция каретки
    int i = 0;
    char comand[128];

//Пока не пробел, считываем команду
    while ((buffer[i] != ' ')&&(i <128)){
        comand[i] = buffer[i];
        i++;
    }
    comand[i] = buffer[i];
    comand[++i] = '\0';

//Распознавание команды
    int flag = checkingComand(T, comand, buffer, i, j);
    if (flag == 0){
        printf("Неизвестная команда в строке: %d", j);
        return 0;
    }
    if (flag == -1){
        return 0;
    }

//Строка обработана успешно
    return 1;
}


int main(){

    Table *T = InitTable(113, 0);

//Открытие файла, в котором содержится программа
    FILE *file;
    file = fopen("TextProgramm.txt", "r");
    char buffer[128];

//Пока не конец файла
    int i = 0;
    while (!feof(file)){
        fgets(buffer, 127, file);
        i++;
//Обработка i - строки
        int flag = update(T, buffer, i);
//Выйти из программы при обнаружении ошибки
        if (!flag)
            break;
    }

    fclose(file);
    puts("");
    system("pause");
    return 0;
}
