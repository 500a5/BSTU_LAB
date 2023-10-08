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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QComboBox *comboBox;
    QLCDNumber *timer;
    QPushButton *start_timer;
    QPushButton *stop_timer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(558, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_6->addWidget(comboBox);

        timer = new QLCDNumber(centralWidget);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setMode(QLCDNumber::Dec);

        verticalLayout_6->addWidget(timer);

        start_timer = new QPushButton(centralWidget);
        start_timer->setObjectName(QStringLiteral("start_timer"));

        verticalLayout_6->addWidget(start_timer);

        stop_timer = new QPushButton(centralWidget);
        stop_timer->setObjectName(QStringLiteral("stop_timer"));

        verticalLayout_6->addWidget(stop_timer);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\232\321\200\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\201\320\265\320\272\321\206\320\270\320\270", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\234\321\214\321\216\321\202\320\265\320\272\321\201\321\213", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\241\320\265\320\274\320\260\321\204\320\276\321\200\321\213", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\226\320\264\321\203\321\211\320\270\320\265 \321\202\320\260\320\271\320\274\320\265\321\200\321\213", Q_NULLPTR)
        );
        start_timer->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\276\321\202\321\201\321\207\320\265\321\202", Q_NULLPTR));
        stop_timer->setText(QApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \321\202\320\260\320\271\320\274\320\265\321\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
