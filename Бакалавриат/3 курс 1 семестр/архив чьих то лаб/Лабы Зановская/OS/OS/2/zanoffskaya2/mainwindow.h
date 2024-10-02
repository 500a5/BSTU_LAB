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
#include <QDebug>
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
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_tableProc_itemClicked(QTableWidgetItem *item);

    void on_pushButton_4_clicked();
    void on_pushButton_13_clicked();
    void on_tableNTProc_itemClicked(QTableWidgetItem *item);
private:
    Ui::MainWindow *ui;
    void getByName(HMODULE &hm, QString name, QString &fullName);
    void getByHandle(HMODULE hm, QString &name, QString &fullName);
    void getByFullName(HMODULE &hm, QString &name, QString fullName);
    void getByEx(HMODULE &hm, QString &name, QString &fullName);
    void getCurrentInfo();

    void clearWin9x();

    void settingsFirWin9x();
    void showTableProc();
    void settingsFinWin9x();
    void setInfoForTableProc(PROCESSENTRY32W pr);
    void setInfoForTableMod(MODULEENTRY32W module);
    void showWin9x();

    void showTableMod(DWORD prid);

    void showTableThred(DWORD prid);
    void setInfoForTableThrd(THREADENTRY32 tr);
    void showDrivers();
    void settingsWindowsNTFirst();
    void settingsWindowsNTLast();
    void clearWindowsNT();
    void showProcess();
    void showWindowsNT();
    void showTreeModule(HANDLE processHandle);
    void showTreeModuleInfo(HANDLE processHandle, HMODULE h_module, QTreeWidgetItem *root);
};

#endif // MAINWINDOW_H
