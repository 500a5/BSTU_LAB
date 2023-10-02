// ConsoleApplication65.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstddef>
#include <vector>
#include <stdint.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string PrintByte(uint8_t a);
uint8_t getMN(string str);

class HemingMatr {
private:
	size_t n, m;
	uint8_t** matr;
	void freeMem();
	void locMem();
public:
	HemingMatr(size_t n, size_t m);
	HemingMatr& inputMatr();
	HemingMatr& inputMatr(string);
	HemingMatr& printMatr();
	HemingMatr& NTprintMatr();
	HemingMatr& rotateR();
	void dopis(uint8_t d);
	void cut(uint8_t c);
	int lenghtCode();
	bool checkZero();
	friend HemingMatr& operator^(HemingMatr&, HemingMatr&);
	uint8_t* operator[](size_t);
	~HemingMatr();

};
class Heming {
private:
	HemingMatr* H, * P, * G, * Ht;
	size_t m, n, k;
	void makeH();
	void makeP();
	void makeG();
public:
	Heming(size_t m);
	Heming& printAllMatr();
	HemingMatr& coding(HemingMatr&);
	HemingMatr& deCoding(HemingMatr&);
	HemingMatr& getInfBit(HemingMatr&);
	size_t getN();
	int getNumberBin(HemingMatr&);
};

HemingMatr& operator^(HemingMatr& a, HemingMatr& b) {
	HemingMatr* result = new HemingMatr(a.n, b.m);
	for (size_t i = 0; i < a.n; ++i)
		for (size_t j = 0; j < b.m; ++j)
			for (size_t k = 0; k < a.m; ++k)
				(*result)[i][j] ^= a[i][k] & b[k][j];

	return *result;
}

uint8_t* HemingMatr::operator[](size_t index) {
	return matr[index];
}

HemingMatr& HemingMatr::printMatr() {
	cout << "Ваша матрица размера " << n << "x" << m << endl;
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j)
			cout << (unsigned int)matr[i][j];
		if (i != n - 1)
			cout << endl;
	}
	return *this;
}

HemingMatr& HemingMatr::rotateR() {
	uint8_t** newMatr = (uint8_t**)calloc(m, n);
	for (size_t i = 0; i < m; ++i)
		newMatr[i] = (uint8_t*)calloc(n, sizeof(uint8_t));

	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			newMatr[j][n - i - 1] = matr[i][j];

	freeMem();
	matr = newMatr;
	swap(m, n);

	return *this;
}

void HemingMatr::freeMem() {
	for (size_t i = 0; i < n; ++i)
		free(matr[i]);
	free(matr);
}

HemingMatr::~HemingMatr() {
	freeMem();
}

void HemingMatr::locMem() {
	matr = (uint8_t**)calloc(n, sizeof(uint8_t*));
	for (size_t i = 0; i < n; ++i)
		matr[i] = (uint8_t*)calloc(m, sizeof(uint8_t));
}

HemingMatr::HemingMatr(size_t n, size_t m) :n(n), m(m) {
	locMem();
}

HemingMatr& HemingMatr::inputMatr() {
	cout << "Введите матрицу " << n << "x" << m << endl;
	char checkTmp = 0;
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j) {
			cin >> checkTmp;
			if (checkTmp == '1')
				matr[i][j] = 1;
			else
				matr[i][j] = 0;
		}
	return *this;
}

bool HemingMatr::checkZero() {
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			if (matr[i][j] != 0)
				return false;
	return true;
}

int HemingMatr::lenghtCode() {
	return m;
}

HemingMatr& HemingMatr::NTprintMatr() {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j)
			cout << (unsigned int)matr[i][j];
		if (i != n - 1)
			cout << endl;
	}
	return *this;
}

void HemingMatr::dopis(uint8_t d) {
	matr[0] = (uint8_t*)(realloc(matr[0], m + d));
	for (int i = m; i < m + d; ++i) {
		matr[0][i] = 0;
	}
	m += d;
}

void HemingMatr::cut(uint8_t c) {
	matr[0] = (uint8_t*)(realloc(matr[0], m - c));
	m -= c;
}

HemingMatr& HemingMatr::inputMatr(string message) {
	for (int i = 0; i < m; ++i) {
		if (message[i] == '1')
			matr[0][i] = 1;
		else
			matr[0][i] = 0;
	}
	return *this;
}

