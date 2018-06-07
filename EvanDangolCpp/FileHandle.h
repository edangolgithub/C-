#pragma once
#ifdef EVANDANGOLCPP_EXPORTS
#define EVANDANGOLCPP_API __declspec(dllexport)
#else
#define EVANDANGOLCPP_API __declspec(dllimport)
#endif
#include <fstream>
#include<iostream>
using namespace std;
class EVANDANGOLCPP_API FileHandle
{
public:
	fstream * file;
	FileHandle();
	~FileHandle();

	void WriteFile();
	void ReadFile();

	const char* GetCin();

	string returnstring();
};
