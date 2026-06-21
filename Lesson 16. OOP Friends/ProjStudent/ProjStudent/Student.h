#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Student
{
private:
	string name;
	string phone;
	int age;

public:
	Student() //по замовчуванню
	{
		this->name = "";
		phone = "";
		this->age = 18;
	}
	//Конструктор з параметрами
	Student(const string name, const string phone, const int age)
	{
		this->name = name;
		this->phone = phone;
		this->age = age;
	}
	//конструктор копіювання
	Student(const Student& s)
	{
		this->name = s.name;
		this->phone = s.phone;
		this->age = s.age;
	}

	void print()
	{
		cout << "Name = " << this->name << "\n";
		cout << "Phone = " << this->phone << "\n";
		cout << "Age = " << this->age << "\n";
	}

	//Хочу зробити дружні метод і подружити наш клас
	//Student із cout - але cout - це ostream Клас
	friend ostream& operator<<(ostream & out,
		const Student & s) //приймаєо потік і студент
	{
		out << s.name << "\t" << s.phone
			<< endl << "Вік: " << s.age;
		return out;
	}
	
	
	//Давайте подружимо Student із cin,
	//але cin - istream - це така особливість
	friend istream& operator>>(istream& in,
		Student& s) //приймаєо потік і студент
	{
		in.seekg(0); //якщо у потоці були дані ми їх ігноруємо
		char tmp[100]; //для вводу даних із клавіатури

		cout << "Вкажіть ім'я: ";
		in.getline(tmp, 100, '\n');
		string str = tmp;
		if (!str.empty())
			s.name = tmp;

		cout << "Вкажіть телефон: ";
		in.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			s.phone = tmp;

		cout << "Вкажіть вік: ";
		in>>s.age;

		return in;
	}

	//Якщо працюю у із файлами, то пококти називаються
	//ifstream - для читання
	//ofstream - для запису

	friend ofstream& operator<<(ofstream& fout,
		const Student& s) //приймаєо потік і студент
	{
		fout << s.name << "\n" 
			<< s.phone << '\n'
			<< s.age << '\n';
		return fout;
	}

	friend ifstream& operator>>(ifstream& fin,
		Student& s) //приймаєо потік і студент
	{
		char tmp[100]; //для вводу даних із клавіатури
		fin.getline(tmp, 100, '\n');
		string str = tmp;
		if (!str.empty())
			s.name = tmp;
		fin.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			s.phone = tmp;
		fin >> s.age;
		fin.getline(tmp, 100, '\n'); //Щоб у потоці не лишилося \n
		return fin;
	}
};

