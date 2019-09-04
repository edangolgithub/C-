#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include "student.h"
using namespace std;
void read()
{
	student *s = (student *)malloc(sizeof(student));
	student ss;
	fstream f("d://student.txt", ios::binary | ios::in);
	int count = 0;
	while (f.read((char*)&ss, sizeof(student)))
	{
		////s = (student *)realloc(s, sizeof(student)*count + 1);
		//f.read((char*)&ss, sizeof(student));
		s[count] = ss;
		
		
		count++;
	}
	
	for (size_t i = 0; i < count; i++)
	{
		cout << s[i].name<<endl;
	}

	f.close();

	
	_getch();
}

	void readchar()
	{
		//char *c = (char *)malloc(sizeof(char));
		char c;
		fstream f("a.txt", ios::in);
		int count = 0;
		char *text=(char*)malloc(sizeof(char));
		char x[26];
		while (f.get(c))
		{
			text = (char*)realloc(text, sizeof(char)* count+1);
			text[count] = c;
			x[count] = c;
			
			
			count++;
			
		}
		
		cout << text;
		f.close();

		
		_getch();
	}
	 

int run()
{
	read();
	_getch();
}
