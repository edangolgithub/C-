#pragma once
#ifdef EVANDANGOLCPP_EXPORTS
#define EVANDANGOLCPP_API __declspec(dllexport)
#else
#define EVANDANGOLCPP_API __declspec(dllimport)
#endif
class EVANDANGOLCPP_API FunctionsCpp
{
public:
	FunctionsCpp();
	~FunctionsCpp();
	void swap(int &a, int &b);

};

