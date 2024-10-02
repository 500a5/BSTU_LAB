// Keyboard functions

#include "function_prototype.h"
#include "sysfunc.h"
#include "keys.h"

byte keycol, keyline, KEYS_last=0;
char table_keys[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};

// Проверка нажатия клавиши в текущий момент, результат:
//  0 - клавиша не нажата
//  ASCII-код клавиши
char KEYS_scannow()
{
  keyline=0;
  // выбираем регистр конфигурации направления (0x03)
  //  и конфигурируем P4-P7 на вывод - для строба столбцов,
  //  а P0-P3 на ввод - для опроса строк (1-ввод, 0-вывод)
  I2C_WriteByte(0x03, 0x0F, KEYS_i2c_addr);

  for (keycol=0; keycol<3; keycol++) {
  // последовательно подаем сигнал низкого уровня на столбцы (P4-P7)
    I2C_WriteByte(0x01, ~(1<<keycol<<4) & 0xf0, KEYS_i2c_addr);
    wait_1ms(1);
    // и опрашиваем строки (P0-P3) на наличие нуля
    keyline = ~(I2C_ReadByte(0x00, KEYS_i2c_addr)) & 0x0f;
    if (keyline) break;
  }
  if (!keyline) return 0;       // если не была нажата никакая клавиша - возвращаем 0
  if (keyline == 4) keyline = 3;  // переводим номера разрядов в номер строки
  if (keyline == 8) keyline = 4;
  KEYS_last = table_keys[--keyline*3+keycol]; // получаем код нажатой клавиши из таблицы
  return KEYS_last;
}


// Возвращает код последней нажатой клавиши, результат:
//  0 - не нажималась никакая клавиша
//  ASCII-код клавиши
char KEYS_lastkey()
{
  KEYS_scannow();
  return KEYS_last;
}


// Очистка последней нажатой клавиши
void KEYS_clear()
{
  KEYS_last = 0;
  wait_1ms(200);
}

// Ожидание нажатия клавиши, результат - ASCII-код нажатой клавиши
char KEYS_waitkey()
{
  KEYS_clear();           // очистка последней нажатой клавиши
  while (!KEYS_scannow()) // пока не нажата никакая клавиша,
    wait_1ms(1);          //    сделать паузу
  return KEYS_last;       // вернуть код нажатой клавиши
}


// пауза с циклическим опросом клавиатуры, прерывается если нажата клавиша
void KEYS_pause(byte cnt)
{
  byte i;
  KEYS_clear();           // очистка последней нажатой клавиши
  for (i=0; i<cnt; i++)
    if (KEYS_scannow())
      break;
}    
