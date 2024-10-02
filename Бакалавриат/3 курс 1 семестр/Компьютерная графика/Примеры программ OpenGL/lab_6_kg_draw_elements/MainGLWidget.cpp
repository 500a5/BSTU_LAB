// Автор: Осипов Олег Васильевич
// Copyright © 2019 БГТУ им. В.Г. Шухова. Кафедра программного обеспечения вычислительной техники и автоматизированных систем.
// Дата изменения: 08.12.2019

// Каркасное приложение для демонстрации буферизованного вывода функцией glDrawElements

#include "MainGLWidget.h"
#include <gl/glu.h>

MainGLWidget::MainGLWidget(QWidget *parent)
    : QGLWidget(parent)
{
    setWindowTitle("Компьютерная графика. Буферизованный вывод");
    setWindowState(Qt::WindowFullScreen); // Разворачиваем приложение на весь экран
}

void MainGLWidget::initializeGL()
{
    // Включение сортировки по глубине
    glEnable(GL_DEPTH_TEST);

    // Инициализируем видовую матрицу
    resetModelView();
}



void MainGLWidget::resizeGL(int nWidth, int nHeight)
{
    // Задание области вывода
    glViewport(0, 0, nWidth, nHeight);
    // Задаём матрицу центрального проектирования
    resetProjection();
}



// Внутри данной подпрограммы происходит рисование объектов
void MainGLWidget::paintGL()
{
    // Очистка буфера глубины и буфера цвета
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Рисование куба
    glCube();

    // Вывод на экран текста
    glColor3f(1, 1, 1);
    QFont text_font("Cambria", 10, QFont::Bold);
    renderText(10, 20, "Колесо мыши - удалить/приблизить", text_font);
    renderText(10, 35, "Зажатая кнопка мыши - повернуть сцену", text_font);
    renderText(10, 50, "Esc - выход", text_font);
}



// Подпрограмма для рисования куба в начале координат
void MainGLWidget::glCube()
{
    // Массив из 8 вершин куба
    float V[8][3] = {{ 1.0f, 1.0f, 1.0f}, // Координаты первой вершины
                     { 1.0f, 1.0f,-1.0f}, // Координаты второй вершины
                     { 1.0f,-1.0f, 1.0f},
                     { 1.0f,-1.0f,-1.0f},
                     {-1.0f, 1.0f, 1.0f},
                     {-1.0f, 1.0f,-1.0f},
                     {-1.0f,-1.0f, 1.0f},
                     {-1.0f,-1.0f,-1.0f}}; // Координаты восьмой вершины

    // Массив цветов вершин
    GLubyte colors[] = {255, 255, 255,   // Цвет первой вершины
                        150, 200, 240,   // Цвет второй вершины
                        255, 255, 255,   // ...
                        250, 180, 150,
                        250, 180, 150,
                        100, 255, 180,
                          0, 250,  50,
                          0,  50, 250};  // Цвет восьмой вершины

    // Массив индексов вершин V
    GLushort indeces[] = {6, 7, 5, 4,   // Индексы вершин первой грани
                          0, 1, 3, 2,   // Индексы вершин второй грани
                          0, 1, 5, 4,   // ...
                          6, 7, 3, 2,
                          4, 6, 2, 0,
                          1, 3, 7, 5};  // Индексы вершин шестой грани

    // Указываем, что будем использовать массив вершин
    glEnableClientState(GL_VERTEX_ARRAY);

    // Считываем координаты вершин
    glVertexPointer(3, GL_FLOAT, 0, V);

    // Указываем, что будем считывать цвета из массива
    glEnableClientState(GL_COLOR_ARRAY);

    // Считываем цвета
    glColorPointer(3, GL_UNSIGNED_BYTE, 0, colors);

    // Рисуем куб
    glDrawElements(GL_QUADS, 6*4, GL_UNSIGNED_SHORT, indeces);

    // Отключаем режимы считывания данных из массивов
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}



void MainGLWidget::resetProjection()
{
    // Переключение на матрицу проектирования
    glMatrixMode(GL_PROJECTION);
    // Загрузка единичной матрицы проектирования
    glLoadIdentity();
    // Инициализация перспективной проекции
    gluPerspective(30.0, (float)width() / height(), 0.1, 20);
}



// Процедура для изменения видовой матрицы
void MainGLWidget::resetModelView()
{
    // Переключение на видовую матрицу
    glMatrixMode(GL_MODELVIEW);
    // Инициализация видовой матрицы в виде единичной матрицы
    glLoadIdentity();
    // Перенос вглубь экрана
    glTranslatef(0, 0, -zoffset);
    // Поворот объекта
    glMultMatrixf(rotateMatrix.inverted().data());
    // Масштабирование
    glScalef(0.3, 0.3, 0.3);
}


// Обработчик события перемещения указателя мыши (событие происходит при зажатой кнопке мыши)
void MainGLWidget::mouseMoveEvent(QMouseEvent* m_event)
{
    // Вычислим, на сколько переместился курсор мыши между двумя событиями mouseMoveEvent
    QPoint dp = m_event->pos() - mousePosition;
    // Изменим матрицу поворота в соответствии с тем, как пользователь переместил курсор мыши
    changeRotateMatrix(rotateMatrix, dp.x(), dp.y());
    // Сохраним текущую позицию мыши
    mousePosition = m_event->pos();
    // Обновим матрицу аффинных преобразований
    resetModelView();
    updateGL(); // Перерисовать окно
}


// Процедура предназначена для изменения матрицы поворота, чтобы куб поворачивался в нужном направлении строго вслед за указателем мыши.
// Вызывается, когда пользователь изменил положение указателя мыши при зажатой кнопке (мыши)
void MainGLWidget::changeRotateMatrix(QMatrix4x4& R, float dx, float dy)
{
    R.rotate(-dx, 0, 1, 0);         // Умножение R на матрицу поворота вокруг оси y
    R.rotate(-dy, 1, 0, 0);         // Умножение R на матрицу поворота вокруг оси x
}


// Обработчик события прокрутки колеса мыши
void MainGLWidget::wheelEvent(QWheelEvent* w_event)
{
    // При прокрутке колеса мыши изменяем глубину объекта
    zoffset -= w_event->delta() / 500.0;
    resetModelView(); // Обновим матрицу аффинных преобразований
    updateGL(); // Перерисовать окно
}


void MainGLWidget::mousePressEvent(QMouseEvent* m_event)
{
    mousePosition = m_event->pos();
}


void MainGLWidget::keyPressEvent(QKeyEvent* event)
{
    // Закрыть окно при нажатии клавиши Escape
    if (event->key() == Qt::Key_Escape)
    {
        close();
    }
}
