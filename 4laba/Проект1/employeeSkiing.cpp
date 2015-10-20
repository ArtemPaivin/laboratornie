#include "employeeSkiing.h"
#include <iostream>
using namespace std;
employeeSkiing::employeeSkiing(int num, int size) : Skiing(num, size)
{
}
void employeeSkiing::setSize(int size)
{
	this->size = size;
}

int employeeSkiing::getSize()
{
	return size;
}

void employeeSkiing::add()
{
	if (Skiing::head == nullptr)
	{
		Skiing::head = this;
		Skiing::head->next = nullptr;
	}
	else
	{
		Skiing* temp = Skiing::head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		this->next = nullptr;
		temp->next = this;


	}
}

void employeeSkiing::show()
{
	Skiing *temp = Skiing::head;
	while (temp)
	{
		cout << "Skiing Number: " << temp->get_num() << "  Size: " << temp->getSize() << endl;
		temp = temp->next;
	}

}