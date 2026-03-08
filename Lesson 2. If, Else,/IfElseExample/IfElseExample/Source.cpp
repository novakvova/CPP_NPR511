#include<iostream>
#include<Windows.h>

int main()
{
	using namespace std;
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--Робота з оператором If Else--\n";
	//Оголошуємо змінні
	int a, b; //Оголосили 2 змінних a та b
	cout << "Введіть a = ";
	cin >> a; //очікує вводу цілого числа, якщо буде 5.27 - вводиться b уже не буде, бо int
	//cin.clear(); // якщо доробове число має проблеми із потоком.
	cout << "Введіть b = ";
	cin >> b;
	cout << "a = " << a << "\t" << "b = " << b << "\n";
	char ch; // Операція яку ми хочемо виконати +, -, /, *
	cout << "Вкажіть операцію(+,-,/,*): ";
	cin >> ch;
	//cout << "ch = " << ch << endl;
	double result=0; // буде зберігати результат операції
	if (ch == '+')
		result = a + b;
	else if (ch == '-')
		result = a - b;
	else if (ch == '/')
	{
		if (b == 0)
			cout << "Операція не можлива b == 0!\n";
		else
			result = a / (double)b; //для того, щоб було дробове ділимо на double
	}
	else if (ch == '*')
		result = a * b;
	else
		cout << "Ви обрали не доступну операцію :(\n";

	cout << "Результат операції = " << result << "\n";
	return 0;
}