#include "stdafx.h"
#include <iostream>
#include "MyVector.h"
#include <ctime>
#include <time.h>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "RUSSIAN");
	Vector a;
	a.Add_size();
	a.Massive();
	a.Sum();
	a.Element();
	Vector b = Vector(a);
	a.Plus();
	b.Minus();
	cout << endl;
	Vector mass[5];
	for (int i = 0; i < 5; i++)
	{
		mass[i].Add_size();
		mass[i].Massive();
	}
	cout << "Четные элементы: " << endl;
	for (int i = 0; i < 5; i++)
	{
		if (mass[i].mod() == 1) mass[i].print();
	}
	int maxS = mass[0].Sum(), maxS_n = 0;
	for (int i = 1; i < 5; i++)
	{ 
		if(mass[i].Sum()>maxS)
		{ 
			maxS = mass[i].Sum();
			maxS_n = i;
		}
	}
	cout << "Самая большая сумма: " << mass[maxS_n].Sum()<<endl;
	system("pause");
	return 0;
}