#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWidget>
#include "import_obj.h"
#include <QOpenGLShaderProgram>
//#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include "simpleobject.h"
#include <QMouseEvent>
#include <QOpenGLContext>
#include <QKeyEvent>
#include "camera.h"
#include <QString>
#include <QFileDialog>

#define WHITE_MOVE TEAM_WHITE
#define BLACK_MOVE TEAM_BLACK

class MainWindow : public QOpenGLWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void initializeGL() override;
    void resizeGL(int w , int h) override;
    void paintGL() override;
    void initShaders();

private:
    QMatrix4x4 projectionMatrix;
    QVector2D mouse_pos, click_pos;
    int field_sz, grid_sz;
    Camera camera;
    QOpenGLShaderProgram sh_program, sh_program_simple;

    int selected_chess_index;
    int game_status;
    int white_count, black_count;
    int cur_obj_num;

    QVector<SimpleObject*> chessBoard;
    QVector<ChessFigure*> chessFigures;
    QVector<SimpleObject*> otherObjects;
    QVector<LampObject*> lamps;
    Spot* spotLight;

    void mousePressEvent(QMouseEvent* ev) override;
    void mouseMoveEvent(QMouseEvent* ev) override;
    void wheelEvent(QWheelEvent* wheelevent) override;
    void keyPressEvent(QKeyEvent *event) override;

    void loadObj(QString name);
    void loadTexture(QString name);

    QVector3D screenToWord(const QVector2D &mosue_pos) const;
    QVector2D wordToField(const QVector3D& coord) const;
    int findFig(const QVector2D &pos) const;
    void endMove();
    void drawLines();

};
#endif // MAINWINDOW_H
