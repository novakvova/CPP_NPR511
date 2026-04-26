#include<iostream>
#include<Windows.h>
using namespace std;
//Прототип функції - приймає значення (int) і нічого не повертає
void changeValue(int); //при передачі параметра його значення буде копіюватися
void changeValueRef(int &); //при передачі параметра по силці - посилання на змінну
void changeValueRef(int&, int&); //Перегрузка функції - приймає два параметри по силці

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "--Передача параметрів у функцію--\n";
	int myValue = 10; //Змінна, яку ми будемо передавати у функцію
	//changeValue(myValue); //Передаємо значення змінної у функцію
	changeValueRef(myValue); //Передаю посилання на функцію
	cout << "Значення змінної після роботи функції "<< myValue <<"\n";
	int salo = 5, bread = 10;
	changeValueRef(salo, bread); //Передаю посилання на функцію
	cout << "Значення змінних після роботи функції: " << salo << ", " << bread << "\n";
}
void changeValue(int value) //Тут буде створено нову змінну value, яка є копією myValue з main
{
	value = 20; //У середині функції змінюємо значення параметра
	cout << "Значення у функції: " << value << endl;
}
void changeValueRef(int& value) //Тут буде створено посилання на змінну myValue з main, тому зміни в цій функції вплинуть на myValue
{
	value = 20; //У середині функції змінюємо значення параметра
	cout << "Значення у функції: " << value << endl;
}
void changeValueRef(int& a, int& b) //Перегрузка функції - приймає два параметри по силці
{
	a = 20; //У середині функції змінюємо значення першого параметра
	b = 30; //У середині функції змінюємо значення другого параметра
	cout << "Значення у функції: " << a << ", " << b << endl;
}