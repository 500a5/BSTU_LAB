#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <locale>
#include <string.h>
#include <string>
#include <tchar.h>

using namespace std;
#ifdef _UNICODE
#define _tcout wcout
#else
#define _tcout cout
#endif // _UNICODE

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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void volumeInformation(int i, HANDLE h, DWORD &size, OVERLAPPED ovl);
    void driveType(string s, HANDLE h, DWORD &size, OVERLAPPED ovl);
    int logicalDrivers(char* fileName);
    LPWSTR ConvertToLPWSTR(const std::string& s);
    int createKey(char *s);
    ofstream outputInfo(char* fileName);
    string  toHex(DWORD a);
    int numRow;
    string dwordToString (DWORD n);

};

#endif // MAINWINDOW_H
