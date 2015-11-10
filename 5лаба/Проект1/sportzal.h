#pragma once
#include "ball.h"
#include "brus.h"
#include "employeeSkiing.h"
#include "mat.h"
#include "skam.h"
class Sportzal
{
public:
	void* adress;
	int type;
	static Sportzal *head;
	Sportzal *next;
	static const int MAX_SUM = 1000000;

};

class Controller :public Sportzal
{
public:
	void* getAdress();
	void setAdress(void*, int);
	static void add(Ball*);
	static void add(Brus*);
	static void add(Mat*);
	static void add(Skam*);
	static int getSum();
	static void show();
	static void del();
	static void sort();
	static void price(int, int);
};
