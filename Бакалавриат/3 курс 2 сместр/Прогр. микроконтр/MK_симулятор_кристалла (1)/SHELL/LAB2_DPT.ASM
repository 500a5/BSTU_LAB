T0_C equ 220                    ;210 MINUS POTERI NA COMANDI
C0_C equ 12                     ;125/10
VT4 bit P1.4
VT5 bit P1.5
VT6 bit P1.6
VT7 bit P1.7
MEMORY_DPL data 30h
MEMORY_DPH data 31h
TIME data 32h
TIME_MAX equ 240
TIME_START data 33h
TIME_STOP data 34h
OBOROT data 35h
NAPR_SKOR data 36h
EDINICA data 37h
DESYATKA data 38h
RAZGON data 39h
VIV_UST DATA 40h                ;DLYA VIVODA USTAVKI VREMENI (2 RAZRYADA) I CHASTOTI (V Hz - 2 RAZRYADA)
C_VIV_UST EQU 120               ;120*4*5ms=2,4s (bilo 120)
F_REVERS bit 2Fh.0
GOTOVO bit 2Fh.1
GOTOV_TIME bit 2Fh.2
MEMORY_CY bit 2Fh.3

org 0h
  jmp start

org 0Bh
  jmp schet

org 8100h
start:
  mov A,#82h
  mov DPL,#3h
  movx @DPTR,A
  setb RS1
  mov A,TMOD
  orl A,#00000111b              ;rezhim 3: L-schetchik, H-taimer
  mov TMOD,A
  mov TL0,#not(C0_C-1)
  mov TH0,#not(T0_C-1)
  setb EA                       ;razreshenie prerivanii
  setb ET0                      ;razreshenie prerivanii ot taimera 0
  setb TR0                      ;start taimera 0

episod:
  mov DPTR,#8600h
  mov MEMORY_DPL,DPL
  mov MEMORY_DPH,DPH

etap:
  mov TIME,#0
  mov OBOROT,#0
  mov NAPR_SKOR,#0
  setb VT4
  setb VT5
  setb VT6
  setb VT7
  mov DPL,MEMORY_DPL
  mov DPH,MEMORY_DPH
  inc DPTR
  movx A,@DPTR
  cjne A,#0,zadanie
  sjmp episod

zadanie:
  mov TIME,A
  inc DPTR
  mov MEMORY_DPL,DPL
  mov MEMORY_DPH,DPH
  movx A,@DPTR
  mov NAPR_SKOR,A
  call propeller
  sjmp etap

;osnovnaya programma

propeller:
  call razgon_time_1
  clr C
  clr F_REVERS
  clr GOTOVO
  clr GOTOV_TIME
  mov A,NAPR_SKOR
  rlc A
  jnb CY,speed
  setb F_REVERS

speed:
  rrc A
  mov B,#5
  anl A,#01111111b
  div AB                        ;V A - CELOE, V B - OSTATOK
  mov R0,B
  mov B,#23                     ;PRI MAX 50 OB/SEK
  mul AB
  add A,R0
  mov TIME_START,A
  mov R0,A
  mov A,#TIME_MAX
  subb A,R0
  mov TIME_STOP,A
  inc TIME_START
  inc TIME_STOP
  mov R2,#10
  call vivod
  mov R6,#4
  jb F_REVERS,revers

;odno napravlenie

  clr VT7

pr_chas:
  clr VT5
  mov R1,TIME_START

pr_chas_start:
  call zaderzhka_1
  djnz R1,pr_chas_start
  setb VT5
  mov R1,TIME_STOP

pr_chas_stop:
  call zaderzhka_1
  djnz R1,pr_chas_stop
  mov A,OBOROT
  mov R3,A
  mov OBOROT,#0
  call raschet
  jb GOTOV_TIME,wait_1          ;ESLI 3s PROSHLO, TO PEREHODIM K REGULIRIVANIU
  djnz R5,pr_chas_speed
  setb GOTOV_TIME

wait_1:
  call edit

;pr_chas_indikacia

pr_chas_speed:
  jnb GOTOVO,pr_chas_desyatki
  cjne R6,#3,pr_chas_desyatki
  mov A,#10h                    ;ESLI NOT(REVERS), TO MIGAET 0
  movx @DPTR,A
  dec R6
  sjmp pr_chas_prop

pr_chas_desyatki:
  djnz R6,pr_chas_desyatki
  mov R6,#4
  mov A,DESYATKA
  orl A,#01000000b
  movx @DPTR,A
  sjmp pr_chas_prop

pr_chas_edinici:
  mov A,EDINICA
  orl A,#10000000b
  movx @DPTR,A

pr_chas_prop:
  jnb GOTOVO,pr_chas
  djnz R2,pr_chas
  mov R2,#10
  djnz TIME,pr_chas
  jmp exit

