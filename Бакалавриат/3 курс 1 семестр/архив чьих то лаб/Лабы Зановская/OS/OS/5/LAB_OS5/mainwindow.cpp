#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setlocale (LC_ALL, "Rus");
    char path[MAX_PATH];
    int t;
    if (t = createKey(path) != 0)
        return;

    logicalDrivers(path);

    //system("pause");
}

int MainWindow::logicalDrivers(char *path)
{
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()
    << "Имя диска" << "Количество доступных байтов"
    << "Общее количество байтов на диске" << "Количество свободных байтов" << "Максимальная длина файла" << "Название тома"
    << "Серийный номер" << "Тип файловой системы");

    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    int n;
    char dd[4];
    string t = '\n'+"Available disk drives : ";
    long dr = GetLogicalDrives(); //возвращает число-битовую маску в которой хранятся все доступные диски ( если 0 бит равен 1, то диск "A:" присутствует, и т.д. )
    DWORD size;
    long long FreeBytesAvail, TotalNumOfBytes, TotalNumOfFreeBytes;

    HANDLE  hEndRead;  // дескриптор события
    OVERLAPPED  ovl;   // структура управления асинхронным доступом к файлу
    {
    // создаем события с автоматическим сбросом
    hEndRead = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (hEndRead == NULL)
        return GetLastError();
    }
    // инициализируем структуру OVERLAPPED
    ovl.Offset = 0xFFFFFFFF;         // младшая часть смещения равна 0
    ovl.OffsetHigh = 0xFFFFFFFF;      // старшая часть смещения равна 0
    ovl.hEvent = hEndRead;

    HANDLE hFile = CreateFileW(ConvertToLPWSTR(path), GENERIC_WRITE,
                               FILE_SHARE_WRITE, NULL, CREATE_ALWAYS,
                               FILE_FLAG_OVERLAPPED, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        cerr << "Create file failed." << endl
             << "The last error code: " << GetLastError() << endl;
        CloseHandle(hEndRead);
        return 0;
    }
    numRow = 0;
    for (int i = 0; i < 26; i++)
    {
        n = ((dr >> i) & 0x00000001);
        if (n == 1)
        {
            ui->tableWidget->insertRow(numRow);
            dd[0] = char(65 + i); dd[1] = ':'; dd[2] = '\\'; dd[3] = 0;

            ui->tableWidget->setItem(numRow, 0, new QTableWidgetItem(dd));
            t = "\nAvailable disk drives : " + (string)dd + '\n';

            //выдаёт информацию о доступном месте на диске.
            GetDiskFreeSpaceEx(ConvertToLPWSTR(dd), (PULARGE_INTEGER)&FreeBytesAvail, (PULARGE_INTEGER)&TotalNumOfBytes, (PULARGE_INTEGER)&TotalNumOfFreeBytes);
            FreeBytesAvail = FreeBytesAvail;//1024/1024/1024;
            TotalNumOfBytes = TotalNumOfBytes;//1024/1024/1024;
            TotalNumOfFreeBytes = TotalNumOfFreeBytes;//1024/1024/1024;

            //записываем информацию в файл
            WriteFile(hFile, t.c_str(), (t).size(), &size, &ovl);
            size += (t).size();

            //добавляем информацию в таблицу
            ui->tableWidget->setItem(numRow, 1, new QTableWidgetItem(QString::number(FreeBytesAvail)));
            ui->tableWidget->setItem(numRow, 2, new QTableWidgetItem(QString::number(TotalNumOfBytes)));
            ui->tableWidget->setItem(numRow, 3, new QTableWidgetItem(QString::number(TotalNumOfFreeBytes)));

            t = "FreeBytesAvail   " + to_string(FreeBytesAvail) + ",  TotalNumOfBytes  " + to_string(TotalNumOfBytes) + ",  TotalNumOfFreeBytes   " + to_string(TotalNumOfFreeBytes) + '\n';
            WriteFile(hFile, t.c_str(), (t).size(), &size, &ovl);
            size += (t).size();

            // возвращает информацию о файловой системе и дисках( директориях ).
            volumeInformation(i, hFile, size, ovl);
            driveType(dd, hFile, size, ovl);
            numRow++;

        }

    }
}


