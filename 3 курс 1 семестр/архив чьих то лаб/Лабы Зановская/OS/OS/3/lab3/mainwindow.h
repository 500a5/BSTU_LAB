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
DWORD WINAPI shellForMainWindowsMetods(void *p);
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);

private:
    Ui::MainWindow *ui;
    friend DWORD WINAPI shellForMainWindowsMetods(void *);
    bool activeTimer = false;
    HANDLE mutex;
    HANDLE winThread = nullptr;
    int time = 0;
    void processMutex();
private slots:
    void startTimerSync();
    void stopTimerSync();
};


typedef struct dataForMetod__
{
    MainWindow *win;
    void (MainWindow::*metod)(void);
} dataForMetod;

#endif //MAINWINDOW_H
