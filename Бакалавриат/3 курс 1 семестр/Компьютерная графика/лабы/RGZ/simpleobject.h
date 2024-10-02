#ifndef MODEL3D_H
#define MODEL3D_H

#define TEAM_WHITE 1
#define TEAM_BLACK 0

#include <import_obj.h>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QtMath>

class SimpleObject{
protected:
    QMatrix4x4 modelMatrix;
    QOpenGLBuffer arrayBuffer;
    QOpenGLBuffer indexBuffer;
    QOpenGLTexture *texture;
    QVector4D color;
    QVector3D min, max, center;
    QVector3D trans;
    float k, r_x, r_y, r_z;
    bool use_texture = false;
public:
    SimpleObject();
    SimpleObject(const QString &name, QVector4D color = QVector4D(0.2f, 0.4f, 0.6f, 1.0f));
    ~SimpleObject();
    void init(const QString &name, QVector4D color = QVector4D(0.2f, 0.4f, 0.6f, 1.0f));
    virtual void drawObject(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions);
    void scale(float k);
    void translate(const QVector3D &vec);
    void rotateX(float angle);
    void rotateY(float angle);
    void rotateZ(float angle);
    void updateModelMatrix();
    QVector3D getMin(){return min;}
    QVector3D getMax(){return max;}
    QVector3D getCenterOfMass(){return QVector3D(modelMatrix*center);}
    QVector4D getColor(){return color;}
    void setTexture(QString name);
    bool getUseTexture(){return use_texture;}
};

class ChessFigure: public SimpleObject{
    int pos_x, pos_y;
    int grid_sz, field_sz;
    bool enable;
    int team;
    QVector4D enableColor, defaultColor;
public:
    ChessFigure(const QString &name, int grid_sz, int field_sz, int x, int y, int team);
    void move(int x1, int y1);
    bool onThisPos(int x, int y);
    void select();
    void deselect();
    int getTeam();
};

struct PointLightStruct{
    QVector3D pos;
    QVector4D color;
    float power;
    float constant;
    float linear;
    float quadratic;
};

class LampObject: public SimpleObject{
    bool turn_on;
    QVector4D base_color, light_color;
    float power;
    float constant, linear, quadratic;  // коэффициенты затухания
public:
    LampObject(const QString &name, QVector4D base_color = QVector4D(0.6f, 0.5f, 0.2f, 1.0f), QVector4D light_color = QVector4D(1.0f, 1.0f, 1.0f, 1.0f));
    void setState(bool state);
    bool getState(){return turn_on;}
    void setPower(float power){this->power = power;}
    PointLightStruct getPointLightStruct();
    void drawObject(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions);
    void drawObjAsLamp(QOpenGLShaderProgram *sh_program, QOpenGLFunctions *functions);
};

struct SpotLightStruct{
    QVector3D pos;
    QVector3D direction;
    QVector4D color;
    float power;
    float cutOff;
};

class Spot{
    bool turn_on;
    QVector4D light_color;
    float power;
    QVector3D position, direction;
    float cutOff;   // cos(phi)
public:
    Spot(QVector4D light_color = QVector4D(1.0f, 1.0f, 1.0f, 1.0f), bool turn_on = false):
        turn_on(turn_on), light_color(light_color), power(1){}
    void setState(bool state){turn_on = state;}
    bool getState(){return turn_on;}
    void setPower(float power){this->power = power;}
    void setAngle(float angle){cutOff = qCos(angle*M_PI/180);}
    SpotLightStruct getSpotLightStruct();
    void setPositionAndDirection(QVector3D pos, QVector3D dir_point);
};

#endif // MODEL3D_H
