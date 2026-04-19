#include<iostream>
#include<Windows.h>
using namespace std;

// Ліній пошук (Linear Search) - це простий алгоритм пошуку, який послідовно перевіряє кожен елемент у колекції, доки не знайде шуканий елемент або не досягне кінця колекції. Лінійний пошук має часову складність O(n), де n - кількість елементів у колекції. Він ефективний для невеликих колекцій або коли дані не відсортовані.
void searchExample();
//функція пошуку
//1 - масив, у якому шукаємо
//2 - розмір масиву
//3 - елемент, який шукаємо
int linearSearch(double[], int size, double);

int main() 
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//cout << "Привіт! Класна погода :)\n";
	//Туту буде робити пошук ціни по АЗК
	searchExample();
	return 0;
}
void searchExample() 
{
	//масив із цінами на пальне
	double okko[] = {49.0, 75.0, 78.0, 85.0, 89.9, 92.9};
	double sokar[] = {49.98, 74.99, 78.99, 84.99, 89.99, 92.99};
	cout << "Введіть ціну, яку хочете знайти: ";
	double price = 0.0;
	cin >> price;
	int result = linearSearch(okko, 6, price);
	if (result != -1) {
		cout << "Ціна " << price 
			<< " знайдена на заправці OKKO під індексом " 
			<< result << ".\n";
	} else {
		cout << "Ціна " 
			<< price 
			<< " не знайдена на заправці OKKO.\n";
	}
}

//Шукає ідекс елемента, який співпадає з target
//index - номер елемента у масиві починаючи з 0
//якщо повертає -1 - елемент не знайдено
int linearSearch(double arr[], int size, double target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) { //перевірка співпадіння
			return i; // Повертаємо індекс знайденого елемента
		}
	}
	return -1; // Повертаємо -1, якщо елемент не знайдено
}