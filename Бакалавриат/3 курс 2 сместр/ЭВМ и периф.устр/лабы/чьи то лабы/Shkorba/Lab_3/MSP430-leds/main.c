#include <msp430.h> 
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */

#pragma vector=PORT1_VECTOR
__interrupt void KEYS_interrupt()
{
    char KEYS_last;
    char f = 1;
    if(P1IFG&BIT7)
    {
        P1IE |= BIT7;
        P1IFG &= !BIT7;
        P1IES |= BIT7;
        I2C_WriteByte(0x00, 0xFF, 0x73);
        I2C_WriteByte(0x03, 0xFF, 0x73);
        _enable_interrupt();
        while(f){
                KEYS_last = KEYS_waitkey();
                switch(KEYS_last){
                case '1':
                   LED_set(1);
                   wait_1ms(500);
                   LED_reset(1);
                   break;
                case '6':
                   LED_set(2);
                   wait_1ms(500);
                   LED_reset(2);
                   break;
                case '8':
                   LED_set(3);
                   wait_1ms(500);
                   LED_reset(3);
                   break;
                case '*':
                   f = 0;
                   break;
                }
            }
            _disable_interrupt();
    }

}


void main(void) {
    _enable_interrupt();
    WDTCTL = WDTPW + WDTHOLD;
    Init_System_Clock();
    Init_System();
    Init_I2C();
    char f = 1;
    I2C_WriteByte(0x00, 0x0F, 0x73);
    I2C_WriteByte(0x03, 0x0F, 0x73);
    while(f){
        KEYS_last = KEYS_waitkey();
                switch(KEYS_last){
                case '1':
                    LED_set(1);
                    wait_1ms(500);
                    LED_reset(1);
                    break;
                case '6':
                    LED_set(2);
                    wait_1ms(500);
                    LED_reset(2);
                    break;
                case '8':
                    LED_set(3);
                    wait_1ms(500);
                    LED_reset(3);
                    break;
                case '*':
                    f = 0;
                    break;
                }
    }
}
