#include<iostream>
#include<fstream>
#include<string> //string - відповідає за роботу з рядками 
#include<Windows.h>
using namespace std;

void WriteToFile()
{
	ofstream fileOut("F:\\example.txt"); //створюємо файл для запису
	if (fileOut.is_open() == false) { //перевіряємо чи файл відкрився
		throw "Не можливо відкривати файл для запису\n"; //не можемо відкрити файл
	}
	fileOut << "Hello, World!\n"; //записуємо рядок у файл
	fileOut.close();
}
void ReadFromFile()
{
	//Хочу прочитати файл і вивести його вміст на екран
	ifstream file("F:\\example.txt"); //будемо проводити його читання
	if (file.is_open() == false) { //перевіряємо чи файл відкрився
		//throw "Не можливо відкривати файл для читання\n"; //не можемо відкрити файл
		throw 23; //не можемо відкрити файл
	}
	string line;
	while (getline(file, line)) { //читаємо рядок з файлу
		cout << line << endl; //виводимо рядок на екран
	}
	file.close();
}
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "--Працюємо із виключеннями--\n";
	try
	{
		WriteToFile(); //викликаємо функцію запису у файл
	}
	catch(const char *msg)
	{
		cout << "Помилка: " << msg << endl;
	}
	try
	{
		ReadFromFile(); //викликаємо функцію читання з файлу
	}
	catch (const int code) {
		cout << "Помилка: Не можливо відкривати файл для читання. Код помилки: " << code << endl;
	}
	catch (const char* msg)
	{
		cout << "Помилка: " << msg << endl;
	}
	return 0;
}