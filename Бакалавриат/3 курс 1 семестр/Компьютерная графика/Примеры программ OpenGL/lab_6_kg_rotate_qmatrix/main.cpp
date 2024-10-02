#include "mainwindow.h"
#include <QApplication>
#include <mainglwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainGLWidget w(nullptr);
    w.show();

    return a.exec();
}
