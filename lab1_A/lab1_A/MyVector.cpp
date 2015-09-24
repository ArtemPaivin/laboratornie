#include "StdAfx.h"
#include "MyVector.h"
#include <iostream>
#include <ctime>
#include <locale>
using namespace std;

void Vector::print(void)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int Vector::Add_size() // задаем размер
{
	cout << "Введите размер: ";
	cin >> size;
	return size;
}
int Vector::Massive()
{
	this->size = size;
	arr = new int[size];
	srand(time(0));
	cout << "Массив: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	return arr[size];
}
int Vector::Sum() //сумма элементов
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	cout << "Сумма= " << sum << endl;
	return sum;
}
int Vector::Element() // вывод по-элементно
{
	int i;
	char a;
	cout << "Введите номер эл-а, который нужно вывести: ";
	cin >> i;
	cout << "Ваш эл-т: " << arr[i - 1] << endl;
	cout << "Продолжить? (y/n): ";
	cin >> a;
	while (a == 'y')
	{
		cout << "Введите номер эл-а, который нужно вывести: ";
		cin >> i;
		cout << "Ваш эл-т: " << arr[i - 1] << endl;
		cout << "Продолжить? (y/n): ";
		cin >> a;
	}
	if (a == 'n') return 0;
	return arr[i - 1];
}
void Vector::Plus() //сложение со скаляром
{
	int scalar;
	cout << "Введите скаляр для суммы: ";
	cin >> scalar;
	for (int i = 0; i<size; i++)
	{
		arr[i] = scalar + arr[i];
		cout << arr[i] << " ";
	}

}
void Vector::Minus()//вычитание со скаляром
{
	int scalar;
	cout << "\nВведите скаляр для разности: ";
	cin >> scalar;
	for (int i = 0; i<size; i++)
	{
		arr[i] = arr[i] - scalar;
		cout << arr[i] << " ";
	}
}

bool Vector::mod(void)
{
	bool c = 1;
	for (int i = 0; i<size; i++)
	{
		if (arr[i] % 2 != 0) c = 0;
	}
	return c;
}

Vector::Vector(void)
{
	cout << "Вызов стандартного конструктора" << endl;
}
Vector::Vector(int size)
{
	arr = *new int *[size];
}

Vector::Vector(const Vector &rVec)
{
	size = rVec.size;
	arr = new int[size];
	for (int i = 0; i<size; i++)
	{
		arr[i] = rVec.arr[i];
	}
}

Vector::~Vector(void)
{
	cout << "Вызов деструктора" << endl;
}