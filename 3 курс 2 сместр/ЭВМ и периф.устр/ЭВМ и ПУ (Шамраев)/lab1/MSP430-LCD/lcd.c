// LCD-display functions
#include "function_prototype.h"
#include "sysfunc.h"
#include "lcd.h"

//������� ���������
char LCD_table[64]={
                      0x41,0xA0,0x42,0xA1,    //0xC0...0xC3 <=> � � � �
                      0xE0,0x45,0xA3,0x33,    //0xC4...0xC7 <=> � � � �
                      0xA5,0xA6,0x4B,0xA7,    //0xC8...0xCB <=> � � � �
                      0x4D,0x48,0x4F,0xA8,    //0xCC...0xCF <=> � � � �

                      0x50,0x43,0x54,0xA9,    //0xD0...0xD4 <=> � � � �
                      0xAA,0x58,0xE1,0xAB,    //0xD5...0xD7 <=> � � � �
                      0xAC,0xE2,0xAC,0xAE,    //0xD8...0xDB <=> � � � � 
                      0x62,0xAF,0xB0,0xB1,    //0xDC...0xDF <=> � � � �

                      0x61,0xB2,0xB3,0xB4,    //0xE0...0xE4 <=> � � � �
                      0xE3,0x65,0xB6,0xB7,    //0xE5...0xE7 <=> � � � �
                      0xB8,0xA6,0xBA,0xBB,    //0xE8...0xEB <=> � � � �
                      0xBC,0xBD,0x6F,0xBE,    //0xEC...0xEF <=> � � � �

                      0x70,0x63,0xBF,0x79,    //0xF0...0xE4 <=> � � � �
                      0xE4,0xD5,0xE5,0xC0,    //0xF5...0xE7 <=> � � � �
                      0xC1,0xE6,0xC2,0xC3,    //0xF8...0xEB <=> � � � �
                      0XC4,0xC5,0xC6,0xC7     //0xFC...0xEF <=> � � � �
};

byte LCD_row, LCD_col, n;

void LCD_init()
{
  wait_1ms(20);   // ����� 20 �� ����� ��������� ������
  P3DIR |= (D_nC_LCD + EN_LCD); // ��������� �����, ������� ��������� LCD �� �����
  Reset_EN_LCD(); //  ��������� ������ "���������� ��������� � ������ LCD" � ���������� ���������

// ������� Function Set         0 0 1 DL N F * *
//    ��������� ����������� ���������� DL=1 =>8, ��� DL=0 =>4 ���
//    N=1 => ��� ������ ��������, N=0 => ���� ������ ��������
//    F=0 => ������ ������ 5�11 �����, F=1 => ������ ������ 5�8 �����
// ����� ������ �������� ������ ��� LCD � ����� ����� ��� �������� ����� ����� BF
  LCD_WriteCommand(0x3C);
   wait_1ms(1);

  LCD_WriteCommand(0x3C);
  wait_1ms(1);
  
// ������� Display ON/OFF control 0 0 0  0 1 D C B
//    �������� ������ D=1 � �������� ��� ������� (C,D)
//    C=0, B=0 - ������� ���, ������ �� ������
//    C=0, B=1 - ������� ���, ������ ���� ������ � ������� �������
//    C=1, B=0 - ������� ���� (�������������), ������ �� ������
//    C=1, B=1 - ������� ���� (�������������), � ������ �� � ������
  LCD_WriteCommand(0x0C); 

  LCD_clear();

// ������� Entry Mode Set        0 0 0 0 0 1 ID SH
//    ��������� ����������� ������ ������� ID=0/1 - ����� �����/������
//    � ���������� ������ ������� SH=1 ��� ������ � DDRAM
  LCD_WriteCommand(0x06);
}


//����� ��������� �� LCD �������
void LCD_message(const char * buf)
{
  n = 0;
  while (buf[n])
  {
     // ���� ������� �� ������� ������ - ������� �� ���������
    if ( (LCD_row < LCD_MAXROWS-1) && (LCD_col >= LCD_MAXCOLS) )
      LCD_set_pos(++LCD_row, 0);
    if (LCD_col >= LCD_MAXCOLS )
      LCD_set_pos(0,0); // ���� ����� �� ������� ������ - �������� � ������
//      break;          // ��� ���� ����� �� ������� ������ - ��������� �������� �������
    LCD_WriteData( LCD_recode(buf[n]) );
    LCD_col++;
    n++;
  }
}


// ������� ������� ������
void LCD_clear()
{
  // ������� Clear Display         0 0 0 0 0 0 0 1
  //    ������� ������ � �������� ������ � ����� ����� �������
  LCD_WriteCommand(0x01);
  LCD_row=0;
  LCD_col=0;
}


