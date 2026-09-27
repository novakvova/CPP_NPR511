#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "Праціює із вкилюченнями" << endl;
	double a, b;
	cout<<"Введіть значення a: ";
	cin>>a;
	cout<<"Введіть значення b: ";
	cin>>b;
	try
	{
		if (b == 0)
		{
			//cout << "Ділення на 0 не можна проводити\n";
			throw "Ділення на 0 не можливо\n"; //кажемо, що програма генерує виключення
		}
		double c = a / b;
		cout << "a/b = " << c << "\n";
	}
	catch (const char* text) //Якщо виникала помилка
	{
		cout << "Сталася Халепа Хюстон -- " << text;
	}

	cout<< "Програма завершила свою роботу ПАПА\n";
	return 0;
}
