#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtOpenGL>
#include <QtGui>
#include <math.h>
#include <gl/glext.h>
#include <gl/gl.h>

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer();
    connect(timer,SIGNAL (timeout()), this, SLOT(timerUpd()));
    timer->start(10);
    angle_x=angle_y=0;
    nSca = ScaleElka = 1;
    checkElka = true;
    xTra = yTra = zTra = 0.0;
    angleTable=0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete textures;
}
void MainWindow::timerUpd()
{

    angleTable++;
    if(checkElka)
    {
        ScaleElka+=0.006;
    }
    else
    {
        ScaleElka-=0.006;
    }
    if(ScaleElka>1.5) checkElka=false;
    else if (ScaleElka<1.0) checkElka=true;


    repaint();
}

void MainWindow::initializeGL()
{
    qglClearColor(Qt::white);
    glEnable(GL_DEPTH_TEST);//буфер глубины
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_AUTO_NORMAL);
        glLightfv(GL_LIGHT0, GL_POSITION, pos1);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    LoadTexture();

}

void MainWindow::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLdouble)width/(GLdouble)height, 0.001, 1000.0);

    /*glViewport(0, 0, (GLint)width, (GLint)height);

    currentWidth = width;
    currentHeight = height;*/

   // glEnable(GL_TEXTURE_2D);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

void MainWindow::paintGL()
{
    //Очистка буфера глубины и буфера цвета
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //Переключение на матрицу вида
    glMatrixMode(GL_MODELVIEW);
    //Загружаем единичную матрицу вида
    glLoadIdentity();

    glTranslatef(0,0,-3.0);

    glRotatef(angle_y, 1.0, 0.0,0.0);
    glRotatef(angle_x, 0.0, 1.0, 0.0);//glScalef(nSca, nSca, nSca);
    glTranslatef(xTra, yTra, zTra);
    glScalef(nSca, nSca, nSca);


    //drawBox2();drawBox1();drawElka();drawTable();
    room(); drawHause(); drawElka(); drawMan(); drawKolodec();
    //glPushMatrix();
    //glScalef();
}
void MainWindow::mousePressEvent(QMouseEvent* event) {
    m_mousePosition.setX(event->x());
    m_mousePosition.setY(event->y());
}
void MainWindow::mouseMoveEvent(QMouseEvent* m_event)
{
    double dx = m_event->x() - m_mousePosition.x();
    double dy = m_event->y() - m_mousePosition.y();
    m_mousePosition=m_event->pos();
    angle_x += dx ;
    angle_y += dy ;
    repaint();
}

void MainWindow::scale_plus() // приблизить сцену
{
   nSca = nSca*1.1;
}

void MainWindow::scale_minus() // удалиться от сцены
{
   nSca = nSca/1.1;
}

void MainWindow::translate_down() // транслировать сцену вниз
{
   zTra -= 0.05;
}

void MainWindow::translate_up() // транслировать сцену вверх
{
   zTra += 0.05;
}

void MainWindow::translate_Vver() // транслировать сцену вниз
{
   yTra -= 0.05;
}

void MainWindow::translate_Vniz() // транслировать сцену вверх
{
   yTra += 0.05;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

   switch (event->key())
   {
      case Qt::Key_Plus:
         scale_plus();     // приблизить сцену
      break;
      case Qt::Key_Equal:
         scale_plus();     // приблизить сцену
      break;
      case Qt::Key_Minus:
        scale_minus();    // удалиться от сцены
      break;
      case Qt::Key_D:
        translate_down(); // транслировать сцену вниз
      break;
      case Qt::Key_A:
        translate_up();   // транслировать сцену вверх
      break;
      case Qt::Key_W:
        translate_Vver(); // транслировать сцену вниз
      break;
      case Qt::Key_S:
        translate_Vniz();   // транслировать сцену вверх
      break;
      case Qt::Key_1:
         glLightfv(GL_LIGHT0, GL_POSITION, pos1);
      break;
      case Qt::Key_2:
         glLightfv(GL_LIGHT0, GL_POSITION, pos2);
      break;
      case Qt::Key_3:
         glLightfv(GL_LIGHT0, GL_POSITION, pos3);
      break;
   }
   updateGL(); // обновление изображения
}

