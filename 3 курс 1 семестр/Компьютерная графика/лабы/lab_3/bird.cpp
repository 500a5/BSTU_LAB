#include "bird.h"
#include <QVector>
#include <QPointF>

Bird::Bird(QPainter *p, Amorph *am, int size, int a){
    painter = p;
    this->size = size;
    agile = a;
    amorph = am;
}

void Bird::draw(int r){
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::darkBlue);
    int pad = r * 0.0666;
    QPointF p8(0, r + pad);
    QPointF p7 = amorph->moveTo(p8, -3*size, 2*size);
    QPointF p6 = amorph->moveTo(p7, size, size);
    QPointF p9 = amorph->moveTo(p8, 3*size, size);
    QPointF p10 = amorph->moveTo(p9, size, 2*size);

    QPointF p2 = amorph->moveTo(p6, pad, pad);
    QPointF p1 = amorph->moveTo(p2, 2*size, 0);
    QPointF p0 = amorph->moveTo(p1, 0, 5*size);

    QPointF p3 = amorph->moveTo(p2, 0, pad);
    QPointF p5 = amorph->moveTo(p3, size - pad, 1.67 * size + pad);
    QPointF p4 = amorph->moveTo(p5, -size, 3*size);

    QPointF p14 = amorph->moveTo(p6, -pad, 0.5*pad);
    QPointF p15 = amorph->moveTo(p14, -2*size, 0);
    QPointF p16 = amorph->moveTo(p15, -size, -size);
    QPointF p17 = amorph->moveTo(p14, -size, -size);

    QPointF p18 = amorph->moveTo(p17, -pad, -pad);
    QPointF p19 = amorph->moveTo(p18, -2*size, 0);
    QPointF p20 = amorph->moveTo(p19, -size, -size);

    QPointF p11 = amorph->moveTo(p10, pad, -pad);
    QPointF p12 = amorph->moveTo(p11, -size, -2*size);
    QPointF p13 = amorph->moveTo(p12, 3*size, -2*size);


    QPointF wing1[3] = {p0, p1, p2};
    QPointF wing2[3] = {p3, p4, p5};
    QPointF mounth[3] = {p18, p19, p20};
    QPointF tail[3] = {p11, p12, p13};
    QPointF head[4] = {p14, p15, p16, p17};
    QPointF body[5] = {p6, p7, p8, p9, p10};

    for (int i=0; i < 3; i++){
        wing1[i] = amorph->rotate(wing1[i], agile);
        wing2[i] = amorph->rotate(wing2[i], agile);
        tail[i] = amorph->rotate(tail[i], agile);
        mounth[i] = amorph->rotate(mounth[i], agile);
    }
    for (int i=0; i < 4; i++)
        head[i] = amorph->rotate(head[i], agile);
    for (int i=0; i < 5; i++)
        body[i] = amorph->rotate(body[i], agile);

    painter->drawPolygon(wing1, 3);
    painter->drawPolygon(wing2, 3);
    painter->drawPolygon(body, 5);
    painter->drawPolygon(head, 4);
    painter->drawPolygon(mounth, 3);
    painter->drawPolygon(tail, 3);
}
