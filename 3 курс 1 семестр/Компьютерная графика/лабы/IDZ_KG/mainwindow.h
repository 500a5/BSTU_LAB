#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtOpenGL>
#include <GL/glu.h>
#include <QTimer>
#include <QVector>
#include "time.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QGLWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void initializeGL() ;
    void resizeGL(int width, int height);
    void paintGL();
    void drawTable();
    void drawBox1();
    void drawBox2();
    void drawElka();
    void room();
    void drawHause();
    void drawKolodec();
    void drawMan();


private:
    Ui::MainWindow *ui;
    void scale_plus();     // приблизить сцену
    void scale_minus();    // удалиться от сцены
    void translate_down() ;
    void translate_up() ;
    void translate_Vver();
    void translate_Vniz();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);


    bool checkElka;
    GLfloat nSca, ScaleElka;
    GLfloat xTra, yTra, zTra;
    int angle_x=0;
    int angle_y=0;

    GLuint textures[10];
    void LoadTexture();
    //void loadObj(const QString &path);

    //освещение
    GLfloat pos1[4] = { -5, -7, 25, 0 };
    GLfloat pos2[4] = { 5, -7, 25, 0 };
    GLfloat pos3[4] = { 0, 0, 25, 0 };
    GLfloat dir[3] = { -1, -1, -1 };


    QPoint m_mousePosition;
    QTimer *timer;int angleTable;
private slots:
    void timerUpd();
};
#endif // MAINWINDOW_H
