
#include <iostream>
#define MAX 10

using namespace std;
class ListsSize {};
template<class Type>
class   List // Класс СПИСОК  
{

public:

	class WrongIndex{
	public:
		int i;
		WrongIndex(int k) :i(k) {};
	};
	class ListIsFull{};
	class ListIsEmpty{};
	class BigNumber{};
	class SmallNumber{};


	List *next;
	List *head;
	Type number;

	List();
	~List();


	void setNumber(Type);

	Type getNumber();
	void Add(Type);
	void Show();
	int HowManyNumbersInList()
	{
		int k = 0;
		List<Type> *temp = head;
		while (temp)
		{
			k++;
			temp = temp->next;
		}
		return k;
	}
	template<class Type>friend List<Type>* operator+ (List<Type>&, List<Type>&);
	template<class Type>friend bool operator == (List<Type>&, List<Type>&);
	void operator < (List);
	Type operator [] (int);


	void showData()
	{
		List *q = head;
		while (q)
		{
			Type temp = q->number;
			cout << temp.getData() << endl;
			q = q->next;
		}
		cout << endl;
	}
};

class Object
{
private:
	char* data;
public:
	Object()
	{
		data = "";
	}
	Object(char* d)
	{
		data = d;
	}
	void setData(char *d)
	{
		data = d;
	}
	char* getData()
	{
		return data;
	}
	void print()
	{
		cout << data << " ";
	}
};

template<class Type>
void delete_from_list(List<Type> *list, List<Type> *del_list)
{
	List<Type> * temp_del = del_list->head;
	while (temp_del)
	{
		List<Type> * temp = list->head;
		List<Type> * tempNext = temp->next;
		if (temp->number != temp_del->number)
		{
			while (tempNext)
			{
				if (tempNext->number == temp_del->number)
				{
					temp->next = tempNext->next;
					List<Type> *del_element = tempNext;
					tempNext = tempNext->next;

					delete del_element;

				}
				else
				{
					temp = temp->next;
					tempNext = tempNext->next;
				}
			}
		}
		else
		{
			list->head = tempNext;
			List<Type> *del_element = temp;
			temp = tempNext;
			tempNext = tempNext->next;
			delete del_element;
		}
		temp_del = temp_del->next;
	}
}





template<class Type>
List<Type>::List()
{

}

template<class Type>
void    List<Type>::Show()
{
	if (HowManyNumbersInList() == 0)throw ListIsEmpty();
	List  *temp;

	temp = head;
	while (temp)
	{
		cout << "Number: " << temp->getNumber() << endl;
		temp = temp->next;
	}
}

