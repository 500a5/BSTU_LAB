org 0000h
  jmp Start
org 8100h
Start:
  setb p1.0
  clr psw.4
  clr psw.3
  mov dptr,#03h
  mov a,#82h
  movx @dptr,a
  mov dptr,#00h
  mov a,#10h
  movx @dptr,a
  clr p1.0
IsBusy:
  jb p1.1,IsBusy

Ready:
  mov dptr,#01h
  movx a,@dptr
  setb p1.0
  mov dptr,#02h
  add a,#80h
  clr p1.0
  mov 00h,c
  jnb acc.7,Positive
  cpl a
  inc a
Positive:
  mov b,#19h
  div ab
  setb acc.5
  mov 10h,a
  mov a,b

  rl a
  rl a
  mov b,#0ah
  div ab
  setb acc.6
  mov 11h,a
  setb b.7
  mov 12h,b

Output:
  mov r1,#07h
Output_0:
  mov r2,#0Fh
Output_1:
  mov r0,#12h

OutputNum:
  mov a,@r0
  movx @dptr,a
  mov r4,#00h
Pause_0:
  djnz r4,Pause_0
  dec r0
  cjne r0,#0fh, OutputNum
Pause_1:
  djnz r4,Pause_1
  djnz r2,Output_1
  djnz r1,Output_0
  jb 00h,IsPositive
  mov a,#80h
  movx @dptr,a
  mov r1,#0fh
Pause_2:
  mov r2,#00h
Pause_3:
  djnz r2,Pause_3
  djnz r1,Pause_2
IsPositive:
  jb p1.1, Output
  jmp Ready
end