Heming::Heming(size_t m) :m(m) {
	n = (1 << m) - 1;
	k = n - m;

	makeH();
	makeP();
	makeG();
}

void Heming::makeH() {
	H = new HemingMatr(this->m, n);
	for (size_t i = 0; i < 15; ++i) {
		size_t tmp = i + 1;
		for (int j = m - 1; j >= 0; --j) {
			(*H)[j][i] = tmp & 1;
			tmp >>= 1;
		}
	}
	Ht = new HemingMatr(n, m);
	for (size_t i = 0; i < m; ++i)
		for (size_t j = 0; j < n; ++j)
			(*Ht)[j][i] = (*H)[i][j];
}

Heming& Heming::printAllMatr() {
	cout << "H матрица" << endl;
	(*H).printMatr();
	cout << endl;
	cout << "P матрица" << endl;
	(*P).printMatr();
	cout << endl;
	cout << "G матрица" << endl;
	(*G).printMatr();
	cout << endl;
	return *this;
}
int isPow2(int a) {
	return !(a & (a - 1));
}
void Heming::makeP() {
	P = new HemingMatr(m, k);
	int count = 0;
	for (int j = 0; j < n; ++j) {
		if (!isPow2(j + 1)) {
			for (size_t i = 0; i < m; ++i)
				(*P)[i][count] = (*H)[i][j];
			++count;
		}
	}
	P->rotateR();
}

void Heming::makeG() {
	G = new HemingMatr(k, n);
	int positionP = 0;
	int positionOne = 0;
	for (int j = 0; j < n; ++j) {
		if (isPow2(j + 1)) {
			for (size_t i = 0; i < k; ++i)
				(*G)[i][j] = (*P)[i][positionP];
			++positionP;
		}
		else {
			(*G)[positionOne][j] = 1;
			++positionOne;
		}
	}
}

HemingMatr& Heming::coding(HemingMatr& message) {
	HemingMatr* newMatr = new HemingMatr(1, (message.lenghtCode() / k) * n);
	HemingMatr mask = HemingMatr(1, k);
	int i = 0;
	int l = 0;
	while (i < message.lenghtCode()) {
		for (int j = 0; j < k; ++j) {
			mask[0][j] = message[0][i + j];
		}
		HemingMatr& tmp = mask ^ (*G);
		for (int j = 0; j < n; ++j) {
			(*newMatr)[0][j + l] = tmp[0][j];
		}
		i += k;
		l += n;
	}

	return *newMatr;
}

HemingMatr& Heming::deCoding(HemingMatr& code) {
	HemingMatr* newMatr = new HemingMatr(1, (code.lenghtCode() / n) * k);
	HemingMatr mask = HemingMatr(1, n);
	int i = 0;
	int l = 0;
	while (i < code.lenghtCode()) {
		for (int j = 0; j < n; ++j) {
			mask[0][j] = code[0][i + j];
		}
		HemingMatr& sindrom = mask ^ (*Ht);
		if (!sindrom.checkZero()) {
			int position = getNumberBin(sindrom);
			cerr << "Искажение в " << position + i << " бите" << endl;
			mask[0][position - 1] = !mask[0][position - 1];
		}
		i += n;
		HemingMatr& tmpI = getInfBit(mask);
		for (int j = 0; j < k; ++j) {
			(*newMatr)[0][j + l] = tmpI[0][j];
		}
		l += k;
	}


	return *newMatr;
}

HemingMatr& Heming::getInfBit(HemingMatr& message) {
	HemingMatr* inf = new HemingMatr(1, k);
	size_t position = 0;
	for (size_t i = 0; i < n; ++i)
		if (!isPow2(i + 1)) {
			(*inf)[0][position] = message[0][i];
			++position;
		}
	return *inf;
}

int Heming::getNumberBin(HemingMatr& sindrom) {
	int result = 0;
	for (size_t i = 0; i < m; ++i) {
		result <<= 1;
		result |= sindrom[0][i];
	}
	return result;
}

size_t Heming::getN() {
	return n;
}

