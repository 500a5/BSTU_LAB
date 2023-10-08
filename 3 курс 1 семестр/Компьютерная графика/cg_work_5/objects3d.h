#ifndef OBJECTS3D_H
#define OBJECTS3D_H

#include <QString>
#include <QVector>
#include <QVector3D>
#include <QPolygon>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtAlgorithms>
#include <QPair>
#include <QColor>
#include <amorph3d.h>

class ObjFilesReader {
public:
    // сбор списка типа, соответствующего метке из строк файла fileName с меткой mark
    template <class T>
    static QVector<QVector<T>> parseByMark(QString fileName, bool is_v=true) {
        QFile fileObj(fileName);
        fileObj.open(QIODevice::ReadOnly);

        char mark = 'f';
        if (is_v) mark = 'v';

        QVector<QVector<T>> result = QVector<QVector<T>>();
        while (!fileObj.atEnd()) {
            QString str = fileObj.readLine();
            if ((str.size() >= 2) && (str[0] == mark)) {
                str[0] = ' ';
                QString elements[3];

                QTextStream stream(&str);
                QVector<T> newElement = QVector<T>();
                while (!stream.atEnd()){
                    QString el;
                    stream >> el;
                    if (el == "") continue;
                    if (is_v) newElement.append(el.toDouble());
                    else newElement.append(el.toInt());
                }
                result.push_back(newElement);
            }
        }
        fileObj.close();
        return result;
    }
};

class ObjObject {
public:
    QVector<QVector3D> points;
    QVector<QVector<int>> polygons;
    QString file;

    // конструктор
    ObjObject(bool read_file=true, QString fileName = "D:/cg_labs/lab_4/test.obj") {
        points = QVector<QVector3D>();
        polygons = QVector<QVector<int>>();
        if (read_file){
            file = fileName;
            for (auto v: ObjFilesReader::parseByMark<double>(file, true)){
                QVector3D vs = QVector3D(v[0], v[1], v[2]);
                points.append(vs);
            }
            polygons = ObjFilesReader::parseByMark<int>(file, false);
            for (int i=0; i < polygons.size(); i++)
                for (int j=0; j < polygons[i].size(); j++){
                    polygons[i][j]--;
                }
        } else rebuildObject(6);
    }

    QVector3D getPointOnCircleByParams(QVector3D c, int r, int i, int n){
        return QVector3D(c.x() + r * cos(2 * M_PI * i / n),
                         c.y(),
                         c.z() + r * sin(2 * M_PI * i / n));
    }

    void createPoly4(int a1, int a2, int a3, int a4, bool is_3=false){
        QVector<int> poly = QVector<int>();
        poly.append(a1);
        poly.append(a2);
        poly.append(a3);
        if (!is_3) poly.append(a4);
        polygons.append(poly);
    }

    QVector<QPair<QVector<QVector3D>, QColor>> getSortedPolygons(QVector<QVector3D> &vertecs) {
        QVector<QPair<QVector<QVector3D>, QColor>> new_poly = QVector<QPair<QVector<QVector3D>, QColor>>();
        for (int i = 0; i < polygons.size(); i++) {
            QVector<QVector3D> poly = QVector<QVector3D>();
            for (int j=0; j < polygons[i].size(); j++){
                poly.append(vertecs[polygons[i][j]]);
            }
            new_poly.append(QPair<QVector<QVector3D>,QColor>(
                                poly,
                                QColor(0, (150 + 30*i) % 255, 255)
                                //QColor((50*i) % 255, (150 + 30*i) % 255, (20*i + 124) % 200)
                                ));
        }

        qSort(new_poly.begin(), new_poly.end(),
              [](QPair<QVector<QVector3D>, QColor>& a, QPair<QVector<QVector3D>, QColor>& b){
            return getZForPoly(a.first) < getZForPoly(b.first);
        });
        return new_poly;
    }

    static double getZForPoly(QVector<QVector3D> &poly){
        QVector3D rez = QVector3D(0., 0., 0.);
        for (int i = 0; i < poly.size(); i++)
            rez += poly[i];
        return rez.z() / ((double)(poly.size()));
    }

    void rebuildObject(int angles){
        points.clear();
        polygons.clear();

        double h = 0.25;
        double r = 1.5;
        double coef = 1.2;
        int layers = 8;
        int inStep = layers * 2 + 2;

        QVector3D p0 = QVector3D(0.0, 0.0, 0.0);
        QVector3D p1 = getPointOnCircleByParams(p0, r, 0, angles);
        QVector3D p2 = p1 * coef;
        QVector3D p3 = p1;
        QVector3D p4 = p2;
        points.append(p0);

        points.append(p1);
        points.append(p2);
        for (int i=0; i < layers; i++){
            p3 = p3 + QVector3D(0, h, 0);
            p4 = p4 + QVector3D(0, h, 0);
            points.append(p3);
            points.append(p4);
        }
        for (int i=1; i <= angles; i++){
            QVector3D p5 = getPointOnCircleByParams(p0, r, i, angles);
            QVector3D p6 = p5 * coef;
            QVector3D p7 = p5;
            QVector3D p8 = p6;

            points.append(p5);
            points.append(p6);

            createPoly4(0, (i-1)*inStep+1, i*inStep+1, 0, true);
            createPoly4((i-1)*inStep+1, (i-1)*inStep+2, i*inStep+2,i*inStep+1);

            for (int l=1; l <= layers; l++){
                p7 = p7 + QVector3D(0, h, 0);
                p8 = p8 + QVector3D(0, h, 0);
                points.append(p7);
                points.append(p8);
                createPoly4((i-1)*inStep+2*l, (i-1)*inStep+2*(l+1), i*inStep+2*(l+1), i*inStep+2*l);
                createPoly4((i-1)*inStep+2*l-1, (i-1)*inStep+2*(l+1)-1, i*inStep+2*(l+1)-1, i*inStep+2*l-1);
            }
            createPoly4(i*inStep+2*(layers+1)-1, i*inStep+2*(layers+1),
                        (i-1)*inStep+2*(layers+1), (i-1)*inStep+2*(layers+1)-1);
        }
        for (int i=0; i < points.size(); i++){
            points[i] -= QVector3D(0, h * (layers/2), 0);
            points[i] *= -1;
        }
    }

    bool pointInPoly(QPolygon poly, QPoint p){
        Amorph3D amorph = Amorph3D();
        QPoint a0 = poly[0] - p;
        qInfo() << poly[0] << p << a0;
        QPoint b;
        int countBig = 0;
        for (int i = 0; i < poly.size() - 1; i++){
            QPoint a = poly[i] - p;
            b = poly[i+1] - p;
            if (a.x()*b.y() - a.y()*b.x() > 0.) countBig++; else countBig--;
        }
        if (a0.x()*b.y() - a0.y()*b.x() > 0.) countBig--; else countBig++;
        return abs(countBig) == poly.size();
    }
};


#endif // OBJECTS3D_H
