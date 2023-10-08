#include <iostream>
#include <Windows.h>
#include <tchar.h>

using std::cout;
using std::wcout;
using std::endl;

#ifdef _UNICODE
#  define _tcout wcout
#else
#  define _tcout cout
#endif // _UNICODE

int _tmain(int argc, _TCHAR* argv[])
{
	// ������������� ������� ������� �������� ��� ������ ���������
	_tsetlocale(LC_ALL, _T("Russain"));

	// ������ ������� ����� ������ � ������
	_TCHAR szTestString[] = _T("This is the test");
	// ���� ������� ����� ���������
	_TCHAR szPath[] = _T("Software\\RegistrySample\\");

	HKEY hKey;

	// ������� ���� � ����� HKEY_CURRENT_USER
	if (RegCreateKeyEx(HKEY_CURRENT_USER, szPath, 0, NULL, REG_OPTION_VOLATILE, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS) {
		_tcout << _T("��� �������� ����� ��������� ������") << endl;
		return 1;
	}

	// ����� �������� ������ � ��������� ����
	if (RegSetValueEx(hKey, _T("Test string"), 0, REG_SZ, (BYTE*)szTestString, sizeof(szTestString)) != ERROR_SUCCESS) {
		_tcout << _T("��� ������ ������ ��������� ������") << endl;
		return 2;
	}

	// ��������� ��������� �����
	if (RegCloseKey(hKey) != ERROR_SUCCESS) {
		_tcout << _T("��� �������� ����� ��������� ������") << endl;
		return 3;
	};

	_TCHAR szBuf[MAX_PATH];
	DWORD dwBufLen = MAX_PATH;

	if (RegGetValue(HKEY_CURRENT_USER, szPath, _T("Test String"), RRF_RT_REG_SZ, NULL, (BYTE*)szBuf, &dwBufLen) != ERROR_SUCCESS) {
		_tcout << _T("��� ������ ������ ��������� ������") << endl;
		return 4;
	}

	_tcout << szBuf << endl;

	_tsystem(_T("pause"));

	return 0;
}