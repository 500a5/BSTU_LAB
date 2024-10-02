#include <iostream>
#include <locale.h>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;


struct Person {
	string name;
	int age;
	int marks[4];
	Person() {};

	friend bool operator < (const Person p1, const Person p2);
	friend bool operator > (const Person p1, const Person p2);
	friend bool operator == (const Person p1, const Person p2);
	friend bool operator != (const Person p1, const Person p2);
	friend bool operator <= (const Person p1, const Person p2);
	friend bool operator >= (const Person p1, const Person p2);
	friend ostream& operator<<(ostream& out, const Person& p);
};

//класс для отслеживания исключительных ситуаций списка
class DLSException : public exception {

	string mesError;
public:
	DLSException(string _mes) : mesError(_mes) {};
	~DLSException() = default;
	const char* what() { return mesError.c_str(); };
};

//Исключительная ситуация - списк пуст
class EmptyDList : public DLSException {
public:
	EmptyDList() : DLSException("Список пуст!") {};
};

//Исключительная ситуация - конец списка
class EndDList : public  DLSException {
public:
	EndDList() : DLSException("Переполнение списка!") {};
};

template<class Type>

class DList   //Создаем тип данных Список
{
	size_t size;
	struct Node       //Структура являющаяся звеном списка
	{
		Type x;     //Значение x будет передаваться в список
		Node* next, * prev; //Указатели на адреса следующего и предыдущего       элементов списка
	};

	Node* head, * tail; //Указатели на адреса начала списка и его конца
public:
	DList()
	{
		head = NULL;
		tail = NULL;
	}

	Node* temp;
	bool endList() { return (temp == NULL); }
	bool emptyList() { return (head == NULL); }

	void addNode(Type x)
	{
		temp = new Node; //Выделение памяти под новый элемент структуры

		if (endList())			//если конец
			throw EndDList();

		temp->next = NULL;  //Указываем, что изначально по следующему    адресу пусто
		temp->x = x; //Записываем значение в структуру

		if (head != NULL) //Если список не был пуст
		{
			temp->prev = tail; //Указываем адрес на предыдущий элемент в соотв. поле
			tail->next = temp; //Указываем адрес следующего за хвостом элемента
			tail = temp; //Меняем адрес хвоста
		}
		else //Если список был пустым
		{
			temp->prev = NULL; //Предыдущий элемент указывает в пустоту
			head = tail = temp;  //Голова=Хвост=тот элемент, что сейчас добавили
		}
	}

	void show() //вывод списка на экран
	{
		if (emptyList())
			throw EmptyDList();

		temp = head; //Временно указываем на адрес первого элемента
		while (!endList()) //Пока не встретим пустое значение
		{
			cout << temp->x << endl; //Выводим каждое считанное значение на экран
			temp = temp->next; //Смена адреса на адрес следующего элемента
		}
	}

	bool inList(Type el) //проверка, есть ли элемент в списке
	{
		temp = head; //Временно указываем на адрес первого элемента
		while (!endList()) //Пока не встретим пустое значение
		{
			if (temp->x == el)
				return true;
			temp = temp->Next;
		}
		return false;
	}

	void getListPost(Type* E) //исключить элемент после рабочего указателя
	{
		if (emptyList())		//если пуст
			throw EmptyDList();

		Node* pntr;
		pntr = temp->next; //запоминаем извлекаемый элемент

		pntr->next->prev = temp; //предыдущий для следующего элемента за извлекаемым - текущий указатель

		temp->next = pntr->next; //следующий для текущего - следующий для извлекаемого элемент.

		*E = pntr->x;

		pntr->next = NULL; //извлекаемый элемент ни на что не указывает
		pntr->prev = NULL;

		free(pntr);
	}

	template<class Type>
	void insertBeforeElement(DList* list, Node* elm, Type* value) {
		Node* ins = NULL;
		if (emptyList())
			throw EmptyDList();


		if (!elm->prev) {
			addNode(value);
			return;
		}
		ins = (Node*)malloc(sizeof(Node));
		ins->value = value;
		ins->prev = elm->prev;
		elm->prev->next = ins;
		ins->next = elm;
		elm->prev = ins;

	}


	void insertionSort(DList** list, int (*cmp)(void*, void*)) {
		DList* out = DList();
		Node* sorted = NULL;
		Node* unsorted = NULL;

		unsorted = (*list)->head;
		while (unsorted) {
			sorted = out->head;
			while (sorted && !cmp(unsorted->value, sorted->value)) {
				sorted = sorted->next;
			}
			if (sorted) {
				insertBeforeElement(out, sorted, unsorted->value);
			}
			else {
				addNode(unsorted->value);
			}
			unsorted = unsorted->next;
		}

		free(*list);
		*list = out;
	}


	~DList() //Деструктор
	{
		while (head) //Пока по адресу на начало списка что-то есть
		{
			tail = head->next; //Резервная копия адреса следующего звена списка
			delete head; //Очистка памяти от первого звена
			head = tail; //Смена адреса начала на адрес следующего элемента
		}
	}

};

bool operator < (const Person p1, const Person p2) {
	if (p1.name != p2.name)
		return p1.name < p2.name;
	else {
		if (p1.age != p2.age)
			return p1.age < p2.age;
		for (int i = 0; i < 4; i++)
			if (p1.marks[i] != p2.marks[i])
				return p1.marks[i] < p2.marks[i];
	}
	return false;
}

bool operator > (const Person p1, const Person p2) {
	if (p1.name != p2.name)
		return p1.name > p2.name;
	else {
		if (p1.age != p2.age)
			return p1.age > p2.age;
		for (int i = 0; i < 4; i++)
			if (p1.marks[i] != p2.marks[i])
				return p1.marks[i] > p2.marks[i];
	}
	return false;

}

bool operator == (const Person p1, const Person p2) {
	if (p1.name != p2.name)
		return false;
	else {
		if (p1.age != p2.age)
			return false;
		for (int i = 0; i < 4; i++)
			if (p1.marks[i] != p2.marks[i])
				return false;
	}
	return true;
}

bool operator != (const Person p1, const Person p2) {
	return !(p1 == p2);
}

bool operator <= (const Person p1, const Person p2) {
	return (p1 < p2) || (p1 == p2);
}

bool operator >= (const Person p1, const Person p2) {
	return (p1 > p2) || (p1 == p2);
}

ostream& operator<< (ostream& out, const Person& p) {
	out << "Last Name: " << p.name << " | Age: " << p.age << " | Marks: ";
	for (auto mark : p.marks)
		out << mark << " ";
	out << endl;
	return out;
}

void personsToFile(size_t n) {
		FILE* f = NULL;
		fopen_s(&f, "persons.bin", "wb");
		if (f == NULL) throw EndDList();
		for (size_t i = 0; i < n; i++) {
			Person a;
			cout << "ENTER Last Name: "; cin >> a.name;
			cout << "ENTER Age: "; cin >> a.age;
			cout << "ENTER 4 marks: ";
			for (int i = 0; i < 4; i++)
				cin >> a.marks[i];
			fwrite(&a, sizeof(Person), 1, f);
			cout << "+=============================================================+" << endl;
		}
		fclose(f);
}


int main()
{
	setlocale(LC_ALL, "rus");
	personsToFile(3);
	try {
		FILE* f = NULL;
		fopen_s(&f, "persons.bin", "rb");
		DList<Person> x;
		Person a;
		while (fread_s(&a, sizeof(a), sizeof(Person), 1, f))
			x.addNode(a);
		fclose(f);
		x.show();
	}
	catch (DLSException *e) {
		e->what();
	}

	return 0;
}

