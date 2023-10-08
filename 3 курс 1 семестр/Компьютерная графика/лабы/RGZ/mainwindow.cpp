#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QOpenGLWidget(parent)
{
    selected_chess_index = -1;
    grid_sz = 6; field_sz = 8;
    white_count = black_count = 16;
    game_status = WHITE_MOVE;
    cur_obj_num = -1;
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL(){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    initShaders();

  //  chessBoard.append(new SimpleObject(":/objects/ChessboardField.obj", QVector4D(1.0, 0.5, 0.3, 1.0)));
//    chessBoard.last()->setTexture(":/textures/field_texture.jpg");
//    chessBoard.append(new SimpleObject(":/objects/ChessboardBase.obj", QVector4D(0.45, 0.2, 0.05, 1.0)));
//    chessBoard.last()->setTexture(":/textures/redWood.jpg");
/*
    for (int j = 1; j <= 8; j++){
        chessFigures.append(new ChessFigure(":/objects/ChessPawn.obj", grid_sz, field_sz, 2, j, TEAM_WHITE));
        chessFigures.append(new ChessFigure(":/objects/ChessPawn.obj", grid_sz, field_sz, 7, j, TEAM_BLACK));
    }    
    chessFigures.append(new ChessFigure(":/objects/ChessRook.obj", grid_sz, field_sz, 1, 1, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessRook.obj", grid_sz, field_sz, 1, 8, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessRook.obj", grid_sz, field_sz, 8, 1, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessRook.obj", grid_sz, field_sz, 8, 8, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessKnight.obj", grid_sz, field_sz, 1, 2, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessKnight.obj", grid_sz, field_sz, 1, 7, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessKnight_mir.obj", grid_sz, field_sz, 8, 2, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessKnight_mir.obj", grid_sz, field_sz, 8, 7, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessKing.obj", grid_sz, field_sz, 1, 5, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessKing.obj", grid_sz, field_sz, 8, 4, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessQeen.obj", grid_sz, field_sz, 1, 4, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessQeen.obj", grid_sz, field_sz, 8, 5, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessBishop.obj", grid_sz, field_sz, 1, 3, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessBishop.obj", grid_sz, field_sz, 1, 6, TEAM_WHITE));
    chessFigures.append(new ChessFigure(":/objects/ChessBishop_mir.obj", grid_sz, field_sz, 8, 3, TEAM_BLACK));
    chessFigures.append(new ChessFigure(":/objects/ChessBishop_mir.obj", grid_sz, field_sz, 8, 6, TEAM_BLACK));
*/
    //otherObjects.append(new SimpleObject(":/objects/Table.obj", QVector4D(0.3, 0.15, 0.0, 1.0)));
    //otherObjects.last()->setTexture(":/textures/WoodSeemles.jpg");
  //  otherObjects.append(new SimpleObject(":/objects/Lamp.obj", QVector4D(0.75, 0.75, 0.75, 1.0)));
  //  otherObjects.last()->setTexture(":/textures/lamp_texture.jpg");
  //  otherObjects.append(new SimpleObject(":/objects/book.obj", QVector4D(0.6, 0.15, 0.1, 1.0)));
  //  otherObjects.last()->setTexture(":/textures/Book_texture.jpg");

    //lamps.append(new LampObject(":/objects/Bulb.obj"));
    //lamps.at(0)->setPower(2);
    lamps.append(new LampObject(":/objects/cube.obj"));
    lamps.at(0)->translate(QVector3D(-100, -100, 100));
    lamps.at(0)->setPower(3);

    spotLight = new Spot();
    spotLight->setAngle(2.4f);
}

void MainWindow::resizeGL(int w , int h){
    float aspect = w/(float)h;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45, aspect, 10.0f, 1000.0f);
}

