#include<iostream>
#include<Windows.h>
#include<ctime>
using namespace std;
#include"Matrix.h" //Підключаємо наш файл із кодом :)

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//Робимо початкову ініціалізацію Random
	srand(time(0)); //Надає початкове значення поточний час

	cout << "----Робота з матрицями :)----\n";
	Matrix a; //Викликаємо автоматично конструктор по замовчуванню
	a.initRandom(); //Заповняє матрицю рандомними числами від 0 до 99
	cout << "\n----Matrix A-----\n";
	a.print();

	Matrix b(3,3); //Матриця 3х3
	b.initRandom(); //Заповняє матрицю рандомними числами від 0 до 99
	cout << "\n----Matrix B-----\n";
	b.print();

	Matrix c = b; //Створив с і у нього присвоїв b
	cout << "\n-----Matrix C-----\n";
	c.print(); // об'єкт с і метод print() - це метод

	Matrix d = c.plus(b); //Роблю додавання матриць
	cout << "\n-------B+C---------\n";
	//d.print();
	cout << d;

}