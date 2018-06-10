#pragma once
#include "../EvanDangolCpp/FunctionsCpp.h"
#ifdef EVANDANGOLCPP_EXPORTS
#define EVANDANGOLCPP_API __declspec(dllexport)
#else
#define EVANDANGOLCPP_API __declspec(dllimport)
#endif
public ref class Function
{
public:
	FunctionsCpp *f;
	Function();
	void swap(int &a, int &b);
};

