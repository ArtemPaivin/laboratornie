#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

void main()
{
	List list1;
	List list2;
	List list3;
	List list3_t;

	cin >> list1;
	cout << endl;
	cin >> list2;
	cout << endl;
	cin >> list3;
	cout << endl;
	cin >> list3_t;
	cout << endl << endl;

	List list4;
	List list5;
	List list6;
	List list7;
	List list8;
	List temp;
	vector<List> my_vektor;
	my_vektor.push_back(list1);
	my_vektor.push_back(list2);
	my_vektor.push_back(list3);
	my_vektor.push_back(list3_t);

	cout << "----------------------- Vektor ----------------------" << endl;
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i];
		cout << endl;
	}

	vector<List>::iterator p = my_vektor.begin();
	p += 2;

	my_vektor.erase(p);

	cout << "----------------------- Delete  ----------------------" << endl;
	p = my_vektor.begin();
	while (p != my_vektor.end())
	{
		cout << *p;
		cout << endl;
		p++;
	}
	cout << "----------------------- Insert  ----------------------" << endl;
	p = my_vektor.begin() + 2;
	cin >> list4;
	cout << endl;
	my_vektor.insert(p, list4);
	cout << "----------------------- Vektor ----------------------" << endl;
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i];
		cout << endl;
	}





	vector<List> my_vektor2;
	cin >> list5;
	cout << endl;
	cin >> list6;
	cout << endl;
	cin >> list7;
	cout << endl;
	cin >> list8;
	cout << endl;
	my_vektor2.push_back(list5);
	my_vektor2.push_back(list6);
	my_vektor2.push_back(list7);
	my_vektor2.push_back(list8);
	cout << "----------------------- Vektor2 ----------------------" << endl;
	for (int i = 0; i < my_vektor2.size(); i++)
	{
		cout << my_vektor2[i];
		cout << endl;
	}

	cout << "----------------------- Vector (del1-2 and add)  ----------------------" << endl;
	p = my_vektor.begin();
	my_vektor.erase(p, p + 2);
	for (int i = 0; i < my_vektor2.size(); i++)
	{
		my_vektor.push_back(my_vektor2[i]);
	}
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i];
		cout << endl;
	}
	cout << endl << endl;
	cout << endl << endl;
	system("pause");
}