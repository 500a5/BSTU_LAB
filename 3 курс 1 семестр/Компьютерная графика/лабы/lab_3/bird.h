#ifndef BIRD_H
#define BIRD_H

#include <QPainter>
#include <QPointF>
#include "amorph.h"

class Bird
{
    QPainter *painter;
    int size;
    int agile;
    Amorph *amorph;
public:
    Bird(QPainter *p, Amorph *am, int size, int a);
    void draw(int r);
};

#endif // BIRD_H
