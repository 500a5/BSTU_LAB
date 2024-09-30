// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mainwindow.h"
#include <QtWidgets\QApplication>
#include <QtWidgets\QDialog.h>
#include <QtWidgets\QLabel.h>
#include <QtWidgets\QScrollBar.h>
#include <QtCore\QString>

//#include <QtCore\QObject.h>

#include <QtWidgets\QMainWindow.h>
#include <QtWidgets\QPushButton.h>
#include <QtWidgets\QScrollArea.h>

#pragma comment(lib, "Qt5Widgets.lib")
#pragma comment(lib, "Qt5Core.lib")
#pragma comment(lib, "Qt5Gui.lib")


int _tmain(int argc, _TCHAR* argv[])
{
    QApplication a(argc, 0);
    MainWindow w;
	w.setWindowTitle(QObject::tr("lab1"));
    w.show();
    return a.exec();
}

