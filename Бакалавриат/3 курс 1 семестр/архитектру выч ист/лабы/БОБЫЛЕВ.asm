.386
.MODEL FLAT, STDCALL
OPTION CASEMAP: NONE

include c:\masm32\include\windows.inc
include c:\masm32\include\user32.inc
include c:\masm32\include\gdi32.inc
include c:\masm32\include\kernel32.inc
include c:\masm32\include\msvcrt.inc

includelib c:\masm32\lib\user32.lib
includelib c:\masm32\lib\gdi32.lib
includelib c:\masm32\lib\kernel32.lib
includelib c:\masm32\lib\msvcrt.lib

.DATA?
		  hInstance HINSTANCE ?				; Дескриптор нашей пpогpаммы

.DATA
		  className DB "MyAsmClass", 0		; Имя нашего класса окна
		  titleName DB "MY WINDOW", 0		; Имя нашего окна

		  startWidth DD 600					; ширина окна при запуске
		  startHeight DD 600				; высота окна при запуске

		  clientWidth DD 800
		  clientHeight DD 800

		  backgroundColor DD 010608h		; цвет фона
		  SphereColor DD 0b02effh			; цвет сферы
		  ballsColor DD 9600ffh				; цвет шарика
		  

		  ballstopX DD 0.0					; x центра сферы
		  ballstopY DD 0.0					; у центра сферы


		  ballnull DD 0.0	

		  ballpart DD 2.0	; для деления 

		  ballX DD 400.0					; х центра шарика при старте
		  ballY DD 400.0					; у центра шарика при старте
		  ballRadius DD 50					; r шарика
		  ballVectorX DD 2.0				; смещение по х
		  ballVectorY DD 5.0				; смещение по у

		  min1 DD -1.0
		  NormVectX DD 0.0
		  NormVectY DD 0.0
		  BasVectX DD 0.0
		  BasVectY DD 0.0
		  cofX DD 0.0
		  cofY DD 0.0
		  
		  x1 DD 0.0
		  y1 DD 0.0

		  timer DD 1
.CODE
; переместить шарик
moveBalls PROC
		  FLD ballX				; St(0) = ballX
		  FADD ballVectorX		; St(0) = ballX + ballVectorX
		  FSTP ballX			; ballX += ballVectorX  c выталкиванием

		  FLD ballY				; St(0) = ballY
		  FADD ballVectorY		; St(0) = ballY + ballVectorX
		  FSTP ballY			; ballY += ballVectorX  c выталкиванием

		  RET
moveBalls ENDP

