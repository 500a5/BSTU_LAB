#include <msp430.h> 
#include "stdio.h"
#include "system_define.h"
#include "system_variable.h"
#include "function_prototype.h"
#include "main.h"

/*
 * main.c
 */

char robot[][8]={
                 {
                    0b00000000,
                    0b00000010,
                    0b00000100,
                    0b00001000,
                    0b00000100,
                    0b00000010,
                    0b00000000,
                    0b00000000
},
{
                    0b00000100,
                    0b00000100,
                    0b00000100,
                    0b00000100,
                    0b00000100,
                    0b00000100,
                    0b00000100,
                    0b00000100
},
{
                    0b00000000,
                    0b00000100,
                    0b00001010,
                    0b00000100,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000
},
{
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000111,
                    0b00000000
},
{
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00011100,
                    0b00000000
},
{
                    0b00000000,
                    0b00000100,
                    0b00001010,
                    0b00000100,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000
},
{
                    0b00010000,
                    0b00010000,
                    0b00010000,
                    0b00010000,
                    0b00010000,
                    0b00010000,
                    0b00010000,
                    0b00010000
},
{
                     0b00000000,
                     0b00001000,
                     0b00000100,
                     0b00000010,
                     0b00000100,
                     0b00001000,
                     0b00000000,
                     0b00000000
}};

void Disable_Watchdog(){
    WDTCTL = WDTPW+WDTHOLD; // Disable watchdog timer
}

void Print_Message(char *buf){
    int cur_row = 0;
    int start = 0;
    LCD_set_pos(cur_row, 0);
    int n = 0;
    while (buf[n]){
        if (buf[n] == '\n'){
            if (cur_row > 0){
                return;
            }
            cur_row++;
            buf[n] = 0;
            LCD_message(&(buf[start]));
            start = n+1;
            LCD_set_pos(cur_row, 0);
        }
        n++;
    }
    if (cur_row <= 1){
        LCD_message(&(buf[start]));
    }
}



void main(void) {
    Disable_Watchdog();
    Init_System_Clock(8); // Start generators
    Init_System();      // Set port1 to output
    LCD_init();         // Set ports for LCD
    LCD_clear();
    char msg[80] = "ÂÒ-31\nÔàðàêøèí Í.Ð.";
    Print_Message(msg);   // Output message
    wait_1ms(300);
    int i, j;
    for (i = 0; i<8; i++){
        for (j = 0; j<8; j++){
            LCD_WriteCommand(0x40 + i*8 + j);
            LCD_WriteData(robot[i][j]);
        }
    }
    LCD_set_pos(0, 0);
    while(1){
        LCD_WriteCommand(0x18); // Shift
        for (i = 0; i<8; i++){
            LCD_WriteData(i);
        }
        wait_1ms(150);
    }
}
