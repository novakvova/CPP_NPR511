#pragma once

#include<iostream>
using namespace std;

class MyList
{
private:
	//В середині класу, буде ще 1 клас для зберігання інформації
	class Node //Вузлик списку - зберігає дані 
	{
	public:
		int data; //дані які зберігає
		Node* next; // вказівник на наступний елемент у списку
	};
	Node* head; //Початок списку. Якщо список пустий, то head = NULL;

public:
	MyList()
	{
		head = NULL; //список порожній
	}
	void Add(int data) //Додаємо у список якусь інформацію
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
};