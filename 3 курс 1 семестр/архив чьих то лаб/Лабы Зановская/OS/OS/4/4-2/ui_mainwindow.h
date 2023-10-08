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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *v_all;
    QLabel *phys_awail;
    QLabel *v_awail;
    QLabel *phys_all;
    QLabel *page_awail;
    QLabel *proc;
    QLabel *page_all;
    QTextEdit *textEdit;
    QLabel *sec;
    QLabel *sec_2;
    QLabel *sec_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(671, 482);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        v_all = new QLabel(centralWidget);
        v_all->setObjectName(QStringLiteral("v_all"));
        v_all->setGeometry(QRect(80, 270, 47, 13));
        phys_awail = new QLabel(centralWidget);
        phys_awail->setObjectName(QStringLiteral("phys_awail"));
        phys_awail->setGeometry(QRect(80, 120, 47, 13));
        v_awail = new QLabel(centralWidget);
        v_awail->setObjectName(QStringLiteral("v_awail"));
        v_awail->setGeometry(QRect(80, 250, 47, 13));
        phys_all = new QLabel(centralWidget);
        phys_all->setObjectName(QStringLiteral("phys_all"));
        phys_all->setGeometry(QRect(80, 140, 47, 13));
        page_awail = new QLabel(centralWidget);
        page_awail->setObjectName(QStringLiteral("page_awail"));
        page_awail->setGeometry(QRect(80, 380, 47, 13));
        proc = new QLabel(centralWidget);
        proc->setObjectName(QStringLiteral("proc"));
        proc->setGeometry(QRect(10, 20, 161, 16));
        page_all = new QLabel(centralWidget);
        page_all->setObjectName(QStringLiteral("page_all"));
        page_all->setGeometry(QRect(80, 400, 47, 13));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(180, 19, 200, 23));
        sec = new QLabel(centralWidget);
        sec->setObjectName(QStringLiteral("sec"));
        sec->setGeometry(QRect(10, 100, 111, 16));
        sec_2 = new QLabel(centralWidget);
        sec_2->setObjectName(QStringLiteral("sec_2"));
        sec_2->setGeometry(QRect(10, 230, 111, 16));
        sec_3 = new QLabel(centralWidget);
        sec_3->setObjectName(QStringLiteral("sec_3"));
        sec_3->setGeometry(QRect(10, 360, 111, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 120, 51, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 270, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 250, 51, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 400, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 380, 51, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        v_all->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        phys_awail->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        v_awail->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        phys_all->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        page_awail->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        proc->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\320\276\320\271 \320\277\320\260\320\274\321\217\321\202\320\270", Q_NULLPTR));
        page_all->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        sec->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\277\320\260\320\274\321\217\321\202\321\214", Q_NULLPTR));
        sec_2->setText(QApplication::translate("MainWindow", "\320\222\320\270\321\200\321\202\321\203\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\260\320\274\321\217\321\202\321\214", Q_NULLPTR));
        sec_3->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\277\320\276\320\264\320\272\320\260\321\207\320\272\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
