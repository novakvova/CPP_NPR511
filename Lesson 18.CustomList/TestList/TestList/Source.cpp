#include<iostream>
#include<Windows.h>
#include "MyList.h"
using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	cout << "------Робота із власними списками------\n";
	MyList people;
	people.Add(19);
	people.Add(21);
	people.Add(17);
	people.ShowItems(); // показати, що є у списку
	return 0;
}