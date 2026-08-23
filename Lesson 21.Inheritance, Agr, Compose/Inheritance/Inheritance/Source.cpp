#include<iostream>
#include<Windows.h>
using namespace std;

class Animal
{
protected:
	string name; //Назва тваринки
public:
	Animal() { name = "No name"; }
	//Animal(string n) : name(n) {}
	Animal(string n) { this->name = n; }
	void eat() //виводимо дію тварини
	{
		cout << name << " їсть\n";
	}
	virtual void makeSound() // Бажно для дочірніх класів даний метод перевизначати
	{
		cout << "Якийсь звук\n";
	}
};

class Dog : public Animal //ми наслідуємо public - методи в Dog будуть доступні
{
public:
	//Мені потрібно, для класа Animal ініціалізувати конструктор 
	//тобто надати значення для name у Animal
	Dog(string name) : Animal(name) { } //Викликає конструктор батьківського класу
	void makeSound() override
	{
		cout << name << " гавкає\n";
	}

};
//Єнот
class Raccoon : public Animal
{
public:
	Raccoon(string name) : Animal(name) {}
	void makeSound() override
	{
		cout << name << " муркає(Єнот)\n";
	}
};


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "--- Наслідування, Агренація і Композиція С++ ---\n";
	//Animal cat("Барсик");
	//cat.eat();
	//cat.makeSound();
	//Dog myDog("Жук");
	//myDog.makeSound();

	//Raccoon semen("Семен");
	//semen.makeSound();

	Animal *list[5]; // Тут ми проводимо виділення пам'яті для тварин
	list[0] = new Dog("Кусачий");
	list[1] = new Raccoon("Пухнатий");
	list[2] = new Raccoon("Славік");
	list[3] = new Dog("Мейсон");
	list[4] = new Dog("Шарик");

	for (int i = 0; i < 5; i++)
		list[i]->makeSound();

	return 0;
}