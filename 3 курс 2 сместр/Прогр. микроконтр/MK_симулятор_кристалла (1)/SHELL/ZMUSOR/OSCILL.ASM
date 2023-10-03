org 0000h
jmp initializeEngine

org 000Bh
jmp timer0Int

org 001Bh
jmp timer1Int
;----------------------------------------
portA XDATA 0000h
portB XDATA 0001h
portC XDATA 0002h
conPort XDATA 0003h

easymode equ 03Dh    ;if easymode = 0 - function
                     ;if easymode <> 0 - constant velocity
angle1 equ 031h ;current angle
angle2 equ 032h ;target

timeS1 equ 03Fh
timeS2 equ 03Eh

counter equ 041h
divider equ 042h
reminder equ 043h ;temporary variable
hB equ 044h      ;high - byte
lB equ 045h      ;low - byte

mode equ 04Ah ;reverse=1 / direct=0

moveFlag equ 046h

uVar equ 04Bh  ;current u = current velocity
uStep equ 04Ch

timeOnOff equ 03Ch
parity equ 04Eh

currentTime equ 04Fh

turnCounter equ 048h
turnTime equ 047h

period1 XDATA 8050h
period2 XDATA 8051h
;----------------------------------------
org 8100h
;----------------------------------------
readT1:
        mov DPTR, #period1
        movx A, @DPTR
        ;mov B, #10
        ;div AB
        ;mov B, #16
        ;mul AB
        ret
;----------------------------------------
readT2:
        mov DPTR, #period2
        movx A, @DPTR
        ;mov B, #10
        ;div AB
        ;mov B, #16
        ;mul AB
        ret
;----------------------------------------
cycleShift:
        ;input - flag c
        mov A,lB
        rlc A
        mov lB,A
        mov A,hB
        rlc A
        mov hB,A
        mov A, reminder
        rlc A
        mov reminder,A
ret
;----------------------------------------
division21:
; division 2-byte digit(hB:lB) by 1-byte digit(divider)
; result - 2-byte integer part(hB:lB) and 1-byte reminder(reminder)
        mov reminder,#00h
        mov counter, #0
divCycle:
        mov A, reminder
        clr c
        subb A, divider
        jc addZero
        setb c
        mov reminder, A
        jmp shiftLabel
addZero:
        clr c
shiftLabel:
        call cycleShift
        inc counter
        mov A, counter
        cjne A,#17,divCycle

        mov A, reminder  ;correct reminder
        rrc A
        mov reminder,A
ret
;----------------------------------------
openTransistors:
        mov A, mode
        jnz reverseLabel
                mov     P1, #01010000b
                jmp endProcOpen
reverseLabel:
        mov     P1, #10100000b
endProcOpen:
ret
;----------------------------------------
closeTransistors:
        mov     P1, #01100000b
ret

readAngles:
                mov     DPTR,#0000h
                mov     A,#20h
                movx    @DPTR,A
                call    readADC
                mov     angle1,A            ;feedback
                mov     DPTR,#0000h
                mov     A,#21h
                movx    @DPTR,A
                call    readADC
                mov     angle2,A            ;job

                ret
;-------------------------------
readADC:
                clr     P1.0
                jb      P1.1,$
                mov     DPTR,#0001h
                movx    A,@DPTR
                cpl     A
                setb    P1.0
                setb    P1.1
                ret


;----------------------------------------
moveEngine:
    mov A, moveFlag
        jz endProcMove
        mov moveFlag, #0
        mov A, angle2
        clr c
        subb A,#01111111b
        jc nullProcMove
        push acc
        subb A,#47

        jc nonmaxangle2
        pop acc
        mov A,#45
        jmp lab00
nonmaxangle2:
         pop acc
lab00:
        mov mode,#1
        ;mov A, #01111111b
        ;subb A, angle2
        ;jc endProcMove

        mov B, #4
        mul AB
        add A, #50

        mov uVar,A

        jmp endProcMove
;nonRevProcMove:
        mov mode,#1
        subb A,#5
        jc nullProcMove
        mov A, angle2
        subb A,#01111111b
        jc nextStep

        mov B, #4
        mul AB
        ;mov lB, A
        ;mov hB, B
        ;mov divider,#100
        ;call division21
        ;mov A, lB ;A = A*44/100
        add A, #50
        mov uVar,A
        jmp endcond
nextStep:
        clr c
        mov A,angle2
        subb A, angle1
        jc negative
        mov B,#3
        mul AB
        add A, uVar
        mov uVar,A

        jmp endcond
