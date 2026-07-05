#include<iostream>
#include<Windows.h>
using namespace std;
//Templates - можливість передавати у клас змінні потрібно для Вас типу
//При стоворені об'єкта класу можна вказати тип даних з яким буде праюцвати клас
//Для цього використовується слово template
//Ми вказуємо, до даний клас може буде шаблоним, тобто приймати певний
//тип, який буде вказувати користувач - Формально це - MyType 
//MyType - int, string, double, ....

template <typename MyType> class Point {
private:
	MyType x; //Тепер дані змінні буду нашого типу
	MyType y; //який вкаже користувач

public:
	Point()	{ x = y = 0; }
	Point(MyType x, MyType y) { this->x = x; this->y = y; }
	void Show() { cout << "x = " << x << "\ty = " << y << "\n"; }
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "----------Використання Templates-----------\n";
	//Point<int> p(12,-3); //MyType - у нас int
	//Point<double> p(12.3,-3.5); //MyType - у нас double
	Point<string> p("Сало", "Цибуля"); //MyType - у нас string
	//Point<char> p('a', 't'); //MyType - у нас char
	p.Show();
	return 0;
}