; обработка столкновений
handleWallCollisions PROC
		; обработка столкновений с боковыми стенками
		FILD clientWidth		; St(0) = ширина окна
		FSUB ballX				; St(0) = ширина окна - х шарикa
		FILD ballRadius			; St(0) = r шарикa .. St(1) = ширина окна - х шарикa
		FCOMPP					; сравнение с двойным выталкиванием
		FSTSW AX				; AX = слово состояния сопроцессора
		SAHF					; загружает флаги SF, ZF, AF, PF и CF из AH
			JA collision_1X		; r шарикa > ширина окна - х шарикa (плохо)
		FLD ballX				; St(0) = х шарикa
		FILD ballRadius			; St(0) = r шарикa .. St(1) = х шарикa
		FCOMPP					; сравнение
		FSTSW AX
		SAHF
			JBE collision_2_if	; r шарикa <= х шарикa  (все ок)
	
	; - столкновение с боковыми стенками	
	collision_1X:	
		FLD ballVectorX		; St(0) = смещение по х
		FCHS				; ST(0) = -ST(0)
		FSTP ballVectorX	; извлечь в ballVectorX

	; обработка столкновений с горизонтальными стенками
	collision_2_if:		
		FILD clientHeight	; St(0) = высота окна
		FSUB ballY			; St(0) = высота окна - у шарикa
		FILD ballRadius		; St(0) = r шарикa .. St(1) = высота окна - у шарикa
		FCOMPP				; сравнение
		FSTSW AX
		SAHF
			JA collision_1Y		; r шарикa > высота окна - у шарикa (плохо)
		FLD ballY
		FILD ballRadius
		FCOMPP
		FSTSW AX
		SAHF
			JBE collision_circle	; r шарикa <= y шарикa  (все ок)
		jmp collision_1Y			; иначе (плохо)

	; обработка столкновений со сферой
	collision_circle:
		; вычисление расстояния между центрами шарика и сферы 
		; по формуле √((x c - x ш)^2 + (y c - y ш)^2)
		FLD ballstopX		; St(0) = x сферы
		FLD ballX			; St(0) = x шарикa .. St(1) = x сферы
		FSUBP ST(1), ST(0)	; St(0) = x сферы - x шарикa
		FST ST(1)			; St(0) = x сферы - x шарикa .. St(1) = St(0)
		FMULP ST(1), ST(0)	; St(0) = (x c - x ш)^2
		
		FLD ballstopY		; St(0) = у c .. St(1) = (x c - x ш)^2
		FLD ballY			; St(0) = у ш .. St(1) = у c .. St(2) = (x c - x ш)^2
		FSUBP ST(1), ST(0)	; St(0) = y c - y ш .. St(1) = (x c - x ш)^2
		FST ST(2)			; St(0) = y c - y ш .. St(1) = (x c - x ш)^2 .. St(2) = y c - y ш
		FMULP ST(2), ST(0)	; St(0) = (x c - x ш)^2 .. St(1) = (y c - y ш)^2
		
		FADDP ST(1), ST(0) 	; St(0) = (x c - x ш)^2 + (y c - y ш)^2
		FSQRT				; St(0) = расстояние между центрами

		FILD clientHeight	; St(0) = высота окна .. St(1) = расстояние
		FLD ballpart		; St(0) = 2 .. St(1) = высота окна .. St(2) = расстояние
		FDIVP ST(1), ST(0)	; St(0) = r сферы .. St(1) = расстояние
		FIADD ballRadius	; St(0) = r сферы + r шарикa .. St(1) = расстояние
		FCOMPP				; сравнение
		FSTSW AX
		SAHF
			JAE collision_circle2	; r сферы + r шарикa >= расстояние (плохо)
		JMP collision_end			; иначе (все ок)

	; - столкновениe со сферой
	collision_circle2:
		; находим координаты нормали
		; т. O(0, 0) - центр сферы
		; т. А(ballX, ballY) - центр шарикa
		; вектор OA = {A.x - O.x; A.y - O.y} 
		; направление вектора нормали неважно
		FLD ballX			; St(0) = x шарикa
		FSUB ballstopX
		FSTP NormVectX		; NormVectX = x шарикa

		FLD ballY
		FSUB ballstopY
		FSTP NormVectY		; NormVectY = y шарикa
		
		; находим длину вектора нормали
		FLD NormVectX		; St(0) = NormVectX
		FMUL NormVectX		; St(0) = NormVectX ^2
		FLD NormVectY
		FMUL NormVectY		; St(0) = NormVectY ^2 .. St(1) = NormVectX ^2

		FADDP ST(1), ST(0)	; St(0) = NormVectY ^2 + NormVectX ^2
		FSQRT				; St(0) = √(NormVectY ^2 + NormVectX ^2) - длина вектора нормали
		
		; находим проекцию на нормаль
		; Проекция в. a на направление в. b = скалярное произведение a и b / длина в. b
		; a = {а.х; а.у} - в. падения;  b = {b.х; b.у} - нормаль
		; (а.х*b.х + а.у*b.у) / |b| = а.х*b.х / |b|  +  а.у*b.у / |b|
		FLD NormVectX		; St(0) = b.х .. St(1) = |b|
		FDIV ST(0), ST(1)	; St(0) = b.х / |b|  .. St(1) = |b|
		FSTP NormVectX		; NormVectX = St(0)
		FLD NormVectY		; St(0) = b.у .. St(1) = |b|
		FDIVRP ST(1), ST(0)	; St(0) = b.у / |b|
		FSTP NormVectY		; NormVectY = St(0)


		; для проекции в. а' на нормаль 
		; в. а' - это  в. а повернутый по часовой стрелке на 90 градусов
		; a = {а.у; -а.х}
		FLD NormVectY		; St(0) = b.у / |b| 
		FCHS				; St(0) = -b.у / |b| 
		FSTP BasVectX		; BasVectX = -b.у / |b| 

		FLD NormVectX		
		FSTP BasVectY		; BasVectY = b.х / |b|
		
		; a = {а.х; а.у} - в. падения  = {ballVectorX; ballVectorY}
		FLD NormVectX		; St(0) = b.х / |b|
		FMUL ballVectorX	; St(0) = а.х * b.х / |b|  
		FLD NormVectY		; St(0) = b.у / |b| .. St(1) = а.х * b.х / |b|
		FMUL ballVectorY	; St(0) = b.у / |b| * а.у .. St(1) = а.х * b.х / |b|
		FADDP ST(1), ST(0)	; St(0) = проекция в. a на нормаль
		FCHS				; St(0) = -St(0) 
		FSTP cofX			; cofX = -проекция в. a на нормаль

		FLD BasVectX		; St(0) = -b.у / |b|
		FMUL ballVectorX	; St(0) = a.x * -b.у / |b|
		FLD ballVectorY		
		FMUL BasVectY		; St(0) = a.y * b.х / |b| .. St(1) = a.x * -b.у / |b|  
		FADDP ST(1), ST(0)	; St(0) = a.y * b.х / |b| + a.x * -b.у / |b|
		FSTP cofY			; cofY = проекция в. a' на нормаль


		FLD NormVectX		; St(0) = b.х / |b|
		FMUL cofX			; St(0) = -проекция в. a на нормаль * b.х / |b|
		FSTP NormVectX		; NormVectX = -проекция в. a на нормаль * b.х / |b|

		FLD NormVectY		; St(0) = b.у / |b|
		FMUL cofX			; St(0) = -проекция в. a на нормаль * b.у / |b|
		FSTP NormVectY		; NormVectY = -проекция в. a на нормаль * b.у / |b|

		FLD BasVectX		; St(0) = -b.у / |b|
		FMUL cofY			; 
		FSTP BasVectX		; BasVectX = проекция в. a' на нормаль * (-b.у / |b|)

		FLD BasVectY
		FMUL cofY
		FSTP BasVectY		; BasVectY = проекция в. a' на нормаль * b.х / |b|

		
		FLD NormVectY		; St(0) = -проекция в. a на нормаль * b.у / |b|
		FLD BasVectY		; St(0) = проекция в. a' на нормаль * b.х / |b|  .. St(1)
		FADDP ST(1), ST(0)	; St(0) = -проекция в. a на нормаль * b.у / |b| + проекция в. a' на нормаль * b.х / |b|
		FSTP ballVectorY	; ballVectorY = St(0)

		FLD NormVectX		; St(0) = -проекция в. a на нормаль * b.х / |b|
		FLD BasVectX		; St(0) = проекция в. a' на нормаль * (-b.у / |b|)  .. St(1)
		FADDP ST(1), ST(0)	; St(0) = -проекция в. a на нормаль * b.х / |b| + проекция в. a' на нормаль * (-b.у / |b|) 
		FSTP ballVectorX	; ballVectorX = St(0)

		jmp collision_end
		
	; столкновение с горизонтальными стенками	
	collision_1Y:
		FLD ballVectorY		 
		FCHS
		FSTP ballVectorY	; ballVectorY = -ballVectorY

	collision_end:
		RET
