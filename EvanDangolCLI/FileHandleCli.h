#pragma once
#include "../EvanDangolCpp/FileHandle.h"
#pragma make_public(FileHandle)
using namespace System;

public ref class FileHandleCli
{
public:
	FileHandleCli();
	FileHandle* fhnd;
	void add();	
    System::String^ GetCin();
	void WriteFile();
	void ReadFile();
	System::String^ returnstring();
};
