#pragma once

#include<iostream>
using namespace std;

template <typename MyData> class MyList
{
private:
	//В середині класу, буде ще 1 клас для зберігання інформації
	class Node //Вузлик списку - зберігає дані 
	{
	public:
		MyData data; //дані які зберігає
		Node* next; // вказівник на наступний елемент у списку
	};
	Node* head; //Початок списку. Якщо список пустий, то head = NULL;

public:
	MyList()
	{
		head = NULL; //список порожній
	}
	
	void Add(MyData data) //Додаємо у список якусь інформацію
	{
		if (head == NULL) //Список пустий, тоді елемент падає на початок
		{
			Node* node = new Node;
			node->data = data;
			node->next = NULL;//Наступного елемента в списку немає
			head = node; //Новий елемент спає на початок
		}
		else
		{
			//Додавання елемента у кінець списку
			//0.Стоврити новий елемент
			Node* node = new Node;
			node->data = data;
			node->next = NULL;//Наступного елемента в списку немає, бо це кінець
			//1.Треба піти у кінець списку
			Node* end = head; //Думаємо, що початок - це останій елемент
			while (end->next != NULL)
				end = end->next; //Покий не вийдемо на осній елемент
			//2.і тоді новий елемент додати у кінець списку
			end->next = node; //На остню позицію ставити новий елемент
		}
	}

	void ShowItems()
	{
		Node* temp = head; //створили вказівник на 1 елемент
		while (temp != NULL) //Якщо не досягли кінця списку
		{
			cout << temp->data << "\n"; //Виводи дані, які є у списку
			temp = temp->next; //Рухаємося дані по списку
		}
	}

	int Size()
	{
		int count = 0; //лічильник кількості лементів у списку
		Node* temp = head; //створили вказівник на 1 елемент
		while (temp != NULL) //Якщо не досягли кінця списку
		{
			count++;
			temp = temp->next; //Рухаємося дані по списку
		}
		return count;
	}

	void Sort()
	{
		int n = this->Size(); //визначаємо поточну кількість
		Node* temp = head; //Запам'ятовуємо початок
		for (int i = 0; i < n - 1; i++) //іду до n-1
		{
			Node* next = temp->next; //Беремо наступний після i
			for (int j = i + 1; j < n; j++) //на i позицію буде ставити найменший
			{
				if (temp->data>next->data)
				{
					MyData tempData = temp->data;
					temp->data = next->data;
					next->data = tempData; //переставляємо елементи місцями
				}
				next = next->next; //переходимо на наступний у списку
			}
			temp = temp->next; //Зміщаємо на наступний
		}
	}

	void WriteFile(string fileName)
	{
		ofstream outFile(fileName);
		Node* temp = head; //створили вказівник на 1 елемент
		while (temp != NULL) //Якщо не досягли кінця списку
		{
			outFile << temp->data << "\n"; //Виводи дані, які є у списку
			temp = temp->next; //Рухаємося дані по списку
		}
	}
};