// asm8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#pragma comment(lib,"lab8.lib")
extern "C" __declspec(dllimport) int _stdcall sorts(float* pos, float* neg, int* pos_count, float* a, int size);
extern "C" __declspec(dllimport) int _cdecl sortc(float* pos, float* neg, int* pos_count, float* a, int size);
extern "C" __declspec(dllimport) int _fastcall sortf(float* pos, float* neg, int* pos_count, float* a, int size);
extern "C" __declspec(dllimport) int _stdcall sorts_arg(float* pos, float* neg, int* pos_count, float* a, int size);
extern "C" __declspec(dllimport) int _cdecl sortc_arg(float* pos, float* neg, int* pos_count, float* a, int size);

void _Sort(float* arr, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			float tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}
int Sort(float* pos, float* neg, int* pos_count, float* a, int size)
{
	*pos_count = 0;
	int t = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (a[i] < 0) {
			pos[*pos_count] = a[i]; *pos_count+=1;
		}
		else {
			neg[t] = a[i]; t++;
		}
	}
	_Sort(pos, *pos_count);
	_Sort(neg, t);
	return t;
}

int Sort_asm(float* pos, float* neeg, int* pos_count, float* a, int sizze)
{
	int t=0;
	_asm{
		PUSH ECX
		PUSH EBX
		PUSH ESI
		PUSH EDI
		PUSH EDX
		MOV ESI, pos; FLOAT POS_RES
		MOV EDI, neeg; FLOAT NEG_RES
		; MOV EBX, [pos_count]; INT* POS_COUNT
		MOV EBX, a; FLOAT* A
		MOV ECX, sizze; INT LENGHT
		XOR EDX, EDX
		CMP ECX, 0
		JLE j1; X <= 0
		FINIT
		FLDZ
		loop1 :
		FLD DWORD PTR[EBX + EDX]
			FCOMIP ST(0), ST(1); db 0dfh, 0f0h + 1;; FCOMIP ST(0), ST(1)
			JB j3; X < 0
			;;
		PUSH EDI
			PUSH ESI
			MOV EDI, EBX
			ADD EDI, EDX
			MOV EAX, ESI
			MOV ESI, EDI
			MOV EDI, EAX
			;;
		MOVSD; [ESI] , [EDI];; [EBX + EDX]
			POP ESI
			POP EDI
			ADD ESI, 4
			JMP j4
			j3 :
		;;
		PUSH ESI
			MOV ESI, EBX
			ADD ESI, EDX
			;;
		MOVSD; [EDI] , [ESI];; [EBX + EDX]
			POP ESI
			;; ADD EDI, 4;; НЕТ ТК EDI CHANGE SELF
			j4 :
		ADD EDX, 4
			loop loop1

			FFREE ST(0)
			SUB ESI, pos; FLOAT POS_RES
			SUB EDI, neeg; FLOAT NEG_RES

			MOV ECX, 4
			MOV EAX, ESI
			CDQ
			DIV ECX
			MOV ESI, EAX
			MOV EAX, EDI
			CDQ
			DIV ECX
			MOV EDI, EAX
			MOV EAX, pos_count
			MOV DWORD PTR[EAX], ESI; INT* POS_COUNT
			JMP j2
			j1 :
		MOV EDI, 0
			MOV EAX, pos_count
			MOV DWORD PTR[EAX], EDI; INT* POS_COUNT
			j2 :
		MOV EAX, EDI
			MOV t,EAX
			PUSH ESI
			MOV ESI, pos; FLOAT POS_RES
			PUSH ESI

			////////////////////////////////////////////
			PUSH ECX
			PUSH EBX
			PUSH ESI
			PUSH EDI
			PUSH EDX
			PUSH EAX
			PUSH EBP
			XOR EDX, EDX
			MOV ESI, [ESP + 4 * 7]
			MOV EBP, [ESP + 4 * 8]
			DEC EBP
			FINIT
			for1 :
		INC EDX

			MOV ECX, EDX
			MOV EDI, EDX
			DEC EDI
			for2 :
		CMP ECX, 0
			JBE  j8
			FLD DWORD PTR[ESI + ECX * 4]; J
			FLD DWORD PTR[ESI + EDI * 4]; J - 1
			FCOMIP ST(0), ST(1); db 0dfh, 0f0h + 1;; FCOMIP ST(0), ST(1)
			JBE j9; JBE j9; X <= Y
			; x[j - 1] <= x[j]

			;;;;;; SWAP
			MOV EAX, [ESI + ECX * 4]
			MOV EBX, [ESI + EDI * 4]
			MOV[ESI + ECX * 4], EBX
			MOV[ESI + EDI * 4], EAX
			;;;;;; SWAP

			j9 :
		FFREE ST(0)
			DEC ECX
			DEC EDI
			JMP for2
			j8 :

		CMP EDX, EBP; X < Y
			JL for1

			POP EBP
			POP EAX
			POP EDX
			POP EDI
			POP ESI
			POP EBX
			POP ECX

			POP ESI
			POP ESI
			/////////////////////////////////////////////
			PUSH EDI
			MOV EDI, neeg; FLOAT NEG_RES
			PUSH EDI

			/////////////////////////////////////////////
			PUSH ECX
			PUSH EBX
			PUSH ESI
			PUSH EDI
			PUSH EDX
			PUSH EAX
			PUSH EBP
			XOR EDX, EDX
			MOV ESI, [ESP + 4 * 7]
			MOV EBP, [ESP + 4 * 8]
			DEC EBP
			FINIT
			for11 :
		INC EDX

			MOV ECX, EDX
			MOV EDI, EDX
			DEC EDI
			for21 :
		CMP ECX, 0
			JBE  j81

			FLD DWORD PTR[ESI + EDI * 4]; J - 1
			FLD DWORD PTR[ESI + ECX * 4]; J
			FCOMIP ST(0), ST(1); db 0dfh, 0f0h + 1;; FCOMIP ST(0), ST(1)
			JBE j91; JBE j9; X <= Y
			; x[j - 1] <= x[j]

			;;;;;; SWAP
			MOV EAX, [ESI + ECX * 4]
			MOV EBX, [ESI + EDI * 4]
			MOV[ESI + ECX * 4], EBX
			MOV[ESI + EDI * 4], EAX
			;;;;;; SWAP

			j91 :
		FFREE ST(0)
			DEC ECX
			DEC EDI
			JMP for21
			j81 :

		CMP EDX, EBP; X < Y
			JL for11

			POP EBP
			POP EAX
			POP EDX
			POP EDI
			POP ESI
			POP EBX
			POP ECX
			POP EDI
			POP EDI
			/////////////////////////////////////////////


			POP EDX
			POP EDI
			POP ESI
			POP EBX
			POP ECX

	
	}
	return t;
}
 int  N = 1024;

