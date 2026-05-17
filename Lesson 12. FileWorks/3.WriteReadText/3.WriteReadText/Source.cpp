#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
void writeTextFile(const char*);
void readTextFile(const char*); // читання файлу
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "---Записуємо у файли тексту---\n";
	//Мої друзі
	//writeTextFile("myFriends.txt");
	readTextFile("myFriends.txt");
}
void writeTextFile(const char* fileName)
{
	// рядок як який можна записувати текст
	char temp[80];
	cout << "Вкажіть ПІБ свого друга(подруги):\n";
	cin.getline(temp, 80, '\n');
	//Тепер, якщо temp вказали пишемо його у файл
	ofstream outFile(fileName);
	outFile << temp << "\n";
	outFile.close();
}

void readTextFile(const char* fileName)
{
	ifstream reader(fileName);
	//яка зберігає, текст що читаємо із файлу
	char buffer[80];
	reader.getline(buffer, 80, '\n'); //як cin
	cout << "---" << buffer << "---\n";
	reader.close();
}