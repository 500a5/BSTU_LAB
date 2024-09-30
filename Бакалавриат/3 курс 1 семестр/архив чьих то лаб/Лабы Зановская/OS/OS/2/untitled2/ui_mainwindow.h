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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineInput;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QLineEdit *lineHandle;
    QLabel *label_2;
    QLineEdit *lineName;
    QLabel *label_3;
    QLineEdit *lineFullName;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *currIDEdit;
    QLabel *label_5;
    QLineEdit *currPseudoEdit;
    QLabel *label_6;
    QLineEdit *currHandleDupEdit;
    QLabel *label_7;
    QLineEdit *currHandleOpenEdit;
    QLabel *label_8;
    QLineEdit *currCloseDupEdit;
    QLabel *label_9;
    QLineEdit *currCloseOpenEdit;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableProc;
    QTableWidget *tableMod;
    QTableWidget *tableThrd;
    QPushButton *pushButton_3;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableNTProc;
    QTreeWidget *treeModul;
    QPushButton *pushButton_5;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listDriv;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(594, 445);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, -20, 699, 489));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_11 = new QVBoxLayout(tab);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineInput = new QLineEdit(groupBox);
        lineInput->setObjectName(QStringLiteral("lineInput"));

        verticalLayout_2->addWidget(lineInput);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        comboBox->setFont(font);

        verticalLayout_2->addWidget(comboBox);


        verticalLayout_9->addLayout(verticalLayout_2);


        verticalLayout_11->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_10 = new QVBoxLayout(groupBox_2);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_10->addWidget(label);

        lineHandle = new QLineEdit(groupBox_2);
        lineHandle->setObjectName(QStringLiteral("lineHandle"));

        verticalLayout_10->addWidget(lineHandle);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_10->addWidget(label_2);

        lineName = new QLineEdit(groupBox_2);
        lineName->setObjectName(QStringLiteral("lineName"));

        verticalLayout_10->addWidget(lineName);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_10->addWidget(label_3);

        lineFullName = new QLineEdit(groupBox_2);
        lineFullName->setObjectName(QStringLiteral("lineFullName"));

        verticalLayout_10->addWidget(lineFullName);


        verticalLayout_11->addWidget(groupBox_2);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_11->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_11->addWidget(pushButton_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        currIDEdit = new QLineEdit(tab_2);
        currIDEdit->setObjectName(QStringLiteral("currIDEdit"));

        verticalLayout_3->addWidget(currIDEdit);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        currPseudoEdit = new QLineEdit(tab_2);
        currPseudoEdit->setObjectName(QStringLiteral("currPseudoEdit"));

        verticalLayout_3->addWidget(currPseudoEdit);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        currHandleDupEdit = new QLineEdit(tab_2);
        currHandleDupEdit->setObjectName(QStringLiteral("currHandleDupEdit"));

        verticalLayout_3->addWidget(currHandleDupEdit);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        currHandleOpenEdit = new QLineEdit(tab_2);
        currHandleOpenEdit->setObjectName(QStringLiteral("currHandleOpenEdit"));

        verticalLayout_3->addWidget(currHandleOpenEdit);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        currCloseDupEdit = new QLineEdit(tab_2);
        currCloseDupEdit->setObjectName(QStringLiteral("currCloseDupEdit"));

        verticalLayout_3->addWidget(currCloseDupEdit);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        currCloseOpenEdit = new QLineEdit(tab_2);
        currCloseOpenEdit->setObjectName(QStringLiteral("currCloseOpenEdit"));

        verticalLayout_3->addWidget(currCloseOpenEdit);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableProc = new QTableWidget(tab_3);
        tableProc->setObjectName(QStringLiteral("tableProc"));

        verticalLayout->addWidget(tableProc);

        tableMod = new QTableWidget(tab_3);
        tableMod->setObjectName(QStringLiteral("tableMod"));

        verticalLayout->addWidget(tableMod);

        tableThrd = new QTableWidget(tab_3);
        tableThrd->setObjectName(QStringLiteral("tableThrd"));

        verticalLayout->addWidget(tableThrd);


        verticalLayout_6->addLayout(verticalLayout);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_6->addWidget(pushButton_3);


        verticalLayout_7->addLayout(verticalLayout_6);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableNTProc = new QTableWidget(tab_4);
        tableNTProc->setObjectName(QStringLiteral("tableNTProc"));

        horizontalLayout->addWidget(tableNTProc);


        verticalLayout_5->addLayout(horizontalLayout);

        treeModul = new QTreeWidget(tab_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeModul->setHeaderItem(__qtreewidgetitem);
        treeModul->setObjectName(QStringLiteral("treeModul"));

        verticalLayout_5->addWidget(treeModul);

        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_5->addWidget(pushButton_5);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        verticalLayout_4 = new QVBoxLayout(tab_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        listDriv = new QListWidget(tab_5);
        listDriv->setObjectName(QStringLiteral("listDriv"));

        verticalLayout_4->addWidget(listDriv);

        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);

        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\235\320\265\321\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\237\321\201\320\265\320\262\320\264\320\276\320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200, \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 DuplicateHandle", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200, \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 OpenProcess", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\320\262\320\260\320\265\320\274 \320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200, \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 DuplicateHandle", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\320\262\320\260\320\265\320\274 \320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200, \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 OpenProcess: ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Windows 9x", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Windows NT", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "\320\224\321\200\320\260\320\271\320\262\320\265\321\200\321\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
