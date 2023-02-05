#pragma once
#include "ProductionMGR.h"
class SingletonProductionMGR
{

private:
	static ProductionMGR* instance;
public:
	static ProductionMGR* GetInstance()
	{
		if (!instance) instance = new ProductionMGR();
		return instance;
	}
	~SingletonProductionMGR()
	{
		std::cout << " asda ddas";
	}
};
