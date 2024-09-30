#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <thread>
#include <chrono>
#include <QString>
#include <QPainter>

namespace Ui {
class MainWindow;
}

DWORD WINAPI shellForMetodsMainWindow( void *p );


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    friend DWORD WINAPI shellForMetodsWaitingApplication( void* );
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);

    DWORD timeWait;
    HANDLE processHandle;
    HANDLE winThread = nullptr;
    bool activeMenu = true;

private slots:
    void checkWait();
    void clearMessage();
};


#endif // MAINWINDOW_H
