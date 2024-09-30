#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWheelEvent>

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

    int angle;

    // Обработчик события перерисовки окна
    void paintEvent(QPaintEvent* event);

    // Обработчик события прокрутки колеса мыши
    void wheelEvent(QWheelEvent* );
};

#endif // MAINWINDOW_H