void MainWindow::volumeInformation(int i, HANDLE h, DWORD &size, OVERLAPPED ovl)
{
    char VolumeNameBuffer[100];
    char FileSystemNameBuffer[100];
    DWORD FileSystemFlags, MaximumComponentLength;
    unsigned long VolumeSerialNumber;

    char dd[4];
    dd[0] = char(65 + i); dd[1] = ':'; dd[2] = '\\'; dd[3] = 0;


    /*

    BOOL GetVolumeInformation(
    LPCTSTR lpRootPathName, // имя диска(директории) [in]
    LPTSTR lpVolumeNameBuffer, // название диска [out]
    DWORD nVolumeNameSize, // длина буфера названия диска [in]
    LPDWORD lpVolumeSerialNumber, // сериальный номер диска [out]
    LPDWORD lpMaximumComponentLength, // максимальная длина фыйла [out]
    LPDWORD lpFileSystemFlags, // опции файловой системы [out]
    LPTSTR lpFileSystemNameBuffer, // имя файловой системы [out]
    DWORD nFileSystemNameSize // длина буфера имени файл. сист. [in]
    );

    */
    BOOL GetVolumeInformationFlag = GetVolumeInformationA(
        dd,
        VolumeNameBuffer,
        100,
        &VolumeSerialNumber,
        &MaximumComponentLength,
        &FileSystemFlags,
        FileSystemNameBuffer,
        100
    );

    if (GetVolumeInformationFlag != 0)
    {
        string t = "	Maximum Component  Length " + dwordToString(MaximumComponentLength) + '\n';
//        QString tt = QString::number((int)MaximumComponentLength);
//        for (int i = 0; i < tt.length(); i++)
//            t = t + tt[i];
//        t += '\n';
        qDebug() << QString::number(MaximumComponentLength);
        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();
        ui->tableWidget->setItem(numRow, 4, new QTableWidgetItem(QString::number(MaximumComponentLength)));
        ui->tableWidget->hideColumn(4);

        t = "	Volume Name  " + (string)VolumeNameBuffer + '\n';
        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();
        QString tmps;
        tmps = VolumeNameBuffer;
        ui->tableWidget->setItem(numRow, 5, new QTableWidgetItem(tmps));

        t = "	Volume Serial Number  " + to_string(VolumeSerialNumber) + '\n';
        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();

        ui->tableWidget->setItem(numRow, 6, new QTableWidgetItem(QString::number(VolumeSerialNumber)));
        t = "	File System  " + (string)FileSystemNameBuffer + '\n';
        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();
        tmps = FileSystemNameBuffer;
        ui->tableWidget->setItem(numRow, 7, new QTableWidgetItem(tmps));


        t = "	System flags ";
        t += "0x" + toHex(FileSystemFlags) + '\n';

        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();
        string tmp = "";

        //это флаги в 16-м виде
        if (t[9] == '2')
            tmp += "FILE_CASE_PRESERVED_NAMES\n";
        if (t[9] == '1')
            tmp += "FILE_CASE_SENSITIVE_SEARCH\n";
        if (t[8] == '1')
            tmp += "FILE_FILE_COMPRESSION\n";
        if (t[5] == '4')
            tmp += "FILE_NAMED_STREAMS\n";
        if (t[9] == '8')
            tmp += "FILE_PERSISTENT_ACLS\n";
        if (t[5] == '8')
            tmp += "FILE_READ_ONLY_VOLUME\n";
        if (t[4] == '1')
            tmp += "FILE_SEQUENTIAL_WRITE_ONCE\n";
        if (t[5] == '2')
            tmp += "FILE_SUPPORTS_ENCRYPTION\n";
        if (t[4] == '8')
            tmp += "FILE_SUPPORTS_EXTENDED_ATTRIBUTES\n";
        if (t[4] == '4')
            tmp += "FILE_SUPPORTS_HARD_LINKS\n";
        if (t[5] == '1')
            tmp += "FILE_SUPPORTS_OBJECT_IDS\n";
        if (t[3] == '1')
            tmp += "FILE_SUPPORTS_OPEN_BY_FILE_ID\n";
        if (t[8] == '8')
            tmp += "FILE_SUPPORTS_REPARSE_POINTS\n";
        if (t[8] == '4')
            tmp += "FILE_SUPPORTS_SPARSE_FILES\n";
        if (t[4] == '2')
            tmp += "FILE_SUPPORTS_TRANSACTIONS\n";
        if (t[3] == '2')
            tmp += "FILE_SUPPORTS_USN_JOURNAL\n";
        if (t[9] == '4')
            tmp += "FILE_UNICODE_ON_DISK\n";
        if (t[6] == '8')
            tmp += "FILE_VOLUME_IS_COMPRESSED\n";
        if (t[8] == '2')
            tmp += "FILE_VOLUME_QUOTAS\n";

        WriteFile(h, tmp.c_str(), (tmp).size(), &size, &ovl);
        size += (tmp).size();
    }
    else
    {
        string t = "	Not Present (GetVolumeInformation)" + '\n';
        WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
        size += (t).size();
    }
}


