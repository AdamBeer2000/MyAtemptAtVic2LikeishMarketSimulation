#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H
#include "IProductType.h"
#include "ISource.h"
#include "singletonworldmarket.h"

#include "IProductType.h"
#include "IBudget.h"

class ResourceMine :public ISource, public IBudget, public IProductType
{

private:

protected:
	void Produce(double ammount);
public:
	ResourceMine(ProductType sourceType, double capacity, double startCash = 1000);

	void Produce();
};

#endif // SOURCE_H
