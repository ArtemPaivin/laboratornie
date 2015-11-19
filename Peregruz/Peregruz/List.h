
#pragma once

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
	void operator < (List);
	int operator [] (int);
};