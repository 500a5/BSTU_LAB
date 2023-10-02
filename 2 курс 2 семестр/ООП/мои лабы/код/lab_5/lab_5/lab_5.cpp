
#include <iostream>
#include <string>
using namespace std;

class Client
{
public:
	
	virtual void print_inf()=0;
	virtual void search_client(string)=0;
	

};


class Creditor : public Client
{
	string surname;
	string date_give_credit;
	double size_credit;
	double perecent_credit;
	double balance_credit;

public:
	Creditor(string surname, string date_give_credit, double size_credit, double perecent_credit, double balance_credit) {
		this->surname = surname;
		this->date_give_credit = date_give_credit;
		this->size_credit = size_credit;
		this->perecent_credit = perecent_credit;
		this->balance_credit = balance_credit;
	};
	void print_inf() {
		cout << "Фамилия " << surname << endl;
		cout << "Дата взятия кредита " << date_give_credit << endl;
		cout << "Размер кредита " << size_credit << endl;
		cout << "Процент по кредиту " << perecent_credit << endl;
		cout << "Остаток по кредиту " << balance_credit << endl;
		cout << endl << "-------------------------------------------" << endl;
	}
	void search_client(string date) {
		if (date == date_give_credit) {
			cout << "Клиент " << surname << " взял кредит в банке в этот: " << date_give_credit << " день" << endl;
		}
		else
		{
			//cout << "В этот день ничего не произошло";
		}
	}

	//~Creditor();

};

class Contributor : public Client
{
	string surname;
	string date_open_contribution;
	double size_contribution;
	double perecent_contribution;
public:
	Contributor(string surname, string date_open_contribution, double size_contribution, double perecent_contribution) {
		this->surname = surname;
		this->date_open_contribution = date_open_contribution;
		this->size_contribution = size_contribution;
		this->perecent_contribution = perecent_contribution;
	};
	void print_inf() {
		cout << "Фамилия " << surname << endl;
		cout << "Дата открытия вклада " << date_open_contribution << endl;
		cout << "Размер вклада " << size_contribution << endl;
		cout << "Процент по вкладу " << perecent_contribution << endl;
		cout << endl << "-------------------------------------------" << endl;
	}
	void search_client(string date) {
		if (date == date_open_contribution) {
			cout << "Клиент " << surname << " положил деньги в банке в этот: " << date_open_contribution << " день" << endl;
		}
		else
		{
		//	cout << "В этот день ничего не произошло";
		}
	}
	//~Contributor();

};

class Organization : public Client
{
	
	string name;
	string date_open_score;
	int namper_score;
	double money_in_scor;
public:
	Organization(string name, string date_open_score, int namper_score, double money_in_scor) {
		this->name = name;
		this->date_open_score = date_open_score;
		this->namper_score = namper_score;
		this->money_in_scor = money_in_scor;
	};
	void print_inf() {
		cout << "Название организации " << name << endl;
		cout << "Дата открытия счета " << date_open_score << endl;
		cout << "Номер счета " << namper_score << endl;
		cout << "Денег на счете " << money_in_scor << endl;
		cout << endl << "-------------------------------------------"<< endl;
	}
	void search_client(string date) {
		if (date == date_open_score) {
			cout << "Организация " << name << " открыла счет в банке в этот: " << date_open_score << " день" << endl;
		}
		else
		{
		//	cout << "В этот день ничего не произошло";
		}
	}
	//~Organization();

};


int main()
{
	setlocale(LC_ALL, "rus");
	const int N = 6;
	Client** arr = new Client * [N];
	string Date;

	arr[0] = new Organization("Apple", "24.05.2012", 45785468, 11045455544544);
	arr[1] = new Organization("Tecла", "22.11.2011", 43785788, 412245);
	arr[2] = new Contributor("Иванов", "12.11.2018", 10000.5 ,7.5);
	arr[3] = new Contributor("Петров", "18.01.2019",  10000000.5, 6.5);
	arr[4] = new Creditor("Ушков", "12.11.2018",  5110000, 6.5,56200);
	arr[5] = new Creditor("Носов", "22.10.2014", 511000000, 6.5, 1256200);
	for (size_t i = 0; i < N; i++)
	{
		arr[i]->print_inf();
	}

	cout << "Введите дату для поиска" << endl;
	cin >> Date;
	for (size_t i = 0; i < N; i++)
	{
		arr[i]->search_client(Date);

	}

	for (size_t i = 0; i < N; i++)
	{
		delete arr[i];
	}
	delete arr;

	return 0;
}
