INIT_PPI EQU 10000010b  ;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN EQU  00010001b  ;VIBOR 2-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT
MK_ADC BIT P1.0                 ;SIGNAL GASHENIE/PREOBRAZOVANIE
ADC_MK BIT P1.1         ;SIGNAL GOTOV
RWCU EQU 3              ;ADDRESS UPRAV. SLOVA BB55
ZNACH DATA 33h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
des DATA 34h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
edin DATA 35h          ;ADRESS ECHEIKI ZNACHENIJ YGLA
TIME EQU 7000          ;10ms
N_SEC DATA 37h          ;YACHEIKA PAMATI SCHITAUSCHYAIA 1sec 100*5ms=500ms clrSEC, ZATEM 500ms setbSEC
C_SEC EQU 100           ;CONSTANTA DLYA SECUNDOMERA
P_A EQU 0               ;ADDRESS PORTA A V BB55
P_B EQU 1               ;ADDRESS PORTA B
P_C EQU 2               ;ADDRESS PORTA C

org 0h
  jmp start

org 8100h
start:
  mov A,#INIT_PPI
  mov DPL,#RWCU                   ;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
  movx @DPTR,A
  mov A,#INIT_KN
  mov DPL,#P_A                    ;NASTROIKA KOMUTATOROV NAPRYASHGENIA
  movx @DPTR,A
  mov R0,#01h                      ;ZNACHENIE PERVOGO KOFICIENTA
  mov R1,#00H
  mov A,TMOD
  orl A,#0000001b
  mov TMOD,A                    ;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT

  call ADC
  jb ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
  mov DPL,#01h
  movx A,@DPTR
  mov R3,A

met1:
  mov A,R3
  cjne R1,#00H,met5 ;ПРОЕРКА НА ЗАДАНИЕ РЕЖИМА ВРАЩЕНИЯ
  add A,R0
  clr p1.7
  setb p1.6
  mov R1,#01H
  jmp met6

Met5:
  subb A,R0
  clr p1.6
  setb p1.7
  mov R1,#00H

met6:
  mov ZNACH,A

met2:
  call ADC
  jb ADC_MK,$     ;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
  mov DPL,#01h
  movx A,@DPTR
  mov R6,A
  call rasch
  call vivod
  mov A,R6
  cjne A,#00H,met3
  jmp exit

met3:
  cjne A,#119,met4
  jmp exit

met4:
  call wait
  cjne A,ZNACH,met2 ;проверка на равенство значеию отклонения
  mov A,R0
  mov B,#02h
  mul AB
  mov R0,A
  jmp met1

;PODPROGRAMMA STARTA "ADC"
ADC:
  setb MK_ADC             ;SBROS "ADC"
  nop
  nop
  nop
  nop
  clr MK_ADC               ;NACHAT' PREOBRAZOVANIE
ret

rasch:
  mov B,#4
  div AB
  mov B,#3
  mul AB
  mov B,#10
  div AB
  mov edin,B
  mov des,A
ret

vivod:
  mov A,des
  orl A,#01000000b
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY
        MOV A,edin
        ORL A,#10000000b                ;VIVOD 1 CIFRI
        MOV DPL,#P_C
        MOVX @DPTR,A
        CALL DELAY              ;ZADERSHKA 10ms
ret

delay:
  setb TR0
  jnb TF0,$
  clr TF0
  clr TR0
  mov TH0,#HIGH(NOT(TIME-1))
  mov TL0,#LOW(NOT(TIME-1))
ret

wait:
  mov TH0,#HIGH(NOT(TIME-1))
  mov TL0,#LOW(NOT(TIME-1))
  inc R4
  cjne R4,#20,M0                ;1cek
  inc R5
  mov R4,#0

M0:

reti

exit:
  clr p1.7
  clr p1.6
end