void MainWindow::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    sh_program.bind();
    sh_program.setUniformValue("u_projectionMatrix", projectionMatrix);
    sh_program.setUniformValue("u_viewMatrix", camera.getviewMatrix());

    QVector<PointLightStruct> strct_vec;
    int count = 0;
    for (int i = 0; i < lamps.size(); i++)
        if (lamps.at(i)->getState()){
            strct_vec.append(lamps.at(i)->getPointLightStruct());
            count++;
        }
    sh_program.setUniformValue("u_numPointLights", count);
    for (int i = 0; i < count; i++){
        sh_program.setUniformValue(QString("u_pointLights[%1].pos").arg(i).toStdString().c_str(), strct_vec[i].pos);
        sh_program.setUniformValue(QString("u_pointLights[%1].color").arg(i).toStdString().c_str(), strct_vec[i].color);
        sh_program.setUniformValue(QString("u_pointLights[%1].power").arg(i).toStdString().c_str(), strct_vec[i].power);
        sh_program.setUniformValue(QString("u_pointLights[%1].constant").arg(i).toStdString().c_str(), strct_vec[i].constant);
        sh_program.setUniformValue(QString("u_pointLights[%1].linear").arg(i).toStdString().c_str(), strct_vec[i].linear);
        sh_program.setUniformValue(QString("u_pointLights[%1].quadratic").arg(i).toStdString().c_str(), strct_vec[i].quadratic);
    }

    QVector<SpotLightStruct> strct_vec_sp;
    QVector3D vec_1, vec_2;
    for (int i = 0; i < chessFigures.size(); i++)
        if(chessFigures[i]->getTeam() == game_status){
            //vec_1 = chessFigures[i]->getCenterOfMass(); vec_1.setZ(50);
            vec_1 = QVector3D(0.0, 0.0, 50.0);
            vec_2 = chessFigures[i]->getCenterOfMass(); vec_2.setZ(0);
            spotLight->setPositionAndDirection(vec_1, vec_2);
            strct_vec_sp.append(spotLight->getSpotLightStruct());
        }
    sh_program.setUniformValue("u_numSpotLights", strct_vec_sp.size());
    for (int i = 0; i < strct_vec_sp.size(); i++){
        sh_program.setUniformValue(QString("u_spotLights[%1].pos").arg(i).toStdString().c_str(), strct_vec_sp[i].pos);
        sh_program.setUniformValue(QString("u_spotLights[%1].direction").arg(i).toStdString().c_str(), strct_vec_sp[i].direction);
        sh_program.setUniformValue(QString("u_spotLights[%1].color").arg(i).toStdString().c_str(), strct_vec_sp[i].color);
        sh_program.setUniformValue(QString("u_spotLights[%1].power").arg(i).toStdString().c_str(), strct_vec_sp[i].power);
        sh_program.setUniformValue(QString("u_spotLights[%1].cutOff").arg(i).toStdString().c_str(), strct_vec_sp[i].cutOff);
    }

    /*for (int i = 0; i < chessBoard.size(); i++)
        chessBoard[i]->drawObject(&sh_program, context()->functions());
    for (int i = 0; i < chessFigures.size(); i++)
        chessFigures[i]->drawObject(&sh_program, context()->functions());*/
    /*for (int i = 0; i < otherObjects.size(); i++)
        otherObjects[i]->drawObject(&sh_program, context()->functions());*/
    if (cur_obj_num != -1)
        otherObjects[cur_obj_num]->drawObject(&sh_program, context()->functions());
    for (int i = 0; i < lamps.size(); i++)
        if (!lamps[i]->getState())
            lamps[i]->drawObject(&sh_program, context()->functions());

    if (count > 0){
        sh_program_simple.bind();
        sh_program_simple.setUniformValue("u_projectionMatrix", projectionMatrix);
        sh_program_simple.setUniformValue("u_viewMatrix", camera.getviewMatrix());

        for (int i = 0; i < lamps.size(); i++){
            if(lamps[i]->getState())
                lamps[i]->drawObjAsLamp(&sh_program_simple, context()->functions());
        }
    }

    /*QMatrix4x4 M = projectionMatrix * camera.getviewMatrix();
    glLoadMatrixf(M.data());
    drawLines();*/
}

void MainWindow::initShaders(){
    if (!sh_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vshader.vert")){
        qDebug() << "ошибка добавления вершинного шейдера";
        close();
    }
    if (!sh_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fshader.frag")){
        qDebug() << "ошибка добавления фрагментного шейдера";
        close();
    }
    if (!sh_program.link()){
        qDebug() << "ошибка линковки шейдеров";
        close();
    }

    if (!sh_program_simple.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vshader.vert")){
        qDebug() << "ошибка добавления вершинного шейдера";
        close();
    }
    if (!sh_program_simple.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fshader_simple.frag")){
        qDebug() << "ошибка добавления фрагментного шейдера";
        close();
    }
    if (!sh_program_simple.link()){
        qDebug() << "ошибка линковки шейдеров";
        close();
    }
}

void MainWindow::loadObj(QString name){
    otherObjects.append(new SimpleObject(name));
    cur_obj_num = otherObjects.size() - 1;
}

void MainWindow::loadTexture(QString name){
    otherObjects[cur_obj_num]->setTexture(name);
}

//----------------------------------------------------------------------------------------------

