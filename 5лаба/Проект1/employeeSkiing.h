#pragma once
#include "skiing.h"
class employeeSkiing : public Skiing {
public:
	employeeSkiing(int, int, int);
	virtual void setSize(int);
	virtual int getSize();
	virtual void add();
	static void show();

};
