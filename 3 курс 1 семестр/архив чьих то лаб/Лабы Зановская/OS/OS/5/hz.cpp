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
            //���������� �����
            std::wcout << "��������� ����� �����:\t";
            DWORD dwSystemFlags;
            GetVolumeInformation(szDisk, NULL, 0, NULL, 0, &dwSystemFlags, NULL, 0);
            std::wcout << dwSystemFlags <<L"\n";
            //���������� �����
            __int64 uliTotalBytes;
            GetDiskFreeSpaceEx(szDisk,NULL,(PULARGE_INTEGER)&uliTotalBytes,NULL);
            std::wcout << "����� �����:\t" << uliTotalBytes/(1024*1024)  << " ��\n";
            std::wcout << std::endl;
        }
        while(*szLogicalDrives) szLogicalDrives++;
        szLogicalDrives++;
    }

}
