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
    //v3, speed 57600, 20 chisel (10-29), 7 bit
    WDTCTL = WDTPW | WDTHOLD;
    Init_System_Clock();
    Init_System();
    UART_init(2, 7, 1, 0, 0);
    int i;
    for(i=10; i<30; i++){
        UART_sendbyte(i);
    }
    UART_off();
    while(1);
}
