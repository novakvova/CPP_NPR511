#include<iostream>
#include<Windows.h>
#include<vector>
using namespace std;

//Композиція - коли 1 клас включає в себе інший класа - його об'єкт
//Тобто клас, який включає в себе інший клас без нього не може існувати.
class Engine {
public:
	void start()
	{
		cout << "Двигун заведено\n";
	}
};
class Car {
private:
	Engine engine;
public:
	void start()
	{
		engine.start(); //Пряма залежність від класу, який входу у Car
	}
};

//Агрегація об'єк входить в інший клас, але при цьому може
//існувати незалежно
class Student
{
private:
	string name;
public:
	Student(string n) : name(n) {}
	void info()
	{
		cout << "ПІБ: " << name << "\n";
	}

	void setName(string name)
	{
		this->name = name;
	}
};

class Group
{
private:
	vector<Student*> students; //набір студентів - динамічний масив
public:
	void addStudent(Student*s)
	{
		students.push_back(s);
	}
	void viewList()
	{
		for (Student* s : students)
		{
			s->info(); //Показуємо інфомрацію про певного студента в групі
		}
	}
};


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "--- Композиція ---\n";
	//Car car;
	//car.start();

	cout << "-- Агрегація --\n";
	Student peter("Мельник Петро Васильович");
	Student vova("Салько Володимир Павлович");
	Student oleh("Жгут Олег Юзікович");
	Group g;
	g.addStudent(&peter);
	g.addStudent(&vova);
	g.addStudent(&oleh);
	cout << "Група студентів\n";
	g.viewList();

	vova.setName("Рябий Валерій Маркович");

	cout << "--У студента змінилася інфомрація--\n";
	g.viewList();
	return 0;
}