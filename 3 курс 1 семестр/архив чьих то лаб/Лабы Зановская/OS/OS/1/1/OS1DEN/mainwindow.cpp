#include <iostream>
#include <thread>
#include <chrono>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Tabl SMTable[] = {
      { SM_CMOUSEBUTTONS,        "SM_CMOUSEBUTTONS",        "Число кнопок на мыши"},
      { SM_CXBORDER,             "SM_CXBORDER",              "Ширина границы окна"},
      { SM_CYBORDER,       "SM_CYBORDER",                    "Высота границы окна"},
      { SM_CXCURSOR,        "SM_CXCURSOR",                   "Ширина курсора"},
      { SM_CYCURSOR,        "SM_CYCURSOR",                   "Высота курсора"},
      { SM_CXDLGFRAME,      "SM_CXDLGFRAME",                 "Толщина рамки вокруг периметра окна(ширина горизонтальной границы)"},
      { SM_CYDLGFRAME,      "SM_CYDLGFRAME",                 "Толщина рамки вокруг периметра окна(высота горизонтальной границы)"},
      { SM_CXDOUBLECLK,     "SM_CXDOUBLECLK",                "Ширина прямоугольника вокруг первого щелчка в последовательности двойного щелчка"},
      { SM_CYDOUBLECLK,     "SM_CYDOUBLECLK",                "Высота прямоугольника вокруг первого щелчка в последовательности двойного щелчка"},
      { SM_CXDRAG,         "SM_CXDRAG",                      "Ширина прямоугольника, центрированного на перетаскиваемой точке для ограничения движения указателя мыши перед стартом операции перетаскивания"},
      { SM_CYDRAG,         "SM_CYDRAG",                      "Высота прямоугольника, центрированного на перетаскиваемой точке для ограничения движения указателя мыши перед стартом операции перетаскивания"},
      { SM_CXFRAME,         "SM_CXFRAME",                    "Толщина рамки вокруг периметра окна, имеющего возможность изменять размеры(ширина горизонтальной границы)"},
      { SM_CYFRAME,         "SM_CYFRAME",                    "Толщина рамки вокруг периметра окна, имеющего возможность изменять размеры(высота вертикальной границы)"},
      { SM_CXFULLSCREEN,    "SM_CXFULLSCREEN",               "Ширина клиентской области для полноэкранного окна"},
      { SM_CYFULLSCREEN,    "SM_CYFULLSCREEN",               "Высота клиентской области для полноэкранного окна"},
      { SM_CXHSCROLL,       "SM_CXHSCROLL",                  "Ширина изображения стрелки горизонтального слайдера"},
      { SM_CYHSCROLL,       "SM_CYHSCROLL",                  "Высота горизонтального слайдера в пикселях"},
      { SM_CXHTHUMB,        "SM_CXHTHUMB",                   "Ширина бегунка горизонтального слайдера"},
      { SM_CXICON,          "SM_CXICON",                     "Заданная по умолчанию ширина иконки"},
      { SM_CYICON,          "SM_CYICON",                     "Заданная по умолчанию высота иконки"},
      { SM_CXICONSPACING,   "SM_CXICONSPACING",              "Ширина ячейки сетки для элементов в виде большой иконки"},
      { SM_CYICONSPACING,   "SM_CYICONSPACING",             "Высота ячейки сетки для элементов в виде большой иконки"},
      { SM_CXMAXIMIZED,      "SM_CXMAXIMIZED",               "Заданные по умолчанию ширина развернутого окна верхнего уровня"},
      { SM_CYMAXIMIZED,      "SM_CYMAXIMIZED",               "Заданные по умолчанию высота развернутого окна верхнего уровня"},
      { SM_CXMAXTRACK,        "SM_CXMAXTRACK",               "Заданные по умолчанию максимальные ширина окна, имеющего заголовок и имеющего возможность изменять свои границы"},
      { SM_CXMAXTRACK,        "SM_CXMAXTRACK",               "Заданные по умолчанию максимальные высота окна, имеющего заголовок и имеющего возможность изменять свои границы"},
      { SM_CXMENUCHECK,        "SM_CXMENUCHECK",             "Ширина заданного по умолчанию растрового рисунка метки меню"},
      { SM_CXMENUCHECK,        "SM_CXMENUCHECK",             "Высота заданного по умолчанию растрового рисунка метки меню"},
      { SM_CXMENUSIZE,          "SM_CXMENUSIZE",             "Ширина кнопок панели меню, таких как кнопка закрытия дочернего окне в документе с многооконным интерфейсом (MIDI)"},
      { SM_CYMENUSIZE,          "SM_CYMENUSIZE",             "Высота кнопок панели меню, таких как кнопка закрытия дочернего окне в документе с многооконным интерфейсом (MIDI)"},
      { SM_CXMIN,           "SM_CXMIN",                      "Минимальная ширина окна"},
      { SM_CYMIN,           "SM_CYMIN",                      "Минимальная высота окна"},
      { SM_CXMINIMIZED,        "SM_CXMINIMIZED",             "Ширина нормально свернутого окна"},
      { SM_CYMINIMIZED,        "SM_CYMINIMIZED",             "Высота нормально свернутого окна"},
      { SM_CXMINSPACING,        "SM_CXMINSPACING",             "Ширина ячейки сетки для свернутых окон. Каждоге свернутое окно помещается в прямоугольник этого размера при упорядочивании"},
      { SM_CYMINSPACING,        "SM_CYMINSPACING",             "Высота ячейки сетки для свернутых окон. Каждоге свернутое окно помещается в прямоугольник этого размера при упорядочивании."},
      { SM_CXSCREEN,        "SM_CXSCREEN",                   "Ширина экрана в пикселях"},
      { SM_CYSCREEN,        "SM_CYSCREEN",                   "Высота экрана в пикселях"},
      { SM_CXSIZE,          "SM_CXSIZE",                     "Ширина заголовка окна или области заголовка"},
      { SM_CYSIZE,          "SM_CYSIZE",                     "Высота заголовка окна или области заголовка"},
      { SM_CXVSCROLL,       "SM_CXVSCROLL",                  "Ширина изображения стрелки вертикального слайдера"},
      { SM_CYVSCROLL,       "SM_CYVSCROLL",                  "Высота размеры изображения стрелки вертикального слайдера"},
      { SM_CYVTHUMB,        "SM_CYVTHUMB",                   "Высота блока бегунка в вертикальном слайдере"},
      { SM_CXSMICON,     "SM_CXSMICOND",                     "Рекомендуемая ширина маленькой иконки"},
      { SM_CYSMICON,           "SM_CYSMICON",                "Рекомендуемая высота маленькой иконки"},
      { SM_CXSMSIZE,     "SM_CXSMSIZE",                      "Ширина маленьких кнопок заголовка"},
      { SM_CYSMSIZE,           "SM_CYSMSIZE",                "Высота маленьких кнопок заголовка"},

      { SM_CYCAPTION,     "SM_CYCAPTION",                    "Высота нормальной области заголовка"},
      { SM_CYMENU,           "SM_CYMENU",                    "Высота однострочного меню"},
      { SM_MIDEASTENABLED, "SM_MIDEASTENABLED",              "Возвращает TRUE, если система допускает еврейский и арабский языки, иначе 0"}
    };

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ViewText();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(DRAGHEIGHT()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(LOWPOWERACTIVE()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(SCREENREADER()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(BTNTEXT()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(APPWORKSPACE()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(SCROLLBAR()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(SLocalTime()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(Cursor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::ViewText()
{
    char buffer[MAX_COMPUTERNAME_LENGTH];
    DWORD size =MAX_COMPUTERNAME_LENGTH+1;
   // GetComputerName(buffer, &size);
    GetComputerNameA(buffer, &size);
    QString str((char*)buffer);
    ui->label_3->setText(str);

    GetUserNameA(buffer, &size);
    str= QString::fromUtf8(buffer);
    ui->label_4->setText(str);

    size=256;
    char buf[256];
    GetWindowsDirectoryA(buf, size);
    str= QString::fromUtf8(buf);
    ui->label_8->setText(str);

    GetSystemDirectoryA(buf, size);
    str= QString::fromUtf8(buf);
    ui->label_9->setText(str);

    GetTempPathA( size,buf);
    str= QString::fromUtf8(buf);
    ui->label_10->setText(str);

    OSVERSIONINFO os;
    SecureZeroMemory(&os, sizeof(OSVERSIONINFO));
    os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&os);
    ui->label_11->setText(QString::number(os.dwMajorVersion)+'.'+QString::number(os.dwMinorVersion));

    //Tabl
    ui->tableWidget->setRowCount(50);
    ui->tableWidget->setColumnCount(3);
    for (int i=0; i< ui->tableWidget->rowCount(); i++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(SMTable[i].String));
            ui->tableWidget->setItem(i,0,itm);
            QTableWidgetItem *itm2 = new QTableWidgetItem(tr("%1").arg(SMTable[i].String2));
            ui->tableWidget->setItem(i,1,itm2);
            QTableWidgetItem *itm3 = new QTableWidgetItem(tr("%1").arg(GetSystemMetrics(SMTable[i].Const)));
            ui->tableWidget->setItem(i,2,itm3);
        }

    LOGFONT lf;
    ZeroMemory(&lf, sizeof(lf));

    SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(lf), &lf, 0);
    //ui->label_22->setNum();
    ui->label_22->setNum((int) lf.lfHeight);
    ui->label_23->setNum((int) lf.lfWidth);
    ui->label_24->setNum((int) lf.lfEscapement);
    ui->label_25->setNum((int) lf.lfOrientation);
    ui->label_26->setNum((int) lf.lfItalic);
    ui->label_27->setNum((int) lf.lfUnderline);
    ui->label_28->setNum((int) lf.lfStrikeOut);
    //WCHAR* tc=;
    ui->label_29->setText(QString::fromWCharArray(lf.lfFaceName));

    NONCLIENTMETRICS noncl;
    ZeroMemory(&noncl, sizeof(noncl));
    noncl.cbSize=sizeof(noncl);
    SystemParametersInfo(SPI_GETNONCLIENTMETRICS, 0, &noncl,0);
    //ui->label_30->setNum((int)noncl.cbSize);
    ui->label_46->setNum((int) noncl.cbSize);
    ui->label_47->setNum((int) noncl.iBorderWidth);
    ui->label_48->setNum((int) noncl.iScrollWidth);
    ui->label_49->setNum((int) noncl.iScrollHeight);
    ui->label_50->setNum((int) noncl.iCaptionWidth);
    ui->label_51->setNum((int) noncl.iCaptionHeight);
    ui->label_52->setText(QString::fromWCharArray(noncl.lfCaptionFont.lfFaceName));
    ui->label_53->setNum((int) noncl.iSmCaptionWidth);
    ui->label_54->setNum((int) noncl.iSmCaptionHeight);
    ui->label_55->setText(QString::fromWCharArray(noncl.lfSmCaptionFont.lfFaceName));
    ui->label_56->setNum((int) noncl.iMenuWidth);
    ui->label_57->setNum((int) noncl.iMenuHeight);
    ui->label_58->setText(QString::fromWCharArray(noncl.lfMenuFont.lfFaceName));
    ui->label_59->setText(QString::fromWCharArray(noncl.lfStatusFont.lfFaceName));
    ui->label_60->setText(QString::fromWCharArray(noncl.lfMessageFont.lfFaceName));

    //ui->listWidget->addItem(QString::fromWCharArray(noncl.lfCaptionFont.lfFaceName) + QString::number((int) noncl.iCaptionHeight)+"ЯЯЯ");
    int n;
    SystemParametersInfo(SPI_ICONHORIZONTALSPACING, 0, &n,0);
    ui->label_62->setNum(n);


    SYSTEMTIME sm;
    GetSystemTime(&sm);
    ui->label_74->setNum(sm.wYear);
    ui->label_75->setNum(sm.wMonth);
    ui->label_76->setNum(sm.wDayOfWeek);
    ui->label_77->setNum(sm.wDay);
    ui->label_78->setNum(sm.wHour);
    ui->label_79->setNum(sm.wMinute);
    ui->label_80->setNum(sm.wSecond);
    ui->label_81->setNum(sm.wMilliseconds);

    TIME_ZONE_INFORMATION tziTest;
    DWORD dwRet;
    LONG d=3;
    dwRet = GetTimeZoneInformation(&tziTest);
     //ui->label_66->setNum((int)tziTest.Bias);
     //ui->label_66->setText(QString::fromWCharArray(tziTest.DaylightName));
     if( dwRet == TIME_ZONE_ID_STANDARD )
     {
         //ui->label_66->setText(QString::fromWCharArray(tziTest.StandardName));
         ui->listWidget->addItem("Используется летнее время");
         ui->listWidget->addItem(QString::fromWCharArray(tziTest.StandardName));
         ui->listWidget->addItem("Значение смещения, используемое в ходе\n преобразований местного времени,\nкоторые имеют место в ходе перехода\n на зимнее время: "+QString::number((int)tziTest.StandardBias));
         ui->listWidget->addItem("Год: "+QString::number((int)tziTest.StandardDate.wYear));
         ui->listWidget->addItem("Месяц: "+QString::number((int)tziTest.StandardDate.wMonth));
         ui->listWidget->addItem("День недели: "+QString::number((int)tziTest.StandardDate.wDayOfWeek));
         ui->listWidget->addItem("День:"+QString::number((int)tziTest.StandardDate.wDay));
         ui->listWidget->addItem("Час: "+QString::number((int)tziTest.StandardDate.wHour));
         ui->listWidget->addItem("Минута: "+QString::number((int)tziTest.StandardDate.wMinute));
         ui->listWidget->addItem("Секунда: "+QString::number((int)tziTest.StandardDate.wSecond));
         ui->listWidget->addItem("Миллисекунда: "+QString::number((int)tziTest.StandardDate.wMilliseconds));
     }
     else if( dwRet == TIME_ZONE_ID_DAYLIGHT )
            {
                 ui->listWidget->addItem("Используется зимнее время");
                 ui->listWidget->addItem(QString::fromWCharArray(tziTest.DaylightName));
                 ui->listWidget->addItem("Значение смещения, используемое в ходе\n преобразований местного времени,\nкоторые имеют место в ходе перехода\n на летнее время: "+QString::number((int)tziTest.StandardBias));
                 ui->listWidget->addItem("Год: "+QString::number((int)tziTest.DaylightDate.wYear));
                 ui->listWidget->addItem("Месяц: "+QString::number((int)tziTest.DaylightDate.wMonth));
                 ui->listWidget->addItem("День недели: "+QString::number((int)tziTest.DaylightDate.wDayOfWeek));
                 ui->listWidget->addItem("День:"+QString::number((int)tziTest.DaylightDate.wDay));
                 ui->listWidget->addItem("Час: "+QString::number((int)tziTest.DaylightDate.wHour));
                 ui->listWidget->addItem("Минута: "+QString::number((int)tziTest.DaylightDate.wMinute));
                 ui->listWidget->addItem("Секунда: "+QString::number((int)tziTest.DaylightDate.wSecond));
                 ui->listWidget->addItem("Миллисекунда: "+QString::number((int)tziTest.DaylightDate.wMilliseconds));
            }
     else
         ui->listWidget->addItem("Летнее время не используется в\n текущем часовом поясе");
       //ui->label_66->setNum((int)GetLastError());
     RECT rec;
     GetClipCursor(&rec);
     ui->label_95->setNum((int) rec.left);
     ui->label_96->setNum((int) rec.top);
     ui->label_97->setNum((int) rec.right);
     ui->label_98->setNum((int) rec.bottom);

     int klava=GetKeyboardType(0);
     switch (klava) {
     case 1:
         ui->label_102->setText("83-клавишная клавиатура для IBM PC/XT -совместимых компьютеров");
         break;
     case 2:
         ui->label_102->setText("102-клавишная клавиатура Olivetti");
         break;
     case 3:
         ui->label_102->setText("IBM PC/AT -совместимая клавиатура (84клавиши)");
         break;
     case 4:
         ui->label_102->setText("Расширенная IBM-клавиатура (101- или 102 клавиши)");
         break;
     case 5:
         ui->label_102->setText("Клавиатура Nokia 1050");
         break;
     case 6:
         ui->label_102->setText("Клавиатура Nokia 9140");
         break;
     case 7:
         ui->label_102->setText("Японская клавиатура");
         break;
     }
     //ui->label_102->setNum(klava);
     klava=GetKeyboardType(1);
     ui->label_103->setNum(klava);
     klava=GetKeyboardType(2);
     switch (klava) {
     case 1:
         ui->label_104->setNum(10);
         break;
     case 2:
         ui->label_104->setNum(12);
         break;
     case 3:
         ui->label_104->setNum(10);
         break;
     case 4:
         ui->label_104->setNum(12);
         break;
     case 5:
         ui->label_104->setNum(10);
         break;
     case 6:
         ui->label_104->setNum(24);
         break;
     default:
         ui->label_104->setText("Определено аппаратно и зависит от OEM");
         break;
     }
     //ui->label_104->setNum(klava);
     ui->label_106->setNum((int)GetUserDefaultLCID());

}

 void MainWindow::paintEvent(QPaintEvent*p_event)
 {
     //p=ui->spinBox->value();
     //ui->label_63->setNum(p);
 }

void MainWindow::DRAGHEIGHT()
{
    //p=ui->spinBox->value();
    p=ui->lineEdit->text().toInt();
   // ui->label_63->setNum(p);
    SystemParametersInfo(SPI_SETDRAGHEIGHT,p,0,0);

}

void MainWindow::LOWPOWERACTIVE()
{
    //p=ui->spinBox->value();
    p=ui->lineEdit_2->text().toInt();
   // ui->label_63->setNum(p);
    if(p==0 || p==1)
        SystemParametersInfo(SPI_SETLOWPOWERACTIVE,p,0,0);

}

void MainWindow::SCREENREADER()
{
    //p=ui->spinBox->value();
    p=ui->lineEdit_3->text().toInt();
    //ui->label_63->setNum(p);
    SystemParametersInfo(SPI_SETSCREENREADER,p,0,0);

}

void MainWindow::BTNTEXT()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    //color.green()
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_BTNTEXT};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

    /*ui->label_63->setNum(GetRValue(r));
    ui->label_64->setNum(GetGValue(r));
    ui->label_65->setNum(GetBValue(r));*/
}

void MainWindow::APPWORKSPACE()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    //color.green()
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_APPWORKSPACE};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

}

void MainWindow::SCROLLBAR()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    //color.green()
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_SCROLLBAR};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

}

void MainWindow::SLocalTime()
{
    SYSTEMTIME lt;
    lt.wDay=ui->lineEdit_4->text().toInt();
    lt.wDayOfWeek=ui->lineEdit_5->text().toInt();
    lt.wMonth=ui->lineEdit_6->text().toInt();
    lt.wYear=ui->lineEdit_7->text().toInt();
    lt.wHour=ui->lineEdit_8->text().toInt();
    lt.wMinute=ui->lineEdit_9->text().toInt();
    lt.wSecond=ui->lineEdit_10->text().toInt();
    lt.wMilliseconds=ui->lineEdit_11->text().toInt();
    SetLocalTime(&lt);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void MainWindow::Cursor()
{
    ShowCursor(false); // Скрываем курсор
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Ждем 3с..
    ShowCursor(true);

}
