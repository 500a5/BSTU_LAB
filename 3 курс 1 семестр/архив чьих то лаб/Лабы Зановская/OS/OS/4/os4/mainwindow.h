#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>


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
    void on_comboBox_FullProc_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    //HANDLE hProcess;
    //int idProcess;
    //int pageSize = 4096;

    //1 задание==============================================
    QString procArhToString(int n);
    void procRevision(short r, int &mod, int &step);
    void showSystemInformation();

    //3 задание==============================================
    void settingsOfTable();
    HANDLE getProcessHandleByName(QString& pName);
    bool getModuleFileNameEx(HANDLE hProcess, HMODULE hModule, QString &fname, QString &name);
    void procFullList();

    void showInfoOfSelectedProcess(QString nameProc);
    void showInfoWithoutModules();

    QString stateToQstring(int state);
    QString typeToQString(int type);
    QString protectToString(DWORD protect);


    //void showInfoOfSelectedProcess();
    //void showModuleInfo(HMODULE hModule);
    //QString getModuleName(HMODULE hModule);
};

#endif // MAINWINDOW_H
