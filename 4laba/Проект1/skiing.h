#pragma once
#include "inv.h"
class Skiing : public Inv {
protected:
	static Skiing* head;
	int size;
public:
	Skiing(int, int);
	Skiing* next;
	virtual void setSize(int) = 0;
	virtual int getSize() = 0;
	virtual void add() = 0;
};
