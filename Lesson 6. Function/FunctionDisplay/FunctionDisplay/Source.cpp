#include<iostream>
#include<Windows.h>
using namespace std;

void eat(); // У нас є прототип функції eat()
void test(); // У нас є прототип функції test()
//Дана функція буде у користувача запитувати інформацію
// і виводити її на екран
//Функція нічого не повертає, тому тип її - void
void setInfoUser();

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "Привіт! Це фукнція main()" << endl;
	//eat(); // Виклик функції eat()
	//test();
	setInfoUser();
	return 0;
}

void eat() // Це визначення функції eat()
{
	cout << "Добре їсти, добре спати" << endl;
	cout << "Має Бог доров'я дати!" << endl;
}

void test() // Це визначення функції test()
{
	cout << "Пасхалочка - це така чудовий вислів," << endl;
	cout << "Який може порадувати людину. Наприклад," << endl;
	cout << "six & seven або 6/7 - дуже добре. (100%)" << endl;
}

void setInfoUser() // Це визначення функції setInfoUser()
{
	char name[100]; // це масив із 100 символів
	int age;
	cout << "Введіть ваше ім'я: ";
	cin.getline(name,100); //вміє читати дані і записувати у масив
	cout << "Введіть ваш вік: ";
	cin >> age; //вводимо вік людини
	cout << "Привіт, " << name << "! Тобі " << age << " років." << endl;
}