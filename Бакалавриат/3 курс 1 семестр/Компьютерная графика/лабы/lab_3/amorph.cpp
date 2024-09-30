#include "amorph.h"

Amorph::Amorph()
{
    reflectMatrixOY = QMatrix(-1, 0, 0, 1, 0, 0);
    reflectMatrixOX = QMatrix(1, 0, 0, -1, 0, 0);
}

QPointF Amorph::reflection(QPointF p, bool is_ox){
    QMatrix xy = QMatrix(p.x(), 0, p.y(), 0, 1, 0);
    QMatrix tmp;
    if (is_ox)
        tmp = reflectMatrixOX * xy;
    else
        tmp = reflectMatrixOY * xy;
    return QPointF(tmp.m11(), tmp.m21());
}

QPointF Amorph::rotate(QPointF p, int a){
    QMatrix xy = QMatrix(p.x(), 0, p.y(), 0, 1, 0);
    double agile = (a % 360) / 57.3;
    QMatrix ma = QMatrix(cos(agile), -sin(agile), sin(agile), cos(agile), 0, 0);
    ma = ma * xy;
    return QPointF(ma.m11(), ma.m21());
}

QPointF Amorph::resize(QPointF p, int kx, int ky){
    QMatrix xy = QMatrix(p.x(), 0, p.y(), 0, 1, 0);
    QMatrix rm = QMatrix(kx, 0, 0, ky, 0, 0);
    rm = rm * xy;
    return QPointF(rm.m11(), rm.m21());
}

QPointF Amorph::moveTo(QPointF p, int dx, int dy){
//    QMatrix xy = QMatrix(p.x(), 0, p.y(), 0, 1, 0);
//    QMatrix m = QMatrix(1, 0, 0, 1, dx, dy);
//    m = m * xy;
//    return QPointF(m.m11(), m.m21());
    return QPointF(p.x() + dx, p.y() + dy);
}
