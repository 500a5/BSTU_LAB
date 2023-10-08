#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    mousePos = QPoint(0, 0);
    ui->setupUi(this);
    rotateMatrix = QMatrix4x4(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
                );
    amorph3d = Amorph3D();
    objObject = ObjObject(false);
    mouseWheel = -1;
    selectP = QPoint(0, 0);
    c = 5;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    int coef = ((std::min(width()/4, height()/4))) - 20;

    QVector<QVector3D> vertecs = QVector<QVector3D>();

    for (int i = 0; i < objObject.points.size(); i++){
        QVector3D tmp_v = objObject.points[i];
        tmp_v = tmp_v * rotateMatrix;
        tmp_v += QVector3D(0, 0, mouseWheel);
        vertecs.append(tmp_v);
    }

    QColor selectColor = QColor(255, 125, 125);

    QVector<QPair<QVector<QVector3D>, QColor>> polysBeforeModify = objObject.getSortedPolygons(vertecs);
    QVector<QPair<QPolygon, QColor>> newPolygons = QVector<QPair<QPolygon, QColor>>();
    bool fst = true;
    for (int j = polysBeforeModify.size() - 1; j >= 0; j--){
        QPolygon poly = QPolygon();
        QColor col = polysBeforeModify[j].second;
        for (int i=0; i < polysBeforeModify[j].first.size(); i++){
            QVector3D v = amorph3d.centralProj(polysBeforeModify[j].first[i], c);
            v = amorph3d.extention(v, coef, coef, coef);
            v = amorph3d.translate(v, width()/2, height()/2, 0);
            poly.append(v.toPoint());
        }
        if (fst && objObject.pointInPoly(poly, selectP)){ col = selectColor; fst = false;}
        newPolygons.push_front(QPair<QPolygon, QColor>(poly, col));
    }

    for (int j = 0; j < newPolygons.size(); j++){
        painter.setBrush(newPolygons[j].second);
        painter.drawPolygon(newPolygons[j].first);
    }
    vertecs.clear();

}

// Обработчик события прокрутки колеса мыши
void Widget::wheelEvent(QWheelEvent* wheelevent){
    if (wheelevent->delta() < 0) mouseWheel += 1;
    else mouseWheel -= 1;
    if (mouseWheel > 1) mouseWheel = 1;
    repaint(); // Обновляем окно
}

void Widget::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    if (mouseEvent->buttons() == Qt::RightButton){
        QPoint dp = mouseEvent->pos() - mousePos;
        rotateMatrix.rotate(dp.y(), 1, 0, 0);
        rotateMatrix.rotate(-dp.x(), 0, 1, 0);
        mousePos = mouseEvent->pos();
        repaint();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        QPoint dp = event->pos();
        QPoint windowP = dp - QPoint(width()/2, height()/2);
        if ((abs(windowP.x()) < width()/2) && (abs(windowP.y()) < height()/2)){
            selectP = dp;
            repaint();
        }
    }
}

void Widget::on_spinBox_valueChanged(int arg1)
{
    objObject.rebuildObject(arg1);
    repaint();
}

void Widget::on_verticalSlider_sliderMoved(int position)
{
    c = position;
    repaint();
}
