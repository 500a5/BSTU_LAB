#ifndef IMPORT_OBJ_H
#define IMPORT_OBJ_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVector3D>
#include <QVector2D>

struct VertexData{
    VertexData(){}
    VertexData(QVector3D p, QVector2D t, QVector3D n):
        position(p), texCoord(t), normal(n){}
    VertexData(QVector3D p, QVector3D n):
        position(p), normal(n){}
    VertexData(QVector3D p, QVector2D t):
        position(p), texCoord(t){}
    VertexData(QVector3D p):
        position(p){}
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

void load_obj(const QString &f_name, QVector<VertexData> &v_data, QVector<uint> &indexes);

#endif // IMPORT_OBJ_H
