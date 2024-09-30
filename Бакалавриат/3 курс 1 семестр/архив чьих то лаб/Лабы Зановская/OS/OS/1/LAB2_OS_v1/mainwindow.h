#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <windows.h>
#include <psapi.h>
#include <QTreeWidget>
#include <QTableWidget>
#include <tlhelp32.h>
#include "blockcells.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool getModuleFileName(HMODULE hModule, QString& fname, QString& name);
    bool getModuleFileNameEx(HANDLE hProcess, HMODULE hModule, QString& fname, QString& name);
    bool getModuleName(HANDLE hProcess, HMODULE hModule, QString& name);
private:
    Ui::MainWindow *ui;
    bool getInfoByName(HMODULE& hModule, QString& fname, QString name);
    bool getInfoByFName(HMODULE& hModule, QString fname, QString& name);
    bool getInfoByHandle(HMODULE hModule, QString& fname, QString& name);
    void setCurrentProcessInfo();
    void showProcessInfo(HANDLE hProcess, QTreeWidgetItem* root);
    void showModuleInfo(HANDLE hProcess, HMODULE hModule, QTreeWidgetItem* root);
    void setProcessesTreeInfo();
    void setDriversInfo();
    void setProcessesInfo();
    void setModulesInfo(DWORD pId);
    void setThreadsInfo(DWORD pId);
private slots:
    void handle_LineEdit_changed();
    void name_LineEdit_changed();
    void fname_LineEdit_changed();
    void on_get_Button_clicked();
    void on_clear_Button_clicked();
    void on_processes_Table_itemClicked(QTableWidgetItem *item);
};

#endif // MAINWINDOW_H