void MainWindow::LoadTexture()
{
    //---------------------------------------SKYBOX-------------------------------
    glGenTextures(10, textures);
    QImage texture1;
    texture1.load(":/front.jpg");
    texture1 = QGLWidget::convertToGLFormat(texture1);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture1.width(), (GLsizei)texture1.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture1.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture2;
    texture2.load(":/Top.jpg");
    texture2 = QGLWidget::convertToGLFormat(texture2);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture2.width(), (GLsizei)texture2.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture2.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture3;
    texture3.load(":/bottom.jpg");
    texture3 = QGLWidget::convertToGLFormat(texture3);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture3.width(), (GLsizei)texture3.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture3.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture4;
    texture4.load(":/left.jpg");
    texture4 = QGLWidget::convertToGLFormat(texture4);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture4.width(), (GLsizei)texture4.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture4.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture5;
    texture5.load(":/right.jpg");
    texture5 = QGLWidget::convertToGLFormat(texture5);
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture5.width(), (GLsizei)texture5.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture5.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //-------------------------------------ДОМ----------------------------------------------------
    QImage texture6;
    texture6.load(":/housePered.jpg");
    texture6 = QGLWidget::convertToGLFormat(texture6);
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture6.width(), (GLsizei)texture6.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture6.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture7;
    texture7.load(":/houseZad.jpg");
    texture7 = QGLWidget::convertToGLFormat(texture7);
    glBindTexture(GL_TEXTURE_2D, textures[6]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture7.width(), (GLsizei)texture7.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture7.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture8;
    texture8.load(":/houseBok.jpg");
    texture8 = QGLWidget::convertToGLFormat(texture8);
    glBindTexture(GL_TEXTURE_2D, textures[7]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture8.width(), (GLsizei)texture8.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture8.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture9;
    texture9.load(":/houseKrisha.jpg");
    texture9 = QGLWidget::convertToGLFormat(texture9);
    glBindTexture(GL_TEXTURE_2D, textures[8]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture9.width(), (GLsizei)texture9.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture9.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    QImage texture10;
    texture10.load(":/Kolodec.jpg");
    texture10 = QGLWidget::convertToGLFormat(texture10);
    glBindTexture(GL_TEXTURE_2D, textures[9]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)texture10.width(), (GLsizei)texture10.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture10.bits());
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}
void MainWindow::room() {

    LoadTexture();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
       glVertex3f(12, -10, -1.5); // стена с окном
       glTexCoord2d(0, 1);
       glVertex3f(12, 10, -1.5);
       glTexCoord2d(1, 1);
       glVertex3f(-12, 10, -1.5);
       glTexCoord2d(1, 0);
       glVertex3f(-12, -10, -1.5);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3f(12, -10, 20);
        glTexCoord2d(0, 1);
        glVertex3f(12, 10, 20);
        glTexCoord2d(1, 1);
        glVertex3f(12, 10, -1.5);
        glTexCoord2d(1, 0);
        glVertex3f(12, -10, -1.5); // правая стена


    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3f(-12, -10, -1.5);// левая стена
        glTexCoord2d(0, 1);
        glVertex3f(-12, 10, -1.5);
        glTexCoord2d(1, 1);
        glVertex3f(-12, 10, 20);
        glTexCoord2d(1, 0);
        glVertex3f(-12, -10, 20);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3f(-12, -10, -1.5); // пол
        glTexCoord2d(0, 1);
        glVertex3f(-12, -10, 20);
        glTexCoord2d(1, 1);
        glVertex3f(12, -10, 20);
        glTexCoord2d(1, 0);
        glVertex3f(12, -10, -1.5);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex3f(-12, 10, 20);
        glTexCoord2d(0, 1);
        glVertex3f(-12, 10, -1.5);
        glTexCoord2d(1, 1);
        glVertex3f(12, 10, -1.5); // потолок
        glTexCoord2d(1, 0);
        glVertex3f(12, 10, 20);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void MainWindow::drawHause(){
    //glPushMatrix();
    //glColor3f(0.9f, 0.5f, 0.0f);
    glTranslatef(0.0, -6, 4.5);
    //glScalef(ScaleHouse, ScaleHouse, ScaleHouse);
    //Рисуем четырёхугольник
    LoadTexture();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);


    //Задаём вершины многоугольника
    glBindTexture(GL_TEXTURE_2D, textures[6]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);//зад домика
    glVertex3f(-4, -4, -4);//3
    glTexCoord2d(0, 1);
    glVertex3f(-4, 4, -4);//2
    glTexCoord2d(1, 1);
    glVertex3f(4, 4, -4);//1
    glTexCoord2d(1, 0);
    glVertex3f(4, -4, -4);//4
    glEnd();


    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);//перед домика
    glVertex3f(4, -4, 4);//8
    glTexCoord2d(0, 1);
    glVertex3f(4, 4, 4);//5
    glTexCoord2d(1, 1);
    glVertex3f(-4, 4, 4);//6
    glTexCoord2d(1, 0);
    glVertex3f(-4, -4, 4);//7
    glEnd();

    glBindTexture(GL_TEXTURE_2D, textures[7]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);//правый бок домика
    glVertex3f(4, -4, -4);
    glTexCoord2d(0, 1);
    glVertex3f(4, 4, -4);
    glTexCoord2d(1, 1);
    glVertex3f(4, 4, 4);
    glTexCoord2d(1, 0);
    glVertex3f(4, -4, 4);

    qglColor(Qt::blue);
    glVertex3f(3.75, 3.75, -4.001101112);//1
    glVertex3f(-3.75, 3.75, -4.001101112);//2
    glVertex3f(-3.75, -3.75, -4.001101112);//3
    glVertex3f(3.75, -3.75, -4.001101112);//4

    glTexCoord2d(0, 0);//левый бок домика
    glVertex3f(-4, -4, 4);
    glTexCoord2d(0, 1);
    glVertex3f(-4, 4, 4);
    glTexCoord2d(1, 1);
    glVertex3f(-4, 4, -4);
    glTexCoord2d(1, 0);
    glVertex3f(-4, -4, -4);



    qglColor(Qt::black);
    glVertex3f(-4, -4, 4);
    glVertex3f(4, -4, 4);
    glVertex3f(4, -4, -4);
    glVertex3f(-4, -4, -4);

    glEnd();


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textures[8]);
    //glBegin(GL_TRIANGLE_STRIP);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f( 0.0,  8,  0);//9
        glVertex3f( 4, 4, -4);//1
        glTexCoord2d(0, 0);
        glVertex3f(-4, 4, -4);//2
        glTexCoord2d(1, 0);
        glVertex3f(-4, 4, 4);//6
        glTexCoord2d(0, 1);
        glVertex3f(4, 4, 4);//5
        glTexCoord2d(1, 1);
        glVertex3f(4, 4, -4);//1
        glVertex3f(0.0,  8,  0);//9
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void MainWindow::drawKolodec(){
        glPushMatrix();
        glTranslatef(6, 0, 0);
        glRotatef(90, -1.0, 0.0, 0.0);
        glRotatef(0, -1.0, 0.0, 0.0);

        GLint n=10;
        GLfloat angle;
        GLfloat a = M_PI / 180.0;
        GLfloat delta = 360.0 / (GLfloat)n;
        // рисуем колодец
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textures[9]);
        glBegin(GL_QUAD_STRIP);
        //qglColor(Qt::darkCyan);
        angle = 0.0;
        bool f = true;
        for (int i = 0; i <= n; i++)
        {
            if(f){

                glVertex3f(2 * cos(a * angle), 2 * sin(a * angle),  1.5);
                glTexCoord2d(0, 0);
                glVertex3f(2 * cos(a * angle), 2 * sin(a * angle), -0.5);//отвечает за низ
                glTexCoord2d(0, 1);
                angle += delta;
                f = false;
            }
            //glVertex3f(cos(a * angle)/10,sin(a * angle)/10,  3.0);
            else{

                glVertex3f(2 * cos(a * angle), 2 * sin(a * angle),  1.5);
                glTexCoord2d(1, 1);
                glVertex3f(2 * cos(a * angle), 2 * sin(a * angle), -0.5);//отвечает за низ
                glTexCoord2d(1, 0);
                angle += delta;
                f = true;
            }
        }
        glEnd();
        glPopMatrix();
}

