#pragma once
#include "inv.h"

class Mat :public Inv
{
protected:
	int kolvo;
public:
	Mat(int , int ); 
	int get_kolvo();
	void set_kolvo(int);
	void print();
};
