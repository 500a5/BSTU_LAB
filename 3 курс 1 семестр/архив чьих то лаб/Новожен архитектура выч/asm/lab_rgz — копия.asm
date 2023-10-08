.386
.model flat,stdcall
option casemap:none
include E:\masm32\include\windows.inc
include E:\masm32\include\user32.inc
include E:\masm32\include\kernel32.inc
include E:\masm32\include\gdi32.inc

includelib E:\masm32\lib\user32.lib 
includelib E:\masm32\lib\kernel32.lib 
includelib E:\masm32\lib\gdi32.lib

WinMain proto :DWORD,:DWORD,:DWORD,:DWORD
;public WndProc
.data?
hInstance dd ? 
CommandLine dd ?
.data
ClassName db "SimpleWinClas",0
AppName db "Novozhen.N.V",0
areaX SDWORD ? 
areaY SDWORD ? 
areaR SDWORD ? 
maxX SDWORD ? 
maxY SDWORD ? 
areaI SDWORD 100

sx SDWORD ? 
sy SDWORD ?


;;my code
CONST_N macro
3
endm


Rect struc
LX SDWORD ?
LY SDWORD ?
SizeX SDWORD ?
SizeY SDWORD ?
Rect ends
;;my code

ArrRect Rect  3 dup (<?>)


 ballX SDWORD 250
 ballY SDWORD 250
 ballR SDWORD 10 ;������ ����
 ballS SDWORD 5 ; speed 
 ballA SDWORD 60
 ballA_ SDWORD ?
 
 temp SDWORD ?
 
c180 SDWORD 180 
c100 SDWORD 100 
c90 SDWORD 90 
c5 SDWORD 5 
cPi SDWORD 3.14159 
c2 SDWORD 2 
c1 SDWORD 1 
c0 SDWORD 0

t1 SDWORD ?
t2 SDWORD ? 
t3 SDWORD ?

hdc SDWORD ?
memBit SDWORD ?
hBitmap SDWORD ?

ps	PAINTSTRUCT <?>

.code 
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
				mov eax, sx
			
;+++++++++++++++++++++++++++++++++++++
;xxxxxxxxxxxxxxxxxxxxxxxxxxxxXXXXXXXXXXXXXXXX			
				fld ballX
				fld ballR
				fadd
				fstp t1
				
				fld ballX
				fld ballR
				fsub
				fstp t2

				
				.if t1 >= eax 
					fld sx 
					fld ballR 
					fsub 
					fstp ballX
				
					fld ballA 
					fchs 
					fstp ballA 
				.elseif t2 <= 0 
					fld ballR 
					fstp ballX
					
					fld ballA 
					fchs 
					fstp ballA 
				.endif
				
				
				;yyyyyyyyyyyyyyyyyyyyyY
				mov eax, sy
				
				fld ballY 
				fld ballR 
				fadd 
				fstp t1

				fld ballY 
				fld ballR 
				fsub 
				fstp t2

				.if t1 >= eax 
					fld sy 
					fld ballR 
					fsub 
					fstp ballY

					fld c180
					fld ballA
					fsub
					fstp ballA
				.elseif t2 <= 0
					fld ballR
					fstp ballY

					fld c180
					fld ballA
					fsub
					fstp ballA
				.endif
			
;++++++++++++++++++++++++++++++++++++++++++++++			
			
			
			
			
			
			
			; ����������� ����
			fld ballA
			fld cPi
			fmul
			fld c180
			fdiv
			fstp ballA_
			; ���������� dx
			fld ballA_
			fsin
			fld ballS
			fmul
			fld ballX
			fadd
			fstp ballX
			; ���������� dy
			fld ballA_
			fcos
			fld ballS
			fmul
			fstp temp
			fld ballY
			fld temp
			fsub
			fstp ballY
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