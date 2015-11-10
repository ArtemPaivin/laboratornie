#include <iostream>
#include "brus.h"

using namespace std;
Brus::Brus(int num, int cost, int w) : Inv(num, cost)
{
	width = w;
}
int Brus::get_width()
{
	return width;
}

void Brus::set_width(int w)
{
	width = w;
}

void Brus::print()
{
	Inv::print();
	cout << "\n\t Ўирина брусьев: " << width;
}

