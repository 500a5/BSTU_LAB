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
    Init_System_Clock();
    Init_System();



    char ser[] = "Kholodov";
    char name[] = "Anton";
    LCD_init();
    LCD_set_cursor(1);

    LCD_clear();
    LCD_set_pos(0,0);
    LCD_message(ser);
    LCD_set_pos(1,0);
    LCD_message(name);

    byte smile[8] = {
                      0b00000001,
                      0b00000001,
                      0b00000001,
                      0b00011111,
                      0b00001110,
                      0b00011111,
                      0b00001110,
                      0b00011111
    };
    char i;
    for (i=0; i<8 ; i++)
    {
        LCD_WriteCommand(0x40+i);
        LCD_WriteData(smile[i]);
    }
    LCD_set_pos(1,11);
    LCD_WriteData(0);


    while(1)
    {
    }


}
