#include <iostream>
#include<algorithm>
#include <vector>
#include <map>
using namespace std;

void main()
{
	vector<double> vek;
	vek.push_back(2.5);
	vek.push_back(7.14);
	vek.push_back(3.1);
	vek.push_back(5.7);
	vek.push_back(0.97);

	cout << "-------------------- Vector ------------------" << endl;
	for (int i = 0; i < vek.size(); i++)
	{
		cout << vek[i] << endl;
	}


	sort(vek.rbegin(), vek.rend());
	cout << endl << endl;
	cout << "--------------------Sort Vector ------------------" << endl;
	for (int i = 0; i < vek.size(); i++)
	{
		cout << vek[i] << endl;
	}
	cout << endl << endl;

	cout << "--------------------Search 5.7 in Vector ------------------" << endl;
	bool t = 0;
	for (int i = 0; i < vek.size(); i++)
	{
		if (vek[i] == 5.7)
		{
			t = 1;
		}
	}

	if (t)cout << "Yes" << endl;
	else cout << "No" << endl;

	cout << endl << endl;
	cout << "--------------------Add in Map num >3 ------------------" << endl;
	map<int, double> my_map;
	int key = 0;
	for (int i = 0; i < vek.size(); i++)
	{
		if (vek[i]>3)
		{
			my_map.insert(pair<int, double>(key, vek[i]));
			key++;
		}
	}

	for (int i = 0; i < my_map.size(); i++)
	{
		cout << my_map[i] << endl;
	}

	sort(vek.begin(), vek.end());
	cout << endl << endl;
	cout << "--------------------Sort Vector ------------------" << endl;
	for (int i = 0; i < vek.size(); i++)
	{
		cout << vek[i] << endl;
	}


	//sort(my_map.begin(), my_map.end());
	cout << endl << endl;
	cout << "--------------------Sort Map ------------------" << endl;
	for (int i = my_map.size() - 1; i >= 0; i--)
	{
		cout << my_map[i] << endl;
	}

	vector<double> vek2;
	for (int i = 0; i < vek.size(); i++)
	{
		vek2.push_back(vek[i]);
	}

	for (int i = my_map.size() - 1; i >= 0; i--)
	{
		vek2.push_back(my_map[i]);
	}

	cout << endl << endl;
	cout << "--------------------Summ Vektor and Map ------------------" << endl;

	for (int i = 0; i < vek2.size(); i++)
	{
		cout << vek2[i] << endl;
	}


	cout << endl << endl;
	cout << "--------------------Search 8.4 in Vector2 ------------------" << endl;
	t = 0;
	for (int i = 0; i < vek2.size(); i++)
	{
		if (vek2[i] == 8.4)
		{
			t = 1;
		}
	}
	if (t)cout << "Yes" << endl;
	else cout << "No" << endl;



	cout << endl << endl;
	int counter = 0;
	cout << "--------------------Count number <7 in Vector2 ------------------" << endl;
	for (int i = 0; i < vek2.size(); i++)
	{
		if (vek2[i] < 7)
		{
			counter++;
		}
	}
	cout << counter << endl;
	system("pause");
}