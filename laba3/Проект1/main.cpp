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
	//cout << "����������� ����� �������: " << myInv.get_num() << endl << endl;
	myInv.print();
	
	cout << "\n\n������� ����������� ����� �������: ";
	cin >> inv;
	myInv.set_num(inv);
    myInv.print();

	Brus myBrus(1401, 147);
	//cout << "����������� ����� �������: " << myBrus.get_num() << endl << "������: " << myBrus.get_width() << endl << endl;
	myBrus.print();

	Skam mySkam(1202, 120, "white","derevo");
	mySkam.print();
	//cout << "����������� ����� ������: " << mySkam.get_num() << endl << "������: " << mySkam.get_height() << endl << endl;

	Mat myMat(1487, 12);
	myMat.print();
	//cout << "����������� ����� �����: " << myMat.get_num() << endl << "����������: " << myMat.get_kolvo() << endl << endl;

	Ball myBall(148, "black");
	myBall.print();
	//cout << "����������� ����� ����: " << myBall.get_num() << endl << "����: " << myBall.get_color() << endl << endl;
	cout << endl;
	
	system("pause");
	return 0;
}