#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showCurrentInfo();
    showWin9x();
    showDrivers();
   // showProcess();
    showWindowsNT();
}

//Discord.exe 20774912
//osqt2.exe  4194304

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineFullName->clear();
    ui->lineHandle->clear();
    ui->lineInput->clear();
    ui->lineName->clear();
}

void MainWindow::on_pushButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        showFullInfoExe();
        break;
    case 1:
        showInfoByName();
        //showLittleNameInfo();
        break;
    case 2:
        //showInfoByFullName();
        showProcInfo();
        break;
    case 3:
        showInfoByHandle();
        //showHandleInfo();
        break;
    }

}

void MainWindow::showInfo(HMODULE hmod, QString name, QString fullname)
{
    ui->lineFullName->setText(fullname);
    ui->lineName->setText(name);
    ui->lineHandle->setText(QString("0x%1").arg((int)hmod, 0, 16));
}

bool MainWindow::getInfoByHandle(HMODULE hmodule, QString& name, QString& moduleName)
{
    WCHAR p_name[255];
    int cur_size = GetModuleFileName(hmodule, p_name, 255);
    if (cur_size != 0) {
        p_name[cur_size + 1] = 0;
        moduleName = QString::fromWCharArray(p_name);
        name = moduleName;
        name.remove(0, name.lastIndexOf("\\") + 1);
        return true;
    }
    return false;
}

void MainWindow::showInfoByHandle()
{
    HMODULE h = (HMODULE)(ui->lineInput->text().toInt(0, 0));
    QString name, moduleName;
    if (getInfoByHandle(h, name, moduleName)) {
        showInfo(h, name, moduleName);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Недоступный дескриптор");
        ui->lineInput->clear();
    }
}

bool MainWindow::getInfoByName(HMODULE& hmodule, QString name, QString &moduleName)
{
    WCHAR wname[255];
    int size = name.toWCharArray(wname);
    wname[size] = 0;
    hmodule = GetModuleHandle(wname);
    if (hmodule != NULL) {
        WCHAR p_name[255];
        int cur_size = GetModuleFileName(hmodule, p_name, 255);
        p_name[cur_size + 1] = 0;
        moduleName = QString::fromWCharArray(p_name);
        return true;
    }
    return false;
}

void MainWindow::showInfoByName()
{
    QString name = ui->lineInput->text();
    QString moduleName;
    HMODULE h;
    if (getInfoByName(h, name, moduleName)) {
        showInfo(h, name, moduleName);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Недоступное имя модуля");
        ui->lineInput->clear();
    }
}

bool MainWindow::getInfoByFullName(HMODULE &hmodule, QString& name, QString moduleName)
{
    name = moduleName;
    name.remove(0, name.lastIndexOf("\\") + 1);
    WCHAR wname[255];
    int size = name.toWCharArray(wname);
    wname[size] = 0;
    hmodule = GetModuleHandle(wname);
    if (hmodule == NULL) {
        return false;
    }
    return true;
}

void MainWindow::showInfoByFullName()
{
    QString name;
    QString moduleName = ui->lineInput->text();
    HMODULE h;
    if (getInfoByFullName(h, name, moduleName)) {
        showInfo(h, name, moduleName);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Недоступный путь к модулю");
        ui->lineInput->clear();
    }
}

bool MainWindow::getFullInfoExe(QString &name, QString &moduleName, HMODULE &hmodule)
{
    hmodule = GetModuleHandle(NULL);
    return getInfoByHandle(hmodule, name, moduleName);
}

void MainWindow::showFullInfoExe()
{
    QString name;
    QString moduleName;
    HMODULE h;
    getFullInfoExe(name, moduleName, h);
    showInfo(h, name, moduleName);
}

