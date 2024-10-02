/******************************************************************************/              
#ifndef __FUNCTION_PROTOTYPE_H__
#define __FUNCTION_PROTOTYPE_H__
#include "system_define.h"
/******************************************************************************/              


/******************************* I2C.c **************************************/
void Init_I2C();
void Send_I2C(unsigned char* buffer,unsigned int num, unsigned char address);
void Receive_I2C(unsigned char* buffer,unsigned int num, unsigned char address);
void I2C_SendByte(char data, char i2c_addr);
void I2C_WriteByte(char reg, char data, char i2c_addr);
byte I2C_ReadByte(char reg, char i2c_addr);
int I2C_ReadWord(char reg, char i2c_addr);
/******************************************************************************/              


/******************************** sysfunc.c ***********************************/
void Init_System();
void Init_System_Clock();
void wait_1ms(word cnt);
void wait_1mks(word cnt);
/******************************************************************************/              

/******************************** TIMERA.c ************************************/
/******************************************************************************/

/******************************** TIMERB.c ************************************/
/******************************************************************************/

/********************************* USART.c ************************************/
void UART_init(byte speed, byte databits, byte stopbits, byte parity, byte iface);
void UART_off();
void UART_sendbyte(char byte);
void UART_message(char * buf);
char UART_getbyte();
/******************************************************************************/

/********************************* leds.c ************************************/
char LED_convert(char led);
void LED_out(char leds);
void LED_clear();
void LED_invert();
void LED_set(char led);
void LED_reset(char led);
void LED_change(byte led);
void LED_fx1(int n);
void LED_fx2(int n);
void LED_fx3(int n);
/******************************************************************************/

/********************************* key.c ************************************/
char KEYS_scannow();
char KEYS_lastkey();
void KEYS_clear();
char KEYS_waitkey();
void KEYS_pause(byte cnt);
/******************************************************************************/

/********************************* lcd.c ************************************/
void LCD_init();
void LCD_clear();
void LCD_set_pos(byte row, byte col);
byte LCD_get_row();
byte LCD_get_col();
void LCD_set_cursor(byte nMode);
void LCD_message(const char* buf);

char LCD_recode(char b);
void LCD_WriteData(char byte);
void LCD_WriteCommand(char byte);
void LCD_WriteByte(char byte, char dnc);
/******************************************************************************/


#endif
