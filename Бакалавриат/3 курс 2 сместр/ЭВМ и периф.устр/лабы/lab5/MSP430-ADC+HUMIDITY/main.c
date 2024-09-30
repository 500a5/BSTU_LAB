#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */

char message[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;

    Init_System();
    Init_System_Clock();

    Init_I2C();
    __enable_interrupt();

    LCD_init();

    while(1)
    {
        sprintf(message, "RH = %g %%", HIH_get_hum());

        LCD_message(message);

        wait_1ms(750);
        LCD_clear();
    }
}
