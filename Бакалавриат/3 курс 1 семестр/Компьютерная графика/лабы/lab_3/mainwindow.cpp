#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "amorph.h"
#include <QPolygonF>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agile = 0;
    objects = InsideObjects();
    startTimer(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);        // Создаём объект-живописец
    QColor orangeRed(240, 100, 0); // Оранжево-красный цвет
    Amorph amorph = Amorph();
    // Координаты центра
    QPointF center = QPointF(width() * 0.5, height() * 0.5);
    int r;
    if (width() < height()) r = width() / 4;
    else r = height() / 4;

    // Main Circle in center
    painter.drawEllipse(center, r, r);

    painter.setPen(orangeRed);
    painter.translate(center);

    Bird bird = Bird(&painter, &amorph, r/6, agile);
    bird.draw(r);

    int side = r/5;

    QPointF f0 = QPoint(0, 0);
    QPointF f1 = amorph.moveTo(f0, 2*side, 0);
    QPointF f2 = amorph.moveTo(f0, side, 2*side);

    QPointF f10 = amorph.moveTo(f0, side, -2*side);
    QPointF f11 = amorph.moveTo(f10, side, side);
    QPointF f12 = amorph.moveTo(f11, 2*side, 0);
    QPointF f13 = amorph.moveTo(f10, 2*side, 0);

    QPointF f3 = amorph.moveTo(f0, -2*side, -1.5*side);
    QPointF f4 = amorph.moveTo(f3, side, -2*side);
    QPointF f5 = amorph.moveTo(f3, -side, -2*side);

    QPointF f6 = amorph.moveTo(f0, -2*side, 2*side);
    QPointF f7 = amorph.moveTo(f6, -2*side, -0.2*side);
    QPointF f8 = amorph.moveTo(f7, 3*side, 3*side);
    QPointF f9 = amorph.moveTo(f6, side, 0.7*side);

    QPointF f14 = amorph.moveTo(f2, 2*side, -side);
    QPointF f15 = amorph.moveTo(f14, side, 0);
    QPointF f16 = amorph.moveTo(f15, 0.3*side, 0.5*side);
    QPointF f17 = amorph.moveTo(f16, -side, 2*side);
    QPointF f18 = amorph.moveTo(f14, -side, side);

    QPointF fig3[3] = {f0, f1, f2};
    QPointF fig1[3] = {f3, f4, f5};
    QPointF fig2[4] = {f10, f11, f12, f13};
    QPointF fig4[4] = {f6, f7, f8, f9};
    QPointF fig5[5] = {f14, f15, f16, f17, f18};

    painter.drawPolygon(fig1, 3);
    painter.drawPolygon(fig2, 4);
    painter.drawPolygon(fig3, 3);
    painter.drawPolygon(fig4, 4);
    painter.drawPolygon(fig5, 5);

    if (agile % 100 == 0){
        objects.addRandomPoint(fig1, 3, fig2, 4, fig3, 3, fig4, 4, fig5, 5, r, side);
    }
    objects.draw(&painter, r, side);
}

void MainWindow::timerEvent(QTimerEvent *event){
    agile += 1;
    repaint();
}
