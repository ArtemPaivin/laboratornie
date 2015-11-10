#pragma once
class Inv
{
protected:
	int	inv_number;
	int cost;
public:
	Inv(int, int);
	void setCost(int);
	int getCost(void);
	int get_num();
	void set_num(int);
	void print();
};