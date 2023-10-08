#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <QComboBox>
#include <QMessageBox>
#include <QTableWidget>
#include <QWidget>
#include <QPainter>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    double sec = 0, sec1, sec2;
    void paintEvent(QPaintEvent* event);
    void timerEvent(QTimerEvent*);
    void showPieDiag();
    void timerUpd();
};

#endif // MAINWINDOW_H
