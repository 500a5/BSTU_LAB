#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.setWindowTitle("Lab3_wait");


    w.show();

    int ret = a.exec();




    return ret;
}
