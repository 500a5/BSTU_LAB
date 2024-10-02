#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QGLWidget>
#include <QMouseEvent>
#include <QMatrix4x4>

class MainGLWidget : public QGLWidget
{

public:
    MainGLWidget(QWidget *);
private:

    // Глубина объекта
    float zoffset = 3;

    // Матрица поворота
    QMatrix4x4 rotateMatrix; // Изначально матрица поворота равна единичной матрице

    // Позиция указателя мыши
    QPoint mousePosition;

    // Подпрограмма для рисования куба
    void glCube();

    // Процедура для изменения матрицы проектирования
    void resetProjection();

    // Процедура для изменения видовой матрицы
    void resetModelView();

    // Процедура для изменения матрицы поворота
    static void changeRotateMatrix(QMatrix4x4& rotate_matrix, float dx, float dy);

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mouseMoveEvent(QMouseEvent* m_event);
    void wheelEvent(QWheelEvent* w_event);
    void keyPressEvent(QKeyEvent* key_event);
    void mousePressEvent(QMouseEvent* m_event);
};

#endif // MYGLWIDGET_H
