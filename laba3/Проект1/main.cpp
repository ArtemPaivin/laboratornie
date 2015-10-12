#include <iostream>
#include <windows.h>

#include "ball.h"
#include "brus.h"
#include "inv.h"
#include "mat.h"
#include "skam.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int inv;

	Inv myInv(1840);
	//cout << "Инвентарный номер объекта: " << myInv.get_num() << endl << endl;
	myInv.print();
	
	cout << "\n\nВведите инвентарный номер объекта: ";
	cin >> inv;
	myInv.set_num(inv);
    myInv.print();

	Brus myBrus(1401, 147);
	//cout << "Инвентарный номер брусьев: " << myBrus.get_num() << endl << "Ширина: " << myBrus.get_width() << endl << endl;
	myBrus.print();

	Skam mySkam(1202, 120, "white","derevo");
	mySkam.print();
	//cout << "Инвентарный номер скамьи: " << mySkam.get_num() << endl << "Высота: " << mySkam.get_height() << endl << endl;

	Mat myMat(1487, 12);
	myMat.print();
	//cout << "Инвентарный номер матов: " << myMat.get_num() << endl << "Количество: " << myMat.get_kolvo() << endl << endl;

	Ball myBall(148, "black");
	myBall.print();
	//cout << "Инвентарный номер мяча: " << myBall.get_num() << endl << "Цвет: " << myBall.get_color() << endl << endl;
	cout << endl;
	
	system("pause");
	return 0;
}