negative:
        clr c
        mov B,A
        mov A, #255
        subb A,B
        mov B,#5
        mul AB
        mov B,A
        mov A,uVar
        subb A,B
        mov uVar,A
endcond:
jmp endProcMove
maxEndProcMove:
 ;       mov uVar,#170
jmp endProcMove
nullProcMove:
        mov uVar,#0
endProcMove:
ret
;----------------------------------------
calculateStep:
        mov B,A
        mov A, #0FFh
        div AB
        mov uStep, A
ret
;----------------------------------------
calculateVelocity:
                mov A,timeS2
                cjne A,#16h,noChange
                mov A,timeS1
                cjne A,#0A8h,noChange    ;if (B:54) - period=0,25mcs
                mov timeS1, #0
                mov timeS2, #0
                mov A,turnCounter
                mov B,#60
                mul AB

                mov lB, A
                mov hB, B
                mov divider,#100
                call division21

                mov A, lB
                mov B, #10
                div AB
                mov r5,B   ;2-digit
                mov r4,A   ;1-digit

                mov A, reminder
                mov B, #10
                div AB
                mov r7,B   ;2-digit
                mov r6,A   ;1-digit

                mov turnCounter, #0

noChange:
ret
timer0Int:
        push acc
        push psw
        inc turnCounter

        mov TL0,#82h
        pop psw
        pop acc
reti
;----------------------------------------
timer1Int:
         mov TH0, #41
  ;save system data
        push acc
        push psw
        clr rs1
        clr rs0
        mov A,parity
        xrl A, #01h
        mov parity,A
        jz endProcess
        ;each double tick
        call activateIndicators
        inc timeOnOff
        mov A, easymode
        jnz next1
        mov A, timeOnOff
        cjne A, #0FFh, next1
                ;100ms finished
                mov timeOnOff,#0h

               inc currentTime
                mov moveFlag,#1 ;call moveEngine
                jmp endProcess
next1:
        mov A, timeOnOff
        clr c
        subb A, uVar
        jnc next2
                call openTransistors
                jmp endProcess
next2:
                call closeTransistors
                jmp endProcess

endProcess:

        mov A,timeS1
        add A,#1h
        mov timeS1,A
        mov A,timeS2
        addc A,#0h
        mov timeS2, A

        pop psw
        pop acc
reti
;----------------------------------------
;r3 - current index
;r4 - 1 digit (left)
;r5 - 2 digit
;r6 - 3 digit
;r7 - 4 digit
activateIndicators:
 digit4:
        cjne r3,#3h,digit3
        mov A,r7
        orl A,#80h
        jmp outpDigit
 digit3:
        cjne r3,#2h,digit2
        mov A,r6
        orl A,#40h
        jmp outpDigit
digit2:
        cjne r3,#1h,digit1
        mov A,r5
        orl A,#20h
        jmp outpDigit
digit1:
        cjne r3,#0h,outpDigit
        mov A,r4
        orl A,#10h
        cjne r4,#0h,outpDigit
        jmp noOut        ;if digit1 = 0 we don't need activate indicator
outpDigit:
        mov DPTR,#portC  ;write to PortC
        movx @DPTR,A
noOut:
        inc r3                  ;choose next indicator
        cjne r3,#04h,incIndex
        mov r3, #0
incIndex:
        ret
;----------------------------------------
initializeEngine:
        clr rs1
        clr rs0

        call closeTransistors
        mov A,#0FFh
        add A,#10h


        mov DPTR, #period1
        mov A, #10
        movx @DPTR,A;

        mov DPTR, #period2
        mov A, #10
        movx @DPTR,A;

        call readT1
        call calculateStep
;        mov uVar,#100
        mov currentTime,#0
        mov mode,#1
        mov timeOnOff,#0
        mov turnCounter,#0
        mov turnTime,#0
        mov easymode,#0

        mov A,#10000010b
        mov DPTR,#conPort        ;set ports mode
        movx @DPTR,A

        mov r3,#0 ;initialize indicator

    mov TL0, #82h
        mov TH0, #41h ;period = 0.000196s = 196mcs
        mov A,TMOD

        anl A,#11110000b
        orl A,#00000111b ;

        mov TMOD,A
        setb IE.1          ;Interruption settings
        setb IE.3
        setb EA                            ;Allow interruptions
        setb TR1
        setb TR0

mainCycle:
                call readAngles
                call moveEngine
                call calculateVelocity
        jmp mainCycle
ret
;----------------------------------------
end