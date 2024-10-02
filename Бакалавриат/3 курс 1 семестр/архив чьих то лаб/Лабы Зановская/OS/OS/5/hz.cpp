#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <locale>
int main()
{
    setlocale(LC_ALL, "rus");
    int sz = GetLogicalDriveStrings(NULL, 0);
    TCHAR* szLogicalDrives = new TCHAR [sz];
    GetLogicalDriveStrings(sz, szLogicalDrives);

    while(*szLogicalDrives)
    {
        TCHAR szDisk[80];
        lstrcpy(szDisk, szLogicalDrives);
        GetDriveType(szDisk);
        UINT uDriveType = GetDriveType(szDisk);
        if(uDriveType == DRIVE_FIXED)
        {
            std::wcout << szDisk << std::endl;
            //определяем флаги
            std::wcout << "Системные флаги диска:\t";
            DWORD dwSystemFlags;
            GetVolumeInformation(szDisk, NULL, 0, NULL, 0, &dwSystemFlags, NULL, 0);
            std::wcout << dwSystemFlags <<L"\n";
            //определяем объем
            __int64 uliTotalBytes;
            GetDiskFreeSpaceEx(szDisk,NULL,(PULARGE_INTEGER)&uliTotalBytes,NULL);
            std::wcout << "Объем диска:\t" << uliTotalBytes/(1024*1024)  << " МБ\n";
            std::wcout << std::endl;
        }
        while(*szLogicalDrives) szLogicalDrives++;
        szLogicalDrives++;
    }

}
