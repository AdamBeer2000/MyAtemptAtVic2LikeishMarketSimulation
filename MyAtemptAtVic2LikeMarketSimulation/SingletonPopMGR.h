#pragma once
#include "PopMGR.h"
class SingletonPopMGR
{

private:
	static PopMGR* instance;
public:
	static PopMGR* GetInstance()
	{
		if (!instance) instance = new PopMGR();
		return instance;
	}
	~SingletonPopMGR()
	{
		delete instance;
	}
};

