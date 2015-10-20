#include <iostream>
#include "mat.h"

using namespace std;

Mat::Mat(int num, int kol) : Inv(num)
{
	kolvo = kol;
}

int Mat::get_kolvo()
{
	return kolvo;
}

void Mat::set_kolvo(int kol)
{
	kolvo = kol;
}
void Mat::print()
{
	Inv::print();
	cout << "\n\tКоличество матов: " << kolvo;
}

