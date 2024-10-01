org 0
mov scon, #80h
setb SM0
setb TB8

mov A,tmod
ANL TMOD, #00001111b
orl tmod,#10100000b

mov TH1, #0fdh
mov tmod,A
jmp listen

setbit:         ;гоним нулевой флаг по ножкам порта р0
jnb p0.0, sl1
jnb p0.1, sl2
jnb p0.2, sl3
jnb p0.3, sl4
jmp setfb
sl1:
setb p0.0
clr p0.1
jmp endpmz

sl2:
setb p0.1
clr p0.2
jmp endpmz

sl3:
setb p0.2
clr p0.3
jmp endpmz

sl4:
setb p0.3
clr p0.0
jmp endpmz

setfb:
clr p0.0
endpmz:
jmp rmz

chkprt: ; провер9ем ножки порта р1 в поисках кода клавиши
jnb p0.0, cl1
jnb p0.1, cl2
jnb p0.2, cl3
jnb p0.3, cl4
cl1:
MOV A, #0feh
XRL A, p1
jz l1b1
MOV A, #0fdh
XRL A, p1
jz l1b2
MOV A, #0fbh
XRL A, p1
jz l1b3
MOV A, #0f7h
XRL A, p1
jz l1b4
MOV A, #0efh
XRL A, p1
jz l1b5
jmp ecp

cl2:

MOV A, #0feh
XRL A, p1
jz l2b1
MOV A, #0fdh
XRL A, p1
jz l2b2
MOV A, #0fbh
XRL A, p1
jz l2b3
MOV A, #0f7h
XRL A, p1
jz l2b4
MOV A, #0efh
XRL A, p1
jz l2b5
jmp ecp
cl3:
MOV A, #0feh
XRL A, p1
jz l3b1
MOV A, #0fdh
XRL A, p1
jz l3b2
MOV A, #0fbh
XRL A, p1
jz l3b3
MOV A, #0f7h
XRL A, p1
jz l3b4
MOV A, #0efh
XRL A, p1
jz l3b5
jmp ecp
cl4:
MOV A, #0feh
XRL A, p1
jz l4b1
MOV A, #0fdh
XRL A, p1
jz l4b2
MOV A, #0fbh
XRL A, p1
jz l4b3
MOV A, #0f7h
XRL A, p1
jz l4b4
MOV A, #0efh
XRL A, p1
jz l4b5
jmp ecp


l1b1:
MOV A, #31H
jmp ecpf
l1b2:
MOV A, #32H
jmp ecpf
l1b3:
MOV A, #33H
jmp ecpf
l1b4:
MOV A, #043H
jmp ecpf
l1b5:
MOV A, #044H
jmp ecpf
l2b1:
MOV A, #34H
jmp ecpf
l2b2:
MOV A, #35H
jmp ecpf
l2b3:
MOV A, #36H
jmp ecpf
l2b4:
MOV A, #045H
jmp ecpf
l2b5:
MOV A, #046H
jmp ecpf
l3b1:
MOV A, #37H
jmp ecpf
l3b2:
MOV A, #38H
jmp ecpf
l3b3:
MOV A, #39H
jmp ecpf
l3b4:
MOV A, #047H
jmp ecpf
l3b5:
MOV A, #048H
jmp ecpf
l4b1:
MOV A, #041H
jmp ecpf
l4b2:
MOV A, #30H
jmp ecpf
l4b3:
MOV A, #042H
jmp ecpf
l4b4:
MOV A, #049H
jmp ecpf
l4b5:
MOV A, #04AH
jmp ecpf
jmp ecp
ecp:
clr A
ecpf:
jmp rcp

mvcdexmem:
movx @DPTR, A
inc DPTR
jmp rmem

sndcd:
JB P, sett
jmp us
sett:
setb TB8
jmp s
us:
clr tb8

s:
mov SBUF, A
jmp rsnd

listen:
clr A
jmp setbit
rmz:
jmp chkprt
rcp:
jnz mvcdexmem
rmem:
jnz sndcd
rsnd:
jmp listen
jmp $
end