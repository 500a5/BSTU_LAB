org 0000h
jmp begin
org 000bh
jmp tim1
org 8100h
;20.54
;42.26
PAUSA:
mov b,#02
div ab
mov 14h,a
cjne a,#00h,ee
jmp ee2
ee:
PAUSA2: mov 10h,#10d
PAUSA3: mov 11h,#98d
PAUSA4: djnz 11h,PAUSA4
djnz 10h,PAUSA3
djnz 14h,PAUSA2
;pausa
ee2:
ret
;+++++++++++++++
vivod1:
MOV a,r3
mov b,#02h
mul ab
;mov a,b
mov r3,#00h
mov dptr,#0002h
mov b,#10d
div ab
mov a,b
ANL A,#00001111b
setb acc.5
movx @dptr,a
ret
   
vivod2:
MOV a,r3
mov b,#02h
mul ab
;mov a,b
mov b,#10d
div ab
mov r3,#00h
mov dptr,#0002h
ANL A,#00001111b
setb acc.4
movx @dptr,a
ret
;+++++++++++++++
per1:
	mov 1fh,#00d
	mov 1eh,#20d
	mov 1dh,#36d
	mov 1ch,#52d
	mov 1bh,#64d
	mov 1ah,#76d
	mov 19h,#84d
	mov 18h,#92d
	mov 17h,#96d
	mov 16h,#98d
	mov 15h,#100d
ret
per2:
	mov 1fh,#00d
	mov 1eh,#10d
	mov 1dh,#18d
	mov 1ch,#26d
	mov 1bh,#32d
	mov 1ah,#38d
	mov 19h,#42d
	mov 18h,#46d
	mov 17h,#48d
	mov 16h,#49d
	mov 15h,#50d
ret
begin:
clr psw.4
clr psw.3               
mov dptr,#03h
mov a,#82h
movx @dptr,a   
	setb ie.7
	setb ie.1    
		mov TMOD,#00000101b 
		mov th0,#35d;255
		mov TL0,#82h
	mov r1,#040d    
	mov r2,#03ch   
	
	mov a,r1
	mov b,#04h
	div ab
	mov b,#01h
	div ab
	mov r0,a
	mov r4,a
setb TCON.4 

mov a,28d
;mov dptr,#0002h
mov b,#10d
div ab
setb acc.6
movx @dptr,a
mov r2,#0ffh
zad2:mov r1,#0ffh
za:
djnz r1,za
djnz r2,zad2

period:
inc r5
mov 12h,#10100000b
;mov 13h,#10010000b
mov 13h,#01100000b
call per1
jmp start
period2:
mov 12h,#01010000b
mov 13h,#01100000b 
call per2  
start:    
mov r0,#1fh
first1:
dec r0
mov r6,#0ah
L1:
mov a,@r0
mov p1,12h
lcall PAUSA
;\------/

mov a,@r0
subb a,#100d
cpl a
inc a
  
mov p1,13h
lcall PAUSA
cjne r6,#06h,tyu
lcall vivod1
tyu:
djnz R6,L1
lcall vivod2
cjne r0,#15h,first1
jmp fit
w1:jmp period2
w2:jmp period

fit:
mov r0,#15h

first2:
mov dph,#01h
mov r6,#0ah
inc r0
L2:

mov a,@r0
mov p1,12h
lcall PAUSA


mov a,@r0
subb a,#100d    ;b{whqk^el t2
cpl a
inc a

mov p1,13h              ;meqhllerphwm{i g`jnm(10010000)
lcall PAUSA
cjne r6,#06h,tyz
lcall vivod1
tyz:
djnz r6,L2
lcall vivod2
cjne r0,#1fh,first2
;******
mov a,12h
jb acc.7,w1
jmp w2

	tim1:  inc r3
	mov th0,#35d;255
	mov tl0,#82h
	reti

end