template<class Type>
List<Type>* operator+ (List<Type>& ls1, List<Type>& ls2)
{

	List<Type> *newList = new List<Type>();
	List<Type> *temp = ls1.head;

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

template<class Type>
List<Type>::~List()
{

}





template<typename Type>
void List<Type>::setNumber(Type number)
{
	this->number = number;
}

template<class Type>
Type List<Type>::getNumber()
{
	return number;
}

template<class Type>
void List<Type>::Add(Type p)
{
	if (p > 10) { throw BigNumber(); }
	if (p < 0) { throw SmallNumber(); }
	if (HowManyNumbersInList() >= MAX) { throw ListIsFull(); }
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


template<class Type>
bool operator == (List<Type>& ls1, List<Type>& ls2)
{
	if (ls1.HowManyNumbersInList() != ls2.HowManyNumbersInList()) { throw ListsSize(); }
	List<Type>  *temp_ls1 = ls1.head;
	List<Type>  *temp_ls2 = ls2.head;

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

template<class Type>
void List<Type>::operator < (List ls2)
{
	List *temp_ls2 = ls2.head;
	while (temp_ls2)
	{
		this->Add(temp_ls2->getNumber());
		temp_ls2 = temp_ls2->next;
	}
}
template<class Type>
Type List<Type>::operator [] (int i)
{
	if (i > HowManyNumbersInList() || i < 0)throw WrongIndex(i);


	List   *temp;
	Type value;
	int j = 0;

	temp = head;
	for (j = 0; j < i - 1; j++)
		temp = temp->next;
	value = temp->number;

	return value;
};


int main()
{
	List<int> list1;
	int p, n, i;
	cout << "---------------------- Work with int -----------------------" << endl;
	cout << "Input count for List 1: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p;
		try
		{
			list1.Add((int)p);
		}
		catch (List<int>::ListIsFull)
		{
			cout << "List is full" << endl;
			break;
		}
		catch (List<int>::BigNumber)
		{
			cout << "Number is big" << endl;
			i--;
		}
		catch (List<int>::SmallNumber)
		{
			cout << "Number is small" << endl;
			i--;
		}
	}



	List<int> list2;
	cout << "Input count for List 2: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p;
		try
		{
			list2.Add((int)p);
		}
		catch (List<int>::ListIsFull)
		{
			cout << "List is full" << endl;
			break;
		}
		catch (List<int>::BigNumber)
		{
			cout << "Number is big" << endl;
			i--;
		}
		catch (List<int>::SmallNumber)
		{
			cout << "Number is small" << endl;
			i--;
		}
	}

	List<int> list_for_del;
	list_for_del.Add(2);
	list_for_del.Add(4);
	list_for_del.Add(6);

	cout << "--------------------------Delete element 4 from List 1----------------------------" << endl;
	delete_from_list(&list1, &list_for_del);

	cout << "--------------------------List 1----------------------------" << endl;
	try {
		list1.Show();

		cout << "--------------------------List 2----------------------------" << endl;
		list2.Show();
	}
	catch (List<int>::ListIsEmpty)
	{
		cout << "List is Empty" << endl;
	}
	cout << "--------------------------List 2[3]----------------------------" << endl;
	try {
		cout << list2[3] << endl;//получение второго эл-та списка
	}
	catch (List<int>::WrongIndex x)
	{
		cout << "Bad Index: " << x.i << endl;
	}

	cout << "--------------------------List 1 + List 2----------------------------" << endl;
	List<int>* result;
	result = list1 + list2;//создается новый список на основе двух других
	result->Show();
	cout << "--------------------------List 1 == List 2----------------------------" << endl;
	try {
		if (list1 == list2)//одинаковые ли эл-ьы в списках
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	catch (ListsSize)
	{
		cout << "Error: Size of List 1  != Size of List 2" << endl;
	}

	cout << "--------------------------List 1 < List 2----------------------------" << endl;
	list1 < list2;// в первый список загружаются элементы второго
	list1.Show();






	cout << "---------------------- Work with double -----------------------" << endl;
	double p_d;
	List<double> list1_d;


	cout << "Input count for List 1: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p_d;
		try
		{
			list1_d.Add(p_d);
		}
		catch (List<double>::ListIsFull)
		{
			cout << "List is full" << endl;
			break;
		}
		catch (List<double>::BigNumber)
		{
			cout << "Number is big" << endl;
			i--;
		}
		catch (List<double>::SmallNumber)
		{
			cout << "Number is small" << endl;
			i--;
		}
	}



	List<double> list2_d;
	cout << "Input count for List 2: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p_d;
		try
		{
			list2_d.Add(p_d);
		}
		catch (List<double>::ListIsFull)
		{
			cout << "List is full" << endl;
			break;
		}
		catch (List<double>::BigNumber)
		{
			cout << "Number is big" << endl;
			i--;
		}
		catch (List<double>::SmallNumber)
		{
			cout << "Number is small" << endl;
			i--;
		}
	}

	List<double> list_for_del_d;
	list_for_del_d.Add(2.2);
	list_for_del_d.Add(4.4);
	list_for_del_d.Add(6.6);

	cout << "--------------------------Delete element 4.1 from List 1----------------------------" << endl;
	delete_from_list(&list1_d, &list_for_del_d);
	cout << "--------------------------List 1----------------------------" << endl;
	try {
		list1_d.Show();

		cout << "--------------------------List 2----------------------------" << endl;
		list2_d.Show();
	}
	catch (List<double>::ListIsEmpty)
	{
		cout << "List is Empty" << endl;
	}
	cout << "--------------------------List 2[3]----------------------------" << endl;
	try {
		cout << list2_d[3] << endl;//получение второго эл-та списка
	}
	catch (List<double>::WrongIndex x)
	{
		cout << "Bad Index: " << x.i << endl;
	}//получение второго эл-та списка
	cout << "--------------------------List 1 + List 2----------------------------" << endl;
	List<double>* result_d;
	result_d = list1_d + list2_d;//создается новый список на основе двух других
	result_d->Show();
	cout << "--------------------------List 1 == List 2----------------------------" << endl;
	try {
		if (list1_d == list2_d)//одинаковые ли эл-ьы в списках
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	catch (ListsSize)
	{
		cout << "Error: Size of List 1  != Size of List 2" << endl;
	}
	cout << "--------------------------List 1 < List 2----------------------------" << endl;
	list1_d < list2_d;// в первый список загружаются элементы второго
	list1_d.Show();


	system("pause");
	return 0;
}