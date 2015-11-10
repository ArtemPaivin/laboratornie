#include <iostream>
#include "ball.h"

using namespace std;

Ball::Ball(int num, int cost, char* col) : Inv(num, cost)
{
	color = col;
}


char* Ball::get_color()
{
	return color;
}

void Ball::set_color(char* col)
{
	color = col;
}
void Ball::print()
{
	Inv::print();
	cout << "\t ÷вет м€ча: " << color << endl;
}
