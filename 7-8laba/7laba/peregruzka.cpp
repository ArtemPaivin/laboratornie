
#include <iostream>


using namespace std;
template<class Type>
class   List // Класс СПИСОК  
{

public:
	List *next;
	List *head;
	Type number;

	List();
	~List();


	void setNumber(Type);

	Type getNumber();
	void Add(Type);
	void Show();
	template<class Type>friend List<Type>* operator+ (List<Type>&, List<Type>&);
	template<class Type>friend bool operator == (List<Type>&, List<Type>&);
	void operator < (List);
	Type operator [] (int);
};

template<class Type>
void delete_from_list(List<Type> *list, Type del)
{

	List<Type> * temp = list->head;
	List<Type> * tempNext = temp->next;
	if (temp->number != del)
	{
		while (tempNext)
		{
			if (tempNext->number == del)
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
}





template<class Type>
List<Type>::List()
{

}

template<class Type>
void    List<Type>::Show()
{
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
		list1.Add(p);
	}



	List<int> list2;
	cout << "Input count for List 2: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p;
		list2.Add(p);
	}



	cout << "--------------------------Delete element 4 from List 1----------------------------" << endl;
	delete_from_list(&list1, 4);

	cout << "--------------------------List 1----------------------------" << endl;
	list1.Show();

	cout << "--------------------------List 2----------------------------" << endl;
	list2.Show();
	cout << "--------------------------List 2[2]----------------------------" << endl;
	cout << list2[2] << endl;//получение второго эл-та списка
	cout << "--------------------------List 1 + List 2----------------------------" << endl;
	List<int>* result;
	result = list1 + list2;//создается новый список на основе двух других
	result->Show();
	cout << "--------------------------List 1 == List 2----------------------------" << endl;
	if (list1 == list2)//одинаковые ли эл-ьы в списках
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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
		list1_d.Add(p_d);
	}



	List<double> list2_d;
	cout << "Input count for List 2: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p_d;
		list2_d.Add(p_d);
	}


	cout << "--------------------------Delete element 4.1 from List 1----------------------------" << endl;
	delete_from_list(&list1_d, 4.1);
	cout << "--------------------------List 1----------------------------" << endl;
	list1_d.Show();

	cout << "--------------------------List 2----------------------------" << endl;
	list2_d.Show();
	cout << "--------------------------List 2[2]----------------------------" << endl;
	cout << list2_d[2] << endl;//получение второго эл-та списка
	cout << "--------------------------List 1 + List 2----------------------------" << endl;
	List<double>* result_d;
	result_d = list1_d + list2_d;//создается новый список на основе двух других
	result_d->Show();
	cout << "--------------------------List 1 == List 2----------------------------" << endl;
	if (list1_d == list2_d)//одинаковые ли эл-ьы в списках
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "--------------------------List 1 < List 2----------------------------" << endl;
	list1_d < list2_d;// в первый список загружаются элементы второго
	list1_d.Show();

	system("pause");
	return 0;
}