#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  showPieDiag();
    timer = new QTimer();
    connect(timer,SIGNAL (timeout()), this, SLOT(timerUpd()));
    timer->start(1000*60);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpd()
{
    sec++; ui->sec->setText(QString::number(sec));
    repaint();
}
void MainWindow::timerEvent(QTimerEvent*)
{
//    ui->sec->setText("0");
//    sec++; ui->sec->setText(QString::number(sec));
//    if (sec >= 60)
//    {
//        repaint();
//        sec = 0;
//    }
}
void MainWindow::showPieDiag()
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(memstat);
    GlobalMemoryStatusEx(&memstat);

    ui->proc->setText(QString::number(memstat.dwMemoryLoad));
    ui->phys_all->setText(QString::number(memstat.ullTotalPhys/ 1024 / 1024) + " МБ");
    ui->phys_awail->setText(QString::number(memstat.ullAvailPhys/ 1024 / 1024) + " МБ");
    ui->v_all->setText(QString::number(memstat.ullTotalVirtual/ 1024 / 1024) + " МБ");
    ui->v_awail->setText(QString::number(memstat.ullAvailVirtual/ 1024 / 1024) + " МБ");
    ui->page_all->setText(QString::number(memstat.ullTotalPageFile/ 1024 / 1024) + " МБ");
    ui->page_awail->setText(QString::number(memstat.ullAvailPageFile/ 1024 / 1024) + " МБ");



}

void MainWindow::paintEvent(QPaintEvent *event)
{
    MEMORYSTATUSEX memstat;
    memstat.dwLength = sizeof(memstat);
    GlobalMemoryStatusEx(&memstat);

    ui->textEdit->setText(QString::number(memstat.dwMemoryLoad));
    ui->phys_all->setText(QString::number(memstat.ullTotalPhys/ 1024 / 1024) + " МБ");
    ui->phys_awail->setText(QString::number(memstat.ullAvailPhys/ 1024 / 1024) + " МБ");
    ui->v_all->setText(QString::number(memstat.ullTotalVirtual/ 1024 / 1024) + " МБ");
    ui->v_awail->setText(QString::number(memstat.ullAvailVirtual/ 1024 / 1024) + " МБ");
    ui->page_all->setText(QString::number(memstat.ullTotalPageFile/ 1024 / 1024) + " МБ");
    ui->page_awail->setText(QString::number(memstat.ullAvailPageFile/ 1024 / 1024) + " МБ");

    //showPieDiag();

    QPoint lt(width()/7,height()/7); //top

    QPainter painter(this);
    QRect rect[6];
    int t = memstat.ullAvailPhys / (double)memstat.ullTotalPhys * 100;

    rect[0] = QRect(lt.x()+100, lt.y()+90, -20, -t);
    rect[1] = QRect(lt.x()+120, lt.y()+90, -20, -100);

    t = memstat.ullAvailVirtual/(double)memstat.ullTotalVirtual * 100;
    rect[2] = QRect(lt.x()+100, lt.y()+220, -20, -t);
    rect[3] = QRect(lt.x()+120, lt.y()+220, -20, -100);

    t = memstat.ullAvailPageFile /(double)memstat.ullTotalPageFile * 100;
    rect[4] = QRect(lt.x()+100, lt.y()+350, -20, -t);
    rect[5] = QRect(lt.x()+120, lt.y()+350, -20, -100);

    painter.setBrush(Qt::darkGray);
    for (int i = 0; i < 6; i++)
        if(i%2==0)
            painter.drawRect(rect[i]);

    painter.setBrush(Qt::gray);
    for (int i = 0; i < 6; i++)
        if(i%2==1)
            painter.drawRect(rect[i]);


}
