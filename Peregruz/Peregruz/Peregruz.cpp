
#include <iostream>
#include "List.h"



using namespace std;


int main()
{
	List list1;
	int p, n, i;

	cout << "Input count for List 1: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p;
		list1.Add(p);
	}



	List list2;
	cout << "Input count for List 2: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cout << "Input value: ";
		cin >> p;
		list2.Add(p);
	}



	cout << "--------------------------List 1----------------------------" << endl;
	list1.Show();

	cout << "--------------------------List 2----------------------------" << endl;
	list2.Show();
	cout << "--------------------------List 2[2]----------------------------" << endl;
	cout << list2[2] << endl;//��������� ������� ��-�� ������
	cout << "--------------------------List 1 + List 2----------------------------" << endl;
	List* result;
	result = list1 + list2;//��������� ����� ������ �� ������ ���� ������
	result->Show();
	cout << "--------------------------List 1 == List 2----------------------------" << endl;
	if (list1 == list2)//���������� �� ��-�� � �������
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "--------------------------List 1 < List 2----------------------------" << endl;
	list1 < list2;// � ������ ������ ����������� �������� �������
	list1.Show();

	system("pause");
	return 0;
}