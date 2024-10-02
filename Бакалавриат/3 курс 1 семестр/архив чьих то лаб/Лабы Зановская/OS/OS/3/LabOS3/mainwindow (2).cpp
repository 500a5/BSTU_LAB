#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_waiting_application.h"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    startTimer(1000. / 60.);
    ui->setupUi(this);

    mutex = CreateMutexW(nullptr, false, L"OC_LAB3_MUTEX");

    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(stopTimerSync()));
    QObject::connect(ui->start_timer, SIGNAL(clicked(bool)), this, SLOT(startTimerSync()));
    QObject::connect(ui->stop_timer, SIGNAL(clicked(bool)), this, SLOT(stopTimerSync()));
    QObject::connect(ui->start_timer, SIGNAL(clicked(bool)), ui->start_timer, SLOT(setEnabled(bool)));
    QObject::connect(ui->stop_timer, SIGNAL(clicked(bool)), ui->start_timer, SLOT(setDisabled(bool)));
}

DWORD WINAPI shellForMainWindowsMetods(void *p)
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
    CloseHandle(mutex);
    if(winThread != nullptr)
        CloseHandle(winThread);
}

void MainWindow::processMutex()
{
    while(activeTimer)
    {
        WaitForSingleObject(mutex, -1);
        for(unsigned char i = 0; i != 5; ++i)
        {
            if(!activeTimer)goto exit;
            time += 1;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        ReleaseMutex(mutex);
    }
    exit :
    ReleaseMutex(mutex);
    time = 0;
}



void MainWindow::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.drawRect(ui->timer->geometry());

    ui->timer->display(time);
}

void MainWindow::timerEvent(QTimerEvent*)
{ repaint(); }



void MainWindow::startTimerSync()
{
    activeTimer = true;
    if(winThread != nullptr)
        CloseHandle(winThread);
    dataForMetod* data = new dataForMetod;
    data->win = this;    
    data->metod = &processMutex;

    winThread = CreateThread(nullptr, 0, shellForMainWindowsMetods, data, 0, nullptr);
}

void MainWindow::stopTimerSync()
{
    activeTimer = false;
  //  activeCounting = false;
    time = 0;
}
