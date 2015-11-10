#pragma once
#include "inv.h"

class Ball :public Inv
{
protected:
	char* color;
public:
	Ball(int, int, char*);
	char* get_color();
	void set_color(char*);
	void print();
};