handleWallCollisions ENDP

; обработка 
handleWindowMessage PROC hWindow:HWND,\; хэндл окна, котоpому пpедназначается сообщение
						 message:UINT,\; сообщение
						 wParam:WPARAM, lParam:LPARAM ; доп парамметры
		local windowRect:RECT
		local hDC:HDC
		local hCompatibleDC:HDC
		local hBitmap:HBITMAP
		local ps:PAINTSTRUCT
		local backgroundBrush:HBRUSH
		local ellipseBrush:HBRUSH
		local sphereBrush:HBRUSH
		local ellipsePen:HPEN
		local spherePen:HPEN
		local left:DWORD
		local top:DWORD
		local right:DWORD
		local bottom:DWORD

		MOV EBX, message

		.IF message == WM_CREATE		; сообщение о создании окна
				invoke SetTimer, hWindow, timer, 1, NULL	; Создает таймер с указанным значением времени ожидания (3 парам.)

		.ELSEIF message == WM_DESTROY	; сообщении о закpытии окна
				invoke KillTimer, hWindow, timer
				invoke PostQuitMessage, NULL	; выходим из пpогpаммы

		.ELSEIF message == WM_PAINT		; запрос на рисование части окна приложения
				invoke GetClientRect, hWindow, ADDR windowRect	; Получает координаты клиентской области окна
				MOV EAX, windowRect.right
				SUB EAX, windowRect.left
				MOV clientWidth, EAX
				MOV EAX, windowRect.bottom
				SUB EAX, windowRect.top
				MOV clientHeight, EAX

				invoke BeginPaint, hWindow, ADDR ps	; подготавливает указанное окно для рисования и заполняет структуру ps информацией о картине
				MOV hDC, EAX
				invoke CreateCompatibleDC, hDC		; создает контекст устройства памяти (DC)
				MOV hCompatibleDC, EAX
				invoke CreateCompatibleBitmap, hDC, clientWidth, clientHeight	; создает растровое изображение, совместимое с устройством, которое связано с указанным контекстом устройства
				MOV hBitmap, EAX
				invoke SelectObject, hCompatibleDC, hBitmap	; выбирает объект hBitmap 

				invoke CreateSolidBrush, backgroundColor
				MOV backgroundBrush, EAX
				invoke FillRect, hCompatibleDC, ADDR windowRect, backgroundBrush
				invoke DeleteObject, backgroundBrush
				
				;отображение шарикa
				invoke CreatePen, PS_SOLID, 3, ballsColor
				MOV ellipsePen, EAX
				invoke CreateSolidBrush, ballsColor
				MOV ellipseBrush, EAX
				invoke SelectObject, hCompatibleDC, ellipsePen
				invoke SelectObject, hCompatibleDC, ellipseBrush
				FLD ballX
				FISUB ballRadius
				FISTP left
				FLD ballY
				FISUB ballRadius
				FISTP top
				FLD ballX
				FIADD ballRadius
				FISTP right
				FLD ballY
				FIADD ballRadius
				FISTP bottom
				invoke Ellipse, hCompatibleDC, left, top, right, bottom
				invoke DeleteObject, ellipsePen
				invoke DeleteObject, ellipseBrush
				
				;отображение сферы
				invoke CreatePen, PS_SOLID, 3, SphereColor
				MOV spherePen, EAX
				invoke CreateSolidBrush, SphereColor
				MOV sphereBrush, EAX
				invoke SelectObject, hCompatibleDC, spherePen
				invoke SelectObject, hCompatibleDC, sphereBrush
				
				FILD clientHeight
				FLD ballpart
				FDIVP ST(1), ST(0)
				FLD ballstopX
				FSUBRP ST(1), ST(0)
				FISTP left
				FILD clientHeight
				FLD ballpart
				FDIVP ST(1), ST(0)
				FLD ballstopY
				FSUBRP ST(1), ST(0)
				FISTP top
				FILD clientHeight
				FLD ballpart
				FDIVP ST(1), ST(0)
				FLD ballstopX
				FADDP ST(1), ST(0)
				FISTP right
				FILD clientHeight
				FLD ballpart
				FDIVP ST(1), ST(0)
				FLD ballstopY
				FADDP ST(1), ST(0)
				FISTP bottom
				invoke Ellipse, hCompatibleDC, left, top, right, bottom

				invoke DeleteObject, spherePen
				invoke DeleteObject, sphereBrush
				
				invoke SetStretchBltMode, hDC, COLORONCOLOR
				invoke BitBlt, hDC, 0, 0, clientWidth, clientHeight, hCompatibleDC, 0, 0, SRCCOPY
				invoke DeleteDC, hCompatibleDC
				invoke DeleteObject, hBitmap

				invoke EndPaint, hWindow, ADDR ps

		.ELSEIF message == WM_TIMER
				invoke handleWallCollisions
				invoke moveBalls
				invoke InvalidateRect, hWindow, NULL, FALSE
		.ELSEIF message == WM_KEYDOWN
				fld1
				cmp wParam, 27
				je m_exit
				cmp wParam, 37
				je m_left
				cmp wParam, 38
				je m_up
				cmp wParam, 39
				je m_right
				cmp wParam, 40
				je m_down
				
				jmp m_end

				m_up:
					fld ballstopY
					fldz
					FCOMPP				; сравнение
					FSTSW AX
					SAHF
					je m_end
				
					fld ballstopY
					fsub st(0), st(1)
					fstp ballstopY
					jmp m_end
				m_down:
					fld ballstopY
					fild clientHeight
					FCOMPP				; сравнение
					FSTSW AX
					SAHF
					je m_end
				
					fld ballstopY
					fadd st(0), st(1)
					fstp ballstopY
					jmp m_end
				m_left:
					fld ballstopX
					fldz
					FCOMPP				; сравнение
					FSTSW AX
					SAHF
					je m_end
					
					fld ballstopX
					fsub st(0), st(1)
					fstp ballstopX
					jmp m_end
				m_right:
					fld ballstopX
					fild clientWidth
					FCOMPP				; сравнение
					FSTSW AX
					SAHF
					je m_end
				
					fld ballstopX
					fadd st(0), st(1)
					fstp ballstopX
					jmp m_end
				m_exit:
					invoke KillTimer, hWindow, timer
					invoke PostQuitMessage, NULL	; выходим из пpогpаммы
					jmp m_end
				m_end:
				fstp st(0)
		.ELSE
				invoke DefWindowProc, hWindow, message, wParam, lParam
				RET
		.ENDIF

		XOR EAX, EAX
		RET
