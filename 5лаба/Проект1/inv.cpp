#include <iostream>
#include "inv.h"

using namespace std;

Inv::Inv(int temp, int cost)
{
	this->cost = cost;
	this->inv_number = temp;
}
void Inv::setCost(int cost)
{
	this->cost = cost;
}

int Inv::getCost(void)
{
	return this->cost;
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
	cout << "\n\n����������� ����� �������: " << inv_number << endl << "\t���������: " << cost << "BYR" << endl;
}
