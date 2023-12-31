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

start:
    clr RS0
    clr RS1
    orl TMOD, #01h
    mov DPTR, #port_d
    mov A, #_bis_
    movx @DPTR, A
    mov DPTR, #port_a
    mov A, #for_A
    movx @DPTR, A
    call Read_ADC           ;������ �� ���
    call Perevod            ;������� � �������
    call OutpDigit_Cur      ;����� �������� ����
    call Translate          ;������� (���������� R1 � R2)
    mov 50h, A              ;���������� � 50h
    mov 70h, #08h           ;� 70h 2 �������

begin:
    setb p1.6               ;������ ���
    clr p1.7                ;������ ���
    ;clr p1.6
    ;setb p1.7
    ;mov 41h, #2Dh
    ;mov 42h, #14h
    ;mov 43h, #50h
    ;mov 44h, #0h
    ;mov R0, 41h
go:
    mov A, 70h
    rl A                    ;����� ������ - �������� 4 �������
    mov 70h, A
    jbc p1.7, decrem
    add A, 50h              ;���������� � �������� ����
    mov 50h, A              ;��������� ������� ����
    jmp hod
decrem:
    mov A, 50h
    subb A, 70h
    mov 50h, A
    setb p1.7
    clr p1.6
    jmp hod
hod:
    mov B, #0Ah             ;� � 10
    div AB                  ;����� ���������� � �� 10
    mov 53h, A              ;� 53h �������
    mov 54h, B              ;� 54h �������
    call OutpDigit_Targ     ;����� �������� ����
m:
    call Read_ADC           ;������ � ���
    call Perevod            ;�������
    call OutpDigit_Cur      ;����� �������� ����
    call OutpDigit_Targ
    call Translate
    cjne A, #0h, more_zero  ;���� ������� ���� �� ����� 0, �� �� more_zero
    jmp mend                ;����� �� mend
more_zero:
    cjne A, #5Ah, less_90   ;���� ������� ���� �� ����� 90, �� �� less_90
    jmp mend                ;����� �� mend
less_90:
    ;cjne A, R0, m          ;���� ������� �� ����� �������� �� �� m
    cjne A, 50h, m
    jbc p1.6, reverse_trace ;���� ���������� p1.6 d ������� �� �� reverse_trace
forward_trace:              ;������ ���
    setb p1.6
    clr p1.7
    ;inc R0
    ;mov 77h, #2Dh
    mov 50h, A
    jmp go
    ;setb p1.7
    ;clr p1.6
reverse_trace:              ;������
    mov 50h, A
    clr p1.6
    setb p1.7
    ;mov 77h, #14h
    ;inc R0
    ;mov 50h, A
    ;clr p1.7
    ;setb p1.6
    jmp go
mend:                       ;������� ���
    setb p1.6
    setb p1.7
    jmp $
end
