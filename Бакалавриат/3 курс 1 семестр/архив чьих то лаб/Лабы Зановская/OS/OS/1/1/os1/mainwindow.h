#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <QString>
#include <QTableWidget>
#include <QColorDialog>
namespace Ui {
class MainWindow;
}


struct Tabl {
    int  Const;
    char String[40];
    char String2[300];
} ;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ViewText();

private slots:
    void GETICONMETRICS();
    void DRAGFULLWINDOWS();
    void SETLANGTOGGLE();
    void ACTIVECAPTION();
    void MENUTEXT();
    void BTNFACE();
    void CARETS();

    void GETMOUSETRAILS();
    void GETWORKAREA();
    void LOCALTIME();
    void TIMEZONE();
    void KEYBOARDSTATE();
    void USERLANGID();
    void SystemPowerState();
    void SLocalTime();
private:
    Ui::MainWindow *ui;
    int p=0;
    void paintEvent(QPaintEvent*p_event);
};

#endif // MAINWINDOW_H
