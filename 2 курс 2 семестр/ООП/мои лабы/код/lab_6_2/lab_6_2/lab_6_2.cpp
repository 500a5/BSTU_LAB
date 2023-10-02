#include <Windows.h>
 #include <iostream>
 #include <cstdlib>
 #include <string>
 #include <ctime>
 #include <tchar.h>

 #define MAXSIZE 255
 using namespace std;

 char text[MAXSIZE] = "The name of the novel, its terminology, and even the name of the author later became ";


 DWORD WINAPI thread_1(LPVOID lpParam)
 {
	 int i = 0;
	 for (int i = 0; i < 100; i++)
		 {
		
			 HANDLE mutex = OpenMutex(SYNCHRONIZE, FALSE, _T("mutex"));
		 int pos = strlen(text);
		 for (int j = pos - 1; j != -1; j--)
			 {
			 text[j + 1] = text[j];
			 }
		 text[0] = ' ';
		 text[pos + 2] = '\0';
		 i++;
		 cout << text << endl;
		 ReleaseMutex(mutex);
		 }
	 return 0;
	 }

 DWORD WINAPI thread_2(LPVOID lpParam)
 {
	 int i = 0;
	 for (int i = 0; i < 100; i++)
		 {
		 HANDLE mutex = OpenMutex(SYNCHRONIZE, FALSE, _T("mutex"));
		 srand(unsigned(time(NULL)));
		 int j = 0;
		 if (strlen(text) != 0)
			 {
			 j = int(rand() % strlen(text));
			 if (text[j] == ' ')
				 {
				
				 int i;
				 for (i = j; text[i] != '\0'; i++)
					 text[i] = text[i + 1];
				 text[i] = '\0';
				
					
				 j = int(rand() % strlen(text));
				 int pos = strlen(text);
				 for (int k = pos - 1; k != j - 1; k--)
					 {
					 text[k + 1] = text[k];
					 }
				 text[j] = ' ';
				 text[pos + 2] = '\0';
				 }
			
				 }
		
			 ReleaseMutex(mutex);
		 }
	 return 0;
	 }

 int main()
 {
	 setlocale(LC_ALL, "rus");
	 HANDLE arr[2];
	 int data_1 = 0, data_2 = 0;
	
	 HANDLE handle_1 = CreateThread(NULL, 0, thread_1, &data_1, 0, NULL);
	 HANDLE handle_2 = CreateThread(NULL, 0, thread_2, &data_2, 0, NULL);
	 arr[0] = handle_1;
	 arr[1] = handle_2;
	 WaitForMultipleObjects(2, arr, TRUE, INFINITY);
	 CloseHandle(handle_1);
	 CloseHandle(handle_2);
	 return 0;
	 }