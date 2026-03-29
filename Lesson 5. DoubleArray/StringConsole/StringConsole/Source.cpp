#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "Привіт класний день :) 💬" << endl;
	//Працює аналогічно як масив цілих чисел
	char str[100]; // одномірний масив із симоволів
	cout << "Як Вас завати: ";
	//Вводимо рядок із консолі. Використовуємо функцію getline
	cin.getline(str, 100); // зчитуємо рядок з консолі і записуємо його в масив str
	//ось так можна виводити масив символів на екран
	//cout - вміє сам перебирати масив символів і виводити його
	cout << "Привіт " << str << endl;
	return 0;
}


//#include <iostream>
//#include<Windows.h>
//using namespace std;// можна писати тут
//int main()
//{
//	SetConsoleOutputCP(65001);
//	SetConsoleCP(65001);
//	cout << " Масив із символів \n";
//	char str[100]; // масив із символів працює із символів
//	cout << " Введіть  ваше іммя: ";
//	//Вводимо рядок в консолі
//	cin.getline(str, 100);
//
//	cout << "Привіт " << str << endl;
//	return 0;
//}
