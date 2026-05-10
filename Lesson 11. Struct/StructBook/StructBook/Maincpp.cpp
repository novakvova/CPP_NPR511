#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

struct MyBook
{
	char author[80]; // автор нижки
	char name[80]; // назва книжки
	int pages; // кількість сторінок у книжці
	double rating; // рейтинг книги
};

//Напишемо функцію, яка виводить на екран інформацію про книгу
void displayBook(MyBook); // приймає певну книгу для виводу.

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "Наша бібліотека :)\n";

	MyBook aspnet; // це буде книжка ASP.NET
	strcpy_s(aspnet.author, "Ствін Сандерсо, Адам Фрімен");
	strcpy_s(aspnet.name, "ASP.NET MVC Core 2.0. Entity Framework. Pro");
	aspnet.pages = 823;
	aspnet.rating = 4.9;

	MyBook cppPrata;
	strcpy_s(cppPrata.author, "Стивен Прата");
	strcpy_s(cppPrata.name, "С++. Лекції та вправи");
	cppPrata.pages = 1487;
	cppPrata.rating = 5.0;

	cout << "Книги для вивчення:\n";
	displayBook(aspnet); //передаємо у функцію змінну asp.net - яка копіюється
	cout << "\n";
	displayBook(cppPrata);
	return 0;
}

void displayBook(MyBook book)
{
	cout << "--------------------------\n";
	cout << "Назва: " << book.name << endl;
	cout << "Автор: " << book.author << endl;
	cout << "Рейтинг: " << book.rating << endl;
	cout << "Сторінки: " << book.pages << endl;
	cout << "--------------------------\n";
}
