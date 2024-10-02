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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
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
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *handle_LineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *name_LineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *fname_LineEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *get_Button;
    QPushButton *clear_Button;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_12;
    QLabel *label_6;
    QLineEdit *id_Line;
    QGridLayout *gridLayout_11;
    QLabel *label_7;
    QLineEdit *pseudoid_Line;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QLineEdit *copy_handle_Line;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QLineEdit *open_handle_Line;
    QGridLayout *gridLayout_10;
    QLabel *label_11;
    QLineEdit *close_open_handle_Line;
    QGridLayout *gridLayout_13;
    QLabel *label_10;
    QLineEdit *close_copy_handle_Line;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QTreeWidget *processes_TreeWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_8;
    QListWidget *drivers_List;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *modules_Table;
    QTableWidget *processes_Table;
    QTableWidget *threads_Table;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(714, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(500, 500));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_7 = new QGridLayout(centralWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777213, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setFocusPolicy(Qt::WheelFocus);

        verticalLayout->addWidget(radioButton_4);


        horizontalLayout_11->addLayout(verticalLayout);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 0));

        horizontalLayout_11->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        gridLayout_5->addLayout(horizontalLayout_11, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(150, 15));
        label->setMaximumSize(QSize(150, 15));

        horizontalLayout_3->addWidget(label);

        handle_LineEdit = new QLineEdit(groupBox_2);
        handle_LineEdit->setObjectName(QStringLiteral("handle_LineEdit"));
        sizePolicy.setHeightForWidth(handle_LineEdit->sizePolicy().hasHeightForWidth());
        handle_LineEdit->setSizePolicy(sizePolicy);
        handle_LineEdit->setMinimumSize(QSize(400, 20));
        handle_LineEdit->setMaximumSize(QSize(115, 20));

        horizontalLayout_3->addWidget(handle_LineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(150, 15));
        label_2->setMaximumSize(QSize(150, 15));

        horizontalLayout_2->addWidget(label_2);

        name_LineEdit = new QLineEdit(groupBox_2);
        name_LineEdit->setObjectName(QStringLiteral("name_LineEdit"));
        sizePolicy.setHeightForWidth(name_LineEdit->sizePolicy().hasHeightForWidth());
        name_LineEdit->setSizePolicy(sizePolicy);
        name_LineEdit->setMinimumSize(QSize(400, 20));
        name_LineEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(name_LineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(150, 15));
        label_3->setMaximumSize(QSize(150, 15));

        horizontalLayout->addWidget(label_3);

        fname_LineEdit = new QLineEdit(groupBox_2);
        fname_LineEdit->setObjectName(QStringLiteral("fname_LineEdit"));
        sizePolicy.setHeightForWidth(fname_LineEdit->sizePolicy().hasHeightForWidth());
        fname_LineEdit->setSizePolicy(sizePolicy);
        fname_LineEdit->setMinimumSize(QSize(400, 20));
        fname_LineEdit->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(fname_LineEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        get_Button = new QPushButton(tab);
        get_Button->setObjectName(QStringLiteral("get_Button"));

        horizontalLayout_4->addWidget(get_Button);

        clear_Button = new QPushButton(tab);
        clear_Button->setObjectName(QStringLiteral("clear_Button"));

        horizontalLayout_4->addWidget(clear_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(340, 15));
        label_6->setMaximumSize(QSize(340, 15));

        gridLayout_12->addWidget(label_6, 0, 0, 1, 1);

        id_Line = new QLineEdit(tab_2);
        id_Line->setObjectName(QStringLiteral("id_Line"));
        sizePolicy.setHeightForWidth(id_Line->sizePolicy().hasHeightForWidth());
        id_Line->setSizePolicy(sizePolicy);
        id_Line->setMinimumSize(QSize(200, 20));
        id_Line->setMaximumSize(QSize(100, 150));

        gridLayout_12->addWidget(id_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_12);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(340, 15));
        label_7->setMaximumSize(QSize(340, 15));

        gridLayout_11->addWidget(label_7, 0, 0, 1, 1);

        pseudoid_Line = new QLineEdit(tab_2);
        pseudoid_Line->setObjectName(QStringLiteral("pseudoid_Line"));
        sizePolicy.setHeightForWidth(pseudoid_Line->sizePolicy().hasHeightForWidth());
        pseudoid_Line->setSizePolicy(sizePolicy);
        pseudoid_Line->setMinimumSize(QSize(200, 20));
        pseudoid_Line->setMaximumSize(QSize(100, 150));

        gridLayout_11->addWidget(pseudoid_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_11);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(340, 15));
        label_8->setMaximumSize(QSize(340, 15));

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        copy_handle_Line = new QLineEdit(tab_2);
        copy_handle_Line->setObjectName(QStringLiteral("copy_handle_Line"));
        sizePolicy.setHeightForWidth(copy_handle_Line->sizePolicy().hasHeightForWidth());
        copy_handle_Line->setSizePolicy(sizePolicy);
        copy_handle_Line->setMinimumSize(QSize(200, 20));
        copy_handle_Line->setMaximumSize(QSize(100, 150));

        gridLayout_8->addWidget(copy_handle_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_8);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(340, 15));
        label_9->setMaximumSize(QSize(340, 15));

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

        open_handle_Line = new QLineEdit(tab_2);
        open_handle_Line->setObjectName(QStringLiteral("open_handle_Line"));
        sizePolicy.setHeightForWidth(open_handle_Line->sizePolicy().hasHeightForWidth());
        open_handle_Line->setSizePolicy(sizePolicy);
        open_handle_Line->setMinimumSize(QSize(200, 20));
        open_handle_Line->setMaximumSize(QSize(100, 150));

        gridLayout_9->addWidget(open_handle_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_9);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(340, 15));
        label_11->setMaximumSize(QSize(340, 15));

        gridLayout_10->addWidget(label_11, 0, 0, 1, 1);

        close_open_handle_Line = new QLineEdit(tab_2);
        close_open_handle_Line->setObjectName(QStringLiteral("close_open_handle_Line"));
        sizePolicy.setHeightForWidth(close_open_handle_Line->sizePolicy().hasHeightForWidth());
        close_open_handle_Line->setSizePolicy(sizePolicy);
        close_open_handle_Line->setMinimumSize(QSize(200, 20));
        close_open_handle_Line->setMaximumSize(QSize(100, 150));

        gridLayout_10->addWidget(close_open_handle_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_10);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(340, 15));
        label_10->setMaximumSize(QSize(340, 15));

        gridLayout_13->addWidget(label_10, 0, 0, 1, 1);

        close_copy_handle_Line = new QLineEdit(tab_2);
        close_copy_handle_Line->setObjectName(QStringLiteral("close_copy_handle_Line"));
        sizePolicy.setHeightForWidth(close_copy_handle_Line->sizePolicy().hasHeightForWidth());
        close_copy_handle_Line->setSizePolicy(sizePolicy);
        close_copy_handle_Line->setMinimumSize(QSize(200, 20));
        close_copy_handle_Line->setMaximumSize(QSize(100, 150));

        gridLayout_13->addWidget(close_copy_handle_Line, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_13);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        processes_TreeWidget = new QTreeWidget(tab_3);
        processes_TreeWidget->setObjectName(QStringLiteral("processes_TreeWidget"));
        processes_TreeWidget->setColumnCount(0);

        verticalLayout_7->addWidget(processes_TreeWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 7);

        verticalLayout_7->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        drivers_List = new QListWidget(tab_4);
        drivers_List->setObjectName(QStringLiteral("drivers_List"));

        verticalLayout_8->addWidget(drivers_List);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 7);

        verticalLayout_8->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        modules_Table = new QTableWidget(tab_5);
        modules_Table->setObjectName(QStringLiteral("modules_Table"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(modules_Table->sizePolicy().hasHeightForWidth());
        modules_Table->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(modules_Table);

        processes_Table = new QTableWidget(tab_5);
        processes_Table->setObjectName(QStringLiteral("processes_Table"));
        sizePolicy1.setHeightForWidth(processes_Table->sizePolicy().hasHeightForWidth());
        processes_Table->setSizePolicy(sizePolicy1);

        verticalLayout_9->addWidget(processes_Table);


        horizontalLayout_8->addLayout(verticalLayout_9);

        threads_Table = new QTableWidget(tab_5);
        threads_Table->setObjectName(QStringLiteral("threads_Table"));

        horizontalLayout_8->addWidget(threads_Table);

        horizontalLayout_8->setStretch(0, 5);
        horizontalLayout_8->setStretch(1, 3);

        verticalLayout_10->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_3 = new QPushButton(tab_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_7->addWidget(pushButton_3);

        horizontalSpacer_5 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 7);

        verticalLayout_10->addLayout(horizontalLayout_7);


        gridLayout_4->addLayout(verticalLayout_10, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_7->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 714, 21));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_2->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "\320\275\320\265\321\202", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217 \320\274\320\276\320\264\321\203\320\273\321\217", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217 \320\274\320\276\320\264\321\203\320\273\321\217", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217 \320\274\320\276\320\264\321\203\320\273\321\217:", Q_NULLPTR));
        get_Button->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", Q_NULLPTR));
        clear_Button->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200, \320\270\320\274\321\217, \320\277\320\276\320\273\320\275\320\276\320\265 \320\270\320\274\321\217 \320\274\320\276\320\264\321\203\320\273\321\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\260:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\321\201\320\265\320\262\320\264\320\276\320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200,  \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 DuplicateHandle:    ", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\224\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200,  \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 OpenProcess:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\320\262\320\260\320\265\320\274 \320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200,   \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 OpenProcess:   ", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\320\262\320\260\320\265\320\274 \320\264\320\265\321\201\320\272\321\200\320\270\320\277\321\202\320\276\321\200,  \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\265\320\271 DuplicateHandle:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Windows NT", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\320\224\321\200\320\260\320\271\320\262\320\265\321\200\321\213", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Windows 9X", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\247\320\265\321\200\320\272\320\260\321\201\320\276\320\262\320\260 \320\220. \320\240., \320\236\320\241-2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
