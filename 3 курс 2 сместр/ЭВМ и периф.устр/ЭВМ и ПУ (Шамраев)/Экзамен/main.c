#include <msp430.h>
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"

void timer_A_init(){
    TACTL = TASSEL0 + MC0; // (SSEL = 01) ACLK - 32768 Гц и режим вверх
    // в режиме вверх период прерываний равен TACCR0 + 1
    TACCR0 = 32767; // - 1 секунда (32768 тиков в секунду)
    TACCTL0 = CCIE; // разрешить прерывание от TACCR0
}

unsigned int k = 1;
void main(void) {
WDTCTL = WDTPW + WDTHOLD; // Остановка watchdog timer
    // Запустить тактирование
    volatile byte i;
    BCSCTL1 &= ~XT2OFF;                       // включение осцилятора XT2
                                              // MCLK = XT2, SMCLK = XT2
    do                                        // ожидание запуска кварца
    {
        IFG1 &= ~OFIFG;                       // Clear OSCFault flag
        for (i = 0xFF; i > 0; i--);           // Time for flag to set
    }
    while ((IFG1 & OFIFG));                   // OSCFault flag still set?
    BCSCTL2 |= SELM_2 | SELS;                 // установка внешнего модуля тактирования
    __enable_interrupt(); //разрешение глобальных прерываний (бит GIE)
    P1DIR = 255; // P1 настраиваем на вывод
    P2DIR = 0; // P2 настраиваем на ввод
    timer_A_init();
    while(1); // Пустой цикл для работы программы
}

// обработчик прерываний от таймера А
#pragma vector=TIMERA0_VECTOR
__interrupt void timer_A_interrupt(void){
    P1OUT = P2IN; //из регистра ввода порта 2 записываем в регистр вывода порта 1
    // флаг прерывания сбрасывается автоматически
}