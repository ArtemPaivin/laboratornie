#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

void main()
{
	vector<double> my_vektor;
	my_vektor.push_back(7.8);
	my_vektor.push_back(8.5);
	my_vektor.push_back(1.5);
	my_vektor.push_back(7.9);
	cout << "----------------------- Vektor ----------------------" << endl;
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i] << endl;
	}

	vector<double>::iterator p = my_vektor.begin();
	p += 2;

	my_vektor.erase(p);
	cout << "----------------------- Delete  ----------------------" << endl;
	p = my_vektor.begin();
	while (p != my_vektor.end())
	{
		cout << *p << endl;
		p++;
	}
	cout << "----------------------- Insert  ----------------------" << endl;
	p = my_vektor.begin() + 2;
	my_vektor.insert(p, 0.5);
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i] << endl;
	}

	
	vector<double> my_vektor2;
	my_vektor2.push_back(10.4);
	my_vektor2.push_back(15.2);
	my_vektor2.push_back(12.3);
	my_vektor2.push_back(11.4);
	cout << "----------------------- Vektor2 ----------------------" << endl;
	for (int i = 0; i < my_vektor2.size(); i++)
	{
		cout << my_vektor2[i] << endl;
	}
	cout << "----------------------- Vector(Delete and insert of first)----------------------" << endl;
	p = my_vektor.begin();
	my_vektor.erase(p, p + 2);
	for (int i = 0; i < my_vektor2.size(); i++)
	{
		my_vektor.push_back(my_vektor2[i]);
	}
	for (int i = 0; i < my_vektor.size(); i++)
	{
		cout << my_vektor[i] << endl;
	}
	system("pause");
}