void show()
{
	int* coun = new int(0);
	float* arr = new float[10];
	float* pos = new float[10];
	float* neg = new float[10];
	float arrs[10] = { 0.0,2.0,-1.0,-8.0,6.0,6.0,6.0,0.0,-7.0,7.0 };
	for (size_t i = 0; i < 10; i++)
	{
		arr[i]=arrs[i] ;
	}
	ULONGLONG t1, t2;
	t1 = GetTickCount64();
	int ng = Sort_asm(pos, neg, coun, arr, 10);//sorts
	t2 = GetTickCount64();
	t2 = t2 - t1;
	std::cout << "test" << "\n";
	std::cout << "a=";
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << "\n";

	std::cout << "neg=";
	for (size_t i = 0; i < *coun; i++)
	{
		std::cout << pos[i] << "  ";
	}
	std::cout << "\n";

	std::cout << "pos=";
	for (size_t i = 0; i < ng; i++)
	{
		std::cout << neg[i] << "  ";
	}
	std::cout << "\n";
	std::cout << "time=" << t2 << "\n\n";

}

void fun(std::string s,float* pos, float* neg, int* pos_count, float* a, int size)
{
	ULONGLONG t1, t2;
	t1 = GetTickCount64();
	int ng = sorts(pos, neg, pos_count, a, size);
	t2 = GetTickCount64();
	t2 = t2 - t1;
	std::cout << s << "\n";
	/*std::cout << "a=";
	for (size_t i = 0; i < size; i++)
	{
		std::cout << a[i] << "  ";
	}
	std::cout << "\n";

	std::cout << "neg=";
	for (size_t i = 0; i < *pos_count; i++)
	{
		std::cout << pos[i] << "  ";
	}
	std::cout << "\n";

	std::cout << "pos=";
	for (size_t i = 0; i < ng; i++)
	{
		std::cout << neg[i] << "  ";
	}*/
	std::cout << "\n";
	std::cout << "time=" << t2 << "\n\n";


}

void fun1(std::string s, float* pos, float* neg, int* pos_count, float* a, int size)
{
	ULONGLONG t1, t2;
	t1 = GetTickCount64();
	int ng = Sort(pos, neg, pos_count, a, size);
	t2 = GetTickCount64();
	t2 = t2 - t1;
	std::cout << s << "\n";
	std::cout << "\n";
	std::cout << "time=" << t2 << "\n\n";
}


