#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_waiting_application.h"


DWORD WINAPI shellForMetodsWaitingApplication(void* p)
{
    MainWindow* data = (MainWindow*)p;

    data->activeMenu = false;
    DWORD start_ = GetTickCount();
    switch(WaitForSingleObject(data->processHandle, data->timeWait))
    {
    case WAIT_TIMEOUT:
        data->ui->label_4->setText("Время ожидания истекло");
        break;

    case WAIT_FAILED:
        data->ui->label_4->setText("Ошибка вызова функции");
        break;

    case WAIT_OBJECT_0:
        data->ui->label_4->setText("Объект был свободен");
        break;

    case WAIT_ABANDONED:
        data->ui->label_4->setText("Мьютекс не был освобожден потоком, породившим его");
        break;

    default:
        data->ui->label_4->setText("Неизвестная ошибка!!!");
        break;
    }
    DWORD finish_ = GetTickCount();
    data->ui->label_5->setText("Время ожидания: " + QString().number(finish_ - start_) + " мс");
    data->activeMenu = true;

    return 0;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(checkWait()) );
    QObject::connect(ui->checkBox, SIGNAL(clicked(bool)), ui->doubleSpinBox, SLOT(setDisabled(bool)));

    QObject::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(clearMessage()) );
    QObject::connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(clearMessage()));
    QObject::connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(clearMessage()));
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(clearMessage()));

    startTimer(1000. / 60.);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(winThread != nullptr)
        CloseHandle(winThread);
}

void MainWindow::paintEvent(QPaintEvent*)
{
    ui->centralwidget->setEnabled(activeMenu);
}

void MainWindow::timerEvent(QTimerEvent*)
{ this -> repaint();}

void MainWindow::checkWait()
{
    if(winThread != nullptr)
    {
        CloseHandle(winThread);
        winThread = nullptr;
    }
    if(ui->checkBox->isChecked() == true)
        timeWait = -1;
    else
        timeWait = ui->doubleSpinBox->value() * 1000;

    HANDLE snapshot; processHandle = 0;
    PROCESSENTRY32W process; process.dwSize = sizeof(process);
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(Process32FirstW(snapshot, &process))
    {
        do
        {
            QString nameProcess = QString::fromWCharArray(process.szExeFile);
            if(nameProcess == ui->lineEdit->text())
            {
                processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, process.th32ProcessID);
                break;
            }
        }
        while(Process32NextW(snapshot, &process));
    }
    CloseHandle(snapshot);
    if(processHandle == 0)
    {
        ui->lineEdit->setText("");
        ui->label_4->setText("");
        return;
    }
    winThread = CreateThread(nullptr, 0, shellForMetodsWaitingApplication, this, 0, nullptr);
}

void MainWindow::clearMessage()
{
    ui->label_4->setText("");
    ui->label_5->setText("");
}
