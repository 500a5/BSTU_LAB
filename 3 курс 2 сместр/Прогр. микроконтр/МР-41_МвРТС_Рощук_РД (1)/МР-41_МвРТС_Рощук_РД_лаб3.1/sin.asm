ORG 0h
	jmp main

t1ISR:
        ORG 1Bh;Указываем где находится обработчик прерывания таймера 1
        mov DPL,#70h ;Загрузка указателя данных
        mov A, R0;Смещение
        movc A,@A+DPTR ;Пересылка в аккумулятор байта из ПП
        MOV P1,A;Загружаем новое значение
        inc R0
        mov A, R0
        CJNE A,#14h,vihod1 ;Сравнение аккумулятора с константой и переход, если не равно
        mov R0,#0h
        vihod1:
        RETI;Выход из обработчика прерываний
SINUS: 
ORG 70h
           db 0h
           db 6h
           db 18h
           db 35h
           db 58h
           db 80h
           db 0A7h
           db 0CAh
           db 0E7h
           db 0F9h
           db 0FFh
           db 0F9h
           db 0E7h
           db 0CAh
           db 0A7h
           db 80h
           db 58h
           db 35h
           db 18h
           db 6h
ORG 100h
main:        
        ;T1 M1=1 M0=0 для переключения сегментов 8 бит
	 ;T0 M1=0 M0=1 для подсчета времени/16бит
	 MOV TMOD,#00100001b
        mov TH1,#0F3h
       
        ;разрешаем прерывание от таймера 1
        SETB ET1
        ;разрешаем выполнение прерываний
        SETB EA
        CLR p0.7
        SETB TR1;запускаем таймер 1
        jmp $;бесконечный цикл ожидания
END