//По полному имени файла записывает в fileNameEdit имя файла, а в handleNameEdi - его дескрпитор
// c:/lfkalsfka/sdfkasldf/asodfkas/1.exe
// 285729475
//1.exe
void MainWindow::showProcInfo()
{
    QString string = ui->lineInput->text();
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hProcess, &process)) {
            do {
                DWORD procId = process.th32ProcessID;
                HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);
                MODULEENTRY32 gege;
                gege.dwSize = sizeof(MODULEENTRY32);
                Module32First(hSnap, &gege);
                if (Module32First(hSnap, &gege)) {
                    do {
                        if (QString::fromWCharArray(gege.szExePath) == string) {
                            QString s = QString("0x%1").arg((int)gege.hModule);
                            ui->lineHandle->setText(s);
                            //ui->fileNameEdit->setText(QString::fromWCharArray(gege.szModule));
                            //ui->handleNameEdit->setText(s);
                            ui->lineName->setText(QString::fromWCharArray(gege.szModule));

                            ui->lineFullName->setText(ui->lineInput->text());
                            break;
                        }
                    } while (Module32Next(hSnap, &gege));
                }
                CloseHandle(hSnap);
            } while (Process32Next(hProcess, &process));
        }
    CloseHandle(hProcess);
}

//По дескрпитору записывает в fullFileName полное имя файла, а в fileName - его краткое имя
void MainWindow::showHandleInfo()
{
    QString string = ui->lineInput->text();
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hProcess, &process)) {
            do {
                DWORD procId = process.th32ProcessID;
                HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);
                MODULEENTRY32 gege;
                gege.dwSize = sizeof(MODULEENTRY32);
                Module32First(hSnap, &gege);
                if (Module32First(hSnap, &gege)) {
                    do {
                        if (QString("0x%1").arg((int)gege.hModule) == string) {
                            //ui->fullFileNameEdit->setText(QString::fromWCharArray(gege.szExePath));
                            //ui->fileNameEdit->setText(QString::fromWCharArray(gege.szModule));
                            ui->lineFullName->setText(QString::fromWCharArray(gege.szExePath));
                            ui->lineName->setText(QString::fromWCharArray(gege.szModule));
                            ui->lineHandle->setText(string);
                            break;
                        }
                    } while (Module32Next(hSnap, &gege));
                }
                CloseHandle(hSnap);
            } while (Process32Next(hProcess, &process));
        }
        CloseHandle(hProcess);
}


//По краткому имени записывает в handleNameEdit дескриптор файла, а в fullNameEdit - его полное имя
void MainWindow::showLittleNameInfo()
{
    QString string = ui->lineInput->text();
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hProcess, &process)) {
            do {
                DWORD procId = process.th32ProcessID;
                HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);
                MODULEENTRY32 gege;
                gege.dwSize = sizeof(MODULEENTRY32);
                Module32First(hSnap, &gege);
                if (Module32First(hSnap, &gege)) {
                    do {
                        if (QString::fromWCharArray(gege.szModule) == string) {
                            ui->lineFullName->setText(QString::fromWCharArray(gege.szExePath));
                            QString s = QString("0x%1").arg((int)gege.hModule);
                            ui->lineHandle->setText(s);
                            ui->lineName->setText(string);
                            break;
                        }
                    } while (Module32Next(hSnap, &gege));
                }
                CloseHandle(hSnap);
            } while (Process32Next(hProcess, &process));
        }
        CloseHandle(hProcess);
}



void MainWindow::showCurrentInfo()
{
    //Идентификатор текущего процесса
    DWORD cpid = GetCurrentProcessId();
    ui->currIDEdit->setText(QString::number(cpid));

    //Псевдодескрпитор текущего процесса
    HANDLE cp = GetCurrentProcess();
    ui->currPseudoEdit->setText(QString("%1").arg((int)cp));

    //Дупликат
    HANDLE copy;
    DuplicateHandle(cp, cp, cp, &copy, PROCESS_ALL_ACCESS, false, 0);
    ui->currHandleDupEdit->setText(QString("%1").arg((int)copy));

    //OpenProc
    HANDLE op = OpenProcess(PROCESS_ALL_ACCESS, false, cpid);
    ui->currHandleOpenEdit->setText(QString("%1").arg((int)op));

    //Закрытие дупликата
    bool fd = CloseHandle(copy);
    ui->currCloseDupEdit->setText(QString("%1").arg((int)copy));

    //Закрытие open
    bool fo = CloseHandle(op);
    ui->currCloseOpenEdit->setText(QString("%1").arg((int)op));
}

