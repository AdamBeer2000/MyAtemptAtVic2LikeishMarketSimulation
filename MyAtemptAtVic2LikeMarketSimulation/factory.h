#ifndef FACTORY_H
#define FACTORY_H

#include "ISource.h"
#include <vector>
#include <algorithm>
#include "singletonworldmarket.h"
#include "need.h"
#include "IProductType.h"
#include "IBudget.h"

/*
class Factory :public ISource
{
public:
	std::vector<std::shared_ptr<Need>> needs;
public:
	Factory(ProductType sourceType, double capacity, std::vector<std::shared_ptr<Need>> needs, double startCash = 1000);
	void Produce();
	void Restock();
	void Print();

};
*/
#endif // FACTORY_H
