#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->processes_Table->setColumnCount(5);
    ui->modules_Table->setColumnCount(4);
    ui->threads_Table->setColumnCount(2);
    ui->modules_Table->setHorizontalHeaderLabels({"Имя модуля","Дескриптор модуля","Размер","Путь"});
    ui->threads_Table->setHorizontalHeaderLabels({"ID потока","Приоритет потока"});
    ui->processes_Table->setHorizontalHeaderLabels({"Имя процесса","ID процесса","Родительский ID","Приоритет процесса","Количество потоков"});
    setCurrentProcessInfo();
    setProcessesTreeInfo();
    setDriversInfo();
    setProcessesInfo();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getModuleName(HANDLE hProcess, HMODULE hModule, QString &name)
{
    WCHAR buffer[MAX_PATH + 1];
    SecureZeroMemory(buffer, MAX_PATH + 1);
    DWORD result = GetModuleBaseNameW(hProcess, hModule, buffer, MAX_PATH + 1);
    if (result != 0) {
        name = QString::fromWCharArray(buffer);
        return true;
    }
    return false;
}

bool MainWindow::getModuleFileName(HMODULE hModule, QString &fname, QString &name)
{
    WCHAR buffer[MAX_PATH + 1];
    SecureZeroMemory(buffer, MAX_PATH + 1);
    DWORD result = GetModuleFileName(hModule, buffer, MAX_PATH + 1);
    if (result != 0) {
        name = fname = QString::fromWCharArray(buffer);
        name.remove(0, name.lastIndexOf('\\') + 1);
        return true;
    }
    return false;
}

bool MainWindow::getModuleFileNameEx(HANDLE hProcess, HMODULE hModule, QString &fname, QString &name)
{
    WCHAR buffer[MAX_PATH + 1];
    SecureZeroMemory(buffer, MAX_PATH + 1);
    DWORD result = GetModuleFileNameEx(hProcess, hModule, buffer, MAX_PATH + 1);
    if (result != 0) {
        name = fname = QString::fromWCharArray(buffer);
        name.remove(0, name.lastIndexOf('\\') + 1);
        return true;
    }
    return false;
}

bool MainWindow::getInfoByHandle(HMODULE hModule, QString &fname, QString &name)
{
    return getModuleFileName(hModule, fname, name);
}

bool MainWindow::getInfoByName(HMODULE &hModule, QString &fname, QString name)
{
    WCHAR buffer[MAX_PATH];
    int size = name.toWCharArray(buffer);
    buffer[size] = '\0';
    hModule = GetModuleHandle(buffer);
    if (hModule != NULL) {
        getModuleFileName(hModule, fname, name);
        return true;
    }
    return false;
}

bool MainWindow::getInfoByFName(HMODULE &hModule, QString fname, QString &name)
{
    name = fname;
    name.remove(0, name.lastIndexOf('\\') + 1);
    getInfoByName(hModule, fname, name);
}
void MainWindow:: showInfo(HMODULE hModule, QString fname, QString name)
{
    ui->fname_LineEdit->setText(fname);
    ui->name_LineEdit->setText(name);
    ui->handle_LineEdit->setText(QString("0x%1").arg((int)hModule, 0, 16));
}

void MainWindow::on_get_Button_clicked()
{
    QString name, fname;
    HMODULE hModule;
    if (ui->radioButton->isChecked())
    {
        getModuleFileName(NULL, fname, name);
        showInfo(GetModuleHandle(NULL),fname, name);
    }
    if(ui->radioButton_2->isChecked())
    {
        hModule=(HMODULE)ui->lineEdit->text().toInt(0, 0);
        if (getInfoByHandle(hModule, fname, name)) {
           showInfo(hModule, fname, name);
        }
        else {
            QMessageBox::warning(this, "Ошибка!", "Некорректный дескриптор.");
            on_clear_Button_clicked();
        }
    }
    if(ui->radioButton_3->isChecked())
    {
        name= ui->lineEdit->text();
        if (getInfoByName(hModule, fname,name)) {
            showInfo(hModule, fname, name);
        }
        else {
            QMessageBox::warning(this, "Ошибка!", "Некорректный дескриптор.");
            on_clear_Button_clicked();
       }
    }
    if(ui->radioButton_4->isChecked())
    {
        fname= ui->lineEdit->text();
        if (getInfoByFName(hModule, fname, name)) {
                showInfo(hModule, fname, name);
        }
        else {
                QMessageBox::warning(this, "Ошибка!", "Некорректный дескриптор.");
                on_clear_Button_clicked();
       }
    }
}

