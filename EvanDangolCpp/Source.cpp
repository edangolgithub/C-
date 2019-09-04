#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<vector>
#include "student.h"
using namespace std;

class studentm
{
public:
	void read()
	{
		student *s =(student *)malloc(sizeof(student));
		fstream f("d://student.txt", ios::binary| ios::in);
		vector<student> slist;
		while (f.read((char*)s, sizeof(student)))
		{
			slist.push_back(*s);
			
		}
		
		f.close();

		for (student x : slist)
		{
			cout << x.name << endl;
		}
		_getch();
	}
	void write()
	{
		char ch;
		student s;
		fstream f;
		f.open("d://student.txt", ios::binary|ios::out| ios::app);
		
		if (f.fail())
		{
			exit(222);
		}
		do {
			cout << "id" << endl;
			cin >> s.id;
			cin.ignore();
			cout << "name" << endl;
			cin.getline(s.name, sizeof(s.name));
			f.write((char*)&s, sizeof(student));
			cout << "again??\n";
			cin >> ch;
		} while (ch != 'n');
		f.close();
		
	}

};
void dmain()
{
	studentm m;
	m.read();
}
