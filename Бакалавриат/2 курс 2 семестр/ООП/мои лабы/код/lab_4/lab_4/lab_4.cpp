#include <iostream>
#include <locale>
using namespace std;

class Rectangle {  //объявление класса
	int a, b;  //члены-данных (скрыты)

public:
	Rectangle(int A, int B) { a = A; b = B; }  //конструктор прямоугольника

	bool operator<(Rectangle op2); //перегрузка оператора меньше

Rectangle operator+(Rectangle op2); //перегрузка оператора бинарного сложения

	void show_rect() {cout << "(a = " << a << ", "<< "b = " << b << ")" << endl;} // вывод длин сторон прямоугольника
																				 // на экран
double perimeter() {return (2 * a + 2 * b);} // вычисление периметра прямоугольника

double area() {return (a * b);} //вычисление площади прямоугольника
};

bool Rectangle ::operator<(Rectangle op2) //перегрузка оператора меньше
{
	if (area() < op2.area()) //если площадь одного прям. < второго
		return true;
	else
		return false;
}

Rectangle Rectangle ::operator+(Rectangle op2) //перегрузка оператора бинарного сложения
{
	Rectangle c(0,0);
	c.a = a + op2.a;
	c.b = b + op2.b;
	return c;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Rectangle q(1, 5); //объявление переменной типа класс
	q.show_rect(); //вывод длин сторон прямоугольника

cout << "Периметр = " <<  q.perimeter() << endl; //вывод периметра прямоугольника
cout << "Площадь = " << q.area() << endl; //вывод площади прямоугольника

	Rectangle rect1(1 , 3); //объявление переменных типа класс
	Rectangle rect2(2, 4); //объявление переменных типа класс

	cout << "Прямоугольники:" << endl;
	rect1.show_rect(); //вывод длин сторон прямоугольника
	rect2.show_rect(); //вывод длин сторон прямоугольника

	cout << "бинарное сложение rect1 и rect2: ";
	(rect1 + rect2).show_rect(); 

	if (rect1 < rect2) //сравнение площадей прямоугольника
		cout << "rect1 меньше по площади rect2" << endl;
	else
		cout << "rect1 не меньше rect2" << endl;

	return 0;
}
 
