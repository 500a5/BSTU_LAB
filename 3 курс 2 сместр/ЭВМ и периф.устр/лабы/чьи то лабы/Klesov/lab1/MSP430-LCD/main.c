#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"


void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
        Init_System_Clock();
        Init_System();
        LCD_init();

        char name[] = "������ ��";
        char group[] = "��-31";
        LCD_set_cursor(0);
        LCD_message(name);
        LCD_set_pos(1,0);
        LCD_message(group);

        char oplus[8] = {0b00000000,
                        0b00000000,
                        0b00001110,
                        0b00010101,
                        0b00011111,
                        0b00010101,
                        0b00001110,
                        0b00000000};

        char i;

            for(i=0; i<8; i++)
            {
                LCD_WriteCommand(0x40 + i);
                LCD_WriteData(oplus[i]);
            }
        LCD_set_pos(1,8);
        LCD_WriteData(0);

        while(1){

        }
}
