 org 0h	
 jmp start 
 org 0bh
 jmp time_handle
 org 100h
 timestep equ 65535-8250
;-----------------------
getkey:
 mov a,r0
 inc a
 movc a,@a+pc
 ret
 db  102,150,153,105
;-----------------------
time_handle:
 call getkey
 mov p1,a
 inc r0
 cjne r0,#5,tm1
 mov r0,#1
 tm1:

 reti
;------------------------
start:
 clr rs0
 clr rs1
 mov tmod,#1
 mov tl0,#low(timestep)
 mov th0,#high(timestep)
 mov r0,#0
 setb ie. 5
 setb ie. 1
 setb tr0
 call time_handle
jmp $
end