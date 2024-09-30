#include "amorph3d.h"

Amorph3D::Amorph3D(){}



QVector3D Amorph3D::doMult(QMatrix4x4 m, QVector3D v, bool is_central){
    QVector4D vec = m * QVector4D(v, 1.);
    if (is_central) return (vec / vec[3]).toVector3D();
    return vec.toVector3D();
}

QVector3D Amorph3D::translate(QVector3D v, double dx, double dy, double dz){
    QMatrix4x4 m(1., 0., 0., dx,
             0., 1., 0., dy,
             0., 0., 1., dz,
             0., 0., 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::rotateX(QVector3D v, double angle){
    QMatrix4x4 m(1., 0.         , 0.          , 0.,
             0., cos(angle), -sin(angle), 0.,
             0., sin(angle), cos(angle) , 0.,
             0., 0.         , 0.          , 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::rotateY(QVector3D v, double angle){
    QMatrix4x4 m(cos(angle) , 0., sin(angle), 0.,
                 0.          , 1., 0.         , 0.,
                 -sin(angle), 0., cos(angle), 0.,
                 0.          , 0., 0.         , 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::rotateZ(QVector3D v, double angle){
    QMatrix4x4 m(cos(angle), -sin(angle), 0., 0.,
                 sin(angle), cos(angle) , 0., 0.,
                 0.         , 0.          , 1., 0.,
                 0.         , 0.          , 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::reflectXY(QVector3D v){
    QMatrix4x4 m(1., 0., 0., 0.,
                 0., 1., 0. ,0.,
                 0., 0., -1., 0.,
                 0., 0., 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::reflectYZ(QVector3D v){
    QMatrix4x4 m(-1., 0., 0., 0.,
                 0. , 1., 0., 0.,
                 0. , 0., 1., 0.,
                 0. , 0., 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::reflectXZ(QVector3D v){
    QMatrix4x4 m(1.,  0., 0., 0.,
                 0., -1., 0., 0.,
                 0.,  0., 1., 0.,
                 0.,  0., 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::extention(QVector3D v, double kx, double ky, double kz){
    QMatrix4x4 m(kx, 0. , 0. , 0.,
                 0. , ky, 0. , 0.,
                 0. , 0. , kz, 0.,
                 0. , 0. , 0. , 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::ortho(QVector3D v){
    QMatrix4x4 m(1., 0., 0., 0.,
                 0., 1., 0., 0.,
                 0., 0., 0., 0.,
                 0., 0., 0., 1.);
    return doMult(m, v);
}

QVector3D Amorph3D::freeProj(QVector3D v){
    QMatrix4x4 m(1., 0., cos(M_PI/4.), 0.,
                 0., 1., cos(M_PI/4.), 0.,
                 0., 0., 0.,           0.,
                 0., 0., 0.,           1.);
    return doMult(m, v);
}

QVector3D Amorph3D::cabinetProj(QVector3D v){
    QMatrix4x4 m(1., 0., cos(M_PI/4.)/2., 0.,
                 0., 1., sin(M_PI/4.)/2., 0.,
                 0., 0., 0.,             0.,
                 0., 0., 0.,             1.);
    return doMult(m, v);
}

QVector3D Amorph3D::centralProj(QVector3D v, double z0){
    QMatrix4x4 m(1., 0., 0.,   0.,
                 0., 1., 0.,   0.,
                 0., 0., 0.,   0.,
                 0., 0.,-1./z0,1.);
    return doMult(m, v, true);
}
