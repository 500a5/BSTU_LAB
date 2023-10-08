;-----------------------------------------------------------------------------
;debug_except_handler function is written by vkim.
;-----------------------------------------------------------------------------

.386
.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\masm32.inc
include debug.inc

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\masm32.lib

public __fTrap
public __pVar

DebugProc proto :dword

.data?
szNum           byte 12 dup(?)

.data
__fTrap         dword 0
__pVar          dword 0

.code

debug_except_handler proc C pExcept: dword, pFrame: dword, pContext: dword, pDispatch: dword
    local szBuff[32]: byte
    FillString szBuff, <Spied variable = >
    mov edx, pContext
    .if __fTrap == EXCEPTION_SINGLE_STEP
        pushfd
        or dword ptr [esp], 100h
        pop (CONTEXT ptr [edx]).regFlag ;set TF
        mov eax, __pVar
        invoke wsprintf, addr szNum, CTEXT("%li"), dword ptr [eax]
        invoke lstrcat, addr szBuff, addr szNum
        invoke DebugPrint, addr szBuff
    .elseif __fTrap == 1
        pushfd
        or dword ptr [esp], 100h
        pop (CONTEXT ptr [edx]).regFlag ;set TF
        mov __fTrap, EXCEPTION_SINGLE_STEP
    .endif
    mov eax, ExceptionContinueExecution
    ret
debug_except_handler endp

end
