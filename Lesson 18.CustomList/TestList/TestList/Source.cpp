#include<iostream>
#include<Windows.h>
#include<string>
#include "MyList.h"
#include "People.h"
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "------Робота із власними списками------\n";
	//MyList<int> people;
	//people.Add(19);
	//people.Add(21);
	//people.Add(17);
	//people.ShowItems(); // показати, що є у списку
	//MyList<People> myFriends;
	//myFriends.Add(People("Потап Максим", "+38 096 89 78 785", 23));
	//myFriends.Add(People());
	//myFriends.ShowItems();

	MyList<People> items;
	int action = 0;
	do
	{
		cout << "Оберіть операцію:\n";
		cout << "0.Вихід\n";
		cout << "1.Додати нового\n";
		cout << "2.Показати усіх козаків\n";
		cout << "->_";
		cin >> action;
		cin.ignore(); // чистимо буфер вводу
		switch (action)
		{
		case 1:
		{
			string name, phone;
			int age;
			cout << "Вкажіть ПІБ: ";
			getline(cin, name);
			cout << "Вкажіть телефон: ";
			getline(cin, phone);
			cout << "Вкажіть вік: ";
			cin >> age;
			items.Add(People(name, phone, age));
			break;
		}
		case 2:
		{
			cout << "---------Ваші козаки і козачки :)----------\n";
			items.ShowItems();
			break;
		}
		}

	} while (action != 0);

	return 0;
}