// ��������� ������� �������:
//    row - ����� ������ (0...1)
//    col - ����� ������� (0...15)
void LCD_set_pos(byte row, byte col)
{
  if (row > LCD_MAXROWS-1)         // �������� �� ������������ ��������
    row = LCD_MAXROWS-1;
  if (col > LCD_MAXCOLS-1)         // �������� �� ������������ ��������
    col = LCD_MAXCOLS-1;
  LCD_row = row;
  LCD_col = col;
  LCD_WriteCommand( BIT7 | ((0x40 * LCD_row) + LCD_col) );
}


byte LCD_get_row()
{
  return LCD_row;
}


byte LCD_get_col()
{
  return LCD_col;
}


// �������� ������ ����������� �������:
//    0 - ������� ���, ������ �� ������
//    1 - ������� ���, ������ ���� ������ � ������� �������
//    2 - ������ ����(�������������), ������ �� ������
//    3 - ������ ����(�������������) � ������ �� ������
void LCD_set_cursor(byte cursor)
{
  if (cursor > 3)             // �������� �� ������������ ��������
    cursor = 2;
  LCD_WriteCommand(cursor | BIT2 | BIT3);   // ��������� ������� Display ON/OFF Control
                                            //  � ������ ������� ����������� �������
}


void LCD_WriteCommand(char byte)
{
// ����� ������ �������� ������ ��� LCD � ����� �����
    LCD_WriteByte(byte, 0);   // 
}


void LCD_WriteData(char byte)
{
// ����� ������ �������� ������ LCD � ����� �����
    LCD_WriteByte(byte, 1);
}


// ����� ����� �� ���������, ���������:
//    byte - ��������� ����
//    dnc=0 - ����� �������� ������, dnc=1 - ������
void LCD_WriteByte(char byte, char D_nC)
{

  DB_DIR = 0x00;      // ���� ������ �� �����
  Set_MCU_SEL_0();    // ����� ������ LCD 				MCU_SEL_0 = 1
  Set_MCU_SEL_1();    // ��� ������ ����������� DD7		MCU_SEL_0 = 1
  	  	  	  	  	  //										_
  Reset_D_nC_LCD();   // ����� ������ �������� ������ ��� LCD D/C_LCD = 0
  	  	  	  	  	  //	   __ ___				  _
  Set_nWR_nRST();  	  // C���� WR/RST = 1 => ������ R/W_LCD = 1, �.�. � ���������� ���������

  	  	  	  	  	  //								__
  Reset_nSS();        // ������������ ����� "OE_BF_LCD" SS = 0

  	  	  	  	  	  //													_____
  Set_EN_LCD();       // ������������ ����� ������ ��� LCD  EN_LCD = 1		|	|
  Set_EN_LCD();       // ������������ ����� ������ ��� LCD  EN_LCD = 1		|	|
  Set_EN_LCD();       // ������������ ����� ������ ��� LCD  EN_LCD = 1	____|	|_____

  while (DB_IN & BIT7); // �������� ������ ����� ��������� BUSY
  Reset_EN_LCD();       // ��������� ������ "EN_LCD_OUT" � ���������� ��������� EN_LCD = 0
  	  	  	  	  	  	//													   __
  Set_nSS(); 	        // ��������� ������ "OE_BF_LCD" � ���������� ��������� SS = 1

  if (D_nC) Set_D_nC_LCD();   // ������� ����� ������ ������ (D_nC = 1)
  else Reset_D_nC_LCD();      //   ��� ������ ������� (D_nC = 0)
  	  	  	  	  	  	//					  __ ___		  _
  Reset_nWR_nRST(); 	// ������������ ����� WR/RST = 0 => R/W_LCD = 0
  	  	  	  	  	  	//								  __
  Reset_nSS();        	// ������������ ����� "OE_BF_LCD" SS = 0
  DB_DIR = 0xFF;    	// ���� ������ �� �����
  DB_OUT = byte;    	// ��������� ������ �� ���� ������
  	  	  	  	  	  	//														_____
  Set_EN_LCD();         // ������������ ����� ������ ��� LCD  EN_LCD = 1		|	|
  Set_EN_LCD();         // ������������ ����� ������ ��� LCD  EN_LCD = 1		|	|
  Set_EN_LCD();         // ������������ ����� ������ ��� LCD  EN_LCD = 1	____|	|_____
  Reset_EN_LCD();       // ��������� ������ "EN_LCD_OUT" � ���������� ��������� EN_LCD = 0

  	  	  	  	  	  	//					 								    __
  Set_nSS(); 	        // ��������� ������ OE_BF_LCD =1 � ���������� ��������� SS = 1
  DB_DIR = 0x00;	    // ���� ������ �� ����
  	  	  	  	  	    //		 __ ___				  	_
  Set_nWR_nRST();  	    // C���� WR/RST = 1 => ������ R/W_LCD = 1, �.�. � ���������� ���������

}


//������� ������������� ������� � ���������
char LCD_recode(char b)
{
  if (b<192) return b;
    else return LCD_table[b-192];
}
