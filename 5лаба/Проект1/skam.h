#pragma once
#include "inv.h"

class Skam :public Inv
{
protected:
	int height;
	char *color;
	char *material;
public:
	Skam(int, int, int, char*, char*);
	int get_height();
	void set_height(int);

	char * get_color();
	void set_color(char *);

	char * get_material();
	void set_material(char *);


	void print();
};
