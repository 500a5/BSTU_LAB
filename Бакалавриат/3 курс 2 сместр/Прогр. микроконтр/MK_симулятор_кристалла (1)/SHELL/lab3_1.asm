org 00h
  jmp Start
org 0bh
  jmp IntCounter ;tl0
org 1bh
  jmp IntTimer ;th0
org 8100h

IntCounter:
  mov tl0,#-125
  inc r6
  reti
  
M1:
  jmp Minute_1
M2:
  jmp Minute_2
M3:  
  jmp Minute_3
M4:
  jmp Minute_4
  
IntTimer:
  clr tr1
  mov a,r0
  dec a
  jz M1
  dec a
  jz M2
  dec a
  jz M3
  dec a
  jz M4
  
Minute_0:
  cjne r5,#165,T
  cjne r3,#0,PeriodPart_0
  cjne r2,#0,Period_0
  cjne r1,#0,Second_0
  inc r0
  mov r1,#59
  mov r2,#9
  mov r3,#5
  mov p1,#01010000b
  clr 02h
  mov r5,#0
  jmp StartTick
Second_0:
  mov a,r6
  mov r7,a
  mov r6,#0
  dec r1
  mov r2,#10
Period_0:
  dec r2
  mov r3,#6
  clr 02h
PeriodPart_0:
  dec r3
  mov r5,#0
  jb 02h,S
  cjne r3,#5,InActive_0
  mov p1,#10100000b
  jmp StartTick
InActive_0:
  mov p1,#10010000b
  setb 02h
  jmp StartTick
Minute_1:
  cjne r5,#165,T
  cjne r3,#0,PeriodPart_1
  cjne r2,#0,Period_1
  cjne r1,#0,Second_1
  inc r0
  mov r1,#59
  mov r2,#9
  mov r3,#5
  mov p1,#10100000b
  clr 02h
  mov r5,#0
  jmp StartTick
Second_1:
  mov a,r6
  mov r7,a
  mov r6,#0
  dec r1
  mov r2,#10
Period_1:
  dec r2
  mov r3,#6
  clr 02h
PeriodPart_1:
  dec r3
  mov r5,#0
  jb 02h,S
  cjne r3,#4,NI_1
NI_1:
  jc InActive_1
  mov p1,#01010000b
  jmp StartTick
InActive_1:
  mov p1,#10010000b
  setb 02h
  jmp StartTick
T:
  jmp Tick
S:
  jmp StartTick
  
Minute_2:
  cjne r5,#165,T
  cjne r3,#0,PeriodPart_2
  cjne r2,#0,Period_2
  cjne r1,#0,Second_2
  inc r0
  mov r1,#59
  mov r2,#9
  mov r3,#5
  mov p1,#01010000b
  clr 02h
  mov r5,#0
  jmp StartTick
Second_2:
  mov a,r6
  mov r7,a
  mov r6,#0
  dec r1
  mov r2,#10
Period_2:
  dec r2
  mov r3,#6
  clr 02h
PeriodPart_2:
  dec r3
  mov r5,#0
  jb 02h,S
  cjne r3,#3,NI_2
NI_2:
  jc InActive_2
  mov p1,#10100000b
  jmp StartTick
InActive_2:
  mov p1,#10010000b
  setb 02h
  jmp StartTick

Minute_3:
  cjne r5,#165,Tick
  cjne r3,#0,PeriodPart_3
  cjne r2,#0,Period_3
  cjne r1,#0,Second_3
  inc r0
  mov r1,#59
  mov r2,#9
  mov r3,#89
  mov r4,#59
  mov p1,#01010000b
  clr 02h
  mov r5,#0
  jmp StartTick
Second_3:
  mov a,r6
  mov r7,a
  mov r6,#0
  dec r1
  mov r2,#10
Period_3:
  dec r2
  mov r3,#6
  clr 02h
PeriodPart_3:
  dec r3
  mov r5,#0
  jb 02h,StartTick
  cjne r3,#2,NI_3
NI_3:
  jc InActive_3
  mov p1,#01010000b
  jmp StartTick
InActive_3:
  mov p1,#10010000b
  setb 02h
  jmp StartTick
Minute_4:
  cjne r5,#11,Tick
  cjne r3,#0,PeriodPart_4
  cjne r2,#0,Period_4
  cjne r1,#0,Second_4
  jmp End_
Second_4:
  mov a,r6
  mov r7,a
  mov r6,#0
  dec r1
  mov r2,#10
Period_4:
  dec r2
  mov r3,#90
  mov a,r1
  mov r4,a
  clr 02h
PeriodPart_4:
  dec r3
  mov r5,#0
  jb 02h,StartTick
  djnz r4,NI_4
  jmp InActive_4
NI_4:
  ;jc InActive_4
  mov p1,#01010000b
  jmp StartTick
InActive_4:
  mov p1,#10010000b
  setb 02h
  ;jmp StartTick
  
StartTick:
  mov th0,#-101
  setb tr1
  jmp End_
Tick:
  inc r5
  mov th0,#-101
  setb tr1
End_:  
  reti
  
Start:
  mov p1,#0ffh
  clr psw.3
  clr psw.4
  clr tr0
  clr tr1
  mov th0,#-101
  mov tl0,#-125
  mov r0,#0 ;минута
  mov r1,#59 ;секунда
  mov r2,#9 ;период повторения
  mov r3,#5 ;часть периода повторения
  ;clr 00h ;прямое | обратное вращение
  ;mov r4,#10100000b ;начальное значение
  mov r5,#0 ;16665==165*101
  mov r6,#0 ;кол-во оборотов двигателя
  mov r7,#0 ;кол-во оборотов двигателя в секунду
  mov 10h,#10000000b ;байт для первого слева индикатора
  mov 11h,#01000000b ;байт для второго слева индикатора
  mov 12h,#00100000b ;байт для третьего слева индикатора
  mov 13h,#00010000b ;байт для четвертого слева индикатора
  mov p1,#10100000b
  mov tmod,#00110111b
  mov ie,#10001010b
  setb tr0
  setb tr1
Label:
  mov a,r7
  mov b,6h
  mul ab
  mov b,#0Ah
  div ab
  orl b,#00100000b
  mov 12h,b
  mov b,#0Ah
  div ab
  orl b,#01000000b
  mov 11h,b
  setb acc.7
  mov 10h,a
  mov dptr,#02h ;адрес порта С
Output:         
  mov 14h,#07h
Output_0:       
  mov 15h,#0Fh
  
Output_1:       
  mov a,13h
  movx @dptr,a
  mov 17h,#00h
Pause_0:        
  djnz 17h,Pause_0 ;задержка
  mov a,12h
  movx @dptr,a
Pause_1:        
  djnz 17h,Pause_1 ;задержка
  mov a,11h
  movx @dptr,a
Pause_2:
  djnz 17h,Pause_2
  mov a,10h
  movx @dptr,a
Pause_3:
  djnz 17h,Pause_3
  
  djnz 15h,Output_1 
  djnz 14h,Output_0 ;вложенные циклы
  
  jmp Label
  
  end
