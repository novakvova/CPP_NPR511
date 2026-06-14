#include "Matrix.h"
//Як саме працють методи класу - його функції - фукнціонала
Matrix::Matrix() //Реалізація конструктора
{
	n = m = 2; // по default буде матриця 2х2
	mat = new int* [n]; //виділяємо пам'ять рядки
	for (int i = 0; i < n; i++) // у рядку під стовпчики
	{
		mat[i] = new int[m];
	}
}

Matrix::Matrix(int n, int m) //з параметрами
{
	//Використовуємо слово this
	//this - означає, що змінна належить класу
	this->n = n; //Тобто у клас зберігаємо значення n
	this->m = m;
	mat = new int* [n]; //виділяємо пам'ять рядки
	for (int i = 0; i < n; i++) // у рядку під стовпчики
	{
		mat[i] = new int[m];
	}
}

//Конструктор поцювання. З одного класу копіює дані в 
// поточний клас, який створюється
Matrix::Matrix(const Matrix & matrix)
{
	//Використовуємо слово this
	//this - означає, що змінна належить класу
	this->n = matrix.n; //Тобто у клас зберігаємо значення n
	this->m = matrix.m;
	mat = new int* [n]; //виділяємо пам'ять рядки
	for (int i = 0; i < n; i++) // у рядку під стовпчики
	{
		mat[i] = new int[m];
	}
	//Починаємо процес копіювання класу
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat[i][j] = matrix.mat[i][j];
}

void Matrix::initRandom()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat[i][j] = rand()%100;
}

void Matrix::print() //Звичайни вивід двох мірного масиву
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << "\n";
	}
}

Matrix & Matrix::operator=(const Matrix& b)
{
	//Спочатку перевірим чи не присвоюємо об'єкт сам собі
	// a = a
	if (this == &b)
		return *this; //Немає смислу коли сам себе присвоює
	//Видаляємо пам'ять для об'єкта, який знаходиться зліва від =
	//a = b - То ми видаляємо пам'ять для об'єкта, а
	for (int i = 0; i < n; i++)
	{
		delete[] mat[i]; //Видаляємо рядки (стовпчики)
	}
	delete[] mat; //Видаляємо усе, що лишилося
	n = b.n; //Буде нова матриця n
	m = b.m; //та m
	mat = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = b.mat[i][j];
		}
	}
	return *this;
}
//Ми будемо поверати із методу plus - нову матрицю
Matrix Matrix::plus(const Matrix& b) const 
{
	Matrix c(n, m); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c.mat[i][j] = mat[i][j] + b.mat[i][j];
		}
	}
	return Matrix(c); //вертамєо новий об'єкт
}

//Перевантаєуємо метод cout для класу Matrix
//os - це посилання на cout - який буде виводити інформацію про matrix
ostream& operator<<(ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			os << matrix.mat[i][j] << "\t";
		}
		os << "\n";
	}
	return os;
}