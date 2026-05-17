#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

//Фукнція для запису чисул у файл
void writeToFile(const char*); //фукнція для запису у файл
void readFile(const char*); // фукція для читання з файлу

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	//writeToFile("mycats.txt");
	readFile("mycats.txt");
}

void writeToFile(const char* fileName)
{
	cout << "Запис у файл з використанням циклу\n";
	ofstream my(fileName); //out
	int age = 0;
	while (age != -1)
	{
		cout << "Вкажіть вік ваших тварин(-1 exit): \n";
		cin >> age;
		if (age == -1)
			continue;
		//працює аналогічно як cout - але записуває у файл
		//сout - воводить інформацію на екран, my - виводить у файл
		my << age << "\n";
	}
	my.close(); //Закриваю зєднання із файлом
}

void readFile(const char* fileName)
{
	//in - читанння
	ifstream myReader(fileName);
	int age;
	// cin - читає дані із консолі
	//myReader - читає дані із вказаного файлу
	while (myReader >> age)
	{
		if (myReader.eof()) //якщо ми досягли кінця файлу
			break; 
		cout << "Число із файлу " << age << "\n";
	}
	myReader.close();
}