void MainWindow::on_clear_Button_clicked()
{
    ui->handle_LineEdit->clear();
    ui->name_LineEdit->clear();
    ui->fname_LineEdit->clear();
    ui->lineEdit->clear();
}

void MainWindow::setCurrentProcessInfo()
{
    DWORD pId = GetCurrentProcessId();
    ui->id_Line->setText(QString::number((int) pId));
    HANDLE pPseudoHandle = GetCurrentProcess();
    ui->pseudoid_Line->setText(QString::number((int) pPseudoHandle));
    HANDLE pCopyHandle;
    DuplicateHandle(pPseudoHandle, pPseudoHandle, pPseudoHandle, &pCopyHandle, PROCESS_ALL_ACCESS, false, 0);
    ui->copy_handle_Line->setText(QString::number((int) pCopyHandle));
    HANDLE pOpen = OpenProcess(PROCESS_ALL_ACCESS, false, pId);
    ui->open_handle_Line->setText(QString::number((int) pOpen));
    CloseHandle(pOpen);
    ui->close_open_handle_Line->setText(QString::number((int) pOpen));
    CloseHandle(pCopyHandle);
    ui->close_copy_handle_Line->setText(QString::number((int) pCopyHandle));
}

void MainWindow::setProcessesTreeInfo()
{
    QString name, fname;
    ui->processes_TreeWidget->setHeaderLabels({"Процессы"});
    DWORD* processesId = new DWORD[255];
    DWORD bytes, size = 255 * sizeof(DWORD);
    if (EnumProcesses(processesId, size, &bytes)) {
        uint count = bytes / sizeof(DWORD);
        for (uint i = 0; i < count; i++) {
            HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE, false, (int) processesId[i]);
            if (getModuleFileNameEx(h, NULL, fname, name)) {
                QTreeWidgetItem* node = new QTreeWidgetItem(ui->processes_TreeWidget);
                node->setText(0, name);
                showProcessInfo(h, node);
            }
            CloseHandle(h);
        }
    }
    else {
        QMessageBox::warning(this, "Ошибка!", "Ошибка вывода процессов.");
    }
}

void MainWindow::showProcessInfo(HANDLE hProcess, QTreeWidgetItem* root)
{
    QString name;
    HMODULE modules[255];
    DWORD bytes;
    if (EnumProcessModules(hProcess, modules, sizeof(HMODULE) * 255, &bytes)) {
        uint count = bytes / sizeof(HMODULE);
        for (uint i = 0; i < count; i++) {
            if (getModuleName(hProcess, modules[i], name)) {
                QTreeWidgetItem* node = new QTreeWidgetItem(root);
                node->setText(0, name);
                showModuleInfo(hProcess, modules[i], node);
            }
        }
    }
}

