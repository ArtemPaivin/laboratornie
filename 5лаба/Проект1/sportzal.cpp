#include "sportzal.h"
#include <iostream>
void * Controller::getAdress()
{
	return adress;
}
void Controller::setAdress(void *a, int type)
{
	adress = a;
	this->type = type;
}

void Controller::add(Ball *a)
{
	if (Sportzal::MAX_SUM > Controller::getSum() + a->getCost())
	{
		if (!head)
		{
			head = new Sportzal();
			head->next = nullptr;
			head->adress = a;
			head->type = 0;
		}
		else
		{
			Sportzal * q = head;
			if (q->next == nullptr)
			{
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 0;
			}
			else
			{
				while (q->next != nullptr)
				{
					q = q->next;
				};
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 0;
			}
		}
	}
	else {
		std::cout << "Ѕюжет исчерпан" << std::endl;
	}
}

void Controller::add(Brus * a)
{
	if (Sportzal::MAX_SUM > Controller::getSum() + a->getCost())
	{
		if (!head)
		{
			head = new Sportzal();
			head->next = nullptr;
			head->adress = a;
			head->type = 1;
		}
		else
		{
			Sportzal * q = head;
			if (q->next == nullptr)
			{
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 1;
			}
			else
			{
				while (q->next != nullptr)
				{
					q = q->next;
				};
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 1;
			}
		}
	}
	else {
		std::cout << "Ѕюжет исчерпан" << std::endl;
	}
}

void Controller::add(Mat * a)
{
	if (Sportzal::MAX_SUM > Controller::getSum() + a->getCost())
	{
		if (!head)
		{
			head = new Sportzal();
			head->next = nullptr;
			head->adress = a;
			head->type = 2;
		}
		else
		{
			Sportzal * q = head;
			if (q->next == nullptr)
			{
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 2;
			}
			else
			{
				while (q->next != nullptr)
				{
					q = q->next;
				};
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 2;
			}
		}
	}
	else {
		std::cout << "Ѕюжет исчерпан" << std::endl;
	}
}

void Controller::add(Skam *a)
{
	if (Sportzal::MAX_SUM > Controller::getSum() + a->getCost())
	{
		if (!head)
		{
			head = new Sportzal();
			head->next = nullptr;
			head->adress = a;
			head->type = 3;
		}
		else
		{
			Sportzal * q = head;
			if (q->next == nullptr)
			{
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 3;
			}
			else
			{
				while (q->next != nullptr)
				{
					q = q->next;
				};
				q->next = new Sportzal();
				q->next->next = nullptr;
				q->next->adress = a;
				q->next->type = 3;
			}
		}
	}
	else {
		std::cout << "Ѕюжет исчерпан" << std::endl;
	}
}

int Controller::getSum()
{
	Sportzal *p = head;
	Inv *temp;
	int sum = 0;
	while (p)
	{

		temp = (Inv*)p->adress;
		sum += temp->getCost();

		p = p->next;
	}
	return sum;
}

void Controller::show()
{
	Sportzal *p = head;
	while (p)
	{
		Ball* temp1;
		Brus* temp2;
		Mat* temp3;
		Skam* temp4;
		switch (p->type)
		{
		case 0:
			temp1 = (Ball*)p->adress;
			temp1->print();
			break;
		case 1:
			temp2 = (Brus*)p->adress;
			temp2->print();
			break;
		case 2:
			temp3 = (Mat*)p->adress;
			temp3->print();
			break;
		case 3:
			temp4 = (Skam*)p->adress;
			temp4->print();
			break;
		default:
			break;
		}
		p = p->next;
	}
}

void Controller::del()
{
	Sportzal *ptr1, *ptr2;

	if (head == nullptr)
		return;
	if ((head)->next == nullptr) {
		free(head);
		head = nullptr;
		return;
	}
	for (ptr1 = head, ptr2 = (head)->next; ptr2->next != nullptr; ptr1 = ptr2, ptr2 = ptr2->next);
	free(ptr2);
	ptr1->next = nullptr;
}

int GetHoarBorder(int m[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = m[sm];
	int buf;
	while (i < j)
	{
		while (m[--j]> brd);
		while (m[++i]< brd);
		if (i < j)
		{
			buf = m[j]; m[j] = m[i]; m[i] = buf;
		};
	};
	return j;
};

int* SortHoar(int m[], int sm, int em)
{
	if (sm < em)
	{
		int hb = GetHoarBorder(m, sm, em);
		SortHoar(m, sm, hb);
		SortHoar(m, hb + 1, em);
	}
	return m;
};


void Controller::sort()
{
	int mass[20];
	int num = 0;
	Sportzal *p = head;
	Inv *temp;
	while (p)
	{
		temp = (Inv*)p->adress;
		mass[num] = temp->get_num();
		num++;
		p = p->next;
	}

	SortHoar(mass, 0, num - 1);
	for (int i = 0; i < num; i++)
	{
		Sportzal *p = head;
		while (p)
		{
			Ball* temp1;
			Brus* temp2;
			Mat* temp3;
			Skam* temp4;
			switch (p->type)
			{
			case 0:
				temp1 = (Ball*)p->adress;
				if (mass[i] == temp1->get_num())	temp1->print();
				break;
			case 1:
				temp2 = (Brus*)p->adress;
				if (mass[i] == temp2->get_num())temp2->print();
				break;
			case 2:
				temp3 = (Mat*)p->adress;
				if (mass[i] == temp3->get_num())temp3->print();
				break;
			case 3:
				temp4 = (Skam*)p->adress;
				if (mass[i] == temp1->get_num())temp4->print();
				break;
			default:
				break;
			}
			p = p->next;
		}
	}

}

void Controller::price(int a, int b)
{
	Sportzal *p = head;
	while (p)
	{
		Ball* temp1;
		Brus* temp2;
		Mat* temp3;
		Skam* temp4;
		switch (p->type)
		{
		case 0:
			temp1 = (Ball*)p->adress;
			if (temp1->getCost()>a && temp1->getCost()<b)temp1->print();
			break;
		case 1:
			temp2 = (Brus*)p->adress;
			if (temp2->getCost()>a && temp2->getCost()<b)temp2->print();
			break;
		case 2:
			temp3 = (Mat*)p->adress;
			if (temp3->getCost()>a && temp3->getCost()<b)temp3->print();
			break;
		case 3:
			temp4 = (Skam*)p->adress;
			if (temp4->getCost()>a && temp4->getCost()<b)temp4->print();
			break;
		default:
			break;
		}
		p = p->next;
	}
}
