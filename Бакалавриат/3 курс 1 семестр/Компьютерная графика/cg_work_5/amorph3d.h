#ifndef AMORPH3D_H
#define AMORPH3D_H

#include <QMatrix4x4>
#include <QVector3D>
#include <QVector4D>
#include <QVector>
#include <QDebug>
#include <math.h>



class Amorph3D
{

public:
    Amorph3D();
    QVector3D doMult(QMatrix4x4 m, QVector3D v, bool is_central=false);
    QVector3D translate(QVector3D v, double dx, double dy, double dz);
    QVector3D rotateX(QVector3D v, double angle);
    QVector3D rotateY(QVector3D v, double angle);
    QVector3D rotateZ(QVector3D v, double angle);
    QVector3D reflectXY(QVector3D v);
    QVector3D reflectYZ(QVector3D v);
    QVector3D reflectXZ(QVector3D v);
    QVector3D extention(QVector3D v, double kx, double ky, double kz);
    QVector3D ortho(QVector3D v);
    QVector3D freeProj(QVector3D v);
    QVector3D cabinetProj(QVector3D v);
    QVector3D centralProj(QVector3D v, double z0);
};

#endif // AMORPH3D_H
