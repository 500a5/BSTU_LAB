#ifndef AMORPH_H
#define AMORPH_H

#include <QMatrix>
#include <QPointF>

class Amorph
{
    QMatrix reflectMatrixOX;
    QMatrix reflectMatrixOY;

public:
    Amorph();

    // Отражение
    QPointF reflection(QPointF p, bool is_ox=true);

    // Поворот
    QPointF rotate(QPointF p, int a);

    // Масштабирование
    QPointF resize(QPointF p, int kx, int ky);

    // Перенос
    QPointF moveTo(QPointF p, int dx, int dy);
};

#endif // AMORPH_H
