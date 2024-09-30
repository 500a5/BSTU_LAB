#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <QMessageBox>
#include <QTableWidget>
#include <QListWidget>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
class WaitingApplication;
}

DWORD WINAPI shellForMainWindowsMetods( void *p );

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);

private slots:

    bool activeTimer = false;
    HANDLE mutex;

    HANDLE winThread = nullptr;



private slots:
    void startTimerSync();
    void stopTimerSync();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    friend DWORD WINAPI shellForMainWindowsMetods( void * );
    int time = 0;
    bool activeCounting = false;
    void processMutex();
};


#endif // MAINWINDOW_H










































