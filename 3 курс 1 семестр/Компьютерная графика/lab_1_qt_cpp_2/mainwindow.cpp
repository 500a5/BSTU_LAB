#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this); // Создаём объект-живописец

    QColor orangeRed(240, 100, 0); // Оранжево-красный цвет

    // Радиус большей окружности
    float radius;
    // Вычисляем радиус окружности
    if (width() > height()) // Если ширина окна больше высоты
     radius = (height() - 20) / 2; // Отступ от краёв - 10 пикселей
    else radius = (width() - 20) / 2;

    // Если размеры окна маленькие, ничего не выводить
    if (width() < 30 || height() < 30)
     return;

    // Координаты центра окружности
    QPointF center = QPointF(width() / 2, height() / 2);

    // Задаём область прорисовки круга
    QRectF rect = QRectF(center.x() - radius, center.y() - radius, radius*2, radius*2);

    // Рисуем большой круг красно-оранжевым цветом
    painter.setBrush( orangeRed);
    painter.setPen( orangeRed );
    painter.drawEllipse(rect);

    // Рисуем ещё три круга меньшего диаметра и разными цветами
    float radiuses[3] = { radius*0.9f, radius*0.3f, radius*0.2f };
    // Инициализируем три кисти разного цвета
    QBrush brushes[3] = { QBrush(Qt::black),  QBrush(orangeRed),  QBrush(Qt::black) };

    for (int i = 0; i < 3; i++) {
      rect = QRectF(center.x() - radiuses[i], center.y() - radiuses[i], radiuses[i] * 2, radiuses[i] * 2);
      painter.setBrush(brushes[i]);
      painter.drawEllipse(rect); // Рисуем круги
      // Отсекаем лепестки
      if (i == 1) {
        QRectF rect2 = QRectF((int)(center.x() - radius*0.95), (int)(center.y() - radius*0.95), (int)(radius*0.95*2), (int)(radius*0.95*2));
        painter.setBrush(QBrush(orangeRed));
        // Рисуем три сектора красно-оранжевым цветом
        painter.drawPie(rect2, angle, 60*16);
        painter.drawPie(rect2, angle + 120*16, 60*16);
        painter.drawPie(rect2, angle + 240*16, 60*16);
      }
    }
}


// Обработчик события прокрутки колеса мыши
void MainWindow::wheelEvent(QWheelEvent* wheelevent)
{
    angle -= wheelevent->delta() / 10;
    repaint(); // Обновляем окно
}
