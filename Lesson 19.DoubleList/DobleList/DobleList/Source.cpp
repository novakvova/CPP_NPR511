#include<iostream>
#include<Windows.h>
using namespace std;

class Doubly
{
private:
	class Node //Вузол у списку 
	{
	public:
		int data; //дані, які зберегіє вузол
		Node* next; //Вказівник на наступний елемент
		Node* prev; //Вказівник на попередній у списку
	};
	Node* head; //початок списку
public:
	//Конструктор
	Doubly()
	{
		head = NULL; //На початку роботи список пустий
	}

	void Add(int data) //Додати новий елемент у список
	{
		if (head == NULL) //Додаємо на початок, якщо список пустий
		{
			Node* myNode = new Node;
			myNode->data = data; //Зберігає дані у вузлі
			myNode->prev = myNode->next = NULL;
			head = myNode; //Це є перший елемент списку
		}
		else
		{
			Node* temp = head; //Починаємо із початку
			//Ідемо до останього елемента списку
			while (temp->next != NULL) //Доки ми не знаходимося у кінці
				temp = temp->next; //Переходим на наступний у списку
			Node* newNode = new Node(); 
			newNode->data = data; //зберігаємо дані у новий вузол
			newNode->prev = temp; //Попередній для нового буде останій елемент списку
			newNode->next = NULL; //Наступного елемента у списку немає- даний він останій
			temp->next = newNode; //Останій вузол вказну на новий вузол
		}
	}

	void ShowList() //відобрає список елементів
	{
		Node* temp = head; //Запам'ятовуємо початок списку
		while (temp != NULL) //Доки ми не знаходимося у кінці
		{
			cout << temp->data << "\n"; //виодимо дані у вузіл
			temp = temp->next; //Переходим на наступний у списку
		}
	}
	void Remove(int data) //По data - Робоимо пошук
	{
		if (head == NULL)
			return; //список пустий
		Node* temp = head; //Зберігаємо вказівник на 1 елемент

		while (temp != NULL && temp->data != data) //будемо йти по списку поки не знайдемо або до канця
			temp = temp->next; //переходимо на наступний
		
		if (temp == NULL)
		{
			cout << "--Елемент, який ви хочете видалити ми не знайли--\n";
			return;
		}
		//якщо елемент, який ми хочемо видалити є першим
		if (temp == head) //перша позиція
		{
			head = head->next; //Початок зміщається на наступний елемент у списку
			if (head != NULL) //наступний елемент є у списку
				head->prev = NULL; //попереднього немає у списку
			delete temp; //чистимо пам'ять
			return;
		}
		//якщо елемент, який ми хочемо видалити він в середині, давайте його обійдемо
		if (temp->next != NULL)
		{
			temp->next->prev = temp->prev; //перустуємо через 1 для попередніх
		}
		//Попередній елемент, в якості наступного вказує через 1, тобто через temp
		temp->prev->next = temp->next;
		//Тепер можна видаляти, і це буде коректно
		delete temp;
	}
};

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	cout << "--Двохзв'язні списки--\n";

	// Перевіряємо роботу конструктора і додавання у список
	Doubly myList; //конструкто
	myList.Add(12); //додавання у список
	myList.Add(18); //додавання у список
	myList.Add(9); //додавання у список
	myList.Add(13); //додавання у список
	cout << "-----Набір елементів у списку------\n";
	myList.ShowList();

	//cout << "_____Видалили 1 елемент_____\n";
	//myList.Remove(12); //видаляємо 1 елемент
	//myList.ShowList();

	//cout << "------Видалення в середині списку-----\n";
	//myList.Remove(9);
	//myList.ShowList();

	cout << "------Видалення в кінці списку-----\n";
	myList.Remove(13);
	myList.ShowList();
	return 0;
}