/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Create;
    QPushButton *pushButton_start;
    QPushButton *pushButton_end;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(420, 281);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Create = new QPushButton(centralWidget);
        pushButton_Create->setObjectName(QStringLiteral("pushButton_Create"));
        pushButton_Create->setGeometry(QRect(10, 10, 391, 40));
        pushButton_Create->setAutoRepeatDelay(300);
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(10, 60, 391, 40));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy);
        pushButton_start->setAutoRepeatDelay(300);
        pushButton_end = new QPushButton(centralWidget);
        pushButton_end->setObjectName(QStringLiteral("pushButton_end"));
        pushButton_end->setGeometry(QRect(10, 110, 391, 40));
        pushButton_end->setAutoRepeatDelay(300);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 180, 391, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 420, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_Create->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\321\214\321\216\321\202\320\265\320\272\321\201", Q_NULLPTR));
        pushButton_start->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\276\321\202\321\201\321\207\320\265\321\202", Q_NULLPTR));
        pushButton_end->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\276\321\202\321\201\321\207\320\265\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
