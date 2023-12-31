// UART functions
#include "function_prototype.h"
#include "sysfunc.h"
#include "uart.h"

// ������������� ������ UART
// databits = 7, 8 - ������ �������
// stopbits = 1, 2 - ���-�� ������������ �������� ���
// parity = 0 - ��� �������� ��������, 1 - �������� ��������, �������, 2 - ������
// iface = 0 - USB, 1 - ������
void UART_init(byte databits, byte stopbits, byte parity, byte iface)
{
  P3SEL |= BIT6 | BIT7;       // ����� ������� USART1
  U1CTL = 0;                  // ������������� ��������� USART
  ME2 |= UTXE1 + URXE1;       // �������� �������� � ���������� USART1

  if (databits == 7) U1CTL &= ~CHAR;        // 7-��������� ������ �������
  if (databits == 8) U1CTL |= CHAR;         // 8-��������� ������ �������
  if (stopbits == 1) U1CTL &= ~SPB;         // 1 �������� ���
  if (stopbits == 2) U1CTL |= SPB;          // 1 �������� ����
  if (parity == 0) U1CTL &= ~PENA;          // �������� �������� ��������
  if (parity == 1) U1CTL = (U1CTL & ~PEV) | PENA; // �������� ��������, ��������
  if (parity == 2) U1CTL |= PENA | PEV;     // �������� ��������, ������

  P5DIR |= BIT0;             // ������������ �������������� �� USB/������
  if (iface == 0)
    P5OUT |= BIT0;
  if (iface == 1)
    P5OUT &= ~BIT0;    

  U1TCTL &= ~SSEL1;                          // BRCLK = ACLK, ACLK=01
  U1TCTL |= SSEL0;
  // ��������� U1BR1..U1BR0 � 109
  U1BR1 = 0x00;
  U1BR0 = 109;
  U1MCTL = 68;                            // ���������
//  U1BR1 = 0x00;
//  U1BR0 = 0x02;
//  U1MCTL = 0x88;
}


// ���������� ������ UART
void UART_off()
{
  P3SEL |= BIT6 | BIT7;       // ����� ������� USART1
  ME2 &= ~(UTXE1 + URXE1);    // ��������� �������� � ���������� USART1
  U1CTL = SWRST;              // ���������� USART1
}


// ����� ������ �������� (������ � ����� 0 - ����� ������)
void UART_message(char * buf)
{
  word i=0;
  while (buf[i])
    UART_sendbyte(buf[i++]);    // �������� ������
}


// �������� �����
void UART_sendbyte(char byte)
{
  while (!(IFG2 & UTXIFG1));    // �������� ���������� ������ �������� USART1
  U1TXBUF = byte;               // �������� �����
}


// ��������� �����
char UART_getbyte()
{
  while (!(IFG2 & URXIFG1));    // �������� ���������� ������ ������ USART1
  return U1RXBUF;               // ������� ����������� �����
}