/// Рисует елочку
void MainWindow::drawElka()
{
    glPushMatrix();
    glTranslatef(-6, -3.5, 10);
    glRotatef(90, -1.0, 0.0, 0.0);
    glRotatef(0, -1.0, 0.0, 0.0);

    GLint n=10;
    GLfloat angle;
    GLfloat a = M_PI / 180.0;
    GLfloat delta = 360.0 / (GLfloat)n;


    glColor3f(0.5f, 0.35f, 0.05f);
    // рисуем ствол
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    for (int i = 0; i <= n; i++)
    {
        glVertex3f(cos(a * angle),sin(a * angle),  1.5);
        glVertex3f(cos(a * angle),sin(a * angle), -0.5);//отвечает за низ
        angle += delta;
    }
    glEnd();

    //рисуем уровни

    glBegin(GL_TRIANGLE_FAN);
    angle = 0.0;
    for (int i = 0; i <= n; i++)
    {
        qglColor(Qt::green);
        glVertex3f(cos(a * angle)/10,sin(a * angle)/10,  15.0);
        angle += delta;
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    bool f1 = true;
    for (int i = 0; i <= n; i++)
    {
        if(f1){
            qglColor(Qt::green);
            //glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(cos(a * angle)/10,sin(a * angle)/10,  15.0);
            glVertex3f(3 * cos(a * angle), 3 * sin(a * angle), 1);
            angle += delta;
            f1 = false;
        }
        else{
            qglColor(Qt::darkGreen);
            glVertex3f(cos(a * angle)/10,sin(a * angle)/10,  15.0);
            glVertex3f(3 * cos(a * angle), 3 * sin(a * angle), 1);
            angle += delta;
            f1 = true;
        }
        //glEnd();
    }
    glEnd();
    glPopMatrix();
}
void MainWindow::drawMan()
{

    GLUquadric *quad = gluNewQuadric(); //создание стандартного контейнера объкта GL

    glTranslatef(0.0, -2.0, 10.0);  //перемещает объект по осям координат на указанные значения

    gluQuadricDrawStyle(quad, GLU_FILL);  //стиль рисования 3 мерных объектов, точками, либо сплошным либо сеткой
    glPushMatrix();
    qglColor(Qt::white);
        glTranslatef(0.0, 0.8, 0.0); // расположение головы относительно центра

        gluSphere(quad, 0.4, 50,50 );  // рисует голову снеговика - принимает 4 аргумента, 1-й - это указатель на Quadric объект, 2-й - радиус сферы, 3-й и 4-й - количество узлов, из которых будет строится сфера вокруг оси Z и вдоль оси Z соответственно.
        //глаза
        glPushMatrix();
            glTranslatef(-0.15, 0.09, 0.35); //расположение глаз
            qglColor(Qt::black);
            gluSphere(quad, 0.05, 5, 5);   //левый глаз
            glTranslatef(0.30, 0.0, 0.0);  //положение правого глаза
            gluSphere(quad, 0.05, 5, 5);   //правый глаз
            glPopMatrix(); //возвращение к старым координатам

        //рот
        glPushMatrix();
            glTranslatef(0.0, -0.1, 0.35);//позиционирование рта
            qglColor(Qt::black);
            gluPartialDisk(quad, 0.05, 0.15, 10, 10, 90, 180); // отрисовка рта
        glPopMatrix();

        //нос
        glPushMatrix();
            qglColor(Qt::red);
            glTranslatef(0.0, 0.0, 0.7); //позиционирование носа
            glRotatef(180, 1.0, 0.0, 0.0); //угол наклона носа
            gluCylinder(quad, 0, 0.1, 0.4, 10, 10);//отрисовка носа с помощью цилиндра
        glPopMatrix();
  glPopMatrix();

    glPushMatrix();
        qglColor(Qt::white);//для центральной сферы
        glTranslatef(0.0, 0.0, 0.0);
        gluSphere(quad, 0.5, 40, 40);//отрисовка центральной сферы

        glPushMatrix();//запись координат
            glTranslatef(0.0, 0.2, 0.45);//позиционирование верхней пуговицы
            qglColor(Qt::black);
            gluSphere(quad, 0.05, 5, 5);//отрисовка верхней пуговицы сферой
            glTranslatef(0.0, -0.4, 0.0); //расположение нижней пуговицы
            gluSphere(quad, 0.05, 5, 5); //отрисовка нижней пуговицы
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        qglColor(Qt::white);//для нижней сферы
        glTranslatef(0.0, -1.1, 0.0);//позиционирование нижней сферы
        gluSphere(quad, 0.7, 60, 60);//отрисовка сферы
    glPopMatrix();

    gluDeleteQuadric(quad);
   glPopMatrix();
}

/*
void MainWindow::loadObj(const QString &path){
   QFile objFile(path);
    if(!objFile.exists()){
        qDebug() << "File not found";
        return;
    }

    objFile.open(QIODevice::ReadOnly);
    QTextStream input(&objFile);

    QVector<QVector3D> coords;
    QVector<QVector2D> textCoords;
    QVector<QVector3D> normals;

    QVector<VertexData> vertexes;
    QVector<GLuint> indexes;

    while (!input.atEnd()){
        QString str = input.readLine(); //считывание строки
        QStringList list =  str.split(" "); //делим по пробелам
        if (list[0] == "#") {
            qDebug() << "This is comment" << str;
            continue;
         } else if(list[0] == "mtllib"){
            //оработать файл с материалами
            qDebug() << "This with materials" << str;
            continue;
         } else if(list[0] == "v"){
            coords.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
         } else if(list[0] == "vt"){
            textCoords.append(QVector2D(list[1].toFloat(), list[2].toFloat()));
            continue;
         } else if(list[0] == "vn"){
            normals.append(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
            continue;
         } else if(list[0] == "f"){
            for(int i = 1; i <= 3; ++i){
                QStringList vert = list[i].split("/");
                vertexes.append(VertexData(coords[vert[0].toLong()-1], textCoords[vert[1].toLong()-1], normals[vert[2].toLong()-1]));
                indexes.append(indexes.size());
            }
            continue;
        }
    }

    objFile.close();

    m_objects.append(new SimpleObject3D(vertexes, indexes, QImage(":/Penguin Diffuse Color.png")));
}
*/
