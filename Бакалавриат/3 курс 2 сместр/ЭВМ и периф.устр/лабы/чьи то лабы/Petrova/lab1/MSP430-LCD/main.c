#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    Init_System_Clock();
    Init_System();

    char* name = "Îכüדא Ïוענמגא";
    char* group = "ÂÒ-31";

    LCD_init();

    LCD_set_pos(0,0);
    LCD_message(name);
    LCD_set_pos(1,0);
    LCD_message(group);

    LCD_set_pos(1,0);
    LCD_set_cursor(3);

    while(1);
}
