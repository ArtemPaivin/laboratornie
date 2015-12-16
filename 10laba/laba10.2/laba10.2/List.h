
#pragma once
#include <iostream>
using namespace std;
class   List //  Î‡ÒÒ —œ»—Œ   
{

public:
	List *next;
	List *head;
	int number;

	List();
	~List();
	void setNumber(int);

	int getNumber();
	void Add(int);
	void Show();
	friend List* operator+ (List&, List&);
	friend bool operator == (List&, List&);
	friend void operator << (ostream&, List&);
	friend void operator >> (istream&, List&);


	void operator < (List);
	int operator [] (int);
};