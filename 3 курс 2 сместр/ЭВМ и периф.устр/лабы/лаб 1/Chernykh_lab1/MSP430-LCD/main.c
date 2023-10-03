#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;

  Init_System();

  Init_System_Clock();

  LCD_init();
  LCD_clear();

  LCD_WriteCommand(0x40);

  // LCD_set_cursor(1);

  char data[] =
  {
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  char data2[] =
  {
    0b00000000,
    0b00000010,
    0b00000010,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  char data3[] =
  {
    0b00000000,
    0b00001000,
    0b00001000,
    0b00000000,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000000
  };

  int i;
  for (i = 0; i < 8; i++)
    LCD_WriteData(data[i]);
  for (i = 0; i < 8; i++)
    LCD_WriteData(data2[i]);
  for (i = 0; i < 8; i++)
    LCD_WriteData(data3[i]);

  word ms = 100;
  while(0b1)
  {
      LCD_set_pos(0, 0);
      LCD_WriteData(0);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(1);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(0);
      wait_1ms(ms);

      LCD_set_pos(0, 0);
      LCD_WriteData(2);
      wait_1ms(ms);
  }

  /*
  char row1[] = "Ситников";
  char row2[] = "ВТ-32";

  LCD_message(row1);

  LCD_set_pos(1, 0);

  LCD_message(row2);
  */
}
