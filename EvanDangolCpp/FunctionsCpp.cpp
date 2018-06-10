#include "stdafx.h"
#include "FunctionsCpp.h"


FunctionsCpp::FunctionsCpp()
{
}


FunctionsCpp::~FunctionsCpp()
{
}

void FunctionsCpp::swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
