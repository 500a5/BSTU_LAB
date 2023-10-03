#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */
// speed = 0 - �������� ������
// databits = 8 - ������ �������
// stopbits = 1, 2 - ���-�� ������������ �������� ���
// parity = 0 - ��� �������� ��������
// iface = 0 - USB
void main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    Init_System_Clock();
    Init_System();
    //char s[50];
    char i;
    char j = 20;
    UART_init(0, 8, 1, 0, 0);
    while(1)
    {
        for(i = 0; i <= 50; i++)
        {
            UART_sendbyte(j);
            j++;
        }
        UART_off();
    }

}
