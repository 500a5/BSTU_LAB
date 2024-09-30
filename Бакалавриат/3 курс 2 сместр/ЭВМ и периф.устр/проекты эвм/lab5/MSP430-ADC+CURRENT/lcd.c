// LCD-display functions
#include "function_prototype.h"
#include "sysfunc.h"
#include "lcd.h"

//Таблица киррилицы
char LCD_table[64]={
                      0x41,0xA0,0x42,0xA1,    //0xC0...0xC3 <=> А Б В Г
                      0xE0,0x45,0xA3,0x33,    //0xC4...0xC7 <=> Д Е Ж З
                      0xA5,0xA6,0x4B,0xA7,    //0xC8...0xCB <=> И Й К Л
                      0x4D,0x48,0x4F,0xA8,    //0xCC...0xCF <=> М Н О П

                      0x50,0x43,0x54,0xA9,    //0xD0...0xD4 <=> Р С Т У
                      0xAA,0x58,0xE1,0xAB,    //0xD5...0xD7 <=> Ф Х Ц Ч
                      0xAC,0xE2,0xAC,0xAE,    //0xD8...0xDB <=> Ш Щ Ъ Ы 
                      0x62,0xAF,0xB0,0xB1,    //0xDC...0xDF <=> Ь Э Ю Я

                      0x61,0xB2,0xB3,0xB4,    //0xE0...0xE4 <=> а б в г
                      0xE3,0x65,0xB6,0xB7,    //0xE5...0xE7 <=> д е ж з
                      0xB8,0xA6,0xBA,0xBB,    //0xE8...0xEB <=> и й к л
                      0xBC,0xBD,0x6F,0xBE,    //0xEC...0xEF <=> м н о п

                      0x70,0x63,0xBF,0x79,    //0xF0...0xE4 <=> р с т у
                      0xE4,0xD5,0xE5,0xC0,    //0xF5...0xE7 <=> ф х ц ч
                      0xC1,0xE6,0xC2,0xC3,    //0xF8...0xEB <=> ш щ ъ ы
                      0XC4,0xC5,0xC6,0xC7     //0xFC...0xEF <=> ь э ю я
};

byte LCD_row, LCD_col, n;

void LCD_init()
{
  wait_1ms(20);   // пауза 20 мс после включения модуля
  P3DIR |= (D_nC_LCD + EN_LCD); // Настроить порты, которые управляют LCD на вывод
  Reset_EN_LCD(); //  Перевести сигнал "Разрешение обращений к модулю LCD" в неактивное состояние

// Команда Function Set         0 0 1 DL N F * *
//    установка разрядности интерфейса DL=1 =>8, бит DL=0 =>4 бит
//    N=1 => две строки символов, N=0 => одна строка символов
//    F=0 => размер шрифта 5х11 точек, F=1 => размер шрифта 5х8 точек
// Выбор режима передачи команд для LCD и вывод байта без ожидание броса влага BF
  LCD_WriteCommand(0x3C);
   wait_1ms(1);

  LCD_WriteCommand(0x3C);
  wait_1ms(1);
  
// Команда Display ON/OFF control 0 0 0  0 1 D C B
//    включает модуль D=1 и выбирает тип курсора (C,D)
//    C=0, B=0 - курсора нет, ничего не мигает
//    C=0, B=1 - курсора нет, мигает весь символ в позиции курсора
//    C=1, B=0 - курсора есть (подчеркивание), ничего не мигает
//    C=1, B=1 - курсора есть (подчеркивание), и только он и мигает
  LCD_WriteCommand(0x0C); 

  LCD_clear();

// Команда Entry Mode Set        0 0 0 0 0 1 ID SH
//    установка направления сдвига курсора ID=0/1 - сдвиг влево/вправо
//    и разрешение сдвига дисплея SH=1 при записи в DDRAM
  LCD_WriteCommand(0x06);
}


//Вывод сообщение на LCD дисплей
void LCD_message(const char * buf)
{
  n = 0;
  while (buf[n])
  {
     // если выходим за границу строки - переход на следующую
    if ( (LCD_row < LCD_MAXROWS-1) && (LCD_col >= LCD_MAXCOLS) )
      LCD_set_pos(++LCD_row, 0);
    if (LCD_col >= LCD_MAXCOLS )
      LCD_set_pos(0,0); // если вышли за границы экрана - начинаем с начала
//      break;          // или если вышли за границы экрана - перестаем выводить символы
    LCD_WriteData( LCD_recode(buf[n]) );
    LCD_col++;
    n++;
  }
}


// Функция очистки экрана
void LCD_clear()
{
  // Команда Clear Display         0 0 0 0 0 0 0 1
  //    очищает модуль и помещает курсор в самую левую позицию
  LCD_WriteCommand(0x01);
  LCD_row=0;
  LCD_col=0;
}


