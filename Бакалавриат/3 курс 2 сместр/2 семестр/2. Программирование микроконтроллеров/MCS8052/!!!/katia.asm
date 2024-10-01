cseg at 0h
jmp start
     org 8100h
start:             mov DPTR,#3h
    mov A,#82h
       movx @DPTR, A
       setb P1.0
      mov DPTR,#0h
       mov A,#20h
      movx @DPTR,A
         ;****************
       mov 30h,#45
      mov 31h,#20
       mov 32h,#10
      mov 33h,#45
      mov 34h,#0
      mov R7,30h
       mov R0,#30h
    
                    begin:
       mov   R6, #5
      beg:
       acall acp
        sjmp  srav
     m1:
       djnz  R6, beg
       stop:
      sjmp  stop
                 
                       acp:
       setb  P1.0
      call  delay
     call  delay
       call  delay
       clr   P1.0
     k:
        jb    P1.1, k
    mov   DPTR, #1
      movx  A, @DPTR
   subb  A, #30
     mov   R1, A
     ret
          
                     srav:
      mov   A, R1
      mov   50h, R7
     cjne  A, 50h, sr1
       Setb  P1.7
       Setb  P1.6
       acall sec
        inc   R0
       mov   A, @R0
       mov   R7, A
      acall begin1
      acall begin1
      acall begin1
        sjmp  m1
         sr1:
       Jc    dn
       setb  P1.7
      clr   P1.6
     sjmp  beg
       dn:
      setb  P1.6
      clr   P1.7
      sjmp  beg
  
                     delay:
        mov  R3, #0ffh
   d1: djnz R3, d1
         mov  R3, #0ffh
    d2: djnz R3, d2
       mov  R3, #0ffh
    d3: djnz R3, d3
      mov  R3, #0ffh
    d4: djnz R3, d4
        ret
                         
                          sec:
        mov  R4, #25
                         sec1:
      mov  R3, #100
                           sec2:
       mov  R5, #8
     sec3:
      mul  ab
      dec  R2
      cjne R2, #0, sec3
        dec  R3
       cjne R3, #0, sec2
     dec  R4
       cjne R4, #0, sec1
      ret
        begin1:
       call delay
       call delay
     call delay
    call delay
        ret            
   End