#include "camera.h"

Camera::Camera(){
    setDefault();
}

void Camera::rotateX(const QQuaternion &r){
    rotate_X = r * rotate_X;
    rotate = rotate_Y * rotate_X;
    updateViewMatrix();
}

void Camera::rotateY(const QQuaternion &r){
    rotate_Y = r * rotate_Y;
    rotate = rotate_X * rotate_Y;
    updateViewMatrix();
}

void Camera::translate(const QVector3D &vec){
    trans += vec;
    updateViewMatrix();
}

void Camera::updateViewMatrix(){
    viewMatrix.setToIdentity();
    viewMatrix.translate(trans);
    viewMatrix.rotate(rotate);
}

const QMatrix4x4 &Camera::getviewMatrix() const{
    return viewMatrix;
}

void Camera::setDefault(){
    rotate = QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), -55);
    rotate_X = QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), -55);
    rotate_Y = QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 0.0), 0);
    trans = QVector3D(0.0, 0.0, -200.0);
    updateViewMatrix();
}