// Установка позиции курсора:
//    row - номер строки (0...1)
//    col - номер столбца (0...15)
void LCD_set_pos(byte row, byte col)
{
  if (row > LCD_MAXROWS-1)         // проверка на неправильные значения
    row = LCD_MAXROWS-1;
  if (col > LCD_MAXCOLS-1)         // проверка на неправильные значения
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


// Устновка режима отображения курсора:
//    0 - курсора нет, ничего не мигает
//    1 - курсора нет, мигает весь символ в позиции курсора
//    2 - курсор есть(подчеркивание), ничего не мигает
//    3 - курсор есть(подчеркивание) и только он мигает
void LCD_set_cursor(byte cursor)
{
  if (cursor > 3)             // проверка на неправильные значения
    cursor = 2;
  LCD_WriteCommand(cursor | BIT2 | BIT3);   // Выполняем команду Display ON/OFF Control
                                            //  с нужным режимом отображения курсора
}


void LCD_WriteCommand(char byte)
{
// Выбор режима передачи команд для LCD и вывод байта
    LCD_WriteByte(byte, 0);   // 
}


void LCD_WriteData(char byte)
{
// Выбор режима передачи данных LCD и вывод байта
    LCD_WriteByte(byte, 1);
}


// Вывод байта на индикатор, параметры:
//    byte - выводимый байт
//    dnc=0 - режим передачи команд, dnc=1 - данных
void LCD_WriteByte(char byte, char D_nC)
{

  DB_DIR = 0x00;      // Шина данных на прием
  Set_MCU_SEL_0();    // Выбор модуля LCD 				MCU_SEL_0 = 1
  Set_MCU_SEL_1();    // при помощи дешифратора DD7		MCU_SEL_0 = 1
  	  	  	  	  	  //										_
  Reset_D_nC_LCD();   // Выбор режима передачи команд для LCD D/C_LCD = 0
  	  	  	  	  	  //	   __ ___				  _
  Set_nWR_nRST();  	  // Cигал WR/RST = 1 => сигнал R/W_LCD = 1, т.е. в неактивном состоянии

  	  	  	  	  	  //								__
  Reset_nSS();        // Сформировать сигал "OE_BF_LCD" SS = 0

  	  	  	  	  	  //													_____
  Set_EN_LCD();       // Сформировать строб данных для LCD  EN_LCD = 1		|	|
  Set_EN_LCD();       // Сформировать строб данных для LCD  EN_LCD = 1		|	|
  Set_EN_LCD();       // Сформировать строб данных для LCD  EN_LCD = 1	____|	|_____

  while (DB_IN & BIT7); // ожидание сброса флага занятости BUSY
  Reset_EN_LCD();       // Перевести сигнал "EN_LCD_OUT" в неактивное состояние EN_LCD = 0
  	  	  	  	  	  	//													   __
  Set_nSS(); 	        // Перевести сигнал "OE_BF_LCD" в неактивное состояние SS = 1

  if (D_nC) Set_D_nC_LCD();   // Выбрать режим записи данных (D_nC = 1)
  else Reset_D_nC_LCD();      //   или записи команды (D_nC = 0)
  	  	  	  	  	  	//					  __ ___		  _
  Reset_nWR_nRST(); 	// Сформировать сигал WR/RST = 0 => R/W_LCD = 0
  	  	  	  	  	  	//								  __
  Reset_nSS();        	// Сформировать сигал "OE_BF_LCD" SS = 0
  DB_DIR = 0xFF;    	// Шина данных на выход
  DB_OUT = byte;    	// Выставить данные на шину данных
  	  	  	  	  	  	//														_____
  Set_EN_LCD();         // Сформировать строб данных для LCD  EN_LCD = 1		|	|
  Set_EN_LCD();         // Сформировать строб данных для LCD  EN_LCD = 1		|	|
  Set_EN_LCD();         // Сформировать строб данных для LCD  EN_LCD = 1	____|	|_____
  Reset_EN_LCD();       // Перевести сигнал "EN_LCD_OUT" в неактивное состояние EN_LCD = 0

  	  	  	  	  	  	//					 								    __
  Set_nSS(); 	        // Перевести сигнал OE_BF_LCD =1 в неактивное состояние SS = 1
  DB_DIR = 0x00;	    // Шина данных на вход
  	  	  	  	  	    //		 __ ___				  	_
  Set_nWR_nRST();  	    // Cигал WR/RST = 1 => сигнал R/W_LCD = 1, т.е. в неактивном состоянии

}


//Функция перекодировки символа в киррилицу
char LCD_recode(char b)
{
  if (b<192) return b;
    else return LCD_table[b-192];
}
