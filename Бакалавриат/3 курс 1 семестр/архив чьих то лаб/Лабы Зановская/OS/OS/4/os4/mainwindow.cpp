#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QMessageBox>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showSystemInformation();
    procFullList();
    settingsOfTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::procArhToString(int n)
{
    switch (n) {
    case PROCESSOR_ARCHITECTURE_INTEL:
        return "x86";
    case PROCESSOR_ARCHITECTURE_MIPS:
        return "MIPSx64";
    case PROCESSOR_ARCHITECTURE_ALPHA:
        return "Alpha AXPx64";
    case PROCESSOR_ARCHITECTURE_PPC:
        return "PPC";
    case PROCESSOR_ARCHITECTURE_ARM:
        return "ARM";
    case PROCESSOR_ARCHITECTURE_IA64:
        return "Intel Itanium-based";
    case PROCESSOR_ARCHITECTURE_AMD64:
        return "AMDx64";
    case PROCESSOR_ARCHITECTURE_UNKNOWN:
        return "Неизвестно";
    default:
        return "Ошибка!";
    }
}

void MainWindow::procRevision(short r, int &mod, int &step)
{
    mod = (r >> 8);
    step = (r & 0x00FF);
}

bool MainWindow::getModuleFileNameEx(HANDLE hProcess, HMODULE hModule, QString &fname, QString &name)
{
    WCHAR buffer[MAX_PATH + 1];
    DWORD result = GetModuleFileNameEx(hProcess, hModule, buffer, MAX_PATH + 1);
    if (result != 0) {
        name = fname = QString::fromWCharArray(buffer);
        name.remove(0, name.lastIndexOf('\\') + 1);
        return true;
    }
    return false;
}

void MainWindow::procFullList()
{
    ui->comboBox_FullProc->addItem("0");
    QString name, fname;
    DWORD* processesId = new DWORD[255];
    DWORD bytes, size = 255 * sizeof(DWORD);
    if (EnumProcesses(processesId, size, &bytes)) {
        uint count = bytes / sizeof(DWORD);
        for (uint i = 0; i < count; i++) {
            HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE, false, (int) processesId[i]);
            if (getModuleFileNameEx(h, NULL, fname, name)) {
                    ui->comboBox_FullProc->addItem(name);
                }
            CloseHandle(h);
            }
    }
}

HANDLE MainWindow::getProcessHandleByName(QString &pName)
{
    QString name, fname;
    DWORD* processesId = new DWORD[255];
    DWORD bytes, size = 255 * sizeof(DWORD);
    if (EnumProcesses(processesId, size, &bytes)) {
        uint count = bytes / sizeof(DWORD);
        for (uint i = 0; i < count; i++) {
            HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE, false, (int) processesId[i]);
            if (getModuleFileNameEx(h, NULL, fname, name)) {
                if (name == pName)
                    return h;
            }
            CloseHandle(h);
        }
    }
    return NULL;
}


void MainWindow::showInfoOfSelectedProcess(QString nameProc)
{
    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->reset();
    settingsOfTable();
    ui->tableWidget->showColumn(0);

    /*
"Базовый адрес" << "Конечный адрес"
    << "Количество страниц" << "Размер области" << "Состояние памяти"
    << "Тип защиты" << "Тип области"
*/
    int numRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(numRow);

    int pageSize = 4096;
    HANDLE hProcess = getProcessHandleByName(nameProc);
    if (hProcess != 0) {
            int initAddress = 0;
            int numRow = 0;
            MEMORY_BASIC_INFORMATION memInfo;
            while (VirtualQueryEx(hProcess, (void*) initAddress, &memInfo, sizeof(memInfo))) {
                ui->tableWidget->insertRow(numRow);
                QTableWidgetItem* baseAddressItem = new QTableWidgetItem(QString("%1").arg((long) memInfo.BaseAddress, 0, 16));
                ui->tableWidget->setItem(numRow, 0, baseAddressItem);
                initAddress += memInfo.RegionSize;
                QTableWidgetItem* finalAddressItem = new QTableWidgetItem(QString("%1").arg(initAddress - 1, 0, 16));
                ui->tableWidget->setItem(numRow, 1, finalAddressItem);
                ui->tableWidget->setItem(numRow, 2, new QTableWidgetItem(QString::number(memInfo.RegionSize/pageSize))); //количество страниц
                ui->tableWidget->setItem(numRow, 3, new QTableWidgetItem(stateToQstring(memInfo.State)));
                if (memInfo.State != MEM_FREE) {
                    ui->tableWidget->setItem(numRow, 5, new QTableWidgetItem(protectToString(memInfo.Protect)));
                    ui->tableWidget->setItem(numRow, 6, new QTableWidgetItem(typeToQString(memInfo.Type)));
                }
                numRow++;
            }
            ui->tableWidget->resizeColumnsToContents();
            CloseHandle(hProcess);
        }


    //ui->tableWidget->setItem(numRow, 0, new QTableWidgetItem(""));
}

