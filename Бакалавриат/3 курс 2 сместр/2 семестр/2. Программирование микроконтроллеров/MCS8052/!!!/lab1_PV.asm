org 0h
jmp start

org 023h
reti
org 030h
	db 31h, 32h, 33h, 42h, 43h
	db 34h, 35h, 36h, 44h, 45h
	db 37h, 38h, 39h, 46h, 47h
	db 40h, 30h, 41h, 48h, 49h
org 100h

start:
mov r6,#0
mov r5,#0
mov r4,#0
mov scon,#11010000b
mov tmod,#00100000b
mov th1,#0fdh
setb tr1
mov ie,#10000000b
mov ip,#0
mov p0,#0FEh
mov p1,#0FFh
setb ti
mov r1,#4h
mov r0,#0FFh

c1:
jnb ti,c1
mov r7,p1
mov r6,p0
mov a,#0FFh
subb a,r7
jnz me

m1a:
djnz r1,m1c
jmp m1b
m1c:
mov a,p0
rl a
mov p0,a
jmp c1

m1b:
mov r1,#4h
mov p0,#0FEh
jmp c1

me:
clr ti
mov dptr,#30h
mov a,r6
anl a,#00001111b
xrl a,#00001111b
mov r2,#0

m1:
jb acc.0,m2
mov b,#2
div ab
inc r2
jmp m1

m2:
mov a,r2
mov b,#5
mul ab
mov r2,a
mov a,r7
anl a,#00011111b
xrl a,#00011111b
mov r3,#0

m3:
jb acc.0,m4
mov b,#2
div ab
inc r3
jmp m3

m4:
mov a,r2
add a,r3
movc a,@a+dptr
mov b,a
subb a,r0
jnz m4a
setb ti
jmp c1

m4a:
mov a,b
mov r0,a
clr tb8
jnb p,m5
setb tb8

m5:
mov sbuf,a
mov dph,r5
mov dpl,r4
movx @dptr,a
inc dptr
mov r5,dph
mov r4,dpl
jmp c1

end