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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextEdit *nameEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QTextEdit *fullEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *handleEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *nameRadio;
    QRadioButton *fullRadio;
    QRadioButton *handleRadio;
    QRadioButton *noRadio;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *currIDEdit;
    QTextEdit *currPseudoEdit;
    QTextEdit *currHandleDupEdit;
    QTextEdit *currHandleOpenEdit;
    QTextEdit *currCloseDupEdit;
    QTextEdit *currCloseOpenEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QWidget *tab_7;
    QPushButton *pushButton_7;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_15;
    QTableWidget *tableProc;
    QTableWidget *tableMod;
    QTableWidget *tableThread;
    QWidget *tab_8;
    QPushButton *pushButton_13;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_26;
    QTableWidget *tableNTProc;
    QTreeWidget *treeModul;
    QWidget *tab_14;
    QListWidget *listDriv;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(643, 489);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 640, 441));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        nameEdit = new QTextEdit(tab);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout_3->addWidget(nameEdit);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        fullEdit = new QTextEdit(tab);
        fullEdit->setObjectName(QStringLiteral("fullEdit"));

        verticalLayout_4->addWidget(fullEdit);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        handleEdit = new QTextEdit(tab);
        handleEdit->setObjectName(QStringLiteral("handleEdit"));

        verticalLayout_2->addWidget(handleEdit);


        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        nameRadio = new QRadioButton(groupBox);
        nameRadio->setObjectName(QStringLiteral("nameRadio"));

        verticalLayout->addWidget(nameRadio);

        fullRadio = new QRadioButton(groupBox);
        fullRadio->setObjectName(QStringLiteral("fullRadio"));

        verticalLayout->addWidget(fullRadio);

        handleRadio = new QRadioButton(groupBox);
        handleRadio->setObjectName(QStringLiteral("handleRadio"));

        verticalLayout->addWidget(handleRadio);

        noRadio = new QRadioButton(groupBox);
        noRadio->setObjectName(QStringLiteral("noRadio"));

        verticalLayout->addWidget(noRadio);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_6->addLayout(horizontalLayout);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_6->addWidget(pushButton_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_7 = new QVBoxLayout(tab_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        currIDEdit = new QTextEdit(tab_2);
        currIDEdit->setObjectName(QStringLiteral("currIDEdit"));

        verticalLayout_7->addWidget(currIDEdit);

        currPseudoEdit = new QTextEdit(tab_2);
        currPseudoEdit->setObjectName(QStringLiteral("currPseudoEdit"));

        verticalLayout_7->addWidget(currPseudoEdit);

        currHandleDupEdit = new QTextEdit(tab_2);
        currHandleDupEdit->setObjectName(QStringLiteral("currHandleDupEdit"));

        verticalLayout_7->addWidget(currHandleDupEdit);

        currHandleOpenEdit = new QTextEdit(tab_2);
        currHandleOpenEdit->setObjectName(QStringLiteral("currHandleOpenEdit"));

        verticalLayout_7->addWidget(currHandleOpenEdit);

        currCloseDupEdit = new QTextEdit(tab_2);
        currCloseDupEdit->setObjectName(QStringLiteral("currCloseDupEdit"));

        verticalLayout_7->addWidget(currCloseDupEdit);

        currCloseOpenEdit = new QTextEdit(tab_2);
        currCloseOpenEdit->setObjectName(QStringLiteral("currCloseOpenEdit"));

        verticalLayout_7->addWidget(currCloseOpenEdit);

        horizontalSpacer = new QSpacerItem(614, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_7->addWidget(pushButton_3);

        tabWidget->addTab(tab_2, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        pushButton_7 = new QPushButton(tab_7);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 390, 621, 23));
        layoutWidget = new QWidget(tab_7);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 621, 371));
        verticalLayout_15 = new QVBoxLayout(layoutWidget);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        tableProc = new QTableWidget(layoutWidget);
        tableProc->setObjectName(QStringLiteral("tableProc"));

        verticalLayout_15->addWidget(tableProc);

        tableMod = new QTableWidget(layoutWidget);
        tableMod->setObjectName(QStringLiteral("tableMod"));

        verticalLayout_15->addWidget(tableMod);

        tableThread = new QTableWidget(layoutWidget);
        tableThread->setObjectName(QStringLiteral("tableThread"));
        tableThread->setMinimumSize(QSize(0, 96));
        tableThread->setMaximumSize(QSize(16777215, 96));

        verticalLayout_15->addWidget(tableThread);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        pushButton_13 = new QPushButton(tab_8);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(10, 380, 621, 23));
        layoutWidget1 = new QWidget(tab_8);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 621, 361));
        verticalLayout_26 = new QVBoxLayout(layoutWidget1);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_26->setContentsMargins(0, 0, 0, 0);
        tableNTProc = new QTableWidget(layoutWidget1);
        tableNTProc->setObjectName(QStringLiteral("tableNTProc"));

        verticalLayout_26->addWidget(tableNTProc);

        treeModul = new QTreeWidget(layoutWidget1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeModul->setHeaderItem(__qtreewidgetitem);
        treeModul->setObjectName(QStringLiteral("treeModul"));

        verticalLayout_26->addWidget(treeModul);

        tabWidget->addTab(tab_8, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        listDriv = new QListWidget(tab_14);
        listDriv->setObjectName(QStringLiteral("listDriv"));
        listDriv->setGeometry(QRect(0, 0, 631, 371));
        pushButton_4 = new QPushButton(tab_14);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 380, 621, 23));
        tabWidget->addTab(tab_14, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200", Q_NULLPTR));
        groupBox->setTitle(QString());
        nameRadio->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        fullRadio->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217", Q_NULLPTR));
        handleRadio->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200", Q_NULLPTR));
        noRadio->setText(QApplication::translate("MainWindow", "\320\235\320\270\321\207\320\265\320\263\320\276", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Windows 9x", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Windows NT", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_14), QApplication::translate("MainWindow", "\320\224\321\200\320\260\320\271\320\262\320\265\321\200\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
