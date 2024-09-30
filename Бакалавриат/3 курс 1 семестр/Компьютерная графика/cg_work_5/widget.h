#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "objects3d.h"
#include "amorph3d.h"
#include <QPainter>
#include <QKeyEvent>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    double angleX;
    double angleY;
    double angleZ;
    int mouseWheel;
    int projection;
    ObjObject objObject;
    Amorph3D amorph3d;
    QPoint mousePos;
    QMatrix4x4 rotateMatrix;
    explicit Widget(QWidget *parent = 0);
    QPoint selectP;
    int c;
    ~Widget();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_verticalSlider_sliderMoved(int position);

private:
    Ui::Widget *ui;
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent* );
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // WIDGET_H
