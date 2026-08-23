#include<iostream>
#include<Windows.h>
using namespace std;

class Car
{
	//Номер машшини
	//список правопорушень - може бути маси
	//Набір елементів по даному номеру.
	//Щоб сортування ішло по номеру авто, Вам потрібно перевантажити
	//оператор порівння для номера авто даного класу
	//Я раджу - ще перевантажити оператор виводу, щоб для Car працював cout
};

class Node 
{
private:
	//Car data; 
	int data; 
	Node* left;
	Node* right;

public:
	//Конструктор з параметрами
	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr; //Знизу гілок немає
	}
	//Щоб BinarySearchTree мав доступ до приватного блоку Node
	friend class BinarySearchTree; //Тобо у нас BinarySearchTree - має доступ
};

//Будуємо клас, який керуває деревами
class BinarySearchTree
{
private:
	Node* root; //Знає про корінь дерева

	//метод для додавання нового елемента в дерево
	Node* insert(Node* node, int value)
	{
		//Якщо вузол порожній - nullptr
		if (node == nullptr)
			return new Node(value); //якщо нода пуста
		//Якщо в дереві не пістий 1 вузол - тобто root, ми маємо знатий місце де має бути вузол
		if (value < node->data) //ідемо в ліво
			node->left = insert(node->left, value);

		else if (value > node->data) //має піти до правого краю
			node->right = insert(node->right, value);

		return node; //повертаємо вказівник на поточний вузол
	}
	//Щоб відобразти елементи дерева по ньому потрібно пройти
	//Прохід по дереву виконується у сортованому вигляді
	//За допомогою рекурсії - виклик метода сам себе і повернення назад
	void view(Node* node)
	{
		if (node == nullptr) //інакше буде зациклення
			return; //дійшли до кінця дерева, більше елементів немає
		//Якщо дерево з більшого до меншого, тоді ідемо з початку з ліва,
		// а потім на право
		//Тут іде виклик метода сам себе - рекурсія
		view(node->left); //звертаюся до лівого вузла і виклика. його
		cout << node->data << "\t";
		view(node->right);  //Доки дерево не обійдемо до nullptr
	}

	void viewReverse(Node* node) // взоротній порядок виводу - від більшого до меншого
	{
		if (node == nullptr) //інакше буде зациклення
			return; //дійшли до кінця дерева, більше елементів немає
		//Якщо дерево з більшого до меншого, тоді ідемо з початку з права,
		// а потім на ліво
		//Тут іде виклик метода сам себе - рекурсія
		viewReverse(node->right);  //Доки дерево не обійдемо до nullptr
		cout << node->data << "\t";
		viewReverse(node->left); //звертаюся до лівого вузла і виклика. його
	}

	bool search(Node* node, int value) //node - поточний взол, value - що шукаємо
	{
		if (node == nullptr) //обійли дерево і нічого не знайшли
			return false;
		if (node->data == value)
			return true; // знайшли елемент, який шукали
		//Відносного того елемента, що шукає або в ліво або в право
		if (value < node->data)
			return search(node->left, value); //ідемо по дереву в ліво
		return search(node->right, value); //ідемо в право, якщо відного поточного більше
	}

public:
	//На почату роботи, дерево буде пусте
	BinarySearchTree()
	{
		root = nullptr; // дерево пусте
	}
	void Add(int value)
	{
		root = this->insert(root, value);
	}

	void Show()
	{
		view(root); //За допомогою рекурсії обходимо дерево і виводимо на екран
		cout << "\n";
	}
	void ShowReverse()
	{
		viewReverse(root); // з права на ліво робимо обхід дерева
		cout << "\n";
	}
	bool Find(int value)
	{
		return search(root, value);
	}
};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "--OOP і бінарні дерева--\n";
	BinarySearchTree myTree;
	myTree.Add(10); //Якшо додаємо 1 елемент він є root
	myTree.Add(5); //Має піти в ліву гілку і там зберегтися
	myTree.Add(15); //Має піти в праву гілку і там зберегтися
	myTree.Add(20); // Дуже піде в право
	myTree.Add(12); //Від 15 піде в ліво
	myTree.Add(7); //Від 5 піде в право
	myTree.Add(3); //Від 5 піде в ліво
	myTree.Add(3); //два рази 3 не може бути в дереві, бо порушиться правила сортування
	/*
			10
		   /  \
		  5    15
		 / \   / \
		3   7 12 20
*/

	myTree.Show(); //Воводжу дерево на екран
	myTree.ShowReverse(); //від більшого до меншого

	cout << "Пошук числа 7 - " << myTree.Find(7) << "\n";
	cout << "Пошук числа 123 - " << myTree.Find(123) << "\n";
	return 0;
}