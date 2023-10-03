 org 0h
 jmp start
start:
  mov DPTR, #0
  setb SCON.7 ; ������������� ����� 2 ������ �� 9600 ���
  clr SCON.6
  mov TH1, #0FDh
  mov TMOD, #20h
  mov R4, #1h ; ���� ������� �������
loop1:
  mov R0, #10000000b
loop2:
  cjne R0, #8h, loop3
  jmp loop1
loop3:
  mov A, R0   ; �������� ���� ������������ ����� ����������
  rl A
  mov R0, A  
  mov P0, #0h ; �������� ����
  mov R1, P3  ; ��������� �������� ����� � 3-�� �����
  cjne R1, #11111111b, next ;
  cjne R4, #0h, next ; ���� ������� ������
  mov R4, #1h
  inc DPTR
  jmp loop1
next:
  cjne R4, #1h, loop1
  mov P0, R0  ; � ���� 0 ������ ���� ������������, ���������� 1 ������ � ����� ����
  mov A, R1 
  xrl A, P3   ; ���� �������� ����� 3-�� �� ����� ����������
  jz loop2    ; �� ������� �� loop2
  mov A, P3
  xrl A, #11111111b ; ���� �������� ����� 3-�� ����� ��� �������,
  jnz loop2         ; ������ ������� �� ������
  mov A, R0   ; �������� ������ ��������� �� 1 ��� ������ ����������
  rr A
  mov R0, A
  mov A, R1   ; ������ ����� �� 2 ���� 
  anl A, #1Fh  ; �������� ������� 3 ����
  rl A
  rl A
  add A, R0   ; ��������� ���������� scan-���
  ; ���� ����������� scan-��� � ASCII-���
    cjne A, #78h, j1
	mov A, #030h
j1: cjne A, #0F8h, j2
	mov A, #31h
j2: cjne A, #0F4h, j3
    mov A, #32h
j3: cjne A, #0ECh, j4
    mov A, #33h
j4: cjne A, #079h, j5
    mov A, #34h
j5: cjne A, #075h, j6
    mov A, #35h
j6: cjne A, #06Dh, j7
    mov A, #36h
j7: cjne A, #07Ah, j8
    mov A, #37h
j8: cjne A, #076h, j9
    mov A, #38h
j9: cjne A, #06Eh, jA
    mov A, #39h
jA: cjne A, #07Ch, jB1
    mov A, #41h
jB1: cjne A, #070h, jC1
    mov A, #42h
jC1: cjne A, #0DCh, jD
    mov A, #43h
jD: cjne A, #0BCh, jE
    mov A, #44h
jE: cjne A, #05Dh, jF
    mov A, #45h
jF: cjne A, #03Dh, jG
    mov A, #46h
jG: cjne A, #05Eh, jH
    mov A, #47h
jH: cjne A, #03Eh, jI
    mov A, #48h
jI: cjne A, #060h, jJ
    mov A, #49h
jJ: cjne A, #040h, next2
    mov A, #4Ah	
next2:
  movx @DPTR, A ; ���������� �� ������� ������
  mov C, P
  mov TB8, C ; ���������� ��� ��������
  mov SBUF, A ; ���������� ����� ���������������� ����
  mov R4, #0h ; ���� ������� ������� - ������
  jmp loop1
jmp $
end