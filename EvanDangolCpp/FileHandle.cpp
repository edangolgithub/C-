#include "stdafx.h"
#include "FileHandle.h"
#include <fstream>
#include<iostream>
#include <string>
using namespace std;
FileHandle::FileHandle()
{
	file = new fstream;
}


FileHandle::~FileHandle()
{
	delete file;
}

void FileHandle::WriteFile()
{

	file->open("a.txt", ios::out);
	
	*file << "hello evan"<<endl;
	*file << "bye bye";
	file->close();
	//cout << "correct";
}

void FileHandle::ReadFile()
{

	file->open("a.txt", ios::in);
	if (file != NULL)
	{
		string p;
		// same as following while loop
		/*char c; 
		while(!file->eof())
		{
			*file >> c;
			cout << c;

			
		}*/

		file->seekg(0, ios::beg); // un necessary
		while (!file->eof())
		{
			getline(*file, p);
			cout << p<<endl;

		}
	
	}
	else
	{
		cout << "no file";

	}
	file->close();
}

const char* FileHandle::GetCin()
{
	
	return "hellllllllllllllllllllllll";
}

string FileHandle::returnstring()
{
	string s = "return string";
	return s;
}
