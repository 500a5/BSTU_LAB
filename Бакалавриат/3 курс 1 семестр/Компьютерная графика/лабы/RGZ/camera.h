#ifndef CAMERA_H
#define CAMERA_H

#include <QQuaternion>
#include <QMatrix4x4>

class Camera{
    QQuaternion rotate;
    QQuaternion rotate_X;
    QQuaternion rotate_Y;
    QVector3D trans;
    QMatrix4x4 viewMatrix;
public:
    Camera();
    void rotateX(const QQuaternion& r);
    void rotateY(const QQuaternion& r);
    void translate(const QVector3D& vec);
    void updateViewMatrix();
    const QMatrix4x4 &getviewMatrix() const;
    void setDefault();
};

#endif // CAMERA_H
