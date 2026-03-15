#include<iostream>
#include<Windows.h>

int main()
{
	using namespace std;
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	cout << "--- Працюємо із циклом do while ---\n";
	//do while - цикл з передумовою
	//спочатку іде тіло циклу, а потім перевіряється умова продовження циклу
	//Можна робите мені із вибором операцій
	int action = 0; // 0 - вихід із програми
	do
	{
		cout << "0.Вихід\n";
		cout << "1.Показати користувачів\n";
		cout << "2.Додавати нового користувача\n";
		cout << "->_";
		cin >> action;
		if (action == 1) {
			cout << "+++ Список користувачів виводимо +++\n";
		}
		else if (action == 2)
		{
			cout << "==== Додаємо нового користувача ====\n";
		}
		else
		{
			if (action != 0)
				cout << "--- Вказали не вірну операцію ---\n";
		}
	} while (action != 0);

	return 0;
}