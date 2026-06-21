#include<iostream>
#include<fstream>
#include<Windows.h>
#include "Student.h"
using namespace std;

void testCinCout(); //прототип
void testFile();

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "------Дружні методи :)------\n";
	//testCinCout();
	//testFile();
	//Хочу записувати список студентів у файл npr511.txt
	const char* fileName = "npr511.txt";
	//ofstream outFile(fileName);
	//Student melnyk("Мельник Матвій", "099 785 56 34", 13);
	//Student pavlo("Пало Хороший", "098 785 56 34", 18);
	//Student malvina("Мальвіна Павлівна", "076 785 56 34", 19);
	//Student iryna("Ірина Максимівна", "067 785 56 34", 21);
	//outFile << melnyk << pavlo << malvina << iryna;
	//outFile.close();
	Student temp;
	ifstream myReader(fileName);
	//myReader >> temp; // Читаю 1 студента
	//cout << temp << "\n";
	//myReader >> temp; //Це має бути 2 студент у файлі
	//cout << temp << "\n";
	while (!myReader.eof()) //eof - якщо не досягли кінця файлу
	{
		Student item;
		myReader >> item;
		if (myReader.eof()) // якщо кінець файлу. далі не рухаємося
			break; //якщо кінець файлу
		cout << item << "\n";
	}
}

void testFile()
{
	ofstream outFile("students.txt");
	//Працює так само, як cout - але у файл а не на консоль
	outFile << "Класна погода сьогодні :)\n";
	outFile.close();
	//так само, як cin, але у файл
	ifstream readFile("students.txt");
	char ch[100];
	readFile.getline(ch, 100, '\n');
	cout << "File DATA --" << ch << endl;
	readFile.close();
}

void testCinCout()
{
	Student ivan; //викликаємо конструктор по замовчуванні
	//ivan.print();
	// 
	cout << "Приклад по замовчуванню\n";
	cout << ivan << "\n";
	//конструктор з параметрами
	Student semen("Максим Федорович", "+38(098) 78 34 213", 23);
	cout << "Констуктор з парамтерами\n";
	cout << semen << "\n";
	Student maxim(semen); //викликаємо конструктор копіювання
	cout << "Конструктор копюівання:\n";
	cout << maxim << "\n";
	Student vulkan;
	cout << "Вкажіть дані про студента Вулкан: \n";
	cin >> vulkan; //istream буде вводити дані про student
	cout << "Інформація, яку Ви ввели:\n";
	cout << vulkan << "\n"; //ostream - буде виводити дані
}