string PrintByte(uint8_t a)
{
	string res = "";
	for (int i = 7; i > -1; --i)
		if ((a >> i) & 1)
			res += '1';
		else
			res += '0';
	return res;

}

uint8_t getMN(string str) {
	uint8_t res = 0;
	for (int i = 0; i < 8; ++i) {
		res <<= 1;
		if (str[i] == '1')
			res |= 1;
	}
	return res;
}
int main() {
	setlocale(LC_ALL, "RUS");
	while (true) {
		int flagI = 0;
		cout << "Введите: \n1-кодирование/декодирование\n2-кодирование\n3-декодирование\n4-для выхода" << endl;
		cin >> flagI;
		if (flagI == 4)
			break;
		if (flagI < 3) {

			if (flagI == 1) {
				cout << "Введите m: ";
				int m;
				cin >> m;
				Heming heming = Heming(m);
				heming.printAllMatr();
				cout << "Введите длинну сообщения: ";
				size_t len;
				cin >> len;
				HemingMatr message = HemingMatr(1, len);
				message.inputMatr();

				uint8_t n = heming.getN();
				int k = n - m;
				uint8_t dopis = (k - message.lenghtCode() % k) % k;
				message.dopis(dopis);
				cout << "Код размера блока: " << PrintByte(n) << endl;
				cout << "Колличество дописанных нулей: " << PrintByte(dopis) << endl;


				HemingMatr code = heming.coding(message);
				cout << "Закодированное сообщение: ";
				code.NTprintMatr();
				cout << endl;
				cout << "Итог: " << PrintByte(n) << PrintByte(dopis);
				code.NTprintMatr();
				cout << endl;
				cout << "Введите 1 для внесения ошибки\nили 0 для продолжения\n";
				int flag = 0;
				cin >> flag;
				if (flag) {
					int raz = -1;
					while (raz < 0) {
						cout << "Введите разряд в который хотите внести ошибку";
						cin >> raz;
						if (((raz - 1) < 0) || ((raz - 1) >= code.lenghtCode())) {
							cout << "Номер разряда выходит за границы";
							raz = -1;
						}
						else
							code[0][raz - 1] = !code[0][raz - 1];
					}
				}
				HemingMatr newMessage = heming.deCoding(code);
				newMessage.cut(dopis);
				cout << "Декодированное сообщение: ";
				newMessage.printMatr();
				cout << endl;
			}
			else {
				cout << "Введите m: ";
				int m;
				cin >> m;
				Heming heming = Heming(m);
				heming.printAllMatr();
				cout << "Введите длинну сообщения: ";
				size_t len;
				cin >> len;
				HemingMatr message = HemingMatr(1, len);
				message.inputMatr();

				uint8_t n = heming.getN();
				int k = n - m;
				uint8_t dopis = (k - message.lenghtCode() % k) % k;
				message.dopis(dopis);
				cout << "Код размера блока: " << PrintByte(n) << endl;
				cout << "Колличество дописанных нулей: " << PrintByte(dopis) << endl;
				HemingMatr code = heming.coding(message);
				cout << "Закодированное сообщение: ";
				code.NTprintMatr();
				cout << endl;
				cout << "Итог: " << PrintByte(n) << PrintByte(dopis);
				code.NTprintMatr();
				cout << endl;
			}
		}
		else {
			cout << "Введите сообщение: ";
			string message;
			cin >> message;
			string tmpN = "";
			string tmpDopis = "";
			string tmpMessage = "";
			for (int i = 0; i < 8; ++i) {
				tmpN += message[i];
				tmpDopis += message[i + 8];
			}
			for (int i = 16; i < message.length(); ++i)
				tmpMessage += message[i];
			uint8_t n = getMN(tmpN);
			uint8_t dopis = getMN(tmpDopis);
			HemingMatr code = HemingMatr(1, tmpMessage.length());
			code.inputMatr(tmpMessage);
			Heming heming = Heming(log2(n + 1));
			heming.printAllMatr();
			cout << "Размер блока: " << (int)n << endl;
			cout << "Колличество дописанных нулей: " << (int)dopis << endl;
			HemingMatr newMessage = heming.deCoding(code);
			newMessage.cut(dopis);
			cout << "Декодированное сообщение: ";
			newMessage.printMatr();
			cout << endl;
		}
	}
	system("pause");
}
