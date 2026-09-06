#include<iostream>
#include<Windows.h>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Створили персону\n";
	}
};
class Faculty : virtual public Person //Віртуальний базовий клас. Вирішує проблему ромба
{
public:
	Faculty()
	{
		cout << "Створили факультет\n";
	}
};
class Student : virtual public Person //Віртуальний базовий клас. Вирішує проблему ромба
{
public:
	Student() 
	{
		cout << "Створили студента\n";
	}
};

class TA : public Faculty, Student
{
public:
	TA()
	{
		cout << "TA констуруктор\n";
	}
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "--Віртуальний базовий клас--\n";
	//Person p;
	//Faculty f;
	//Student s;
	//----Тут викникає проблема при ромбовидному наслідуванні------
	TA ta;

	return 0;
}