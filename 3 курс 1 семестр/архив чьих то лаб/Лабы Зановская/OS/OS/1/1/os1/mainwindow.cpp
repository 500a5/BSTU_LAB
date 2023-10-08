#include <iostream>
#include <thread>
#include <chrono>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Tabl SMTable[] = {
      { SM_CMOUSEBUTTONS,  "SM_CMOUSEBUTTONS",  "Число кнопок на мыши"},
      { SM_CXBORDER,       "SM_CXBORDER",       "Ширина границы окна"},
      { SM_CYBORDER,       "SM_CYBORDER",       "Высота границы окна"},
      { SM_CXCURSOR,       "SM_CXCURSOR",       "Ширина курсора"},
      { SM_CYCURSOR,       "SM_CYCURSOR",       "Высота курсора"},
      { SM_CXDLGFRAME,     "SM_CXDLGFRAME",     "Толщина рамки вокруг периметра окна"},
      { SM_CYDLGFRAME,     "SM_CYDLGFRAME",     "Толщина рамки вокруг периметра окна"},
      { SM_CXDOUBLECLK,    "SM_CXDOUBLECLK",    "Ширина прямоугольника вокруг первого щелчка в последовательности двойного щелчка"},
      { SM_CYDOUBLECLK,    "SM_CYDOUBLECLK",    "Высота прямоугольника вокруг первого щелчка в последовательности двойного щелчка"},
      { SM_CXDRAG,         "SM_CXDRAG",         "Ширина прямоугольника, центрированного на перетаскиваемой точке для ограничения движения указателя мыши перед стартом операции перетаскивания"},
      { SM_CYDRAG,         "SM_CYDRAG",         "Высота прямоугольника, центрированного на перетаскиваемой точке для ограничения движения указателя мыши перед стартом операции перетаскивания"},
      { SM_CXFRAME,        "SM_CXFRAME",        "Толщина рамки вокруг периметра окна, имеющего возможность изменять размеры(ширина горизонтальной границы)"},
      { SM_CYFRAME,        "SM_CYFRAME",        "Толщина рамки вокруг периметра окна, имеющего возможность изменять размеры(высота вертикальной границы)"},
      { SM_CXFULLSCREEN,   "SM_CXFULLSCREEN",   "Ширина клиентской области для полноэкранного окна"},
      { SM_CYFULLSCREEN,   "SM_CYFULLSCREEN",   "Высота клиентской области для полноэкранного окна"},
      { SM_CXHSCROLL,      "SM_CXHSCROLL",      "Ширина изображения стрелки горизонтального слайдера"},
      { SM_CYHSCROLL,      "SM_CYHSCROLL",      "Высота горизонтального слайдера в пикселях"},
      { SM_CXHTHUMB,       "SM_CXHTHUMB",       "Ширина бегунка горизонтального слайдера"},
      { SM_CXICON,         "SM_CXICON",         "Заданная по умолчанию ширина иконки"},
      { SM_CYICON,         "SM_CYICON",         "Заданная по умолчанию высота иконки"},
      { SM_CXICONSPACING,  "SM_CXICONSPACING",  "Ширина ячейки сетки для элементов в виде большой иконки"},
      { SM_CYICONSPACING,  "SM_CYICONSPACING",  "Высота ячейки сетки для элементов в виде большой иконки"},
      { SM_CXMAXIMIZED,    "SM_CXMAXIMIZED",    "Заданные по умолчанию ширина развернутого окна верхнего уровня"},
      { SM_CYMAXIMIZED,    "SM_CYMAXIMIZED",    "Заданные по умолчанию высота развернутого окна верхнего уровня"},
      { SM_CXMAXTRACK,     "SM_CXMAXTRACK",     "Заданные по умолчанию максимальные ширина окна, имеющего заголовок и имеющего возможность изменять свои границы"},
      { SM_CXMAXTRACK,     "SM_CXMAXTRACK",     "Заданные по умолчанию максимальные высота окна, имеющего заголовок и имеющего возможность изменять свои границы"},
      { SM_CXMENUCHECK,    "SM_CXMENUCHECK",    "Ширина заданного по умолчанию растрового рисунка метки меню"},
      { SM_CXMENUCHECK,    "SM_CXMENUCHECK",    "Высота заданного по умолчанию растрового рисунка метки меню"},
      { SM_CXMENUSIZE,     "SM_CXMENUSIZE",     "Ширина кнопок панели меню, таких как кнопка закрытия дочернего окне в документе с многооконным интерфейсом (MIDI)"},
      { SM_CYMENUSIZE,     "SM_CYMENUSIZE",     "Высота кнопок панели меню, таких как кнопка закрытия дочернего окне в документе с многооконным интерфейсом (MIDI)"},
      { SM_CXMIN,          "SM_CXMIN",          "Минимальная ширина окна"},
      { SM_CYMIN,          "SM_CYMIN",          "Минимальная высота окна"},
      { SM_CXMINIMIZED,    "SM_CXMINIMIZED",    "Ширина нормально свернутого окна"},
      { SM_CYMINIMIZED,    "SM_CYMINIMIZED",    "Высота нормально свернутого окна"},
      { SM_CXMINSPACING,   "SM_CXMINSPACING",   "Ширина ячейки сетки для свернутых окон."},
      { SM_CYMINSPACING,   "SM_CYMINSPACING",   "Высота ячейки сетки для свернутых окон."},
      { SM_CXSCREEN,       "SM_CXSCREEN",       "Ширина экрана в пикселях"},
      { SM_CYSCREEN,       "SM_CYSCREEN",       "Высота экрана в пикселях"},
      { SM_CXSIZE,         "SM_CXSIZE",         "Ширина заголовка окна или области заголовка"},
      { SM_CYSIZE,         "SM_CYSIZE",         "Высота заголовка окна или области заголовка"},
      { SM_CXVSCROLL,      "SM_CXVSCROLL",      "Ширина изображения стрелки вертикального слайдера"},
      { SM_CYVSCROLL,      "SM_CYVSCROLL",      "Высота размеры изображения стрелки вертикального слайдера"},
      { SM_CYVTHUMB,       "SM_CYVTHUMB",       "Высота блока бегунка в вертикальном слайдере"},
      { SM_CXSMICON,       "SM_CXSMICOND",      "Рекомендуемая ширина маленькой иконки"},
      { SM_CYSMICON,       "SM_CYSMICON",       "Рекомендуемая высота маленькой иконки"},
      { SM_CXSMSIZE,       "SM_CXSMSIZE",       "Ширина маленьких кнопок заголовка"},
      { SM_CYSMSIZE,       "SM_CYSMSIZE",       "Высота маленьких кнопок заголовка"},
      { SM_CYCAPTION,      "SM_CYCAPTION",      "Высота нормальной области заголовка"},
      { SM_CYMENU,         "SM_CYMENU",         "Высота однострочного меню"},
      { SM_MIDEASTENABLED, "SM_MIDEASTENABLED", "Возвращает TRUE, если система допускает еврейский и арабский языки, иначе 0"}
    };

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ViewText();



    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(ACTIVECAPTION()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(MENUTEXT()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(BTNFACE()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(SLocalTime()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(SystemPowerState()));

    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(DRAGFULLWINDOWS()));
    connect(ui->pushButton_18,SIGNAL(clicked()),this,SLOT(SETLANGTOGGLE()));
    connect(ui->pushButton_19,SIGNAL(clicked()),this,SLOT(SETPOWEROFFTIMEOUT()));


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
    ui->label_userName->setText(str);

    GetUserNameA(buffer, &size);
    str= QString::fromUtf8(buffer);
    ui->label_computerName->setText(str);

    size=256;
    char buf[256];
    GetWindowsDirectoryA(buf, size);
    str= QString::fromUtf8(buf);
    ui->label_catalogWindows->setText(str);

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

    GETICONMETRICS();
    GETMOUSETRAILS();
    GETWORKAREA();
    LOCALTIME();
    TIMEZONE();
    CARETS ();
    KEYBOARDSTATE();
    USERLANGID();

}

 void MainWindow::paintEvent(QPaintEvent*p_event)
 {
     //p=ui->spinBox->value();
     //ui->label_63->setNum(p);
 }

void MainWindow::GETICONMETRICS()
{
    ICONMETRICS icm;
    icm.cbSize = sizeof(icm);
    BOOL res = SystemParametersInfo(SPI_GETICONMETRICS, sizeof(icm), &icm, 0);
    BOOL bTest;
    res = SystemParametersInfo(SPI_GETSNAPTODEFBUTTON, 0, &bTest, 0);
    ui->label_33->setNum((int) icm.cbSize);
    ui->label_34->setNum((int) icm.iHorzSpacing);
    ui->label_35->setNum((int) icm.iVertSpacing);
    ui->label_36->setNum((int) icm.iTitleWrap);

    ui->label_37->setNum((int) icm.lfFont.lfHeight);
    ui->label_38->setNum((int) icm.lfFont.lfWidth);
    ui->label_39->setNum((int) icm.lfFont.lfEscapement);
    ui->label_40->setNum((int) icm.lfFont.lfOrientation);
    ui->label_41->setNum((int) icm.lfFont.lfWeight);
    ui->label_42->setNum((int) icm.lfFont.lfItalic);
    ui->label_43->setNum((int) icm.lfFont.lfUnderline);
    ui->label_44->setNum((int) icm.lfFont.lfStrikeOut);
    ui->label_45->setNum((int) icm.lfFont.lfCharSet);
    ui->label_46->setNum((int) icm.lfFont.lfOutPrecision);
    ui->label_47->setNum((int) icm.lfFont.lfClipPrecision);
    ui->label_48->setNum((int) icm.lfFont.lfQuality);
    ui->label_49->setNum((int) icm.lfFont.lfPitchAndFamily);
    ui->label_50->setText(QString::fromWCharArray(icm.lfFont.lfFaceName));
}

void MainWindow::GETMOUSETRAILS()
{
    LONG mt;
    SystemParametersInfo(SPI_GETMOUSETRAILS, sizeof(mt), &mt, 0);
    ui->label_52->setNum((int) mt);
}

void MainWindow::GETWORKAREA()
{
    RECT wArea;
    SystemParametersInfo(SPI_GETWORKAREA, sizeof(wArea), &wArea, 0);
    ui->label_217->setNum((int) wArea.bottom);
    ui->label_218->setNum((int) wArea.left);
    ui->label_219->setNum((int) wArea.right);
    ui->label_220->setNum((int) wArea.top);
}

void MainWindow::LOCALTIME()
{

    SYSTEMTIME sm;
    GetLocalTime(&sm);
    ui->label_74->setNum(sm.wYear);
    ui->label_75->setNum(sm.wMonth);
    ui->label_76->setNum(sm.wDayOfWeek);
    ui->label_77->setNum(sm.wDay);
    ui->label_78->setNum(sm.wHour);
    ui->label_79->setNum(sm.wMinute);
    ui->label_80->setNum(sm.wSecond);
    ui->label_81->setNum(sm.wMilliseconds);

}

void MainWindow::TIMEZONE()
{
    TIME_ZONE_INFORMATION tziTest;
    DWORD dwRet;
    LONG d=3;
    dwRet = GetTimeZoneInformation(&tziTest);
    if( dwRet == TIME_ZONE_ID_STANDARD )
    {
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
            }
     else
         ui->listWidget->addItem("Летнее время не используется в\nтекущем часовом поясе");
}

void MainWindow::DRAGFULLWINDOWS()
{
    p = ui->lineEdit_23->text().toInt();
    SystemParametersInfo(SPI_SETDRAGFULLWINDOWS,p,0,0);
}

void MainWindow::SETLANGTOGGLE()
{
    p = ui->lineEdit_24->text().toInt();
    if(p==1 || p==2 || p==3)
        SystemParametersInfo(SPI_SETLANGTOGGLE,0,0,p);
}

void MainWindow::BTNFACE()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_BTNFACE};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

}
void MainWindow::MENUTEXT()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_MENUTEXT};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

}