;obratnoe napravlenie

revers:
  clr VT4

chas:
  clr VT6
  mov R1,TIME_START

chas_start:
  call zaderzhka_1
  djnz R1,chas_start
  setb VT6
  mov R1,TIME_STOP

chas_stop:
  call zaderzhka_1
  djnz R1,chas_stop
  mov A,OBOROT
  mov R3,A
  mov OBOROT,#0
  call raschet
  jb GOTOV_TIME,wait_2          ;ESLI 3s PROSHLO, TO PEREHODIM K REGULIROVANIU
  djnz R5,chas_speed
  setb GOTOV_TIME
wait_2:
  call edit

;chas_indikacia

chas_speed:
  jnb GOTOVO,chas_desyatki
  CJNE R6,#3,chas_desyatki
  mov A,#11h                    ;ESLI REVERS, TO MIGAET 1
  movx @DPTR,A
  dec R6
  sjmp chas_prop

chas_desyatki:
  djnz R6,chas_edinici
  mov R6,#4
  mov A,DESYATKA
  orl A,#01000000b
  movx @DPTR,A
  sjmp chas_prop

chas_edinici:
  mov A,EDINICA
  orl A,#10000000b
  movx @DPTR,A

chas_prop:
  jnb GOTOVO,chas
  djnz R2,chas
  mov R2,#10
  djnz NAPR_SKOR,chas

exit:
ret

raschet:
  mov A,R3
  mov B,#10
  div AB
  mov DESYATKA,A
  mov EDINICA,B
  mov DPTR,#2
ret

schet:
  inc OBOROT
  mov TL0,#not(C0_C-1)
reti

razgon_time_1:                  ;OPREDELYAEM ZNACH_R_REGUL DLYA BISTRODEISTVIYA & TOCHNOSTI
  clr C
  mov A,NAPR_SKOR
  anl A,#01111111b
  subb A,#5
  jnb CY,razgon_time_2
  mov RAZGON,#5                 ;N<=5           500ms
  sjmp razgon_exit

razgon_time_2:
  mov RAZGON,#5

razgon_exit:
  mov R5,RAZGON
ret

edit:
  mov A,NAPR_SKOR
  anl A,#01111111b
  mov NAPR_SKOR,A
  mov A,R3
  clr C
  clr GOTOVO
  subb A,NAPR_SKOR
  mov MEMORY_CY,C
  cjne A,#0,reg_start
  setb GOTOVO
  sjmp reg_stop

reg_start:
  jb MEMORY_CY,up

;down:
  mov A,TIME_STOP
  cjne A,#239,down_reg
  mov TIME_STOP,#239            ;ZAGLUSHKA PO NIZHNEMU ZNACHENIU
  mov TIME_START,#1
  sjmp reg_stop

down_reg:
  inc TIME_STOP
  dec TIME_START
  sjmp reg_stop

up:
  mov A,TIME_START
  cjne A,#239,up_reg
  mov TIME_START,#239           ;ZAGLUSHKA PO VERHNEMY ZNACHENIU
  mov TIME_STOP,#1
  sjmp reg_stop

up_reg:
  inc TIME_START
  dec TIME_STOP

reg_stop:

ret

vivod:
  mov VIV_UST,#C_VIV_UST
  indicator:
    mov A,TIME
    mov B,#10
    div AB
    mov DPTR,#2
    orl A,#00010000b
    movx @DPTR,A
    call zaderzhka_2
    mov A,B
    orl A,#00100000b
    movx @DPTR,A
    call zaderzhka_2
    mov A,NAPR_SKOR
    anl A,#01111111b
    mov B,#10
    div AB
    orl A,#01000000b
    movx @DPTR,A
    call zaderzhka_2
    mov A,B
    orl A,#10000000b
    movx @DPTR,A
    call zaderzhka_2
    jnb F_REVERS,vpered
    mov A,#0
    movx @DPTR,A
    call zaderzhka_3

vpered:
  djnz VIV_UST,indicator
ret

zaderzhka_1:                    ;(420mks)
  mov TH0,#not(T0_C-1)
  setb TR1
  mov R4,#2
  povtor_1:
    jnb TF1,$
    clr TF1
    mov TH0,#not(T0_C-1)
    djnz R4,povtor_1
  clr TR1
ret

zaderzhka_2:                    ;(5ms)
  mov R7,#6                     ;(bilo 12)
  povtor_2:
    call zaderzhka_1
    djnz R7,povtor_2
ret

zaderzhka_3:                    ;(21ms)
  mov R7,#25                    ;(bilo 50)
  povtor_3:
    call zaderzhka_1
    djnz R7,povtor_3
ret

end