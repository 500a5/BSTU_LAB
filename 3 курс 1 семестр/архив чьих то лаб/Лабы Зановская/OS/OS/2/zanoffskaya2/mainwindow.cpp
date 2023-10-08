#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->fullEdit->clear();
    ui->nameEdit->clear();
    ui->handleEdit->clear();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->fullRadio->isChecked())
    {
        QString name;
        QString fullName = ui->fullEdit->toPlainText();
        HMODULE hm;
        getByFullName(hm, name, fullName);
        ui->nameEdit->setText(name);
        ui->handleEdit->setText(QString("%1").arg((int)hm));
    }
    if(ui->nameRadio->isChecked())
    {
        QString name = ui->nameEdit->toPlainText();
        QString fullName;
        HMODULE hm;
        getByName(hm,name,fullName);
        ui->fullEdit->setText(fullName);
        ui->handleEdit->setText(QString("%1").arg((int)hm));
    }
    if(ui->handleRadio->isChecked())
    {
        QString name;
        QString fullName;
        HMODULE hm = (HMODULE)ui->handleEdit->toPlainText().toInt();
        getByHandle(hm, name, fullName);
        ui->fullEdit->setText(fullName);
        ui->nameEdit->setText(name);

    }
    if(ui->noRadio->isChecked())
    {
        QString name;
        QString fullName;
        HMODULE hm;
        getByEx(hm, name, fullName);
        ui->fullEdit->setText(fullName);
        ui->nameEdit->setText(name);
        ui->handleEdit->setText(QString("%1").arg((int)hm));
    }
}

void MainWindow::getByName(HMODULE &hm, QString name, QString &fullName)
{
    WCHAR info[255];
    int size = name.toWCharArray(info);
    info[size] = 0;
    hm = GetModuleHandle(info);
    //qDebug() << hm;
    if (hm != NULL)
    {
        WCHAR tmp_name[255];
        int tmp_size = GetModuleFileName(hm, tmp_name, 255);
        tmp_name[tmp_size + 1] = 0;
        fullName = QString::fromWCharArray(tmp_name);
    }
}

void MainWindow::getByHandle(HMODULE hm, QString &name, QString &fullName)
{
    WCHAR info[255];
    int size = GetModuleFileName(hm, info, 255);
    fullName = QString::fromWCharArray(info);
    if (size!=0)
    {
        info[size + 1] = 0;
        fullName = QString::fromWCharArray(info);
        name = fullName;
        name.remove(0, name.lastIndexOf("\\") + 1);
    }
}

void MainWindow::getByFullName(HMODULE &hm, QString &name, QString fullName)
{
    name = fullName;
    name.remove(0, name.lastIndexOf("\\") + 1);

    WCHAR info[255];
    int size =  name.toWCharArray(info);
    info[size] = 0;
    hm = GetModuleHandle(info);
}

void MainWindow::getByEx(HMODULE &hm, QString &name, QString &fullName)
{
    hm = GetModuleHandle(NULL);
    return getByHandle(hm, name, fullName);
}

void MainWindow::getCurrentInfo()
{
    DWORD tid = GetCurrentProcessId();
    ui->currIDEdit->setText(QString::number(tid));

    HANDLE tcp = GetCurrentProcess();
    ui->currPseudoEdit->setText(QString("%1").arg((int)tcp));

    HANDLE tcopy;
    DuplicateHandle(tcp, tcp, tcp, &tcopy, PROCESS_ALL_ACCESS, false, 0);
    ui->currHandleDupEdit->setText(QString("%1").arg((int)tcopy));

    HANDLE top = OpenProcess(PROCESS_ALL_ACCESS, false, tid);
    ui->currHandleOpenEdit->setText(QString("%1").arg((int)top));

    bool tfd = CloseHandle(tcopy);
    ui->currCloseDupEdit->setText(QString("%1").arg((int)tcopy));

    bool tfo = CloseHandle(top);
    ui->currCloseOpenEdit->setText(QString("%1").arg((int)top));
}


void MainWindow::on_pushButton_3_clicked()
{
    getCurrentInfo();
}

void MainWindow::on_pushButton_7_clicked()
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

void MainWindow::clearWin9x()
{
     ui->tableMod->clear();
     ui->tableMod->clearContents();
     ui->tableMod->setRowCount(0);
     ui->tableMod->clear();
     ui->tableThread->clear();
     ui->tableThread->clearContents();
     ui->tableThread->setRowCount(0);
     ui->tableThread->clear();
     ui->tableProc->clear();
     ui->tableProc->clearContents();
     ui->tableProc->setRowCount(0);
     ui->tableProc->clear();
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
    ui->tableThread->setColumnCount(2);
    ui->tableThread->setHorizontalHeaderLabels(head);
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
    ui->tableProc->setItem(i-1, 4, new QTableWidgetItem(QString::number(prior)));
}


void MainWindow::settingsFinWin9x()
{
    ui->tableProc->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableProc->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableThread->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableThread->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableMod->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMod->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    if (!flag)
        QMessageBox::warning(this, "Предупреждение!", "fals");
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
    int i = ui->tableThread->rowCount();
    ui->tableThread->insertRow(i);
    ui->tableThread->setItem(i-1, 0, new QTableWidgetItem(QString::number(tr.th32ThreadID)));
    int prior = (int)tr.tpBasePri;
    ui->tableThread->setItem(i-1, 1, new QTableWidgetItem(QString::number(prior)));
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
    head << "Имя" << "Дескриптор";
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
                //qDebug() << name;
                int i = ui->tableNTProc->rowCount();
                ui->tableNTProc->insertRow(i);
                ui->tableNTProc->setItem(i-1, 0, new QTableWidgetItem(name));
                ui->tableNTProc->setItem(i-1, 1, new QTableWidgetItem(QString("%1").arg((int)hPr)));
            }
        }
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    showWindowsNT();
}

void MainWindow::showWindowsNT()
{
    ui->treeModul->setColumnCount(1);
    ui->treeModul->setHeaderLabel("Модули процесса");
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