void MainWindow::settingsFinWin9x()
{
    ui->tableProc->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableProc->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableThrd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableThrd->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableMod->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMod->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::settingsFirWin9x()
{
    QStringList head;
    head << "Имя проц." << "ID" << "Кол-во потоков" << "Род. проц." << "Приор.";
    ui->tableProc->setColumnCount(5);
    ui->tableProc->setHorizontalHeaderLabels(head);
    head.clear();

    head << "Имя модуля" << "Дескриптор" << "Размер" << "Путь";
    ui->tableMod->setColumnCount(4);
    ui->tableMod->setHorizontalHeaderLabels(head);
    head.clear();

    head << "ID потока" << "Приор.";
    ui->tableThrd->setColumnCount(2);
    ui->tableThrd->setHorizontalHeaderLabels(head);
}

void MainWindow::clearWin9x()
{
     ui->tableMod->clear();
     ui->tableMod->clearContents();
     ui->tableMod->setRowCount(0);
     ui->tableMod->clear();
     ui->tableThrd->clear();
     ui->tableThrd->clearContents();
     ui->tableThrd->setRowCount(0);
     ui->tableThrd->clear();
     ui->tableProc->clear();
     ui->tableProc->clearContents();
     ui->tableProc->setRowCount(0);
     ui->tableProc->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    showWin9x();
}

void MainWindow::showWin9x()
{
    clearWin9x();
    settingsFirWin9x();
    showTableProc();
    settingsFinWin9x();
}

void MainWindow::showTableProc()
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if ((int)snap == -1){
        QMessageBox::warning(this, "Ошибка!", "Не удалось сделать снимок процессов системы!");
        clearWin9x();
    }
    PROCESSENTRY32W proc;
    proc.dwSize = sizeof(PROCESSENTRY32W);
    bool flag;
    if (Process32FirstW(snap, &proc)){
        flag = true;
        while(flag){
            setInfoForTableProc(proc);
            flag = Process32NextW(snap, &proc);
        }
    }
    CloseHandle(snap);
}

void MainWindow::setInfoForTableProc(PROCESSENTRY32W pr)
{
    int i = ui->tableProc->rowCount();
    ui->tableProc->insertRow(i);
    ui->tableProc->setItem(i-1, 0, new QTableWidgetItem(QString::fromWCharArray(pr.szExeFile)));
    ui->tableProc->setItem(i-1, 1, new QTableWidgetItem(QString::number(pr.th32ProcessID)));
    ui->tableProc->setItem(i-1, 2, new QTableWidgetItem(QString::number(pr.cntThreads)));
    ui->tableProc->setItem(i-1, 3, new QTableWidgetItem(QString::number(pr.th32ParentProcessID)));
    int prior = (int)pr.pcPriClassBase;
    if (prior >=1 && prior <=4)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - простаивающий"));
    if (prior >=5 && prior <=6)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - ниже обычного"));
    if (prior >=7 && prior <=8)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - обычный"));
    if (prior >=9 && prior <=10)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - выше обычного"));
    if (prior >=11 && prior <=14)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - высокий"));
    if (prior >=15 && prior <=16)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - простаивающий реального времени"));
    if (prior >=17 && prior <=30)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - реального времени"));
    if (prior >=1 && prior <=5)
        ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)+" - критичный реального времени"));
}

