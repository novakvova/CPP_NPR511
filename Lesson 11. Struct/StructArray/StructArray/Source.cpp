#include<iostream>
#include<Windows.h>
#include<cstring>
using namespace std;

struct MyAuto
{
	char mark[80];
	char model[80];
	char color[50];
	double price;
	int year;
};

//дана фукнція буде запитувати інфомрацію про авто у користувача
MyAuto inputAuto();
//відображає інформацію про певне авто
void displayInfo(MyAuto);

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "Наш авто парк машин :)\n";
	MyAuto list[10]; // максимально 10 авто
	for (int i = 0; i < 10; i++)
	{
		cout << "--Вкажіть інформацію про" << i+1 <<" авто--\n";
		list[i] = inputAuto();
		if (strlen(list[i].mark) == 0) // Виходжу із циклу, якщо користувач натиснув Enter
			break;
	}

	cout << "------Ваші авто------\n";
	for (int i = 0; i < 10; i++)
	{
		//Про цю машину була вказана інформація
		if (strlen(list[i].mark) == 0) // Виходжу із циклу, якщо користувач натиснув Enter
			break;

		cout << "--Вкажіть інформацію про" << i + 1 << " авто--\n";
		displayInfo(list[i]);
	}
}

MyAuto inputAuto()
{
	//Для вводу даних
	MyAuto temp; //типчасова змінна зберігає інформацію про авто
	cout << "Вкажіть марку авто (пустий рядок (Enter) - завершити) -> ";
	cin.getline(temp.mark, 80, '\n');
	if (strlen(temp.mark) == 0) // якщо перший символ пустий рядок ми завершаємо
		return temp;
	cout << "Вкажіть модель авто -> ";
	cin.getline(temp.model, 80, '\n');
	cout << "Вкажіть колір авто -> ";
	cin.getline(temp.color, 80, '\n');
	cout << "Вкажіть рік авто -> ";
	cin>>temp.year;
	cout << "Вкажіть ціну авто -> ";
	cin >> temp.price;
	//тут залишається мусор у консолі. його потрібно очищати
	// Тут може лишитися \n, який піде на ввід наступної машини
	cin.ignore(1000, '\n'); // Це очистка консолі від мусору
	//повертає авто
	return temp;
}

void displayInfo(MyAuto car)
{
	cout << "Марка авто -> " << car.mark << endl;
	cout << "Модель авто -> " << car.model << endl;
	cout << "Колір авто -> " << car.color << endl;
	cout << "Рік авто -> " << car.year << endl;
	cout << "Ціна авто -> " << car.price << endl;
}