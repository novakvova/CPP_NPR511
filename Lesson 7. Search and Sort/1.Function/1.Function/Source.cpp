#include<iostream>
#include<Windows.h>
#include<cmath> //математична бібліотека - має різні функції
using namespace std;
//Функції з параметрами
//Також функція буде повертати значення
//Формальні парметри та фактичні параметри
//Формальні параметри - це ті, які вказані в оголошенні функції
//Фактичні параметри - це ті, які передаються при виклику функції

//Прототип функції - це оголошення функції без її тіла
int SumArray(int[], int); //Приймає масив та ціле число

//підносить число до степеня, який ми вказуємо
double MyPow(double, int); //double - число яке підносимо до степеня, int - степінь

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	//endl - перевід на новий рядок,як \n, але з очищенням буфера виводу
	cout << "Робота з функція!" << endl; 
	int apples[] = { 1, 12, 8, 7, 16 }; //Масив з 5 елементів
	//SumArray - це ім'я функції, apples - це фактичний параметр, 5 - це фактичний параметр
	int result = SumArray(apples, 5); //Виклик функції SumArray, передаємо масив та його розмір
	cout << "Сума елементів масиву: " << result << "\n";

	double powResult = MyPow(3.5, 4);
	cout << "3.5 піднесене до степеня 4: " << powResult << "\n";

	double mathPowResult = pow(2.2, 4); // Використання функції pow з бібліотеки cmath
	cout << "2.2 піднесене до степеня 4 (cmath): " << mathPowResult << "\n";
	return 0;
}

int SumArray(int arr[], int size) //масив - це arr[], size - розмір його
{
	int sum = 0; // Сума елементів на початку 0
	for (int i = 0; i < size; i++) //Ідемо по елементах масиву від 0 до size-1
	{
		sum += arr[i]; //sum = sum + arr[i]; Додаємо кожен елемент масиву до суми
	}
	return sum; //Повертаємо суму елементів масиву - результат роботи функції
}

double MyPow(double input, int step)
{
	double result = input; // відразу фуксую 1 супінь
	for (int i = 1; i < step; i++)
	{
		result *= input; // result = result * input; Підносимо число до степеня
	}
	return result; //Повертаємо результат піднесення до степеня
}