void fun2(std::string s, float* pos, float* neg, int* pos_count, float* a, int size)
{
	ULONGLONG t1, t2;
	t1 = GetTickCount64();
	int ng = Sort_asm(pos, neg, pos_count, a, size);
	t2 = GetTickCount64();
	t2 = t2 - t1;
	std::cout << s << "\n";
	std::cout << "\n";
	std::cout << "time=" << t2 << "\n\n";
}

void get_arr(float* f, int n) {
	for (size_t i = 0; i < n; i++)
	{
		if(rand()%2==1)f[i] = float(rand());
		else f[i] = -float(rand());
	}
}

char dll_name[] = "lab8.dll"; // Полный путь к библиотеке
HMODULE hModule = LoadLibraryA(dll_name);

typedef int(_stdcall* func_sorts) (float* pos, float* neg, int* pos_count, float* a, int size);
typedef int(_cdecl* func_sortc) (float* pos, float* neg, int* pos_count, float* a, int size);
typedef int(_fastcall* func_sortf) (float* pos, float* neg, int* pos_count, float* a, int size);
typedef int(_stdcall* func_sorts_arg) (float* pos, float* neg, int* pos_count, float* a, int size);
typedef int(_cdecl* func_sortc_arg) (float* pos, float* neg, int* pos_count, float* a, int size);
void SSotr_dinamik()
{
	// Если dll-файл найден
	if (hModule != NULL)
	{
		char func_name[] = "_sorts@20";
		char func_name1[] = "sortc";
		char func_name2[] = "@sortf@20";
		char func_name3[] = "sortc_arg";
		char func_name4[] = "sorts_arg";


		// Получить указатель на подпрограмму
		func_sorts f1 = (func_sorts)GetProcAddress(hModule, func_name);
		func_sortc f2 = (func_sortc)GetProcAddress(hModule, func_name1);
		func_sortf f3 = (func_sortf)GetProcAddress(hModule, func_name2);
		func_sorts_arg f4 = (func_sorts_arg)GetProcAddress(hModule, func_name3);
		func_sortc_arg f5 = (func_sortc_arg)GetProcAddress(hModule, func_name4);
		if (f1 == NULL)
			printf("Подпрограмма %s не найдена в библиотеке", func_name);
		if (f2 == NULL)
			printf("Подпрограмма %s не найдена в библиотеке", func_name1);
		if (f3 == NULL)
			printf("Подпрограмма %s не найдена в библиотеке", func_name2);	
		if (f4 == NULL)
			printf("Подпрограмма %s не найдена в библиотеке", func_name3);
		if (f5 == NULL)
			printf("Подпрограмма %s не найдена в библиотеке", func_name4);
		if(f1 != NULL&& f2 != NULL&& f3 != NULL&& f4 != NULL&& f5 != NULL)
		{
			printf("Подпрограмма %s %s %s %s %s  найдены  в библиотеке и одна из них use", func_name, func_name1,func_name2, func_name3, func_name);
			int* coun = new int(0);
			float* arr = new float[10];
			float* pos = new float[10];
			float* neg = new float[10];
			float arrs[10] = { 0.0,2.0,-1.0,-8.0,6.0,6.0,6.0,0.0,-7.0,7.0 };
			for (size_t i = 0; i < 10; i++)
			{
				arr[i] = arrs[i];
			}
			int ng = f1(pos, neg, coun, arr, 10);//sorts
			std::cout << "test" << "\n";
			std::cout << "a=";
			for (size_t i = 0; i < 10; i++)
			{
				std::cout << arr[i] << "  ";
			}
			std::cout << "\n";

			std::cout << "neg=";
			for (size_t i = 0; i < *coun; i++)
			{
				std::cout << pos[i] << "  ";
			}
			std::cout << "\n";

			std::cout << "pos=";
			for (size_t i = 0; i < ng; i++)
			{
				std::cout << neg[i] << "  ";
			}
			std::cout << "\n";

			delete[] arr;
			delete[] pos;
			delete[] neg;
			delete coun;
		}
		// Освобождение библиотеки
		FreeLibrary(hModule);
	}
	else
		printf("dll-файл %s не найден", dll_name);

}




int main()
{
	setlocale(LC_ALL, "Russian");
	int ng = 0;
	N = N * 10;
	int coun;
	float *arr = new float[N];
	float *pos = new float[N];
	float *neg = new float[N];
	show();

	get_arr(arr, N);
	fun("sort stdcall ", pos, neg, &coun, arr, N);
	fun1("sort c++ ", pos, neg, &coun, arr, N);
	fun2("sort c++ ", pos, neg, &coun, arr, N);
	SSotr_dinamik();
	delete[] arr;
	delete[] pos;
	delete[] neg;
	//fun2("asm  c++ ", pos, neg, coun, arr, N);
}