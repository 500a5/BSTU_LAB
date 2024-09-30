#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w_1, w_2;

    w_1.setWindowTitle("Lab3_1");
    w_2.setWindowTitle("Lab3_2");

    w_1.move(0, 0);
    w_2.move(w_1.rect().right()+ 20, w_1.rect().top());

    w_1.show();
    w_2.show();

    int ret = a.exec();


    return ret;
}