void MainWindow::showTableThred(DWORD prid)
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, prid);
    if ((int)snap == -1){
        QMessageBox::warning(this, "Ошибка!", "Не удалось сделать снимок потоков системы!");
        clearWin9x();
    }
    THREADENTRY32 thrd;
    thrd.dwSize = sizeof(THREADENTRY32);
    bool flag;
    if (Thread32First(snap, &thrd)){
        flag = true;
        while (flag){
            setInfoForTableThrd(thrd);
            flag = Thread32Next(snap, &thrd);
        }
    }
    CloseHandle(snap);
}

void MainWindow::setInfoForTableThrd(THREADENTRY32 tr)
{
    int i = ui->tableThrd->rowCount();
    ui->tableThrd->insertRow(i);
    ui->tableThrd->setItem(i-1, 0, new QTableWidgetItem(QString::number(tr.th32ThreadID)));
    int prior = (int)tr.tpBasePri;
    switch (prior) {
    case -15:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - простаивающий"));
        break;
    case -2:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - самый низкий"));
        break;
    case -1:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - ниже обычного"));
        break;
    case 0:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - обычный"));
        break;
    case 1:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - выше обычного"));
        break;
    case 2:        ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - самый высокий"));
        break;
    default:         ui->tableThrd->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)+" - критичный по времени"));
        break;
    }
}

void MainWindow::showTableMod(DWORD prid)
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, prid);
    if ((int)snap == -1){
        QMessageBox::warning(this, "Предупреждение!", "Доступ к модулям запрещен!");
    }
    MODULEENTRY32W mod;
    mod.dwSize = sizeof(MODULEENTRY32W);
    bool flag;
    if (Module32FirstW(snap, &mod)){
        flag = true;
        while (flag){
            setInfoForTableMod(mod);
            flag = Module32NextW(snap, &mod);
        }
    }
    CloseHandle(snap);
}

void MainWindow::setInfoForTableMod(MODULEENTRY32W module)
{
    int i = ui->tableMod->rowCount();
    ui->tableMod->insertRow(i);
    ui->tableMod->setItem(i-1, 0, new QTableWidgetItem(QString::fromWCharArray(module.szModule)));
    ui->tableMod->setItem(i-1, 1, new QTableWidgetItem(QString("%1").arg((int)module.hModule)));
    ui->tableMod->setItem(i-1, 2, new QTableWidgetItem(QString::number(module.modBaseSize)));
    ui->tableMod->setItem(i-1, 3, new QTableWidgetItem(QString::fromWCharArray(module.szExePath)));
}

void MainWindow::on_tableProc_itemClicked(QTableWidgetItem *item)
{
    if (item->column() == 1){
        showTableThred(item->text().toInt());
        showTableMod(item->text().toInt());
    }
}

void MainWindow::showDrivers()
{
    LPVOID driv[255];           //указатель на массив элементов DWORDa, получит id дров
    DWORD cb = sizeof(driv);    //кол-во элементов типа DWORD
    DWORD cbn;                  //кол-во байтов, скопированных в массив, на которые указывает первый параметр.
    bool flag = EnumDeviceDrivers(driv, cb, &cbn);
    if (flag){
       int max = cbn/sizeof(DWORD); //число элементов в массиве (всего дров)
       for(int i = 0; i < max; i++){
           WCHAR name[255], path[255];
           DWORD bufsizep = sizeof(path);
           DWORD bufsizen = sizeof(path);
           GetDeviceDriverFileName(driv[i], path, bufsizep);
           GetDeviceDriverBaseName(driv[i], name, bufsizen);
           ui->listDriv->addItem(QString::fromWCharArray(name));
           ui->listDriv->addItem(QString::fromWCharArray(path));
           ui->listDriv->addItem("\n");
       }
    }
}

void MainWindow::settingsWindowsNTFirst()
{
    QStringList head;
    head << "Имя проц." << "Дескрпитор проц.";
    ui->tableNTProc->setColumnCount(2);
    ui->tableNTProc->setHorizontalHeaderLabels(head);
}

