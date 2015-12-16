#pragma once
#include "List.h"
#include <iostream>


using namespace std;

List::List()
{

}

void    List::Show()
{
	List  *temp;

	temp = head;
	while (temp)
	{
		cout << "Number: " << temp->getNumber() << endl;
		temp = temp->next;
	}
}

void operator << (ostream& x, List& my_list)
{
	List  *temp;

	temp = my_list.head;
	while (temp)
	{
		x << "Number: " << temp->getNumber() << std::endl;
		temp = temp->next;
	}
}

void operator >> (std::istream& x, List& my_list)
{
	int p;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Input value: ";
		x >> p;
		my_list.Add(p);
	}
}

List* operator+ (List& ls1, List& ls2)
{

	List *newList = new List();
	List *temp = ls1.head;

	while (temp)
	{
		newList->Add(temp->getNumber());
		temp = temp->next;
	}

	temp = ls2.head;

	while (temp)
	{


		newList->Add(temp->getNumber());
		temp = temp->next;

	}

	return newList;

}

List::~List()
{

}



void List::setNumber(int number)
{
	this->number = number;
}

int List::getNumber()
{
	return number;
}

void List::Add(int p)
{
	if (head != nullptr)
	{
		List* temp = head;
		List *tempn = new List();
		tempn->number = p;
		tempn->next = nullptr;

		while (temp->next)
			temp = temp->next;


		temp->next = tempn;
	}
	else
	{
		head = new List();
		head->number = p;
		head->next = nullptr;
	}
}



bool operator == (List& ls1, List& ls2)
{
	List  *temp_ls1 = ls1.head;
	List  *temp_ls2 = ls2.head;

	while (temp_ls1 && temp_ls1)
	{
		if (temp_ls1->number != temp_ls2->number)
			return false;
		temp_ls1 = temp_ls1->next;
		temp_ls2 = temp_ls2->next;
	}

	if (temp_ls1 || temp_ls2)
		return false;

	return true;
}

void List::operator < (List ls2)
{
	List *temp_ls2 = ls2.head;
	while (temp_ls2)
	{
		this->Add(temp_ls2->getNumber());
		temp_ls2 = temp_ls2->next;
	}
}

int List::operator [] (int i)
{
	List   *temp;
	int value;
	int j = 0;

	temp = head;
	for (j = 0; j < i - 1; j++)
		temp = temp->next;
	value = temp->number;

	return value;
}