void MainWindow::showModuleInfo(HANDLE hProcess, HMODULE hModule, QTreeWidgetItem *root)
{
    QString name, fname;
    MODULEINFO mInfo;
    QTreeWidgetItem* hModuleNode = new QTreeWidgetItem(root);
    hModuleNode->setText(0, "Дескриптор модуля: " + QString("0x%1").arg((int)hModule, 0, 16));
    QTreeWidgetItem* hHandleNode = new QTreeWidgetItem(root);
    hHandleNode->setText(0, "Идентификатор процесса: " + QString::number((int)hProcess));
    if (GetModuleInformation(hProcess, hModule, &mInfo, sizeof(mInfo))) {
        QTreeWidgetItem* mSize = new QTreeWidgetItem(root);
        mSize->setText(0, "Размер занимаемый модулем: " + QString::number(mInfo.SizeOfImage / 1024) + "kB");
        QTreeWidgetItem* mBase = new QTreeWidgetItem(root);
        if (getModuleFileName((HMODULE)mInfo.lpBaseOfDll, fname, name)) {
            mBase->setText(0, "Адрес загрузки модуля: " + fname + " (" + QString("0x%1").arg((int)mInfo.lpBaseOfDll, 0, 16) + ")");
        }
        else {
            mBase->setText(0, "Адрес загрузки модуля: " + QString("0x%1").arg((int)mInfo.lpBaseOfDll, 0, 16));
        }
        QTreeWidgetItem* mEntry = new QTreeWidgetItem(root);
        if (getModuleFileName((HMODULE)mInfo.EntryPoint, fname, name)) {
            mEntry->setText(0, "Точка входа модуля: " + fname + " (" + QString("0x%1").arg((int)mInfo.EntryPoint, 0, 16) + ")");
        }
        else {
            mEntry->setText(0, "Точка входа модуля: " + QString("0x%1").arg((int)mInfo.EntryPoint, 0, 16));
        }
    }
}

void MainWindow::setDriversInfo()
{
    LPVOID drivers[1024];
    DWORD cbNeeded;
    if (EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded) && cbNeeded < sizeof(drivers)) {
         TCHAR szDriver[1024];
         uint cDrivers = cbNeeded/sizeof(drivers[0]);
         for(uint i = 0; i < cDrivers; i++) {
            if (GetDeviceDriverBaseName(drivers[i], szDriver, sizeof(szDriver)/sizeof(szDriver[0]))) {
               ui->drivers_List->addItem(QString::fromWCharArray(szDriver));
            }
         }
    }
}

void MainWindow::setProcessesInfo()
{
    HANDLE hProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pEntry32;
    if(hProcessSnapshot == INVALID_HANDLE_VALUE) {
        QMessageBox::warning(this, "Ошибка", "Ошибка получения моментального cнимка (Windows 9X)");
        CloseHandle(hProcessSnapshot);
        return;
    }
    pEntry32.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hProcessSnapshot, &pEntry32) == false) {
        QMessageBox::warning(this, "Ошибка", "Ошибка получения ProcessFirst (Windows 9X)");
        CloseHandle(hProcessSnapshot);
        return;
    }
    do {
        ui->processes_Table->insertRow(ui->processes_Table->rowCount());
        ui->processes_Table->setItem(ui->processes_Table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromWCharArray(pEntry32.szExeFile)));
        ui->processes_Table->setItem(ui->processes_Table->rowCount() - 1, 1, new QTableWidgetItem(QString::number((int)pEntry32.th32ProcessID)));
        ui->processes_Table->setItem(ui->processes_Table->rowCount() - 1, 2, new QTableWidgetItem(QString::number((int)pEntry32.th32ParentProcessID)));
        ui->processes_Table->setItem(ui->processes_Table->rowCount() - 1, 3, new QTableWidgetItem(QString::number((int)pEntry32.pcPriClassBase)));
        ui->processes_Table->setItem(ui->processes_Table->rowCount() - 1, 4, new QTableWidgetItem(QString::number((int)pEntry32.cntThreads)));
    } while (Process32Next(hProcessSnapshot, &pEntry32));
    CloseHandle(hProcessSnapshot);
    ui->processes_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->processes_Table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_processes_Table_itemClicked(QTableWidgetItem *item)
{
    if (item->column() == 1 || item->column() == 2) {
        ui->modules_Table->clear();
        ui->modules_Table->setRowCount(0);
        ui->threads_Table->clear();
        ui->threads_Table->setRowCount(0);
        ui->modules_Table->setHorizontalHeaderLabels({"Имя модуля","Дескриптор модуля","Размер","Путь"});
        ui->threads_Table->setHorizontalHeaderLabels({"ID потока","Приоритет потока"});
        QString number = item->text();
        number.remove(0, number.lastIndexOf(' ') + 1);
        DWORD pId = number.toUInt();
        setModulesInfo(pId);
        setThreadsInfo(pId);
    }
}

