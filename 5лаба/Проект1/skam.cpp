#include <iostream>
#include "skam.h"

using namespace std;

Skam::Skam(int num, int h, int cost, char *colr, char *matrl) : Inv(num, cost)
{
	height = h;
	color = colr;
	material = matrl;
}

int Skam::get_height()
{
	return height;
}

char * Skam::get_color()
{
	return color;
}


char * Skam::get_material()
{
	return material;
}

void Skam::set_height(int h)
{
	height = h;
}

void Skam::set_color(char *colr)
{
	color = colr;
}

void Skam::set_material(char *matrl)
{
	material = matrl;
}

void Skam::print()
{
	Inv::print();
	cout << "\n\tВысота скамейки: " << height << endl;
	cout << "\n\tЦвет скамейки: " << color << endl;
	cout << "\n\tМатериал скамейки: " << material << endl;
}