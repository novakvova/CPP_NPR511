#include<iostream>
#include<vector> //для роботи з масивами, STL
#include<algorithm> //містить допоміжні методи для STL
#include<Windows.h>
using namespace std;

void print(const vector<int>& data) //& посилання на змінну data
{
	for (auto item : data) // автоматично буде підставляти int замість auto
	{
		cout << item << "\t";
	}
	cout << "\n";
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "--Працюєм із STL--\n";
	//Динамічний масив
	vector<int> numbers{ 12, 8, 1, 7, 5, 34, 5, 2, 1};

	//Виведемо елементи на екран - новий спосіб
	for (int item : numbers)
	{
		cout << "item = " << item << "\n";
	}
	cout << "Вивід елементів через ітератор:\n";
	//Ітератор - це вказвник на елемент у списку numbers
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		//it - це вказівник, it++ - перехід на наступний елемент списку
		cout << *it << "\t";
	}

	//vector динамічна колекція - push_back() - додати елемент у кінець
	numbers.push_back(-6);
	cout << "\n\nДодаю новий елемент у список -6\n";
	//for (int item : numbers)
	//{
	//	cout << item << "\t";
	//}
	//cout << "\n";
	print(numbers);

	cout << "Видалення елемента із списку '1'\n";
	int remove = 1; // будемо видаляти із списку

	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		if (*it == remove)
		{
			numbers.erase(it);
			break;
		}
	}
	print(numbers);

	//Пошук за допомогою find
	int itemFind = 5;
	//Буде створено новий ітератор - який містить резульат пошуку
	auto result { find(begin(numbers), end(numbers), itemFind) };
	cout << "Результат пошуку '5'\n";
	//Позиція знайденого елемента
	if (result != numbers.end()) //Це перевірка чи ми знайшли елемент у списку
	{
		int position = result - numbers.begin(); //ідекс у масиві
		cout << "Позиція знайденого елемента: " << position << endl;
		cout << "Значення елемента: " << numbers[position] << endl;
	}
}