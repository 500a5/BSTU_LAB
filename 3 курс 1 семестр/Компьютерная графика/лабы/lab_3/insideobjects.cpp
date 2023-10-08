#include "insideobjects.h"

InsideObjects::InsideObjects()
{
    qsrand(9139); // Установка базового числа для отсчёта рандома в qrand
}



void InsideObjects::addRandomPoint(
        QPointF *f1, int s1, QPointF *f2, int s2,
        QPointF *f3, int s3, QPointF *f4, int s4,
        QPointF *f5, int s5, int r, int side){
    QPointF *arr;
    int as;
    switch (qrand() % 5) {
    case 0:
        arr = f1; as = s1; break;
    case 1:
        arr = f2; as = s2; break;
    case 2:
        arr = f3; as = s3; break;
    case 3:
        arr = f4; as = s4; break;
    default:
        arr = f5; as = s5; break;
    }

    double circle_size = (double)(qrand() % 5 + 1) / side;
    double x=0, y=0;
    for (int i=0; i<as; i++){
        x += arr[i].x();
        y += arr[i].y();
    }
    x = (x + (qrand() % 2*side - side)) / (as * r);
    y = (y + (qrand() % 2*side - side)) / (as * r);
    QPointF point(x, y);
    sizes.append(circle_size);
    points.append(point);
}


void InsideObjects::draw(QPainter *painter, int r, int side){
    QVector<QPointF>::iterator cur;

    int c = 0;
    for(cur = points.begin(); cur != points.end(); cur++, c++){
        QVector<double>::iterator sizes_cur = sizes.begin() + c;
        painter->setBrush(Qt::red);
        QPointF point(r * cur->x(), r * cur->y());
        painter->drawEllipse(point, *sizes_cur* side, *sizes_cur* side);
    }
}
