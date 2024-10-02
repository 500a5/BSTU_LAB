#ifndef INSIDEOBJECTS_H
#define INSIDEOBJECTS_H
#include <QPointF>
#include <QPainter>
#include <QPolygonF>
#include <QVector>

class InsideObjects
{
public:
    InsideObjects();
    QVector<QPointF> points;
    QVector<double> sizes;
    void addRandomPoint(QPointF *f1, int s1,
                        QPointF *f2, int s2,
                        QPointF *f3, int s3,
                        QPointF *f4, int s4,
                        QPointF *f5, int s5,
                        int r, int radius);
    bool pointInPoly(QPointF p, QPointF *arr, int s);
    void draw(QPainter *painter, int r, int side);
};

#endif // INSIDEOBJECTS_H
