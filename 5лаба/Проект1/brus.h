#pragma once
#include "inv.h"

class Brus :public Inv
{
protected:
	int width;
public:
	Brus(int, int, int);
	int get_width();
	void set_width(int);
	void print();
};
