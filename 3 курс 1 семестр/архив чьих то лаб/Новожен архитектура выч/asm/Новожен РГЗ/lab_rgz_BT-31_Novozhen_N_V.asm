.386
.model flat,stdcall
option casemap:none
include E:\masm32\include\windows.inc
include E:\masm32\include\user32.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\gdi32.inc
INCLUDE E:\masm32\include\msvcrt.inc

includelib E:\masm32\lib\msvcrt.lib
includelib E:\masm32\lib\user32.lib 
includelib E:\masm32\lib\kernel32.lib 
includelib E:\masm32\lib\gdi32.lib
 
 
WinMain proto :DWORD,:DWORD,:DWORD,:DWORD
.data?
hInstance dd ? 
CommandLine dd ?
N equ 4 ;macros
.data
ClassName db "SimpleWinClas",0
AppName db "Novozhen.N.V",0
maxX SDWORD ? 
maxY SDWORD ? 

sx SDWORD ? ;real time window x
sy SDWORD ? ; real time windowy

 ballX SDWORD 300 ;x 
 ballY SDWORD 300; y
 ballR SDWORD 10 ;������ ����
 c100 SDWORD 100 ;timer
 c1 SDWORD 1      ;timer
 c0 SDWORD 0      ;timer
 c2 SDWORD 2      ;timer
 temp SDWORD ? ;tmp help
 t1 SDWORD ?
 t2 SDWORD ?
 ballDX SDWORD 3 ;speed x
 ballDY SDWORD 2 ;speed y
 ballS SDWORD 2 ; speed t
 
 
Rect struc
LX SDWORD ?
LY SDWORD ?
SizeX SDWORD ?
SizeY SDWORD ?
Rect ends
;ArrRect Rect  20 dup (<?>)
ArrRect Rect <400,400,200,300>
		 Rect <200,200,50,50>
		 Rect <0,0,150,150>
		 Rect <500,500,600,100>

hdc SDWORD ?
memBit SDWORD ?
hBitmap SDWORD ?

ps	PAINTSTRUCT <?>
.code 
DrawPoligons proc  padr:DWORD,count:DWORD
PUSH ECX
PUSH EBX
PUSH EAX
PUSH EDX
PUSH EDI
MOV EBX,padr
MOV ECX,count
MOV EAX,16
j1:
PUSH ECX
PUSH EAX
assume EBX:ptr Rect
MOV EDI,[EBX].LX
MOV EDX,[EBX].LY
PUSH EDI
PUSH EDX
MOV EDX,[EBX].SizeY;;;;;;;xxx
ADD EDX,EDI
PUSH EDX
MOV EDI,[EBX].LY
MOV EDX,[EBX].SizeX;;;;;;;;;;;;yyyyyy
ADD EDX,EDI
PUSH EDX
PUSH memBit
CALL Rectangle
POP EAX
POP ECX
ADD EBX,EAX
loop j1
POP EDI
POP EDX
POP EAX
POP EBX
POP ECX
RET
DrawPoligons endp

Collision proc   padr:DWORD,count:DWORD
	PUSH EAX
	PUSH EDX
	PUSH ECX
	PUSH EDI
	PUSH ESI
	PUSH EBX
	MOV ECX,count
	MOV ESI,padr
	MOV EBX,16
	assume ESI:ptr Rect
	j73:

		fild [ESI].LX
		fild [ESI].SizeX
		faddp st(1),st
		fistp t1 ;Dx
		
		fild [ESI].LY
		fild [ESI].SizeY
		faddp st(1),st
		fistp t2;Dy
		
		MOV eax,ballY
		.IF([ESI].LY <= EAX)
			.IF(EAX <= t2)
				MOV EAX,ballX
				ADD EAX,ballR
				.IF([ESI].LX <= EAX)
					.IF(EAX <= t1)
						fild ballDX
						FCHS
						fistp ballDX
						JMP jjj
					.ENDIF
				.ENDIF
				MOV EAX,ballX
				SUB EAX,ballR
				.IF([ESI].LX <= EAX)
					.IF(EAX <= t1)
						fild ballDX
						FCHS
						fistp ballDX
						JMP jjj
					.ENDIF
				.ENDIF
			.ENDIF
		.ENDIF	
		
		
		MOV eax,ballX
		.IF([ESI].LX <= EAX)
			.IF(EAX <= t1)
				MOV EAX,ballY
				SUB EAX,ballR
				
				.IF([ESI].LY <= EAX)
					.IF(EAX <= t2)
						fild ballDY
						FCHS
						fistp ballDY
						JMP jjj
					.ENDIF
				.ENDIF
				MOV EAX,ballY
				ADD EAX,ballR ;up
				.IF([ESI].LY <= EAX)
					.IF(EAX <= t2)
						fild ballDY
						FCHS
						fistp ballDY
						JMP jjj
					.ENDIF
				.ENDIF
			.ENDIF
		.ENDIF	

	.IF(ECX>0) 
	DEC ECX
	ADD ESI,EBX
	JMP j73
	.ENDIF
	
		jjj:
	POP EBX
	POP ESI
	POP EDI
	POP ECX
	POP EDX
	POP EAX
	RET
