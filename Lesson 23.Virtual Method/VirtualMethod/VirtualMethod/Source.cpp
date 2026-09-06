#include<iostream>
#include<Windows.h>
using namespace std;
//Віртуальні метод потрібні коли ми
//робимо наслідування класів.
//Іде мова про раннє та пізнє зв'язування
class Animal 
{
public:
	//Це вказує про те, що дочірній клас,
	//може перевизначити даний метод
	virtual void makeSound()
	{
		cout << "Тварина видає звук\n";
	}
};

class Dog : public Animal
{
public:
	//Для того, щоб позначити, що ми
	//перевизначаємо метод класу є слова override
	void makeSound() override
	{
		cout << "Собака гавкає\n";
	}
};

class Cat : public Animal
{
public:
	void makeSound() override
	{
		cout << "Кіт нявкає\n";
	}
};


int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "---Віртуальні методи---\n";

	Dog barsik;
	Cat murchuk;
	//Тварина є базовий клас, тому вона може вказувати на
	//собаку
	Animal* animal = &barsik;
	animal->makeSound(); //пізнє зв'язування

	Animal* testM = &murchuk;
	testM->makeSound(); //пізнє зв'язування
	//Ініціаліазіція random
	srand(time(0)); //Для того, щоб було інше число 

	//int random = rand() % 2;
	//cout << "Random = " << random << "\n";
	//Масив вказівників із 10 елементів
	Animal** animals = new Animal*[10]; // буде 10 тварин
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		//animal[i] = Dog();
		//animal[i] = Cat();
		if (rand() % 2 == 0)
		{
			//Cat cat;
			animals[i] = new Cat();
		}
		else
			animals[i] = new Dog();
	}
	cout << "---Такі звуки на нашому притулку---\n";
	for (int i = 0; i < n; i++)
	{
		//Динамічний поліморфізм.
		//Динамічно виділяємо пам'ять і використовуємо
		//пізнє звязування.
		animals[i]->makeSound();
	}
	return 0;
}