void MainWindow::wheelEvent(QWheelEvent* wheelevent){
    camera.translate(QVector3D(0.0, 0.0, wheelevent->delta() / 100.f));
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space)
        camera.setDefault();
    if (event->key() == Qt::Key_Left)
        lamps.at(0)->rotateZ(2);
    if (event->key() == Qt::Key_Right)
        lamps.at(0)->rotateZ(-2);
    if (event->key() == Qt::Key_Up)
        lamps.at(0)->translate(QVector3D(0, 0, 2));
    if (event->key() == Qt::Key_Down)
        lamps.at(0)->translate(QVector3D(0, 0, -2));
    if (event->key() == Qt::Key_1)
        lamps.at(0)->setState(!lamps.at(0)->getState());
    /*if (event->key() == Qt::Key_2)
        lamps.at(1)->setState(!lamps.at(1)->getState());*/
    if (event->key() == Qt::Key_Escape)
        showNormal();
    if (event->key() == Qt::Key_4)  // выбор объекта
        loadObj(QFileDialog::getOpenFileName());
    if (event->key() == Qt::Key_5) //  выбор текстуры
        loadTexture(QFileDialog::getOpenFileName());
    if (event->key() == Qt::Key_7){  // предыдущий объект
        if (cur_obj_num == 0)
            cur_obj_num = otherObjects.size()-1;
            else cur_obj_num = (cur_obj_num-1)%otherObjects.size();
    }
    if (event->key() == Qt::Key_8) //  следующий объект
        cur_obj_num = (cur_obj_num+1)%otherObjects.size();
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent* ev){
    if (ev->buttons() != Qt::LeftButton) return;
    //if (ev->buttons() != Qt::LeftButton) return;
    QVector2D diff = QVector2D(ev->localPos()) - mouse_pos;

    float angleX = diff.y() / 2.0f;
    float angleY = diff.x() / 2.0f;
    camera.rotateX(QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, angleX));
    camera.rotateY(QQuaternion::fromAxisAndAngle(0.0f, 0.0f, 1.0f, angleY));

    mouse_pos = QVector2D(ev->localPos());
    update();
}

void MainWindow::mousePressEvent(QMouseEvent* ev){
    //if (ev->buttons() == Qt::MidButton)
    if (ev->buttons() == Qt::LeftButton)
        mouse_pos = QVector2D(ev->localPos());
    /*if (ev->buttons() == Qt::LeftButton)
        click_pos = QVector2D(ev->localPos());*/
}

//---------------------------------------------------------------------------------------------

QVector3D MainWindow::screenToWord(const QVector2D &mouse_pos) const{
    QVector4D tmp(2.0f * mouse_pos.x() / width() - 1.0f, -2.0f * mouse_pos.y() / height() + 1.0f, -1.0f, 1.0f);
    QVector4D iTmp((projectionMatrix.inverted() * tmp).toVector2D(), -1.0f, 0.0f);
    QVector3D direction((camera.getviewMatrix().inverted() * iTmp).toVector3D().normalized());
    QVector3D camPos((camera.getviewMatrix().inverted() * QVector4D(0.0f, 0.0f, 0.0f, 1.0f)).toVector3D());

    // Ax + By +Cz + D = 0
    // Norm = (A, B, C)
    // P * N - P0 * N = 0
    // O + D*t
    // (O + D*t)*N - P0*N = 0
    // t = (P0*N - O*N)/(D*N)
    // result = O + D * t

    QVector3D N(0.0f, 0.0f, 1.0f);
    float t = -QVector3D::dotProduct(camPos, N) / QVector3D::dotProduct(direction, N);
    QVector3D result = camPos + direction * t;
    return result;
}

QVector2D MainWindow::wordToField(const QVector3D &coord) const{
    int x = int(coord.x() + grid_sz * field_sz/2.0)/6 + 1;
    int y = int(coord.y() + grid_sz * field_sz/2.0)/6 + 1;
    return QVector2D(x, y);
}

int MainWindow::findFig(const QVector2D &pos) const{
    for (int i = 0; i < chessFigures.size(); i++)
        if (chessFigures[i]->onThisPos(pos.x(), pos.y()))
            return i;
    return -1;
}

void MainWindow::endMove(){
    if (game_status == WHITE_MOVE)
        game_status = BLACK_MOVE;
    else if (game_status == BLACK_MOVE)
        game_status = WHITE_MOVE;
}


void MainWindow::drawLines(){
    QVector3D min, max;
    min = chessBoard[0]->getMin();
    max = chessBoard[0]->getMax();

    float dl_x = (max.x()-min.x())/8;
    float dl_y = (max.y()-min.y())/8;

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 1; i < 8; i++){
        glVertex3f(min.x(), min.y()+i*dl_y, min.z()+0.1f);
        glVertex3f(max.x(), min.y()+i*dl_y, min.z()+0.1f);
        glVertex3f(min.x()+i*dl_x, min.y(), min.z()+0.1f);
        glVertex3f(min.x()+i*dl_x, max.y(), min.z()+0.1f);
    }
    glEnd();
}
