ORG 0h
	jmp main
t0ISR: 
        ORG 0Bh;Указываем где находится обработчик прерывания таймера 0
        CLR TF0;Первой командой обработчика является команда очистки флага прерывания
        MOV TH0,#0ECh;задаем смещение срабатывания таймера
	MOV TL0,#078h
        ;начинаем циклически менять напряжение на порту Р0 и проверять падение напряжений на линиях Р1
        MOV R0,#1b;Пусть изначально проверяем первую линию
        L:
        MOV P0,R0;загружаем с регистра в порт
        jb P0.0,stroca1;Если бит равен 1 то опрашиваем соответствующую строку
        jb P0.1,stroca2
        jb P0.2,stroca3
        ;Значит 4-я строка:
        jmp stroca4
        stroca1:
            JNB P1.0,CH1;Переход если бит равен 0 (нажатие клавиши садит пин на землю)
	    Stolbik2:
            JNB P1.1,CH2
            Stolbik3:
	    JNB P1.2,CH3
            Stolbik4:
	    JNB P1.3,CHC
            Stolbik5:
	    JNB P1.4,CHD
            jmp netnacshatiy
            CH1:
	       MOV A,#31h
	       LCall Uart;Запуск подпрограммы по выводу символа
               jmp Stolbik2;Возвращаемся для продолжения опроса столбцов
            CH2:
	       MOV A,#32h
	       LCall Uart
               jmp Stolbik3
            CH3:
	       MOV A,#33h
	       LCall Uart
               jmp Stolbik4
            CHC:
	       MOV A,#43h
	       LCall Uart
               jmp Stolbik5
            CHD:
	       MOV A,#44h
	       LCall Uart
               jmp netnacshatiy
        stroca2:
            JNB P1.0,CH4;Переход если бит равен 0 (нажатие клавиши садит пин на землю)
	    Stolbik22:
            JNB P1.1,CH5
            Stolbik32:
	    JNB P1.2,CH6
            Stolbik42:
	    JNB P1.3,CHE
            Stolbik52:
	    JNB P1.4,CHF
            jmp netnacshatiy
            CH4:
	       MOV A,#34h
	       LCall Uart;Запуск подпрограммы по выводу символа 4
               jmp Stolbik22;Возвращаемся для продолжения опроса столбцов этой строки
            CH5:
	       MOV A,#35h
	       LCall Uart
               jmp Stolbik32
            CH6:
	       MOV A,#36h
	       LCall Uart
               jmp Stolbik42
            CHE:
	       MOV A,#45h
	       LCall Uart
               jmp Stolbik52
            CHF:
	       MOV A,#46h
	       LCall Uart
               jmp netnacshatiy
        stroca3:
            JNB P1.0,CH7;Переход если бит равен 0 (нажатие клавиши садит пин на землю)
	    Stolbik23:
            JNB P1.1,CH8
            Stolbik33:
	    JNB P1.2,CH9
            Stolbik43:
	    JNB P1.3,CHG
            Stolbik53:
	    JNB P1.4,CHH
            jmp netnacshatiy
            CH7:
	       MOV A,#37h
	       LCall Uart;Запуск подпрограммы по выводу символа
               jmp Stolbik23;Возвращаемся для продолжения опроса столбцов
            CH8:
	       MOV A,#38h
	       LCall Uart
               jmp Stolbik33
            CH9:
	       MOV A,#39h
	       LCall Uart
               jmp Stolbik43
            CHG:
	       MOV A,#47h
	       LCall Uart
               jmp Stolbik53
            CHH:
	       MOV A,#48h
	       LCall Uart
               jmp netnacshatiy
        stroca4:
            JNB P1.0,CHA;Переход если бит равен 0 (нажатие клавиши садит пин на землю)
	    Stolbik24:
            JNB P1.1,CH0
            Stolbik34:
	    JNB P1.2,CHB
            Stolbik44:
	    JNB P1.3,CHI
            Stolbik54:
	    JNB P1.4,CHJ
            jmp netnacshatiy
            CHA:
	       MOV A,#41h
	       LCall Uart;Запуск подпрограммы по выводу символа
               jmp Stolbik24;Возвращаемся для продолжения опроса столбцов
            CH0:
	       MOV A,#30h
	       LCall Uart
               jmp Stolbik34
            CHB:
	       MOV A,#42h
	       LCall Uart
               jmp Stolbik44
            CHI:
	       MOV A,#49h
	       LCall Uart
               jmp Stolbik54
            CHJ:
	       MOV A,#4Ah
	       LCall Uart
        netnacshatiy:
        MOV A,R0;Делаем сдвиг бита влево с помощью Аккумулятора
        RL A
        MOV R0,A
        CJNE R0,#00010000b,LL;Сравнение регистра с константой и переход, если не равно
        sjmp D
        LL: ljmp L;Костыль для того чтобы вернуться к L
        D:
        MOV R0,#0b;Сбрасываем R0 и A в исходное состояние чтобы прерывание не влияло на регистры и эмулятор не выдавал ошибку
        MOV A,#0b
        RETI;Выход из обработчика прерываний
Uart:	
	MOV SBUF,A;отправляем в последовательный порт нажатую клавишу
	;Перевод на новую строку
	MOV A,#13
	MOV SBUF,A
	MOV A,#10
	MOV SBUF,A
	RET
main:        
        ;T1 M1=1 M0=0 вывод в монитор порта
	;T0 M1=0 M0=1 для опросов клавиатуры/16бит
	MOV TMOD,#00100001b
	;передача с скоростью 9600=(2^smod*Fosc)/(32*12*[256-TH])=31250/(256-TH)
	MOV TH1,#0FDh
        ;1-й режим передачи (асинхронный 8 бит в кадре)
	SETB SM1
	CLR SM0
	;опрос клавиатуры с частотой 200гц(5мс)
	MOV TH0,#0ECh;2^16-5000=60536=0EC78h
	MOV TL0,#78h
        ;разрешаем прерывание от таймера 0
        SETB ET0
        ;разрешаем выполнение прерываний
        SETB EA
        SETB TR0;запускаем таймер 0
        jmp $;бесконечный цикл ожидания
END