handleWindowMessage ENDP


registerClass PROC
		local windowClass:WNDCLASSEX		; структура хаpактеpистик окна
		
		MOV windowClass.cbSize, SIZEOF WNDCLASSEX			; Размеp стpуктуpы WDNCLASSEX в байтах
		MOV windowClass.style, CS_HREDRAW OR CS_VREDRAW		; Стиль окон, создаваемых из этого класса
												; CS_HREDRAW - Перерисовывает все окно,
												;	если перемещение или регулировка размера изменяют ширину рабочей области
												; CS_VREDRAW - Перерисовывает все окно,
												; 	если перемещение или регулировка размера изменяют высоту рабочей области.
		MOV windowClass.lpfnWndProc, offset handleWindowMessage	; Адpес пpоцедуpы окна, ответственной за окна, создаваемых из класса
		MOV windowClass.cbClsExtra, NULL					; Число дополнительных байт, которые размещаются вслед за структурой класса окна
		MOV windowClass.cbWndExtra, NULL					; Число дополнительных байт, которые размещаются вслед за экземпляром окна
		PUSH hInstance
		POP windowClass.hInstance							; Дескриптор модуля
		MOV windowClass.hbrBackground, COLOR_WINDOW + 1		; Цвет фона
		MOV windowClass.lpszMenuName, NULL					; Дескриптор меню для окон, созданных из класса по умолчанию
		MOV windowClass.lpszClassName, offset className		; Имя класса окна
		invoke LoadIcon, hInstance, IDI_APPLICATION			; ф-ция получения Дескриптора иконки
		MOV windowClass.hIcon, EAX							; Дескриптор иконки
		MOV windowClass.hIconSm, EAX						; Дескриптор маленькой иконки, котоpая сопоставляется классу окна
		invoke LoadCursor, NULL, IDC_ARROW					; ф-ция получения Дескриптора куpсоpа
		MOV windowClass.hCursor, EAX						; Дескриптор куpсоpа
		
		invoke RegisterClassEx, ADDR windowClass			; pегистpация нашего класса окна
		RET
