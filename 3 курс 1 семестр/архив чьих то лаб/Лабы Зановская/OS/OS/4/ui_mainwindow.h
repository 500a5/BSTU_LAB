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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit_ArhProc;
    QLineEdit *lineEdit_KolProc;
    QLineEdit *lineEdit_RedProc;
    QLineEdit *lineEdit_LvlProc;
    QLineEdit *lineEdit_MaskProc;
    QLineEdit *lineEdit_SizePage;
    QLineEdit *lineEdit_DownAdr;
    QLineEdit *lineEdit_UpAdr;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_Granul;
    QWidget *tab_3;
    QComboBox *comboBox_FullProc;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(708, 445);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 701, 391));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit_ArhProc = new QLineEdit(tab);
        lineEdit_ArhProc->setObjectName(QStringLiteral("lineEdit_ArhProc"));
        lineEdit_ArhProc->setGeometry(QRect(250, 10, 331, 20));
        lineEdit_KolProc = new QLineEdit(tab);
        lineEdit_KolProc->setObjectName(QStringLiteral("lineEdit_KolProc"));
        lineEdit_KolProc->setGeometry(QRect(250, 40, 331, 20));
        lineEdit_RedProc = new QLineEdit(tab);
        lineEdit_RedProc->setObjectName(QStringLiteral("lineEdit_RedProc"));
        lineEdit_RedProc->setGeometry(QRect(250, 70, 331, 20));
        lineEdit_LvlProc = new QLineEdit(tab);
        lineEdit_LvlProc->setObjectName(QStringLiteral("lineEdit_LvlProc"));
        lineEdit_LvlProc->setGeometry(QRect(250, 100, 331, 20));
        lineEdit_MaskProc = new QLineEdit(tab);
        lineEdit_MaskProc->setObjectName(QStringLiteral("lineEdit_MaskProc"));
        lineEdit_MaskProc->setGeometry(QRect(250, 130, 331, 20));
        lineEdit_SizePage = new QLineEdit(tab);
        lineEdit_SizePage->setObjectName(QStringLiteral("lineEdit_SizePage"));
        lineEdit_SizePage->setGeometry(QRect(250, 160, 331, 20));
        lineEdit_DownAdr = new QLineEdit(tab);
        lineEdit_DownAdr->setObjectName(QStringLiteral("lineEdit_DownAdr"));
        lineEdit_DownAdr->setGeometry(QRect(250, 190, 331, 20));
        lineEdit_UpAdr = new QLineEdit(tab);
        lineEdit_UpAdr->setObjectName(QStringLiteral("lineEdit_UpAdr"));
        lineEdit_UpAdr->setGeometry(QRect(250, 220, 331, 20));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 211, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 211, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 211, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 211, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 130, 211, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 211, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 190, 211, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 221, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 250, 221, 16));
        lineEdit_Granul = new QLineEdit(tab);
        lineEdit_Granul->setObjectName(QStringLiteral("lineEdit_Granul"));
        lineEdit_Granul->setGeometry(QRect(250, 250, 331, 20));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        comboBox_FullProc = new QComboBox(tab_3);
        comboBox_FullProc->setObjectName(QStringLiteral("comboBox_FullProc"));
        comboBox_FullProc->setGeometry(QRect(0, 10, 681, 22));
        tableWidget = new QTableWidget(tab_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 50, 681, 301));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 708, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\220\320\240\320\245\320\230\320\242\320\225\320\232\320\242\320\243\320\240\320\220 \320\237\320\240\320\236\320\246\320\225\320\241\320\241\320\236\320\240\320\236\320\222", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200\320\276\320\262", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200\320\276\320\262", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\320\260\321\217 \320\274\320\260\321\201\320\272\320\260 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\321\200\320\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\321\213 (\320\261\320\260\320\271\321\202)", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\235\320\270\320\266\320\275\321\217\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 \320\260\320\264\321\200\320\265\321\201\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\205\320\275\321\217\321\217 \320\263\321\200\320\260\320\275\320\270\321\206\320\260 \320\260\320\264\321\200\320\265\321\201\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\275\321\203\320\273\321\217\321\200\320\275\320\276\321\201\321\202\321\214 \320\262\320\270\321\200\321\202\321\203\320\260\320\273\321\214\320\275\320\276\320\271 \320\277\320\260\320\274\321\217\321\202\320\270 (\320\261\320\260\320\271\321\202)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\342\204\226 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\342\204\226 3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
