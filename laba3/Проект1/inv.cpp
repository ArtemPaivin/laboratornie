#include <iostream>
#include "inv.h"

using namespace std;

Inv::Inv(int temp)
{
	this->inv_number = temp;
}

int Inv::get_num()
{
	return this->inv_number;
}

void Inv::set_num(int temp)
{
	this->inv_number = temp;
}

void Inv::print()
{
	cout << "\n\n����������� ����� �������: " << inv_number;
}
