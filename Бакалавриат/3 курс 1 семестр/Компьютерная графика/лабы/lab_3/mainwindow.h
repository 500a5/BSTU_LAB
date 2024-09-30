#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "bird.h"
#include <QPointF>
#include "insideobjects.h"

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
    int agile;
    InsideObjects objects;
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
