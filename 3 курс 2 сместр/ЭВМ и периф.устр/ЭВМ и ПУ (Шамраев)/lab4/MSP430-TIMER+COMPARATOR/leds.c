// LED-indicator functions

#include "function_prototype.h"
#include "sysfunc.h"
#include "leds.h"

char LED_config=0;                  // хранитс€ конфигураци€ светодиодов (вкл/выкл)

void LED_out(char leds)
{
  // регистр конфигурации направлени€ 0x03 конфигурируем на вывод информации (1-ввод, 0-вывод)
  I2C_WriteByte(0x03, 0x00, LED_i2c_addr);
  I2C_WriteByte(0x01, leds, LED_i2c_addr);    // выводим данные в регистр OUTPUT (0x01)
  LED_config=leds;                // сохран€ем новую конфигурацию
}


// ѕреобразование номера светодиода в бит, с которым нужно проводить операцию
// 1 = 10000000, 2 = 01000000 ... 8 = 00000001
char LED_convert(char led)
{
  if(led<1)
    led=1;
  if(led>8)
    led=8;
  led=9-led;
  return (1<<(led-1));
}


// ¬ыключить все светодиоды
void LED_clear()
{
  LED_out(0x00);
}


// »нвертировать все светодиоды
void LED_invert()
{
  LED_out(LED_config ^ 0xff);
}


// ¬ключить светодиод с номером от 1 до 8 (слева направо)
void LED_set(char led)
{
  led=LED_convert(led);
  LED_config |= led;      // устанавливаем соответствующий разр€д
  LED_out(LED_config);    // выводим в регистр
}


// ¬ыключить светодиод с номером от 1 до 8 (слева направо)
void LED_reset(char led)
{
  led=LED_convert(led);
  LED_config &= ~(led);   // сбрасываем соответствующий разр€д
  LED_out(LED_config);    // выводим в регистр
}


// —менить состо€ние светодиода с номером от 1 до 8 (слева направо)
void LED_change(byte led)
{
  led=LED_convert(led);
  LED_config ^= led;      // мен€ем состо€ние соответствующего разр€да (XOR)
  LED_out(LED_config);    // выводим в регистр
}


void LED_fx1(int n)
{
  LED_clear();
  LED_set(1);
  wait_1ms(n);
  LED_set(3);
  wait_1ms(n);
  LED_set(5);
  wait_1ms(n);
  LED_set(7);
  wait_1ms(n);
  LED_reset(1);
  wait_1ms(n);
  LED_reset(3);
  wait_1ms(n);
  LED_reset(5);
  wait_1ms(n);
  LED_reset(7);
  wait_1ms(n);
  LED_clear();
}


void LED_fx2(int n)
{
  LED_clear();
  LED_out(0x81);
  wait_1ms(n);
  LED_out(0x42);
  wait_1ms(n*8);
  LED_out(0x24);
  wait_1ms(n*5);
  LED_out(0x18);
  wait_1ms(n*3);

  LED_out(0x24);
  wait_1ms(n*5);
  LED_out(0x42);
  wait_1ms(n*8);
  LED_clear();
}


void LED_fx3(int n)
{
  LED_clear();
  LED_out(0x01);
  wait_1ms(n*6);
  LED_out(0x02);
  wait_1ms(n*4);
  LED_out(0x04);
  wait_1ms(n*2);
  LED_out(0x08);
  wait_1ms(n*1);
  LED_out(0x10);
  wait_1ms(n*1);
  LED_out(0x20);
  wait_1ms(n*2);
  LED_out(0x40);
  wait_1ms(n*4);
  LED_out(0x80);
  wait_1ms(n*6);

  LED_out(0x40);
  wait_1ms(n*4);
  LED_out(0x20);
  wait_1ms(n*2);
  LED_out(0x10);
  wait_1ms(n*1);
  LED_out(0x08);
  wait_1ms(n*1);
  LED_out(0x04);
  wait_1ms(n*2);
  LED_out(0x02);
  wait_1ms(n*4);
  LED_clear();
}
