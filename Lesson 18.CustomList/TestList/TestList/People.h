#pragma once

#include<iostream>
using namespace std;

class People
{
private:
	string name; //ПІБ
	string phone; //Телефон
	int age; //Вік

public:
	People()
	{
		this->name = "Не вказано";
		this->phone = "+380";
		this->age = 18;
	}
	People(const char* name, const char* phone, int age)
	{
		this->name = name;
		this->phone = phone;
		this->age = age;
	}
	People(const string name, const string phone, int age)
	{
		this->name = name;
		this->phone = phone;
		this->age = age;
	}

	friend ostream& operator<<(ostream& os, const People& people)
	{
		os << people.name << "\t" << people.phone << "\t"
			<< people.age;
		return os;
	}
	//people - це об'єкт - який буде з правого боку від >
	bool operator>(const People& people)
	{
		if (this->name > people.name)
			return true;
		return false;
	}
};