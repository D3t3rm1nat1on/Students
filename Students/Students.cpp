#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Students
{
	string name;
	string group;
	string phone;
};

vector <Students> student;

void new_record()
{
	Students temp;
	cout << "Enter name ==> ";
	cin >> temp.name;
	cout << "Enter group ==> ";
	cin >> temp.group;
	cout << "Enter phone number (optional or n) ==> ";
	cin >> temp.phone;
	if (temp.phone == "n")
		temp.phone = "N/A";
	student.push_back(temp);
}

void search()
{
	string type, find;
	bool not_found = true;
	cout << "Find by (name/group/phone) ==> ";
	cin >> type;

	if (type == "name")
	{
		cout << "Find ..." << endl;
		cin >> find;
		for (auto temp : student)
		{
			if (temp.name == find)
			{
				cout << temp.name << " ";
				cout << temp.group << " ";
				cout << temp.phone << endl;
				not_found = false;
			}
		}
	}
	else
		if (type == "group")
		{
			cout << "Find ..." << endl;
			cin >> find;
			for (auto temp : student)
			{
				if (temp.group == find)
				{
					cout << temp.name << " ";
					cout << temp.group << " ";
					cout << temp.phone << endl;
					not_found = false;
				}
			}
		}
		else
			if (type == "phone")
			{
				cout << "Find ..." << endl;
				cin >> find;
				for (auto temp : student)
				{
					if (temp.phone == find)
					{
						cout << temp.name << " ";
						cout << temp.group << " ";
						cout << temp.phone << endl;
						not_found = false;
					}
				}
			}
	cout << endl;
	if (not_found)
		cout << "NOT FOUND" << endl;
}

void review()
{
	int i = 1;
	for (auto temp : student) {
		cout << i++ << ") ";
		cout << temp.name << " ";
		cout << temp.group << " ";
		cout << temp.phone << endl;
	}
}

void add_to_file()
{
	ofstream add;
	add.open("list.txt");
	for (int i = 0; i < student.size(); i++)
	{
		add << student[i].name << " " << student[i].group << " " << student[i].phone << "\n";
	}

	add.close();

	cout << "complete" << endl;

}

void erase()
{
	int n;
	review();
	cout << "which one?" << endl;
	cin >> n;
	if ((n <= student.size()) && (n > 0))
		student.erase(student.begin() + n - 1);
	else
		cout << "out of numbers" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251>nul");
	string action;
	for (;; cout << endl)
	{
		cout << "Available actions (create/search/review/file/erase/exit)" << endl;
		cin >> action;
		if (action == "create")
			new_record();
		if (action == "search")
			search();
		if (action == "review")
			review();
		if (action == "file")
			add_to_file();
		if (action == "erase")
			erase();
		if (action == "exit")
			exit(0);
	}
}