void MainWindow::settingsOfTable()
{
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
    << "Базовый адрес" << "Конечный адрес"
    << "Количество страниц" << "Размер области" << "Состояние памяти"
    << "Тип защиты" << "Тип области");
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->hideColumn(4);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void MainWindow::showSystemInformation()
{
    int mod, step;
    _SYSTEM_INFO sysinf;
    GetSystemInfo(&sysinf);
    procRevision(sysinf.wProcessorRevision, mod, step);
    ui->lineEdit_ArhProc->setText(procArhToString(sysinf.wProcessorArchitecture));
    ui->lineEdit_LvlProc->setText(QString::number(sysinf.wProcessorLevel));
    ui->lineEdit_KolProc->setText(QString::number(sysinf.dwNumberOfProcessors));
    ui->lineEdit_RedProc->setText(QString("Модель %1, шаг: %2").arg(mod).arg(step));
    ui->lineEdit_SizePage->setText(QString::number(sysinf.dwPageSize));
    ui->lineEdit_DownAdr->setText(QString("%1").arg((long)sysinf.lpMinimumApplicationAddress, 0, 16).toUpper());
    ui->lineEdit_UpAdr->setText(QString("%1").arg((long)sysinf.lpMaximumApplicationAddress, 0, 16).toUpper());
    ui->lineEdit_MaskProc->setText(QString("%1").arg(sysinf.dwActiveProcessorMask, 32, 2, QChar('0')));
    ui->lineEdit_Granul->setText(QString::number(sysinf.dwAllocationGranularity));
}

void MainWindow::on_comboBox_FullProc_currentTextChanged(const QString &arg1)
{
    if(arg1 != "0")
        showInfoOfSelectedProcess(arg1);
}

QString MainWindow::stateToQstring(int state)
{
    switch (state) {
    case MEM_COMMIT: return "Передано";
    case MEM_RESERVE: return "Зарезервировано";
    case MEM_FREE: return "Свободно";
    }
}

QString MainWindow::typeToQString(int type)
{
    switch (type) {
    case MEM_IMAGE: return "Загрузочный";
    case MEM_MAPPED: return "Файл данных";
    case MEM_PRIVATE: return "Приватный";
    }
}

QString MainWindow::protectToString(DWORD protect)
{
    QString str;
    if (protect & PAGE_EXECUTE_READWRITE) {
        str += "Исполнение/чтение/запись";
    }
    else if (protect & PAGE_READONLY) {
        str += "Только чтение";
    }
    else if (protect & PAGE_READWRITE) {
        str += "Чтение/запись";
    }
    else if (protect & PAGE_EXECUTE_WRITECOPY) {
        str += "Исполнение/запись копирование";
    }
    else if (protect & PAGE_EXECUTE_READ) {
        str += "Исполнение/чтение";
    }
    else if (protect & PAGE_EXECUTE) {
        str += "Исполнение";
    }
    else if (protect & PAGE_NOACCESS) {
        str += "Нет доступа";
    }
    else if (protect & PAGE_WRITECOPY) {
        str += "Запись копированием";
    }
    if (protect & PAGE_GUARD) {
        str += "|Защищенный";
    }
    if (protect & PAGE_NOCACHE) {
        str += "|Запрет кэширования";
    }

    if (str.length() == 0) {
        return QString::number(protect);
    }
    return str;
}