Collision endp


start:
		invoke GetModuleHandle, NULL 
		mov	hInstance,eax ;���������� ���������� ����������
		;���� ���������� �������� ����� ������ ���� ��������� � �� �������� ������������. 
		;���������� hInstance ���� ����� ��������� ��������, ���������� � ��������� ���������.
		
		;HINSTANCE hPrevInstance � ���������� ����������� ���������� ����������.
		;���� ���������� ������� �� ������ ������ Windows - ������ �����, ��� �� ������� �� ����������.
		;HINSTANCE hPrevInstance=NULL � ���������
		invoke GetCommandLine ;get
		mov	CommandLine,eax ;��������� �� ������ ��������� ������, ��������� ��� ������� ���������.
		;int nCmdShow � ��� �������� �������� �������� ��� ���� (��������, ��������� ��� �����������)
		;int nCmdShow=SW_SHOWDEFAULT 
		invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT 
		invoke ExitProcess, eax

WinMain proc hInst:HINSTANCE, hPrevInst:HINSTANCE, CmdLine:LPSTR, CmdShow:DWORD
		LOCAL wc:WNDCLASSEX ;SS:0018FF68  ��������� WNDCLASSEX �������� ���������� � ������ ���a
		LOCAL msg:MSG ;SS:0018FF4C //��������� ���������
		LOCAL hwnd:HWND ;SS:0018FF78 ���������� - ���������� ����� ���������� ���� ���������
	
		mov wc.cbSize, SIZEOF WNDCLASSEX ;������������� ������ ���� ���������, � ������
		mov wc.style, CS_HREDRAW or CS_VREDRAW ;������������� �����(�) ������. ���� ���� ��������� ����� ���� ����� ����������� ������ ������
		mov wc.lpfnWndProc,OFFSET   WndProc ;��������� �� ������� ���������.
		mov wc.cbClsExtra,NULL ;������������� ����� �������������� ����, ������� ����������� ����� �� ���������� ������ ����
		mov wc.cbWndExtra,NULL ;������������� ����� �������������� ������, ������� ����������� ����� �� ����������� ����
		push hInstance ;���������� ����������, ������� �������� ������� ��������� ��� ������.
		pop wc.hInstance
		mov wc.hbrBackground, COLOR_WINDOW+1;���������� ����� ���� ������.
		mov wc.lpszMenuName ,NULL ;��������� �� ���������� ������ � �������� ����� ������ ('\0')
		mov wc.lpszClassName, OFFSET ClassName ;��������� �� ���������� ������ � ����� � ����� ���  ����
	
		invoke LoadIcon,hInst,500
		mov wc.hIcon, eax ;���������� ������ ������
		
		mov wc.hIconSm,eax ;���������� ���������� ������, ������� ������ � ������� ����
		invoke LoadCursor,NULL,IDC_ARROW
		mov wc.hCursor,eax ;���������� ������� ������
		invoke RegisterClassEx,addr wc ; ������������ ����� ���� ��� ������������ �������������
		;CreateWindowEx ������� �������������, ������������� ��� �������� ���� � ����������� ������
		
		;DWORD dwExStyle,      // ���������� ����� ����
		;LPCTSTR lpClassName,  // ��������� �� ������������������ ��� ������
		;LPCTSTR lpWindowName, // ��������� �� ��� ����
		;DWORD dwStyle,        // ����� ����
		;int x,                // �������������� ������� ����
		;int y,                // ������������ ������� ����
		;int nWidth,           // ������ ����
		;int nHeight,          // ������ ����
		;HWND hWndParent,      // ���������� ������������� ��� ���� ���������
		;HMENU hMenu,          // ���������� ���� ��� ID ��������� ����
		;HINSTANCE hInstance,  // ���������� ���������� ���������� ���������
		;LPVOID lpParam        // ��������� �� ������ �������� ����
		
		;���� ������� ����������� �������, ������������ �������� - ���������� ���������� ����.
		INVOKE CreateWindowEx,NULL,ADDR ClassName,ADDR AppName,\
			13303808,CW_USEDEFAULT,\
			CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,\
			hInst,NULL
		mov hwnd,eax ;���������� ���������� ����.
		invoke LoadMenu,hInst,600 ;���p����� ������������� p���p� ����
		invoke SetMenu,hwnd,eax ;������������� � ��p�p��������� ���� ���� ��� ����, ��p��������� ��p����p�� Menu
	
		invoke ShowWindow,hwnd,SW_SHOWNORMAL ;hwnd-������������p ���� 
		;����p����� ��� �p���� ���� ��p����, ��������� ��p����p�� CmdShow
		invoke UpdateWindow,hwnd  ;��������� ������� ������� ��������� ���� hwnd -���������� ����
		.WHILE TRUE ;��������� ���� ��������� ���������
		
				;ADDR msg ��������� �� ��������� ���������, 
				;� ������� GetMessage ������ ���������.
				;2 �������� -��������� ����, �� �������� GetMessage ������ ��������� 
				;(NULL ��������, ��� GetMessage ��������� ��������� �� ���� ����, ������������� ������
				;3 �������� UINT wMsgFilterMin � ���������� ������������� ���������, ������� ������ GetMessage
				;4 �������� UINT wMsgFilterMax � ���������� ������������� ���������, ������� ������ GetMessage 
				;(���� � ��������� ���������� wMsgFilterMin � wMsgFilterMax �������� 0, ������� ����� ��������� ��� ���������)
				invoke GetMessage,ADDR msg,NULL,0,0
				;� eax ��������� -���������� ���������
				.BREAK .IF (!eax)
				invoke TranslateMessage, ADDR msg ;��������� use ����������
				invoke DispatchMessage, ADDR msg ;������� ���������� windows
		.ENDW
		mov eax,msg.wParam ;���������� �������������� ���������� � ���������
		ret
WinMain endp
	;
	; ������ ��������� 
	;
	
	
;		HWND hwnd,���������� ������� ���������, ������� �������� ���������
;		UINT uMsg,���������� ���������.
;		WPARAM wParam,���������� �������������� ���������� � ���������
;		LPARAM lParam ���������� �������������� ���������� � ���������
WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
		;##################################close window
		.if uMsg==WM_DESTROY ;���������� ����� ���������� ���������� ����
		;������� DeleteObject ������� ���������� ����, �����, �����, �������� ��������, ������ ��� �������,
		;���������� ��� ��������� �������, ��������� � ��������
			invoke DeleteObject,memBit;���������� ������������ �������
		;������� PostQuitMessage ��������� �������, ��� ����� ������ ������ �� ��, ����� ��������� ���� ������
		;�������� ���������� ��� ���������� ���������� ���������.
			invoke PostQuitMessage, NULL
		;##################################create window
		.elseif uMsg==WM_CREATE ;��������� �����, ����� ��������� �����������, ������� ����� ������� CreateWindowEx ,������ ���� ������� ����
			;set timer 
			fild c1
			fild c100
			fdiv
			fst temp
			;HWND hWnd, ���������� ����, ������� ������� � ��������
			;UINT_PTR nIDEvent, ��������� ������������� ������� �������� �� ����
			;UINT uElapse,��������� �������� ������� �������, � �������������.
			;TIMERPROC lpTimerFun ��������� �� �������, ������� ����������, ����� �������� ������� ������� ��������
			invoke SetTimer,hWnd,1,c1,0
			
			
			
			; get max size window 
			invoke GetSystemMetrics, SM_CXSCREEN
			mov maxX, eax
			invoke GetSystemMetrics,SM_CYSCREEN;������ � ������ ������ � ��������
			mov maxY, eax
	
			; ��������� ��������� 
			;��������� ���������� ����������� ��������� ����������
			invoke GetDC, hWnd ;hWnd ���������� ����
			mov hdc, eax
			;�������� ����� � ������ 
			;c������ �������� ���������� � ������ 
			invoke CreateCompatibleDC, hdc 
			mov memBit, eax
			; CreateCompatibleBitmap  ������� �������� �������
			;HDC hdc,        // ���������� DC
			;int nWidth,     // ������ �������, � ��������
			;int nHeight     // ������ �������, � ��������
			invoke CreateCompatibleBitmap, hdc, maxX, maxY 
			mov hBitmap, eax
			;���� ������� ����������� �������, ������������ �������� - ���������� 
			;������������ ��������� ������� (���������-��������� �������� �������� (DDB)
		
			
			;SelectObject �������� ������ � �������� �������� ���������� (DC). 
			;����� ������ �������� ���������� ������ ���� �� ������ ���
			invoke SelectObject, memBit, hBitmap
			
			; ########################################### ���������
			.elseif uMsg==WM_PAINT ; ������� ��� ������ ���������� ������ ������ �� ������������ ����� ���� ����������
				; ��������� �������
				invoke PatBlt, memBit, 0, 0, maxX, maxY, WHITENESS
				;BOOL PatBlt(
				;HDC hdc,      // ���������� ��������� ���������� (DC)
				;int nXLeft,   // x-���������� �������� ������ ���� ��������������
				;int nYLeft,   // y-���������� �������� ������ ���� ��������������
				;int nWidth,   // ������ ��������������
				;int nHeight,  // ������ ��������������
				;DWORD dwRop   // ��� ��������� ��������
				invoke GetStockObject, c1;��������� ���������� ������ �� ���������������� (�����������) ������, ������, ������� ��� ������
				invoke SelectObject, memBit, eax
				;;;;;;;;;;;;;;;;;;------------------------------------------------------------------------------
				; �����
				fld ballY
				fld ballR
				fadd
				fstp temp
				push temp
				
				fld ballX
				fld ballR
				fadd
				fstp temp
				push temp
				
				fld ballY
				fld ballR
				fsub
				fstp temp
				push temp
				
				fld ballX
				fld ballR
				fsub
				fstp temp
				push temp
				
				push memBit
				call Ellipse
				
	
;MY
				INVOKE DrawPoligons  ,offset ArrRect,N
				
;MY				
				
				; ��������� �� ������ � ����
				;HWND hwnd,            // ���������� ����
				;LPPAINTSTRUCT lpPaint // ���������� �� �����������
				invoke BeginPaint, hWnd, offset ps
				mov hdc, eax
				
				;BOOL BitBlt(
				;HDC hdcDest, // ���������� �������� DC
				;int nXDest,  // x-�����. ������ �������� ���� �������� ��������������
				;int nYDest,  // y-�����. ������ �������� ���� �������� ��������������
				;int nWidth,  // ������ �������� ��������������
				;int nHeight, // ������ �������� ��������������
				;HDC hdcSrc,  // ���������� ��������� DC
				;int nXSrc,   // x-�����. ������ �������� ���� ��������� ��������������
				;int nYSrc,   // y-�����. ������ �������� ���� ��������� ��������������
				;DWORD dwRop  // ��� ��������� ��������
				invoke BitBlt, hdc, 0, 0, sx, sy, memBit, 0, 0, SRCCOPY
				invoke EndPaint, hWnd, offset ps ;�������� ����� ����������� � �������� ����
				
				
				; ########################################### ��������� ������� ���� 
			.elseif uMsg==WM_SIZE ;���������� ���� ����� ����, ��� ��� ������ ���������
				xor eax, eax
				mov ax, word ptr lParam
				mov sx, eax
				mov eax, eax
				mov eax, lParam
				shr eax, 16
				mov sy, eax
								
				;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;########################################### ������������ ������� 
			.elseif uMsg==WM_TIMER
			;WM_TIMER �������� �����������������

		
;MY
			INVOKE Collision,offset ArrRect,N
;;MY
			
			
			mov eax,ballX
			.IF(c0>=eax || sx<=eax )
				fild ballDX
				FCHS
				fistp ballDX
			.ENDIF
			mov eax,ballY
			.IF(c0>=eax || sy<=eax )
				fild ballDY
				FCHS
				fistp ballDY
			.ENDIF			

			; ���������� dx
			fild ballX
			fild ballDX
			fild ballS
			fmulp st(1),st
			faddp st(1),st
			FRNDINT
			fistp ballX
			; ���������� dy
			fild ballY
			fild ballDY
			fild ballS
			fmulp st(1),st
			faddp st(1),st
			FRNDINT
			fistp ballY
			

			
			invoke InvalidateRect, hWnd, 0, 0  ;��������� ������������� ��� ����������� ����
			;HWND hWnd,		// ��������� �� ����
			;CONST RECT *lpRect,	// ������������� �����������
			;BOOL bErase		// ����� �����������
;########################################### meni ###############################################################

			.else
				invoke DefWindowProc, hWnd, uMsg, wParam, lParam 
				;������� DefWindowProc ���������� ������� ���������� �� ���������,
				;����� ���������� ��������� �� ��������� ������ ��������� ����, ������� ���������� �� ������������
				ret
		.endif
	xor eax , eax
	ret
WndProc endp
end start	