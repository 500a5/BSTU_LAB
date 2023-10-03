    org 00h
    jmp start
    ORG 8100h
OutpDigit_Cur:              ;����� �������� ����
    mov dptr, #port_c       ;����� ����� ���� �
    mov A, R2               ;� R2 �������
    movx @dptr, A           ;������� �� 2 ���������
    call Delay
    mov A, R1               ;� R1 �������
    movx @dptr, A           ;������� �� 1 ���������
    call Delay
ret
OutpDigit_Targ:             ;����� �������� ����
    mov dptr, #port_c       ;����� ����� ���� �
    mov A, 53h              ;� 53h �������
    ;mov A, #01h
    orl A, #40h             ;�������� 3 ���������
    ;add A, #40h
    ;orl A, #01000000b
    movx @dptr, A           ;������� �� 3 ���������
    call Delay
    mov A, 54h              ;� 54h �������
    ;mov A, #02h
    orl A, #80h             ;�������� 3 ���������
    ;add A, #80h
    ;orl A, #10000000b
    movx @dptr, A           ;������� �� 3 ���������
    call Delay
ret
Read_ADC:                   ;������ � ���
    mov R1, #010h
    mov R2, #020h
    ;mov R3, #040h
    ;mov R4, #080h
    setb p1.0
    clr p1.0
    jb p1.1,$
    mov DPTR, #port_b
    movx A, @DPTR
ret
Perevod:
    mov B, #46h
    mul AB
    mov R7, A
    mov A, B
    mov B, #0Ah
    div AB
    swap A
    mov R6, A
    mov A, B
    mov A, R7
    clr Acc.0
    clr Acc.1
    clr Acc.2
    clr Acc.3
    add A, B
    swap A
    mov B, #0Ah
    div AB
    add A, R6
    mov R6, A
    mov A, R7
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    swap A
    add A, B
    swap A
    mov B, #0Ah
    div AB
    mov R5, A
    mov A, B
    add A, R4
    mov R4, A
    mov A, R6
    mov B, #0Ah
    div AB
    swap A
    mov R6, A
    mov A, R5
    swap A
    add A, B
    swap A
    mov B, #0Ah
    div AB
    add A, R6
    mov R6, A
    mov A, B
    add A, R3
    mov R3, A
    mov A, R6
    mov B, #0Ah
    div AB
    add A, R1
    mov R1, A
    mov A, B
    add A, R2
    mov R2, A
ret
Translate:                  ; ��������� �������� ���������� R1 � R2 ������
    mov A, R2
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    mov R2, A
    mov A, R1
    clr Acc.4
    clr Acc.5
    clr Acc.6
    clr Acc.7
    ;swap A
    mov B, #0Ah
    mul AB
    add A, R2
ret
Delay:
    mov 32h, #5
cicl:
    mov 33h, #100
    djnz 33h, $
    djnz 32h, cicl
ret

    port_a equ 0h
    port_b equ 01h
    port_c equ 02h
    port_d equ 03h
    _bis_ equ 82h
    for_A equ 011h

tbl: db 2dh,14h,50h


start:

    mov 50h,#2dH
    mov 51h,#14h
    mov 52h,#50h
    mov 53h,#00h

    mov DPTR,#8230h
    mov A,#2dh
    movx @DPTR,A
    
    mov A,#00h
    movx A,@DPTR
    


    mov A,30h

    mov A,#0h
    movc A,@A + DPTR
    jmp $
end