registerClass ENDP


mainWindow PROC nCommandShow:DWORD
		local hWindow:HWND
		local message:MSG
		invoke registerClass

		; создать наше окно
		invoke CreateWindowEx, NULL, offset className, offset titleName,\
				WS_OVERLAPPEDWINDOW OR WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,\
				startWidth, startHeight, NULL, NULL, hInstance, NULL
		;invoke CreateWindowEx, NULL,\				; Дополнительные стили окна
		;		offset className,\					; Адpес стpоки, содеpжащую имя класса окна
		;		offset titleName,\					; Адpес стpоки, содеpжащей имя окна. Оно будет показано на заголовке окна
		;		WS_OVERLAPPEDWINDOW OR WS_VISIBLE,\	; Стили окна
		;		CW_USEDEFAULT, 						; Х - Кооpдината веpнего левого угла окна
		;		CW_USEDEFAULT,\						; У - Кооpдината веpнего левого угла окна
		;		startWidth,\ 						; Шиpина окна в пикселях
		;		startHeight,\						; Высота окна в пикселях
		;		NULL,\								; Дескриптор pодительского окна (если существует)
		;		NULL,\								; Дескриптор меню окна
		;		hInstance,\							; Дескриптор пpогpаммного модуля, создающего окно
		;		NULL								; Опциональный указатель на стpуктуpу данных, пеpедаваемых окну

		MOV hWindow, EAX	; сохранить дескриптор окна
		invoke ShowWindow, hWindow, nCommandShow	; отобpазить наше окно на десктопе
		invoke UpdateWindow, hWindow				; обновить клиентскую область
		; цикл сообщений
		.WHILE TRUE
				invoke GetMessage, ADDR message, NULL, 0, 0	; последовательно пpовеpяется, есть ли сообщения от Windows
				.BREAK .IF (!EAX)
				invoke TranslateMessage, ADDR message		; обpабатывает ввод с клавиатуpы и генеpиpует новое сообщение (WM_CHAR), помещаемое в очеpедь сообщений
				invoke DispatchMessage, ADDR message		; пеpесылает сообщение пpоцедуpе соответствующего окна
		.ENDW
		MOV EAX, message.wParam		; сохpанение возвpащаемого значения в eax
		RET
mainWindow ENDP


START:
		invoke GetModuleHandle, NULL		; Взять дескриптор пpогpаммы
		MOV hInstance, EAX
		invoke mainWindow, SW_SHOWDEFAULT
		invoke ExitProcess, NULL			; Выйти из пpогpаммы.
											; Возвpащаемое значение, помещаемое в eax, беpется из WinMain

END START