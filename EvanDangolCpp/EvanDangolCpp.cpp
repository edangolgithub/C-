// EvanDangolCpp.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "EvanDangolCpp.h"


// This is an example of an exported variable
EVANDANGOLCPP_API int nEvanDangolCpp=0;

// This is an example of an exported function.
EVANDANGOLCPP_API int fnEvanDangolCpp(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see EvanDangolCpp.h for the class definition
CEvanDangolCpp::CEvanDangolCpp()
{
    return;
}

void CEvanDangolCpp::add(int a, int b)
{
	cout << a + b;
}
