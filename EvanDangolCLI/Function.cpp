#include "stdafx.h"
#include "Function.h"


Function::Function()
{
	f = new FunctionsCpp;
}

void Function::swap(int &a, int &b)
{
	f->swap(a, b);
}