void MainWindow::ACTIVECAPTION()
{
    QColor color = QColorDialog::getColor(Qt::black,this,"Color");
    COLORREF r=RGB(color.red(),color.green(),color.blue());
    int c[]={COLOR_ACTIVECAPTION};
    COLORREF col[]={r};
    SetSysColors(1,c,col);

}
void MainWindow::CARETS ()
{
    /*
    LPPOINT lpPoint;
    GetCaretPos(lpPoint);
    ui->label_95->setNum((int)lpPoint->x);
    ui->label_96->setNum((int)lpPoint->y);
    */
}


void MainWindow::SLocalTime()
{
    SYSTEMTIME sm, stLocal;
    GetLocalTime(&sm);
    SystemTimeToTzSpecificLocalTime(NULL, &sm, &stLocal);
    ui->label_85->setNum(stLocal.wYear);
    ui->label_88->setNum(stLocal.wMonth);
    ui->label_89->setNum(stLocal.wDayOfWeek);
    ui->label_90->setNum(stLocal.wDay);
    ui->label_336->setNum(stLocal.wHour);
    ui->label_337->setNum(stLocal.wMinute);
    ui->label_338->setNum(stLocal.wSecond);
    ui->label_340->setNum(stLocal.wMilliseconds);
}

void MainWindow::KEYBOARDSTATE()
{
 /*   PBYTE lpKeyState;
    GetKeyboardState(lpKeyState);
    ui->label_97->setNum((int)lpKeyState);
    */
}

void MainWindow::USERLANGID()
{

    LANGID defaultLangID;
    LANGID GetUserDefaultLangID(void);
    ui->label_106->setNum((int)GetUserDefaultLangID());
}

void MainWindow::SystemPowerState()
{
    SetSystemPowerState(false,false);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Ждем 3с..
    SetSystemPowerState(true,true);
}
