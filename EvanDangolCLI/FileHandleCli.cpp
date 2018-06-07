#include "stdafx.h"
#include "FileHandleCli.h"
#include<iostream>
FileHandleCli::FileHandleCli()
{
	fhnd = new FileHandle;
}

void FileHandleCli::add()
{
	fhnd->ReadFile();
}


System::String^ FileHandleCli::GetCin()
{
	cout << fhnd->GetCin()<<endl;
	System::String^ s = gcnew System::String(fhnd->GetCin());
	return s;
}

void FileHandleCli::WriteFile()
{
	fhnd->WriteFile();
}

void FileHandleCli::ReadFile()
{
	fhnd->ReadFile();
}

System::String^ FileHandleCli::returnstring()
{
	System::String^ str = gcnew System::String(fhnd->returnstring().c_str());
	return str ;
}
