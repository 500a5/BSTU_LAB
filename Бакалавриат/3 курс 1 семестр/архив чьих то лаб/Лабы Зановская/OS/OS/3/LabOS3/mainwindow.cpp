#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_waiting_application.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    startTimer( 1000. / 60. );
    ui->setupUi(this);

    mutex = CreateMutexW( nullptr, false, L"OC_LAB3_MUTEX" );

    QObject::connect( ui->pushButton_Create, SIGNAL(clicked(bool)) , this, SLOT(stopTimerSync()));
    QObject::connect( ui->pushButton_start, SIGNAL(clicked(bool)), this, SLOT( startTimerSync()) );
    QObject::connect( ui->pushButton_end, SIGNAL(clicked(bool)), this, SLOT( stopTimerSync() ) );
    QObject::connect( ui->pushButton_start, SIGNAL(clicked(bool)), ui->start_timer, SLOT(setEnabled(bool)) );
    QObject::connect( ui->pushButton_end, SIGNAL(clicked(bool)), ui->start_timer, SLOT(setDisabled(bool)) );
}

DWORD WINAPI shellForMainWindowsMetods( void *p )
{
    dataForMetod* dM = (dataForMetod*)p;
    ((dM->win)->*(dM->metod))();
    delete dM;
    return 0;
}


MainWindow::~MainWindow()
{
    delete ui;
    this->stopTimerSync();
    CloseHandle( mutex );
    if( winThread != nullptr )
        CloseHandle( winThread );
//    this->stopTimerSync();
}

void MainWindow::processMutex()
{
    while( activeTimer )
    {
        WaitForSingleObject( mutex, -1 );
        activeCounting = true;
        for( unsigned char i = 0; i != 5; ++i )
        {
            if( !activeTimer ) goto exit;
            time += 1;
            std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
        }
        activeCounting = false;
        ReleaseMutex( mutex );
    }
    exit :
    activeCounting = false;
    ReleaseMutex( mutex );
    time = 0;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    if( activeCounting )
    {
        QPainter painter(this);
        painter.setPen( Qt::green );
        painter.setBrush( Qt::green );
        painter.drawRect( ui->timer->geometry() );
    }
    else
    {
        QPainter painter(this);
        painter.setPen( Qt::red );
        painter.setBrush( Qt::red );
        painter.drawRect( ui->timer->geometry() );

//        ui->timer->setBackgroundRole( QPalette( Qt::red ) );
    }
    ui->timer->display( time );
}

void MainWindow::timerEvent(QTimerEvent*)
{ repaint(); }



void MainWindow::startTimerSync()
{
    activeTimer = true;
    if( winThread != nullptr )
        CloseHandle( winThread );
    dataForMetod* data = new dataForMetod;
    data->win = this;

    data->metod = &processMutex;
    winThread = CreateThread( nullptr, 0, shellForMainWindowsMetods, data, 0, nullptr);
//    timerThread.detach();
}

void MainWindow::stopTimerSync()
{
    activeTimer = false;
    activeCounting = false;
    time = 0;
}
/*
DWORD WINAPI shellForMetodsWaitingApplication( void* p )
{
    WaitingApplication* data = (WaitingApplication*)p;

    data->activeMenu = false;
    DWORD start_ = GetTickCount();
    switch( WaitForSingleObject( data->processHandle, data->timeWait ) )
    {
    case WAIT_TIMEOUT:
        data->ui->label_4->setText( "Время ожидания истекло" );
        break;

    case WAIT_FAILED:
        data->ui->label_4->setText( "Ошибка вызова функции" );
        break;

    case WAIT_OBJECT_0:
        data->ui->label_4->setText( "Объект был свободен" );
        break;

    case WAIT_ABANDONED:
        data->ui->label_4->setText( "Мьютекс не был освобожден потоком, породившим его" );
        break;

    default:
        data->ui->label_4->setText( "Неизвестная ошибка!!!" );
        break;
    }
    DWORD finish_ = GetTickCount();
    data->ui->label_5->setText( "Время ожидания в мс равно: " + QString().number( finish_ - start_ ) );
    data->activeMenu = true;

    return 0;
}


WaitingApplication::WaitingApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaitingApplication)
{
    ui->setupUi(this);
    QObject::connect( ui->pushButton, SIGNAL( pressed()), this, SLOT( checkWait() )  );
    QObject::connect( ui->checkBox, SIGNAL(clicked(bool)), ui->doubleSpinBox, SLOT(setDisabled(bool)) );

    QObject::connect( ui->pushButton, SIGNAL( pressed()), this, SLOT( clearMessage() )  );
    QObject::connect( ui->checkBox, SIGNAL(clicked(bool)), this, SLOT( clearMessage() ) );
    QObject::connect( ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT( clearMessage() ) );
    QObject::connect( ui->lineEdit, SIGNAL(returnPressed()), this, SLOT( clearMessage() ) );

    startTimer( 1000. / 60. );
}

WaitingApplication::~WaitingApplication()
{
    delete ui;
    if( winThread != nullptr )
        CloseHandle(winThread);
}

void WaitingApplication::paintEvent(QPaintEvent*)
{ ui->centralwidget->setEnabled( activeMenu ); }

void WaitingApplication::timerEvent(QTimerEvent*)
{ this -> repaint();}

void WaitingApplication::checkWait()
{
    if( winThread != nullptr )
    {
        CloseHandle(winThread);
        winThread = nullptr;
    }
    if( ui->checkBox->isChecked() == true )
        timeWait = -1;
    else
        timeWait = ui->doubleSpinBox->value() * 1000;

    HANDLE snapshot; processHandle = 0;
    PROCESSENTRY32W process; process.dwSize = sizeof( process );
    snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if( Process32FirstW( snapshot, &process ) )
    {
        do
        {
            QString nameProcess = QString::fromWCharArray( process.szExeFile );

            if( nameProcess == ui->lineEdit->text() )
            {
                processHandle = OpenProcess( PROCESS_ALL_ACCESS, false, process.th32ProcessID );
                break;
            }
        }
        while( Process32NextW( snapshot, &process ) );
    }
    CloseHandle( snapshot );
    if( processHandle == 0 )
    {
        ui->lineEdit->setText( "" );
        ui->label_4->setText("");
        return;
    }

    winThread = CreateThread( nullptr, 0, shellForMetodsWaitingApplication, this, 0, nullptr );

}

void WaitingApplication::clearMessage()
{
    ui->label_4->setText("");
    ui->label_5->setText("");
}
*/