void MainWindow::setModulesInfo(DWORD pId)
{
    HANDLE hModuleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pId);
    MODULEENTRY32 mEntry32;
    if (hModuleSnapshot == INVALID_HANDLE_VALUE) {
        //QMessageBox::warning(this, "Ошибка", "Ошибка получения снапшота модулей для данного процесса(Windows 9X)");
        CloseHandle(hModuleSnapshot);
        return;
    }
    mEntry32.dwSize = sizeof(MODULEENTRY32);
    if (Module32First(hModuleSnapshot, &mEntry32) == false) {
        //QMessageBox::warning(this, "Ошибка", "Ошибка доступа к ModuleFirst (Windows 9X)");
        CloseHandle(hModuleSnapshot);
        return;
    }
    do {
        ui->modules_Table->insertRow(ui->modules_Table->rowCount());
        ui->modules_Table->setItem(ui->modules_Table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromWCharArray(mEntry32.szModule)));
        ui->modules_Table->setItem(ui->modules_Table->rowCount() - 1, 1, new QTableWidgetItem(QString("0x%1").arg((int)mEntry32.hModule, 0, 16)));
        ui->modules_Table->setItem(ui->modules_Table->rowCount() - 1, 2, new QTableWidgetItem(QString::number((int)mEntry32.modBaseSize/1024) + "kB"));
        ui->modules_Table->setItem(ui->modules_Table->rowCount() - 1, 3, new QTableWidgetItem(QString::fromWCharArray(mEntry32.szExePath)));
    } while (Module32Next(hModuleSnapshot, &mEntry32));
    CloseHandle(hModuleSnapshot);
    ui->modules_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->modules_Table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::setThreadsInfo(DWORD pId)
{
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    THREADENTRY32 tEntry32;
    if (hThreadSnapshot == INVALID_HANDLE_VALUE) {
        //QMessageBox::warning(this, "Ошибка", "Ошибка получения снапшота потоков для данного процесса(Windows 9X)");
        CloseHandle(hThreadSnapshot);
        return;
    }
    tEntry32.dwSize = sizeof(THREADENTRY32);
    if (Thread32First(hThreadSnapshot, &tEntry32) == false) {
        //QMessageBox::warning(this, "Ошибка", "Ошибка доступа к ThreadFirst (Windows 9X)");
        CloseHandle(hThreadSnapshot);
        return;
    }
    do {
        if (tEntry32.th32OwnerProcessID == pId) {
            ui->threads_Table->insertRow(ui->threads_Table->rowCount());
            ui->threads_Table->setItem(ui->threads_Table->rowCount() - 1, 0, new QTableWidgetItem(QString::number(tEntry32.th32ThreadID, 16)));
            ui->threads_Table->setItem(ui->threads_Table->rowCount() - 1, 1, new QTableWidgetItem(QString::number(tEntry32.tpBasePri)));
        }
    } while (Thread32Next(hThreadSnapshot, &tEntry32));
    CloseHandle(hThreadSnapshot);
    ui->threads_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->threads_Table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_pushButton_clicked()
{
    ui->processes_TreeWidget->clear();
    setProcessesTreeInfo();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->drivers_List->clear();
    setDriversInfo();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->processes_Table->clear();
    ui->processes_Table->setRowCount(0);
    ui->modules_Table->clear();
    ui->modules_Table->setRowCount(0);
    ui->threads_Table->clear();
    ui->threads_Table->setRowCount(0);
    ui->modules_Table->setHorizontalHeaderLabels({"Имя модуля","Дескриптор модуля","Размер","Путь"});
    ui->threads_Table->setHorizontalHeaderLabels({"ID потока","Приоритет потока"});
    ui->processes_Table->setHorizontalHeaderLabels({"Имя процесса","ID процесса","Родительский ID","Приоритет процесса","Количество потоков"});
    setProcessesInfo();
}
