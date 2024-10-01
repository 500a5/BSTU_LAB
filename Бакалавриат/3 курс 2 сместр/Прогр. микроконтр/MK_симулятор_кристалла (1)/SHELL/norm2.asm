MK_ADC bit P1.0			;SIGNAL GASHENIE/PREOBRAZOVANIE
ADC_MK bit P1.1			;SIGNAL GOTOV
INIT_PPI equ 10000010b		;A-VIVOD, B-VVOD, C-VIVOD(INDIKACIA) DLYA BB55
INIT_KN equ  00010001b		;VIBOR 2-OGO KOMMUTATORA NAPRYASHGENIA I 1 PORT
P_A equ 0			;ADDRESS PORTA A V BB55
P_B equ 1			;ADDRESS PORTA B
P_C equ 2			;ADDRESS PORTA C
RWCU equ 3			;ADDRESS UPRAV. SLOVA BB55
P_V bit P1.7
P_N bit P1.6
D_X data 30h
D_Y data 31h
TEMP data 32h
EDINICA data 33h
DESYATKA data 34h
TIME EQU 5000 			;5ms



org 0h
jmp start

org 8100h
start:
  mov A,#INIT_PPI
  mov DPL,#RWCU			;NASTROIKA BB55 NA NEOBHODIMYI REZHIM
  movx @DPTR,A
  setb RS1
  mov A,#INIT_KN
  mov DPL,#P_A			;NASTROIKA KOMUTATOROV NAPRYASHGENIA
  movx @DPTR,A
  mov A,TMOD
  orl A,#0000001b	
  mov TMOD,A			;T/C0 - 16 BITNUYI TAIMER (T/C1 NE TROGHEAM, T.K. ON ZANAT 
  setb EA			;razreshenie prerivanii
  clr P_N
  clr P_V
  mov R0,#0			;regulirovanie ugla pri starte vverh
  mov R1,#0			;regulirovanie ugla pri starte vniz
  mov R2,#1			;dobavka k uglu pri starte vverh
  mov R3,#2			;dobavka k uglu pri starte vniz
  mov R4,#0			;dlya zadaniya perioda zaderzhki
  
start_up:
  setb P_V
  call ADC
  jb ADC_MK,$			;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
  call raschet
  mov DPL,#P_B
  movx A,@DPTR
  cjne A,#0,niz_dalee_up
  jmp exit

niz_dalee_up:
  cjne A,#119,verh_dalee_up
  jmp exit

verh_dalee_up:
  cjne R0,#0,next_up
    add A,R2
    mov D_X,A
    subb A,R2
    mov R0,#1
 
next_up:
  cjne A,#D_X,start_up
  clr P_V
  inc D_X
  call vivod
  call wait
  setb P_N

start_down:
  call ADC
  jb ADC_MK,$			;ZHDEM 30mks - PREOBRAZOVANIE "ADC"
;  call rascet
  mov DPL,#P_B
  movx A,