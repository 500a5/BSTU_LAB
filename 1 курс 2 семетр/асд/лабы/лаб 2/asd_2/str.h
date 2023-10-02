#ifndef ASD_2_STR_H
#define ASD_2_STR_H
#include <malloc.h>
#include <stdio.h>

//Операция прошла успешно
static const short STR_SUCCESSFUL= 0;

//Выход за границу максимально разрешенного размера строки
//при вводе в нее данных
static const short STRING_INPUT_ERROR = -1;


//Выход за границу максимально разрешенного размера строки
//при вставке данных из одной строки в другую
static const short STRING_INSERT_ERROR = -2;

//Попытка вставить элемент на место которое не существует
static const short STRING_NO_PLACE = -3;

//Выход за границу максимально разрешенного размера строки
//при конкатенации в нее данных
static const short STRING_CONCATEN_ERROR = -4;
// ошибка поиска в меньшей строки большей подстроки
static const short STRING_Pos_ERROR = -5;

extern short STRING_ERROR;
#define M 1024
typedef struct
{
    char s[M];
    unsigned N; // Динамическая (текущая) длина строки

} str;

typedef str string1[2];

//Запись данных в строку st из строки s
//Строка s заканчивается нулевым символом
void WriteToStr(string1 st, char *s);

//Запись данных в строку s из строки st
//Строка s заканчивается нулевым символом
void WriteFromStr(char *s, string1 st);

//Ввод строки s с клавиатуры
void InputStr(string1 st);

//Вывод строки s на экран монитора
void OutputStr(string1 st);

//Сравнивает строки s1 и s2 возвращает 0 если
//s1 == s2; 1 если s1 > s2; -1 если s1 < s2
int Comp(string1 s1, string1 s2);

//Удаляет count символов из строки s
//начиная с позиции index
void Delete(string1 st, unsigned index, unsigned count);

//Вставляет подстроку subS в строку s
//начиная с позиции index
void Insert(string1 subS, string1 st, unsigned index);

//Выполняет конкатенацию строк s1 и s2 результат помещает в sRez
void Concat(string1 s1, string1 s2, string1 sRez);

//Записывает count символов в строку subS из строки s
//начиная с позиции index
void Copy(string1 s, unsigned index, unsigned count, string1 subS);

//Возвращает текущую длинну строки s
unsigned Length(string1 s);

//Возвращает позицию начиная с которой в строке s
//распологается строка subS
unsigned Pos(string1 subS, string1 s);



#endif //ASD_2_STR_H