void MainWindow::settingsWindowsNTLast()
{
    ui->tableNTProc->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableNTProc->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::clearWindowsNT()
{
    ui->tableNTProc->clear();
    ui->tableNTProc->clearContents();
    ui->tableNTProc->setRowCount(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    showDrivers();
}

void MainWindow::showProcess()
{
    DWORD idp[255];
    DWORD cb = sizeof(idp);
    DWORD cbn;
    HANDLE hPr;
    WCHAR t_name[255];
    QString name;
    if (EnumProcesses(idp, cb, &cbn)){
        int max = cbn/sizeof(DWORD);
        for(int i = 0; i < max; i++){
            hPr = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, idp[i]);
            int cs = GetModuleFileNameEx (hPr, NULL, t_name, sizeof(t_name));
            if(cs != 0){
                t_name[cs + 1] = 0;
                name = QString::fromWCharArray(t_name);
                name.remove(0, name.lastIndexOf("\\") + 1);
                int i = ui->tableNTProc->rowCount();
                ui->tableNTProc->insertRow(i);
                ui->tableNTProc->setItem(i-1, 0, new QTableWidgetItem(name));
                ui->tableNTProc->setItem(i-1, 1, new QTableWidgetItem(QString("%1").arg((int)hPr)));
            }
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    showWindowsNT();
}

void MainWindow::showWindowsNT()
{
    ui->treeModul->setColumnCount(1);
    ui->treeModul->setHeaderLabel("Модули процесса ");
    clearWindowsNT();
    settingsWindowsNTFirst();
    showProcess();
    settingsWindowsNTLast();
}

void MainWindow::showTreeModule(HANDLE processHandle)
{
    ui->treeModul->setColumnCount(1);
    ui->treeModul->setHeaderLabel("Модули процесса ");
    HMODULE hModules [255];
    DWORD cb = 255*sizeof(HMODULE);
    DWORD cb_needed;
    WCHAR moduleName[255];
    int size = EnumProcessModules(processHandle, hModules, cb, &cb_needed);
    if (size != 0) {
        int count = cb_needed / sizeof(HMODULE);
        for(int i = 0; i < count; i++) {
            QTreeWidgetItem* module = new QTreeWidgetItem(ui->treeModul);
            int curr_size = GetModuleBaseNameW(processHandle, hModules[i], moduleName, 255);
            moduleName[curr_size + 1] = 0;
            module->setText(0, QString::fromWCharArray(moduleName));
            showTreeModuleInfo(processHandle, hModules[i], module);
        }
    }
}

void MainWindow::showTreeModuleInfo(HANDLE processHandle, HMODULE h_module, QTreeWidgetItem *root)
{
    MODULEINFO moduleInfo;
    WCHAR moduleName[255];
    QTreeWidgetItem* moduleState = new QTreeWidgetItem(root);
    int curr_size = GetModuleFileNameExW(processHandle, h_module, moduleName, 255);
    moduleName[curr_size + 1] = 0;
    moduleState->setText(0, "Путь к модулю: " + QString::fromWCharArray(moduleName));
    if (GetModuleInformation(processHandle, h_module, &moduleInfo, sizeof(moduleInfo)) != 0) {
        moduleState = new QTreeWidgetItem(root);
        moduleState->setText(0, "Адрес загрузки: " + QString("0x%1").arg((int)moduleInfo.lpBaseOfDll, 0, 16));
        moduleState = new QTreeWidgetItem(root);
        moduleState->setText(0, "Размер: " + QString::number(moduleInfo.SizeOfImage / 1024) + " КБайт");
        moduleState = new QTreeWidgetItem(root);
        moduleState->setText(0, "Точка входа: " +  QString("0x%1").arg((int)moduleInfo.EntryPoint, 0, 16));
    }
}

void MainWindow::on_tableNTProc_itemClicked(QTableWidgetItem *item)
{
    if (item->column() == 1){
        //ui->listModule->clear();
        ui->treeModul->clear();
        //showModule((HANDLE)item->text().toInt());
        showTreeModule((HANDLE)item->text().toInt());
    }
}
