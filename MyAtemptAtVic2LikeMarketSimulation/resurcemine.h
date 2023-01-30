#ifndef RESOURCEMINE_H
#define RESOURCEMINE_H
#include "IProductType.h"
#include "ISource.h"
#include "singletonworldmarket.h"
#include "IProductType.h"
#include "IBudget.h"

class ResourceGatheringOperation :public ISource, public IBudget, public IProductType
{

private:

protected:
	void Produce(double ammount);
public:
	ResourceGatheringOperation(ProductType sourceType, double capacity, double startCash = 1000);
	void Payout()override;
	void Produce();
	void Print()const;
};

#endif // SOURCE_H
