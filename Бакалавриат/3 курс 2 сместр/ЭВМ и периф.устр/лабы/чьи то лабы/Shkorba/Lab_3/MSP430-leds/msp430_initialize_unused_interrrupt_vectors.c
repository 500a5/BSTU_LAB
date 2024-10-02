#include <msp430.h>
/* Initialize non-used ISR vectors with a trap function */
/*
DACDMA_VECTOR           (0 * 1u)       0xFFE0 DAC/DMA
PORT2_VECTOR            (1 * 1u)       0xFFE2 Port 2
USART1TX_VECTOR         (2 * 1u)       0xFFE4 USART 1 Transmit
USART1RX_VECTOR         (3 * 1u)       0xFFE6 USART 1 Receive
PORT1_VECTOR            (4 * 1u)       0xFFE8 Port 1
TIMERA1_VECTOR          (5 * 1u)       0xFFEA Timer A CC1-2, TA
TIMERA0_VECTOR          (6 * 1u)       0xFFEC Timer A CC0
ADC12_VECTOR            (7 * 1u)       0xFFEE ADC
USART0TX_VECTOR         (8 * 1u)       0xFFF0 USART 0 Transmit  // Прерывание используется
USART0RX_VECTOR         (9 * 1u)       0xFFF2 USART 0 Receive   // Прерывание используется
WDT_VECTOR              (10 * 1u)      0xFFF4 Watchdog Timer
COMPARATORA_VECTOR      (11 * 1u)      0xFFF6 Comparator A
TIMERB1_VECTOR          (12 * 1u)      0xFFF8 Timer B CC1-6, TB
TIMERB0_VECTOR          (13 * 1u)      0xFFFA Timer B CC0
NMI_VECTOR              (14 * 1u)      0xFFFC Non-maskable
RESET_VECTOR            (15 * 1u)      0xFFFE Reset [Highest Priority]
*/

#pragma vector=DACDMA_VECTOR,PORT2_VECTOR,USART1TX_VECTOR,USART1RX_VECTOR,TIMERA1_VECTOR,  \
               TIMERA0_VECTOR,ADC12_VECTOR,WDT_VECTOR,COMPARATORA_VECTOR,TIMERB1_VECTOR,TIMERB0_VECTOR, \
               NMI_VECTOR,RESET_VECTOR
__interrupt void ISR_trap(void)
{
  // Вызов неиспользуемого прерывания приведет к сбросу процессора (PUC reset)
  WDTCTL = 0; 
}
