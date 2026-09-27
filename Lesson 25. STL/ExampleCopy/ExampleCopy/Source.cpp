#include<iostream>
#include<Windows.h>
#include<vector>
#include<algorithm>
using namespace std;

//пошук парного числа
bool is_even(int n) { return n % 2 == 0; }
//Якщо число позитивне - додатнє 
bool is_positive(int n) { return n > 0; }
//Виводимо дані із вектора
void print(const vector<int>& data)
{
	for (const auto& item : data)
	{
		cout << item << "\t";
	}
	cout << endl;
}
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "-- Копіювання елементів --\n";

	vector<int> numbers{ -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	//парні числа
	vector<int> even_numbers(numbers.size()); //Уявляємо, що масив увесь із парних чисел
	//позитивні числа
	vector<int> pos_numbers(numbers.size());

	//Виконуємо копіювання із масиву numbers у масив even_numbers
	//При цьому вказуємо, що для умови копіювання використовуюємо фукнцію
	//is_even - яка перевіряє чи є число парник
	auto end_even_iter = copy_if(numbers.begin(), 
		numbers.end(), even_numbers.begin(), is_even);
	//Масив після копіювання
	cout << "--Масив після копіювання--\n";
	print(even_numbers);

	//Видаляємо значення, які не підійшли після копіювання
	//end_even_iter - це кінцевий елемент, з нього потрібно зробити видалення
	//Ми видаляєм із end_even_iter і до кінця
	cout << "End even iter = " << *end_even_iter << "\n";
	even_numbers.erase(end_even_iter, even_numbers.end());

	cout << "Усі парні числа із колекції: \n";
	print(even_numbers);

	//Шукаю позитивні числа
	auto end_pos_iter = copy_if(numbers.begin(), numbers.end(),
		pos_numbers.begin(), is_positive);

	pos_numbers.erase(end_pos_iter, pos_numbers.end());
	cout << "Пошук позитивних чисел:\n";
	print(pos_numbers);
	return 0;
}