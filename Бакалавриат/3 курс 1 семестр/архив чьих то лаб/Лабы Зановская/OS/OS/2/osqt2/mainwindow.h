#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <QMessageBox>
#include <QTableWidget>
#include <QListWidget>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();
    void on_tableProc_itemClicked(QTableWidgetItem *item);
    void on_pushButton_4_clicked();
    void on_tableNTProc_itemClicked(QTableWidgetItem *item);
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    //Первое задание: определение
    void showInfo(HMODULE hmod, QString name, QString fullname);

    bool getInfoByHandle(HMODULE hmodule, QString& name, QString& moduleName);
    void showInfoByHandle();

    bool getInfoByName(HMODULE& hmodule, QString name, QString &moduleName);
    void showInfoByName();

    bool getInfoByFullName(HMODULE &hmodule, QString& name, QString moduleName);
    void showInfoByFullName();

    bool getFullInfoExe(QString &name, QString &moduleName, HMODULE &hmodule);
    void showFullInfoExe();

    void showProcInfo();
    void showHandleInfo();
    void showLittleNameInfo();

    //Второе задание: текущий процесс
    void showCurrentInfo();

    //Widows 9x
    void settingsFinWin9x();
    void settingsFirWin9x();
    void clearWin9x();
    void showWin9x();
    void showTableProc();
    void setInfoForTableProc(PROCESSENTRY32W pr);
    void showTableThred(DWORD prid);
    void setInfoForTableThrd(THREADENTRY32 tr);
    void showTableMod(DWORD prid);
    void setInfoForTableMod(MODULEENTRY32W module);

    //Windows NT
    void showDrivers();
    void settingsWindowsNTFirst();
    void settingsWindowsNTLast();
    void clearWindowsNT();
    void showProcess();
    void showTreeModule(HANDLE processHandle);
    void showTreeModuleInfo(HANDLE processHandle, HMODULE h_module, QTreeWidgetItem *root);

    void showWindowsNT();

};

#endif // MAINWINDOW_H