//возвращает тип диска
void MainWindow::driveType(string s, HANDLE h, DWORD &size, OVERLAPPED ovl)
{
    int d;
    LPWSTR x = ConvertToLPWSTR(s);
    //d = GetDriveType(L"c:\\");
    d = GetDriveType(x);
    string t;
    if (d == DRIVE_UNKNOWN) t =		"\n	\t \t \t \t Drive type UNKNOWN" + '\n';
    if (d == DRIVE_NO_ROOT_DIR) t = "\n \t \t \t \t Drive type DRIVE NO ROOT DIR" + '\n';
    if (d == DRIVE_REMOVABLE) t =	"\n	\t \t \t \t Drive type REMOVABLE" + '\n';
    if (d == DRIVE_FIXED) t =		"\n	\t \t \t \t Drive type FIXED" + '\n';
    if (d == DRIVE_REMOTE) t =		"\n	\t \t \t \t Drive type REMOTE" + '\n';
    if (d == DRIVE_CDROM) t =		"\n \t \t \t \t	Drive type CDROM" + '\n';
    if (d == DRIVE_RAMDISK) t =		"\n	\t \t \t \t Drive type RAMDISK" + '\n';

    WriteFile(h, t.c_str(), (t).size(), &size, &ovl);
    size += (t).size();
}

//некоторые компиляторы не пропускают строку
LPWSTR MainWindow::ConvertToLPWSTR(const std::string& s)
{
    LPWSTR ws = new wchar_t[s.size() + 1]; // +1 for zero at the end
    copy(s.begin(), s.end(), ws);
    ws[s.size()] = 0; // zero at the end
    return ws;
}


int MainWindow::createKey(char *ret)
{
    // Строка которую будем писать в реестр
    _TCHAR szTestString[] = _T("‪C:\\Users\\Acer\\Desktop\\LABS\\OS\\5\\o.txt");

    // Ключ который будем создавать
    _TCHAR szPath[] = _T("Software\\");

    HKEY hKey;

    // Создаем ключ в ветке HKEY_CURRENT_USER
    if (RegCreateKeyEx(HKEY_CURRENT_USER, szPath, 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS) {
    //if (RegCreateKeyEx(HKEY_CURRENT_USER, ConvertToLPWSTR(szPath), 0,NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS) {
        _tcout << _T("При создании ключа произошла ошибка") << endl;
        return 1;
    }

    // Пишем тестовую строку в созданный ключ
    if (RegSetValueEx(hKey, _T("OS5"), 0, REG_SZ, (BYTE*)szTestString, sizeof(szTestString)) != ERROR_SUCCESS) {
    //if (RegSetValueEx(hKey, ConvertToLPWSTR(_T("OS5")), 0, REG_SZ, (BYTE*)szTestString, sizeof(szTestString)) != ERROR_SUCCESS) {
        _tcout << _T("При записи строки произошла ошибка") << endl;
        return 2;
    }

    // Закрываем описатель ключа
    if (RegCloseKey(hKey) != ERROR_SUCCESS) {
        _tcout << _T("При закрытии ключа произошла ошибка") << endl;
        return 3;
    };

    _TCHAR szBuf[MAX_PATH];

    DWORD dwBufLen = MAX_PATH;

    //if (RegGetValue(HKEY_CURRENT_USER, ConvertToLPWSTR(szPath), ConvertToLPWSTR(_T("OS5")), RRF_RT_REG_SZ, NULL, (BYTE*)szBuf, &dwBufLen) != ERROR_SUCCESS) {
    if (RegGetValue(HKEY_CURRENT_USER, szPath, _T("OS5"), RRF_RT_REG_SZ, NULL, (BYTE*)szBuf, &dwBufLen) != ERROR_SUCCESS) {
        _tcout << _T("При чтении строки произошла ошибка") << endl;
        return 4;
    }

    for (int i = 3; i < MAX_PATH; i++)
    {
        ret[i-3] = szBuf[i];
    }
    qDebug() << "Считанная строка " << ret << endl;
   // system("pause");
   // _tsystem(_T("pause"));

    return 0;
}

ofstream MainWindow::outputInfo(char * fileName)
{
    ofstream out(fileName);
    return out;
}


string MainWindow:: toHex(DWORD a)
{
    string tmp("");
    char t[9];
    do
    {
        int r(a % 16);
        if (r > 9) { r += (int)'A' - 10; }
        else { r += (int)'0'; };
        tmp = (char)r + tmp;
        a /= 16;
    } while (a);
    int size = tmp.size();
    int i;
    t[8] = 0;

    size--;
    for (i = 7; size >= 0; i--)
        t[i] = tmp[size--];
    for (; i >= 0; i--)
        t[i] = '0';
    return t;
}
MainWindow::~MainWindow()
{
    delete ui;
}
string MainWindow::dwordToString (DWORD n)
{
    char s[20];
    int i = 0;
    while (n > 0)
    {
        s[i] = n%10 + '0';
        n = n/10;

        i++;
    }
    s[i] = 0;

    for (int j = 0; j < i/2; j++)
    {
        char c;
        c = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = c;
    }

    return s;
}
void MainWindow::on_pushButton_clicked()
{
}

