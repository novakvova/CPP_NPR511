#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

struct Client
{
	char name[80];
	char phone[20];
};

//відобраєжає меню із списком доступних операцій
void menu();
void writeClientToFile(); //Будемо вводити інформацію про клієнта і записувати у файл
void readDisplayClients(); //читаємо і виводи клієнтів
void editClient(); //Редагування інформації про клієнта

const char* fileStorage = "clients.txt"; //файл, який зберігає клієнтів програми

int main() 
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "--Робота з файлами--\n";
	menu();
}

void menu()
{
	int action = 0;
	do 
	{
		cout << "Оберіть операцію:\n";
		cout << "0.Вихід\n";
		cout << "1.Додати клієнта\n";
		cout << "2.Відобразити клієнтів\n";
		cout << "3.Редагувати клієнта\n";
		cout << "->_";
		cin >> action;
		switch (action)
		{
		case 1: 
			//cout << "-----Додаємо клієнта у файл----\n";
			cin.ignore(); // cin>>action - видаляємо '\n'
			writeClientToFile(); //викликаємо фукнцію для запису у файл
			break;
		case 2:
			//cout << "-------Читаємо список клієнтів--------\n";
			readDisplayClients();
			break;
		case 3:
			editClient(); //викликаємо змінну клієнта
			break;
		}

	} while (action != 0);
}

void writeClientToFile()
{
	Client client;
	cout << "Вкажіть ПІБ клієнта:\n";
	cin.getline(client.name, 80, '\n');
	cout << "Вкажіть телефон:\n";
	cin.getline(client.phone, 80, '\n');
	ofstream outFile(fileStorage, ios_base::app); //ios_base::app - для дозапису
	outFile << client.name << "\n";
	outFile << client.phone << "\n";
	outFile.close();
}

void readDisplayClients()
{
	ifstream readerFile(fileStorage);
	bool isOpen = readerFile.is_open();
	if (!isOpen)
	{
		cout << "Файл не існує "<<fileStorage<<"\n";
		return;
	}
	Client marko;
	int count = 0;
	while (readerFile.getline(marko.name, 80, '\n'))
	{
		if (strlen(marko.name) == 0)
		{
			return;
		}
		readerFile.getline(marko.phone, 20, '\n');
		cout << "---------" << ++count << "---------\n";
		cout << "Name: " << marko.name << "\nPhone: " << marko.phone << endl;
	}
	readerFile.close();
}

void editClient()
{
	//1.Користувач вказує номер запису.
	//2.Знаходжу даний запис і зберігаю його у структуру.
	//3.Даю можливіть користувачу ввести нові дані
	//4.Поновіню оновляю файл із усі користувачами і записую оновленого клієнта
	//Підраховую кількість клієнтів
	ifstream readerFile(fileStorage);
	bool isOpen = readerFile.is_open();
	if (!isOpen)
	{
		cout << "Файл не існує " << fileStorage << "\n";
		return;
	}
	Client marko;
	int count = 0;
	while (readerFile.getline(marko.name, 80, '\n'))
	{
		if (strlen(marko.name) == 0)
		{
			break; //виходимо з циклу
		}
		readerFile.getline(marko.phone, 20, '\n');
		count++; //піраховую кількість клієнтів
	}
	int numberClient;
	cout << "Вкажіть номер клієнта, якого потрібно змінити\n";
	cout << "->_";
	cin >> numberClient;
	if (numberClient<0 || numberClient > count)
	{
		cout << "Номер клієнта вказано не вірно!\n";
		return;
	}
	//Якщо ми знаємо кількість клієнтів ми можемо виділити память під дану кількість
	Client* list = new Client[count];
	//вичитуємо із файлу усіх клієнтів
	//Тут є проблема. Ми коли читати файл у ньому змістилися до кінця. 
	// потрібно перемітитися на початок
	readerFile.clear();
	readerFile.seekg(0); //змістився на початок файлу
	for (int i = 0;i < count;i++)
	{
		readerFile.getline(list[i].name, 80, '\n');
		readerFile.getline(list[i].phone, 80, '\n');
	}
	readerFile.close();
	cout << "Вкажіть ім'я(" << list[numberClient - 1].name << "): ";
	cin.ignore(); //очищаємо консоль \n
	cin.getline(marko.name, 80, '\n');
	if (strlen(marko.name) != 0)
		strcpy_s(list[numberClient - 1].name, marko.name); //Якщо вказав ім'я то ми його змінюємо у списку

	cout << "Вкажіть телефон(" << list[numberClient - 1].phone << "): ";
	cin.getline(marko.phone, 80, '\n');
	if (strlen(marko.phone) != 0)
		strcpy_s(list[numberClient - 1].phone, marko.phone); //Якщо вказав телефон то ми його змінюємо у списку
	//Тепер можна сміливо очисти файл і запити туди оновлені дані
	ofstream outUpdateClients(fileStorage); //воно його автомаично очистить, бо він відривається для запису
	for (int i = 0;i < count;i++)
	{
		outUpdateClients<<list[i].name<<'\n';
		outUpdateClients<<list[i].phone<<'\n';
	}
	outUpdateClients.close();
}