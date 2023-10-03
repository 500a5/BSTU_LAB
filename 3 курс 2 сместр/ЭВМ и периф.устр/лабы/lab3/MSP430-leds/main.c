#include <msp430.h> 
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "I2C.h"
#include "main.h"

/*
 * main.c
 */

void main(void) {
    _enable_interrupt();
    WDTCTL = WDTPW+WDTHOLD;
    Init_System_Clock();
    Init_System();
    Init_I2C();
    LED_clear();
    char key;
    int f = 0;
    Init_I2C();
    I2CSCLH = 0x26; //38 + 2 = 40
    I2CSCLL = 0x26; //38 + 2 = 40
  //  40*2=80
  //  8 000 000 / 80 = 30 000 Гц

    while (f != 1) {
        key = KEYS_scannow();
        switch (key) {
        case '9':
            LED_clear();
            LED_set(1);
            break;
        case '0':
            LED_clear();
            LED_set(2);
            break;
        case '1':
            LED_clear();
            LED_set(3);
            break;
        case '*':
            f = 1;
        }
    }

    while(1){
    }
}