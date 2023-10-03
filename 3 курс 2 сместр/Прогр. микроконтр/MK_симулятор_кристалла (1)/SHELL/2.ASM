desatki data 34h
edinicy data 33h
IMPULS DATA 32h
napr DATA 35h


ORG 00h
JMP START

org 000BH
jmp counter

org 001Bh
jmp TIMER

ORG 8100h

START:
       mov A,#10000010b
       mov DPL,#3
       movx @DPTR,A

        setb RS0        ;3 bank
        setb RS1

        mov IMPULS, #5
        mov napr, #0

        mov R0, #240 ;counter_space
        mov R2, #1 ;counter_impuls
        mov R3, #240 ;counter_decrement

        mov R1, #40 ;sec_counter1
        mov R4, #100 ;sec_counter2

        mov R6, #0 ;flag_vivoda

        mov R7, #0 ;ychastok

        mov TMOD,#00000111b
        mov IE, #10011010b ;razresheniye preryvaniya

        setb P1.5
        setb P1.7

        clr P1.4
        clr P1.6

        mov TH0, IMPULS
        setb TR0
        setb TR1


mov 036h,#15

jmp $


TIMER:
       cjne R7,#0,METKA0
         call razgon

         METKA0:
         cjne R7,#1,METKA1
         call constant

         METKA1:
         cjne R7,#2,METKA2
         call tormoz

         METKA2:
         cjne R7,#3,METKA3
         call razgon_back

           METKA3:
         cjne R7,#4,METKA4
         call constant_back

           METKA4:
         cjne R7,#5,METKA5
         call tormoz_back

        METKA5: call indicator
                mov TH0, IMPULS
    RETI

razgon:
        PUSH ACC
        jb P1.6,INTERVAL

        dec R2
        cjne R2,#0,NEXT
        inc 036h

        mov R2,036h
        setb P1.6
          clr P1.7
        jmp NEXT

        INTERVAL:
        dec R0
        cjne R0,#0,NEXT
        dec R3
        mov A,R3
        mov R0,A

        setb P1.7
                clr P1.6

        cjne R3,#0,NEXT
        mov R7,#1

        mov R0, #255
        mov R3, #255

NEXT: POP ACC
RET

constant:
        PUSH ACC
        setb P1.5
        setb P1.7
        clr P1.4
      clr P1.6

        dec R0
        cjne R0,#0,const_end
        dec R3
        mov A,R3
        mov R0,A

        cjne R3,#0,const_end
        mov R7,#2

        mov R0, #254
        mov R2, #255
        mov R3, #255
        mov 036h, #255

const_end:POP ACC
RET

tormoz:
        PUSH ACC
jb P1.6,INTERVAL_t

        dec R2
        cjne R2,#15,tormoz_end
        dec 036h

        mov R2,036h
        setb P1.6
          clr P1.7
        jmp tormoz_end

        INTERVAL_t:
        inc R0
        cjne R0,#255,tormoz_end
        dec R3
        mov A,R3
        mov R0,A

        setb P1.7
        clr P1.6

        cjne R3,#15,tormoz_end
        mov R7,#3

          setb P1.6
        setb P1.4

        clr P1.7
        clr P1.5

        mov R0, #240
        mov R2, #1
        mov R3, #240
        mov 036h, #15

        mov napr, #1
tormoz_end: POP ACC
RET

razgon_back:
        PUSH ACC
        jb P1.5,INTERVAL_RB

        dec R2
        cjne R2,#0,razgon_back_end
        inc 036h
        mov R2,036h
        setb P1.5
          clr P1.4
        jmp razgon_back_end

        INTERVAL_RB:
        dec R0
        cjne R0,#0,razgon_back_end
        dec R3
        mov A,R3
        mov R0,A

        setb P1.4
        clr P1.5

        cjne R3,#0,razgon_back_end
        mov R7,#4

        mov R0, #255
        mov R3, #255

razgon_back_end: POP ACC
RET

constant_back:
        PUSH ACC
        setb P1.4
        setb P1.6
        clr P1.5
        clr P1.7

        dec R0
        cjne R0,#0,const_back_end
        dec R3
        mov A,R3
        mov R0,A

        cjne R3,#0,const_back_end
        mov R7,#5

        mov R0, #254
        mov R2, #255
        mov R3, #255
        mov 036h,#255

const_back_end:POP ACC
RET

tormoz_back:
        PUSH ACC
jb P1.5,INTERVAL_TB

        dec R2
        cjne R2,#15,tormoz_back_end
        dec 036h
        mov R2,036h
        setb P1.5
          clr P1.4
        jmp tormoz_back_end

        INTERVAL_TB:
        inc R0
        cjne R0,#255,tormoz_back_end
        dec R3
        mov A,R3
        mov R0,A

        setb P1.4
        clr P1.5

        cjne R3,#15,tormoz_back_end
        mov R7,#0

        clr P1.4
        clr P1.6
        setb P1.5
        setb P1.7


        mov R0, #255
        mov R2, #50
        mov R3, #255

        mov napr,#0
tormoz_back_end: POP ACC
RET

indicator:
        PUSH ACC
        dec R1
        cjne R1,#0,indicator_end
             dec R4
             mov R1,#40
             call vivod
             cjne R4,#0,indicator_end
                  mov R4,#100
                  call calculate
        indicator_end:POP ACC
RET

calculate:
        PUSH ACC
        MOV A,R5
        MOV B,#10
        DIV AB
        MOV desatki,A
        MOV edinicy,B
        MOV R5,#0
        POP ACC
RET

vivod:
      PUSH ACC

      cjne R6,#0,des
      mov A, napr
      cjne A,#0,napravlenie
           mov A,#00100000b
           MOV DPL,#2
           MOVX @DPTR,A
           mov R6,#1
           jmp vivod_end
           napravlenie:
                        mov A,#00101111b
                        MOV DPL,#2
                        MOVX @DPTR,A
                        mov R6,#1
                        jmp vivod_end

      des:
           cjne R6,#1,ed
           MOV A,desatki
           setb ACC.6
           MOV DPL,#2
           MOVX @DPTR,A

           mov R6,#2
           jmp vivod_end

      ed:
           MOV A,edinicy
           setb ACC.7
           MOV DPL,#2
           MOVX @DPTR,A

           mov R6,#0
      vivod_end:POP ACC
RET

counter:
       mov TL0,#82h
       inc R5
RETI

END