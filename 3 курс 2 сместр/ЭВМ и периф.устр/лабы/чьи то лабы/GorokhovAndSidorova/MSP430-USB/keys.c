// Keyboard functions

#include "function_prototype.h"
#include "sysfunc.h"
#include "keys.h"

byte keycol, keyline, KEYS_last=0;
char table_keys[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};

// �������� ������� ������� � ������� ������, ���������:
//  0 - ������� �� ������
//  ASCII-��� �������
char KEYS_scannow()
{
  keyline=0;
  // �������� ������� ������������ ����������� (0x03)
  //  � ������������� P4-P7 �� ����� - ��� ������ ��������,
  //  � P0-P3 �� ���� - ��� ������ ����� (1-����, 0-�����)
  I2C_WriteByte(0x03, 0x0F, KEYS_i2c_addr);

  for (keycol=0; keycol<3; keycol++) {
  // ��������������� ������ ������ ������� ������ �� ������� (P4-P7)
    I2C_WriteByte(0x01, ~(1<<keycol<<4) & 0xf0, KEYS_i2c_addr);
    wait_1ms(1);
    // � ���������� ������ (P0-P3) �� ������� ����
    keyline = ~(I2C_ReadByte(0x00, KEYS_i2c_addr)) & 0x0f;
    if (keyline) break;
  }
  if (!keyline) return 0;       // ���� �� ���� ������ ������� ������� - ���������� 0
  if (keyline == 4) keyline = 3;  // ��������� ������ �������� � ����� ������
  if (keyline == 8) keyline = 4;
  KEYS_last = table_keys[--keyline*3+keycol]; // �������� ��� ������� ������� �� �������
  return KEYS_last;
}


// ���������� ��� ��������� ������� �������, ���������:
//  0 - �� ���������� ������� �������
//  ASCII-��� �������
char KEYS_lastkey()
{
  KEYS_scannow();
  return KEYS_last;
}


// ������� ��������� ������� �������
void KEYS_clear()
{
  KEYS_last = 0;
  wait_1ms(200);
}

// �������� ������� �������, ��������� - ASCII-��� ������� �������
char KEYS_waitkey()
{
  KEYS_clear();           // ������� ��������� ������� �������
  while (!KEYS_scannow()) // ���� �� ������ ������� �������,
    wait_1ms(1);          //    ������� �����
  return KEYS_last;       // ������� ��� ������� �������
}


// ����� � ����������� ������� ����������, ����������� ���� ������ �������
void KEYS_pause(byte cnt)
{
  byte i;
  KEYS_clear();           // ������� ��������� ������� �������
  for (i=0; i<cnt; i++)
    if (KEYS_scannow())
      break;
}    
