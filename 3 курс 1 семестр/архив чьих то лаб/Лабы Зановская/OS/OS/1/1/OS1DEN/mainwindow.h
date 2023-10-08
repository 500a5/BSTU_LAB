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
    void DRAGHEIGHT();
    void LOWPOWERACTIVE();
    void SCREENREADER();
    void BTNTEXT();
    void APPWORKSPACE();
    void SCROLLBAR();
    void SLocalTime();
    void Cursor();
private:
    Ui::MainWindow *ui;
    int p=0;
    void paintEvent(QPaintEvent*p_event);
};

#endif // MAINWINDOW_H
