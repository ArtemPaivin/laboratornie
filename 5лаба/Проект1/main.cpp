#include <iostream>
#include <windows.h>

#include "ball.h"
#include "brus.h"
#include "inv.h"
#include "mat.h"
#include "skam.h"
#include "employeeSkiing.h"
#include "sportzal.h"
using namespace std;
Skiing *Skiing::head = nullptr;
Sportzal *Sportzal::head = nullptr;
int main()
{
	setlocale(LC_ALL, "");
	int inv;

	Inv myInv(1840, 12000);
	//cout << "Инвентарный номер объекта: " << myInv.get_num() << endl << endl;
	myInv.print();

	cout << "\n\nВведите инвентарный номер объекта: ";
	cin >> inv;
	myInv.set_num(inv);
	myInv.print();

	Brus myBrus(1401, 180000, 147);
	//cout << "Инвентарный номер брусьев: " << myBrus.get_num() << endl << "Ширина: " << myBrus.get_width() << endl << endl;
	myBrus.print();

	Skam mySkam(1202, 120, 1000000, "white", "derevo");
	mySkam.print();
	//cout << "Инвентарный номер скамьи: " << mySkam.get_num() << endl << "Высота: " << mySkam.get_height() << endl << endl;

	Mat myMat(1487, 12, 500000);
	myMat.print();
	//cout << "Инвентарный номер матов: " << myMat.get_num() << endl << "Количество: " << myMat.get_kolvo() << endl << endl;

	Ball myBall(148, 200000, "black");
	myBall.print();
	//cout << "Инвентарный номер мяча: " << myBall.get_num() << endl << "Цвет: " << myBall.get_color() << endl << endl;
	cout << endl;
	cout << endl;









	employeeSkiing sk1(1201, 42, 99000);
	employeeSkiing sk2(1202, 42, 91000);
	employeeSkiing sk3(1203, 43, 80000);
	employeeSkiing sk4(1204, 44, 75000);



	sk1.add();
	sk2.add();
	sk3.add();
	sk4.add();
	employeeSkiing::show();



	cout << endl << endl << "-------------Lab5-------------------" << endl << endl;
	Controller::add(&myBrus);
	Controller::add(&mySkam);
	Controller::add(&myBall);
	Controller::add(&myMat);
	cout << endl << endl << "-------------Вывод cписка на экран-------------------" << endl << endl;
	Controller::show();

	cout << endl << endl << "-------------Вывод в порядке возрастания серийного номера-------------------" << endl << endl;

	Controller::sort();

	cout << endl << endl << "-------------Вывод товара из нужного диапазона цены-------------------" << endl << endl;
	cout << endl << "От: "; int a, b; cin >> a;
	cout << endl << "До: "; cin >> b;
	Controller::price(a, b);
	system("pause");
	return 0;
}