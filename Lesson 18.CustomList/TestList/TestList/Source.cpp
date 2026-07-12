#include<iostream>
#include<Windows.h>
#include<string>
#include "MyList.h"
#include "People.h"
using namespace std;

void menu(); //робота із користувачами

void sortInt();

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

	//Перевіряю оператор >
	//People matviy("Матвій Олегович", "098 78 78 654", 18);
	//People maria("Рошко Марія", "063 89 54 658", 16);
	//People svitlana("Юрчук Світлана", "063 89 54 658", 16);

	//if (matviy > maria)
	//	cout << "matviy > maria\n";
	//else
	//	cout << "matviy <= maria\n";
	//if (svitlana > maria)
	//	cout << "svitlana > maria\n";
	//else
	//	cout << "svitlana <= maria\n";
	
	//Перевіряю роботу Size
	//MyList<People> items;
	////cout << "items size = " << items.Size() << "\n";
	//items.Add(People("Юрчук Світлана", "063 89 54 658", 16));
	//items.Add(People("Матвій Олегович", "098 78 78 654", 18));
	//items.Add(People("Мельник Альчік", "098 89 45 231", 12));
	//items.Add(People("Хомко Христина", "067 78 45 125", 22));
	//items.Add(People("Адам Матвій", "066 78 55 785", 14));
	//cout << "items size = " << items.Size() << "\n";
	//cout << "-----Список елемнетів------\n";
	//items.ShowItems();
	//items.Sort();
	//cout << "++++++++Сортований список++++++++\n";
	//items.ShowItems();

	//sortInt();
	//робота з користучами
	menu();

	return 0;
}

void menu()
{
	MyList<People> items;
	int action = 0;
	do
	{
		cout << "Оберіть операцію:\n";
		cout << "0.Вихід\n";
		cout << "1.Додати нового\n";
		cout << "2.Показати усіх козаків\n";
		cout << "3.Сортувати список\n";
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
		case 3:
		{
			items.Sort(); // виконуємо сортування
			cout << "----Список відсортовано :)-----\n";
			break;
		}
		}

	} while (action != 0);
}

void sortInt()
{
	int list[5] = { 12, 33, 4, 1, 8 };
	int n = 5; // 5 елементів у масиві
	cout << "Список елементів\n";
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << "\t";
	}
	cout << "\n";
	//сортую список
	for (int i = 0; i < n - 1; i++) //іду до n-1
	{
		for (int j = i + 1; j < n; j++) //на i позицію буде ставити найменший
		{
			if (list[i] > list[j])
			{
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp; //переставляємо елементи місцями
			}
		}
	}
	cout << "Сортований список елементів\n";
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << "\t";
	}
}