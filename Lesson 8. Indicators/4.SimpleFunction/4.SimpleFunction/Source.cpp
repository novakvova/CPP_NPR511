#include<iostream>
#include<Windows.h>
using namespace std;
//якщо число від'ємне, то воно буде додатнє
//Якщо воно додатнє, то буде без змін
void Abs(int &a); // робить модуль числа
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "--Використання фукнці із вказівниками та посиланнями--\n";
	int p = -5;
	cout << "Адреса числа p: " << &p << "\n";
	Abs(p); // тут не буде робитися копія числа, а беремо адресу
	cout << "Модуль числа: " << p << endl;
}
void Abs(int &a)
{
	cout << "Адреса числа а у функції: " << &a << "\n";
	if (a < 0)
		a = -a;
}