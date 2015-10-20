#include <iostream>
#include "ball.h"

using namespace std;

Ball::Ball(int num, char* col) : Inv(num)
{
	color= col;
}

char* Ball::get_color()
{
	return color;
}

void Ball::set_color(char* col)
{
		color= col;
}
void Ball::print()
{
	Inv::print();
	cout<<"\n\t ÷вет м€ча: "<<color;
}
