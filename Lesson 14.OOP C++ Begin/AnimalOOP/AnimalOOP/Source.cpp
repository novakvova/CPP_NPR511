#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

class Animal
{
private:
	char name[80]; //Назва
	char breed[50]; //Порода тварини
	int age; //Вік тварини
	double weight; //Вага тварини
public:
	//Для початкової ініалізації об'єкта потірбно будувати конструктор
	//Конструктор співпадає із назвою класу
	//Цей конструктор - по замовчюванню - викликається автоматично
	Animal() //Це Метод класу, але він є спеціальний і зветься конструктор
	{
		strcpy_s(name, "Назва_тварини");
		strcpy_s(breed, "Порода_тварини");
		age = 0;
		weight = 0;
	}
	//Давайте зробимо конструктора за параметрами
	Animal(const char *name, const char *breed,
		int age, double weight) //Це прегружений коструктор - як функція - але це метод
	{
		//Для вирішення проблеми, коли змінна яка приходить
		//співпадає із зміною, яка в класі, використовуємо слова this
		strcpy_s(this->name, name);
		strcpy_s(this->breed, breed);
		this->age = age;
		this->weight = weight;
	}

	void print()
	{
		cout << "Назва: " << name << "\n";
		cout << "Порода: " << breed << "\n";
		cout << "Вік: " << age << "\tВага: " << weight << "\n";
	}
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "-----Буде працювати із котиками----\n";

	//Тут автоматично визивається конструкто по замовчуванню
	Animal barsyk; //змінні звуться з малої букви - так само об'єкти
	barsyk.print();

	cout << "\n-------Конструктор з параметрами---------\n";
	//Викликаємо коснтруктор з параметрами
	Animal miniPigValera("Валера","Міні Піг", 4, 80);
	miniPigValera.print();

}